#include "Stdafx.h"
#include "managedSTYClass.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace managedSTY;
using namespace System::Runtime::InteropServices;


Strategy_OPEN::Strategy_OPEN()
{
	m_open_strategy = new CIndexFutureArbitrage_open();
};

Strategy_OPEN::~Strategy_OPEN()
{
	delete m_open_strategy;
};

void Strategy_OPEN::updateSecurityInfo(array<managedMarketInforStruct^>^ marketinfo, int num){
	MarketInforStruct * MarketInfo = new MarketInforStruct[num];
	
	for (int m = 0; m < num; m++){
		for (int i = 0; i < 10; i++)
		{
			MarketInfo->dAskPrice[i] = 0;
			MarketInfo->dAskVol[i] = 0;
			MarketInfo->dBidPrice[i] = 0;
			MarketInfo->dBidVol[i] = 0;
		}
	}

	for (int i = 0; i < num; i++)
	{
		MarketInfo[i] = marketinfo[i]->CreateInstance();
	}
     m_open_strategy->updateSecurityInfo(MarketInfo, num);
};

array<managedsecurityindex^>^ Strategy_OPEN::getsubscribelist(){

	securityindex*  subscribelist = new securityindex[1];
	array<managedsecurityindex^>^ securityIndexs;
	int num;
	if (m_open_strategy->getsubscribelist(&subscribelist, num))
	{
		securityIndexs = gcnew array<managedsecurityindex^>(num);
		for (int i = 0; i < num; i++){
			managedsecurityindex^ index = gcnew managedsecurityindex();
			securityIndexs[i] = gcnew managedsecurityindex();

			index->cSecuritytype = subscribelist[i].cSecuritytype;
			index->cSecurity_code = gcnew String(subscribelist[i].cSecurity_code);\
			securityIndexs[i]->cSecurity_code = gcnew String(index->cSecurity_code);
			securityIndexs[i]->cSecuritytype = index->cSecuritytype;
		
		}
		return securityIndexs;
	}

	return securityIndexs;
}

void Strategy_OPEN::init(open_args^ m){


	IntPtr ptr = Marshal::AllocHGlobal(Marshal::SizeOf(m));
	Marshal::StructureToPtr(m, ptr, false);
	OPENARGS* p = (OPENARGS*)(ptr.ToPointer());
	
	m_open_strategy->m_args = new IndexFutureArbitrageopeninputargs();
	m_open_strategy->m_args->weightlist = new indexweightstruct[1];
	m_open_strategy->m_args->positionlist = new stockpotionstruct[1];

	strcpy_s(m_open_strategy->m_args->weightliststr, 65535, p->weightliststr);
	strcpy_s(m_open_strategy->m_args->positionliststr, 65535, p->positionliststr);

	m_open_strategy->m_args->nHands = p->nHands;
	strcpy_s(m_open_strategy->m_args->indexCode, 32, p->indexCode);
	strcpy_s(m_open_strategy->m_args->contractCode, 32, p->contractCode);

	m_open_strategy->m_args->dPositiveOpenDelta = p->dPositiveOpenDelta;
	m_open_strategy->m_args->bTradingAllowed = p->bTradingAllowed;

	m_open_strategy->m_args->positionlistnum = p->positionlistnum;
	m_open_strategy->m_args->weightlistnum = p->weightlistnum;

	m_open_strategy->init();

}

void Strategy_OPEN::calculateSimTradeStrikeAndDelta(){
	 m_open_strategy->calculateSimTradeStrikeAndDelta();
}

bool Strategy_OPEN::isOpenPointReached(){
	bool b = m_open_strategy->isOpenPointReached();
	return b;
}

String^  Strategy_OPEN::getshowstatus(){

	//char* str = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(status);
	IndexFutureArbitrageopenshowargs* _args = new IndexFutureArbitrageopenshowargs();
	m_open_strategy->getshowstatus(*_args);

	String^ status = "期货价格：" + _args->futureprice + "  " +
		"指数价格：" + _args->indexprice + "  " +
		"模拟指数：" + _args->SimIndex + "  " +
		"原始基差：" + _args->OrgDeltaPre + "  " +
		"模拟误差：" + _args->SimerrorPre + "  " +
		"模拟市值：" + _args->TotalStocksMarketValue + "  " +
		"停盘市值：" + _args->stopmarketvalue + "  " +
		"买入冲击：" + _args->TotalStockBuyStrike + "  " +
		"期货卖出冲击：" + _args->dFutureSellStrike + "  " +
		"调整基差：" + _args->dPositiveDelta + "  " +
		"交易误差：" + _args->SimtraderPre + "  " +
		"状态：" + (gcnew String(_args->statusmsg));

	return status;
}

array<managedTraderorderstruct^>^ Strategy_OPEN::getTradeList(){
	array<managedTraderorderstruct^>^ orderlist;
	Traderorderstruct *m_list=0;

	int m_num;

	bool b = m_open_strategy->gettaderlist(&m_list, m_num);
	orderlist = gcnew array<managedTraderorderstruct^>(m_num);
	if (b == true){
		for (int i = 0; i < m_num; i++){
			orderlist[i] = gcnew managedTraderorderstruct();
			orderlist[i]->SetInstance(m_list[i]);
		}
	}

	return orderlist;
}

