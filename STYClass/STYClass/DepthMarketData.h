#include <string.h>
#include "CDataStruct.h"
#pragma once
struct MarketInforStruct
{
	securityindex msecurity;
	char    security_name[18];		//����
    int		nTime;					//ʱ��(HHMMSSmmm)
    int		nStatus;				//״̬
    double  nPreClose;				//ǰ���̼�
    double  dLastPrice;				//���¼�
    double  dAskPrice[10];			//������
    double  dAskVol[10];			//������
    double  dBidPrice[10];			//�����
    double  dBidVol[10];			//������
    double  dHighLimited;			//��ͣ��
    double  dLowLimited;			//��ͣ��

	void update(MarketInforStruct * lastmarketinfor )
	{
		memcpy(this,lastmarketinfor,sizeof(MarketInforStruct));
	  
	};
};

class CDepthMarketData
{
public:
	 CDepthMarketData(void);
	~CDepthMarketData(void);
 
public:
	
	int    nMarketdepth;        //�г����
    securityindex msecurity;
	
public:
	bool  bupdated;			    //����ʱ���ж���������ӳ�ʱ��
	bool  bStoped;              //״̬λ   ͣ��  ��������  �۶�
	int LastUpdateTime;  //�������¸���ʱ��
	int nInfotLag;   //������¼��

public:
   MarketInforStruct marketinfor;

};

