#include "stdafx.h"
#include <stdio.h>
#include "TraderBassClass.h"
#pragma comment(lib, "WS2_32")

#define EXCHANGE_SH  1
#define EXCHANGE_SZ  2


CStockTrader::CStockTrader(void)
{
	this->bConnected = false;
	bRunning = false;

}
CStockTrader::~CStockTrader(void)
{
}

WORD CalCRC(void *pData, int nDataLen)
{
	WORD acc = 0;
	int i;
	unsigned char* Data = (unsigned char*)pData;

	while (nDataLen--)
	{
		acc = acc ^ (*Data++ << 8);
		for (i = 0; i++ < 8;)
		if (acc & 0x8000)
			acc = (acc << 1) ^ 0x1021;
		else
			acc <<= 1;
	}
	i = ((WORD)(((UCHAR)acc) << 8)) | ((WORD)(acc >> 8));

	return i;
}

bool CStockTrader::init(Logininfor mylogininfor, char * Errormsg)  //���ز���,��½
{
	//״̬����
	Errormsg = "success";
	bRunning = true;
	//���ز�����׼��socket
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	this->loadArgs(mylogininfor.serverAddr, mylogininfor.nPort, mylogininfor.ZjAccount, mylogininfor.PASSWORD);//���ز���

	if (!connectToServer())
	{
		Errormsg = "stockTraders����ʧ��";
		bRunning = false;
		return false;
	}

	if (!openAccount())
	{
		Errormsg = "stockTraders,openAccountʧ��";
		bRunning = false;
		return false;
	}

	if (!login())
	{
		Errormsg = "stockTraders,loginʧ��";
		bRunning = false;
		return false;
	}

	this->bConnected = true;
	bRunning = false;
	return true;
}

bool CStockTrader::trader(Traderorderstruct  mytraderoder, QueryEntrustorderstruct &myEntrust, char * Errormsg)
{
	//״̬����
	Errormsg = "success";
	bRunning = true;

	//���ͽ�������

	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_AddEntrustRequest  *pReqMsg;
	pReqMsg = (SWI_AddEntrustRequest*)(buf);

	int n = sizeof(SWI_BlockHead);
	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_AddEntrustRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x201;

	if (!strcmp(mytraderoder.cExchangeID, "SZ"))//�����г�
	{
		pReqMsg->account_type = '2';
		pReqMsg->exchange_no = 2;
		strcpy(pReqMsg->account, SzAccount);
	}
	else
	{
		pReqMsg->account_type = '1';
		pReqMsg->exchange_no = 1;
		strcpy(pReqMsg->account, ShAccount);
	}

	pReqMsg->bs_type = mytraderoder.cTraderdirection;   // ������𣨼������ֵ�˵����
	strcpy(pReqMsg->security_code, mytraderoder.cSecurity_code);  //֤ȯ����
	pReqMsg->stock_amount = mytraderoder.nSecurity_amount; //����
	if (mytraderoder.cSecuritytype == 's')
		pReqMsg->price = ((int)(mytraderoder.dOrderprice * 100)) * 10;  //��Ʊֻ����λ����
	else
		pReqMsg->price = (int)(mytraderoder.dOrderprice * 1000);

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		Errormsg = "send to agc error";
		bRunning = false;
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8) {
			Errormsg = "parse length error!\n";
			bRunning = false;
			return false;
		}
		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8)
		{
			Errormsg = "parse length error!";
			bRunning = false;
			return false;
		}
		SWI_AddEntrustReturn * pAddEntrustRtn = (SWI_AddEntrustReturn*)buf;
		if (pAddEntrustRtn->return_status > 0)
		{
			bRunning = false;
			sprintf(myEntrust.cOrderSysID, "%d", pAddEntrustRtn->entrust_sn);
			return true;
		}
		else
		{
			strcpy(Errormsg, getErrorCodeMsg(pAddEntrustRtn->return_status));
			bRunning = false;
			return false;
		}
	}
	Errormsg = "none konw";
	bRunning = false;
	return false;


}

