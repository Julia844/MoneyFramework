#include <string.h>
#include "CDataStruct.h"
#pragma once
struct MarketInforStruct
{
	securityindex msecurity;  //key
	int		LastUpdateTime = 0;				//�������½��ܸ���ʱ��(HHMMSSmmm)
	int		nInfotLag = 100;   //������¼��
	bool    bStoped = true;     //״̬λ   ͣ��  ��������  �۶�
	/********ԭʼ����****/
	char    security_name[18];		//����
	int		nTime = 0;					//����ʱ��(HHMMSSmmm)
	int		nStatus;				//״̬
	double  nPreClose = 0;				//ǰ���̼�
	double  dLastPrice = 0;				//���¼�
	double  dAskPrice[10];			//������
	double  dAskVol[10];			//������
	double  dBidPrice[10];			//�����
	double  dBidVol[10];			//������
	double  dHighLimited = 0;			//��ͣ��
	double  dLowLimited = 0;			//��ͣ��

	void update(MarketInforStruct * lastmarketinfor)
	{
		memcpy(this, lastmarketinfor, sizeof(MarketInforStruct));

	};
};

class CDepthMarketData
{
public:
	CDepthMarketData(void);
	~CDepthMarketData(void);

public:
	int    nMarketdepth;        //�г����
	securityindex msecurity;    //key
public:
	bool  bupdated;			    //����ʱ���ж���������ӳ�ʱ��

public:
	MarketInforStruct marketinfor;

};

