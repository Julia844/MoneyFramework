// STYClass.h
#include "SyntheticIndex.h"
#include "Future.h"
#include "CInterfaceStruct.h"
#include "StrategyBase.h"
#pragma once

using namespace System;

namespace STYClass 
{

struct IndexFutureArbitrageopenargs
{
	int    nHands;      //����
	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ
    double dPositiveOpenDelta;    //���ֵ�λ

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	

};

class CIndexFutureArbitrage_open
{

private:
	CSyntheticIndex			 m_SyntheticIndex;      //��Ʊ���
	CFuture                  m_future;             //�ڻ�
	CIndex                   m_index;              //ָ��


   Traderorderstruct *       m_stockorders;		  //ί���б�
   int    stockordernum;                 //ί������
	
private:
	bool   isargsupdate;			 //�ͻ��˲����Ƿ����
	double dPositiveDelta;			//������Ļ��� = 	�ڻ� - ģ��ָ�� -���������ɵ㣩
	double dTotalStockBuyStrike;	//�����Ʊ�ĳ��	
	double dFutureSellStrike;		//�����ڻ��ĳ��
	double dOrgDelta;				//ԭʼ���� = �ڻ� -ָ��	
	double dTotalStocksMarketValue;//Ҫ����Ĺ�Ʊ����ֵ(������ͣ��)
	double dSimIndex;			   //ģ��ָ��
	double dSimerror;
	double dTradeIndex;		 	   //����ָ��
	
   IndexFutureArbitrageopenargs      m_indexfuturearbitrageopenargs;//�ӿ��ļ�����

public:
	 CIndexFutureArbitrage_open(void);
	~CIndexFutureArbitrage_open(void);

public:
    /************���鲿��********/
	bool    updateSecurityInfo(MarketInforStruct *,int &num);      //���������Ϣ  
    bool    getsubscribelist(securityindex*,int& num);            //��ö��ĵĹ�Ʊ �����ڳ�ʼ�����������

	

   /**********����ִ��*******/
	bool   init(IndexFutureArbitrageopeninputargs      m_indexfuturearbitrageopenargs);		//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�  
	bool calculateSimTradeStrikeAndDelta(); //����ģ��ָ��������ָ������������
	bool isOpenPointReached();				//�Ƿ�ﵽ���ֵ㣬���飬�ʽ�
	
	//void logOpenRecord();					//��¼���ּ�¼  д�����ݿ�
	/*****��ʾ����****/
	bool   gettaderargs(IndexFutureArbitrageopeninputargs &realargs);    //���ʵ�������еĲ��� ����samp�ļ�
	bool   getshowstatus(char *);
	 /**********��ȡ����*******/
	bool   gettaderlist(Traderorderstruct *, int &num);  
};

}