bool CStockTrader::Batchstocktrader(Traderorderstruct * mytraderoder, int nSize, QueryEntrustorderstruct * myEntrust, int &num, char * Errormsg)
{
	//״̬����
	strcpy(Errormsg, "success");
	bRunning = true;
	num = 0;

	bool bRtn = true;
	if (nSize <= 0)
	{
		bRunning = true;
		return true;
	}

	int    len, in_len;
	char   buf[2048], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_BatchEntrustRequest  *pReqMsg;
	pReqMsg = (SWI_BatchEntrustRequest*)(buf);
	int n = sizeof(SWI_BlockHead);
	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_BatchEntrustRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x205;

	pReqMsg->detail_block_size = nSize * sizeof(SWI_BatchDetail);
	pReqMsg->implement_mode = '1';
	pReqMsg->trade_interval = 2;
	if (!strcmp(mytraderoder[0].cExchangeID, "SH"))
	{//��֤
		strcpy(pReqMsg->account, ShAccount);
		pReqMsg->exchange_no = 1;
		pReqMsg->account_type = '1';
	}
	else
	{//����
		strcpy(pReqMsg->account, SzAccount);
		pReqMsg->exchange_no = 2;
		pReqMsg->account_type = '2';
	}
	int i = 0;
	for (; i < nSize; i++)
	{
		pReqMsg->detail_buf[i].bs_type = mytraderoder[i].cTraderdirection;
		strcpy(pReqMsg->detail_buf[i].security_code, mytraderoder[i].cSecurity_code);//��Ʊ����
		pReqMsg->detail_buf[i].price = (long)((mytraderoder[i].dOrderprice) * 1000);	// 			
		pReqMsg->detail_buf[i].stock_amount = mytraderoder[i].nSecurity_amount;//��������		
	}
	pReqMsg->entrust_length = nSize;//������Ŀ��

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		Errormsg = "send to agc error!";

		bRunning = false;
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{

		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8)
		{
			Errormsg = "parse length error!";
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8)
		{
			Errormsg = "parse length error!";
			bRunning = false;
			return false;
		}
		SWI_BatchEntrustResult * pResult = (SWI_BatchEntrustResult*)buf;
		if (pResult->row_no == 0xffff)
		{
			break;
		}
		else  //���ί�б��
		{
			sprintf(myEntrust[num].cOrderSysID, "%d", pResult->entrust_sn);// ί�б��: ����״̬<0Ϊʧ��
			num++;
		}

		if (pResult->return_status <= 0)
		{

			strcpy(Errormsg, pResult->err_msg);
			bRtn = false;
		}

	}
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8)
		{

			Errormsg = "parse length error!";
			bRunning = false;
			return false;
		}
		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8)
		{
			Errormsg = "parse length error!";
			bRunning = false;
			return false;
		}
		SWI_BatchEntrustReturn * pRtn = (SWI_BatchEntrustReturn*)buf;
		if (pRtn->return_status > 0)
		{//�е�ʱ�򣬲��ֱ�����Ŀ�д������ص�return_status���Ǵ���0
			bRunning = false;
			return bRtn;
		}
		else
		{
			strcpy(Errormsg, this->getErrorCodeMsg(pRtn->return_status));
			bRunning = false;
			return false;
		}

	}

	bRunning = false;
	return true;

}

