#pragma once
#include "Security.h"
class CStrategyBase
{
public:
	CStrategyBase(void);
	~CStrategyBase(void);
private:
	bool bisnewsubscribed;  //�Ƿ����µ�������Ҫ����
public:
	/************���鲿��********/
	virtual bool    updateSecurityInfo(MarketInforStruct *,int &num)=0;      //���������Ϣ  
	virtual bool    getsubscribelist(securityindex *,int& num)=0;            //��ö��ĵĹ�Ʊ    
	virtual bool    isnewsubscribed(){return bisnewsubscribed;};            //��ȡ�Ƿ���������Ҫ����
	virtual void    setsubscribestatus(bool bstatus ){bisnewsubscribed=bstatus;};    //�������鶩��״̬

	/**********���潻������*******/
	virtual bool    onUpdateArgs()=0;		        //��������
	virtual bool    showStatus()=0;                 //������ʾ����

	/**********����ִ��*******/
	//virtual bool    init()=0;				      //��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�   ��������    
	//bool   loadargs();				//��ʼ�����ã�����Ȩ������  ���¹�Ʊ�б�   ��������   
	bool   cal();
	bool   istraderallowed();

//	bool   gettadersamp(Traderorderstruct *, int &num);  
	bool   getshowstatus(char *);
	/*************����****************************/

	bool   gettaderlist(Traderorderstruct *, int &num);  
	
};

