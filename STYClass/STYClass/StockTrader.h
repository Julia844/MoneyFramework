#pragma once
#include "stdafx.h"
#include "AGCClient.h"
#include "defines.h"
#include "CDataStruct.h"

#pragma comment(lib, "WS2_32")
#pragma pack(4)
class CStockTrader
{
public:
	CStockTrader(void);
	~CStockTrader(void);


public:
	bool init(Logininfor mylogininfor,char * Errormsg);  //���ز���,��½
	bool trader(Traderorderstruct  mytraderoder, QueryEntrustorderstruct &myEntrust,char * Errormsg);      //����֤ȯ����,myEntrust���÷���ί�б��
	bool Batchstocktrader(Traderorderstruct * mytraderoder,int nSize,QueryEntrustorderstruct * myEntrust,int &num,char * Errormsg); //���֤ȯ����,myEntrust���÷���ί�б��
	bool canceltrader( QueryEntrustorderstruct myEntrust,char * Errormsg);      //���� 
	bool queryorder( QueryEntrustorderstruct myEntrust ,Entrustreturnstruct * myoderreturn,int &num,char * Errormsg);      //��ѯί��
	bool querytrader( QueryEntrustorderstruct myEntrust,Bargainreturnstruct * mytraderreturn,int &num,char * Errormsg);      //��ѯ�ɽ�
	bool queryBalanceSheet(QueryBalanceSheetReturn & pRetunResult);   //��ѯ�ʽ�״̬
	bool heartBeat();  //��������
	bool getconnectstate();//  ���ؽ������ δ���� 
	bool getworkstate(); //�����Ƿ�ռ��

private:
	void loadArgs(char * SERVER_IP,int N_PORT,char *ZJ_ACCOUNT,char *PASSWORD);//���ز���(�˺ţ����룬��������ַ��
	bool connectToServer();//���ӵ�������
	bool openAccount();//�ȴ��˺�
	bool login();//Ȼ���½�û�,�õ���֤A�ɺ�����A�ɵ��˺�	

	//bool buyBatchStocks(SampleStock * stocksToBuy,int nSize);//��������
	//bool sellBatchStocks(SampleStock * stocksToSell,int nSize);//��������
	bool queryEntrustStatusByCode(int nEntrustCode);//��ѯ����״̬(��ʱû�ã�
	char * getErrorCodeMsg(int nErrorCode);//ͨ������ŵõ������ı���Ϣ
	bool queryBalanceSheet(SWI_QueryBalanceSheetReturn * pRetunResult);//��ѯ�ʽ�״̬
	bool closeAccount();//�ر��˺�
	int getExchangeNumByStockCode(int stkCode);

private:
	/************����************/
	SOCKET sock;//socket

	char  serverIP[255];//ip��ַ
	char  ZjAccount[55];//�ʽ��˺�
	int    nPort;//�˿�
	char  ShAccount[55];//�Ϻ�A���˺�(loginʱ���Զ���ã�
	char  SzAccount[55];//����A���˺�(loginʱ���Զ���ã�
	char  password[55];//��������
	int  nDept;//���ű�ţ�ͨ���ʽ��˺Ž����ó�����loadArgs�У�


	bool bConnected;//���ӳɹ�ʱ��Ϊtrue	
	bool bRunning;  //�Ƿ���������
	int Id;//����һ����ţ��Ա��ڵ��Թ�����
	
};