bool  CStockTrader::canceltrader(QueryEntrustorderstruct myEntrust, char * Errormsg)      //���� 
{
	strcpy(Errormsg, "success");
	bRunning = true;

	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_WithdrawEntrustRequest  *pReqMsg;
	pReqMsg = (SWI_WithdrawEntrustRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_WithdrawEntrustRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x202;

	if (!strcmp(myEntrust.cExchangeID, "SZ"))//�����г�)
	{
		pReqMsg->account_type = '2';
		pReqMsg->exchange_no = 2;
		strcpy(pReqMsg->account, SzAccount);
	}
	else
	{
		pReqMsg->account_type = '1';
		pReqMsg->exchange_no = 1;
		strcpy(pReqMsg->account, ShAccount);
	}
	pReqMsg->entrust_sn = atoi(myEntrust.cOrderSysID);

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		strcpy(Errormsg, "rev ::parse length error!");
		bRunning = false;
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));

	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len<8) {
			strcpy(Errormsg, "rev ::parse length error!");
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len<in_len - 8) {
			strcpy(Errormsg, "rev ::parse length error!");
			bRunning = false;
			return false;
		}
		SWI_WithdrawEntrustReturn * pRetun = (SWI_WithdrawEntrustReturn*)buf;
		if (pRetun->return_status<0)
		{
			strcpy(Errormsg, this->getErrorCodeMsg(pRetun->return_status));
			bRunning = false;
			return false;
		}
		break;

	}
	bRunning = false;
	return true;
}
bool  CStockTrader::queryorder(QueryEntrustorderstruct myEntrust, Entrustreturnstruct * myoderreturn, int &num, char * Errormsg)     //��ѯί��
{
	strcpy(Errormsg, "success");
	bRunning = true;
	num = 0;
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_QueryEntrustRequest  *pReqMsg;
	pReqMsg = (SWI_QueryEntrustRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_QueryEntrustRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x402;

	if (!strcmp(myEntrust.cExchangeID, "SZ"))//�����г�)
	{
		pReqMsg->account_type = '2';
		pReqMsg->exchange_no = 2;
		strcpy(pReqMsg->account, SzAccount);
	}
	else
	{
		pReqMsg->account_type = '1';
		pReqMsg->exchange_no = 1;
		strcpy(pReqMsg->account, ShAccount);
	}

	pReqMsg->entrust_sn = atoi(myEntrust.cOrderSysID);
	pReqMsg->max_results = 0;

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		strcpy(Errormsg, "queryEntrustStatus::send to agc error!");
		bRunning = false;
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));


	while (1)
	{
		//----�Ƚ���8bytes,pack������
		len = recv(sock, buf, 8, 0);
		if (len<8) {
			strcpy(Errormsg, " queryEntrustStatus::parse length error!");
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len<in_len - 8) {
			strcpy(Errormsg, " queryEntrustStatus::parse length error!");
			bRunning = false;
			return false;
		}
		SWI_QueryEntrustResult * pRetunResult = (SWI_QueryEntrustResult*)buf;
		if (pRetunResult->row_no != 0xFFFF)
		{
			sprintf(myoderreturn[num].cInsertDate, "%d", pRetunResult->entrust_date);
			sprintf(myoderreturn[num].cInsertTime, "%d", pRetunResult->entrust_time);
			myoderreturn[num].cOrderStatus = pRetunResult->entrust_status;
			sprintf(myoderreturn[num].cOrderSysID, "%d", pRetunResult->entrust_sn);
			myoderreturn[num].cOrderType = pRetunResult->entrust_method;      //  ί�з�ʽ���������ֵ�˵����;
			strcpy(myoderreturn[num].cSecurity_code, pRetunResult->security_code);
			myoderreturn[num].frozen_amount = pRetunResult->frozen_amount;     //����֤ȯ����
			myoderreturn[num].frozen_money = (pRetunResult->frozen_money.lo_value + pRetunResult->frozen_money.hi_value * 4294967296) / 10000.00;    //������
			myoderreturn[num].nVolumeTotalOriginal = pRetunResult->stock_ammount;
			myoderreturn[num].nVolumeTraded = pRetunResult->bargain_ammount;     //  �ѳɽ�����
			myoderreturn[num].withdraw_ammount = pRetunResult->withdraw_ammount;     //  ��������
			myoderreturn[num].nVolumeTotal = myoderreturn[num].nVolumeTotalOriginal - myoderreturn[num].nVolumeTraded - myoderreturn[num].withdraw_ammount;
			strcpy(myoderreturn[num].error_msg, pRetunResult->error_msg);
			num++;
		}
		else{
			break;
		}

	}
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len<8) {
			strcpy(Errormsg, " queryEntrustStatus::parse length error!");
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len<in_len - 8) {
			strcpy(Errormsg, " queryEntrustStatus::parse length error!");
			bRunning = false;
			return false;
		}
		SWI_QueryEntrustReturn * pRetun = (SWI_QueryEntrustReturn*)buf;
		if (pRetun->return_status<0)
		{
			strcpy(Errormsg, " error!");
			bRunning = false;
			return false;
		}
		break;

	}

	return true;
}
bool  CStockTrader::querytrader(QueryEntrustorderstruct myEntrust, Bargainreturnstruct * mytraderreturn, int &num, char * Errormsg)     //��ѯ�ɽ�
{
	strcpy(Errormsg, "success");
	bRunning = true;
	num = 0;
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_QueryBusinessRequest  *pReqMsg;
	pReqMsg = (SWI_QueryBusinessRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_QueryBusinessRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x403;

	if (!strcmp(myEntrust.cExchangeID, "SZ"))//�����г�)
	{
		pReqMsg->account_type = '2';
		pReqMsg->exchange_no = 2;
		strcpy(pReqMsg->account, SzAccount);
	}
	else
	{
		pReqMsg->account_type = '1';
		pReqMsg->exchange_no = 1;
		strcpy(pReqMsg->account, ShAccount);
	}
	pReqMsg->entrust_sn = atoi(myEntrust.cOrderSysID);

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		strcpy(Errormsg, "queryEntrustStatusByCode::send to agc error!");
		bRunning = false;
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,pack������
		len = recv(sock, buf, 8, 0);
		if (len<8) {
			strcpy(Errormsg, "queryEntrustStatusByCode::parse length error!");
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len<in_len - 8) {
			strcpy(Errormsg, "queryEntrustStatusByCode::parse length error!");
			bRunning = false;
			return false;
		}
		SWI_QueryBusinessResult * pRetunResult = (SWI_QueryBusinessResult*)buf;
		if (pRetunResult->row_no != 0xFFFF){

			mytraderreturn[num].bargain_money = (pRetunResult->money.lo_value + pRetunResult->money.hi_value * 4294967296) / 10000.00;
			mytraderreturn[num].bargain_no = pRetunResult->bargain_no;
			mytraderreturn[num].bargain_price = pRetunResult->price;// �ɽ��۸�
			strcpy(mytraderreturn[num].bargain_time, pRetunResult->bargain_time);
			//mytraderreturn[num].cOrderStatus
			sprintf(mytraderreturn[num].cOrderSysID, "%d", pRetunResult->entrust_no);
			mytraderreturn[num].cOrderType = pRetunResult->bs_type;   // ������𣨼������ֵ�˵����
			strcpy(mytraderreturn[num].cSecurity_code, pRetunResult->security_code);
			strcpy(mytraderreturn[num].security_name, pRetunResult->security_name);
			mytraderreturn[num].stock_ammount = pRetunResult->stock_ammount;   // �ɽ�����
			mytraderreturn[num].unfrozen_amount = pRetunResult->unfrozen_amount;    //�ⶳ֤ȯ����(A����Ч��B�ɷ���0)
			mytraderreturn[num].unfrozen_money = (pRetunResult->unfrozen_money.lo_value + pRetunResult->unfrozen_money.hi_value * 4294967296) / 10000.00;
			num++;
		}
		else{
			break;
		}

	}
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len<8) {
			strcpy(Errormsg, "queryEntrustStatusByCode::parse length error!");
			bRunning = false;
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len<in_len - 8) {
			strcpy(Errormsg, "queryEntrustStatusByCode::parse length error!");
			bRunning = false;
			return false;
		}
		SWI_QueryBusinessReturn * pRetun = (SWI_QueryBusinessReturn*)buf;
		if (pRetun->return_status<0)
		{
			bRunning = false;
			strcpy(Errormsg, " error!");
			return false;
		}
		break;

	}
	bRunning = false;
	return true;
}

