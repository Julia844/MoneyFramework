#include "StdAfx.h"
#include "STYClass.h"
#include "TimeUtil.h"

namespace STYClass 
{
CIndexFutureArbitrage_open::CIndexFutureArbitrage_open(void)
{

}
CIndexFutureArbitrage_open::~CIndexFutureArbitrage_open(void)
{

}

bool    CIndexFutureArbitrage_open::updateSecurityInfo(MarketInforStruct * MarketInfor,int &num)      //���������Ϣ  
{
	for(int i=0;i<num;i++)
	{
		if(MarketInfor[num].msecurity.cSecuritytype=='s')
		{
			this->m_SyntheticIndex.updateInfo(&MarketInfor[num]);  //��������
		}

		if(MarketInfor[num].msecurity==this->m_future.m_DepthMarketData.msecurity) //�ڻ�
		{
			this->m_future.updateInfo(&MarketInfor[num]);  //��������
		}

		if(MarketInfor[num].msecurity==this->m_index.m_DepthMarketData.msecurity) //�ڻ�
		{
			this->m_index.updateInfo(&MarketInfor[num]);  //��������
		}
	}

	return true;
}
bool   CIndexFutureArbitrage_open::getsubscribelist(securityindex* subscribelist,int& num)            //��ö��ĵĹ�Ʊ 
 {
	int totalnum = this->m_SyntheticIndex.stockDb.size() + 2;
	 //securityindex * subscribelist = new securityindex[totalnum];


	map<securityindex ,CSecurity * >::iterator itor;
	
	 itor=this->m_SyntheticIndex.stockDb.begin();
	 
	 num = 0;
	 while(itor!=m_SyntheticIndex.stockDb.end())
       {    
		   subscribelist[num].cSecuritytype=itor->first.cSecuritytype;
		   strcpy( subscribelist[num].cSecurity_code,itor->first.cSecurity_code);
		   itor++;
		   num++;
       } 
	 //ָ��
	 subscribelist[num].cSecuritytype='i';
	 strcpy(subscribelist[num].cSecurity_code,this->m_indexfuturearbitrageopenargs.indexCode);
	 itor++;
     num++;

	 subscribelist[num].cSecuritytype='f';
	 strcpy(subscribelist[num].cSecurity_code,this->m_indexfuturearbitrageopenargs.contractCode);
	 
     num++;
	 return true;
 }

bool   CIndexFutureArbitrage_open::init(IndexFutureArbitrageopeninputargs      m_indexfuturearbitrageopenargs)
{

	m_future.setcode(m_indexfuturearbitrageopenargs.contractCode); //��ʼ�ڻ�

	//��ʼ��position�ļ� 
	if(m_indexfuturearbitrageopenargs.weightlistnum==0)
		return false;   //���Ȩ���ļ�Ϊ�� 

	m_SyntheticIndex.init( m_indexfuturearbitrageopenargs.weightlist,m_indexfuturearbitrageopenargs.weightlistnum,m_indexfuturearbitrageopenargs.positionlist,m_indexfuturearbitrageopenargs.positionlistnum,m_indexfuturearbitrageopenargs.indexCode);					 // ��ʼ��ģ��ָ��

	return   true;
}


bool CIndexFutureArbitrage_open::calculateSimTradeStrikeAndDelta() //����ģ��ָ��������ָ������������
{
	m_SyntheticIndex.updatepositioninfor();   //����position�ļ�

	dTotalStocksMarketValue=m_SyntheticIndex.getrealmarketvalue();
	this->dSimIndex=m_SyntheticIndex.getSimIndex();
	this->dSimerror=this->dSimIndex-m_index.getlastprice();
	this->dTradeIndex=dTotalStocksMarketValue/m_indexfuturearbitrageopenargs.nHands;
	dOrgDelta=m_future.getlastprice()-m_index.getlastprice();

	dTotalStockBuyStrike=m_SyntheticIndex.getrealbuycost()-dTotalStocksMarketValue;
	dFutureSellStrike=m_future.getrealmarketvalue(m_indexfuturearbitrageopenargs.nHands)-m_future.getrealsellgain(m_indexfuturearbitrageopenargs.nHands);

	this->dPositiveDelta = m_future.getlastprice() 
							- this->dSimIndex
							- (this->dTotalStockBuyStrike+this->dFutureSellStrike)/(m_indexfuturearbitrageopenargs.nHands*m_future.getfuturetime());
	return  true;
}

bool CIndexFutureArbitrage_open::isOpenPointReached()
{
	if(!this->m_SyntheticIndex.isupdated()||!this->m_future.isupdated())
	   return false;
	if(abs(this->dSimerror)>6)
		return false;
	if(!CTimeUtil::isAutoTradingTime())
		return false;
	 return true;
}

/*bool CIndexFutureArbitrage_open::doOpenAction()					//����,��������ί��
{

	  Traderorderstruct temptraderorder;
	  list<stockpotionstruct>::iterator itor;
	  itor=this->m_SyntheticIndex.m_positionlist.begin();
	 while(itor!=this->m_SyntheticIndex.m_positionlist.end())
       { 
		   if(itor->bstoped)
			   continue;
		   /*******���ɽ��ױ���********/
		  /* strcpy_s(temptraderorder.cSecurity_code,itor->cSecurity_code);
		
		   itor++;
       }
	return true;
	
}
*/


bool   CIndexFutureArbitrage_open::gettaderargs(IndexFutureArbitrageopeninputargs &realargs)   //���ʵ�������еĲ��� ����samp�ļ�
{
	
	return true;
}
bool   CIndexFutureArbitrage_open::getshowstatus(char * showstr)
	{
		strcpy(showstr,"test");
		return true;
	}
	 /**********��ȡ����*******/
bool   CIndexFutureArbitrage_open::gettaderlist(Traderorderstruct *, int &num)
	{
		return true;

	}
}