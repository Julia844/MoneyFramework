#pragma once
#include "SyntheticSecurity.h"
#include "Stock.h"
#include "Index.h"
#include"list"
#include"map"
using namespace std;  



class CSyntheticIndex:public CSyntheticSecurity  //���������weight�ļ� �����
{
  private:
	list<indexweightstruct>  stockweight;  //Ȩ���ļ�CSecurity
	CIndex      m_index;              //ָ��

 public:
    map<securityindex ,CSecurity *>  stockDb;  //��������
	list<stockpotionstruct>   m_positionlist;   //�ֲֽ����ļ�  �ⲿ�ɸ���

 public:
	CSyntheticIndex(void);
   ~CSyntheticIndex(void);

public:
	double  getSimIndex();  //���weight�ļ�ģ��ָ��

	double  getrealmarketvalue(double & stopmarketvalue);  //postion�б���ֵ
	double  getrealbuycost();      //����ɱ�
	double  getrealsellgain();     //��������

	bool    isupdated();    //DB�����Ƿ����

	bool   init(indexweightstruct * indexweightlist,int weightnum, stockpotionstruct * stockpotionlist,int potionnum,char *indexCode);  //��ʼ����  

	bool   updatepositioninfor();  //����positon�ļ�����ȡ�۸��״̬

	bool   isSecurityFocused(securityindex   SecurityCode);

	void updateInfo(MarketInforStruct *); //����stockDB�е�����
};

