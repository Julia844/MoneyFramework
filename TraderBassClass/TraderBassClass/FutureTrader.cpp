#include "StdAfx.h"
#include "FutureTrader.h"
#include "defines.h"
#include "ThostFtdcTraderApi.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)
// USER_API����

CFutureTrader::CFutureTrader(void)
{		
	hFutureDataMutex =  CreateMutex( NULL, FALSE, NULL );
	this->bConnected=false;
	this->bRunning=false;
}
CFutureTrader::~CFutureTrader(){
//	pTraderApi->Join();
}


bool CFutureTrader::init(Logininfor mylogininfor)
{	
	strcpy_s(addr,mylogininfor.serverAddr);
	strcpy_s(userAccount,mylogininfor.ZjAccount);
	strcpy_s(pwd,mylogininfor.PASSWORD);
	strcpy_s(BROKER_ID,mylogininfor.BROKER_ID);

	this->bConnected = false;
	pTraderApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// ����UserApi
	pTraderApi->RegisterSpi((CThostFtdcTraderSpi*)this);				// ע���¼���
	pTraderApi->SubscribePublicTopic(TERT_QUICK);						// ע�ṫ����
	pTraderApi->SubscribePrivateTopic(TERT_QUICK);						// ע��˽����
	pTraderApi->RegisterFront(addr);									// connect
	pTraderApi->Init();
	return true;
}

bool CFutureTrader::sendtrader(Traderorderstruct  mytraderoder,char * OrderRef)   //��������
{
	this->bRunning=true;
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///��Լ����

	strcpy_s(req.BrokerID, BROKER_ID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID, this->userAccount);	

	strcpy_s(req.InstrumentID, mytraderoder.cSecurity_code);
	///��������: 
	req.Direction = mytraderoder.cTraderdirection;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] =mytraderoder.cOffsetFlag; 
	////����: 1
	req.VolumeTotalOriginal =mytraderoder.nSecurity_amount;
	///�۸�
	req.LimitPrice = mytraderoder.dOrderprice;
		
	///��������
	strcpy_s(req.OrderRef,OrderRef);
	///�û�����
	///�����۸�����
	req.OrderPriceType =mytraderoder.cOrderPriceType;

	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = 
		THOST_FTDC_HF_Speculation;	
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;
	///GTD����
	//	TThostFtdcDateType	GTDDate;
	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
	//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	///ҵ��Ԫ
	//	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	//	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־: ��
	req.UserForceClose = 0;

	int iResult = pTraderApi->ReqOrderInsert(&req, ++iRequestID);
	if(iResult ==0)
	{		
		this->bRunning=false;
		return true;
	}
	this->bRunning=false;
	return false;
}

bool CFutureTrader::getconnectstate()//  ���ؽ������ δ���� 
{
	return this->bConnected;
}

bool  CFutureTrader::getworkstate() //�����Ƿ�ռ��
{
	return this->bRunning;
}
void CFutureTrader::OnFrontConnected()
{
	
	///�û���¼����
	ReqUserLogin();
}

void CFutureTrader::ReqUserLogin()
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, this->BROKER_ID);
	strcpy_s(req.UserID, this->userAccount);
	strcpy_s(req.Password, pwd);
	int iResult = pTraderApi->ReqUserLogin(&req, ++iRequestID);
	cerr << "--->>> �����û���¼����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CFutureTrader::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspUserLogin" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		// ����Ự����
		//CSysLoger::logMessage("CFutureTrader::OnRspUserLogin:��½�ɹ�");
		FRONT_ID = pRspUserLogin->FrontID;
		SESSION_ID = pRspUserLogin->SessionID;
		m_nNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		m_nNextOrderRef++;
		sprintf(ORDER_REF, "%d", m_nNextOrderRef);
		///��ȡ��ǰ������
		cerr << "--->>> ��ȡ��ǰ������ = " << pTraderApi->GetTradingDay() << endl;
		///Ͷ���߽�����ȷ��
		ReqSettlementInfoConfirm();		
		this->bConnected = true;
	}else
	{
		this->bConnected = false;
	}
}

