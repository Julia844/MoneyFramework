#include "Stdafx.h"
#include "CDataStruct.h"
#include "STYClass.h"


using namespace System;
using namespace STYClass;

namespace managedSTY
{
	

	public ref struct managedsecurityindex{
		char cSecuritytype;
		String^ cSecurity_code;

		securityindex GetInstance(){
			char* code = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cSecurity_code);
			securityindex m;
			m.cSecuritytype = cSecuritytype;
			strcpy_s(m.cSecurity_code, 31, code);

			return m;
		}
	};

	public ref struct managedIndexWeights{
		managedsecurityindex^ sSecurity; //֤ȯ��Ϣ
		double dweight;  //Ȩ��

		indexweightstruct GetInstance(){
			indexweightstruct* m = new indexweightstruct();
			m->sSecurity = sSecurity->GetInstance();
			m->dweight = dweight;

			return *m;
		}
	};

	public ref struct managedstockposition {
		managedsecurityindex^ sSecurity; //֤ȯ��Ϣ
		int tradevolume; //����
		bool bstoped;    //��ǰ״̬(�Ƿ�ͣ��)
		double dlastprice;  //��ǰ�۸�

	     stockpotionstruct  GetInstance(){
			stockpotionstruct* m = new stockpotionstruct();
			m->sSecurity = sSecurity->GetInstance();
			m->ntradervolume = tradevolume;
			m->bstoped = bstoped;
			m->dlastprice = dlastprice;

			return *m;
		}
	};

	public ref struct open_args{
		array<managedIndexWeights^>^ weightlist; //Ȩ���ļ�
		int weightlistnum; //Ȩ���ļ�����

		array<managedstockposition^>^ positionlist; //��ʾ�ֲ�
		int positionlistNUM;

		int nHands; //����
		String^ indexCode; //ָ��
		String^ contractCode; //�ڻ���Լ
		double dPositiveOpenDelta; //���ֵ�λ

		bool bTradingAllowed;  //�Ƿ�������
	};

	public ref struct close_args{
		array<managedIndexWeights^>^ weightlist;//Ȩ���ļ�
		int weightlistnum; //Ȩ���ļ�����

		array<managedstockposition^>^ positionlist; //��ʾ�ֲ�
		int positionlistNUM;

		int nHands; //����
		String^ indexCode; //ָ��
		String^ contractCode; //�ڻ���Լ

		double dStockBonus = 0;		//�ֺ�
		double dGiftValue = 0;		//�͹�
		double dStockOpenCost = 0;  //���ֳɱ�
		double dFutureSellPoint = 0; //�ڻ����ֵ�

		double dOpenedPoint = 0;   //���ֻ����λ
		double dExpectedGain = 0;  //Ԥ������
		double dShortCharge = 0;  //Ԥ������

		bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	
	};

	public ref struct managedMarketInforStruct{
		managedsecurityindex^ msecurity;
		String^    security_name;		//����
		String^    exchangeID;			//������
		int		nTime;					//ʱ��(HHMMSSmmm)
		int		nStatus;				//״̬
		double  nPreClose;				//ǰ���̼�
		double  dLastPrice;				//���¼�
		array<double>^  dAskPrice;		//������
		array<double>^  dAskVol;		//������
		array<double>^  dBidPrice;		//�����
		array<double>^  dBidVol;		//������
		double  dHighLimited;			//��ͣ��
		double  dLowLimited;			//��ͣ��

		bool bstoped;					//״̬λ   ͣ��  ��������  �۶�
		int nInfotLag;					//������¼��
		int LastUpdateTime;				//�������½��ܸ���ʱ��(HHMMSSmmm)

		MarketInforStruct CreateInstance(){
			MarketInforStruct m;
			strcpy_s(m.security_name, 18, (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(security_name));
			m.nTime = nTime;
			m.nStatus = nStatus;
			m.nPreClose = nPreClose;
			m.dLastPrice = dLastPrice;
			
			for (int i = 0; i < 10; i++)
			{
				m.dAskPrice[i] = dAskPrice[i];
				m.dAskVol[i] = dAskVol[i];
				m.dBidPrice[i] = dBidPrice[i];
				m.dBidVol[i] = dBidVol[i];
			}

			m.dHighLimited = dHighLimited;
			m.dLowLimited = dLowLimited;

			m.bStoped = bstoped;
			m.nInfotLag = nInfotLag;
			m.LastUpdateTime = LastUpdateTime;
		

			m.msecurity = msecurity->GetInstance();

			return m;
		};
	};

	public ref struct managedTraderorderstruct
	{
		//���ײ���
		String^    cExchangeID;            //������
		String^    cSecurity_code;     // ֤ȯ����
		String^    security_name;      //֤ȯ����
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
			//cExchangeID = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcExchangeID);
			//cSecurity_code = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mcSecurity_code);
			//security_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(msecurity_name);
			cExchangeID = mcExchangeID;
			cSecurity_code = mcSecurity_code;
			security_name = msecurity_name;
			nSecurity_amount = mnSecurity_amount;
			dOrderprice = mdOrderprice;
			cTraderdirection = mcTraderdirection;
			cOffsetFlag = mcOffsetFlag;
			cOrderPriceType = mcOrderPriceType;

			cSecuritytype = mcSecuritytype;
			cOrderlevel = mcOrderlevel;
			cOrderexecutedetail = mcOrderexecutedetail;

		};

		managedTraderorderstruct(){}

		void SetInstance(Traderorderstruct m){
			cExchangeID = gcnew String(m.cExchangeID);
			cSecurity_code = gcnew String(m.cSecurity_code);
			security_name = gcnew String(m.security_name);
			nSecurity_amount = m.nSecurity_amount;
			dOrderprice = m.dOrderprice;
			cTraderdirection = m.cTraderdirection;
			cOffsetFlag = m.cOffsetFlag;
			cOrderPriceType = m.cOrderPriceType;

			cSecuritytype = m.cSecuritytype;
			cOrderlevel = m.cOrderlevel;
			cOrderexecutedetail = m.cOrderexecutedetail;
		}

		Traderorderstruct createInstance()
		{
			Traderorderstruct unmanagedTraderorderstruct;
			char* exchangeid = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cExchangeID);
			strcpy_s(unmanagedTraderorderstruct.cExchangeID, 21, exchangeid);
			char* securitycode = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cSecurity_code);
			strcpy_s(unmanagedTraderorderstruct.cSecurity_code, 31, securitycode);
			char* securityname = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(security_name);
			strcpy_s(unmanagedTraderorderstruct.security_name, 55, securityname);

			unmanagedTraderorderstruct.nSecurity_amount = nSecurity_amount;
			unmanagedTraderorderstruct.dOrderprice = dOrderprice;
			unmanagedTraderorderstruct.cTraderdirection = cTraderdirection;
			unmanagedTraderorderstruct.cOffsetFlag = cOffsetFlag;
			unmanagedTraderorderstruct.cOrderPriceType = cOrderPriceType;

			unmanagedTraderorderstruct.cSecuritytype = cSecuritytype;
			unmanagedTraderorderstruct.cOrderlevel = cOrderlevel;
			unmanagedTraderorderstruct.cOrderexecutedetail = cOrderexecutedetail;

			return unmanagedTraderorderstruct;
		}
	};


	//������ʾ����
	public ref struct managedIndexFutureArbitragecloseshowargs
	{
		double dTotalStockMarketValue = 0;  //��Ʊ��ֵ
		double 	dStopedStockValue = 0;   //ͣ����ֵ
		double 	dDownlimitStockValue = 0;   //��ͣ��ֵ
		double dTotalStockSellStrike = 0;  //��Ʊ���
		double drealStockIncome = 0; //��ʵ��Ʊ��������
		double dActualStockGain = 0; //��ʵ��Ʊ���棨���Ƿ��� �����

		double dFutureBuyStrike = 0; //�ڻ�������
		double dActualFutureGain = 0;  //��ʵ�ڻ�����
		double dtotalgain = 0;		 //ȫ������
		double  dzerobpgain = 0;	 //��0��������
		String^ statusmsg;			//����ԭ�� ��״̬
	};

	public ref class Strategy_OPEN
	{
	public:
		Strategy_OPEN();
		virtual ~Strategy_OPEN();

	public:
		/************���鲿��********/
		void updateSecurityInfo(array<managedMarketInforStruct^>^ marketinfo, int num); //���������Ϣ
		array<managedsecurityindex^>^ getsubscribelist();
		//bool getsubscribelist(array<managedsecurityindex^>^ securityIndex, int num);//��ö��ĵĹ�Ʊ�������ڳ�ʼ�������

		/**********����ִ��*******/
		void init(open_args^ m); //��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
		void calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
		void isOpenPointReached(bool^ open); //�Ƿ�ﵽ���ֵ㣬���飬�ʽ�

		/*****��ʾ����****/
		//bool   gettaderargs(open_args^ realargs);    //���ʵ�������еĲ��� ����samp�ļ�
		void getshowstatus(String^ status); 

		/**********��ȡ����*******/
		array<managedTraderorderstruct^>^ getTradeList();

	private:
		CIndexFutureArbitrage_open* m_open_strategy;
	};

	public ref class Strategy_CLOSE
	{
	public :
		Strategy_CLOSE();
		virtual ~Strategy_CLOSE();

	public:
		/************���鲿��********/
		void updateSecurityInfo(array<managedMarketInforStruct^>^ marketinfo, int num);//���������Ϣ
		array<managedsecurityindex^>^ getsubscribelist();

		/**********����ִ��*******/
		void init(close_args^ m);
		void calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
		void isOpenPointReached(bool^ open); //�Ƿ�ﵽ���ֵ㣬���飬�ʽ�

		/*****��ʾ����****/
		//close_args^ gettradeargs();
		managedIndexFutureArbitragecloseshowargs^ getshowstatus();

		/**********��ȡ����*******/
		array<managedTraderorderstruct^>^ getTradeList();

	private:
		CIndexFutureArbitrage_close* m_close_strategy;
	};
}