#pragma once
#include "security.h"


class CSyntheticSecurity :
	public CSecurity
{
public:
	CSyntheticSecurity(void);
   ~CSyntheticSecurity(void);

private:
	double  dsimprice;     //ģ��۸�/ָ��
	double  dtraderprice;  //���׼۸񣨿���ͣ�� �����

public:
   virtual  double  getSimIndex()=0;
   double  getSimError();
};