bool CStockTrader::heartBeat() //��������
{

	bRunning = true;
	SWI_QueryBalanceSheetReturn pRetunResult;
	if (!queryBalanceSheet(&pRetunResult))
		this->bConnected = false; //�����ѯ�ʽ�ʧ��  ����Ϊ�����ж�

	bRunning = false;
	return true;
}
bool CStockTrader::getconnectstate()//  ���ؽ������ δ���� 
{
	return this->bConnected;
}

bool CStockTrader::getworkstate() //�����Ƿ�ռ��
{
	return this->bRunning;
}

/********˽�к�������**********/
void CStockTrader::loadArgs(char * SERVER_IP, int N_PORT, char *ZJ_ACCOUNT, char *PASSWORD)
{
	strcpy(serverIP, SERVER_IP);//���׷�������ַ(Ҳ���ǿ충��
	this->nPort = N_PORT;//�˿�
	strcpy(ZjAccount, ZJ_ACCOUNT);
	char szDpt[5];
	strncpy(szDpt, ZjAccount, 5);//ͨ���ʽ��˺Ž���Ӫҵ����ţ��ʽ��˺ŵ�ǰ4λ+\0
	this->nDept = atoi(szDpt);
	strcpy(this->password, PASSWORD);//��������

}
bool CStockTrader::connectToServer(){
	struct sockaddr_in server;// �Է���ַ��Ϣ
	char   buf[8192];
	int    len;
	SWI_ConnectRequest  *pRequest;
	SWI_ConnectResponse *pResponse;

	//-------------------��������AGC��TCP���������-----------------------------
	sock = socket(PF_INET, SOCK_STREAM, 0);//����socket
	if (sock == INVALID_SOCKET)
	{
		//CSysLoger::logMessage("connectToServer::socket init error!\n");
		return false;
	}

	memset(&server, 0x00, sizeof(server));//�Է���ַ��0
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(serverIP);
	server.sin_port = htons(nPort);

	if (connect(sock, (sockaddr *)&server, sizeof(server)) < 0)//���socket����ʧ��
	{
		closesocket(sock);
		//CSysLoger::logMessage("connectToServer::connect agc error!\n");
		return false;
	}

	//----------------����SWI_ConnectRequestӦ�ò���������(������Կ)---------------------
	pRequest = (SWI_ConnectRequest *)buf;
	memset(&buf, 0x00, sizeof(buf));
	pRequest->head.block_size = sizeof(SWI_ConnectRequest);
	pRequest->head.block_type = 6;//��������
	pRequest->method = 0;		    	   // ���ܷ�ʽ
	pRequest->entrust_method = '0';      // ί�з�ʽ
	pRequest->head.crc = CalCRC(&pRequest->head.block_type, pRequest->head.block_size - 4);

	len = sizeof(SWI_ConnectRequest);
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		closesocket(sock);
		return false;
	}
	pResponse = (SWI_ConnectResponse *)buf;
	memset(&buf, 0x00, sizeof(buf));
	len = recv(sock, buf, sizeof(buf), 0);
	int lenExpected = pResponse->head.block_size;
	lenExpected = (lenExpected % 8 == 0) ? lenExpected : lenExpected + (8 - lenExpected % 8);
	if (len <= 0 || len < lenExpected)
	{
		closesocket(sock);
		//CSysLoger::logMessage("connectToServer::recv error!\n");
		return false;
	}
	if (pResponse->head.function_no != 0 || pResponse->return_value <= 0)
	{
		closesocket(sock);
		//CSysLoger::logMessage("connectToServer::AGC ��������ʧ��!\n");
		return false;
	}
	this->bConnected = true;
	return true;
}
bool CStockTrader::openAccount(){//�൱�ڵ�½
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_OpenAccountRequest  *pReqMsg;
	pReqMsg = (SWI_OpenAccountRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_OpenAccountRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x101;

	pReqMsg->account_type = '0';
	strcpy(pReqMsg->account, ZjAccount);
	strcpy(pReqMsg->pwd, password);

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		//CSysLoger::logMessage("openAccount::send to agc error!\n");
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,pack������*********/
		len = recv(sock, buf, 8, 0);
		if (len < 8) {
			//CSysLoger::logMessage("openAccount::parse length error!\n");
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;//������Ч����
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);//��һ����û�в��룬����в������������
		len = recv(sock, &buf[8], in_len - 8, 0);//����ʣ��İ���
		if (len < in_len - 8) {
			//CSysLoger::logMessage("openAccount::parse length error!\n");
			return false;
		}
		SWI_OpenAccountReturn * pOpenAccountReturn = (SWI_OpenAccountReturn*)buf;
		if (pOpenAccountReturn->return_status < 0){
			return false;
		}
		break;

	}
	return true;

}
bool CStockTrader::login(){//��ѯ��֤�������˺�
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_OpenAccountRequest  *pReqMsg;
	pReqMsg = (SWI_OpenAccountRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_OpenAccountRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x111;

	pReqMsg->account_type = '0';
	strcpy(pReqMsg->account, ZjAccount);
	strcpy(pReqMsg->pwd, password);

	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		//CSysLoger::logMessage("login::send to agc error!\n");
		return false;
	}

	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8) {
			//CSysLoger::logMessage("login::parse length error!\n");
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8) {
			//CSysLoger::logMessage("login::parse length error!\n");
			return false;
		}
		int nSize = sizeof(SWI_AccountLoginResult);
		SWI_AccountLoginResult * pRetunResult = (SWI_AccountLoginResult*)buf;
		if (pRetunResult->account_type == '1'){//��֤
			strcpy(ShAccount, pRetunResult->security_account);
		}
		if (pRetunResult->account_type == '2'){//����
			strcpy(this->SzAccount, pRetunResult->security_account);
		}
		if (pRetunResult->row_no == 0xffff)
			break;

	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8) {
			//CSysLoger::logMessage("login::parse length error!\n");
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8){
			//CSysLoger::logMessage("login::parse length error!\n");
			return false;
		}
		SWI_AccountLoginReturn * pRtn = (SWI_AccountLoginReturn*)buf;
		if (pRtn->return_status < 0){
			return false;
		}
		break;

	}

	return true;
}


