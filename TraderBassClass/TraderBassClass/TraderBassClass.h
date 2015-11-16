// TraderBassClass.h
#include "AGCClient.h"
#include "CDataStruct.h"
#include "ThostFtdcTraderApi.h"
#include <windows.h>
#include <map>
#pragma once
#pragma comment(lib, "WS2_32")


class CStockTrader
{
public:
	CStockTrader(void);
	~CStockTrader(void);


public:
	bool init(const Logininfor mylogininfor, char * Errormsg);  //���ز���,��½
	bool trader(const Traderorderstruct  mytraderoder, QueryEntrustorderstruct &myEntrust, char * Errormsg);      //����֤ȯ����,myEntrust���÷���ί�б��
	bool Batchstocktrader(const Traderorderstruct * mytraderoder,const  int nSize, QueryEntrustorderstruct **  pmyEntrust, int &num, char * Errormsg); //���֤ȯ����,myEntrust���÷���ί�б��

	bool canceltrader(const QueryEntrustorderstruct myEntrust, char * Errormsg);      //���� 
	bool queryorder(const QueryEntrustorderstruct myEntrust, Entrustreturnstruct * myoderreturn, int &num, char * Errormsg);      //��ѯί��
	bool querytrader(const QueryEntrustorderstruct myEntrust, Bargainreturnstruct * mytraderreturn, int &num, char * Errormsg);      //��ѯ�ɽ�

	bool heartBeat();  //��������
	bool getconnectstate();//  ���ؽ������ δ���� 
	bool getworkstate(); //�����Ƿ�ռ��
	int  cal(char* msg);
private:
	void loadArgs(char * SERVER_IP, int N_PORT, char *ZJ_ACCOUNT, char *PASSWORD);//���ز���(�˺ţ����룬��������ַ��
	bool connectToServer();//���ӵ�������
	bool openAccount();//�ȴ��˺�
	bool login();//Ȼ���½�û�,�õ���֤A�ɺ�����A�ɵ��˺�	

	//bool buyBatchStocks(SampleStock * stocksToBuy,int nSize);//��������
	//bool sellBatchStocks(SampleStock * stocksToSell,int nSize);//��������
	char * getErrorCodeMsg(int nErrorCode);//ͨ������ŵõ������ı���Ϣ
	bool queryBalanceSheet(SWI_QueryBalanceSheetReturn * pRetunResult);//��ѯ�ʽ�״̬

private:
	/************����************/
	SOCKET sock;//socket

	char  serverIP[49];//ip��ַ
	char  ZjAccount[49];//�ʽ��˺�
	int nPort;//�˿�
	char  ShAccount[49];//�Ϻ�A���˺�(loginʱ���Զ���ã�
	char  SzAccount[49];//����A���˺�(loginʱ���Զ���ã�
	char  password[49];//��������
	int nDept;//���ű�ţ�ͨ���ʽ��˺Ž����ó�����loadArgs�У�


	bool bConnected;//���ӳɹ�ʱ��Ϊtrue	
	bool bRunning;  //�Ƿ���������
	int Id;//����һ����ţ��Ա��ڵ��Թ�����

};
