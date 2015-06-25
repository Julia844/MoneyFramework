#include "Stdafx.h"
#include "TraderBassClass.h"

using namespace System;



namespace MCStockLib
{

	

	public ref struct managedTraderorderstruct
	{
		//���ײ���
		char*    cExchangeID;            //������
		char*    cSecurity_code;     // ֤ȯ����
		char*    security_name;      //֤ȯ����
		long    nSecurity_amount;      // ί������
		double  dOrderprice;           // ί�м۸�
		char    cTraderdirection;      // ������𣨼������ֵ�˵����
		char    cOffsetFlag;           //��ƽ��־
		char    cOrderPriceType;       //��������(�޼�  �м�)

		//���Ʋ���
		char    cSecuritytype;          //֤ȯ����	
		char    cOrderlevel;             //�������ȼ� ִ��˳��
		char    cOrderexecutedetail;     //����ִ��ϸ��

		managedTraderorderstruct(String^ mcExchangeID, String^ mcSecurity_code, String^ msecurity_name
			, long mnSecurity_amount, double mdOrderprice, char mcTraderdirection, char mcOffsetFlag
			, char mcOrderPriceType, char mcSecuritytype, char mcOrderlevel, char mcOrderexecutedetail)
		{
			cExchangeID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcExchangeID);
			cSecurity_code = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcSecurity_code);
			security_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(msecurity_name);
			nSecurity_amount = mnSecurity_amount;
			dOrderprice = mdOrderprice;
			cTraderdirection = mcTraderdirection;
			cOffsetFlag = mcOffsetFlag;
			cOrderPriceType = mcOrderPriceType;

			cSecuritytype = mcSecuritytype;
			cOrderlevel = mcOrderlevel;
			cOrderexecutedetail = mcOrderexecutedetail;
				
		};

		Traderorderstruct createInstance()
		{
			Traderorderstruct unmanagedTraderorderstruct;
			//unmanagedTraderorderstruct.cExchangeID = cExchangeID;
			strcpy_s(unmanagedTraderorderstruct.cExchangeID, 21, cExchangeID);
			//unmanagedTraderorderstruct.cSecurity_code = cSecurity_code;
			strcpy_s(unmanagedTraderorderstruct.cSecurity_code, 31, cSecurity_code);
			//unmanagedTraderorderstruct.security_name = security_name;
			strcpy_s(unmanagedTraderorderstruct.security_name, 55, security_name);
			unmanagedTraderorderstruct.nSecurity_amount = nSecurity_amount;
			unmanagedTraderorderstruct.dOrderprice = dOrderprice;
			unmanagedTraderorderstruct.cTraderdirection = cTraderdirection;
			unmanagedTraderorderstruct.cOffsetFlag = cOffsetFlag;
			unmanagedTraderorderstruct.cOrderPriceType = cOrderPriceType;

			unmanagedTraderorderstruct.cSecuritytype = cSecuritytype;
			unmanagedTraderorderstruct.cOrderlevel = cOrderlevel;
			unmanagedTraderorderstruct.cOrderexecutedetail = cOrderexecutedetail;

			return unmanagedTraderorderstruct;
		};
	};


	public ref struct managedLogin
	{
		char* serverAddr;// ��ַ
		int nPort;//�˿�
		char* ZjAccount; //�ʽ�
		char* BROKER_ID  ;   //���ű��
		char*  PASSWORD ;    //����
		char* INVESTOR_ID ;  //�˻�

		Logininfor createInstance()
		{
			Logininfor unmanagedInfo;
			unmanagedInfo.serverAddr = serverAddr;
			unmanagedInfo.nPort = nPort;
			unmanagedInfo.ZjAccount = ZjAccount;
			unmanagedInfo.BROKER_ID = BROKER_ID;
			unmanagedInfo.PASSWORD = PASSWORD;
			unmanagedInfo.INVESTOR_ID = INVESTOR_ID;

			return unmanagedInfo;
		}

		managedLogin(String^ server_addr,int nport,String^ account,String^ broker_id ,String^ password, String^ investor_id)
		{
			serverAddr = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(server_addr);
			ZjAccount = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(account);
			BROKER_ID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(broker_id);
			PASSWORD = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(password);
			INVESTOR_ID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(investor_id);
			nPort = nport;
		}
	};

	public ref struct managedQueryEntrustorderstruct
	{
		char cSecurityType;
		char* cExchangeID;
		char* cOrderSysID;

		managedQueryEntrustorderstruct(char mcSecurityType, String^ mcExchangeID ,String^ mcOrderSysID)
		{
			cExchangeID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcExchangeID);
			cOrderSysID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcOrderSysID);
			cSecurityType = mcSecurityType;
		}

		managedQueryEntrustorderstruct()
		{
			cExchangeID = new char[255];
			cOrderSysID = new char[255];
			cSecurityType = 's';
		}

		QueryEntrustorderstruct createInstance()
		{
			QueryEntrustorderstruct queryEntrust;

			memset(queryEntrust.cExchangeID,0,21);
			memset(queryEntrust.cOrderSysID,0,21);
			
			queryEntrust.cSecuritytype = 0;

			return queryEntrust;
		}
	};
}