Strategy_CLOSE::Strategy_CLOSE(){
	m_close_strategy = new CIndexFutureArbitrage_close();
}

Strategy_CLOSE::~Strategy_CLOSE(){
	delete m_close_strategy;
}

void Strategy_CLOSE::updateSecurityInfo(array<managedMarketInforStruct^>^ marketinfo, int num){
	

	MarketInforStruct * MarketInfo = new MarketInforStruct[num];
	for (int m = 0; m < num; m++){
		for (int i = 0; i < 10; i++)
		{
			MarketInfo[m].dAskPrice[i] = 0;
			MarketInfo[m].dAskVol[i] = 0;
			MarketInfo[m].dBidPrice[i] = 0;
			MarketInfo[m].dBidVol[i] = 0;
		}
	}

	for (int i = 0; i < num; i++)
	{
		MarketInfo[i] = marketinfo[i]->CreateInstance();
	}
	m_close_strategy->updateSecurityInfo(MarketInfo, num);
}

array<managedsecurityindex^>^ Strategy_CLOSE::getsubscribelist(){
	securityindex*  subscribelist = new securityindex[1];
	array<managedsecurityindex^>^ securityIndexs;
	int num;
	if (m_close_strategy->getsubscribelist(&subscribelist, num))
	{
		securityIndexs = gcnew array<managedsecurityindex^>(num);
		for (int i = 0; i < num; i++){
			managedsecurityindex^ index = gcnew managedsecurityindex();
			securityIndexs[i] = gcnew managedsecurityindex();

			index->cSecuritytype = subscribelist[i].cSecuritytype;
			index->cSecurity_code = gcnew String(subscribelist[i].cSecurity_code);
			securityIndexs[i]->cSecurity_code = gcnew String(index->cSecurity_code);
			securityIndexs[i]->cSecuritytype = index->cSecuritytype;

		}
		return securityIndexs;
	}

	return securityIndexs;
}

void Strategy_CLOSE::init(close_args^ m){
	m_close_strategy->m_args = new IndexFutureArbitragecloseinputargs();
	m_close_strategy->m_args->weightlist = new indexweightstruct[1];
	m_close_strategy->m_args->positionlist = new stockpotionstruct[1];


	char* position = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(m->POSITION);
	memset(m_close_strategy->m_args->positionliststr, 0, sizeof(m_close_strategy->m_args->positionliststr));
	strcpy_s(m_close_strategy->m_args->positionliststr, strlen(position)+1, position);


	m_close_strategy->m_args->nHands = m->nHands;
	strcpy_s(m_close_strategy->m_args->indexCode, 32, (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(m->indexCode));
	strcpy_s(m_close_strategy->m_args->contractCode, 32, (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(m->contractCode));

	m_close_strategy->m_args->dStockBonus = m->dStockBonus;
	m_close_strategy->m_args->dGiftValue = m->dGiftValue;
	m_close_strategy->m_args->dStockOpenCost = m->dStockOpenCost;
	m_close_strategy->m_args->dFutureSellPoint = m->dFutureSellPoint;
	m_close_strategy->m_args->dOpenedPoint = m->dOpenedPoint;
	m_close_strategy->m_args->dExpectedGain = m->dExpectedGain;
	m_close_strategy->m_args->positionlistnum = m->positionNum;
	m_close_strategy->m_args->dShortCharge = m->dShortCharge;
	m_close_strategy->m_args->bTradingAllowed = m->bTradingAllowed;

	m_close_strategy->init();
}

void Strategy_CLOSE::calculateSimTradeStrikeAndDelta(){
	m_close_strategy->calculateSimTradeStrikeAndDelta();
}

bool Strategy_CLOSE::isOpenPointReached(){
	bool b = m_close_strategy->isOpenPointReached();
	return b;
}

String^ Strategy_CLOSE::getshowstatus()
{
	IndexFutureArbitragecloseshowargs m;
	

	m_close_strategy->getshowstatus(m);


	String^ status = "真实期货收益：" + m.dActualFutureGain + "  "
		+ "真实股票收益：" + m.dActualStockGain + "  "
		+ "真实股票卖出收益：" + m.drealStockIncome + "  "
		+ "跌停市值：" + m.dDownlimitStockValue + "  "
		+ "期货买入冲击：" + m.dFutureBuyStrike + "  "
		+ "停盘市值：" + m.dStopedStockValue + "  "
		+ "全部收益：" + m.dtotalgain + "  "
		+ "股票市值：" + m.dTotalStockMarketValue + "  "
		+ "股票冲击：" + m.dTotalStockSellStrike + "  "
		+ "状态：" + (gcnew String(m.statusmsg));


	return status;
}

array<managedTraderorderstruct^>^ Strategy_CLOSE::getTradeList(){
	array<managedTraderorderstruct^>^ orderlist;
	Traderorderstruct *m_list = 0;

	int m_num;

	bool b = m_close_strategy->gettaderlist(&m_list, m_num);


	orderlist = gcnew array<managedTraderorderstruct^>(m_num);
	if (b == true){
		for (int i = 0; i < m_num; i++){
			orderlist[i] = gcnew managedTraderorderstruct();
			orderlist[i]->SetInstance(m_list[i]);
		}
	}

	return orderlist;
}