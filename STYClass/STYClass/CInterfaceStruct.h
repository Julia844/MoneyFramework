#ifndef __INTERFACESTRUCT_H
#define __INTERFACESTRUCT_H
#include "CDataStruct.h"

struct IndexFutureArbitrageopeninputargs  //�����������
{
	indexweightstruct *       weightlist;			 //Ȩ���ļ�
	int   weightlistnum;  //�б�����

	stockpotionstruct   *    positionlist;		 //��ʾ�ֲ�
	int   positionlistnum;  //�б�����

	int    nHands;      //����
	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ
    double dPositiveOpenDelta;    //���ֵ�λ

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	 ���ڷ��� 
};


struct IndexFutureArbitrageopenshowargs  //������ʾ����
{
	/*��������*/
	double  futureprice;       //�ڻ��۸�
	double  indexprice;        //ָ����С
	double  SimIndex;		 //ģ��ָ����С
	double OrgDeltaPre;           //ģ�����ٷֱ� 
	double SimerrorPre;           //ģ�����ٷֱ� 

	/*���岿��*/
	double SimtraderPre;		 	   //�������
	double TotalStocksMarketValue;	//Ҫ����Ĺ�Ʊ����ֵ(������ͣ��)
	double stopmarketvalue;			 //ͣ����ֵ
	double uplimitmarketvalue;       //��ͣ��ֵ
	double dFutureSellStrike;		//�����ڻ��ĳ��
	double TotalStockBuyStrike;		//�����Ʊ�ĳ��	
	double dPositiveDelta;			//������Ļ��� = �ڻ� - ģ��ָ�� -���������ɵ㣩
	char statusmsg[255];			//����ԭ�� ��״̬
};

struct IndexFutureArbitragecloseargs
{
	list<stockpotionstruct>       m_positionlist;		 //��ʾ�ֲ�
	int    nHands;      //����
	char   indexCode[32];   //ָ������
	char   contractCode[32]; //�ڻ���Լ
    double dPositiveOpenDelta;    //���ֵ�λ

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	
};

#endif