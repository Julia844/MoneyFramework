#ifndef __SWAGX_H
#define __SWAGX_H

#include <winsock.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

#pragma pack(1)
typedef struct SWI_BlockHead
{
	WORD    block_size; 	// ������Ϣ���ֽ�������������
	WORD    crc;       		// ���¸��ֶ�block_type�� (������block_size��
                   			// crc�ֶα���) ��CRCУ����
	BYTE    block_type;  	// ������  	1 - ����         ��SWI_???Request��
					 		//         	2 - ����״̬     ��SWI_???Return��
					 		//          3 - ��ѯ�����   ��SWI_???Result��
					 		//          5 - ȡ����ѯ
					 		//          4 - ������Ϣ
					 		//          5 - ����Ի�
					 		//          6 - ��������(������Կ)
					 		//          7 - ����Ӧ��(������Կ)
					 		//          8 - ��չ������Ϣ
					 		//          9 - ��չӦ����Ϣ
	BYTE    reserved1;    	// ������������0
	WORD    function_no;  	// ���ܺ�
	long    cn_id;      	// �������Ӻ�
	WORD    reserved2;  	// �������ڲ�ʹ�ã�ԭӪҵ����
	WORD    dest_dpt;    	// Ŀ��Ӫҵ�����
} SWI_BlockHead;

typedef struct SWI_ConnectRequest
{
	SWI_BlockHead  head;    	// ��Ϣͷ block_type == 6
	WORD   method;     	   		// �ͻ��˵ļ��ܷ�ʽ
								//0��ʾ������
	char   entrust_method;   	// ί�з�ʽ���������ֵ�˵����
	BYTE   return_cp;        	// �ͻ���ϣ���ķ��ؽṹ�������ֶεĴ���ҳ
					     		//   	0 -- MBCS  ��CP936�������ģ�
					     		//   	1 -- Unicode(Java�ͻ���Ҫ)
	BYTE   network[4];      	// �ͻ���Novell���κ�
	BYTE   address[6];      	// �ͻ���������ַ��Novell�ڵ��ַ��
	WORD   client_major_ver;  // �ͻ���Э��ӿ����汾�ţ����ڰ汾Э�̣�
	WORD   client_minor_ver;   // �ͻ���Э��ӿڴΰ汾�ţ����ڰ汾Э�̣�
	WORD   key_length;			// RSA��Կ���ȣ���method 1, key_length=0��
} SWI_ConnectRequest;

typedef struct SWI_ConnectResponse
{
	SWI_BlockHead  head;    	// ��Ϣͷ block_type == 7
    WORD return_value;			// ����״̬
	WORD method;				// ����ͬ��ļ��ܷ�ʽ
	char department_name[60];	// Ӫҵ�����ƣ�MBCS/Unicode��
	WORD key_length;			// DES��Կ���ȣ�key_length=8��
	BYTE des_key[8];			// DES��Կ(����"ExpressT"��Ϊ��Կdes����)
} SWI_ConnectResponse;

typedef	struct SWI_ReturnHead
{
	SWI_BlockHead head;
	long          return_status;
} SWI_ReturnHead;

typedef struct SWI_ResultHead
{
	SWI_BlockHead head;
	WORD          row_no;
} SWI_ResultHead;

typedef struct SWI_OpenAccountRequest
{
	SWI_BlockHead  head;    	// ��Ϣͷ block_type == 1
	char   account_type;     	// �ͻ��ʺ�����
	char   account[16];      	// �ͻ��ʺ�
	char   pwd[8];           	// �������루��Ϊ����Ա��½����Ϊ����Ա���룩
	short  op_code;             // ����Ա����
	unsigned  long  flag;      //"��������"�жϱ�־λ���,ÿһ��������λ��Ӧһ��"��������",ȱʡֵΪ0��ʾ���ж��κ�"��������"
	char   productno[7];		//��Ʒ��Ϣ��ţ�5λ�����������Ĳ�Ʒ����+2λ��
							    //  ��Ʒ���루��7λ�ַ�����ȱʡֵΪ�ա�
	char   note[30];			//��ע��Ŀǰ�����ڿͻ�ί��ʱ�����Χ�ͻ���½��MAC��ַ ��IP ��ַ��绰�������Ϣ��
	char   note2[30];           // ��ע����note�ֶι�ͬʹ�ã�����ʹ�÷�����ע������5
	char   login_flag;          // ��¼���˵�¼��Ϣ�ı�־��'0'--����¼��Ĭ�ϣ���'1'--��¼���ͻ�������������ĵ�¼Ӧ��'1'
} SWI_OpenAccountRequest;

