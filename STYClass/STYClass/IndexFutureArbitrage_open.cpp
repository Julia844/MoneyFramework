#include "StdAfx.h"
#include "STYClass.h"
#include "TimeUtil.h"

namespace STYClass
{
	CIndexFutureArbitrage_open::CIndexFutureArbitrage_open(void)
	{
		bTradingAllowed = false;//�Ƿ�������,��"����"ʱ��Ϊtrue	 ���ڷ��� 
		dSimIndex = 0;			   //ģ��ָ����С
		dSimerrorPre = 0;           //ģ�����ٷֱ� 
		dSimtraderPre = 0;		 	   //����ָ����С

		dTotalStockBuyStrike = 0;	//�����Ʊ�ĳ��	
		dTotalStocksMarketValue = 0;//Ҫ����Ĺ�Ʊ����ֵ(������ͣ��)
		stopmarketvalue = 0;			 //ͣ����ֵ
		dFutureSellStrike = 0;		//�����ڻ��ĳ��

		dOrgDeltaPre = 0;				//ԭʼ���� = �ڻ� -ָ��
		dPositiveDelta = 0;			//������Ļ��� = 	�ڻ� - ģ��ָ�� -���������ɵ㣩

	}
	CIndexFutureArbitrage_open::~CIndexFutureArbitrage_open(void)
	{

	}

	bool    CIndexFutureArbitrage_open::updateSecurityInfo(MarketInforStruct * MarketInfor, int &num)      //���������Ϣ  
	{
		for (int i = 0; i<num; i++)
		{
			char m = MarketInfor[i].msecurity.cSecuritytype;
			if (MarketInfor[i].msecurity.cSecuritytype == 's')
			{
				this->m_SyntheticIndex.updateInfo(&MarketInfor[i]);  //��������
			}

			if (MarketInfor[i].msecurity == this->m_future.m_DepthMarketData.msecurity) //�ڻ�
			{
				this->m_future.updateInfo(&MarketInfor[i]);  //��������
			}

			if (MarketInfor[i].msecurity == this->m_index.m_DepthMarketData.msecurity) //�ڻ�
			{
				this->m_index.updateInfo(&MarketInfor[i]);  //��������
			}
		}

		return true;
	}
	bool   CIndexFutureArbitrage_open::getsubscribelist(securityindex* * psubscribelist, int& num)            //��ö��ĵĹ�Ʊ 
	{
		int totalnum = this->m_SyntheticIndex.stockDb.size() + 2;
		if (*psubscribelist != 0)
			delete *psubscribelist;
		*psubscribelist = new securityindex[totalnum];
		securityindex *subscribelist = *psubscribelist;


		map<securityindex, CSecurity * >::iterator itor;

		itor = this->m_SyntheticIndex.stockDb.begin();

		num = 0;
		while (itor != m_SyntheticIndex.stockDb.end())
		{
			subscribelist[num].cSecuritytype = itor->first.cSecuritytype;
			strcpy(subscribelist[num].cSecurity_code, itor->first.cSecurity_code);
			itor++;
			num++;
		}
		//ָ��
		subscribelist[num].cSecuritytype = 'i';
		strcpy(subscribelist[num].cSecurity_code, this->m_index.m_DepthMarketData.msecurity.cSecurity_code);
		num++;
		//�ڻ�
		subscribelist[num].cSecuritytype = 'f';
		strcpy(subscribelist[num].cSecurity_code, this->m_future.m_DepthMarketData.msecurity.cSecurity_code);
		num++;
		return true;
	}