//��ʱû��ʹ�ã�Ҫ����Ҫ�ٸĸ�
char * CStockTrader::getErrorCodeMsg(int nErrorCode){
	char * msg = "error code��ѯʧ��";
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_ErrorMsgRequest  *pReqMsg;
	pReqMsg = (SWI_ErrorMsgRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_ErrorMsgRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x901;

	pReqMsg->error_no = nErrorCode;



	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		//CSysLoger::logMessage("queryErrorCode::send to agc error!\n");
		return msg;
	}
	memset(&buf, 0x00, sizeof(buf));

	//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
	len = recv(sock, buf, 8, 0);
	if (len < 8) return msg;

	//----�ٽ���pack��ʣ�೤��----------------------------
	memcpy(buf2, buf, 8);
	//if(method>0) dedes_data(des_key,buf2,8);
	WORD *pWord = (WORD *)buf2;
	in_len = *pWord;
	in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
	len = recv(sock, &buf[8], in_len - 8, 0);
	if (len < in_len - 8) return msg;
	SWI_ErrorMsgReturn * pErrorMsgReturn = (SWI_ErrorMsgReturn*)buf;
	if (nErrorCode <= 0){//ÿ�δ�����Ϣ�Ĳ�ѯ����¼����־��
		strcpy(msg, pErrorMsgReturn->error_msg);
		//CSysLoger::logMessage(msg);
	}
	return msg;
}
bool CStockTrader::queryBalanceSheet(SWI_QueryBalanceSheetReturn * pRetunResult){
	int    len, in_len;
	char   buf[1024], buf2[100];
	memset(buf, 0x00, sizeof(buf));

	SWI_QueryBalanceSheetRequest  *pReqMsg;
	pReqMsg = (SWI_QueryBalanceSheetRequest*)(buf);

	pReqMsg->head.block_type = 1;
	pReqMsg->head.block_size = sizeof(SWI_QueryEntrustRequest);
	pReqMsg->head.dest_dpt = nDept;
	pReqMsg->head.function_no = 0x303;

	pReqMsg->account_type = '0';
	strcpy(pReqMsg->account, this->ZjAccount);
	pReqMsg->currency_type = '1';



	pReqMsg->head.crc = CalCRC(&pReqMsg->head.block_type, pReqMsg->head.block_size - 4);
	len = pReqMsg->head.block_size;
	len = (len % 8 == 0) ? len : len + (8 - len % 8);
	if (send(sock, buf, len, 0) == SOCKET_ERROR)
	{
		//CSysLoger::logMessage("queryBalanceSheet::send errror");
		return false;
	}
	memset(&buf, 0x00, sizeof(buf));
	while (1)
	{
		//----�Ƚ���8bytes,����des���ܵȵ���Ҫ���յ�pack������
		len = recv(sock, buf, 8, 0);
		if (len < 8) {
			//CSysLoger::logMessage("queryBalanceSheet::parse length error!\n");
			return false;
		}

		//----�ٽ���pack��ʣ�೤��----------------------------
		memcpy(buf2, buf, 8);
		//if(method>0) dedes_data(des_key,buf2,8);
		WORD *pWord = (WORD *)buf2;
		in_len = *pWord;
		in_len = (in_len % 8 == 0) ? in_len : in_len + (8 - in_len % 8);
		len = recv(sock, &buf[8], in_len - 8, 0);
		if (len < in_len - 8){
			//CSysLoger::logMessage("queryBalanceSheet::parse length error!\n");
			return false;
		}
		memcpy(pRetunResult, buf, sizeof(SWI_QueryBalanceSheetReturn));
		if (pRetunResult->return_status < 0){
			//CSysLoger::logMessage("queryBalanceSheet::queryBalanceSheet:false");
			return false;
		}
		else{
			//CSysLoger::logMessage("queryBalanceSheet:true");
			return true;
		}
	}
	return true;
}

int CStockTrader::cal(char* msg)
{
	const size_t length = strlen(msg);
	char* temp = new char[length];
	strcpy(temp, msg);
	for (size_t i = 0; i < length / 2; i++)
	{
		char c = temp[i];
		temp[i] = temp[length - i - 1];
		temp[length - i - 1] = c;
	}

	msg = temp;
	return length;
}
