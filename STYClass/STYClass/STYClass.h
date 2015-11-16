// STYClass.h
#include "SyntheticIndex.h"
#include "Future.h"
#include "CInterfaceStruct.h"
#include "StrategyBase.h"
#pragma once

using namespace System;

////////////���ú���//////////////////
inline char *  getExchangeNumByStockCode(char *Security_code) 
{
	int stkCode = atoi(Security_code);
	int nflag = stkCode / 10000;
	switch (nflag){
	case  0:return "SZ";
	case 16:return "SZ";
	case 15:return "SZ";
	case 20:return "SZ";
	case 18:return "SZ";
	case 30:return "SZ";
	}
	return "SH";
}


inline  char *  weightlisttostring(indexweightstruct *weightlist, int  weightlistnum)
{
	char tempstr[65535];
	tempstr[0] = 0;  //INIT
	char temprow[255];
	for (int i = 0; i <weightlistnum; i++)  //��ȡȨ���б�
	{
		sprintf(temprow, "%s;%c;%.12f|", weightlist[i].sSecurity.cSecurity_code, weightlist[i].sSecurity.cSecuritytype,
			weightlist[i].dweight);
		strcat_s(tempstr, temprow);

	}
	strcat_s(tempstr, "*/0");
	return tempstr;
}

inline  char *  positionlisttostring(stockpotionstruct  *positionlist, int   positionlistnum)
{
	
	char tempstr[65535];
	tempstr[0] = 0;  //INIT
	char temprow[255];
	for (int i = 0; i < positionlistnum; i++)  //��ȡȨ���б�
	{
		sprintf(temprow, "%s;%c;%d|", positionlist[i].sSecurity.cSecurity_code, positionlist[i].sSecurity.cSecuritytype, positionlist[i].ntradervolume);
		strcat(tempstr, temprow);

	}
	strcat(tempstr, "*/0");
	return tempstr;
}

inline  bool stringtoweightlist(const char * tempstr,  indexweightstruct *weightlist, int & realweightlistnum)
{
	int colnun[2];
	int i = 0;
	int weightlistnum = 0;
	string strtypetemp(tempstr);
	int rowflag = -1, preflag = -1;
	if (tempstr == 0)
		return 0;

	char temp = tempstr[i];
	while (tempstr[i] != '/0')
	{
		temp = tempstr[i];
		if (tempstr[i] == '*')
			break;
		if (tempstr[i] == '|')  //row
		{
			preflag = rowflag;
			rowflag = i;
			int  k = 0;
			for (int j = preflag; j < rowflag; j++)
			{
				if (tempstr[j] == ';')
				{
					colnun[k] = j;
					k++;
				}
			}
			if (k != 2)
				return false;

			strcpy_s(weightlist[weightlistnum].sSecurity.cSecurity_code, strtypetemp.substr(preflag + 1, colnun[0] - preflag - 1).c_str());
			weightlist[weightlistnum].sSecurity.cSecuritytype = tempstr[colnun[0] + 1];
			weightlist[weightlistnum].dweight = atof(strtypetemp.substr(colnun[1] + 1, rowflag - colnun[1] - 1).c_str());
			weightlistnum++;
		if (weightlistnum > realweightlistnum)
				return false;
		}
		i++;
	}
	return true;
}

inline  bool  stringtopositionlist(const char * tempstr,stockpotionstruct  *positionlist, int  & realpositionlistnum)
{

	int colnun[2];
	int positionlistnum = 0;
	string strtypetemp(tempstr);
	int rowflag=-1, preflag = -1;
	if (tempstr == 0)
		return 0;
	int i = 0;
	while (tempstr[i] != '/0')
	{
		if (tempstr[i] == '*')
			break;
		if (tempstr[i] == '|')  //row
		{
			preflag = rowflag;
			rowflag = i;
			int  k = 0;
			for (int j = preflag; j < rowflag; j++)
			{
				if (tempstr[j] == ';')
				{
					colnun[k] = j;
					k++;
				}
			}
			if (k != 2)
				return false;

			strcpy_s(positionlist[positionlistnum].sSecurity.cSecurity_code, strtypetemp.substr(preflag + 1, colnun[0] - preflag - 1).c_str());
			positionlist[positionlistnum].sSecurity.cSecuritytype = tempstr[colnun[0] + 1];
			positionlist[positionlistnum].ntradervolume= atoi(strtypetemp.substr(colnun[1] + 1, rowflag - colnun[1] - 1).c_str());
			positionlistnum++;
		}
		i++;
		if (positionlistnum > realpositionlistnum)
			return false;
	}
	return true;
}

namespace STYClass
{

	class CIndexFutureArbitrage_close
	{
	public:
		CIndexFutureArbitrage_close(void);
		~CIndexFutureArbitrage_close(void);