	//bool   CIndexFutureArbitrage_open::init(IndexFutureArbitrageopeninputargs* m)
	bool  CIndexFutureArbitrage_open::init()
	{
		//IndexFutureArbitrageopeninputargs      indexfuturearbitrageopenargs = *m;
		//this->nHands = indexfuturearbitrageopenargs.nHands;  //����
		//this->dExpectOpenDelta = indexfuturearbitrageopenargs.dPositiveOpenDelta; //���ֵ�λ
		//this->bTradingAllowed = indexfuturearbitrageopenargs.bTradingAllowed;
		//m_future.setcode(indexfuturearbitrageopenargs.contractCode); //��ʼ�ڻ�
		//m_index.setcode(indexfuturearbitrageopenargs.indexCode);     //��ʼ��ָ��
		////��ʼ��position�ļ� 
		//if(indexfuturearbitrageopenargs.weightlistnum==0)  //��������������������Ȩ���ļ�
		//	return false;   //���Ȩ���ļ�Ϊ�� 

		//if (!m_SyntheticIndex.init(indexfuturearbitrageopenargs.weightlist, indexfuturearbitrageopenargs.weightlistnum, indexfuturearbitrageopenargs.positionlist, indexfuturearbitrageopenargs.positionlistnum, indexfuturearbitrageopenargs.indexCode))
		//	return  false;
		//	// ��ʼ��ģ��ָ������
		//return   true;

		this->nHands = m_args->nHands;  //����
		this->dExpectOpenDelta = m_args->dPositiveOpenDelta; //���ֵ�λ
		this->bTradingAllowed = m_args->bTradingAllowed;
		m_future.setcode(m_args->contractCode); //��ʼ�ڻ�
		m_index.setcode(m_args->indexCode);     //��ʼ��ָ��
		//��ʼ��position�ļ� 
		if (m_args->weightlistnum <= 0 || m_args->positionlistnum<=0)  //��������������������Ȩ���ļ�
			return false;
		if (m_args->weightlist != 0)
			delete m_args->weightlist;

		if (m_args->positionlist != 0)
			delete m_args->positionlist;

		m_args->weightlist = new  indexweightstruct[m_args->weightlistnum];
		m_args->positionlist = new  stockpotionstruct[m_args->positionlistnum];

		if (!stringtoweightlist(m_args->weightliststr, m_args->weightlist, m_args->weightlistnum))
			return false;
		if (!stringtopositionlist(m_args->positionliststr, m_args->positionlist, m_args->positionlistnum))
			return false;

		if (!m_SyntheticIndex.init(m_args->weightlist, m_args->weightlistnum, m_args->positionlist, m_args->positionlistnum, m_args->indexCode))
			return false;
		return true;

	}

	bool CIndexFutureArbitrage_open::calculateSimTradeStrikeAndDelta() //����ģ��ָ��������ָ������������
	{
		m_SyntheticIndex.updatepositioninfor();   //����position�ļ�����������traderlist�ļ�

		dTotalStocksMarketValue = m_SyntheticIndex.getrealmarketvalue(stopmarketvalue);  //��ȡposition����ֵ
		this->dSimIndex = m_SyntheticIndex.getSimIndex();
		this->dSimerrorPre = (this->dSimIndex - m_index.getlastprice()) / m_index.getlastprice();
		this->dSimtraderPre = dTotalStocksMarketValue / (nHands *m_index.getlastprice()*m_future.getfuturetime());
		dOrgDeltaPre = (m_future.getlastprice() - m_index.getlastprice()) / m_index.getlastprice();  //ԭʼ���� 

		dTotalStockBuyStrike = m_SyntheticIndex.getrealbuycost() - dTotalStocksMarketValue;  //���
		dFutureSellStrike = (m_future.getrealmarketvalue(nHands) - m_future.getrealsellgain(nHands))*m_future.getfuturetime();

		this->dPositiveDelta = m_future.getlastprice()   //������Ļ���
			- this->dSimIndex
			- (this->dTotalStockBuyStrike + this->dFutureSellStrike) / (nHands*m_future.getfuturetime());
		isOpenPointReached();
		return  true;
	}

	bool CIndexFutureArbitrage_open::isOpenPointReached()
	{
		if (!this->m_SyntheticIndex.isupdated() || !this->m_future.isupdated()) //����
		{
			strcpy(this->statusmsg, "����������");
			return false;
		}
		//if (abs(this->dSimerrorPre) > 0.002)  //ģ��������ǧ��֮2  
		//{
			//return false;
		//}
		if (!CTimeUtil::isAutoTradingTime())  //����ʱ��
		{
			strcpy(this->statusmsg, "�ǽ���ʱ��");
			return false;
		}
		if (this->dPositiveDelta > this->dExpectOpenDelta) // ����Ԥ��ֵ����������
		{
			strcpy(this->statusmsg, "�ȴ�����");
			return true;

		}
		else
		{
			strcpy(this->statusmsg, "��������");
			return false;
		}

	}

