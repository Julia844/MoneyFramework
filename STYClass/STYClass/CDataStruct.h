#pragma once
#ifndef __DATASTRUCT_H
#define __DATASTRUCT_H
#include "string.h"

typedef struct securityindex 
{
	char       cSecuritytype;          // ֤ȯ����
	char       cSecurity_code[31];     // ֤ȯ����

  bool operator == (const securityindex & infor1)  
	{
		if (infor1.cSecuritytype == cSecuritytype)
		 {
			 if(strcmp(infor1.cSecurity_code,cSecurity_code)==0)
				 return true;
			 else
				 return false;
		 }

          return false;
    };
  securityindex & operator=(const securityindex & infor1)
  {
	  this->cSecuritytype = infor1.cSecuritytype;
	  strcpy(this->cSecurity_code, infor1.cSecurity_code);
	  return *this;
  }

}securitykey;

struct indexweightstruct  //ָ���������ļ�
{
	securityindex  sSecurity;     // ֤ȯ��Ϣ
	double     dweight;				   // Ȩ��
};

struct stockpotionstruct    //�ֲ���ʾ�ļ� 
{
	securityindex  sSecurity;     // ֤ȯ��Ϣ
	int        ntradervolume;		   //����
	bool       bstoped;                //��ǰ״̬���Ƿ�ͣ�ƣ�
	double     duplimitprice;             // ��ǰ�۸�
	double     ddownlimitprice;             // ��ǰ�۸�
	double     dlastprice;             // ��ǰ�۸�
	bool       isupdate;
};

/*****************�������***********************************************/


struct  Clientinfor //�ͻ��˱�����Ϣ ����������
{
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

	Traderorderstruct(){}
};

struct  QueryEntrustorderstruct 
{
	char    cSecuritytype;          //֤ȯ����	
	char    cExchangeID[21];            //������
	char	cOrderSysID[21];  	   ///�������
	//��־��Ϣ
	Clientinfor myclientinfor;
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
	//��־��Ϣ
	Clientinfor myclientinfor;
};

struct Bargainreturnstruct  //�ɽ��ر�
{
	char    cSecurity_code[31];			// ֤ȯ����
	char    security_name[18];
	char	cOrderSysID[21]; 			///�������
	char	cOrderStatus;				///����״̬
	char	cOrderType;					///��������
	long    stock_ammount;         		// �ɽ�����
	double  bargain_price;        		// �ɽ��۸�
	double  bargain_money;             	// �ɽ����
	char    bargain_time[9];       		// �ɽ�ʱ��
	long    bargain_no;            		// �ɽ����
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
		issendfail=false;
		isreject=false;
	}

};

#endif