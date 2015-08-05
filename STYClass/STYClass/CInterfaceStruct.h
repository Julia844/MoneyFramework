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

struct IndexFutureArbitragecloseinputargs
{
	indexweightstruct *       weightlist;			 //Ȩ���ļ�
	int   weightlistnum;  //�б�����

	stockpotionstruct   *    positionlist;		 //��ʾ�ֲ�
	int   positionlistnum;  //�б�����


	int    nHands;			//����
	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ

	double dStockBonus;		//�ֺ�
	double dGiftValue;		//�͹�
	double dStockOpenCost;  //���ֳɱ�
	double dFutureSellPoint; //�ڻ����ֵ�

	double dOpenedPoint;   //���ֻ����λ
	double dExpectedGain;  //Ԥ������
	double dShortCharge;  //Ԥ������

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	
};


struct IndexFutureArbitragecloseshowargs  //������ʾ����
{
	double dTotalStockMarketValue;  //��Ʊ��ֵ
	double 	dStopedStockValue;   //ͣ����ֵ
	double 	dDownlimitStockValue;   //��ͣ��ֵ
	double dTotalStockSellStrike;  //��Ʊ���
	double drealStockIncome; //��ʵ��Ʊ��������
	double dActualStockGain; //��ʵ��Ʊ���棨���Ƿ��� �����

	double dFutureBuyStrike; //�ڻ�������
	double dActualFutureGain;  //��ʵ�ڻ�����
	double dtotalgain;		 //ȫ������
	double  dzerobpgain;	 //��0��������
	char statusmsg[255];			//����ԭ�� ��״̬
};
#endif