void CFutureTrader::ReqSettlementInfoConfirm()
{
	CThostFtdcSettlementInfoConfirmField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, BROKER_ID);
	strcpy_s(req.InvestorID, this->userAccount);
	int iResult = pTraderApi->ReqSettlementInfoConfirm(&req, ++iRequestID);
	cerr << "--->>> Ͷ���߽�����ȷ��: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CFutureTrader::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		
		this->bConnected = true;
	}else{
		
		this->bConnected = false;
	}
}

void CFutureTrader::ReqQryInstrument()
{
	CThostFtdcQryInstrumentField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.InstrumentID, "IF1111");
	int iResult = pTraderApi->ReqQryInstrument(&req, ++iRequestID);
	cerr << "--->>> �����ѯ��Լ: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CFutureTrader::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspQryInstrument" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///�����ѯ��Լ
		ReqQryTradingAccount();
	}
}

void CFutureTrader::ReqQryTradingAccount()
{
	CThostFtdcQryTradingAccountField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, BROKER_ID);
	strcpy_s(req.InvestorID, userAccount);
	int iResult = pTraderApi->ReqQryTradingAccount(&req, ++iRequestID);
	cerr << "--->>> �����ѯ�ʽ��˻�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CFutureTrader::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspQryTradingAccount" << endl;
	this->dBalance=0;
	this->dDeposit=0;	
	this->dUsable =0;
	this->dMargin=0;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///�����ѯͶ���ֲ߳�
		//ReqQryInvestorPosition();
		this->dUsable = pTradingAccount->Available;
		this->dMargin = pTradingAccount->CurrMargin;
		this->dBalance = pTradingAccount->Balance;
		this->dDeposit = pTradingAccount->Deposit;

	}else{
		//AfxMessageBox("��ѯ�ʽ�ʧ��");
	}
}

void CFutureTrader::ReqQryInvestorPosition()
{
	CThostFtdcQryInvestorPositionField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, BROKER_ID);
	strcpy_s(req.InvestorID, INVESTOR_ID);
	//strcpy_s(req.InstrumentID, INSTRUMENT_ID);
	int iResult = pTraderApi->ReqQryInvestorPosition(&req, ++iRequestID);
	cerr << "--->>> �����ѯͶ���ֲ߳�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CFutureTrader::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspQryInvestorPosition" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///����¼������
		//ReqOrderInsert();
	}
}


//ֻ���ڱ���ʧ��ʱ�Ż�ص��������
void CFutureTrader::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(IsErrorRspInfo(pRspInfo))
	{		
		//CSysLoger::logMessage("CFutureTrader::OnRspOrderInsert:����ʧ��");	
		//AfxMessageBox(pRspInfo->ErrorMsg);
		WaitForSingleObject( hFutureDataMutex, INFINITE ); 	

		strcpy(orderDb[pInputOrder->OrderRef].OrderRef,pInputOrder->OrderRef);
		orderDb[pInputOrder->OrderRef].issendfail=true;

		ReleaseMutex( hFutureDataMutex );
	}
	 
}
///����֪ͨ
void CFutureTrader::OnRtnOrder(CThostFtdcOrderField *pOrder)
{	
	if (IsMyOrder(pOrder))
	{	
		WaitForSingleObject( hFutureDataMutex, INFINITE ); 	
		strcpy(orderDb[pOrder->OrderRef].OrderRef,pOrder->OrderRef);
		ReleaseMutex( hFutureDataMutex );
		
		switch(pOrder->OrderSubmitStatus)
		{
			case THOST_FTDC_OSS_InsertRejected:
			{
				
				//AfxMessageBox("����ʧ��:�����Ѿ����ܾ�");
			}
		}
	}
}
///�ɽ�֪ͨ
void CFutureTrader::OnRtnTrade(CThostFtdcTradeField *pTrade)
{	
	if(IsMytrader(pTrade))
	{
		WaitForSingleObject( hFutureDataMutex, INFINITE ); 	//�ɽ��ر�ȫ����������
		strcpy(orderDb[pTrade->OrderRef].OrderRef,pTrade->OrderRef);
		ReleaseMutex( hFutureDataMutex );
	}
	
}