typedef struct SWI_ErrorMsgRequest
{
	struct SWI_BlockHead head;  // function_no==0x901, block_type==1
	long    error_no;           // �������
} SWI_ErrorMsgRequest;

typedef struct SWI_ErrorMsgReturn
{
	struct SWI_BlockHead head;	//function_no==0x901,block_type==2
	long    return_status;      // ����״̬
	char    error_msg[40];      // ������Ϣ��MBCS/Unicode��
}SWI_ErrorMsgReturn;

struct SWI_OpenAccountReturn
{
	struct SWI_BlockHead head; 	// function_no==0x101
	long    return_status;  		// ����״̬
	BYTE    flag;				// (�������ֶ�)�������ر�־��0����Ĭ�ϣ���1����	���ͻ��ŵ�¼����1ʱ,�����ڡ�����Լ����
	char    last_login_date[9];  // �ϴε�¼�����ڣ���ʽΪ��YYYYMMDD
	char    last_login_time[9];  // �ϴε�¼��ʱ�䣬��ʽΪ��HH:MM:SS
	char    last_full_note[60];  // �ϴεĵ�½��Ϣ���μ�ע������5��˵��
};

struct SWI_AccountLoginRequest
{
	struct SWI_BlockHead head;	// function_no==0x111, block_type == 1
	char   account_type;     	// �ͻ��ʺ����ͣ��������ֵ�˵����
	char   account[16];      	// �ͻ��ʺ�
	char   pwd[8];           	// ��������
	unsigned  long   flag;         //"��������"�жϱ�־λ���,ÿһ��������λ��Ӧһ��"��������",ȱʡֵΪ0��ʾ���ж��κ�"��������"
	char   productno [7];		    //��Ʒ��Ϣ��ţ�5λ�����������Ĳ�Ʒ����+2λ��	��Ʒ���루��7λ�ַ�����ȱʡֵΪ�ա�
	char   note[30];				//��ע��Ŀǰ�����ڿͻ�ί��ʱ�����Χ�ͻ���½��MAC��ַ ��IP ��ַ��绰�������Ϣ��
	char   note2[30];           // ��ע����note�ֶι�ͬʹ�ã�����ʹ�÷�����0x101ע������5
	char   login_flag;           // ��¼���˵�¼��Ϣ�ı�־����0����������¼��Ĭ�ϣ���	��1��������¼���ͻ�������������ĵ�¼Ӧ�1��


};