	bool   CIndexFutureArbitrage_open::gettaderargs(IndexFutureArbitrageopeninputargs &realargs)   //���ʵ�������еĲ��� ����samp�ļ�
	{
		realargs.nHands = this->nHands;  //����
		realargs.dPositiveOpenDelta = this->dExpectOpenDelta; //���ֵ�λ
		realargs.bTradingAllowed = this->bTradingAllowed;
		strcpy(realargs.contractCode, m_future.m_DepthMarketData.msecurity.cSecurity_code); //��ʼ�ڻ�
		strcpy(realargs.indexCode, m_index.m_DepthMarketData.msecurity.cSecurity_code);    //��ʼ��ָ��
		//����position�ļ�  weight�ļ������� 
		int num = 0;
		list<stockpotionstruct>::iterator itor;
		itor = this->m_SyntheticIndex.m_positionlist.begin();
		while (itor != this->m_SyntheticIndex.m_positionlist.end())
		{
			realargs.positionlist[num].bstoped = itor->bstoped;
			realargs.positionlist[num].dlastprice = itor->dlastprice;
			realargs.positionlist[num].ntradervolume = itor->ntradervolume;
			realargs.positionlist[num].sSecurity = itor->sSecurity;
			num++;
			itor++;
		}
		realargs.positionlistnum = num;
		return true;
	}
	bool   CIndexFutureArbitrage_open::getshowstatus(IndexFutureArbitrageopenshowargs & msg)
	{
		msg.futureprice = this->m_future.getlastprice(); //�ڻ��۸�
		msg.indexprice = this->m_index.getlastprice(); //ָ���۸�
		msg.SimIndex = this->dSimIndex; //ģ��ָ��
		msg.OrgDeltaPre = this->dOrgDeltaPre;//ԭʼ����
		msg.SimerrorPre = this->dSimerrorPre;//ģ�����

		msg.TotalStocksMarketValue = this->dTotalStocksMarketValue; //ģ����ֵ
		msg.stopmarketvalue = this->stopmarketvalue;//ͣ����ֵ
		msg.uplimitmarketvalue = 0;//
		msg.TotalStockBuyStrike = this->dTotalStockBuyStrike;//������
		msg.dFutureSellStrike = this->dFutureSellStrike;//�ڻ��������
		msg.dPositiveDelta = this->dPositiveDelta;//��������
		msg.SimtraderPre = this->dSimtraderPre;//�������
		strcpy(msg.statusmsg, this->statusmsg);//��ʾ״̬ 
		return true;
	}
	/**********��ȡ����*******/
	bool   CIndexFutureArbitrage_open::gettaderlist(Traderorderstruct **mp_stockorders, int &num)
	{
		int stockordernum = 0;						   //ί������
		if (*mp_stockorders != 0)
			delete (*mp_stockorders);
		*mp_stockorders = new Traderorderstruct[this->m_SyntheticIndex.m_positionlist.size() + 1];   //shen qing  nei cun 
		Traderorderstruct * m_stockorders = *mp_stockorders;
		list<stockpotionstruct>::iterator itor;
		itor = this->m_SyntheticIndex.m_positionlist.begin();
		while (itor != this->m_SyntheticIndex.m_positionlist.end())
		{
			

			if (itor->bstoped)
			{
				itor++;
				continue;
			}
			/*******���ɽ��ױ���********/
			strcpy(m_stockorders[stockordernum].cSecurity_code, itor->sSecurity.cSecurity_code);
			m_stockorders[stockordernum].cSecuritytype = itor->sSecurity.cSecuritytype;
			m_stockorders[stockordernum].nSecurity_amount = 100;// itor->ntradervolume; //����
			m_stockorders[stockordernum].dOrderprice = itor->dlastprice*1.02;   //��2%������޼�����
			if (m_stockorders[stockordernum].dOrderprice > itor->duplimitprice)
				m_stockorders[stockordernum].dOrderprice = itor->duplimitprice;  //��ͣ��

			strcpy(m_stockorders[stockordernum].cExchangeID, getExchangeNumByStockCode(itor->sSecurity.cSecurity_code));

			m_stockorders[stockordernum].cOffsetFlag = 0;  //��Ʊ����Ҫ
			m_stockorders[stockordernum].cOrderexecutedetail = 0; //���� �ݲ�ʹ��
			m_stockorders[stockordernum].cOrderlevel = 1;  //���ȼ�
			m_stockorders[stockordernum].cOrderPriceType = 0; //��Ʊֻ���޼۵�  ����Ҫ
			m_stockorders[stockordernum].cTraderdirection = '1'; //����
			/**********************/


			itor++;
			stockordernum++;
		}

		/**************�ڻ�********/
		strcpy(m_stockorders[stockordernum].cSecurity_code, this->m_future.m_DepthMarketData.msecurity.cSecurity_code);
		m_stockorders[stockordernum].cSecuritytype = this->m_future.m_DepthMarketData.msecurity.cSecuritytype;
		strcpy(m_stockorders[stockordernum].cExchangeID, "cf");
		m_stockorders[stockordernum].cOffsetFlag = '0'; //0  �� 1 ƽ
		m_stockorders[stockordernum].cOrderPriceType = '2'; //�޼�
		m_stockorders[stockordernum].dOrderprice = this->m_future.getlastprice() -10; //�ѵ���ʵʱ��5����
		m_stockorders[stockordernum].cTraderdirection = '1'; //0 ���� 1 ����
		m_stockorders[stockordernum].cOrderlevel = 1;  //���ȼ�
		m_stockorders[stockordernum].cOrderexecutedetail = 0; //���� �ݲ�ʹ��
		m_stockorders[stockordernum].nSecurity_amount = nHands;
		stockordernum++;
		num = stockordernum;

		return true;

	}

}//namespace STYClass 