//��ʱû���õ�
void CFutureTrader::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	static bool ORDER_ACTION_SENT = false;		//�Ƿ����˱���
	if (ORDER_ACTION_SENT)
		return;

	CThostFtdcInputOrderActionField req;
	memset(&req, 0, sizeof(req));
	///���͹�˾����
	strcpy_s(req.BrokerID, pOrder->BrokerID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID, pOrder->InvestorID);
	///������������
//	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	strcpy_s(req.OrderRef, pOrder->OrderRef);
	///������
//	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	req.FrontID = FRONT_ID;
	///�Ự���
	req.SessionID = SESSION_ID;
	///����������
//	TThostFtdcExchangeIDType	ExchangeID;
	///�������
//	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	req.ActionFlag = THOST_FTDC_AF_Delete;
	///�۸�
//	TThostFtdcPriceType	LimitPrice;
	///�����仯
//	TThostFtdcVolumeType	VolumeChange;
	///�û�����
//	TThostFtdcUserIDType	UserID;
	///��Լ����
	strcpy_s(req.InstrumentID, pOrder->InstrumentID);

	int iResult = pTraderApi->ReqOrderAction(&req, ++iRequestID);
	cerr << "--->>> ������������: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
	ORDER_ACTION_SENT = true;
}
//��ʱû�õ�
void CFutureTrader::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspOrderAction" << endl;
	IsErrorRspInfo(pRspInfo);
}


void CFutureTrader:: OnFrontDisconnected(int nReason)
{
	cerr << "--->>> " << "OnFrontDisconnected" << endl;
	cerr << "--->>> Reason = " << nReason << endl;
}		
void CFutureTrader::OnHeartBeatWarning(int nTimeLapse)
{	
	this->bConnected = false;
	cerr << "--->>> " << "OnHeartBeatWarning" << endl;
	cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}
void CFutureTrader::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspError" << endl;
	IsErrorRspInfo(pRspInfo);
}

bool CFutureTrader::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// ���ErrorID != 0, ˵���յ��˴������Ӧ
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
	{
		cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	}
	return bResult;
}
bool CFutureTrader::IsMyOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->FrontID == FRONT_ID) &&
		(pOrder->SessionID == SESSION_ID));
}
bool CFutureTrader::IsMytrader(CThostFtdcTradeField *pTrade)
{
	return true;
}
bool CFutureTrader::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}

