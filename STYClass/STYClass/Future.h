#pragma once
#include "security.h"
class CFuture :
	public CSecurity
{
public:
	CFuture(void);
	~CFuture(void);

public:
	int   indextimes;   //ָ�����Ӧ�����ı���  
public:
	int   getfuturetime();  //�����ڻ�������ָ������
	double  getrealmarketvalue(int namount);

};