struct SWI_AccountLoginResult
{
	struct SWI_BlockHead head;     	// function==0x111,block_type==3
	WORD   row_no;          			// ��¼�ţ�0xFFFF��ʾ��¼������
	long   bankbook_number;         // �ʽ��ʺ�
	char   account_type;  			// �ʺ����ͣ��������ֵ�, �����ʽ��ʺš�0����
	char   security_account[16];	 	// ֤ȯ�ʺ�
};
struct SWI_AccountLoginReturn
{
	struct SWI_BlockHead head;		// function_no = 0x111,block_type==2
	long   return_status;     		// ����״̬
	long    bankbook_number;     	// �ʽ��ʺ�
	BYTE    account_status;      	// �ʺ�״̬���������ֵ�˵����
	char    name[20];            	// �ͻ�������MBCS/Unicode��
	char    id[19];      			// ���֤��
	BYTE    card_version;          	//�ſ��汾��
	char		customer_flag[16];      //�ͻ����Ի���Ϣ��־
	char		Cust_flag[32];		//�ͻ�Ȩ�ޱ�־���ֶ��������R��������������ȯ��
	char		Cust_risk_type;		//�ͻ�����������𣨼������ֵ�˵����
	short   depart_number;			//Ӫҵ�����루4λ��
	char    last_login_date[9];     // �ϴε�¼�����ڣ���ʽΪ��YYYYMMDD
	char    last_login_time[9];     // �ϴε�¼��ʱ�䣬��ʽΪ��HH:MM:SS
	char    last_full_note[60];     // �ϴεĵ�½��Ϣ���μ�0x101ע������5��˵��
};
typedef struct _SWIMoney    // Same as the type CURRENCY in VB
{
	DWORD lo_value;
	long  hi_value;
} SWIMoney;
typedef long	 SWISmallMoney;
struct SWI_AddEntrustRequest
{
	struct SWI_BlockHead head;// function_no == 0x201, block_type==1//16
	char    account_type;     // �ͻ��ʺ����ͣ��������ֵ�˵����//17
	char    account[16];      // �ͻ��ʺ�//33
	BYTE    exchange_no;      // ��������ţ��������ֵ�˵����//34
	char    bs_type;          // ������𣨼������ֵ�˵����//35
	char    security_code[7]; // ֤ȯ����//42
	long    stock_amount;     // ί������//46
	SWISmallMoney price;      // ί�м۸�SWISmallMoney�������ֵ�˵������ͬ��//50
	short   effect_days;      // ��Ч���� //52
	SWIMoney   apply_amount;  //������ //60
	BYTE    mark;             //�Ƿ�������� 1Ϊ�������,0Ϊ������ ȷʡΪ0//61
	int		Frozen_no ;        //֤ȯ���ʽ𶳽���ˮ��(��֤ͨר�ã�ȱʡΪ0)//65
	SWIMoney		fund_amount;  //ί������(֧�ֿ���ʽ����С���ݶ�)//73
	char    Entrust_sign[10]; //����ǩ��(ȱʡΪ����)//83
	SWIMoney    Cash_limit ;  //ί���ʽ��ȣ�ȱʡΪ0��ʾ������ί���ʽ���;��	��ί�ж����ʽ𳬹�ί���ʽ���ʱ����ί��ʧ��,B		���ݲ����ƣ�//91
	char 	MarketOrder_type[2]; //�۸����ͣ��������ֵ�˵������ȱʡ��00����ʾ�޼�ί�У�//93
	char	Trade_type;		//�������ʣ��������ֵ�˵������ȱʡ������ʾ�ֽ��ף�//94
	char    CompNo[3];		//���⹫˾���//97
	long	contract_no;	//Լ���ţ��۸�����Ϊ��11��ʱ��Ҫ���룩//101
	char 	PBU_no[8];		//�Է����׵�Ԫ���۸�����Ϊ��11��ʱ��Ҫ���룩//109
};
struct SWI_AddEntrustReturn
{
	struct SWI_BlockHead head;
	long return_status;   	      	//  ����״̬
	long entrust_sn;      			//  ί�б��
	SWIMoney  frozen_money;    	//�����ʽ���
	long     frozen_amount;     	//����֤ȯ����
};

struct SWI_QueryEntrustRequest
{
	struct SWI_BlockHead head; 	// function_no == 0x402 ,block_type==1
	char    account_type;    	// �ͻ��ʺ����ͣ��������ֵ�˵����
	char    account[16];     	// �ͻ��ʺ�	
	BYTE    exchange_no;     	// ��������ţ��������ֵ�˵����
	long    begin_date;      	// ��ʼ���ڣ����磺yyyymmdd��
	long    end_date;        	// �������ڣ����磺yyyymmdd��
	long    entrust_sn;      	// ί�б�ţ�Ĭ��Ϊ0��0��ʾȫ����
	char    security_code[7];	// ��Ʊ���루Ĭ��Ϊ�գ��ձ�ʾȫ����
	WORD    max_results;     	// ����ѯ��¼����Ĭ��Ϊ0��
	char 	stock_type;			// ֤ȯ���, ȱʡΪ�գ���ѯȫ��֤ȯ���. 	���������ֵ�˵����
};

