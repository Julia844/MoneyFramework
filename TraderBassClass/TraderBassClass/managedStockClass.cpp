#include "Stdafx.h"

#include "managedTradeClass.h"

using namespace MCStockLib;

managedStockClass::managedStockClass(void)
{
	m_cstockTrader = new CStockTrader();
}

managedStockClass::~managedStockClass(void)
{
	delete m_cstockTrader;
}

//��ʼ������
bool managedStockClass::Init(Logininfor mylogininfor,char * Errormsg)
{
	Logininfor info ;
	

	bool rt_value = false;

	rt_value = m_cstockTrader->init(info,Errormsg);

	return rt_value;
}

//���ʽ���
bool managedStockClass::SingleTrade(Traderorderstruct  mytraderoder, QueryEntrustorderstruct &myEntrust,char * Errormsg)
{
	Traderorderstruct trade ;
	QueryEntrustorderstruct entrust;
	trade.getInit(mytraderoder);
	(entrust).getInit(myEntrust);

	bool rt_value = false;

	rt_value = m_cstockTrader->trader(trade,entrust,Errormsg);

	return rt_value;

}

//�������ף� ���ڵ�֧��Ʊ�߸ýӿ�
bool managedStockClass::BatchTrade(Traderorderstruct * mytraderoder,int nSize,QueryEntrustorderstruct * myEntrust,int &num,char * Errormsg)
{
	bool rt_value = false;

	rt_value = m_cstockTrader->Batchstocktrader(mytraderoder,nSize,myEntrust,num,Errormsg);
	return rt_value;
}

//��ѯ����״̬
bool managedStockClass::getConnectStatus()
{
	bool rt_value = false;
	rt_value = m_cstockTrader->getconnectstate();
	return rt_value;
}

//��ȡ����״̬
bool managedStockClass::getWorkStatus()
{
	return m_cstockTrader->getworkstate();
}