	private:
		CFuture                  m_future;             //�ڻ�
		CIndex                   m_index;              //ָ��

		CSyntheticIndex			 m_SyntheticIndex;     //ģ��ָ��

		int    nHands;			//����
		char   indexCode[32];   //ָ��
		char   contractCode[32]; //�ڻ���Լ

		double dStockBonus;		//�ֺ�
		double dGiftValue;		//�͹�
		double dStockOpenCost;  //���ֳɱ�
		double dFutureSellPoint; //�ڻ����ֵ�
		double dOpenedPoint;   //���ֵ�λ
		double dExpectedGain;  //Ԥ������
		double dShortCharge;  //Ԥ������

	private:  //�ڲ�����

		double dTotalStockMarketValue;  //��Ʊ��ֵ
		double 	dStopedStockValue;   //ͣ����ֵ
		double 	dDownlimitStockValue;   //��ͣ��ֵ
		double dTotalStockSellStrike;  //��Ʊ���
		double drealStockIncome; //��ʵ��Ʊ��������
		double dActualStockGain; //��ʵ��Ʊ���棨���Ƿ��� �����

		double dFutureBuyStrike; //�ڻ�������
		double dActualFutureGain;  //��ʵ�ڻ�����

		double  dzerobpgain;  //��0��������
		char statusmsg[255];         //����ԭ�� ��״̬

	public:
		/************���鲿��********/
		bool    updateSecurityInfo(MarketInforStruct *, int &num);      //���������Ϣ  
		bool    getsubscribelist(securityindex**, int& num);            //��ö��ĵĹ�Ʊ �����ڳ�ʼ�����������


		/**********����ִ��*******/
		bool    init();		//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
		bool	calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
		bool	isOpenPointReached();				//�Ƿ�ﵽ���ֵ㣬���飬�ʽ�

		//void logOpenRecord();					//��¼���ּ�¼  д�����ݿ�
		/*****��ʾ����****/
		bool   gettaderargs(IndexFutureArbitragecloseinputargs &realargs);    //���ʵ�������еĲ��� ����samp�ļ�
		bool   getshowstatus(IndexFutureArbitragecloseshowargs & msg);

		/**********��ȡ����*******/
		bool   gettaderlist(Traderorderstruct * *, int &num);

	public:
		IndexFutureArbitragecloseinputargs* m_args;

	};


	class CIndexFutureArbitrage_open
	{

	private: //���Ʋ���

		CFuture                  m_future;             //�ڻ�
		CIndex                   m_index;              //ָ��
		int nHands;									   //�ڻ���������
		CSyntheticIndex			 m_SyntheticIndex;     //ģ��ָ��

		double dExpectOpenDelta;							 //���ֵ�λ
		bool   bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	 ���ڷ��� 

	private:  //�ڲ�����

		double dSimIndex;			   //ģ��ָ����С
		double dSimerrorPre;           //ģ�����ٷֱ� 
		double dSimtraderPre;		 	   //����ָ����С

		double dTotalStockBuyStrike;	//�����Ʊ�ĳ��	
		double dTotalStocksMarketValue;//Ҫ����Ĺ�Ʊ����ֵ(������ͣ��)
		double stopmarketvalue;			 //ͣ����ֵ
		double dFutureSellStrike;		//�����ڻ��ĳ��

		double dOrgDeltaPre;				//ԭʼ���� = �ڻ� -ָ��
		double dPositiveDelta;			//������Ļ��� = 	�ڻ� - ģ��ָ�� -���������ɵ㣩

		char statusmsg[255];         //����ԭ�� ��״̬

	public:
		IndexFutureArbitrageopeninputargs* m_args;


	public:
		CIndexFutureArbitrage_open(void);
		~CIndexFutureArbitrage_open(void);

	public:
		/************���鲿��********/
		bool    updateSecurityInfo(MarketInforStruct *, int &num);      //���������Ϣ  
		bool    getsubscribelist(securityindex**, int& num);            //��ö��ĵĹ�Ʊ �����ڳ�ʼ�����������


		/**********����ִ��*******/
		//bool    init(IndexFutureArbitrageopeninputargs* m);		//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
		bool   init();		//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
		bool	calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
		bool	isOpenPointReached();				//�Ƿ�ﵽ���ֵ㣬���飬�ʽ�

		//void logOpenRecord();					//��¼���ּ�¼  д�����ݿ�
		/*****��ʾ����****/
		bool   gettaderargs(IndexFutureArbitrageopeninputargs &realargs);    //���ʵ�������еĲ��� ����samp�ļ�
		bool   getshowstatus(IndexFutureArbitrageopenshowargs & msg);

		/**********��ȡ����*******/
		bool   gettaderlist(Traderorderstruct **, int &num);
	};

}
