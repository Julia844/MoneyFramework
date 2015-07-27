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

	bool  bTradingAllowed;//�Ƿ�������,��"����"ʱ��Ϊtrue	
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