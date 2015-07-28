#include "StdAfx.h"
#include "SyntheticIndex.h"

bool operator < (const securityindex & infor1,const securityindex &infor2) 
	{
		if (infor1.cSecuritytype == infor2.cSecuritytype)
		 {
			 if(strcmp(infor1.cSecurity_code,infor2.cSecurity_code)<0)
				 return true;
			 else
				 return false;
		 }

       if (infor1.cSecuritytype < infor2.cSecuritytype)
          return true;
      
        else
          return false;
    };

CSyntheticIndex::CSyntheticIndex(void)
{
}
CSyntheticIndex::~CSyntheticIndex(void)
{
}


double  CSyntheticIndex::getSimIndex()
{
	list<indexweightstruct>::iterator itor;
	 itor=stockweight.begin();
	 dSimIndex=0;
	 while(itor!=stockweight.end())
       {    
		   dSimIndex+=itor->dweight*stockDb[itor->sSecurity]->getlastprice();
		  itor++;
       } 
	 return dSimIndex;
}

double  CSyntheticIndex::getrealmarketvalue()
{
	 list<stockpotionstruct>::iterator itor;
	 itor=m_positionlist.begin();
	 marketvalue=0;
	 while(itor!=m_positionlist.end())
       { 
		   marketvalue+=stockDb[itor->sSecurity]->getrealmarketvalue(itor->ntradervolume);
		   itor++;
       } 
	
	 return  marketvalue;
}

double  CSyntheticIndex::getrealbuycost()
{
	 list<stockpotionstruct>::iterator itor;
	 itor=m_positionlist.begin();
	 double tempvalue=0;
	 while(itor!=m_positionlist.end())
       { 
		   tempvalue+=stockDb[itor->sSecurity]->getrealbuycost(itor->ntradervolume);
		   itor++;
       } 
	 return tempvalue;
}

double  CSyntheticIndex::getrealsellgain()
{
	 list<stockpotionstruct>::iterator itor;
	 itor=m_positionlist.begin();
	 double tempvalue=0;
	 while(itor!=m_positionlist.end())
       { 
		  tempvalue+=stockDb[itor->sSecurity]->getrealsellgain(itor->ntradervolume);
		   itor++;
       } 
	 return tempvalue;
}

bool    CSyntheticIndex::isupdated()
{

	 map<securityindex ,CSecurity * >::iterator itor;
	 itor=stockDb.begin();
	 while(itor!=stockDb.end())
       { 
		   if(!itor->second->isupdated())
		       return  false;
       } 
 
    return true;
}

bool   CSyntheticIndex::init(indexweightstruct * indexweightlist,int weightnum, stockpotionstruct * stockpotionlist,int positionnum,char *indexCode )
{

	 m_index.setcode(indexCode);   //��ʼָ��


	 stockweight.clear();  //�������Ȩ���ļ�  �ͷ��ڴ�
	 stockDb.clear();      //����
	 m_positionlist.clear();

	for(int i=0;i<weightnum;i++)  
	{
		stockweight.push_back(indexweightlist[i]);//��ȡȨ��
     
	  if(isSecurityFocused(indexweightlist[i].sSecurity))
			continue;

	  if( indexweightlist[i].sSecurity.cSecuritytype=='s') //��ʼ����Ʊ����
		   {

		      stockDb[indexweightlist[i].sSecurity]=new CStock;
			  stockDb[indexweightlist[i].sSecurity]->setcode(indexweightlist[i].sSecurity.cSecurity_code);

		   }
	   else

		return false;

	}

	for(int i=0;i<positionnum;i++)//��ȡ�����б�
	 {
		  m_positionlist.push_back(*(stockpotionlist+i));
	 }

	 return true;
}



bool   CSyntheticIndex::updatepositioninfor()
{
	 list<stockpotionstruct>::iterator itor;
	 itor=m_positionlist.begin();
	 while(itor!=m_positionlist.end())
       { 
		   itor->bstoped=stockDb[itor->sSecurity]->isstoped();
		   itor->dlastprice=stockDb[itor->sSecurity]->getlastprice(); 
		   itor++;
       } 

	 return true;
}

bool   CSyntheticIndex::isSecurityFocused(securityindex  SecurityCode)
	{
		if(this->stockDb.find(SecurityCode) != stockDb.end())
		{ 
		  return true;
	    }
	  return false;
	}

void CSyntheticIndex::updateInfo(MarketInforStruct * MarketInfor )
{
	//if(isSecurityFocused(MarketInfor->msecurity)) //ÿ�����������Ҫ�жϹ�Ʊ�Ƿ���hash����
	{
	   this->stockDb[MarketInfor->msecurity]->updateInfo(MarketInfor);
	}
}