struct SWI_QueryEntrustResult
{
	struct SWI_BlockHead head; // function_no==0x402,block_type==3
	WORD row_no;               // ��¼��,  0xFFFF���������
	long entrust_date;         //  ί�����ڣ����磺yyyymmdd��
	long entrust_sn;           //  ί�б��
	char entrust_time[9];      //  ί��ʱ�䣨���磺hh:mm:ss��
	BYTE exchange_no;          //  ��������ţ��������ֵ�˵����
	char security_account[11]; //  �ɶ�����
	char security_code[7];     //  ֤ȯ����
	char security_name[18];    //  ֤ȯ���ƣ�MBCS/Unicode��
	char bs_type;              //  ������𣨼������ֵ�˵����
	long stock_ammount;        //  ί������
	SWISmallMoney price;       //  ί�м۸�
	SWIMoney frozen_money;     //  ������/����������
	char  entrust_method;      //  ί�з�ʽ���������ֵ�˵����
	char  entrust_status;      //  ί��״̬���������ֵ�˵����
	short operator_no;         //  ����Ա����
	long  bargain_ammount;     //  �ѳɽ�����
	char  error_msg[32];		  //ί��ʧ��ԭ��/��ע������������ǳ��⿪��ʽ����ֺ췽ʽ�޸�ʱ��ʾ���趨�ķֺ췽ʽ������תͶ/�ֽ�ֺ죩������������ǳ��⿪��ʽ����ת��ʱ����ʾĿ��֤ȯ���롣 
	BYTE    mark;             //��ʾ�Ƿ�������� 1Ϊ�������,0Ϊ�������� 
	char stock_account[20];   //����ʽ�����ʺ�
	SWIMoney		fund_amount;  //ί��������֧�ֿ���ʽ����С���ݶ
	char    Entrust_sign[10]; //����ǩ��(ȱʡΪ����)
	long     frozen_amount;     //����֤ȯ����
	char 	MarketOrder_type[2];		//�м�ί�з�ʽ��ȱʡ��00����ʾ�޼�ί�У�
	char		Trade_type;		//�������ʣ��������ֵ�˵������ȱʡΪ�գ���ʾ�ֽ��ף�
	long  withdraw_ammount;     //  ��������
	long		contract_no;			//Լ����
	char 	PBU_no[8];			//�Է����׵�Ԫ
	SWIMoney  done_money;        // �ѳɽ����
};
struct SWI_QueryEntrustReturn
{
	struct SWI_BlockHead head; 		// function_no==0x402,block_type==2
	long   return_status;      		// ����״̬
};

struct SWI_BatchDetail
{
	char bs_type;          //������𣨽�֧�֡�1��-����,��2��-������
						//implement_mode=��1��ʱҪ��ÿ��ί�з���һ���Ե�һ��Ϊ׼��
	char security_code[7]; // ֤ȯ����
	long stock_amount;     // ί������
	SWISmallMoney price;   // ί�м۸�
	char entrust_sign[10]; // ����ǩ��(ȱʡΪ����)����implement_mode=��0��ʱ��Ч��
};

