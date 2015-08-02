#include <string.h>
#include "CDataStruct.h"
#pragma once
struct MarketInforStruct
{
	securityindex msecurity;  //key
	int		LastUpdateTime;				//�������½��ܸ���ʱ��(HHMMSSmmm)
	int		nInfotLag;   //������¼��
	bool    bStoped;     //״̬λ   ͣ��  ��������  �۶�
	/********ԭʼ����****/
	char    security_name[18];		//����
	int		nTime;					//����ʱ��(HHMMSSmmm)
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
    securityindex msecurity;    //key
public:
	bool  bupdated;			    //����ʱ���ж���������ӳ�ʱ��
            
public:
     MarketInforStruct marketinfor;

};

