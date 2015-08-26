#ifndef __INTERFACESTRUCT_H
#define __INTERFACESTRUCT_H
#include "CDataStruct.h"

struct IndexFutureArbitrageopeninputargs  //�����������
{
	indexweightstruct *       weightlist=0;			 //Ȩ���ļ�
	int   weightlistnum = 0;  //�б�����

	stockpotionstruct   *    positionlist=0;		 //��ʾ�ֲ�
	int   positionlistnum = 0;  //�б�����

	char   weightliststr[65535];
	char   positionliststr[65535];
	int    nHands = 0;      //����
	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ
	double dPositiveOpenDelta = 0;    //���ֵ�λ

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	 ���ڷ��� 
};

struct OPENARGS
{
	

	char weightliststr[65535];
	char positionliststr[65535];

	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ

	int    nHands = 0;      //����
	double dPositiveOpenDelta = 0;    //���ֵ�λ

	int   weightlistnum = 0;  //�б�����
	int   positionlistnum = 0;  //�б�����

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	 ���ڷ��� 
};


struct IndexFutureArbitrageopenshowargs  //������ʾ����
{
	/*��������*/
	double  futureprice = 0;       //�ڻ��۸�
	double  indexprice = 0;        //ָ����С
	double  SimIndex = 0;		 //ģ��ָ����С
	double OrgDeltaPre = 0;           //ģ�����ٷֱ� 
	double SimerrorPre = 0;           //ģ�����ٷֱ� 

	/*���岿��*/
	double SimtraderPre = 0;		 	   //�������
	double TotalStocksMarketValue = 0;	//Ҫ����Ĺ�Ʊ����ֵ(������ͣ��)
	double stopmarketvalue = 0;			 //ͣ����ֵ
	double uplimitmarketvalue = 0;       //��ͣ��ֵ
	double dFutureSellStrike = 0;		//�����ڻ��ĳ��
	double TotalStockBuyStrike = 0;		//�����Ʊ�ĳ��	
	double dPositiveDelta;			//������Ļ��� = �ڻ� - ģ��ָ�� -���������ɵ㣩
	char statusmsg[255];			//����ԭ�� ��״̬
};

struct IndexFutureArbitragecloseinputargs
{
	indexweightstruct *       weightlist=0;			 //Ȩ���ļ�
	int   weightlistnum = 0;  //�б�����

	stockpotionstruct   *    positionlist=0;		 //��ʾ�ֲ�
	int   positionlistnum = 0;  //�б�����

	char  weightliststr[65525];
	char   positionliststr[65535];
	int    nHands = 0;			//����
	char   indexCode[32];   //ָ��
	char   contractCode[32]; //�ڻ���Լ

	double dStockBonus = 0;		//�ֺ�
	double dGiftValue = 0;		//�͹�
	double dStockOpenCost = 0;  //���ֳɱ�
	double dFutureSellPoint = 0; //�ڻ����ֵ�

	double dOpenedPoint = 0;   //���ֻ����λ
	double dExpectedGain = 0;  //Ԥ������
	double dShortCharge = 0;  //Ԥ������

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	
};


struct IndexFutureArbitragecloseshowargs  //������ʾ����
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
	char statusmsg[255];			//����ԭ�� ��״̬
};
#endif