struct SWI_BatchEntrustRequest
{
	struct SWI_BlockHead head;// function_no == 0x205, block_type==1
	char    account_type;     // �ͻ��ʺ����ͣ��������ֵ�˵����
	char    account[16];      // �ͻ��ʺ�
	BYTE    exchange_no;      // ��������ţ��������ֵ�˵����
	long   entrust_length;    // ί�б���(implement_mode=��0��ʱ���֧��50��
	//          implement_mode=��1��ʱ���֧��15)
	WORD    detail_block_size; // ί����ϸ�ṹ���ֽڴ�С��
							   //ע��By̷�����Ҿ�����û�а�������ģ���Ȼdetail_block_sizeӦ��= ����x sizeof(SWI_BatchDetail) +2
	SWI_BatchDetail	detail_buf[50]; // ί����ϸ���ݣ�����˵����
	SWIMoney    Cash_limit ;  //ί���ʽ��ȣ�ȱʡΪ0��ʾ������ί���ʽ���;
	//����ί���ʽ��ܶ�Ⱥ��ί�з���ʧ��
	//(��implement_mode=��0��ʱ��Ч��
	long      trade_interval; //ÿ��ί��֮��ͣ���ļ������λΪ����,Ĭ��200ms
	//(��implement_mode=��0��ʱ��Ч)
	char      implement_mode; // ʵ��ģʽ����������Ĭ�ϡ�0����AGCʵ�֣��Ƚ�����һ�����֧��50��
	//                       ��1������̨ʵ��.�ȽϿ죬һ�����֧��15�ʣ�
};
struct SWI_BatchEntrustResult
{
	struct SWI_BlockHead head; // function_no==0x205,block_type==3
	WORD row_no;               // ��¼��,  0xFFFF���������
	long return_status;        // ����״̬: >  0  �ɹ� <= 0  ʧ��
	long entrust_sn;           // ί�б��: ����״̬<0Ϊʧ��
	SWIMoney frozen_money;     // ������
	long     frozen_amount;     // ����֤ȯ����
	char    Entrust_sign[10];  // ����ǩ��(ȱʡΪ����)
	char    err_msg[60];       // ����ԭ�򣬵�ί�гɹ�ʱ������Ϊ�գ�ί��ʧ��ʱ������ʧ��ԭ��
};
struct SWI_BatchEntrustReturn
{
	struct SWI_BlockHead head;
	long return_status;              // ����״̬��>0 ���óɹ� ��=0����ʧ��
};
struct SWI_QueryBalanceSheetRequest
{
	struct SWI_BlockHead head;	//function_no == 0x303,block_type==1
	char    account_type;       // �ͻ��ʺ����ͣ��������ֵ�˵����
	char    account[16];        // �ͻ��ʺ�
	char    currency_type;      // ���֣��������ֵ�˵����Ĭ��Ϊ����ң�����Ϊ�գ�
};
struct SWI_QueryBalanceSheetReturn
{
	struct SWI_BlockHead head; 	// function_no == 0x303 block_type==2
	long      return_status; 	// ����״̬
	char      name[20];      	// �ɶ�������MBCS/Unicode��
	SWIMoney		net_assets;    //���ʲ�
	SWIMoney		total_liabilities;	//��ծ�ܶ�
	SWIMoney		fund_liabilities; 	//�ʽ�ծ
	SWIMoney		stock_liabilities;	//��Ʊ��ծ
	SWIMoney		profit_loss_in_shortsale;	//��ȯӯ��
	SWIMoney		assure_rate;	//������
	SWIMoney		deposit_usable;	//��֤����ö��
	SWIMoney		credit_range;	//���Ŷ��
	SWIMoney	    financeable;		//������������
	SWIMoney	    shortsale_usable;	//����ȯ�������
	SWIMoney		usable;		//�����ʽ�
	SWIMoney		market_value	;	//��ֵ
	SWIMoney		total_assets	;	//���ʲ�
	SWIMoney		total_profit_loss;	//�ܸ���ӯ��
	SWIMoney		exceptional_frozen;	//�쳣�����ʽ�
	SWIMoney		fund_balance;	//�ʽ����
	SWIMoney		today_bought_money;	//��������ɽ����
	SWIMoney		today_sell_money;	//���������ɽ����
	SWIMoney		today_bought_nobargain;	//��������δ�ɽ����
	SWIMoney		bought_nobargain;	//����δ���ս��
	SWIMoney		sell_nobargain;	//����δ���ս��
};


SOCKET AGCConnect(char *ip,WORD port,char entrust_way,WORD *method,char *des_key,int *key_len);
int AGCSend(SOCKET sock,char *pSendData,WORD method,const char *des_key);

int endes_data(const char *des_key,char *buf2,int len);
int dedes_data(const char *des_key,char *buf2,int len);
WORD CalCRC(void *pData, int nDataLen);

#endif
