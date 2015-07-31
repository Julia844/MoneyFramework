#pragma once
#include "DepthMarketData.h"
#include "CDataStruct.h"
#include <Windows.h>
class CSecurity
{
public:
	CSecurity(void);
	~CSecurity(void);
private:
	//HANDLE hlocalDataMutex;//��Ʊ��ָ��������µ���
	
public:
	CDepthMarketData m_DepthMarketData;

public:
	double  getlastprice();
	bool    isstoped();
	virtual bool    isupdated(); 
	virtual double  getrealmarketvalue(int namount);
	virtual double  getrealbuycost(int namount);
	virtual double  getrealsellgain(int namount);

	virtual bool    setcode(char *);      //���ô���  �������� 

	void updateInfo(MarketInforStruct *);
};

