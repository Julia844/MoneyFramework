#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#ifndef __DATASTRUCT_H
#define __DATASTRUCT_H

struct indexweightstruct  //ָ���������ļ�
{
	char       cSecuritytype;          // ֤ȯ����
	char       cSecurity_code[31];     // ֤ȯ����
	double     dweight;				   // Ȩ��
};

struct stockpotionstruct    //�ֲ���ʾ�ļ� 
{
	char       cSecuritytype;          // ֤ȯ����
	char       cSecurity_code[31];     // ֤ȯ����
	int        ntradervolume;		   //����
	bool       bstoped;                //��ǰ״̬���Ƿ�ͣ�ƣ�
	double     dlastprice;             // ��ǰ�۸�
};

/*****************�������***********************************************/
struct  Clientinfor //�ͻ��˱�����Ϣ ����������
{
};

struct Logininfor // ��½��Ϣ
{
	char * serverAddr;// ��ַ
	int nPort;//�˿�
	char * ZjAccount; //�ʽ�
	char * BROKER_ID;   //���ű��
	char *  PASSWORD;    //����
	char * INVESTOR_ID;  //�˻�

	Logininfor()
	{
		serverAddr = "0";
		nPort = 0;
		ZjAccount = "0";
		BROKER_ID = "0";
		PASSWORD = "0";
		INVESTOR_ID = "0";
	}

	void getInit(Logininfor info)
	{
		//strcpy(serverAddr,info.serverAddr);
		strcpy_s(serverAddr, strlen(info.serverAddr), info.serverAddr);
		nPort = info.nPort;
		//strcpy(ZjAccount,info.ZjAccount);
		strcpy_s(ZjAccount, strlen(info.ZjAccount), info.ZjAccount);
		//strcpy(BROKER_ID,info.BROKER_ID);
		strcpy_s(BROKER_ID, strlen(info.BROKER_ID), info.BROKER_ID);
		strcpy(PASSWORD, info.PASSWORD);
		strcpy(INVESTOR_ID, info.INVESTOR_ID);
	}

};

struct Traderorderstruct   //���ױ��������� �깺 ��
{

	//���ײ���
	char    cExchangeID[21];            //������
	char    cSecurity_code[31];     // ֤ȯ����
	char    security_name[55];      //֤ȯ����
	long    nSecurity_amount;      // ί������
	double  dOrderprice;           // ί�м۸�
	char    cTraderdirection;      // ������𣨼������ֵ�˵����
	char    cOffsetFlag;           //��ƽ��־
	char    cOrderPriceType;       //��������(�޼�  �м�)

	//���Ʋ���
	char    cSecuritytype;          //֤ȯ����	
	char    cOrderlevel;             //�������ȼ� ִ��˳��
	char    cOrderexecutedetail;     //����ִ��ϸ��
	//��־��Ϣ
	Clientinfor myclientinfor; //

	void getInit(Traderorderstruct stu)
	{
		memcpy(cExchangeID, stu.cExchangeID, 21);
		memcpy(cSecurity_code, stu.cSecurity_code, 31);
		memcpy(security_name, stu.security_name, 55);
		nSecurity_amount = stu.nSecurity_amount;
		dOrderprice = stu.dOrderprice;
		cTraderdirection = stu.cTraderdirection;
		cOffsetFlag = stu.cOffsetFlag;
		cOrderPriceType = stu.cOrderPriceType;

		cSecuritytype = stu.cSecuritytype;
		cOrderlevel = stu.cOrderlevel;
		cOrderexecutedetail = stu.cOrderexecutedetail;

		myclientinfor = stu.myclientinfor;
	}
};

struct  QueryEntrustorderstruct
{
	char    cSecuritytype;          //֤ȯ����	
	char    cExchangeID[21];            //������
	char	cOrderSysID[21];  	   ///�������
	//��־��Ϣ
	Clientinfor myclientinfor;

	void getInit(QueryEntrustorderstruct entrust)
	{
		cSecuritytype = entrust.cSecuritytype;
		memcpy(cExchangeID, entrust.cExchangeID, 21);
		memcpy(cOrderSysID, entrust.cOrderSysID, 21);
		myclientinfor = entrust.myclientinfor;
	}
};

struct Entrustreturnstruct //ί�лر�
{
	char    cSecurity_code[31];     // ֤ȯ����
	char    security_name[18];
	char	cOrderSysID[21]; 	///�������
	char	cOrderStatus;///����״̬
	char	cOrderType;///��������
	long    nVolumeTotalOriginal;  //ί������
	long	nVolumeTraded;	///��ɽ�����
	long	nVolumeTotal;   ///ʣ������
	long     withdraw_ammount;     //��������
	double   frozen_money;    //  ������/����������
	long     frozen_amount;     //����֤ȯ����
	char	cInsertDate[9];	///��������
	char	cInsertTime[9];	///ί��ʱ��
	char	cCancelTime[9];///����ʱ��
	char  error_msg[255];   //����ԭ��
	//��־��Ϣ
	Clientinfor myclientinfor;
};

struct Bargainreturnstruct  //�ɽ��ر�
{
	char    cSecurity_code[31];         // ֤ȯ����
	char    security_name[18];
	char	cOrderSysID[21]; 			///�������
	char	cOrderStatus;				///����״̬
	char	cOrderType;					///��������
	long    stock_ammount;         		// �ɽ�����
	double  bargain_price;        		// �ɽ��۸�
	double  bargain_money;             	// �ɽ����
	char    bargain_time[9];       		// �ɽ�ʱ��
	long    bargain_no;            		// �ɽ����
	double  unfrozen_money;        //�ⶳ�ʽ���(A����Ч��B�ɷ���0)
	long    unfrozen_amount;         //�ⶳ֤ȯ����(A����Ч��B�ɷ���0)
	//��־��Ϣ
	Clientinfor myclientinfor;
};

struct QueryBalanceSheetReturn
{

};

/*******************�ڻ�ӳ������****************/
struct  FuTuremapinfor
{
	char  OrderRef[31];  //�Զ���
	bool issendfail; //�����Ƿ�ʧ�ܣ�CTP�ܾ����ͣ�
	bool isreject;   //�������Ƿ�ܾ�
	char  errormsg[255];
	QueryEntrustorderstruct  myEntrust;
	Entrustreturnstruct      myoderreturn;
	Bargainreturnstruct      mytraderreturn;
	FuTuremapinfor()
	{
		issendfail = false;
		isreject = false;
	}

};

#endif