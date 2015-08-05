// STYClass.h
#include "SyntheticIndex.h"
#include "Future.h"
#include "CInterfaceStruct.h"
#include "StrategyBase.h"
#pragma once

using namespace System;

namespace STYClass 
{



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
	 CIndexFutureArbitrage_open(void);
	~CIndexFutureArbitrage_open(void);

public:
    /************���鲿��********/
	bool    updateSecurityInfo(MarketInforStruct *,int &num);      //���������Ϣ  
    bool    getsubscribelist(securityindex*,int& num);            //��ö��ĵĹ�Ʊ �����ڳ�ʼ�����������

	
   /**********����ִ��*******/
	bool    init(IndexFutureArbitrageopeninputargs* m);		//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
	bool	calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
	bool	isOpenPointReached();				//�Ƿ�ﵽ���ֵ㣬���飬�ʽ�
	
	//void logOpenRecord();					//��¼���ּ�¼  д�����ݿ�
	/*****��ʾ����****/
	bool   gettaderargs(IndexFutureArbitrageopeninputargs &realargs);    //���ʵ�������еĲ��� ����samp�ļ�
	bool   getshowstatus(IndexFutureArbitrageopenshowargs & msg);

	 /**********��ȡ����*******/
	bool   gettaderlist(Traderorderstruct *, int &num);  
};

}