bool CFutureTrader::buyOpen(char * code,double price,int Qty){
	
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///��Լ����
	strcpy_s(req.InstrumentID, code);
	///��������: 
	req.Direction = THOST_FTDC_D_Buy;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	///�۸�
	req.VolumeTotalOriginal = Qty;
	///����: 1
	req.LimitPrice = price;
		
	///��������
	strcpy_s(req.OrderRef, "12345");
	m_nNextOrderRef++;
	sprintf(ORDER_REF, "%d", m_nNextOrderRef);
	///�û�����
	///�����۸�����: �޼�
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///���͹�˾����
	strcpy_s(req.BrokerID, BROKER_ID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID, this->userAccount);	
	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;	
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;
	///GTD����
	//	TThostFtdcDateType	GTDDate;
	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
	//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	///ҵ��Ԫ
	//	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	//	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־: ��
	req.UserForceClose = 0;

	int iResult = pTraderApi->ReqOrderInsert(&req, ++iRequestID);
	if(iResult ==0){		
	//	CString logMsg;
		//logMsg.Format("���뿪�ַ����ɹ�;��Լ:%s;�۸�:%.2f;����:%d;order_ref:%s",code,price,Qty,ORDER_REF);		
		//CSysLoger::logMessage(logMsg);
		return true;
	}
	return false;
}
bool CFutureTrader::sellOpen(char * code,double price,int Qty){//��������
//	return true;
	
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///��Լ����
	strcpy_s(req.InstrumentID, code);
	///��������: 
	req.Direction = THOST_FTDC_D_Sell;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	///�۸�
	req.VolumeTotalOriginal = Qty;
	///����: 1
	req.LimitPrice =price;

	///��������
	//strcpy_s(req.OrderRef, ORDER_REF);
	m_nNextOrderRef++;
	sprintf(ORDER_REF, "%d", m_nNextOrderRef);
	///�û�����
	///�����۸�����: �޼�
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///���͹�˾����
	strcpy_s(req.BrokerID, BROKER_ID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID,  this->userAccount);	
	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;	
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;
	///GTD����
	//	TThostFtdcDateType	GTDDate;
	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
	//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	///ҵ��Ԫ
	//	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	//	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־: ��
	req.UserForceClose = 0;

	int iResult = pTraderApi->ReqOrderInsert(&req, ++iRequestID);
	if(iResult ==0){
		//CString logMsg;
		//logMsg.Format("�������ַ����ɹ�;��Լ:%s;�۸�:%.2f;����:%d;order_ref:%s",code,price,Qty,ORDER_REF);		
		//CSysLoger::logMessage(logMsg);
		return true;
	}
	return false;
}
bool CFutureTrader::buyClose(char * code,double price,int Qty){//����ƽ��
	
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///��Լ����
	strcpy_s(req.InstrumentID,  code);
	///��������: 
	req.Direction = THOST_FTDC_D_Buy;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
	///�۸�
	req.VolumeTotalOriginal = Qty;
	///����: 1
	req.LimitPrice = price;

	///��������
	strcpy_s(req.OrderRef, ORDER_REF);
	m_nNextOrderRef++;
	sprintf(ORDER_REF, "%d", m_nNextOrderRef);
	///�û�����
	///�����۸�����: �޼�
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///���͹�˾����
	strcpy_s(req.BrokerID, BROKER_ID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID, this->userAccount);	
	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;	
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;
	///GTD����
	//	TThostFtdcDateType	GTDDate;
	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
	//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	///ҵ��Ԫ
	//	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	//	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־: ��
	req.UserForceClose = 0;

	int iResult = pTraderApi->ReqOrderInsert(&req, ++iRequestID);
	if(iResult ==0){		
		//CString logMsg;
		//logMsg.Format("����ƽ�ַ����ɹ�;��Լ:%s;�۸�:%.2f;����:%d;order_ref:%s",code,price,Qty,ORDER_REF);		
		//CSysLoger::logMessage(logMsg);
		return true;
	}
	return false;
}
bool CFutureTrader::sellClose(char * code,double price,int Qty){
	
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///��Լ����
	strcpy_s(req.InstrumentID,  code);
	///��������: 
	req.Direction = THOST_FTDC_D_Sell;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
	///�۸�
	req.VolumeTotalOriginal = Qty;
	///����: 1
	req.LimitPrice = price;

	///��������
	strcpy_s(req.OrderRef, ORDER_REF);
	m_nNextOrderRef++;
	sprintf(ORDER_REF, "%d", m_nNextOrderRef);
	///�û�����
	///�����۸�����: �޼�
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///���͹�˾����
	strcpy_s(req.BrokerID, BROKER_ID);
	///Ͷ���ߴ���
	strcpy_s(req.InvestorID,  this->userAccount);	
	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;	
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;
	///GTD����
	//	TThostFtdcDateType	GTDDate;
	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
	//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	///ҵ��Ԫ
	//	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	//	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־: ��
	req.UserForceClose = 0;

	int iResult = pTraderApi->ReqOrderInsert(&req, ++iRequestID);
	if(iResult ==0){
		//CString logMsg;
		//logMsg.Format("����ƽ�ַ����ɹ�;��Լ:%s;�۸�:%.2f;����:%d;order_ref:%s",code,price,Qty,ORDER_REF);		
		//CSysLoger::logMessage(logMsg);
		return true;
	}
	return false;
}
