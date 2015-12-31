#include "StdAfx.h"
#include "STYClass.h"
#include "TimeUtil.h"

namespace STYClass
{
	CIndexFutureArbitrage_close::CIndexFutureArbitrage_close(void)
	{
		dTotalStockMarketValue=0;  //��Ʊ��ֵ
		dStopedStockValue=0;   //ͣ����ֵ
		dDownlimitStockValue=0;   //��ͣ��ֵ
		dTotalStockSellStrike=0;  //��Ʊ���
		drealStockIncome=0; //��ʵ��Ʊ��������
		dActualStockGain=0; //��ʵ��Ʊ���棨���Ƿ��� �����

		dFutureBuyStrike=0; //�ڻ�������
		dActualFutureGain=0;  //��ʵ�ڻ�����

		 dzerobpgain=0;  //��0��������
	

	}

	CIndexFutureArbitrage_close::~CIndexFutureArbitrage_close(void)
	{

	}


	bool    CIndexFutureArbitrage_close::updateSecurityInfo(MarketInforStruct *MarketInfor, int &num)     //���������Ϣ  
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

			/*if (MarketInfor[i].msecurity == this->m_index.m_DepthMarketData.msecurity) //�ڻ�
			{
				this->m_index.updateInfo(&MarketInfor[i]);  //��������
			}*/
		}

		return true;

	}
	bool    CIndexFutureArbitrage_close::getsubscribelist(securityindex* *psubscribelist, int& num)          //��ö��ĵĹ�Ʊ �����ڳ�ʼ�����������
	{
		int totalnum = this->m_SyntheticIndex.stockDb.size() + 2;
		if (*psubscribelist != 0)
			delete *psubscribelist;
		* psubscribelist = new securityindex[totalnum];
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

	bool     CIndexFutureArbitrage_close::init()	//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
	{
		IndexFutureArbitragecloseinputargs  indexfuturearbitragecloseargs = *m_args;
		this->nHands = indexfuturearbitragecloseargs.nHands;  //����
		this->dStockBonus = indexfuturearbitragecloseargs.dStockBonus;
		this->dGiftValue = indexfuturearbitragecloseargs.dGiftValue;
		this->dStockOpenCost = indexfuturearbitragecloseargs.dStockOpenCost;
		this->dFutureSellPoint = indexfuturearbitragecloseargs.dFutureSellPoint;
		this->dOpenedPoint = indexfuturearbitragecloseargs.dOpenedPoint; //���ֻ���
		this->dExpectedGain = indexfuturearbitragecloseargs.dExpectedGain; //Ԥ������
		this->dShortCharge = indexfuturearbitragecloseargs.dShortCharge;
		//this->bTradingAllowed = indexfuturearbitrageopenargs.bTradingAllowed;
		m_future.setcode(indexfuturearbitragecloseargs.contractCode); //��ʼ�ڻ�
		m_index.setcode(indexfuturearbitragecloseargs.indexCode);     //��ʼ��ָ��
		//��ʼ��position�ļ� 
		indexfuturearbitragecloseargs.weightlistnum = 0;//��������ƽ������������Ȩ���ļ�

		if (indexfuturearbitragecloseargs.positionlist != 0)
			delete indexfuturearbitragecloseargs.positionlist;

		//if (indexfuturearbitragecloseargs.positionlistnum <= 0)
			//return false;

		indexfuturearbitragecloseargs.positionlist= new  stockpotionstruct[indexfuturearbitragecloseargs.positionlistnum];
		//stringtoweightlist(indexfuturearbitragecloseargs.weightliststr, indexfuturearbitragecloseargs.weightlist, indexfuturearbitragecloseargs.weightlistnum);
		if (!stringtopositionlist(indexfuturearbitragecloseargs.positionliststr, indexfuturearbitragecloseargs.positionlist, indexfuturearbitragecloseargs.positionlistnum))
			return false;
		if (!m_SyntheticIndex.init(indexfuturearbitragecloseargs.weightlist, indexfuturearbitragecloseargs.weightlistnum, indexfuturearbitragecloseargs.positionlist, indexfuturearbitragecloseargs.positionlistnum, indexfuturearbitragecloseargs.indexCode))
			return  false;
		// ��ʼ��ģ��ָ������
		return   true;

	}
	bool	 CIndexFutureArbitrage_close::calculateSimTradeStrikeAndDelta() //����ģ��ָ��������ָ������������
	{

		m_SyntheticIndex.updatepositioninfor();   //����position�ļ�����������traderlist�ļ�

		dTotalStockMarketValue = m_SyntheticIndex.getrealmarketvalue(dStopedStockValue);  //��ȡposition����ֵ
		drealStockIncome = m_SyntheticIndex.getrealsellgain();
		dTotalStockSellStrike = dTotalStockMarketValue - drealStockIncome;  //���

		double drealFutureBuyCost = m_future.getrealbuycost(nHands);
		dFutureBuyStrike = m_future.getrealmarketvalue(nHands) -drealFutureBuyCost;

		this->dActualStockGain = this->drealStockIncome + this->dGiftValue + this->dStockBonus - this->dStockOpenCost - (this->dShortCharge*this->dTotalStockMarketValue + this->nHands * 100);
		dActualFutureGain = (this->dFutureSellPoint *nHands - drealFutureBuyCost)*m_future.getfuturetime();
		return  true;
	}
	bool	 CIndexFutureArbitrage_close::isOpenPointReached()				//�Ƿ�ﵽ���ֵ㣬���飬�ʽ�
	{
		if (!this->m_SyntheticIndex.isupdated() || !this->m_future.isupdated()) //����
		{
			strcpy(this->statusmsg, "����������");
			return false;
		}

		if (!CTimeUtil::isAutoTradingTime())  //����ʱ��
		{
			strcpy(this->statusmsg, "�ǽ���ʱ��");
			return false;
		}
		if (dActualFutureGain + dActualStockGain < this->dExpectedGain)
		{
			strcpy(this->statusmsg, "�ȴ�����");
			return false;
		}
		else
		{
			strcpy(this->statusmsg, "��������");
			return true;
		}
	}

	/*****��ʾ����****/
	bool    CIndexFutureArbitrage_close::gettaderargs(IndexFutureArbitragecloseinputargs &realargs)    //���ʵ�������еĲ��� ����samp�ļ�
	{
		realargs.nHands = this->nHands;  //����
		realargs.dExpectedGain = this->dExpectedGain; //Ԥ������
		realargs.dFutureSellPoint = this->dFutureSellPoint;
		realargs.dGiftValue = this->dGiftValue;
		realargs.dShortCharge = this->dShortCharge;
		realargs.dStockBonus = this->dStockBonus;
		realargs.dStockOpenCost = this->dStockOpenCost;
		realargs.dOpenedPoint = this->dOpenedPoint;
		//realargs.bTradingAllowed=this->bTradingAllowed;
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
	bool    CIndexFutureArbitrage_close::getshowstatus(IndexFutureArbitragecloseshowargs & msg)
	{
		msg.dTotalStockMarketValue = dTotalStockMarketValue;  //��Ʊ��ֵ
		msg.dStopedStockValue = dStopedStockValue;   //ͣ����ֵ
		msg.dDownlimitStockValue = 0;   //��ͣ��ֵ
		msg.dTotalStockSellStrike = dTotalStockSellStrike;  //��Ʊ���
		msg.drealStockIncome = drealStockIncome; //��ʵ��Ʊ��������
		msg.dActualStockGain = dActualStockGain; //��ʵ��Ʊ���棨���Ƿ��� �����

		msg.dFutureBuyStrike = dFutureBuyStrike; //�ڻ�������
		msg.dActualFutureGain = dActualFutureGain;  //��ʵ�ڻ�����
		msg.dtotalgain = dActualFutureGain + this->dActualStockGain;		 //ȫ������
		msg.dzerobpgain = 0;	 //��0��������
		strcpy(statusmsg, this->statusmsg);			//����ԭ�� ��״̬

		return true;
	}
	/**********��ȡ����*******/
	bool    CIndexFutureArbitrage_close::gettaderlist(Traderorderstruct ** mp_stockorders, int &num)
	{
		if (*mp_stockorders != 0)
			delete (*mp_stockorders);
		* mp_stockorders = new Traderorderstruct[this->m_SyntheticIndex.m_positionlist.size() + 1];   //shen qing  nei cun 
		Traderorderstruct * m_stockorders = *mp_stockorders;
		int stockordernum = 0;						   //ί������
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
			m_stockorders[stockordernum].nSecurity_amount = itor->ntradervolume;
			m_stockorders[stockordernum].dOrderprice = itor->dlastprice*0.98;   //��2%������޼�����
			if (m_stockorders[stockordernum].dOrderprice< itor->ddownlimitprice)
				m_stockorders[stockordernum].dOrderprice = itor->ddownlimitprice;  //��ͣ��
			strcpy(m_stockorders[stockordernum].cExchangeID, getExchangeNumByStockCode(itor->sSecurity.cSecurity_code));

			m_stockorders[stockordernum].cOffsetFlag = 0;  //��Ʊ����Ҫ
			m_stockorders[stockordernum].cOrderexecutedetail = 0; //���� �ݲ�ʹ��
			m_stockorders[stockordernum].cOrderlevel = 1;  //���ȼ�
			m_stockorders[stockordernum].cOrderPriceType = 0; //��Ʊֻ���޼۵�  ����Ҫ
			m_stockorders[stockordernum].cTraderdirection = '2';
			//��1��---- - ���루�����г�������ʹ�òμ����ܺ�0x201¼��ί�й��ܺŵ�˵����
			//��2��---- - �����������г�������ʹ�òμ����ܺ�0x20

			itor++;
			stockordernum++;
		}

		/**************�ڻ�********/
		strcpy(m_stockorders[stockordernum].cSecurity_code, this->m_future.m_DepthMarketData.msecurity.cSecurity_code);
		m_stockorders[stockordernum].cSecuritytype = this->m_future.m_DepthMarketData.msecurity.cSecuritytype;
		strcpy(m_stockorders[stockordernum].cExchangeID, "cf");
		m_stockorders[stockordernum].cOffsetFlag = '1'; //0  �� 1 ƽ
		m_stockorders[stockordernum].cOrderPriceType = '2'; //�޼�
		m_stockorders[stockordernum].dOrderprice = this->m_future.getlastprice()+5; //�Ѹ���ʵʱ��5����
		m_stockorders[stockordernum].cTraderdirection = '0'; //0 ���� 1 ����
		m_stockorders[stockordernum].cOrderlevel = 1;  //���ȼ�
		m_stockorders[stockordernum].cOrderexecutedetail = 0; //���� �ݲ�ʹ��
		m_stockorders[stockordernum].nSecurity_amount = nHands;
		stockordernum++;

		num = stockordernum;

		return true;
	}
}