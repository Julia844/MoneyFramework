#pragma once
#include"thostftdctraderapi.h"
#include "ThostFtdcUserApiStruct.h"
#include "callbackAndDelegate.h"

namespace CTP_CLI
{


class CCTPSpi :	public CThostFtdcTraderSpi
{
private:
	FrontConnectedCallback frontConnectedCallback;
	FrontDisconnectedCallback frontDisconnectedCallback;
	
	HeartBeatWarningCallback heartBeatWarningCallback;
	RspUserLoginCallback rspUserLoginCallback;
	RspUserLogoutCallback rspUserLogoutCallback;

	RspErrorCallback rspErrorCallback;

	RtnOrderCallback rtnOrderCallback;
	RtnTradeCallback rtnTradeCallback;
	RspOrderActionCallback rspOrderActionCallback;
	RspOrderInsertCallback rspOrderInsertCallback;
	ErrRtnOrderActionCallback errRtnOrderActionCallback;
	ErrRtnOrderInsertCallback errRtnOrderInsertCallback;
	RspQryTradeCallback rspQryTradeCallback;
	RspQryTradingCodeCallback rspQryTradingCodeCallback;
	RspQryTradingNoticeCallback rspQryTradingNoticeCallback;
	RspQryOrderCallback rspQryOrderCallback;
	
	RspQryTradingAccountCallback rspQryTradingAccountCallback;
	RspQryInvestorPositionCallback rspQryInvestorPositionCallback;
	RspQryInvestorCallback rspQryInvestorCallback;

	RspSettlementInfoConfirmCallback rspSettlementInfoConfirmCallback;

public:
	CCTPSpi(void);
	~CCTPSpi(void);
public:

#pragma region �麯��
	
	//���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷���������
#pragma region  ����
virtual void OnFrontConnected();
	void SetFrontConnectedCallback(FrontConnectedCallback ptr2F);

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	virtual void OnFrontDisconnected(int nReason);
	void SetFrontDisconnectedCallback(FrontDisconnectedCallback ptr2F);
#pragma endregion  ����


#pragma region ����
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷���������
	virtual void OnHeartBeatWarning(int nTimeLapse);
	void SetHeartBeatWarningCallback(HeartBeatWarningCallback ptr2F);
#pragma endregion ����

#pragma region ��¼
	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);	
	void SetRspUserLoginCallback(RspUserLoginCallback ptr2F);
	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspUserLogoutCallback(RspUserLogoutCallback ptr2F);
#pragma endregion ��¼

#pragma region ����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspErrorCallback(RspErrorCallback pt2F);
#pragma endregion ����Ӧ��


#pragma region ����
	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) ;
	void SetRtnOrderCallback(RtnOrderCallback pt2F);

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) ;
	void SetRtnTradeCallback(RtnTradeCallback pt2F);

	///��������������Ӧ
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspOrderActionCallback(RspOrderActionCallback pt2F);

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspOrderInsertCallback(RspOrderInsertCallback pt2F);

	///������������ر�
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;
	void SetErrRtnOrderActionCallback(ErrRtnOrderActionCallback pt2F);

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;
	void SetErrRtnOrderInsertCallback(ErrRtnOrderInsertCallback pt2F);

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryTradeCallback(RspQryTradeCallback pt2F);

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryTradingCodeCallback(RspQryTradingCodeCallback pt2F);

	///�����ѯ����֪ͨ��Ӧ
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryTradingNoticeCallback(RspQryTradingNoticeCallback pt2F);

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryOrderCallback(RspQryOrderCallback pt2F);
#pragma endregion ����


#pragma region �˻�
	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryTradingAccountCallback(RspQryTradingAccountCallback pt2F);
	
	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryInvestorCallback(RspQryInvestorCallback pt2F);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	void SetRspQryInvestorPositionCallback(RspQryInvestorPositionCallback pt2F);

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetRspSettlementInfoConfirmCallback(RspSettlementInfoConfirmCallback pt2F);
#pragma endregion �˻�
#pragma endregion �麯��

	private:		
			CThostFtdcRspInfoField* repareInfo(CThostFtdcRspInfoField *pRspInfo);
			// �Ƿ��յ��ɹ�����Ӧ
			bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
			// �Ƿ��ҵı����ر�
			bool IsMyOrder(CThostFtdcOrderField *pOrder);
			// �Ƿ����ڽ��׵ı���
			bool IsTradingOrder(CThostFtdcOrderField *pOrder);

		
};

}