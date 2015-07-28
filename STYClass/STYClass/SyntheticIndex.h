#pragma once
#include "SyntheticSecurity.h"
#include "Stock.h"
#include "Index.h"
#include"list"
#include"map"
using namespace std;  



class CSyntheticIndex:public CSyntheticSecurity
{
  private:
	double  dSimIndex;
	double  marketvalue;
	list<indexweightstruct>  stockweight;  //Ȩ���ļ�CSecurity
	CIndex      m_index;              //ָ��

 public:
    map<securityindex ,CSecurity *>  stockDb;  //��������
	list<stockpotionstruct>   m_positionlist;   //�ֲֽ����ļ�  �ⲿ�ɸ���

 public:
	CSyntheticIndex(void);
   ~CSyntheticIndex(void);

public:
	double  getSimIndex();  //���ģ��ָ��

	double  getrealmarketvalue();  //��ֵ
	double  getrealbuycost();  
	double  getrealsellgain();

	bool    isupdated();    //�����Ƿ����

	bool   init(indexweightstruct * indexweightlist,int weightnum, stockpotionstruct * stockpotionlist,int potionnum,char *indexCode);  //��ʼ����  

	bool   updatepositioninfor();  //������������positon�ļ�

	bool   isSecurityFocused(securityindex   SecurityCode);
	void updateInfo(MarketInforStruct *);
};

