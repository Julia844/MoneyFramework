#pragma once
#include "syntheticsecurity.h"
class CSyntheticOptionUnderlying :
	public CSyntheticSecurity
{
public:
	CSecurity * m_underlying;  //���
public:
	CSyntheticOptionUnderlying(void);
	~CSyntheticOptionUnderlying(void);
};

