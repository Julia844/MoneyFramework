#pragma once
#include "ThostFtdcTraderApi.h"
#include "CDataStruct.h"
#pragma pack(4)
class CFutureTrader : public CThostFtdcTraderSpi
{
public:
	bool init(Logininfor mylogininfor,char * Errormsg);  //���ز���,��½ �첽ͨ��  ������ȴ��ر�

	bool sendtrader(Traderorderstruct  mytraderoder,char * OrderRef);    //��������
	bool sendcanceltrader(QueryEntrustorderstruct myEntrust);      //�������� 

	bool sendqueryorder(QueryEntrustorderstruct  myEntrust);      //���Ͳ�ѯί������
	bool sendquerytrader(QueryEntrustorderstruct myEntrust);      //���Ͳ�ѯ�ɽ�����

	bool sendqueryBalanceSheet();   //��ѯ�ʽ�״̬
	bool getQueryBalance(QueryBalanceSheetReturn & pRetunResult);//����ʽ�

	bool getorderstute (char * OrderRef, Entrustreturnstruct &myoderreturn,char * Errormsg); //����OrderRef�����״̬  ����״̬�к���ί�б��
	bool gettraderstute(char * OrderRef,Bargainreturnstruct  &mytraderreturn,char * Errormsg);

	bool getorderstute(QueryEntrustorderstruct myEntrust, Entrustreturnstruct &myoderreturn,char * Errormsg);  //���� ����ί�б�Ż�ȡ����״̬
	bool gettraderstute(QueryEntrustorderstruct myEntrust,Bargainreturnstruct &mytraderreturn,char * Errormsg); //����
	

	bool heartBeat();  //��������
	bool getconnectstate();//  ���ؽ������ δ���� 
	bool getworkstate(); //�����Ƿ�ռ��

private:
	/************����******************/
	TThostFtdcFrontIDType	FRONT_ID;	//ǰ�ñ��
    TThostFtdcSessionIDType	SESSION_ID;	//�Ự���
    TThostFtdcOrderRefType	ORDER_REF;	//��������
	// ���ò���
	char   FRONT_ADDR[255] ;
	char   BROKER_ID[25]  ;
	char   INVESTOR_ID[55] ;
	char   PASSWORD[55] ;
	char   addr[255];
	char   pwd[49];
	char userAccount[49];
	int iRequestID;


	bool bRunning;//��½�ɹ���Ϊtrue
	int m_nNextOrderRef;
	
	TThostFtdcMoneyType dBalance;
	TThostFtdcMoneyType dDeposit;
	TThostFtdcMoneyType dUsable;	
	TThostFtdcMoneyType dMargin;

	CThostFtdcTraderApi* pTraderApi;
	/************����******************/
	CFutureTrader(void);
	~CFutureTrader();

	void loadArgs();
	void init();
	bool buyOpen(char * code,double price,int Qty);
	bool buyClose(char * code,double price,int Qty);
	bool sellOpen(char *code,double price,int Qty);
	bool sellClose(char * code,double price,int Qty);

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������������Ӧ
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	virtual void OnFrontDisconnected(int nReason);
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	virtual void OnHeartBeatWarning(int nTimeLapse);
	
	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
	

	///�û���¼����
	void ReqUserLogin();
	///Ͷ���߽�����ȷ��
	void ReqSettlementInfoConfirm();
	///�����ѯ��Լ
	void ReqQryInstrument();
	///�����ѯ�ʽ��˻�
	void ReqQryTradingAccount();
	///�����ѯͶ���ֲ߳�
	void ReqQryInvestorPosition();

	///������������
	void ReqOrderAction(CThostFtdcOrderField *pOrder);

	// �Ƿ��յ��ɹ�����Ӧ
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
	// �Ƿ��ҵı����ر�
	bool IsMyOrder(CThostFtdcOrderField *pOrder);
	// �Ƿ����ڽ��׵ı���
	bool IsTradingOrder(CThostFtdcOrderField *pOrder);
	
};

