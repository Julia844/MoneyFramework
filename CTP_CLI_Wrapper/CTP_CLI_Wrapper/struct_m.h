#ifndef STRUCT_M_H
#define STRUCT_M_H



using namespace System;
using namespace System::Runtime::InteropServices;

namespace CTP_CLI
{

#pragma region type_enum
	/// <summary>
	/// TFtdcExchangePropertyType��һ����������������
	/// </summary>
	public enum class EnumExchangePropertyTypeL : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// ���ݳɽ����ɱ���
		/// </summary>
		GenOrderByTrade = (Byte)'1'
	};

	/// <summary>
	/// TFtdcIdCardTypeType��һ��֤����������
	/// </summary>
	public enum class EnumIdCardTypeType : Byte
	{
		/// <summary>
		/// ��֯��������
		/// </summary>
		EID = (Byte)'0',

		/// <summary>
		/// ���֤
		/// </summary>
		IDCard = (Byte)'1',

		/// <summary>
		/// ����֤
		/// </summary>
		OfficerIDCard = (Byte)'2',

		/// <summary>
		/// ����֤
		/// </summary>
		PoliceIDCard = (Byte)'3',

		/// <summary>
		/// ʿ��֤
		/// </summary>
		SoldierIDCard = (Byte)'4',

		/// <summary>
		/// ���ڲ�
		/// </summary>
		HouseholdRegister = (Byte)'5',

		/// <summary>
		/// ����
		/// </summary>
		Passport = (Byte)'6',

		/// <summary>
		/// ̨��֤
		/// </summary>
		TaiwanCompatriotIDCard = (Byte)'7',

		/// <summary>
		/// ����֤
		/// </summary>
		HomeComingCard = (Byte)'8',

		/// <summary>
		/// Ӫҵִ�պ�
		/// </summary>
		LicenseNo = (Byte)'9',

		/// <summary>
		/// ����֤��
		/// </summary>
		OtherCard = (Byte)'x'
	};

	/// <summary>
	/// TFtdcInvestorRangeType��һ��Ͷ���߷�Χ����
	/// </summary>
	public enum class EnumInvestorRangeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// Ͷ������
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// ��һͶ����
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDepartmentRangeType��һ��Ͷ���߷�Χ����
	/// </summary>
	public enum class EnumDepartmentRangeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// ��֯�ܹ�
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// ��һͶ����
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDataSyncStatusType��һ������ͬ��״̬����
	/// </summary>
	public enum class EnumDataSyncStatusType : Byte
	{
		/// <summary>
		/// δͬ��
		/// </summary>
		Asynchronous = (Byte)'1',

		/// <summary>
		/// ͬ����
		/// </summary>
		Synchronizing = (Byte)'2',

		/// <summary>
		/// ��ͬ��
		/// </summary>
		Synchronized = (Byte)'3'
	};

	/// <summary>
	/// TFtdcBrokerDataSyncStatusType��һ�����͹�˾����ͬ��״̬����
	/// </summary>
	public enum class EnumBrokerDataSyncStatusType : Byte
	{
		/// <summary>
		/// ��ͬ��
		/// </summary>
		Synchronized = (Byte)'1',

		/// <summary>
		/// ͬ����
		/// </summary>
		Synchronizing = (Byte)'2'
	};

	/// <summary>
	/// TFtdcExchangeConnectStatusType��һ������������״̬����
	/// </summary>
	public enum class EnumExchangeConnectStatusType : Byte
	{
		/// <summary>
		/// û���κ�����
		/// </summary>
		NoConnection = (Byte)'1',

		/// <summary>
		/// �Ѿ�������Լ��ѯ����
		/// </summary>
		QryInstrumentSent = (Byte)'2',

		/// <summary>
		/// �Ѿ���ȡ��Ϣ
		/// </summary>
		GotInformation = (Byte)'9'
	};

	/// <summary>
	/// TFtdcTraderConnectStatusType��һ������������Ա����״̬����
	/// </summary>
	public enum class EnumTraderConnectStatusType : Byte
	{
		/// <summary>
		/// û���κ�����
		/// </summary>
		NotConnected = (Byte)'1',

		/// <summary>
		/// �Ѿ�����
		/// </summary>
		Connected = (Byte)'2',

		/// <summary>
		/// �Ѿ�������Լ��ѯ����
		/// </summary>
		QryInstrumentSent = (Byte)'3',

		/// <summary>
		/// ����˽����
		/// </summary>
		SubPrivateFlow = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFunctionCodeType��һ�����ܴ�������
	/// </summary>
	public enum class EnumFunctionCodeType : Byte
	{
		/// <summary>
		/// �����첽��
		/// </summary>
		DataAsync = (Byte)'1',

		/// <summary>
		/// ǿ���û��ǳ�
		/// </summary>
		ForceUserLogout = (Byte)'2',

		/// <summary>
		/// ��������û�����
		/// </summary>
		UserPasswordUpdate = (Byte)'3',

		/// <summary>
		/// ������͹�˾����
		/// </summary>
		BrokerPasswordUpdate = (Byte)'4',

		/// <summary>
		/// ���Ͷ���߿���
		/// </summary>
		InvestorPasswordUpdate = (Byte)'5',

		/// <summary>
		/// ��������
		/// </summary>
		OrderInsert = (Byte)'6',

		/// <summary>
		/// ��������
		/// </summary>
		OrderAction = (Byte)'7',

		/// <summary>
		/// ͬ��ϵͳ����
		/// </summary>
		SyncSystemData = (Byte)'8',

		/// <summary>
		/// ͬ�����͹�˾����
		/// </summary>
		SyncBrokerData = (Byte)'9',

		/// <summary>
		/// ����ͬ�����͹�˾����
		/// </summary>
		BachSyncBrokerData = (Byte)'A',

		/// <summary>
		/// ������ѯ
		/// </summary>
		SuperQuery = (Byte)'B',

		/// <summary>
		/// ��������
		/// </summary>
		ParkedOrderInsert = (Byte)'C',

		/// <summary>
		/// ��������
		/// </summary>
		ParkedOrderAction = (Byte)'D',

		/// <summary>
		/// ͬ����̬����
		/// </summary>
		SyncOTP = (Byte)'E'
	};

	/// <summary>
	/// TFtdcBrokerFunctionCodeType��һ�����͹�˾���ܴ�������
	/// </summary>
	public enum class EnumBrokerFunctionCodeType : Byte
	{
		/// <summary>
		/// ǿ���û��ǳ�
		/// </summary>
		ForceUserLogout = (Byte)'1',

		/// <summary>
		/// ����û�����
		/// </summary>
		UserPasswordUpdate = (Byte)'2',

		/// <summary>
		/// ͬ�����͹�˾����
		/// </summary>
		SyncBrokerData = (Byte)'3',

		/// <summary>
		/// ����ͬ�����͹�˾����
		/// </summary>
		BachSyncBrokerData = (Byte)'4',

		/// <summary>
		/// ��������
		/// </summary>
		OrderInsert = (Byte)'5',

		/// <summary>
		/// ��������
		/// </summary>
		OrderAction = (Byte)'6',

		/// <summary>
		/// ȫ����ѯ
		/// </summary>
		AllQuery = (Byte)'7',

		/// <summary>
		/// ϵͳ���ܣ�����/�ǳ�/�޸������
		/// </summary>
		log = (Byte)'a',

		/// <summary>
		/// ������ѯ����ѯ�������ݣ����Լ���������ȳ���
		/// </summary>
		BaseQry = (Byte)'b',

		/// <summary>
		/// ���ײ�ѯ�����ɽ���ί��
		/// </summary>
		TradeQry = (Byte)'c',

		/// <summary>
		/// ���׹��ܣ�����������
		/// </summary>
		Trade = (Byte)'d',

		/// <summary>
		/// ����ת��
		/// </summary>
		Virement = (Byte)'e',

		/// <summary>
		/// ���ռ��
		/// </summary>
		Risk = (Byte)'f',

		/// <summary>
		/// ��ѯ/������ѯ�Ự�����˵�
		/// </summary>
		Session = (Byte)'g',

		/// <summary>
		/// ���֪ͨ����
		/// </summary>
		RiskNoticeCtl = (Byte)'h',

		/// <summary>
		/// ���֪ͨ����
		/// </summary>
		RiskNotice = (Byte)'i',

		/// <summary>
		/// �쿴���͹�˾�ʽ�Ȩ��
		/// </summary>
		BrokerDeposit = (Byte)'j',

		/// <summary>
		/// �ʽ��ѯ
		/// </summary>
		QueryFund = (Byte)'k',

		/// <summary>
		/// ������ѯ
		/// </summary>
		QueryOrder = (Byte)'l',

		/// <summary>
		/// �ɽ���ѯ
		/// </summary>
		QueryTrade = (Byte)'m',

		/// <summary>
		/// �ֲֲ�ѯ
		/// </summary>
		QueryPosition = (Byte)'n',

		/// <summary>
		/// �����ѯ
		/// </summary>
		QueryMarketData = (Byte)'o',

		/// <summary>
		/// �û��¼���ѯ
		/// </summary>
		QueryUserEvent = (Byte)'p',

		/// <summary>
		/// ����֪ͨ��ѯ
		/// </summary>
		QueryRiskNotify = (Byte)'q',

		/// <summary>
		/// ������ѯ
		/// </summary>
		QueryFundChange = (Byte)'r',

		/// <summary>
		/// Ͷ������Ϣ��ѯ
		/// </summary>
		QueryInvestor = (Byte)'s',

		/// <summary>
		/// ���ױ����ѯ
		/// </summary>
		QueryTradingCode = (Byte)'t',

		/// <summary>
		/// ǿƽ
		/// </summary>
		ForceClose = (Byte)'u',

		/// <summary>
		/// ѹ������
		/// </summary>
		PressTest = (Byte)'v',

		/// <summary>
		/// Ȩ�淴��
		/// </summary>
		RemainCalc = (Byte)'w',

		/// <summary>
		/// ���ֱֲ�֤��ָ��
		/// </summary>
		NetPositionInd = (Byte)'x',

		/// <summary>
		/// ����Ԥ��
		/// </summary>
		RiskPredict = (Byte)'y',

		/// <summary>
		/// ���ݵ���
		/// </summary>
		DataExport = (Byte)'z',

		/// <summary>
		/// ���ָ������
		/// </summary>
		RiskTargetSetup = (Byte)'A',

		/// <summary>
		/// ����Ԥ��
		/// </summary>
		MarketDataWarn = (Byte)'B',

		/// <summary>
		/// ͬ����̬����
		/// </summary>
		SyncOTP = (Byte)'E'
	};

	/// <summary>
	/// TFtdcOrderActionStatusType��һ����������״̬����
	/// </summary>
	public enum class EnumOrderActionStatusType : Byte
	{
		/// <summary>
		/// �Ѿ��ύ
		/// </summary>
		Submitted = (Byte)'a',

		/// <summary>
		/// �Ѿ�����
		/// </summary>
		Accepted = (Byte)'b',

		/// <summary>
		/// �Ѿ����ܾ�
		/// </summary>
		Rejected = (Byte)'c'
	};

	/// <summary>
	/// TFtdcOrderStatusType��һ������״̬����
	/// </summary>
	public enum class EnumOrderStatusType : Byte
	{
		/// <summary>
		/// ȫ���ɽ�
		/// </summary>
		AllTraded = (Byte)'0',

		/// <summary>
		/// ���ֳɽ����ڶ�����
		/// </summary>
		PartTradedQueueing = (Byte)'1',

		/// <summary>
		/// ���ֳɽ����ڶ�����
		/// </summary>
		PartTradedNotQueueing = (Byte)'2',

		/// <summary>
		/// δ�ɽ����ڶ�����
		/// </summary>
		NoTradeQueueing = (Byte)'3',

		/// <summary>
		/// δ�ɽ����ڶ�����
		/// </summary>
		NoTradeNotQueueing = (Byte)'4',

		/// <summary>
		/// ����
		/// </summary>
		Canceled = (Byte)'5',

		/// <summary>
		/// δ֪
		/// </summary>
		Unknown = (Byte)'a',

		/// <summary>
		/// ��δ����
		/// </summary>
		NotTouched = (Byte)'b',

		/// <summary>
		/// �Ѵ���
		/// </summary>
		Touched = (Byte)'c'
	};

	/// <summary>
	/// TFtdcOrderSubmitStatusType��һ�������ύ״̬����
	/// </summary>
	public enum class EnumOrderSubmitStatusType : Byte
	{
		/// <summary>
		/// �Ѿ��ύ
		/// </summary>
		InsertSubmitted = (Byte)'0',

		/// <summary>
		/// �����Ѿ��ύ
		/// </summary>
		CancelSubmitted = (Byte)'1',

		/// <summary>
		/// �޸��Ѿ��ύ
		/// </summary>
		ModifySubmitted = (Byte)'2',

		/// <summary>
		/// �Ѿ�����
		/// </summary>
		Accepted = (Byte)'3',

		/// <summary>
		/// �����Ѿ����ܾ�
		/// </summary>
		InsertRejected = (Byte)'4',

		/// <summary>
		/// �����Ѿ����ܾ�
		/// </summary>
		CancelRejected = (Byte)'5',

		/// <summary>
		/// �ĵ��Ѿ����ܾ�
		/// </summary>
		ModifyRejected = (Byte)'6'
	};

	/// <summary>
	/// TFtdcPositionDateType��һ���ֲ���������
	/// </summary>
	public enum class EnumPositionDateType : Byte
	{
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		Today = (Byte)'1',

		/// <summary>
		/// ��ʷ�ֲ�
		/// </summary>
		History = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPositionDateTypeType��һ���ֲ�������������
	/// </summary>
	public enum class EnumPositionDateTypeType : Byte
	{
		/// <summary>
		/// ʹ����ʷ�ֲ�
		/// </summary>
		UseHistory = (Byte)'1',

		/// <summary>
		/// ��ʹ����ʷ�ֲ�
		/// </summary>
		NoUseHistory = (Byte)'2'
	};

	/// <summary>
	/// TFtdcTradingRoleType��һ�����׽�ɫ����
	/// </summary>
	public enum class EnumTradingRoleType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Broker = (Byte)'1',

		/// <summary>
		/// ��Ӫ
		/// </summary>
		Host = (Byte)'2',

		/// <summary>
		/// ������
		/// </summary>
		Maker = (Byte)'3'
	};

	/// <summary>
	/// TFtdcProductClassType��һ����Ʒ��������
	/// </summary>
	public enum class EnumProductClassType : Byte
	{
		/// <summary>
		/// �ڻ�
		/// </summary>
		Futures = (Byte)'1',

		/// <summary>
		/// ��Ȩ
		/// </summary>
		Options = (Byte)'2',

		/// <summary>
		/// ���
		/// </summary>
		Combination = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		Spot = (Byte)'4',

		/// <summary>
		/// ��ת��
		/// </summary>
		EFP = (Byte)'5'
	};

	/// <summary>
	/// TFtdcInstLifePhaseType��һ����Լ��������״̬����
	/// </summary>
	public enum class EnumInstLifePhaseType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NotStart = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Started = (Byte)'1',

		/// <summary>
		/// ͣ��
		/// </summary>
		Pause = (Byte)'2',

		/// <summary>
		/// ����
		/// </summary>
		Expired = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDirectionType��һ��������������
	/// </summary>
	public enum class EnumDirectionType : Byte
	{
		/// <summary>
		/// ��
		/// </summary>
		Buy = (Byte)'0',

		/// <summary>
		/// ��
		/// </summary>
		Sell = (Byte)'1'
	};

	/// <summary>
	/// TFtdcPositionTypeType��һ���ֲ���������
	/// </summary>
	public enum class EnumPositionTypeType : Byte
	{
		/// <summary>
		/// ���ֲ�
		/// </summary>
		Net = (Byte)'1',

		/// <summary>
		/// �ۺϳֲ�
		/// </summary>
		Gross = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPosiDirectionType��һ���ֲֶ�շ�������
	/// </summary>
	public enum class EnumPosiDirectionType : Byte
	{
		/// <summary>
		/// ��
		/// </summary>
		Net = (Byte)'1',

		/// <summary>
		/// ��ͷ
		/// </summary>
		Long = (Byte)'2',

		/// <summary>
		/// ��ͷ
		/// </summary>
		Short = (Byte)'3'
	};

	/// <summary>
	/// TFtdcSysSettlementStatusType��һ��ϵͳ����״̬����
	/// </summary>
	public enum class EnumSysSettlementStatusType : Byte
	{
		/// <summary>
		/// ����Ծ
		/// </summary>
		NonActive = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Startup = (Byte)'2',

		/// <summary>
		/// ����
		/// </summary>
		Operating = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		Settlement = (Byte)'4',

		/// <summary>
		/// �������
		/// </summary>
		SettlementFinished = (Byte)'5'
	};

	/// <summary>
	/// TFtdcRatioAttrType��һ��������������
	/// </summary>
	public enum class EnumRatioAttrType : Byte
	{
		/// <summary>
		/// ���׷���
		/// </summary>
		Trade = (Byte)'0',

		/// <summary>
		/// �������
		/// </summary>
		Settlement = (Byte)'1'
	};

	/// <summary>
	/// TFtdcHedgeFlagType��һ��Ͷ���ױ���־����
	/// </summary>
	public enum class EnumHedgeFlagType : Byte
	{
		/// <summary>
		/// Ͷ��
		/// </summary>
		Speculation = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Arbitrage = (Byte)'2',

		/// <summary>
		/// �ױ�
		/// </summary>
		Hedge = (Byte)'3'
	};

	/// <summary>
	/// TFtdcClientIDTypeType��һ�����ױ�����������
	/// </summary>
	public enum class EnumClientIDTypeType : Byte
	{
		/// <summary>
		/// Ͷ��
		/// </summary>
		Speculation = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Arbitrage = (Byte)'2',

		/// <summary>
		/// �ױ�
		/// </summary>
		Hedge = (Byte)'3'
	};

	/// <summary>
	/// TFtdcOrderPriceTypeType��һ�������۸���������
	/// </summary>
	public enum class EnumOrderPriceTypeType : Byte
	{
		/// <summary>
		/// �����
		/// </summary>
		AnyPrice = (Byte)'1',

		/// <summary>
		/// �޼�
		/// </summary>
		LimitPrice = (Byte)'2',

		/// <summary>
		/// ���ż�
		/// </summary>
		BestPrice = (Byte)'3',

		/// <summary>
		/// ���¼�
		/// </summary>
		LastPrice = (Byte)'4',

		/// <summary>
		/// ���¼۸����ϸ�1��ticks
		/// </summary>
		LastPricePlusOneTicks = (Byte)'5',

		/// <summary>
		/// ���¼۸����ϸ�2��ticks
		/// </summary>
		LastPricePlusTwoTicks = (Byte)'6',

		/// <summary>
		/// ���¼۸����ϸ�3��ticks
		/// </summary>
		LastPricePlusThreeTicks = (Byte)'7',

		/// <summary>
		/// ��һ��
		/// </summary>
		AskPrice1 = (Byte)'8',

		/// <summary>
		/// ��һ�۸����ϸ�1��ticks
		/// </summary>
		AskPrice1PlusOneTicks = (Byte)'9',

		/// <summary>
		/// ��һ�۸����ϸ�2��ticks
		/// </summary>
		AskPrice1PlusTwoTicks = (Byte)'A',

		/// <summary>
		/// ��һ�۸����ϸ�3��ticks
		/// </summary>
		AskPrice1PlusThreeTicks = (Byte)'B',

		/// <summary>
		/// ��һ��
		/// </summary>
		BidPrice1 = (Byte)'C',

		/// <summary>
		/// ��һ�۸����ϸ�1��ticks
		/// </summary>
		BidPrice1PlusOneTicks = (Byte)'D',

		/// <summary>
		/// ��һ�۸����ϸ�2��ticks
		/// </summary>
		BidPrice1PlusTwoTicks = (Byte)'E',

		/// <summary>
		/// ��һ�۸����ϸ�3��ticks
		/// </summary>
		BidPrice1PlusThreeTicks = (Byte)'F'
	};

	/// <summary>
	/// TFtdcOffsetFlagType��һ����ƽ��־����
	/// </summary>
	public enum class EnumOffsetFlagType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Open = (Byte)'0',

		/// <summary>
		/// ƽ��
		/// </summary>
		Close = (Byte)'1',

		/// <summary>
		/// ǿƽ
		/// </summary>
		ForceClose = (Byte)'2',

		/// <summary>
		/// ƽ��
		/// </summary>
		CloseToday = (Byte)'3',

		/// <summary>
		/// ƽ��
		/// </summary>
		CloseYesterday = (Byte)'4',

		/// <summary>
		/// ǿ��
		/// </summary>
		ForceOff = (Byte)'5',

		/// <summary>
		/// ����ǿƽ
		/// </summary>
		LocalForceClose = (Byte)'6'
	};

	/// <summary>
	/// TFtdcForceCloseReasonType��һ��ǿƽԭ������
	/// </summary>
	public enum class EnumForceCloseReasonType : Byte
	{
		/// <summary>
		/// ��ǿƽ
		/// </summary>
		NotForceClose = (Byte)'0',

		/// <summary>
		/// �ʽ���
		/// </summary>
		LackDeposit = (Byte)'1',

		/// <summary>
		/// �ͻ�����
		/// </summary>
		ClientOverPositionLimit = (Byte)'2',

		/// <summary>
		/// ��Ա����
		/// </summary>
		MemberOverPositionLimit = (Byte)'3',

		/// <summary>
		/// �ֲַ�������
		/// </summary>
		NotMultiple = (Byte)'4',

		/// <summary>
		/// Υ��
		/// </summary>
		Violation = (Byte)'5',

		/// <summary>
		/// ����
		/// </summary>
		Other = (Byte)'6',

		/// <summary>
		/// ��Ȼ���ٽ�����
		/// </summary>
		PersonDeliv = (Byte)'7'
	};

	/// <summary>
	/// TFtdcOrderTypeType��һ��������������
	/// </summary>
	public enum class EnumOrderTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// ��������
		/// </summary>
		DeriveFromQuote = (Byte)'1',

		/// <summary>
		/// �������
		/// </summary>
		DeriveFromCombination = (Byte)'2',

		/// <summary>
		/// ��ϱ���
		/// </summary>
		Combination = (Byte)'3',

		/// <summary>
		/// ������
		/// </summary>
		ConditionalOrder = (Byte)'4',

		/// <summary>
		/// ������
		/// </summary>
		Swap = (Byte)'5'
	};

	/// <summary>
	/// TFtdcTimeConditionType��һ����Ч����������
	/// </summary>
	public enum class EnumTimeConditionType : Byte
	{
		/// <summary>
		/// ������ɣ�������
		/// </summary>
		IOC = (Byte)'1',

		/// <summary>
		/// ������Ч
		/// </summary>
		GFS = (Byte)'2',

		/// <summary>
		/// ������Ч
		/// </summary>
		GFD = (Byte)'3',

		/// <summary>
		/// ָ������ǰ��Ч
		/// </summary>
		GTD = (Byte)'4',

		/// <summary>
		/// ����ǰ��Ч
		/// </summary>
		GTC = (Byte)'5',

		/// <summary>
		/// ���Ͼ�����Ч
		/// </summary>
		GFA = (Byte)'6'
	};

	/// <summary>
	/// TFtdcVolumeConditionType��һ���ɽ�����������
	/// </summary>
	public enum class EnumVolumeConditionType : Byte
	{
		/// <summary>
		/// �κ�����
		/// </summary>
		AV = (Byte)'1',

		/// <summary>
		/// ��С����
		/// </summary>
		MV = (Byte)'2',

		/// <summary>
		/// ȫ������
		/// </summary>
		CV = (Byte)'3'
	};

	/// <summary>
	/// TFtdcContingentConditionType��һ��������������
	/// </summary>
	public enum class EnumContingentConditionType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Immediately = (Byte)'1',

		/// <summary>
		/// ֹ��
		/// </summary>
		Touch = (Byte)'2',

		/// <summary>
		/// ֹӮ
		/// </summary>
		TouchProfit = (Byte)'3',

		/// <summary>
		/// Ԥ��
		/// </summary>
		ParkedOrder = (Byte)'4',

		/// <summary>
		/// ���¼۴���������
		/// </summary>
		LastPriceGreaterThanStopPrice = (Byte)'5',

		/// <summary>
		/// ���¼۴��ڵ���������
		/// </summary>
		LastPriceGreaterEqualStopPrice = (Byte)'6',

		/// <summary>
		/// ���¼�С��������
		/// </summary>
		LastPriceLesserThanStopPrice = (Byte)'7',

		/// <summary>
		/// ���¼�С�ڵ���������
		/// </summary>
		LastPriceLesserEqualStopPrice = (Byte)'8',

		/// <summary>
		/// ��һ�۴���������
		/// </summary>
		AskPriceGreaterThanStopPrice = (Byte)'9',

		/// <summary>
		/// ��һ�۴��ڵ���������
		/// </summary>
		AskPriceGreaterEqualStopPrice = (Byte)'A',

		/// <summary>
		/// ��һ��С��������
		/// </summary>
		AskPriceLesserThanStopPrice = (Byte)'B',

		/// <summary>
		/// ��һ��С�ڵ���������
		/// </summary>
		AskPriceLesserEqualStopPrice = (Byte)'C',

		/// <summary>
		/// ��һ�۴���������
		/// </summary>
		BidPriceGreaterThanStopPrice = (Byte)'D',

		/// <summary>
		/// ��һ�۴��ڵ���������
		/// </summary>
		BidPriceGreaterEqualStopPrice = (Byte)'E',

		/// <summary>
		/// ��һ��С��������
		/// </summary>
		BidPriceLesserThanStopPrice = (Byte)'F',

		/// <summary>
		/// ��һ��С�ڵ���������
		/// </summary>
		BidPriceLesserEqualStopPrice = (Byte)'H'
	};

	/// <summary>
	/// TFtdcActionFlagType��һ��������־����
	/// </summary>
	public enum class EnumActionFlagType : Byte
	{
		/// <summary>
		/// ɾ��
		/// </summary>
		Delete = (Byte)'0',

		/// <summary>
		/// �޸�
		/// </summary>
		Modify = (Byte)'3'
	};

	/// <summary>
	/// TFtdcTradingRightType��һ������Ȩ������
	/// </summary>
	public enum class EnumTradingRightType : Byte
	{
		/// <summary>
		/// ���Խ���
		/// </summary>
		Allow = (Byte)'0',

		/// <summary>
		/// ֻ��ƽ��
		/// </summary>
		CloseOnly = (Byte)'1',

		/// <summary>
		/// ���ܽ���
		/// </summary>
		Forbidden = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrderSourceType��һ��������Դ����
	/// </summary>
	public enum class EnumOrderSourceType : Byte
	{
		/// <summary>
		/// ���Բ�����
		/// </summary>
		Participant = (Byte)'0',

		/// <summary>
		/// ���Թ���Ա
		/// </summary>
		Administrator = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTradeTypeType��һ���ɽ���������
	/// </summary>
	public enum class EnumTradeTypeType : Byte
	{
		/// <summary>
		/// ��ͨ�ɽ�
		/// </summary>
		Common = (Byte)'0',

		/// <summary>
		/// ��Ȩִ��
		/// </summary>
		OptionsExecution = (Byte)'1',

		/// <summary>
		/// OTC�ɽ�
		/// </summary>
		OTC = (Byte)'2',

		/// <summary>
		/// ��ת�������ɽ�
		/// </summary>
		EFPDerived = (Byte)'3',

		/// <summary>
		/// ��������ɽ�
		/// </summary>
		CombinationDerived = (Byte)'4'
	};

	/// <summary>
	/// TFtdcPriceSourceType��һ���ɽ�����Դ����
	/// </summary>
	public enum class EnumPriceSourceType : Byte
	{
		/// <summary>
		/// ǰ�ɽ���
		/// </summary>
		LastPrice = (Byte)'0',

		/// <summary>
		/// ��ί�м�
		/// </summary>
		Buy = (Byte)'1',

		/// <summary>
		/// ��ί�м�
		/// </summary>
		Sell = (Byte)'2'
	};

	/// <summary>
	/// TFtdcInstrumentStatusType��һ����Լ����״̬����
	/// </summary>
	public enum class EnumInstrumentStatusType : Byte
	{
		/// <summary>
		/// ����ǰ
		/// </summary>
		BeforeTrading = (Byte)'0',

		/// <summary>
		/// �ǽ���
		/// </summary>
		NoTrading = (Byte)'1',

		/// <summary>
		/// ��������
		/// </summary>
		Continous = (Byte)'2',

		/// <summary>
		/// ���Ͼ��۱���
		/// </summary>
		AuctionOrdering = (Byte)'3',

		/// <summary>
		/// ���Ͼ��ۼ۸�ƽ��
		/// </summary>
		AuctionBalance = (Byte)'4',

		/// <summary>
		/// ���Ͼ��۴��
		/// </summary>
		AuctionMatch = (Byte)'5',

		/// <summary>
		/// ����
		/// </summary>
		Closed = (Byte)'6'
	};

	/// <summary>
	/// TFtdcInstStatusEnterReasonType��һ��Ʒ�ֽ��뽻��״̬ԭ������
	/// </summary>
	public enum class EnumInstStatusEnterReasonType : Byte
	{
		/// <summary>
		/// �Զ��л�
		/// </summary>
		Automatic = (Byte)'1',

		/// <summary>
		/// �ֶ��л�
		/// </summary>
		Manual = (Byte)'2',

		/// <summary>
		/// �۶�
		/// </summary>
		Fuse = (Byte)'3'
	};

	/// <summary>
	/// TFtdcBatchStatusType��һ������״̬����
	/// </summary>
	public enum class EnumBatchStatusType : Byte
	{
		/// <summary>
		/// δ�ϴ�
		/// </summary>
		NoUpload = (Byte)'1',

		/// <summary>
		/// ���ϴ�
		/// </summary>
		Uploaded = (Byte)'2',

		/// <summary>
		/// ���ʧ��
		/// </summary>
		Failed = (Byte)'3'
	};

	/// <summary>
	/// TFtdcReturnStyleType��һ����Ʒ�ַ�����ʽ����
	/// </summary>
	public enum class EnumReturnStyleType : Byte
	{
		/// <summary>
		/// ������Ʒ��
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// ��Ʒ��
		/// </summary>
		ByProduct = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReturnPatternType��һ������ģʽ����
	/// </summary>
	public enum class EnumReturnPatternType : Byte
	{
		/// <summary>
		/// ���ɽ�����
		/// </summary>
		ByVolume = (Byte)'1',

		/// <summary>
		/// ������������
		/// </summary>
		ByFeeOnHand = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReturnLevelType��һ��������������
	/// </summary>
	public enum class EnumReturnLevelType : Byte
	{
		/// <summary>
		/// ����1
		/// </summary>
		Level1 = (Byte)'1',

		/// <summary>
		/// ����2
		/// </summary>
		Level2 = (Byte)'2',

		/// <summary>
		/// ����3
		/// </summary>
		Level3 = (Byte)'3',

		/// <summary>
		/// ����4
		/// </summary>
		Level4 = (Byte)'4',

		/// <summary>
		/// ����5
		/// </summary>
		Level5 = (Byte)'5',

		/// <summary>
		/// ����6
		/// </summary>
		Level6 = (Byte)'6',

		/// <summary>
		/// ����7
		/// </summary>
		Level7 = (Byte)'7',

		/// <summary>
		/// ����8
		/// </summary>
		Level8 = (Byte)'8',

		/// <summary>
		/// ����9
		/// </summary>
		Level9 = (Byte)'9'
	};

	/// <summary>
	/// TFtdcReturnStandardType��һ��������׼����
	/// </summary>
	public enum class EnumReturnStandardType : Byte
	{
		/// <summary>
		/// �ֽ׶η���
		/// </summary>
		ByPeriod = (Byte)'1',

		/// <summary>
		/// ��ĳһ��׼
		/// </summary>
		ByStandard = (Byte)'2'
	};

	/// <summary>
	/// TFtdcMortgageTypeType��һ����Ѻ��������
	/// </summary>
	public enum class EnumMortgageTypeType : Byte
	{
		/// <summary>
		/// �ʳ�
		/// </summary>
		Out = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		In = (Byte)'1'
	};

	/// <summary>
	/// TFtdcInvestorSettlementParamIDType��һ��Ͷ���߽��������������
	/// </summary>
	public enum class EnumInvestorSettlementParamIDType : Byte
	{
		/// <summary>
		/// ������֤��
		/// </summary>
		BaseMargin = (Byte)'1',

		/// <summary>
		/// ���Ȩ���׼
		/// </summary>
		LowestInterest = (Byte)'2',

		/// <summary>
		/// ��Ѻ����
		/// </summary>
		MortgageRatio = (Byte)'4',

		/// <summary>
		/// ��֤���㷨
		/// </summary>
		MarginWay = (Byte)'5',

		/// <summary>
		/// ���㵥(����)Ȩ����ڽ��
		/// </summary>
		BillDeposit = (Byte)'9'
	};

	/// <summary>
	/// TFtdcExchangeSettlementParamIDType��һ�����������������������
	/// </summary>
	public enum class EnumExchangeSettlementParamIDType : Byte
	{
		/// <summary>
		/// ��Ѻ����
		/// </summary>
		MortgageRatio = (Byte)'1',

		/// <summary>
		/// �����ʽ�����
		/// </summary>
		OtherFundItem = (Byte)'2',

		/// <summary>
		/// �����ʽ��뽻���������
		/// </summary>
		OtherFundImport = (Byte)'3',

		/// <summary>
		/// ������������������ȡ��ʽ
		/// </summary>
		SHFEDelivFee = (Byte)'4',

		/// <summary>
		/// ������������������ȡ��ʽ
		/// </summary>
		DCEDelivFee = (Byte)'5',

		/// <summary>
		/// �н���������Ϳ��ý��
		/// </summary>
		CFFEXMinPrepa = (Byte)'6'
	};

	/// <summary>
	/// TFtdcSystemParamIDType��һ��ϵͳ������������
	/// </summary>
	public enum class EnumSystemParamIDType : Byte
	{
		/// <summary>
		/// Ͷ���ߴ�����С����
		/// </summary>
		InvestorIDMinLength = (Byte)'1',

		/// <summary>
		/// Ͷ�����ʺŴ�����С����
		/// </summary>
		AccountIDMinLength = (Byte)'2',

		/// <summary>
		/// Ͷ���߿���Ĭ�ϵ�¼Ȩ��
		/// </summary>
		UserRightLogon = (Byte)'3',

		/// <summary>
		/// Ͷ���߽��׽��㵥�ɽ����ܷ�ʽ
		/// </summary>
		SettlementBillTrade = (Byte)'4',

		/// <summary>
		/// ͳһ�������½��ױ��뷽ʽ
		/// </summary>
		TradingCode = (Byte)'5',

		/// <summary>
		/// �����Ƿ��жϴ���δ���˵ĳ����ͷ����ʽ�
		/// </summary>
		CheckFund = (Byte)'6',

		/// <summary>
		/// �ϴ��Ľ����ļ���ʶ
		/// </summary>
		UploadSettlementFile = (Byte)'U',

		/// <summary>
		/// ���صı�֤�����ļ�
		/// </summary>
		DownloadCSRCFile = (Byte)'D',

		/// <summary>
		/// ���㵥�ļ���ʶ
		/// </summary>
		SettlementBillFile = (Byte)'S',

		/// <summary>
		/// ֤����ļ���ʶ
		/// </summary>
		CSRCOthersFile = (Byte)'C',

		/// <summary>
		/// Ͷ������Ƭ·��
		/// </summary>
		InvestorPhoto = (Byte)'P',

		/// <summary>
		/// �ϱ���֤������������
		/// </summary>
		CSRCData = (Byte)'R',

		/// <summary>
		/// ��������¼�뷽ʽ
		/// </summary>
		InvestorPwdModel = (Byte)'I'
	};

	/// <summary>
	/// TFtdcTradeParamIDType��һ������ϵͳ������������
	/// </summary>
	public enum class EnumTradeParamIDType : Byte
	{
		/// <summary>
		/// ϵͳ�����㷨
		/// </summary>
		EncryptionStandard = (Byte)'E',

		/// <summary>
		/// ϵͳ�����㷨
		/// </summary>
		RiskMode = (Byte)'R',

		/// <summary>
		/// ϵͳ�����㷨�Ƿ�ȫ�� 0-�� 1-��
		/// </summary>
		RiskModeGlobal = (Byte)'G'
	};

	/// <summary>
	/// TFtdcFileIDType��һ���ļ���ʶ����
	/// </summary>
	public enum class EnumFileIDType : Byte
	{
		/// <summary>
		/// �ʽ�����
		/// </summary>
		SettlementFund = (Byte)'F',

		/// <summary>
		/// �ɽ�����
		/// </summary>
		Trade = (Byte)'T',

		/// <summary>
		/// Ͷ���ֲ߳�����
		/// </summary>
		InvestorPosition = (Byte)'P',

		/// <summary>
		/// Ͷ���߷����ʽ�����
		/// </summary>
		SubEntryFund = (Byte)'O',

		/// <summary>
		/// ֣������ϳֲ�����
		/// </summary>
		CZCECombinationPos = (Byte)'C',

		/// <summary>
		/// �ϱ���֤������������
		/// </summary>
		CSRCData = (Byte)'R'
	};

	/// <summary>
	/// TFtdcFileTypeType��һ���ļ��ϴ���������
	/// </summary>
	public enum class EnumFileTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Settlement = (Byte)'0',

		/// <summary>
		/// �˶�
		/// </summary>
		Check = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFileFormatType��һ���ļ���ʽ����
	/// </summary>
	public enum class EnumFileFormatType : Byte
	{
		/// <summary>
		/// �ı��ļ�(.txt)
		/// </summary>
		Txt = (Byte)'0',

		/// <summary>
		/// ѹ���ļ�(.zip)
		/// </summary>
		Zip = (Byte)'1',

		/// <summary>
		/// DBF�ļ�(.dbf)
		/// </summary>
		DBF = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFileUploadStatusType��һ���ļ�״̬����
	/// </summary>
	public enum class EnumFileUploadStatusType : Byte
	{
		/// <summary>
		/// �ϴ��ɹ�
		/// </summary>
		SucceedUpload = (Byte)'1',

		/// <summary>
		/// �ϴ�ʧ��
		/// </summary>
		FailedUpload = (Byte)'2',

		/// <summary>
		/// ����ɹ�
		/// </summary>
		SucceedLoad = (Byte)'3',

		/// <summary>
		/// ���벿�ֳɹ�
		/// </summary>
		PartSucceedLoad = (Byte)'4',

		/// <summary>
		/// ����ʧ��
		/// </summary>
		FailedLoad = (Byte)'5'
	};

	/// <summary>
	/// TFtdcTransferDirectionType��һ���Ʋַ�������
	/// </summary>
	public enum class EnumTransferDirectionType : Byte
	{
		/// <summary>
		/// �Ƴ�
		/// </summary>
		Out = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		In = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankFlagType��һ������ͳһ��ʶ��������
	/// </summary>
	public enum class EnumBankFlagType : Byte
	{
		/// <summary>
		/// ��������
		/// </summary>
		ICBC = (Byte)'1',

		/// <summary>
		/// ũҵ����
		/// </summary>
		ABC = (Byte)'2',

		/// <summary>
		/// �й�����
		/// </summary>
		BC = (Byte)'3',

		/// <summary>
		/// ��������
		/// </summary>
		CBC = (Byte)'4',

		/// <summary>
		/// ��ͨ����
		/// </summary>
		BOC = (Byte)'5',

		/// <summary>
		/// ��������
		/// </summary>
		Other = (Byte)'Z'
	};

	/// <summary>
	/// TFtdcSpecialCreateRuleType��һ������Ĵ�����������
	/// </summary>
	public enum class EnumSpecialCreateRuleType : Byte
	{
		/// <summary>
		/// û�����ⴴ������
		/// </summary>
		NoSpecialRule = (Byte)'0',

		/// <summary>
		/// ����������
		/// </summary>
		NoSpringFestival = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBasisPriceTypeType��һ�����ƻ�׼����������
	/// </summary>
	public enum class EnumBasisPriceTypeType : Byte
	{
		/// <summary>
		/// ��һ��Լ�����
		/// </summary>
		LastSettlement = (Byte)'1',

		/// <summary>
		/// ��һ��Լ���̼�
		/// </summary>
		LaseClose = (Byte)'2'
	};

	/// <summary>
	/// TFtdcProductLifePhaseType��һ����Ʒ��������״̬����
	/// </summary>
	public enum class EnumProductLifePhaseType : Byte
	{
		/// <summary>
		/// ��Ծ
		/// </summary>
		Active = (Byte)'1',

		/// <summary>
		/// ����Ծ
		/// </summary>
		NonActive = (Byte)'2',

		/// <summary>
		/// ע��
		/// </summary>
		Canceled = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDeliveryModeType��һ�����ʽ����
	/// </summary>
	public enum class EnumDeliveryModeType : Byte
	{
		/// <summary>
		/// �ֽ𽻸�
		/// </summary>
		CashDeliv = (Byte)'1',

		/// <summary>
		/// ʵ�ｻ��
		/// </summary>
		CommodityDeliv = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundIOTypeType��һ���������������
	/// </summary>
	public enum class EnumFundIOTypeType : Byte
	{
		/// <summary>
		/// �����
		/// </summary>
		FundIO = (Byte)'1',

		/// <summary>
		/// ����ת��
		/// </summary>
		Transfer = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundTypeType��һ���ʽ���������
	/// </summary>
	public enum class EnumFundTypeType : Byte
	{
		/// <summary>
		/// ���д��
		/// </summary>
		Deposite = (Byte)'1',

		/// <summary>
		/// �����ʽ�
		/// </summary>
		ItemFund = (Byte)'2',

		/// <summary>
		/// ��˾����
		/// </summary>
		Company = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFundDirectionType��һ�������������
	/// </summary>
	public enum class EnumFundDirectionType : Byte
	{
		/// <summary>
		/// ���
		/// </summary>
		In = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Out = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundStatusType��һ���ʽ�״̬����
	/// </summary>
	public enum class EnumFundStatusType : Byte
	{
		/// <summary>
		/// ��¼��
		/// </summary>
		Record = (Byte)'1',

		/// <summary>
		/// �Ѹ���
		/// </summary>
		Check = (Byte)'2',

		/// <summary>
		/// �ѳ���
		/// </summary>
		Charge = (Byte)'3'
	};

	/// <summary>
	/// TFtdcPublishStatusType��һ������״̬����
	/// </summary>
	public enum class EnumPublishStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		None = (Byte)'1',

		/// <summary>
		/// ���ڷ���
		/// </summary>
		Publishing = (Byte)'2',

		/// <summary>
		/// �ѷ���
		/// </summary>
		Published = (Byte)'3'
	};

	/// <summary>
	/// TFtdcSystemStatusType��һ��ϵͳ״̬����
	/// </summary>
	public enum class EnumSystemStatusType : Byte
	{
		/// <summary>
		/// ����Ծ
		/// </summary>
		NonActive = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Startup = (Byte)'2',

		/// <summary>
		/// ���׿�ʼ��ʼ��
		/// </summary>
		Initialize = (Byte)'3',

		/// <summary>
		/// ������ɳ�ʼ��
		/// </summary>
		Initialized = (Byte)'4',

		/// <summary>
		/// ���п�ʼ
		/// </summary>
		Close = (Byte)'5',

		/// <summary>
		/// �������
		/// </summary>
		Closed = (Byte)'6',

		/// <summary>
		/// ����
		/// </summary>
		Settlement = (Byte)'7'
	};

	/// <summary>
	/// TFtdcSettlementStatusType��һ������״̬����
	/// </summary>
	public enum class EnumSettlementStatusType : Byte
	{
		/// <summary>
		/// ��ʼ
		/// </summary>
		Initialize = (Byte)'0',

		/// <summary>
		/// ������
		/// </summary>
		Settlementing = (Byte)'1',

		/// <summary>
		/// �ѽ���
		/// </summary>
		Settlemented = (Byte)'2',

		/// <summary>
		/// �������
		/// </summary>
		Finished = (Byte)'3'
	};

	/// <summary>
	/// TFtdcInvestorTypeType��һ��Ͷ������������
	/// </summary>
	public enum class EnumInvestorTypeType : Byte
	{
		/// <summary>
		/// ��Ȼ��
		/// </summary>
		Person = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Company = (Byte)'1',

		/// <summary>
		/// Ͷ�ʻ���
		/// </summary>
		Fund = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerTypeType��һ�����͹�˾��������
	/// </summary>
	public enum class EnumBrokerTypeType : Byte
	{
		/// <summary>
		/// ���׻�Ա
		/// </summary>
		Trade = (Byte)'0',

		/// <summary>
		/// ���׽����Ա
		/// </summary>
		TradeSettle = (Byte)'1'
	};

	/// <summary>
	/// TFtdcRiskLevelType��һ�����յȼ�����
	/// </summary>
	public enum class EnumRiskLevelType : Byte
	{
		/// <summary>
		/// �ͷ��տͻ�
		/// </summary>
		Low = (Byte)'1',

		/// <summary>
		/// ��ͨ�ͻ�
		/// </summary>
		Normal = (Byte)'2',

		/// <summary>
		/// ��ע�ͻ�
		/// </summary>
		Focus = (Byte)'3',

		/// <summary>
		/// ���տͻ�
		/// </summary>
		Risk = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFeeAcceptStyleType��һ����������ȡ��ʽ����
	/// </summary>
	public enum class EnumFeeAcceptStyleType : Byte
	{
		/// <summary>
		/// ��������ȡ
		/// </summary>
		ByTrade = (Byte)'1',

		/// <summary>
		/// ��������ȡ
		/// </summary>
		ByDeliv = (Byte)'2',

		/// <summary>
		/// ����
		/// </summary>
		None = (Byte)'3',

		/// <summary>
		/// ��ָ����������ȡ
		/// </summary>
		FixFee = (Byte)'4'
	};

	/// <summary>
	/// TFtdcPasswordTypeType��һ��������������
	/// </summary>
	public enum class EnumPasswordTypeType : Byte
	{
		/// <summary>
		/// ��������
		/// </summary>
		Trade = (Byte)'1',

		/// <summary>
		/// �ʽ�����
		/// </summary>
		Account = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAlgorithmType��һ��ӯ���㷨����
	/// </summary>
	public enum class EnumAlgorithmType : Byte
	{
		/// <summary>
		/// ��ӯ����������
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// ��ӯ���ƣ�������
		/// </summary>
		OnlyLost = (Byte)'2',

		/// <summary>
		/// ��ӯ�ƣ���������
		/// </summary>
		OnlyGain = (Byte)'3',

		/// <summary>
		/// ��ӯ������������
		/// </summary>
		None = (Byte)'4'
	};

	/// <summary>
	/// TFtdcIncludeCloseProfitType��һ���Ƿ����ƽ��ӯ������
	/// </summary>
	public enum class EnumIncludeCloseProfitType : Byte
	{
		/// <summary>
		/// ����ƽ��ӯ��
		/// </summary>
		Include = (Byte)'0',

		/// <summary>
		/// ������ƽ��ӯ��
		/// </summary>
		NotInclude = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAllWithoutTradeType��һ���Ƿ��ܿ��������������
	/// </summary>
	public enum class EnumAllWithoutTradeType : Byte
	{
		/// <summary>
		/// ���ܿ����������
		/// </summary>
		Enable = (Byte)'0',

		/// <summary>
		/// �ܿ����������
		/// </summary>
		Disable = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFuturePwdFlagType��һ���ʽ�����˶Ա�־����
	/// </summary>
	public enum class EnumFuturePwdFlagType : Byte
	{
		/// <summary>
		/// ���˶�
		/// </summary>
		UnCheck = (Byte)'0',

		/// <summary>
		/// �˶�
		/// </summary>
		Check = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTransferTypeType��һ������ת����������
	/// </summary>
	public enum class EnumTransferTypeType : Byte
	{
		/// <summary>
		/// ����ת�ڻ�
		/// </summary>
		BankToFuture = (Byte)'0',

		/// <summary>
		/// �ڻ�ת����
		/// </summary>
		FutureToBank = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTransferValidFlagType��һ��ת����Ч��־����
	/// </summary>
	public enum class EnumTransferValidFlagType : Byte
	{
		/// <summary>
		/// ��Ч��ʧ��
		/// </summary>
		Invalid = (Byte)'0',

		/// <summary>
		/// ��Ч
		/// </summary>
		Valid = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Reverse = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReasonType��һ����������
	/// </summary>
	public enum class EnumReasonType : Byte
	{
		/// <summary>
		/// ��
		/// </summary>
		CD = (Byte)'0',

		/// <summary>
		/// �ʽ���;
		/// </summary>
		ZT = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		QT = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSexType��һ���Ա�����
	/// </summary>
	public enum class EnumSexType : Byte
	{
		/// <summary>
		/// δ֪
		/// </summary>
		None = (Byte)'0',

		/// <summary>
		/// ��
		/// </summary>
		Man = (Byte)'1',

		/// <summary>
		/// Ů
		/// </summary>
		Woman = (Byte)'2'
	};

	/// <summary>
	/// TFtdcUserTypeType��һ���û���������
	/// </summary>
	public enum class EnumUserTypeType : Byte
	{
		/// <summary>
		/// Ͷ����
		/// </summary>
		Investor = (Byte)'0',

		/// <summary>
		/// ����Ա
		/// </summary>
		Operator = (Byte)'1',

		/// <summary>
		/// ����Ա
		/// </summary>
		SuperUser = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRateTypeType��һ��������������
	/// </summary>
	public enum class EnumRateTypeType : Byte
	{
		/// <summary>
		/// ��֤����
		/// </summary>
		MarginRate = (Byte)'2',

		/// <summary>
		/// ��������
		/// </summary>
		CommRate = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		AllRate = (Byte)'0'
	};

	/// <summary>
	/// TFtdcNoteTypeType��һ��֪ͨ��������
	/// </summary>
	public enum class EnumNoteTypeType : Byte
	{
		/// <summary>
		/// ���׽��㵥
		/// </summary>
		TradeSettleBill = (Byte)'1',

		/// <summary>
		/// ���׽����±�
		/// </summary>
		TradeSettleMonth = (Byte)'2',

		/// <summary>
		/// ׷�ӱ�֤��֪ͨ��
		/// </summary>
		CallMarginNotes = (Byte)'3',

		/// <summary>
		/// ǿ��ƽ��֪ͨ��
		/// </summary>
		ForceCloseNotes = (Byte)'4',

		/// <summary>
		/// �ɽ�֪ͨ��
		/// </summary>
		TradeNotes = (Byte)'5',

		/// <summary>
		/// ����֪ͨ��
		/// </summary>
		DelivNotes = (Byte)'6'
	};

	/// <summary>
	/// TFtdcSettlementStyleType��һ�����㵥��ʽ����
	/// </summary>
	public enum class EnumSettlementStyleType : Byte
	{
		/// <summary>
		/// ���ն���
		/// </summary>
		Day = (Byte)'1',

		/// <summary>
		/// ��ʶԳ�
		/// </summary>
		Volume = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSettlementBillTypeType��һ�����㵥��������
	/// </summary>
	public enum class EnumSettlementBillTypeType : Byte
	{
		/// <summary>
		/// �ձ�
		/// </summary>
		Day = (Byte)'0',

		/// <summary>
		/// �±�
		/// </summary>
		Month = (Byte)'1'
	};

	/// <summary>
	/// TFtdcUserRightTypeType��һ���ͻ�Ȩ����������
	/// </summary>
	public enum class EnumUserRightTypeType : Byte
	{
		/// <summary>
		/// ��¼
		/// </summary>
		Logon = (Byte)'1',

		/// <summary>
		/// ����ת��
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// �ʼĽ��㵥
		/// </summary>
		EMail = (Byte)'3',

		/// <summary>
		/// ������㵥
		/// </summary>
		Fax = (Byte)'4',

		/// <summary>
		/// ������
		/// </summary>
		ConditionOrder = (Byte)'5'
	};

	/// <summary>
	/// TFtdcMarginPriceTypeType��һ����֤��۸���������
	/// </summary>
	public enum class EnumMarginPriceTypeType : Byte
	{
		/// <summary>
		/// ������
		/// </summary>
		PreSettlementPrice = (Byte)'1',

		/// <summary>
		/// ���¼�
		/// </summary>
		SettlementPrice = (Byte)'2',

		/// <summary>
		/// �ɽ�����
		/// </summary>
		AveragePrice = (Byte)'3',

		/// <summary>
		/// ���ּ�
		/// </summary>
		OpenPrice = (Byte)'4'
	};

	/// <summary>
	/// TFtdcBillGenStatusType��һ�����㵥����״̬����
	/// </summary>
	public enum class EnumBillGenStatusType : Byte
	{
		/// <summary>
		/// ������
		/// </summary>
		None = (Byte)'0',

		/// <summary>
		/// δ����
		/// </summary>
		NoGenerated = (Byte)'1',

		/// <summary>
		/// ������
		/// </summary>
		Generated = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAlgoTypeType��һ���㷨��������
	/// </summary>
	public enum class EnumAlgoTypeType : Byte
	{
		/// <summary>
		/// �ֲִ����㷨
		/// </summary>
		HandlePositionAlgo = (Byte)'1',

		/// <summary>
		/// Ѱ�ұ�֤�����㷨
		/// </summary>
		FindMarginRateAlgo = (Byte)'2'
	};

	/// <summary>
	/// TFtdcHandlePositionAlgoIDType��һ���ֲִ����㷨�������
	/// </summary>
	public enum class EnumHandlePositionAlgoIDType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// ������Ʒ������
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// ֣����Ʒ������
		/// </summary>
		CZCE = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFindMarginRateAlgoIDType��һ��Ѱ�ұ�֤�����㷨�������
	/// </summary>
	public enum class EnumFindMarginRateAlgoIDType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// ������Ʒ������
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// ֣����Ʒ������
		/// </summary>
		CZCE = (Byte)'3'
	};

	/// <summary>
	/// TFtdcHandleTradingAccountAlgoIDType��һ���ʽ����㷨�������
	/// </summary>
	public enum class EnumHandleTradingAccountAlgoIDType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// ������Ʒ������
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// ֣����Ʒ������
		/// </summary>
		CZCE = (Byte)'3'
	};

	/// <summary>
	/// TFtdcPersonTypeType��һ����ϵ����������
	/// </summary>
	public enum class EnumPersonTypeType : Byte
	{
		/// <summary>
		/// ָ���µ���
		/// </summary>
		Order = (Byte)'1',

		/// <summary>
		/// ������Ȩ��
		/// </summary>
		Open = (Byte)'2',

		/// <summary>
		/// �ʽ������
		/// </summary>
		Fund = (Byte)'3',

		/// <summary>
		/// ���㵥ȷ����
		/// </summary>
		Settlement = (Byte)'4'
	};

	/// <summary>
	/// TFtdcQueryInvestorRangeType��һ����ѯ��Χ����
	/// </summary>
	public enum class EnumQueryInvestorRangeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// ��ѯ����
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// ��һͶ����
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcInvestorRiskStatusType��һ��Ͷ���߷���״̬����
	/// </summary>
	public enum class EnumInvestorRiskStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Warn = (Byte)'2',

		/// <summary>
		/// ׷��
		/// </summary>
		Call = (Byte)'3',

		/// <summary>
		/// ǿƽ
		/// </summary>
		Force = (Byte)'4',

		/// <summary>
		/// �쳣
		/// </summary>
		Exception = (Byte)'5'
	};

	/// <summary>
	/// TFtdcUserEventTypeType��һ���û��¼���������
	/// </summary>
	public enum class EnumUserEventTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)' ',

		/// <summary>
		/// ��¼
		/// </summary>
		Login = (Byte)'1',

		/// <summary>
		/// �ǳ�
		/// </summary>
		Logout = (Byte)'2',

		/// <summary>
		/// ���׳ɹ�
		/// </summary>
		Trading = (Byte)'3',

		/// <summary>
		/// ����ʧ��
		/// </summary>
		TradingError = (Byte)'4',

		/// <summary>
		/// �޸�����
		/// </summary>
		UpdatePassword = (Byte)'5',

		/// <summary>
		/// ����
		/// </summary>
		Other = (Byte)'9'
	};

	/// <summary>
	/// TFtdcCloseStyleType��һ��ƽ�ַ�ʽ����
	/// </summary>
	public enum class EnumCloseStyleType : Byte
	{
		/// <summary>
		/// �ȿ���ƽ
		/// </summary>
		Close = (Byte)'0',

		/// <summary>
		/// ��ƽ����ƽ��
		/// </summary>
		CloseToday = (Byte)'1'
	};

	/// <summary>
	/// TFtdcStatModeType��һ��ͳ�Ʒ�ʽ����
	/// </summary>
	public enum class EnumStatModeType : Byte
	{
		/// <summary>
		/// ----
		/// </summary>
		Non = (Byte)'0',

		/// <summary>
		/// ����Լͳ��
		/// </summary>
		Instrument = (Byte)'1',

		/// <summary>
		/// ����Ʒͳ��
		/// </summary>
		Product = (Byte)'2',

		/// <summary>
		/// ��Ͷ����ͳ��
		/// </summary>
		Investor = (Byte)'3'
	};

	/// <summary>
	/// TFtdcParkedOrderStatusType��һ��Ԥ��״̬����
	/// </summary>
	public enum class EnumParkedOrderStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NotSend = (Byte)'1',

		/// <summary>
		/// �ѷ���
		/// </summary>
		Send = (Byte)'2',

		/// <summary>
		/// ��ɾ��
		/// </summary>
		Deleted = (Byte)'3'
	};

	/// <summary>
	/// TFtdcVirDealStatusType��һ������״̬����
	/// </summary>
	public enum class EnumVirDealStatusType : Byte
	{
		/// <summary>
		/// ���ڴ���
		/// </summary>
		Dealing = (Byte)'1',

		/// <summary>
		/// ����ɹ�
		/// </summary>
		DeaclSucceed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrgSystemIDType��һ��ԭ��ϵͳ��������
	/// </summary>
	public enum class EnumOrgSystemIDType : Byte
	{
		/// <summary>
		/// �ۺϽ���ƽ̨
		/// </summary>
		Standard = (Byte)'0',

		/// <summary>
		/// ��ʢϵͳ
		/// </summary>
		ESunny = (Byte)'1',

		/// <summary>
		/// ���˴�V6ϵͳ
		/// </summary>
		KingStarV6 = (Byte)'2'
	};

	/// <summary>
	/// TFtdcVirTradeStatusType��һ������״̬����
	/// </summary>
	public enum class EnumVirTradeStatusType : Byte
	{
		/// <summary>
		/// ����������
		/// </summary>
		NaturalDeal = (Byte)'0',

		/// <summary>
		/// �ɹ�����
		/// </summary>
		SucceedEnd = (Byte)'1',

		/// <summary>
		/// ʧ�ܽ���
		/// </summary>
		FailedEND = (Byte)'2',

		/// <summary>
		/// �쳣��
		/// </summary>
		Exception = (Byte)'3',

		/// <summary>
		/// ���˹��쳣����
		/// </summary>
		ManualDeal = (Byte)'4',

		/// <summary>
		/// ͨѶ�쳣 �����˹�����
		/// </summary>
		MesException = (Byte)'5',

		/// <summary>
		/// ϵͳ�������˹�����
		/// </summary>
		SysException = (Byte)'6'
	};

	/// <summary>
	/// TFtdcVirBankAccTypeType��һ�������ʻ���������
	/// </summary>
	public enum class EnumVirBankAccTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// ���
		/// </summary>
		BankCard = (Byte)'2',

		/// <summary>
		/// ���ÿ�
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcVirementStatusType��һ�������ʻ���������
	/// </summary>
	public enum class EnumVirementStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Natural = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Canceled = (Byte)'9'
	};

	/// <summary>
	/// TFtdcVirementAvailAbilityType��һ����Ч��־����
	/// </summary>
	public enum class EnumVirementAvailAbilityType : Byte
	{
		/// <summary>
		/// δȷ��
		/// </summary>
		NoAvailAbility = (Byte)'0',

		/// <summary>
		/// ��Ч
		/// </summary>
		AvailAbility = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Repeal = (Byte)'2'
	};

	/// <summary>
	/// TFtdcVirementTradeCodeType��һ�����״�������
	/// </summary>
	public enum class EnumVirementTradeCodeType : Byte
	{
		/// <summary>
		/// ���з��������ʽ�ת�ڻ�
		/// </summary>
		BankBankToFuture_102001 = (Byte)'1',//'102001',

		/// <summary>
		/// ���з����ڻ��ʽ�ת����
		/// </summary>
		BankFutureToBank_102002 = (Byte)'2',//'102002',

		/// <summary>
		/// �ڻ����������ʽ�ת�ڻ�
		/// </summary>
		FutureBankToFuture_202001 = (Byte)'3',//'202001',

		/// <summary>
		/// �ڻ������ڻ��ʽ�ת����
		/// </summary>
		FutureFutureToBank_202002 = (Byte)'4'//'202002'
	};

	/// <summary>
	/// TFtdcCFMMCKeyKindType��һ����̬��Կ���(��֤����)����
	/// </summary>
	public enum class EnumCFMMCKeyKindType : Byte
	{
		/// <summary>
		/// �����������
		/// </summary>
		REQUEST = (Byte)'R',

		/// <summary>
		/// CFMMC�Զ�����
		/// </summary>
		AUTO = (Byte)'A',

		/// <summary>
		/// CFMMC�ֶ�����
		/// </summary>
		MANUAL = (Byte)'M'
	};

	/// <summary>
	/// TFtdcCertificationTypeType��һ��֤����������
	/// </summary>
	public enum class EnumCertificationTypeType : Byte
	{
		/// <summary>
		/// ���֤
		/// </summary>
		IDCard = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Passport = (Byte)'1',

		/// <summary>
		/// ����֤
		/// </summary>
		OfficerIDCard = (Byte)'2',

		/// <summary>
		/// ʿ��֤
		/// </summary>
		SoldierIDCard = (Byte)'3',

		/// <summary>
		/// ����֤
		/// </summary>
		HomeComingCard = (Byte)'4',

		/// <summary>
		/// ���ڲ�
		/// </summary>
		HouseholdRegister = (Byte)'5',

		/// <summary>
		/// Ӫҵִ�պ�
		/// </summary>
		LicenseNo = (Byte)'6',

		/// <summary>
		/// ��֯��������֤
		/// </summary>
		InstitutionCodeCard = (Byte)'7',

		/// <summary>
		/// ��ʱӪҵִ�պ�
		/// </summary>
		TempLicenseNo = (Byte)'8',

		/// <summary>
		/// ������ҵ�Ǽ�֤��
		/// </summary>
		NoEnterpriseLicenseNo = (Byte)'9',

		/// <summary>
		/// ����֤��
		/// </summary>
		OtherCard = (Byte)'x',

		/// <summary>
		/// ���ܲ�������
		/// </summary>
		SuperDepAgree = (Byte)'a'
	};

	/// <summary>
	/// TFtdcFileBusinessCodeType��һ���ļ�ҵ��������
	/// </summary>
	public enum class EnumFileBusinessCodeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Others = (Byte)'0',

		/// <summary>
		/// ת�˽�����ϸ����
		/// </summary>
		TransferDetails = (Byte)'1',

		/// <summary>
		/// �ͻ��˻�״̬����
		/// </summary>
		CustAccStatus = (Byte)'2',

		/// <summary>
		/// �˻��ཻ����ϸ����
		/// </summary>
		AccountTradeDetails = (Byte)'3',

		/// <summary>
		/// �ڻ��˻���Ϣ�����ϸ����
		/// </summary>
		FutureAccountChangeInfoDetails = (Byte)'4',

		/// <summary>
		/// �ͻ��ʽ�̨�������ϸ����
		/// </summary>
		CustMoneyDetail = (Byte)'5',

		/// <summary>
		/// �ͻ�������Ϣ��ϸ����
		/// </summary>
		CustCancelAccountInfo = (Byte)'6',

		/// <summary>
		/// �ͻ��ʽ������˽��
		/// </summary>
		CustMoneyResult = (Byte)'7',

		/// <summary>
		/// ���������쳣����ļ�
		/// </summary>
		OthersExceptionResult = (Byte)'8',

		/// <summary>
		/// �ͻ���Ϣ������ϸ
		/// </summary>
		CustInterestNetMoneyDetails = (Byte)'9',

		/// <summary>
		/// �ͻ��ʽ�����ϸ
		/// </summary>
		CustMoneySendAndReceiveDetails = (Byte)'a',

		/// <summary>
		/// ���˴�������ʽ��ջ���
		/// </summary>
		CorporationMoneyTotal = (Byte)'b',

		/// <summary>
		/// ������ʽ��ջ���
		/// </summary>
		MainbodyMoneyTotal = (Byte)'c',

		/// <summary>
		/// �ܷ�ƽ��������
		/// </summary>
		MainPartMonitorData = (Byte)'d',

		/// <summary>
		/// ������б��������
		/// </summary>
		PreparationMoney = (Byte)'e',

		/// <summary>
		/// Э���������ʽ�������
		/// </summary>
		BankMoneyMonitorData = (Byte)'f'
	};

	/// <summary>
	/// TFtdcCashExchangeCodeType��һ���㳮��־����
	/// </summary>
	public enum class EnumCashExchangeCodeType : Byte
	{
		/// <summary>
		/// ��
		/// </summary>
		Exchange = (Byte)'1',

		/// <summary>
		/// ��
		/// </summary>
		Cash = (Byte)'2'
	};

	/// <summary>
	/// TFtdcYesNoIndicatorType��һ���ǻ���ʶ����
	/// </summary>
	public enum class EnumYesNoIndicatorType : Byte
	{
		/// <summary>
		/// ��
		/// </summary>
		Yes = (Byte)'0',

		/// <summary>
		/// ��
		/// </summary>
		No = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBanlanceTypeType��һ�������������
	/// </summary>
	public enum class EnumBanlanceTypeType : Byte
	{
		/// <summary>
		/// ��ǰ���
		/// </summary>
		CurrentMoney = (Byte)'0',

		/// <summary>
		/// �������
		/// </summary>
		UsableMoney = (Byte)'1',

		/// <summary>
		/// ��ȡ���
		/// </summary>
		FetchableMoney = (Byte)'2',

		/// <summary>
		/// �������
		/// </summary>
		FreezeMoney = (Byte)'3'
	};

	/// <summary>
	/// TFtdcGenderType��һ���Ա�����
	/// </summary>
	public enum class EnumGenderType : Byte
	{
		/// <summary>
		/// δ֪״̬
		/// </summary>
		Unknown = (Byte)'0',

		/// <summary>
		/// ��
		/// </summary>
		Male = (Byte)'1',

		/// <summary>
		/// Ů
		/// </summary>
		Female = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFeePayFlagType��һ������֧����־����
	/// </summary>
	public enum class EnumFeePayFlagType : Byte
	{
		/// <summary>
		/// �����淽֧������
		/// </summary>
		BEN = (Byte)'0',

		/// <summary>
		/// �ɷ��ͷ�֧������
		/// </summary>
		OUR = (Byte)'1',

		/// <summary>
		/// �ɷ��ͷ�֧������ķ��ã����淽֧�����ܵķ���
		/// </summary>
		SHA = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPassWordKeyTypeType��һ����Կ��������
	/// </summary>
	public enum class EnumPassWordKeyTypeType : Byte
	{
		/// <summary>
		/// ������Կ
		/// </summary>
		ExchangeKey = (Byte)'0',

		/// <summary>
		/// ������Կ
		/// </summary>
		PassWordKey = (Byte)'1',

		/// <summary>
		/// MAC��Կ
		/// </summary>
		MACKey = (Byte)'2',

		/// <summary>
		/// ������Կ
		/// </summary>
		MessageKey = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFBTPassWordTypeType��һ��������������
	/// </summary>
	public enum class EnumFBTPassWordTypeType : Byte
	{
		/// <summary>
		/// ��ѯ
		/// </summary>
		Query = (Byte)'0',

		/// <summary>
		/// ȡ��
		/// </summary>
		Fetch = (Byte)'1',

		/// <summary>
		/// ת��
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// ����
		/// </summary>
		Trade = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFBTEncryModeType��һ�����ܷ�ʽ����
	/// </summary>
	public enum class EnumFBTEncryModeType : Byte
	{
		/// <summary>
		/// ������
		/// </summary>
		NoEncry = (Byte)'0',

		/// <summary>
		/// DES
		/// </summary>
		DES = (Byte)'1',

		/// <summary>
		/// 3DES
		/// </summary>
		DES3 = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBankRepealFlagType��һ�����г�����־����
	/// </summary>
	public enum class EnumBankRepealFlagType : Byte
	{
		/// <summary>
		/// ���������Զ�����
		/// </summary>
		BankNotNeedRepeal = (Byte)'0',

		/// <summary>
		/// ���д��Զ�����
		/// </summary>
		BankWaitingRepeal = (Byte)'1',

		/// <summary>
		/// �������Զ�����
		/// </summary>
		BankBeenRepealed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerRepealFlagType��һ�����̳�����־����
	/// </summary>
	public enum class EnumBrokerRepealFlagType : Byte
	{
		/// <summary>
		/// ���������Զ�����
		/// </summary>
		BrokerNotNeedRepeal = (Byte)'0',

		/// <summary>
		/// ���̴��Զ�����
		/// </summary>
		BrokerWaitingRepeal = (Byte)'1',

		/// <summary>
		/// �������Զ�����
		/// </summary>
		BrokerBeenRepealed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcInstitutionTypeType��һ�������������
	/// </summary>
	public enum class EnumInstitutionTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Bank = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Future = (Byte)'1',

		/// <summary>
		/// ȯ��
		/// </summary>
		Store = (Byte)'2'
	};

	/// <summary>
	/// TFtdcLastFragmentType��һ������Ƭ��־����
	/// </summary>
	public enum class EnumLastFragmentType : Byte
	{
		/// <summary>
		/// ������Ƭ
		/// </summary>
		Yes = (Byte)'0',

		/// <summary>
		/// ��������Ƭ
		/// </summary>
		No = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankAccStatusType��һ�������˻�״̬����
	/// </summary>
	public enum class EnumBankAccStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Freeze = (Byte)'1',

		/// <summary>
		/// ��ʧ
		/// </summary>
		ReportLoss = (Byte)'2'
	};

	/// <summary>
	/// TFtdcMoneyAccountStatusType��һ���ʽ��˻�״̬����
	/// </summary>
	public enum class EnumMoneyAccountStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Cancel = (Byte)'1'
	};

	/// <summary>
	/// TFtdcManageStatusType��һ�����״̬����
	/// </summary>
	public enum class EnumManageStatusType : Byte
	{
		/// <summary>
		/// ָ�����
		/// </summary>
		Point = (Byte)'0',

		/// <summary>
		/// Ԥָ��
		/// </summary>
		PrePoint = (Byte)'1',

		/// <summary>
		/// ����ָ��
		/// </summary>
		CancelPoint = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSystemTypeType��һ��Ӧ��ϵͳ��������
	/// </summary>
	public enum class EnumSystemTypeType : Byte
	{
		/// <summary>
		/// ����ת��
		/// </summary>
		FutureBankTransfer = (Byte)'0',

		/// <summary>
		/// ��֤ת��
		/// </summary>
		StockBankTransfer = (Byte)'1',

		/// <summary>
		/// ���������
		/// </summary>
		TheThirdPartStore = (Byte)'2'
	};

	/// <summary>
	/// TFtdcTxnEndFlagType��һ������ת�ʻ�ת�����־����
	/// </summary>
	public enum class EnumTxnEndFlagType : Byte
	{
		/// <summary>
		/// ����������
		/// </summary>
		NormalProcessing = (Byte)'0',

		/// <summary>
		/// �ɹ�����
		/// </summary>
		Success = (Byte)'1',

		/// <summary>
		/// ʧ�ܽ���
		/// </summary>
		Failed = (Byte)'2',

		/// <summary>
		/// �쳣��
		/// </summary>
		Abnormal = (Byte)'3',

		/// <summary>
		/// ���˹��쳣����
		/// </summary>
		ManualProcessedForException = (Byte)'4',

		/// <summary>
		/// ͨѶ�쳣 �����˹�����
		/// </summary>
		CommuFailedNeedManualProcess = (Byte)'5',

		/// <summary>
		/// ϵͳ�������˹�����
		/// </summary>
		SysErrorNeedManualProcess = (Byte)'6'
	};

	/// <summary>
	/// TFtdcProcessStatusType��һ������ת�ʷ�����״̬����
	/// </summary>
	public enum class EnumProcessStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NotProcess = (Byte)'0',

		/// <summary>
		/// ��ʼ����
		/// </summary>
		StartProcess = (Byte)'1',

		/// <summary>
		/// �������
		/// </summary>
		Finished = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCustTypeType��һ���ͻ���������
	/// </summary>
	public enum class EnumCustTypeType : Byte
	{
		/// <summary>
		/// ��Ȼ��
		/// </summary>
		Person = (Byte)'0',

		/// <summary>
		/// ������
		/// </summary>
		Institution = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFBTTransferDirectionType��һ������ת�ʷ�������
	/// </summary>
	public enum class EnumFBTTransferDirectionType : Byte
	{
		/// <summary>
		/// �������ת�ڻ�
		/// </summary>
		FromBankToFuture = (Byte)'1',

		/// <summary>
		/// �����ڻ�ת����
		/// </summary>
		FromFutureToBank = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOpenOrDestroyType��һ���������������
	/// </summary>
	public enum class EnumOpenOrDestroyType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Open = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Destroy = (Byte)'0'
	};

	/// <summary>
	/// TFtdcAvailabilityFlagType��һ����Ч��־����
	/// </summary>
	public enum class EnumAvailabilityFlagType : Byte
	{
		/// <summary>
		/// δȷ��
		/// </summary>
		Invalid = (Byte)'0',

		/// <summary>
		/// ��Ч
		/// </summary>
		Valid = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Repeal = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrganTypeType��һ��������������
	/// </summary>
	public enum class EnumOrganTypeType : Byte
	{
		/// <summary>
		/// ���д���
		/// </summary>
		Bank = (Byte)'1',

		/// <summary>
		/// ����ǰ��
		/// </summary>
		Future = (Byte)'2',

		/// <summary>
		/// ����ת��ƽ̨����
		/// </summary>
		PlateForm = (Byte)'9'
	};

	/// <summary>
	/// TFtdcOrganLevelType��һ��������������
	/// </summary>
	public enum class EnumOrganLevelType : Byte
	{
		/// <summary>
		/// �������л������ܲ�
		/// </summary>
		HeadQuarters = (Byte)'1',

		/// <summary>
		/// ���з����Ļ��ڻ���˾Ӫҵ��
		/// </summary>
		Branch = (Byte)'2'
	};

	/// <summary>
	/// TFtdcProtocalIDType��һ��Э����������
	/// </summary>
	public enum class EnumProtocalIDType : Byte
	{
		/// <summary>
		/// ����Э��
		/// </summary>
		FutureProtocal = (Byte)'0',

		/// <summary>
		/// ����Э��
		/// </summary>
		ICBCProtocal = (Byte)'1',

		/// <summary>
		/// ũ��Э��
		/// </summary>
		ABCProtocal = (Byte)'2',

		/// <summary>
		/// �й�����Э��
		/// </summary>
		CBCProtocal = (Byte)'3',

		/// <summary>
		/// ����Э��
		/// </summary>
		CCBProtocal = (Byte)'4',

		/// <summary>
		/// ����Э��
		/// </summary>
		BOCOMProtocal = (Byte)'5',

		/// <summary>
		/// ����ת��ƽ̨Э��
		/// </summary>
		FBTPlateFormProtocal = (Byte)'X'
	};

	/// <summary>
	/// TFtdcConnectModeType��һ���׽������ӷ�ʽ����
	/// </summary>
	public enum class EnumConnectModeType : Byte
	{
		/// <summary>
		/// ������
		/// </summary>
		ShortConnect = (Byte)'0',

		/// <summary>
		/// ������
		/// </summary>
		LongConnect = (Byte)'1'
	};

	/// <summary>
	/// TFtdcSyncModeType��һ���׽���ͨ�ŷ�ʽ����
	/// </summary>
	public enum class EnumSyncModeType : Byte
	{
		/// <summary>
		/// �첽
		/// </summary>
		ASync = (Byte)'0',

		/// <summary>
		/// ͬ��
		/// </summary>
		Sync = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankAccTypeType��һ�������ʺ���������
	/// </summary>
	public enum class EnumBankAccTypeType : Byte
	{
		/// <summary>
		/// ���д���
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// ���
		/// </summary>
		SavingCard = (Byte)'2',

		/// <summary>
		/// ���ÿ�
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFutureAccTypeType��һ���ڻ���˾�ʺ���������
	/// </summary>
	public enum class EnumFutureAccTypeType : Byte
	{
		/// <summary>
		/// ���д���
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// ���
		/// </summary>
		SavingCard = (Byte)'2',

		/// <summary>
		/// ���ÿ�
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcOrganStatusType��һ���������״̬����
	/// </summary>
	public enum class EnumOrganStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Ready = (Byte)'0',

		/// <summary>
		/// ǩ��
		/// </summary>
		CheckIn = (Byte)'1',

		/// <summary>
		/// ǩ��
		/// </summary>
		CheckOut = (Byte)'2',

		/// <summary>
		/// �����ļ�����
		/// </summary>
		CheckFileArrived = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		CheckDetail = (Byte)'4',

		/// <summary>
		/// ��������
		/// </summary>
		DayEndClean = (Byte)'5',

		/// <summary>
		/// ע��
		/// </summary>
		Invalid = (Byte)'9'
	};

	/// <summary>
	/// TFtdcCCBFeeModeType��һ�������շ�ģʽ����
	/// </summary>
	public enum class EnumCCBFeeModeType : Byte
	{
		/// <summary>
		/// ��������
		/// </summary>
		ByAmount = (Byte)'1',

		/// <summary>
		/// ���¿���
		/// </summary>
		ByMonth = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCommApiTypeType��һ��ͨѶAPI��������
	/// </summary>
	public enum class EnumCommApiTypeType : Byte
	{
		/// <summary>
		/// �ͻ���
		/// </summary>
		Client = (Byte)'1',

		/// <summary>
		/// �����
		/// </summary>
		Server = (Byte)'2',

		/// <summary>
		/// ����ϵͳ��UserApi
		/// </summary>
		UserApi = (Byte)'3'
	};

	/// <summary>
	/// TFtdcLinkStatusType��һ������״̬����
	/// </summary>
	public enum class EnumLinkStatusType : Byte
	{
		/// <summary>
		/// �Ѿ�����
		/// </summary>
		Connected = (Byte)'1',

		/// <summary>
		/// û������
		/// </summary>
		Disconnected = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPwdFlagType��һ������˶Ա�־����
	/// </summary>
	public enum class EnumPwdFlagType : Byte
	{
		/// <summary>
		/// ���˶�
		/// </summary>
		NoCheck = (Byte)'0',

		/// <summary>
		/// ���ĺ˶�
		/// </summary>
		BlankCheck = (Byte)'1',

		/// <summary>
		/// ���ĺ˶�
		/// </summary>
		EncryptCheck = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSecuAccTypeType��һ���ڻ��ʺ���������
	/// </summary>
	public enum class EnumSecuAccTypeType : Byte
	{
		/// <summary>
		/// �ʽ��ʺ�
		/// </summary>
		AccountID = (Byte)'1',

		/// <summary>
		/// �ʽ𿨺�
		/// </summary>
		CardID = (Byte)'2',

		/// <summary>
		/// �Ϻ��ɶ��ʺ�
		/// </summary>
		SHStockholderID = (Byte)'3',

		/// <summary>
		/// ���ڹɶ��ʺ�
		/// </summary>
		SZStockholderID = (Byte)'4'
	};

	/// <summary>
	/// TFtdcTransferStatusType��һ��ת�˽���״̬����
	/// </summary>
	public enum class EnumTransferStatusType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// ������
		/// </summary>
		Repealed = (Byte)'1'
	};

	/// <summary>
	/// TFtdcSponsorTypeType��һ����������
	/// </summary>
	public enum class EnumSponsorTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Broker = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Bank = (Byte)'1'
	};

	/// <summary>
	/// TFtdcReqRspTypeType��һ��������Ӧ�������
	/// </summary>
	public enum class EnumReqRspTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Request = (Byte)'0',

		/// <summary>
		/// ��Ӧ
		/// </summary>
		Response = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFBTUserEventTypeType��һ������ת���û��¼���������
	/// </summary>
	public enum class EnumFBTUserEventTypeType : Byte
	{
		/// <summary>
		/// ǩ��
		/// </summary>
		SignIn = (Byte)'0',

		/// <summary>
		/// ����ת�ڻ�
		/// </summary>
		FromBankToFuture = (Byte)'1',

		/// <summary>
		/// �ڻ�ת����
		/// </summary>
		FromFutureToBank = (Byte)'2',

		/// <summary>
		/// ����
		/// </summary>
		OpenAccount = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		CancelAccount = (Byte)'4',

		/// <summary>
		/// ��������˻�
		/// </summary>
		ChangeAccount = (Byte)'5',

		/// <summary>
		/// ��������ת�ڻ�
		/// </summary>
		RepealFromBankToFuture = (Byte)'6',

		/// <summary>
		/// �����ڻ�ת����
		/// </summary>
		RepealFromFutureToBank = (Byte)'7',

		/// <summary>
		/// ��ѯ�����˻�
		/// </summary>
		QueryBankAccount = (Byte)'8',

		/// <summary>
		/// ��ѯ�ڻ��˻�
		/// </summary>
		QueryFutureAccount = (Byte)'9',

		/// <summary>
		/// ǩ��
		/// </summary>
		SignOut = (Byte)'A',

		/// <summary>
		/// ��Կͬ��
		/// </summary>
		SyncKey = (Byte)'B',

		/// <summary>
		/// ����
		/// </summary>
		Other = (Byte)'Z'
	};

	/// <summary>
	/// TFtdcNotifyClassType��һ������֪ͨ��������
	/// </summary>
	public enum class EnumNotifyClassType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		NOERROR_ = (Byte)'0',

		/// <summary>
		/// ��ʾ
		/// </summary>
		Warn = (Byte)'1',

		/// <summary>
		/// ׷��
		/// </summary>
		Call = (Byte)'2',

		/// <summary>
		/// ǿƽ
		/// </summary>
		Force = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		CHUANCANG = (Byte)'4',

		/// <summary>
		/// �쳣
		/// </summary>
		Exception_ = (Byte)'5'
	};

	/// <summary>
	/// TFtdcForceCloseTypeType��һ��ǿƽ����������
	/// </summary>
	public enum class EnumForceCloseTypeType : Byte
	{
		/// <summary>
		/// �ֹ�ǿƽ
		/// </summary>
		Manual = (Byte)'0',

		/// <summary>
		/// ��һͶ���߸���ǿƽ
		/// </summary>
		Single = (Byte)'1',

		/// <summary>
		/// ����Ͷ���߸���ǿƽ
		/// </summary>
		Group = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRiskNotifyMethodType��һ������֪ͨ;������
	/// </summary>
	public enum class EnumRiskNotifyMethodType : Byte
	{
		/// <summary>
		/// ϵͳ֪ͨ
		/// </summary>
		System = (Byte)'0',

		/// <summary>
		/// ����֪ͨ
		/// </summary>
		SMS = (Byte)'1',

		/// <summary>
		/// �ʼ�֪ͨ
		/// </summary>
		EMail = (Byte)'2',

		/// <summary>
		/// �˹�֪ͨ
		/// </summary>
		Manual = (Byte)'3'
	};

	/// <summary>
	/// TFtdcRiskNotifyStatusType��һ������֪ͨ״̬����
	/// </summary>
	public enum class EnumRiskNotifyStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NotGen = (Byte)'0',

		/// <summary>
		/// ������δ����
		/// </summary>
		Generated = (Byte)'1',

		/// <summary>
		/// ����ʧ��
		/// </summary>
		SendError = (Byte)'2',

		/// <summary>
		/// �ѷ���δ����
		/// </summary>
		SendOk = (Byte)'3',

		/// <summary>
		/// �ѽ���δȷ��
		/// </summary>
		Received = (Byte)'4',

		/// <summary>
		/// ��ȷ��
		/// </summary>
		Confirmed = (Byte)'5'
	};

	/// <summary>
	/// TFtdcRiskUserEventType��һ������û������¼�����
	/// </summary>
	public enum class EnumRiskUserEventType : Byte
	{
		/// <summary>
		/// ��������
		/// </summary>
		ExportData = (Byte)'0'
	};

	/// <summary>
	/// TFtdcConditionalOrderSortTypeType��һ��������������������
	/// </summary>
	public enum class EnumConditionalOrderSortTypeType : Byte
	{
		/// <summary>
		/// ʹ�����¼�����
		/// </summary>
		LastPriceAsc = (Byte)'0',

		/// <summary>
		/// ʹ�����¼۽���
		/// </summary>
		LastPriceDesc = (Byte)'1',

		/// <summary>
		/// ʹ����������
		/// </summary>
		AskPriceAsc = (Byte)'2',

		/// <summary>
		/// ʹ�����۽���
		/// </summary>
		AskPriceDesc = (Byte)'3',

		/// <summary>
		/// ʹ���������
		/// </summary>
		BidPriceAsc = (Byte)'4',

		/// <summary>
		/// ʹ����۽���
		/// </summary>
		BidPriceDesc = (Byte)'5'
	};

	/// <summary>
	/// TFtdcSendTypeType��һ������״̬����
	/// </summary>
	public enum class EnumSendTypeType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NoSend = (Byte)'0',

		/// <summary>
		/// �ѷ���
		/// </summary>
		Sended = (Byte)'1',

		/// <summary>
		/// ������
		/// </summary>
		Generated = (Byte)'2',

		/// <summary>
		/// ����ʧ��
		/// </summary>
		SendFail = (Byte)'3',

		/// <summary>
		/// ���ճɹ�
		/// </summary>
		Success = (Byte)'4',

		/// <summary>
		/// ����ʧ��
		/// </summary>
		Fail = (Byte)'5',

		/// <summary>
		/// ȡ������
		/// </summary>
		Cancel = (Byte)'6'
	};

	/// <summary>
	/// TFtdcClientIDStatusType��һ�����ױ���״̬����
	/// </summary>
	public enum class EnumClientIDStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NoApply = (Byte)'1',

		/// <summary>
		/// ���ύ����
		/// </summary>
		Submited = (Byte)'2',

		/// <summary>
		/// �ѷ�������
		/// </summary>
		Sended = (Byte)'3',

		/// <summary>
		/// ���
		/// </summary>
		Success = (Byte)'4',

		/// <summary>
		/// �ܾ�
		/// </summary>
		Refuse = (Byte)'5',

		/// <summary>
		/// �ѳ�������
		/// </summary>
		Cancel = (Byte)'6'
	};

	/// <summary>
	/// TFtdcQuestionTypeType��һ��������Ϣ��������
	/// </summary>
	public enum class EnumQuestionTypeType : Byte
	{
		/// <summary>
		/// ��ѡ
		/// </summary>
		Radio = (Byte)'1',

		/// <summary>
		/// ��ѡ
		/// </summary>
		Option = (Byte)'2',

		/// <summary>
		/// ���
		/// </summary>
		Blank = (Byte)'3'
	};

	/// <summary>
	/// TFtdcProcessTypeType��һ�����̹�����������
	/// </summary>
	public enum class EnumProcessTypeType : Byte
	{
		/// <summary>
		/// ���뽻�ױ���
		/// </summary>
		ApplyTradingCode = (Byte)'1',

		/// <summary>
		/// �������ױ���
		/// </summary>
		CancelTradingCode = (Byte)'2',

		/// <summary>
		/// �޸������Ϣ
		/// </summary>
		ModifyIDCard = (Byte)'3',

		/// <summary>
		/// �޸�һ����Ϣ
		/// </summary>
		ModifyNoIDCard = (Byte)'4',

		/// <summary>
		/// ��������������
		/// </summary>
		ExchOpenBak = (Byte)'5',

		/// <summary>
		/// ��������������
		/// </summary>
		ExchCancelBak = (Byte)'6'
	};

	/// <summary>
	/// TFtdcBusinessTypeType��һ��ҵ����������
	/// </summary>
	public enum class EnumBusinessTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		Request = (Byte)'1',

		/// <summary>
		/// Ӧ��
		/// </summary>
		Response = (Byte)'2',

		/// <summary>
		/// ֪ͨ
		/// </summary>
		Notice = (Byte)'3'
	};

	/// <summary>
	/// TFtdcCfmmcReturnCodeType��һ��������ķ���������
	/// </summary>
	public enum class EnumCfmmcReturnCodeType : Byte
	{
		/// <summary>
		/// �ɹ�
		/// </summary>
		Success = (Byte)'0',

		/// <summary>
		/// �ÿͻ��Ѿ��������ڴ�����
		/// </summary>
		Working = (Byte)'1',

		/// <summary>
		/// ����пͻ����ϼ��ʧ��
		/// </summary>
		InfoFail = (Byte)'2',

		/// <summary>
		/// �����ʵ���Ƽ��ʧ��
		/// </summary>
		IDCardFail = (Byte)'3',

		/// <summary>
		/// ��������
		/// </summary>
		OtherFail = (Byte)'4'
	};

	/// <summary>
	/// TFtdcClientTypeType��һ���ͻ���������
	/// </summary>
	public enum class EnumClientTypeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)'0',

		/// <summary>
		/// ����
		/// </summary>
		Person = (Byte)'1',

		/// <summary>
		/// ��λ
		/// </summary>
		Company = (Byte)'2'
	};

	/// <summary>
	/// TFtdcExchangeIDTypeType��һ���������������
	/// </summary>
	public enum class EnumExchangeIDTypeType : Byte
	{
		/// <summary>
		/// �Ϻ��ڻ�������
		/// </summary>
		SHFE = (Byte)'S',

		/// <summary>
		/// ֣����Ʒ������
		/// </summary>
		CZCE = (Byte)'Z',

		/// <summary>
		/// ������Ʒ������
		/// </summary>
		DCE = (Byte)'D',

		/// <summary>
		/// �й������ڻ�������
		/// </summary>
		CFFEX = (Byte)'J'
	};

	/// <summary>
	/// TFtdcExClientIDTypeType��һ�����ױ�����������
	/// </summary>
	public enum class EnumExClientIDTypeType : Byte
	{
		/// <summary>
		/// �ױ�
		/// </summary>
		Hedge = (Byte)'1',

		/// <summary>
		/// ����
		/// </summary>
		Arbitrage = (Byte)'2',

		/// <summary>
		/// Ͷ��
		/// </summary>
		Speculation = (Byte)'3'
	};

	/// <summary>
	/// TFtdcUpdateFlagType��һ������״̬����
	/// </summary>
	public enum class EnumUpdateFlagType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		NoUpdate = (Byte)'0',

		/// <summary>
		/// ����ȫ����Ϣ�ɹ�
		/// </summary>
		Success = (Byte)'1',

		/// <summary>
		/// ����ȫ����Ϣʧ��
		/// </summary>
		Fail = (Byte)'2',

		/// <summary>
		/// ���½��ױ���ɹ�
		/// </summary>
		TCSuccess = (Byte)'3',

		/// <summary>
		/// ���½��ױ���ʧ��
		/// </summary>
		TCFail = (Byte)'4',

		/// <summary>
		/// �Ѷ���
		/// </summary>
		Cancel = (Byte)'5'
	};

	/// <summary>
	/// TFtdcApplyOperateIDType��һ�����붯������
	/// </summary>
	public enum class EnumApplyOperateIDType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		OpenInvestor = (Byte)'1',

		/// <summary>
		/// �޸������Ϣ
		/// </summary>
		ModifyIDCard = (Byte)'2',

		/// <summary>
		/// �޸�һ����Ϣ
		/// </summary>
		ModifyNoIDCard = (Byte)'3',

		/// <summary>
		/// ���뽻�ױ���
		/// </summary>
		ApplyTradingCode = (Byte)'4',

		/// <summary>
		/// �������ױ���
		/// </summary>
		CancelTradingCode = (Byte)'5',

		/// <summary>
		/// ����
		/// </summary>
		CancelInvestor = (Byte)'6'
	};

	/// <summary>
	/// TFtdcApplyStatusIDType��һ������״̬����
	/// </summary>
	public enum class EnumApplyStatusIDType : Byte
	{
		/// <summary>
		/// δ��ȫ
		/// </summary>
		NoComplete = (Byte)'1',

		/// <summary>
		/// ���ύ
		/// </summary>
		Submited = (Byte)'2',

		/// <summary>
		/// �����
		/// </summary>
		Checked = (Byte)'3',

		/// <summary>
		/// �Ѿܾ�
		/// </summary>
		Refused = (Byte)'4',

		/// <summary>
		/// ��ɾ��
		/// </summary>
		Deleted = (Byte)'5'
	};

	/// <summary>
	/// TFtdcSendMethodType��һ�����ͷ�ʽ����
	/// </summary>
	public enum class EnumSendMethodType : Byte
	{
		/// <summary>
		/// ���ӷ���
		/// </summary>
		ByAPI = (Byte)'1',

		/// <summary>
		/// �ļ�����
		/// </summary>
		ByFile = (Byte)'2'
	};

	/// <summary>
	/// TFtdcEventModeType��һ��������������
	/// </summary>
	public enum class EnumEventModeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		ADD = (Byte)'1',

		/// <summary>
		/// �޸�
		/// </summary>
		UPDATE = (Byte)'2',

		/// <summary>
		/// ɾ��
		/// </summary>
		DELETE_ = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		CHECK = (Byte)'4'
	};

	/// <summary>
	/// TFtdcUOAAutoSendType��һ��ͳһ���������Զ���������
	/// </summary>
	public enum class EnumUOAAutoSendType : Byte
	{
		/// <summary>
		/// �Զ����Ͳ�����
		/// </summary>
		ASR = (Byte)'1',

		/// <summary>
		/// �Զ����ͣ����Զ�����
		/// </summary>
		ASNR = (Byte)'2',

		/// <summary>
		/// ���Զ����ͣ��Զ�����
		/// </summary>
		NSAR = (Byte)'3',

		/// <summary>
		/// ���Զ����ͣ�Ҳ���Զ�����
		/// </summary>
		NSR = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFlowIDType��һ������ID����
	/// </summary>
	public enum class EnumFlowIDType : Byte
	{
		/// <summary>
		/// Ͷ���߶�ӦͶ����������
		/// </summary>
		InvestorGroupFlow = (Byte)'1'
	};

	/// <summary>
	/// TFtdcCheckLevelType��һ�����˼�������
	/// </summary>
	public enum class EnumCheckLevelType : Byte
	{
		/// <summary>
		/// �㼶����
		/// </summary>
		Zero = (Byte)'0',

		/// <summary>
		/// һ������
		/// </summary>
		One = (Byte)'1',

		/// <summary>
		/// ��������
		/// </summary>
		Two = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCheckStatusType��һ�����˼�������
	/// </summary>
	public enum class EnumCheckStatusType : Byte
	{
		/// <summary>
		/// δ����
		/// </summary>
		Init = (Byte)'0',

		/// <summary>
		/// ������
		/// </summary>
		Checking = (Byte)'1',

		/// <summary>
		/// �Ѹ���
		/// </summary>
		Checked = (Byte)'2',

		/// <summary>
		/// �ܾ�
		/// </summary>
		Refuse = (Byte)'3',

		/// <summary>
		/// ����
		/// </summary>
		Cancel = (Byte)'4'
	};

	/// <summary>
	/// TFtdcUsedStatusType��һ����Ч״̬����
	/// </summary>
	public enum class EnumUsedStatusType : Byte
	{
		/// <summary>
		/// δ��Ч
		/// </summary>
		Unused = (Byte)'0',

		/// <summary>
		/// ����Ч
		/// </summary>
		Used = (Byte)'1',

		/// <summary>
		/// ��Чʧ��
		/// </summary>
		Fail = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBankAcountOriginType��һ���˻���Դ����
	/// </summary>
	public enum class EnumBankAcountOriginType : Byte
	{
		/// <summary>
		/// �ֹ�¼��
		/// </summary>
		ByAccProperty = (Byte)'0',

		/// <summary>
		/// ����ת��
		/// </summary>
		ByFBTransfer = (Byte)'1'
	};

	/// <summary>
	/// TFtdcMonthBillTradeSumType��һ�����㵥�±��ɽ����ܷ�ʽ����
	/// </summary>
	public enum class EnumMonthBillTradeSumType : Byte
	{
		/// <summary>
		/// ͬ��ͬ��Լ
		/// </summary>
		ByInstrument = (Byte)'0',

		/// <summary>
		/// ͬ��ͬ��Լͬ�۸�
		/// </summary>
		ByDayInsPrc = (Byte)'1',

		/// <summary>
		/// ͬ��Լ
		/// </summary>
		ByDayIns = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFBTTradeCodeEnumType��һ�����ڽ��״���ö������
	/// </summary>
	public enum class EnumFBTTradeCodeEnumType : Byte
	{
		/// <summary>
		/// ���з�������ת�ڻ�
		/// </summary>
		BankLaunchBankToBroker_102001 = (Byte)'1',//'102001',

		/// <summary>
		/// �ڻ���������ת�ڻ�
		/// </summary>
		BrokerLaunchBankToBroker_202001 = (Byte)'2',//'202001',

		/// <summary>
		/// ���з����ڻ�ת����
		/// </summary>
		BankLaunchBrokerToBank_102002 = (Byte)'3',//'102002',

		/// <summary>
		/// �ڻ������ڻ�ת����
		/// </summary>
		BrokerLaunchBrokerToBank_202002 = (Byte)'4'//'202002'
	};

	/// <summary>
	/// TFtdcOTPTypeType��һ����̬������������
	/// </summary>
	public enum class EnumOTPTypeType : Byte
	{
		/// <summary>
		/// �޶�̬����
		/// </summary>
		NONE = (Byte)'0',

		/// <summary>
		/// ʱ������
		/// </summary>
		TOTP = (Byte)'1'
	};

	/// <summary>
	/// TFtdcOTPStatusType��һ����̬����״̬����
	/// </summary>
	public enum class EnumOTPStatusType : Byte
	{
		/// <summary>
		/// δʹ��
		/// </summary>
		Unused = (Byte)'0',

		/// <summary>
		/// ��ʹ��
		/// </summary>
		Used = (Byte)'1',

		/// <summary>
		/// ע��
		/// </summary>
		Disuse = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerUserTypeType��һ�����ù�˾�û���������
	/// </summary>
	public enum class EnumBrokerUserTypeType : Byte
	{
		/// <summary>
		/// Ͷ����
		/// </summary>
		Investor = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFutureTypeType��һ���ڻ���������
	/// </summary>
	public enum class EnumFutureTypeType : Byte
	{
		/// <summary>
		/// ��Ʒ�ڻ�
		/// </summary>
		Commodity = (Byte)'1',

		/// <summary>
		/// �����ڻ�
		/// </summary>
		Financial = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundEventTypeType��һ���ʽ���������������
	/// </summary>
	public enum class EnumFundEventTypeType : Byte
	{
		/// <summary>
		/// ת���޶�
		/// </summary>
		Restriction = (Byte)'0',

		/// <summary>
		/// ����ת���޶�
		/// </summary>
		TodayRestriction = (Byte)'1',

		/// <summary>
		/// ������ˮ
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// �ʽ𶳽�
		/// </summary>
		Credit = (Byte)'3',

		/// <summary>
		/// Ͷ���߿����ʽ����
		/// </summary>
		InvestorWithdrawAlm = (Byte)'4',

		/// <summary>
		/// ���������ʻ�ת���޶�
		/// </summary>
		BankRestriction = (Byte)'5'
	};

	/// <summary>
	/// TFtdcAccountSourceTypeType��һ���ʽ��˻���Դ����
	/// </summary>
	public enum class EnumAccountSourceTypeType : Byte
	{
		/// <summary>
		/// ����ͬ��
		/// </summary>
		FBTransfer = (Byte)'0',

		/// <summary>
		/// �ֹ�¼��
		/// </summary>
		ManualEntry = (Byte)'1'
	};

	/// <summary>
	/// TFtdcCodeSourceTypeType��һ�����ױ�����Դ����
	/// </summary>
	public enum class EnumCodeSourceTypeType : Byte
	{
		/// <summary>
		/// ͳһ����
		/// </summary>
		UnifyAccount = (Byte)'0',

		/// <summary>
		/// �ֹ�¼��
		/// </summary>
		ManualEntry = (Byte)'1'
	};

	/// <summary>
	/// TFtdcUserRangeType��һ������Ա��Χ����
	/// </summary>
	public enum class EnumUserRangeType : Byte
	{
		/// <summary>
		/// ����
		/// </summary>
		All = (Byte)'0',

		/// <summary>
		/// ��һ����Ա
		/// </summary>
		Single = (Byte)'1'
	};

	/// <summary>
	/// TFtdcByGroupType��һ������ͳ�Ʊ��ͻ�ͳ�Ʒ�ʽ����
	/// </summary>
	public enum class EnumByGroupType : Byte
	{
		/// <summary>
		/// ��Ͷ����ͳ��
		/// </summary>
		Investor = (Byte)'2',

		/// <summary>
		/// ����ͳ��
		/// </summary>
		Group = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTradeSumStatModeType��һ������ͳ�Ʊ���Χͳ�Ʒ�ʽ����
	/// </summary>
	public enum class EnumTradeSumStatModeType : Byte
	{
		/// <summary>
		/// ����Լͳ��
		/// </summary>
		Instrument = (Byte)'1',

		/// <summary>
		/// ����Ʒͳ��
		/// </summary>
		Product = (Byte)'2',

		/// <summary>
		/// ��������ͳ��
		/// </summary>
		Exchange = (Byte)'3'
	};

	/// <summary>
	/// 
	/// </summary>
	public enum class EnumBoolType:int
	{
		/// <summary>
		/// 
		/// </summary>
		No=0,
		/// <summary>
		/// 
		/// </summary>
		Yes=1
	};
#pragma endregion type_enum

	/// <summary>
	/// ��Ϣ�ַ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcDisseminationField_M
	{
		/// <summary>
		/// ����ϵ�к�
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// ���к�
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// �û���¼����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqUserLoginField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �û��˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ UserProductInfo;
		/// <summary>
		/// �ӿڶ˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ InterfaceProductInfo;
		/// <summary>
		/// Э����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ProtocolInfo;
		/// <summary>
		/// Mac��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MacAddress;
		/// <summary>
		/// ��̬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ OneTimePassword;
		/// <summary>
		/// �ն�IP��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ ClientIPAddress;
	};

	/// <summary>
	/// �û���¼Ӧ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspUserLoginField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ��¼�ɹ�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LoginTime;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ SystemName;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��󱨵�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ MaxOrderRef;
		/// <summary>
		/// ������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SHFETime;
		/// <summary>
		/// ������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ DCETime;
		/// <summary>
		/// ֣����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CZCETime;
		/// <summary>
		/// �н���ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ FFEXTime;
	};

	/// <summary>
	/// �û��ǳ�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcUserLogoutField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ǿ�ƽ���Ա�˳�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcForceUserLogoutField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ����ת�ʱ���ͷ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferHeaderField_M
	{
		/// <summary>
		/// �汾�ţ�������1.0
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ Version;
		/// <summary>
		/// ���״��룬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// �������ڣ������ʽ��yyyymmdd
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ�䣬�����ʽ��hhmmss
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ�ţ�N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeSerial;
		/// <summary>
		/// �ڻ���˾���룬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ FutureID;
		/// <summary>
		/// ���д��룬���ݲ�ѯ���еõ�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ��룬���ݲ�ѯ���еõ�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
		/// <summary>
		/// ����Ա��N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// �����豸���ͣ�N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// ��¼����N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ RecordNum;
		/// <summary>
		/// �Ự��ţ�N/A
		/// </summary>
		int SessionID;
		/// <summary>
		/// �����ţ�N/A
		/// </summary>
		int RequestID;
	};

	/// <summary>
	/// �����ʽ�ת�ڻ�����TradeCode=202001
	/// </summary>
	[StructLayout(LayoutKind::Sequential,Pack = 1)]
	public ref struct CThostFtdcTransferBankToFutureReqField_M
	{
		/// <summary>
		/// �ڻ��ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// �����־
		/// </summary>
		System::Byte FuturePwdFlag;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ FutureAccPwd;
		/// <summary>
		/// ת�˽��
		/// </summary>
		System::Double TradeAmt;
		/// <summary>
		/// �ͻ�������
		/// </summary>
		System::Double CustFee;
		/// <summary>
		/// ���֣�RMB-����� USD-��Բ HKD-��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// �����ʽ�ת�ڻ�������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferBankToFutureRspField_M
	{
		/// <summary>
		/// ��Ӧ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ RetCode;
		/// <summary>
		/// ��Ӧ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ RetInfo;
		/// <summary>
		/// �ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// Ӧ�տͻ�������
		/// </summary>
		double CustFee;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// �ڻ��ʽ�ת��������TradeCode=202002
	/// </summary>
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CThostFtdcTransferFutureToBankReqField_M
	{
		/// <summary>
		/// �ڻ��ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// �����־
		/// </summary>
		System::Byte FuturePwdFlag;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ FutureAccPwd;
		/// <summary>
		/// ת�˽��
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// �ͻ�������
		/// </summary>
		double CustFee;
		/// <summary>
		/// ���֣�RMB-����� USD-��Բ HKD-��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// �ڻ��ʽ�ת����������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferFutureToBankRspField_M
	{
		/// <summary>
		/// ��Ӧ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ RetCode;
		/// <summary>
		/// ��Ӧ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ RetInfo;
		/// <summary>
		/// �ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// Ӧ�տͻ�������
		/// </summary>
		double CustFee;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// ��ѯ�����ʽ�����TradeCode=204002
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferQryBankReqField_M
	{
		/// <summary>
		/// �ڻ��ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// �����־
		/// </summary>
		System::Byte FuturePwdFlag;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ FutureAccPwd;
		/// <summary>
		/// ���֣�RMB-����� USD-��Բ HKD-��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// ��ѯ�����ʽ�������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferQryBankRspField_M
	{
		/// <summary>
		/// ��Ӧ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ RetCode;
		/// <summary>
		/// ��Ӧ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ RetInfo;
		/// <summary>
		/// �ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
		/// <summary>
		/// �������
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// ���п������
		/// </summary>
		double UseAmt;
		/// <summary>
		/// ���п�ȡ���
		/// </summary>
		double FetchAmt;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
	};

	/// <summary>
	/// ��ѯ���н�����ϸ����TradeCode=204999
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferQryDetailReqField_M
	{
		/// <summary>
		/// �ڻ��ʽ��˻�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ FutureAccount;
	};

	/// <summary>
	/// ��ѯ���н�����ϸ������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferQryDetailRspField_M
	{
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ���״���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// �ڻ���ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// �ڻ���˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ FutureID;
		/// <summary>
		/// �ʽ��ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		System::String^ FutureAccount;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		int BankSerial;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
		/// <summary>
		/// �����˺�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CertCode;
		/// <summary>
		/// ���Ҵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyCode;
		/// <summary>
		/// �������
		/// </summary>
		double TxAmount;
		/// <summary>
		/// ��Ч��־
		/// </summary>
		System::Byte Flag;//EnumTransferValidFlagType
	};

	/// <summary>
	/// ��Ӧ��Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspInfoField_M
	{
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CThostFtdcExchangeField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeName;
		/// <summary>
		/// ����������
		/// </summary>
		System::Byte ExchangeProperty;//EnumExchangePropertyType
	};

	/// <summary>
	/// ��Ʒ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcProductField_M
	{
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ProductID;
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ ProductName;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		System::Byte ProductClass;//EnumProductClassType
		/// <summary>
		/// ��Լ��������
		/// </summary>
		int VolumeMultiple;
		/// <summary>
		/// ��С�䶯��λ
		/// </summary>
		double PriceTick;
		/// <summary>
		/// �м۵�����µ���
		/// </summary>
		int MaxMarketOrderVolume;
		/// <summary>
		/// �м۵���С�µ���
		/// </summary>
		int MinMarketOrderVolume;
		/// <summary>
		/// �޼۵�����µ���
		/// </summary>
		int MaxLimitOrderVolume;
		/// <summary>
		/// �޼۵���С�µ���
		/// </summary>
		int MinLimitOrderVolume;
		/// <summary>
		/// �ֲ�����
		/// </summary>
		Byte PositionType;//EnumPositionTypeType 
		/// <summary>
		/// �ֲ���������
		/// </summary>
		Byte PositionDateType;//EnumPositionDateTypeType
	};

	/// <summary>
	/// ��Լ
	/// </summary>
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CThostFtdcInstrumentField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ InstrumentName;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ProductID;
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		System::Byte ProductClass;//EnumProductClassType
		/// <summary>
		/// �������
		/// </summary>
		int DeliveryYear;
		/// <summary>
		/// ������
		/// </summary>
		int DeliveryMonth;
		/// <summary>
		/// �м۵�����µ���
		/// </summary>
		int MaxMarketOrderVolume;
		/// <summary>
		/// �м۵���С�µ���
		/// </summary>
		int MinMarketOrderVolume;
		/// <summary>
		/// �޼۵�����µ���
		/// </summary>
		int MaxLimitOrderVolume;
		/// <summary>
		/// �޼۵���С�µ���
		/// </summary>
		int MinLimitOrderVolume;
		/// <summary>
		/// ��Լ��������
		/// </summary>
		int VolumeMultiple;
		/// <summary>
		/// ��С�䶯��λ
		/// </summary>
		double PriceTick;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CreateDate;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ OpenDate;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExpireDate;
		/// <summary>
		/// ��ʼ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ StartDelivDate;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ EndDelivDate;
		/// <summary>
		/// ��Լ��������״̬
		/// </summary>
		Byte InstLifePhase;
		/// <summary>
		/// ��ǰ�Ƿ���
		/// </summary>
		int IsTrading;
		/// <summary>
		/// �ֲ�����
		/// </summary>
		Byte PositionType;//EnumPositionTypeType 
		/// <summary>
		/// �ֲ���������
		/// </summary>
		Byte PositionDateType;//EnumPositionDateTypeType 
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double LongMarginRatio;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double ShortMarginRatio;
	};

	/// <summary>
	/// ���͹�˾
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���͹�˾���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ BrokerAbbr;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ BrokerName;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// ����������Ա
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTraderField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ����
		/// </summary>
		int InstallCount;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// Ͷ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorField_M
	{
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorGroupID;
		/// <summary>
		/// Ͷ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ InvestorName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdentifiedCardType;//EnumIdCardTypeType 
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
		/// <summary>
		/// ��ϵ�绰
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// ͨѶ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ OpenDate;
		/// <summary>
		/// �ֻ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Mobile;
	};

	/// <summary>
	/// ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingCodeField_M
	{
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
		/// <summary>
		/// ���ױ�������
		/// </summary>
		Byte ClientIDType;//EnumClientIDTypeType 
	};

	/// <summary>
	/// ��Ա����;��͹�˾������ձ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcPartBrokerField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// �����û�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSuperUserField_M
	{
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ UserName;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// �����û�����Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSuperUserFunctionField_M
	{
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ���ܴ���
		/// </summary>
		Byte FunctionCode;
	};

	/// <summary>
	/// Ͷ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorGroupField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorGroupID;
		/// <summary>
		/// Ͷ���߷�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ InvestorGroupName;
	};

	/// <summary>
	/// �ʽ��˻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingAccountField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ϴ���Ѻ���
		/// </summary>
		double PreMortgage;
		/// <summary>
		/// �ϴ����ö��
		/// </summary>
		double PreCredit;
		/// <summary>
		/// �ϴδ���
		/// </summary>
		double PreDeposit;
		/// <summary>
		/// �ϴν���׼����
		/// </summary>
		double PreBalance;
		/// <summary>
		/// �ϴ�ռ�õı�֤��
		/// </summary>
		double PreMargin;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		double InterestBase;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		double Interest;
		/// <summary>
		/// �����
		/// </summary>
		double Deposit;
		/// <summary>
		/// ������
		/// </summary>
		double Withdraw;
		/// <summary>
		/// ����ı�֤��
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// ������ʽ�
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// �����������
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// ��ǰ��֤���ܶ�
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// �ʽ���
		/// </summary>
		double CashIn;
		/// <summary>
		/// ������
		/// </summary>
		double Commission;
		/// <summary>
		/// ƽ��ӯ��
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// �ֲ�ӯ��
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// �ڻ�����׼����
		/// </summary>
		double Balance;
		/// <summary>
		/// �����ʽ�
		/// </summary>
		double Available;
		/// <summary>
		/// ��ȡ�ʽ�
		/// </summary>
		double WithdrawQuota;
		/// <summary>
		/// ����׼����
		/// </summary>
		double Reserve;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���ö��
		/// </summary>
		double Credit;
		/// <summary>
		/// ��Ѻ���
		/// </summary>
		double Mortgage;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// Ͷ���߽��֤��
		/// </summary>
		double DeliveryMargin;
		/// <summary>
		/// ���������֤��
		/// </summary>
		double ExchangeDeliveryMargin;
	};

	/// <summary>
	/// Ͷ���ֲ߳�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorPositionField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �ֲֶ�շ���
		/// </summary>
		Byte PosiDirection;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		Byte HedgeFlag;
		/// <summary>
		/// �ֲ�����
		/// </summary>
		Byte PositionDate;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int YdPosition;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int Position;
		/// <summary>
		/// ��ͷ����
		/// </summary>
		int LongFrozen;
		/// <summary>
		/// ��ͷ����
		/// </summary>
		int ShortFrozen;
		/// <summary>
		/// ���ֶ�����
		/// </summary>
		double LongFrozenAmount;
		/// <summary>
		/// ���ֶ�����
		/// </summary>
		double ShortFrozenAmount;
		/// <summary>
		/// ������
		/// </summary>
		int OpenVolume;
		/// <summary>
		/// ƽ����
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// ���ֽ��
		/// </summary>
		double OpenAmount;
		/// <summary>
		/// ƽ�ֽ��
		/// </summary>
		double CloseAmount;
		/// <summary>
		/// �ֲֳɱ�
		/// </summary>
		double PositionCost;
		/// <summary>
		/// �ϴ�ռ�õı�֤��
		/// </summary>
		double PreMargin;
		/// <summary>
		/// ռ�õı�֤��
		/// </summary>
		double UseMargin;
		/// <summary>
		/// ����ı�֤��
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// ������ʽ�
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// �����������
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// �ʽ���
		/// </summary>
		double CashIn;
		/// <summary>
		/// ������
		/// </summary>
		double Commission;
		/// <summary>
		/// ƽ��ӯ��
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// �ֲ�ӯ��
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// �ϴν����
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// ���ν����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���ֳɱ�
		/// </summary>
		double OpenCost;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// ��ϳɽ��γɵĳֲ�
		/// </summary>
		int CombPosition;
		/// <summary>
		/// ��϶�ͷ����
		/// </summary>
		int CombLongFrozen;
		/// <summary>
		/// ��Ͽ�ͷ����
		/// </summary>
		int CombShortFrozen;
		/// <summary>
		/// ���ն���ƽ��ӯ��
		/// </summary>
		double CloseProfitByDate;
		/// <summary>
		/// ��ʶԳ�ƽ��ӯ��
		/// </summary>
		double CloseProfitByTrade;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int TodayPosition;
		/// <summary>
		/// ��֤����
		/// </summary>
		double MarginRateByMoney;
		/// <summary>
		/// ��֤����(������)
		/// </summary>
		double MarginRateByVolume;
	};

	/// <summary>
	/// ��Լ��֤����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInstrumentMarginRateField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// �Ƿ���Խ�������ȡ
		/// </summary>
		Int32 IsRelative;//EnumBoolType
	};

	/// <summary>
	/// ��Լ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInstrumentCommissionRateField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		double OpenRatioByMoney;
		/// <summary>
		/// ����������
		/// </summary>
		double OpenRatioByVolume;
		/// <summary>
		/// ƽ����������
		/// </summary>
		double CloseRatioByMoney;
		/// <summary>
		/// ƽ��������
		/// </summary>
		double CloseRatioByVolume;
		/// <summary>
		/// ƽ����������
		/// </summary>
		double CloseTodayRatioByMoney;
		/// <summary>
		/// ƽ��������
		/// </summary>
		double CloseTodayRatioByVolume;
	};

	/// <summary>
	/// �������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcDepthMarketDataField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ���¼�
		/// </summary>
		double LastPrice;
		/// <summary>
		/// �ϴν����
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// ������
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// ��ֲ���
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// ����
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// ��߼�
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// ��ͼ�
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// �ɽ����
		/// </summary>
		double Turnover;
		/// <summary>
		/// �ֲ���
		/// </summary>
		double OpenInterest;
		/// <summary>
		/// ������
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// ���ν����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double PreDelta;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double CurrDelta;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����޸ĺ���
		/// </summary>
		int UpdateMillisec;
		/// <summary>
		/// �����һ
		/// </summary>
		double BidPrice1;
		/// <summary>
		/// ������һ
		/// </summary>
		int BidVolume1;
		/// <summary>
		/// ������һ
		/// </summary>
		double AskPrice1;
		/// <summary>
		/// ������һ
		/// </summary>
		int AskVolume1;
		/// <summary>
		/// ����۶�
		/// </summary>
		double BidPrice2;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume2;
		/// <summary>
		/// �����۶�
		/// </summary>
		double AskPrice2;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume2;
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice3;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume3;
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice3;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume3;
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice4;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume4;
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice4;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume4;
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice5;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume5;
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice5;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume5;
		/// <summary>
		/// ���վ���
		/// </summary>
		double AveragePrice;
	};

	/// <summary>
	/// Ͷ���ߺ�Լ����Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInstrumentTradingRightField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����Ȩ��
		/// </summary>
		System::Byte TradingRight;
	};

	/// <summary>
	/// ���͹�˾�û�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerUserField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ UserName;
		/// <summary>
		/// �û�����
		/// </summary>
		Byte UserType;//EnumUserTypeType 
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
		/// <summary>
		/// �Ƿ�ʹ������
		/// </summary>
		int IsUsingOTP;
	};

	/// <summary>
	/// ���͹�˾�û�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerUserPasswordField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
	};

	/// <summary>
	/// ���͹�˾�û�����Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerUserFunctionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ���͹�˾���ܴ���
		/// </summary>
		Byte BrokerFunctionCode;
	};

	/// <summary>
	/// ����������Ա���̻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTraderOfferField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// ����������Ա����״̬
		/// </summary>
		System::Byte TraderConnectStatus;
		/// <summary>
		/// �����������������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectRequestDate;
		/// <summary>
		/// �������������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectRequestTime;
		/// <summary>
		/// �ϴα�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportDate;
		/// <summary>
		/// �ϴα���ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportTime;
		/// <summary>
		/// �����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectDate;
		/// <summary>
		/// �������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectTime;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ StartDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ StartTime;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// Ͷ���߽�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSettlementInfoField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		System::String^ Content;
	};

	/// <summary>
	/// ��Լ��֤���ʵ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInstrumentMarginRateAdjustField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// �Ƿ���Խ�������ȡ
		/// </summary>
		int IsRelative;
	};

	/// <summary>
	/// ��������֤����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeMarginRateField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double ShortMarginRatioByVolume;
	};

	/// <summary>
	/// ��������֤���ʵ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeMarginRateAdjustField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ���潻����Ͷ���߶�ͷ��֤����
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// ���潻����Ͷ���߶�ͷ��֤���
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// ���潻����Ͷ���߿�ͷ��֤����
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// ���潻����Ͷ���߿�ͷ��֤���
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// ��������ͷ��֤����
		/// </summary>
		double ExchLongMarginRatioByMoney;
		/// <summary>
		/// ��������ͷ��֤���
		/// </summary>
		double ExchLongMarginRatioByVolume;
		/// <summary>
		/// ��������ͷ��֤����
		/// </summary>
		double ExchShortMarginRatioByMoney;
		/// <summary>
		/// ��������ͷ��֤���
		/// </summary>
		double ExchShortMarginRatioByVolume;
		/// <summary>
		/// �����潻����Ͷ���߶�ͷ��֤����
		/// </summary>
		double NoLongMarginRatioByMoney;
		/// <summary>
		/// �����潻����Ͷ���߶�ͷ��֤���
		/// </summary>
		double NoLongMarginRatioByVolume;
		/// <summary>
		/// �����潻����Ͷ���߿�ͷ��֤����
		/// </summary>
		double NoShortMarginRatioByMoney;
		/// <summary>
		/// �����潻����Ͷ���߿�ͷ��֤���
		/// </summary>
		double NoShortMarginRatioByVolume;
	};

	/// <summary>
	/// ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSettlementRefField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
	};

	/// <summary>
	/// ��ǰʱ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcCurrentTimeField_M
	{
		/// <summary>
		/// ��ǰ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CurrDate;
		/// <summary>
		/// ��ǰʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CurrTime;
		/// <summary>
		/// ��ǰʱ�䣨���룩
		/// </summary>
		int CurrMillisec;
	};

	/// <summary>
	/// ͨѶ�׶�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcCommPhaseField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ͨѶʱ�α��
		/// </summary>
		short CommPhaseNo;
	};

	/// <summary>
	/// ��¼��Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcLoginInfoField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��¼����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LoginDate;
		/// <summary>
		/// ��¼ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LoginTime;
		/// <summary>
		/// IP��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ IPAddress;
		/// <summary>
		/// �û��˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ UserProductInfo;
		/// <summary>
		/// �ӿڶ˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ InterfaceProductInfo;
		/// <summary>
		/// Э����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ProtocolInfo;
		/// <summary>
		/// ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ SystemName;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��󱨵�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ MaxOrderRef;
		/// <summary>
		/// ������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SHFETime;
		/// <summary>
		/// ������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ DCETime;
		/// <summary>
		/// ֣����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CZCETime;
		/// <summary>
		/// �н���ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ FFEXTime;
		/// <summary>
		/// Mac��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MacAddress;
		/// <summary>
		/// ��̬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ OneTimePassword;
	};

	/// <summary>
	/// ��¼��Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcLogoutAllField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ SystemName;
	};

	/// <summary>
	/// ǰ��״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcFrontStatusField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �ϴα�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportDate;
		/// <summary>
		/// �ϴα���ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportTime;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// �û�������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcUserPasswordUpdateField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ԭ���Ŀ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ OldPassword;
		/// <summary>
		/// �µĿ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ NewPassword;
	};

	/// <summary>
	/// ���뱨��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInputOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �����۸�����
		/// </summary>
		System::Byte OrderPriceType;//EnumOrderPriceTypeType 
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_0;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_1;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_2;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_3;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_4;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_0;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_1;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_2;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_3;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_4;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// �û�ǿ����־
		/// </summary>
		int UserForceClose;
		///��������־
	    int IsSwapOrder;
		
	};

	/// <summary>
	/// ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �����۸�����
		/// </summary>
		System::Byte OrderPriceType;//EnumOrderPriceTypeType 
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_0;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_1;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_2;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_3;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_4;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_0;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_1;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_2;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_3;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_4;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �����ύ״̬
		/// </summary>
		System::Byte OrderSubmitStatus;
		/// <summary>
		/// ������ʾ���
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������Դ
		/// </summary>
		System::Byte OrderSource;
		/// <summary>
		/// ����״̬
		/// </summary>
		System::Byte OrderStatus;
		/// <summary>
		/// ��������
		/// </summary>
		Byte OrderType;//EnumOrderTypeType
		/// <summary>
		/// ��ɽ�����
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// ʣ������
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertDate;
		/// <summary>
		/// ί��ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActiveTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SuspendTime;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CancelTime;
		/// <summary>
		/// ����޸Ľ���������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ ActiveTraderID;
		/// <summary>
		/// �����Ա���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClearingPartID;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// �û��˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ UserProductInfo;
		/// <summary>
		/// ״̬��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ StatusMsg;
		/// <summary>
		/// �û�ǿ����־
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// �����û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ ActiveUserID;
		/// <summary>
		/// ���͹�˾�������
		/// </summary>
		int BrokerOrderSeq;
		/// <summary>
		/// ��ر���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ RelativeOrderSysID;
		///֣�����ɽ�����
		int	ZCETotalTradedVolume;
		///��������־
		int IsSwapOrder;
	};

	/// <summary>
	/// ����������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeOrderField_M
	{
		/// <summary>
		/// �����۸�����
		/// </summary>
		Byte OrderPriceType;//EnumOrderPriceTypeType 
		/// <summary>
		/// ��������
		/// </summary>
		Byte Direction;//EnumDirectionType 
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombOffsetFlag;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombHedgeFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �����ύ״̬
		/// </summary>
		System::Byte OrderSubmitStatus;
		/// <summary>
		/// ������ʾ���
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������Դ
		/// </summary>
		System::Byte OrderSource;
		/// <summary>
		/// ����״̬
		/// </summary>
		System::Byte OrderStatus;
		/// <summary>
		/// ��������
		/// </summary>
		Byte OrderType;//EnumOrderTypeType 
		/// <summary>
		/// ��ɽ�����
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// ʣ������
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertDate;
		/// <summary>
		/// ί��ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActiveTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SuspendTime;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CancelTime;
		/// <summary>
		/// ����޸Ľ���������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ ActiveTraderID;
		/// <summary>
		/// �����Ա���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClearingPartID;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// ��������������ʧ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeOrderInsertErrorField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ���뱨������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInputOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������־
		/// </summary>
		System::Byte ActionFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// �����仯
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������־
		/// </summary>
		System::Byte ActionFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// �����仯
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionTime;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �������ر��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ActionLocalID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ��������״̬
		/// </summary>
		System::Byte OrderActionStatus;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ״̬��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ StatusMsg;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��������������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeOrderActionField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������־
		/// </summary>
		System::Byte ActionFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// �����仯
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionTime;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �������ر��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ActionLocalID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ��������״̬
		/// </summary>
		System::Byte OrderActionStatus;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��������������ʧ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeOrderActionErrorField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �������ر��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ActionLocalID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// �������ɽ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeTradeField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ɽ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TradeID;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ���׽�ɫ
		/// </summary>
		System::Byte TradingRole;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ��ƽ��־
		/// </summary>
		System::Byte OffsetFlag;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double Price;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// �ɽ�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// �ɽ�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// �ɽ�����
		/// </summary>
		Byte TradeType;//EnumTradeTypeType
		/// <summary>
		/// �ɽ�����Դ
		/// </summary>
		Byte PriceSource;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �����Ա���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClearingPartID;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// �ɽ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ɽ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TradeID;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ���׽�ɫ
		/// </summary>
		System::Byte TradingRole;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ��ƽ��־
		/// </summary>
		System::Byte OffsetFlag;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double Price;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// �ɽ�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// �ɽ�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// �ɽ�����
		/// </summary>
		Byte TradeType;//EnumTradeTypeType
		/// <summary>
		/// �ɽ�����Դ
		/// </summary>
		Byte PriceSource;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �����Ա���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClearingPartID;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���͹�˾�������
		/// </summary>
		int BrokerOrderSeq;
	};

	/// <summary>
	/// �û��Ự
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcUserSessionField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��¼����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LoginDate;
		/// <summary>
		/// ��¼ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LoginTime;
		/// <summary>
		/// IP��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ IPAddress;
		/// <summary>
		/// �û��˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ UserProductInfo;
		/// <summary>
		/// �ӿڶ˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ InterfaceProductInfo;
		/// <summary>
		/// Э����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ProtocolInfo;
		/// <summary>
		/// Mac��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MacAddress;
	};

	/// <summary>
	/// ��ѯ��󱨵�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQueryMaxOrderVolumeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��ƽ��־
		/// </summary>
		System::Byte OffsetFlag;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// �������������
		/// </summary>
		int MaxVolume;
	};

	/// <summary>
	/// Ͷ���߽�����ȷ����Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSettlementInfoConfirmField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ȷ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConfirmDate;
		/// <summary>
		/// ȷ��ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConfirmTime;
	};

	/// <summary>
	/// �����ͬ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncDepositField_M
	{
		/// <summary>
		/// �������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		System::String^ DepositSeqNo;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �����
		/// </summary>
		double Deposit;
		/// <summary>
		/// �Ƿ�ǿ�ƽ���
		/// </summary>
		int IsForce;
	};

	/// <summary>
	/// ���͹�˾ͬ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerSyncField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ����ͬ���е�Ͷ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInvestorField_M
	{
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorGroupID;
		/// <summary>
		/// Ͷ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ InvestorName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdentifiedCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
		/// <summary>
		/// ��ϵ�绰
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// ͨѶ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ OpenDate;
		/// <summary>
		/// �ֻ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Mobile;
		///��������ģ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^	CommModelID;
		///��֤����ģ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^	MarginModelID;
	};

	/// <summary>
	/// ����ͬ���еĽ��״���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingTradingCodeField_M
	{
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
		/// <summary>
		/// ���ױ�������
		/// </summary>
		Byte ClientIDType;//EnumClientIDTypeType
	};

	/// <summary>
	/// ����ͬ���е�Ͷ���߷���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInvestorGroupField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorGroupID;
		/// <summary>
		/// Ͷ���߷�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ InvestorGroupName;
	};

	/// <summary>
	/// ����ͬ���еĽ����˺�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingTradingAccountField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ϴ���Ѻ���
		/// </summary>
		double PreMortgage;
		/// <summary>
		/// �ϴ����ö��
		/// </summary>
		double PreCredit;
		/// <summary>
		/// �ϴδ���
		/// </summary>
		double PreDeposit;
		/// <summary>
		/// �ϴν���׼����
		/// </summary>
		double PreBalance;
		/// <summary>
		/// �ϴ�ռ�õı�֤��
		/// </summary>
		double PreMargin;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		double InterestBase;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		double Interest;
		/// <summary>
		/// �����
		/// </summary>
		double Deposit;
		/// <summary>
		/// ������
		/// </summary>
		double Withdraw;
		/// <summary>
		/// ����ı�֤��
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// ������ʽ�
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// �����������
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// ��ǰ��֤���ܶ�
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// �ʽ���
		/// </summary>
		double CashIn;
		/// <summary>
		/// ������
		/// </summary>
		double Commission;
		/// <summary>
		/// ƽ��ӯ��
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// �ֲ�ӯ��
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// �ڻ�����׼����
		/// </summary>
		double Balance;
		/// <summary>
		/// �����ʽ�
		/// </summary>
		double Available;
		/// <summary>
		/// ��ȡ�ʽ�
		/// </summary>
		double WithdrawQuota;
		/// <summary>
		/// ����׼����
		/// </summary>
		double Reserve;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���ö��
		/// </summary>
		double Credit;
		/// <summary>
		/// ��Ѻ���
		/// </summary>
		double Mortgage;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// Ͷ���߽��֤��
		/// </summary>
		double DeliveryMargin;
		/// <summary>
		/// ���������֤��
		/// </summary>
		double ExchangeDeliveryMargin;
	};

	/// <summary>
	/// ����ͬ���е�Ͷ���ֲ߳�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInvestorPositionField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �ֲֶ�շ���
		/// </summary>
		Byte PosiDirection;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// �ֲ�����
		/// </summary>
		Byte PositionDate;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int YdPosition;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int Position;
		/// <summary>
		/// ��ͷ����
		/// </summary>
		int LongFrozen;
		/// <summary>
		/// ��ͷ����
		/// </summary>
		int ShortFrozen;
		/// <summary>
		/// ���ֶ�����
		/// </summary>
		double LongFrozenAmount;
		/// <summary>
		/// ���ֶ�����
		/// </summary>
		double ShortFrozenAmount;
		/// <summary>
		/// ������
		/// </summary>
		int OpenVolume;
		/// <summary>
		/// ƽ����
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// ���ֽ��
		/// </summary>
		double OpenAmount;
		/// <summary>
		/// ƽ�ֽ��
		/// </summary>
		double CloseAmount;
		/// <summary>
		/// �ֲֳɱ�
		/// </summary>
		double PositionCost;
		/// <summary>
		/// �ϴ�ռ�õı�֤��
		/// </summary>
		double PreMargin;
		/// <summary>
		/// ռ�õı�֤��
		/// </summary>
		double UseMargin;
		/// <summary>
		/// ����ı�֤��
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// ������ʽ�
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// �����������
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// �ʽ���
		/// </summary>
		double CashIn;
		/// <summary>
		/// ������
		/// </summary>
		double Commission;
		/// <summary>
		/// ƽ��ӯ��
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// �ֲ�ӯ��
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// �ϴν����
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// ���ν����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���ֳɱ�
		/// </summary>
		double OpenCost;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// ��ϳɽ��γɵĳֲ�
		/// </summary>
		int CombPosition;
		/// <summary>
		/// ��϶�ͷ����
		/// </summary>
		int CombLongFrozen;
		/// <summary>
		/// ��Ͽ�ͷ����
		/// </summary>
		int CombShortFrozen;
		/// <summary>
		/// ���ն���ƽ��ӯ��
		/// </summary>
		double CloseProfitByDate;
		/// <summary>
		/// ��ʶԳ�ƽ��ӯ��
		/// </summary>
		double CloseProfitByTrade;
		/// <summary>
		/// ���ճֲ�
		/// </summary>
		int TodayPosition;
		/// <summary>
		/// ��֤����
		/// </summary>
		double MarginRateByMoney;
		/// <summary>
		/// ��֤����(������)
		/// </summary>
		double MarginRateByVolume;
	};

	/// <summary>
	/// ����ͬ���еĺ�Լ��֤����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInstrumentMarginRateField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// ��ͷ��֤����
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// ��ͷ��֤���
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// �Ƿ���Խ�������ȡ
		/// </summary>
		int IsRelative;
	};

	/// <summary>
	/// ����ͬ���еĺ�Լ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInstrumentCommissionRateField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		double OpenRatioByMoney;
		/// <summary>
		/// ����������
		/// </summary>
		double OpenRatioByVolume;
		/// <summary>
		/// ƽ����������
		/// </summary>
		double CloseRatioByMoney;
		/// <summary>
		/// ƽ��������
		/// </summary>
		double CloseRatioByVolume;
		/// <summary>
		/// ƽ����������
		/// </summary>
		double CloseTodayRatioByMoney;
		/// <summary>
		/// ƽ��������
		/// </summary>
		double CloseTodayRatioByVolume;
	};

	/// <summary>
	/// ����ͬ���еĺ�Լ����Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncingInstrumentTradingRightField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����Ȩ��
		/// </summary>
		System::Byte TradingRight;
	};

	/// <summary>
	/// ��ѯ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ��ʼʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTimeStart;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTimeEnd;
	};

	/// <summary>
	/// ��ѯ�ɽ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTradeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ɽ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TradeID;
		/// <summary>
		/// ��ʼʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTimeStart;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTimeEnd;
	};

	/// <summary>
	/// ��ѯͶ���ֲ߳�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInvestorPositionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��ѯ�ʽ��˻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTradingAccountField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ��ѯͶ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInvestorField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ��ѯ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTradingCodeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ���ױ�������
		/// </summary>
		Byte ClientIDType;//EnumClientIDTypeType
	};

	/// <summary>
	/// ��ѯ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInvestorGroupField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ��ѯ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInstrumentMarginRateField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
	};

	/// <summary>
	/// ��ѯ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInstrumentCommissionRateField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��ѯ���ױ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInstrumentTradingRightField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��ѯ���͹�˾
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ��ѯ����Ա
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTraderField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
	};

	/// <summary>
	/// ��ѯ���͹�˾��Ա����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryPartBrokerField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
	};

	/// <summary>
	/// ��ѯ�����û�����Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySuperUserFunctionField_M
	{
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��ѯ�û��Ự
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryUserSessionField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��ѯǰ��״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryFrontStatusField_M
	{
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
	};

	/// <summary>
	/// ��ѯ����������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryExchangeOrderField_M
	{
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
	};

	/// <summary>
	/// ��ѯ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ��ѯ��������������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryExchangeOrderActionField_M
	{
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
	};

	/// <summary>
	/// ��ѯ�����û�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySuperUserField_M
	{
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��ѯ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryExchangeField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ��ѯ��Ʒ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryProductField_M
	{
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ProductID;
	};

	/// <summary>
	/// ��ѯ��Լ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInstrumentField
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ��Ʒ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ProductID;
	};

	/// <summary>
	/// ��ѯ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryDepthMarketDataField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��ѯ���͹�˾�û�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerUserField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��ѯ���͹�˾�û�Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerUserFunctionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
	};

	/// <summary>
	/// ��ѯ����Ա���̻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTraderOfferField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
	};

	/// <summary>
	/// ��ѯ�������ˮ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySyncDepositField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		System::String^ DepositSeqNo;
	};

	/// <summary>
	/// ��ѯͶ���߽�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySettlementInfoField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
	};

	/// <summary>
	/// ��ѯ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryHisOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ��ʼʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTimeStart;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTimeEnd;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
	};

	/// <summary>
	/// �г�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ���¼�
		/// </summary>
		double LastPrice;
		/// <summary>
		/// �ϴν����
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// ������
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// ��ֲ���
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// ����
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// ��߼�
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// ��ͼ�
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// �ɽ����
		/// </summary>
		double Turnover;
		/// <summary>
		/// �ֲ���
		/// </summary>
		double OpenInterest;
		/// <summary>
		/// ������
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// ���ν����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double PreDelta;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double CurrDelta;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����޸ĺ���
		/// </summary>
		int UpdateMillisec;
	};

	/// <summary>
	/// �����������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataBaseField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// �ϴν����
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// ������
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// ��ֲ���
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double PreDelta;
	};

	/// <summary>
	/// ���龲̬����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataStaticField_M
	{
		/// <summary>
		/// ����
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// ��߼�
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// ��ͼ�
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// ������
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// ��ͣ���
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// ���ν����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ����ʵ��
		/// </summary>
		double CurrDelta;
	};

	/// <summary>
	/// �������³ɽ�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataLastMatchField_M
	{
		/// <summary>
		/// ���¼�
		/// </summary>
		double LastPrice;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// �ɽ����
		/// </summary>
		double Turnover;
		/// <summary>
		/// �ֲ���
		/// </summary>
		double OpenInterest;
	};

	/// <summary>
	/// �������ż�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataBestPriceField_M
	{
		/// <summary>
		/// �����һ
		/// </summary>
		double BidPrice1;
		/// <summary>
		/// ������һ
		/// </summary>
		int BidVolume1;
		/// <summary>
		/// ������һ
		/// </summary>
		double AskPrice1;
		/// <summary>
		/// ������һ
		/// </summary>
		int AskVolume1;
	};

	/// <summary>
	/// �����������������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataBid23Field_M
	{
		/// <summary>
		/// ����۶�
		/// </summary>
		double BidPrice2;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume2;
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice3;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume3;
	};

	/// <summary>
	/// ������������������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataAsk23Field_M
	{
		/// <summary>
		/// �����۶�
		/// </summary>
		double AskPrice2;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume2;
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice3;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume3;
	};

	/// <summary>
	/// ���������ġ�������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataBid45Field_M
	{
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice4;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume4;
		/// <summary>
		/// �������
		/// </summary>
		double BidPrice5;
		/// <summary>
		/// ��������
		/// </summary>
		int BidVolume5;
	};

	/// <summary>
	/// ���������ġ�������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataAsk45Field_M
	{
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice4;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume4;
		/// <summary>
		/// ��������
		/// </summary>
		double AskPrice5;
		/// <summary>
		/// ��������
		/// </summary>
		int AskVolume5;
	};

	/// <summary>
	/// �������ʱ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataUpdateTimeField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����޸ĺ���
		/// </summary>
		int UpdateMillisec;
	};

	/// <summary>
	/// ָ���ĺ�Լ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSpecificInstrumentField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��Լ״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInstrumentStatusField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ���������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SettlementGroupID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��Լ����״̬
		/// </summary>
		Byte InstrumentStatus;
		/// <summary>
		/// ���׽׶α��
		/// </summary>
		int TradingSegmentSN;
		/// <summary>
		/// ���뱾״̬ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ EnterTime;
		/// <summary>
		/// ���뱾״̬ԭ��
		/// </summary>
		Byte EnterReason;
	};

	/// <summary>
	/// ��ѯ��Լ״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInstrumentStatusField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
	};

	/// <summary>
	/// Ͷ�����˻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorAccountField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
	};

	/// <summary>
	/// ����ӯ���㷨
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcPositionProfitAlgorithmField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// ӯ���㷨
		/// </summary>
		Byte Algorithm;
		/// <summary>
		/// ��ע
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
		System::String^ Memo;
	};

	/// <summary>
	/// ��Ա�ʽ��ۿ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcDiscountField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �ʽ��ۿ۱���
		/// </summary>
		double Discount;
	};

	/// <summary>
	/// ��ѯת������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTransferBankField_M
	{
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
	};

	/// <summary>
	/// ת������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferBankField_M
	{
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ BankName;
		/// <summary>
		/// �Ƿ��Ծ
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// ��ѯͶ���ֲ߳���ϸ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInvestorPositionDetailField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// Ͷ���ֲ߳���ϸ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorPositionDetailField_M
	{
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ����
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ OpenDate;
		/// <summary>
		/// �ɽ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TradeID;
		/// <summary>
		/// ����
		/// </summary>
		int Volume;
		/// <summary>
		/// ���ּ�
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// �ɽ�����
		/// </summary>
		Byte TradeType;//EnumTradeTypeType
		/// <summary>
		/// ��Ϻ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ CombInstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ���ն���ƽ��ӯ��
		/// </summary>
		double CloseProfitByDate;
		/// <summary>
		/// ��ʶԳ�ƽ��ӯ��
		/// </summary>
		double CloseProfitByTrade;
		/// <summary>
		/// ���ն��гֲ�ӯ��
		/// </summary>
		double PositionProfitByDate;
		/// <summary>
		/// ��ʶԳ�ֲ�ӯ��
		/// </summary>
		double PositionProfitByTrade;
		/// <summary>
		/// Ͷ���߱�֤��
		/// </summary>
		double Margin;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchMargin;
		/// <summary>
		/// ��֤����
		/// </summary>
		double MarginRateByMoney;
		/// <summary>
		/// ��֤����(������)
		/// </summary>
		double MarginRateByVolume;
		/// <summary>
		/// ������
		/// </summary>
		double LastSettlementPrice;
		/// <summary>
		/// �����
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// ƽ����
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// ƽ�ֽ��
		/// </summary>
		double CloseAmount;
	};

	/// <summary>
	/// �ʽ��˻�������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingAccountPasswordField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
	};

	/// <summary>
	/// ���������鱨�̻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMDTraderOfferField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// ����������Ա����״̬
		/// </summary>
		System::Byte TraderConnectStatus;
		/// <summary>
		/// �����������������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectRequestDate;
		/// <summary>
		/// �������������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectRequestTime;
		/// <summary>
		/// �ϴα�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportDate;
		/// <summary>
		/// �ϴα���ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ LastReportTime;
		/// <summary>
		/// �����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectDate;
		/// <summary>
		/// �������ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ConnectTime;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ StartDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ StartTime;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ��ѯ���鱨�̻�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryMDTraderOfferField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
	};

	/// <summary>
	/// ��ѯ�ͻ�֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryNoticeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// �ͻ�֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcNoticeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		System::String^ Content;
		/// <summary>
		/// ���͹�˾֪ͨ�������к�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
		System::String^ SequenceLabel;
	};

	/// <summary>
	/// �û�Ȩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcUserRightField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �ͻ�Ȩ������
		/// </summary>
		Byte UserRightType;//EnumUserRightTypeType
		/// <summary>
		/// �Ƿ��ֹ
		/// </summary>
		int IsForbidden;
	};

	/// <summary>
	/// ��ѯ������Ϣȷ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySettlementInfoConfirmField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// װ�ؽ�����Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcLoadSettlementInfoField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ���͹�˾�����ʽ��㷨��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerWithdrawAlgorithmField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �����ʽ��㷨
		/// </summary>
		Byte WithdrawAlgorithm;
		/// <summary>
		/// �ʽ�ʹ����
		/// </summary>
		double UsingRatio;
		/// <summary>
		/// �����Ƿ����ƽ��ӯ��
		/// </summary>
		Byte IncludeCloseProfit;
		/// <summary>
		/// �����޲����޳ɽ��ͻ��Ƿ��ܿ����������
		/// </summary>
		Byte AllWithoutTrade;
		/// <summary>
		/// �����Ƿ����ƽ��ӯ��
		/// </summary>
		Byte AvailIncludeCloseProfit;
		/// <summary>
		/// �Ƿ������û��¼�
		/// </summary>
		int IsBrokerUserEvent;
	};

	/// <summary>
	/// �ʽ��˻���������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingAccountPasswordUpdateV1Field_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ԭ���Ŀ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ OldPassword;
		/// <summary>
		/// �µĿ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ NewPassword;
	};

	/// <summary>
	/// �ʽ��˻���������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingAccountPasswordUpdateField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// ԭ���Ŀ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ OldPassword;
		/// <summary>
		/// �µĿ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ NewPassword;
	};

	/// <summary>
	/// ��ѯ��Ϻ�Լ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryCombinationLegField_M
	{
		/// <summary>
		/// ��Ϻ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ CombInstrumentID;
		/// <summary>
		/// ���ȱ��
		/// </summary>
		int LegID;
		/// <summary>
		/// ���Ⱥ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ LegInstrumentID;
	};

	/// <summary>
	/// ��ѯ��Ϻ�Լ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQrySyncStatusField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
	};

	/// <summary>
	/// ��Ͻ��׺�Լ�ĵ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcCombinationLegField_M
	{
		/// <summary>
		/// ��Ϻ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ CombInstrumentID;
		/// <summary>
		/// ���ȱ��
		/// </summary>
		int LegID;
		/// <summary>
		/// ���Ⱥ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ LegInstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ���ȳ���
		/// </summary>
		int LegMultiple;
		/// <summary>
		/// ��������
		/// </summary>
		int ImplyLevel;
	};

	/// <summary>
	/// ����ͬ��״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcSyncStatusField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ͬ��״̬
		/// </summary>
		Byte DataSyncStatus;
	};

	/// <summary>
	/// ��ѯ��ϵ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryLinkManField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ��ϵ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcLinkManField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��ϵ������
		/// </summary>
		Byte PersonType;//EnumPersonTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdentifiedCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ PersonName;
		/// <summary>
		/// ��ϵ�绰
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// ͨѶ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ZipCode;
		/// <summary>
		/// ���ȼ�
		/// </summary>
		int Priority;
	};

	/// <summary>
	/// ��ѯ���͹�˾�û��¼�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerUserEventField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �û��¼�����
		/// </summary>
		Byte UserEventType;//EnumUserEventTypeType
	};

	/// <summary>
	/// ��ѯ���͹�˾�û��¼�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerUserEventField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �û��¼�����
		/// </summary>
		Byte UserEventType;//EnumUserEventTypeType
		/// <summary>
		/// �û��¼����
		/// </summary>
		int EventSequenceNo;
		/// <summary>
		/// �¼���������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ EventDate;
		/// <summary>
		/// �¼�����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ EventTime;
		/// <summary>
		/// �û��¼���Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1025)]
		System::String^ UserEventInfo;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ��ѯǩԼ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryContractBankField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
	};

	/// <summary>
	/// ��ѯǩԼ������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcContractBankField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з����Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBrchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ BankName;
	};

	/// <summary>
	/// Ͷ������ϳֲ���ϸ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorPositionCombineDetailField_M
	{
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ OpenDate;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��ϱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ ComTradeID;
		/// <summary>
		/// ��ϱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TradeID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// ����
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// �ֲ���
		/// </summary>
		int TotalAmt;
		/// <summary>
		/// Ͷ���߱�֤��
		/// </summary>
		double Margin;
		/// <summary>
		/// ��������֤��
		/// </summary>
		double ExchMargin;
		/// <summary>
		/// ��֤����
		/// </summary>
		double MarginRateByMoney;
		/// <summary>
		/// ��֤����(������)
		/// </summary>
		double MarginRateByVolume;
		/// <summary>
		/// ���ȱ��
		/// </summary>
		int LegID;
		/// <summary>
		/// ���ȳ���
		/// </summary>
		int LegMultiple;
		/// <summary>
		/// ��ϳֲֺ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ CombInstrumentID;
	};

	/// <summary>
	/// Ԥ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcParkedOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �����۸�����
		/// </summary>
		Byte OrderPriceType;//EnumOrderPriceTypeType
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_0;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_1;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_2;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_3;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		System::Byte CombOffsetFlag_4;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_0;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_1;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_2;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_3;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		System::Byte CombHedgeFlag_4;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// �û�ǿ����־
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// Ԥ�񱨵����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ParkedOrderID;
		/// <summary>
		/// �û�����
		/// </summary>
		Byte UserType;//EnumUserTypeType
		/// <summary>
		/// Ԥ��״̬
		/// </summary>
		System::Byte Status;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		///��������־
		int	IsSwapOrder;
	};

	/// <summary>
	/// ����Ԥ�񵥲���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcParkedOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������־
		/// </summary>
		System::Byte ActionFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// �����仯
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// Ԥ�񳷵������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ParkedOrderActionID;
		/// <summary>
		/// �û�����
		/// </summary>
		Byte UserType;//EnumUserTypeType
		/// <summary>
		/// Ԥ�񳷵�״̬
		/// </summary>
		System::Byte Status;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��ѯԤ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryParkedOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ��ѯԤ�񳷵�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryParkedOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ɾ��Ԥ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRemoveParkedOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ԥ�񱨵����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ParkedOrderID;
	};

	/// <summary>
	/// ɾ��Ԥ�񳷵�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRemoveParkedOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// Ԥ�񳷵����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ParkedOrderActionID;
	};

	/// <summary>
	/// ���͹�˾�����ʽ��㷨��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcInvestorWithdrawAlgorithmField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �����ʽ����
		/// </summary>
		double UsingRatio;
	};

	/// <summary>
	/// ��ѯ��ϳֲ���ϸ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryInvestorPositionCombineDetailField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��ϳֲֺ�Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ CombInstrumentID;
	};

	/// <summary>
	/// �ɽ�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcMarketDataAveragePriceField_M
	{
		/// <summary>
		/// ���վ���
		/// </summary>
		double AveragePrice;
	};

	/// <summary>
	/// У��Ͷ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcVerifyInvestorPasswordField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
	};

	/// <summary>
	/// �û�IP
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcUserIPField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// IP��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ IPAddress;
		/// <summary>
		/// IP��ַ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ IPMask;
		/// <summary>
		/// Mac��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MacAddress;
	};

	/// <summary>
	/// �û��¼�֪ͨ��Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingNoticeInfoField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SendTime;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		System::String^ FieldContent;
		/// <summary>
		/// ����ϵ�к�
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// ���к�
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// �û��¼�֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTradingNoticeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���߷�Χ
		/// </summary>
		System::Byte InvestorRange;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ����ϵ�к�
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SendTime;
		/// <summary>
		/// ���к�
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ��Ϣ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		System::String^ FieldContent;
	};

	/// <summary>
	/// ��ѯ�����¼�֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTradingNoticeField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ��ѯ���󱨵�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryErrOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ���󱨵�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcErrOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �����۸�����
		/// </summary>
		Byte OrderPriceType;//EnumOrderPriceTypeType
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombOffsetFlag;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombHedgeFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// �û�ǿ����־
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		///��������־
		int	IsSwapOrder;
	};

	/// <summary>
	/// ��ѯ���󱨵�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcErrorConditionalOrderField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// �����۸�����
		/// </summary>
		Byte OrderPriceType;//EnumOrderPriceTypeType
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��Ͽ�ƽ��־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombOffsetFlag;
		/// <summary>
		/// ���Ͷ���ױ���־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ CombHedgeFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// ����
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// ��Ч������
		/// </summary>
		System::Byte TimeCondition;
		/// <summary>
		/// GTD����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ GTDDate;
		/// <summary>
		/// �ɽ�������
		/// </summary>
		System::Byte VolumeCondition;
		/// <summary>
		/// ��С�ɽ���
		/// </summary>
		int MinVolume;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte ContingentCondition;
		/// <summary>
		/// ֹ���
		/// </summary>
		double StopPrice;
		/// <summary>
		/// ǿƽԭ��
		/// </summary>
		System::Byte ForceCloseReason;
		/// <summary>
		/// �Զ������־
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ��Լ�ڽ������Ĵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ ExchangeInstID;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �����ύ״̬
		/// </summary>
		System::Byte OrderSubmitStatus;
		/// <summary>
		/// ������ʾ���
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ������
		/// </summary>
		int SettlementID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������Դ
		/// </summary>
		System::Byte OrderSource;
		/// <summary>
		/// ����״̬
		/// </summary>
		System::Byte OrderStatus;
		/// <summary>
		/// ��������
		/// </summary>
		Byte OrderType;//EnumOrderTypeType
		/// <summary>
		/// ��ɽ�����
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// ʣ������
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertDate;
		/// <summary>
		/// ί��ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ InsertTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActiveTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ SuspendTime;
		/// <summary>
		/// ����޸�ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ UpdateTime;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CancelTime;
		/// <summary>
		/// ����޸Ľ���������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ ActiveTraderID;
		/// <summary>
		/// �����Ա���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClearingPartID;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// �û��˲�Ʒ��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ UserProductInfo;
		/// <summary>
		/// ״̬��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ StatusMsg;
		/// <summary>
		/// �û�ǿ����־
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// �����û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ ActiveUserID;
		/// <summary>
		/// ���͹�˾�������
		/// </summary>
		int BrokerOrderSeq;
		/// <summary>
		/// ��ر���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ RelativeOrderSysID;
		///֣�����ɽ�����
		int	ZCETotalTradedVolume;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		///��������־
		int	IsSwapOrder;
	};

	/// <summary>
	/// ��ѯ���󱨵�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryErrOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ���󱨵�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcErrOrderActionField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ������������
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderRef;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ǰ�ñ��
		/// </summary>
		int FrontID;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ OrderSysID;
		/// <summary>
		/// ������־
		/// </summary>
		System::Byte ActionFlag;
		/// <summary>
		/// �۸�
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// �����仯
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ActionTime;
		/// <summary>
		/// ����������Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ TraderID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ���ر������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ OrderLocalID;
		/// <summary>
		/// �������ر��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ ActionLocalID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ClientID;
		/// <summary>
		/// ҵ��Ԫ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ BusinessUnit;
		/// <summary>
		/// ��������״̬
		/// </summary>
		System::Byte OrderActionStatus;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ״̬��Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ StatusMsg;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��ѯ������״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryExchangeSequenceField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ������״̬
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcExchangeSequenceField_M
	{
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ���
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// ��Լ����״̬
		/// </summary>
		Byte MarketStatus;
	};

	/// <summary>
	/// ���ݼ۸��ѯ��󱨵�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQueryMaxOrderVolumeWithPriceField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// ��������
		/// </summary>
		System::Byte Direction;
		/// <summary>
		/// ��ƽ��־
		/// </summary>
		System::Byte OffsetFlag;
		/// <summary>
		/// Ͷ���ױ���־
		/// </summary>
		System::Byte HedgeFlag;
		/// <summary>
		/// �������������
		/// </summary>
		int MaxVolume;
		/// <summary>
		/// �����۸�
		/// </summary>
		double Price;
	};

	/// <summary>
	/// ��ѯ���͹�˾���ײ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerTradingParamsField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// ���͹�˾���ײ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerTradingParamsField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// ��֤��۸�����
		/// </summary>
		Byte MarginPriceType;//EnumMarginPriceTypeType
		/// <summary>
		/// ӯ���㷨
		/// </summary>
		Byte Algorithm;
		/// <summary>
		/// �����Ƿ����ƽ��ӯ��
		/// </summary>
		Byte AvailIncludeCloseProfit;
	};

	/// <summary>
	/// ��ѯ���͹�˾�����㷨
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryBrokerTradingAlgosField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
	};

	/// <summary>
	/// ���͹�˾�����㷨
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerTradingAlgosField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// ��Լ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ InstrumentID;
		/// <summary>
		/// �ֲִ����㷨���
		/// </summary>
		System::Byte HandlePositionAlgoID;
		/// <summary>
		/// Ѱ�ұ�֤�����㷨���
		/// </summary>
		System::Byte FindMarginRateAlgoID;
		/// <summary>
		/// �ʽ����㷨���
		/// </summary>
		System::Byte HandleTradingAccountAlgoID;
	};

	/// <summary>
	/// ��ѯ���͹�˾�ʽ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQueryBrokerDepositField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
	};

	/// <summary>
	/// ���͹�˾�ʽ�
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerDepositField_M
	{
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ��Ա����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ ExchangeID;
		/// <summary>
		/// �ϴν���׼����
		/// </summary>
		double PreBalance;
		/// <summary>
		/// ��ǰ��֤���ܶ�
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// ƽ��ӯ��
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// �ڻ�����׼����
		/// </summary>
		double Balance;
		/// <summary>
		/// �����
		/// </summary>
		double Deposit;
		/// <summary>
		/// ������
		/// </summary>
		double Withdraw;
		/// <summary>
		/// �����ʽ�
		/// </summary>
		double Available;
		/// <summary>
		/// ����׼����
		/// </summary>
		double Reserve;
		/// <summary>
		/// ����ı�֤��
		/// </summary>
		double FrozenMargin;
	};

	/// <summary>
	/// ��ѯ��֤����ϵͳ���͹�˾��Կ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryCFMMCBrokerKeyField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
	};

	/// <summary>
	/// ��֤����ϵͳ���͹�˾��Կ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcCFMMCBrokerKeyField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���͹�˾ͳһ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// ��Կ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CreateDate;
		/// <summary>
		/// ��Կ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ CreateTime;
		/// <summary>
		/// ��Կ���
		/// </summary>
		int KeyID;
		/// <summary>
		/// ��̬��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CurrentKey;
		/// <summary>
		/// ��̬��Կ����
		/// </summary>
		System::Byte KeyKind;
	};

	/// <summary>
	/// ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcCFMMCTradingAccountKeyField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���͹�˾ͳһ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ ParticipantID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// ��Կ���
		/// </summary>
		int KeyID;
		/// <summary>
		/// ��̬��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CurrentKey;
	};

	/// <summary>
	/// �����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryCFMMCTradingAccountKeyField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
	};

	/// <summary>
	/// �û���̬���Ʋ���
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcBrokerUserOTPParamField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��̬�����ṩ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
		System::String^ OTPVendorsID;
		/// <summary>
		/// ��̬�������к�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ SerialNumber;
		/// <summary>
		/// ������Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ AuthKey;
		/// <summary>
		/// Ư��ֵ
		/// </summary>
		int LastDrift;
		/// <summary>
		/// �ɹ�ֵ
		/// </summary>
		int LastSuccess;
		/// <summary>
		/// ��̬��������
		/// </summary>
		Byte OTPType;//EnumOTPTypeType
	};

	/// <summary>
	/// �ֹ�ͬ���û���̬����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcManualSyncBrokerUserOTPField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// �û�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��̬��������
		/// </summary>
		Byte OTPType;//EnumOTPTypeType
		/// <summary>
		/// ��һ����̬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ FirstOTP;
		/// <summary>
		/// �ڶ�����̬����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ SecondOTP;
	};

	/// <summary>
	/// ת�ʿ�������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqOpenAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �Ա�
		/// </summary>
		System::Byte Gender;
		/// <summary>
		/// ���Ҵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CountryCode;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// �ʱ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ZipCode;
		/// <summary>
		/// �绰����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// �ֻ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MobilePhone;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Fax;
		/// <summary>
		/// �����ʼ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ EMail;
		/// <summary>
		/// �ʽ��˻�״̬
		/// </summary>
		System::Byte MoneyAccountStatus;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// �㳮��־
		/// </summary>
		System::Byte CashExchangeCode;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		///�û���ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^	UserID;
	};

	/// <summary>
	/// ת����������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqCancelAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �Ա�
		/// </summary>
		System::Byte Gender;
		/// <summary>
		/// ���Ҵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CountryCode;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// �ʱ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ZipCode;
		/// <summary>
		/// �绰����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// �ֻ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MobilePhone;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Fax;
		/// <summary>
		/// �����ʼ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ EMail;
		/// <summary>
		/// �ʽ��˻�״̬
		/// </summary>
		System::Byte MoneyAccountStatus;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// �㳮��־
		/// </summary>
		System::Byte CashExchangeCode;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ��������˻�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqChangeAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �Ա�
		/// </summary>
		System::Byte Gender;
		/// <summary>
		/// ���Ҵ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ CountryCode;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// ��ַ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		System::String^ Address;
		/// <summary>
		/// �ʱ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ZipCode;
		/// <summary>
		/// �绰����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Telephone;
		/// <summary>
		/// �ֻ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		System::String^ MobilePhone;
		/// <summary>
		/// ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Fax;
		/// <summary>
		/// �����ʼ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ EMail;
		/// <summary>
		/// �ʽ��˻�״̬
		/// </summary>
		System::Byte MoneyAccountStatus;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// �������ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ NewBankAccount;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ NewBankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
	};

	/// <summary>
	/// ת������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqTransferField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// �ڻ���ȡ���
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// ����֧����־
		/// </summary>
		System::Byte FeePayFlag;
		/// <summary>
		/// Ӧ�տͻ�����
		/// </summary>
		double CustFee;
		/// <summary>
		/// Ӧ���ڻ���˾����
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// ���ͷ������շ�����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ת�˽���״̬
		/// </summary>
		Byte TransferStatus;
	};

	/// <summary>
	/// ���з��������ʽ�ת�ڻ���Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspTransferField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// �ڻ���ȡ���
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// ����֧����־
		/// </summary>
		System::Byte FeePayFlag;
		/// <summary>
		/// Ӧ�տͻ�����
		/// </summary>
		double CustFee;
		/// <summary>
		/// Ӧ���ڻ���˾����
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// ���ͷ������շ�����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ת�˽���״̬
		/// </summary>
		Byte TransferStatus;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqRepealField_M
	{
		/// <summary>
		/// ����ʱ����
		/// </summary>
		int RepealTimeInterval;
		/// <summary>
		/// �Ѿ���������
		/// </summary>
		int RepealedTimes;
		/// <summary>
		/// ���г�����־
		/// </summary>
		System::Byte BankRepealFlag;
		/// <summary>
		/// ���̳�����־
		/// </summary>
		System::Byte BrokerRepealFlag;
		/// <summary>
		/// ������ƽ̨��ˮ��
		/// </summary>
		int PlateRepealSerial;
		/// <summary>
		/// ������������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankRepealSerial;
		/// <summary>
		/// �������ڻ���ˮ��
		/// </summary>
		int FutureRepealSerial;
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;//EnumIdCardTypeType
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// �ڻ���ȡ���
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// ����֧����־
		/// </summary>
		System::Byte FeePayFlag;
		/// <summary>
		/// Ӧ�տͻ�����
		/// </summary>
		double CustFee;
		/// <summary>
		/// Ӧ���ڻ���˾����
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// ���ͷ������շ�����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ת�˽���״̬
		/// </summary>
		Byte TransferStatus;
	};

	/// <summary>
	/// ������Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspRepealField_M
	{
		/// <summary>
		/// ����ʱ����
		/// </summary>
		int RepealTimeInterval;
		/// <summary>
		/// �Ѿ���������
		/// </summary>
		int RepealedTimes;
		/// <summary>
		/// ���г�����־
		/// </summary>
		System::Byte BankRepealFlag;
		/// <summary>
		/// ���̳�����־
		/// </summary>
		System::Byte BrokerRepealFlag;
		/// <summary>
		/// ������ƽ̨��ˮ��
		/// </summary>
		int PlateRepealSerial;
		/// <summary>
		/// ������������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankRepealSerial;
		/// <summary>
		/// �������ڻ���ˮ��
		/// </summary>
		int FutureRepealSerial;
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;//EnumCustTypeType
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// �ڻ���ȡ���
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// ����֧����־
		/// </summary>
		System::Byte FeePayFlag;
		/// <summary>
		/// Ӧ�տͻ�����
		/// </summary>
		double CustFee;
		/// <summary>
		/// Ӧ���ڻ���˾����
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// ���ͷ������շ�����Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;//EnumBankAccTypeType
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;//EnumBankAccTypeType
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ת�˽���״̬
		/// </summary>
		Byte TransferStatus;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��ѯ�˻���Ϣ����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqQueryAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ��ѯ�˻���Ϣ��Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspQueryAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ���п��ý��
		/// </summary>
		double BankUseAmount;
		/// <summary>
		/// ���п�ȡ���
		/// </summary>
		double BankFetchAmount;
	};

	/// <summary>
	/// ����ǩ��ǩ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcFutureSignIOField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ����ǩ����Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspFutureSignInField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		/// <summary>
		/// PIN��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ PinKey;
		/// <summary>
		/// MAC��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ MacKey;
	};

	/// <summary>
	/// ����ǩ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqFutureSignOutField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ����ǩ����Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspFutureSignOutField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��ѯָ����ˮ�ŵĽ��׽������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqQueryTradeResultBySerialField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��ˮ��
		/// </summary>
		int Reference;
		/// <summary>
		/// ����ˮ�ŷ����ߵĻ�������
		/// </summary>
		Byte RefrenceIssureType;
		/// <summary>
		/// ����ˮ�ŷ����߻�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ RefrenceIssure;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
	};

	/// <summary>
	/// ��ѯָ����ˮ�ŵĽ��׽����Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspQueryTradeResultBySerialField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		/// <summary>
		/// ��ˮ��
		/// </summary>
		int Reference;
		/// <summary>
		/// ����ˮ�ŷ����ߵĻ�������
		/// </summary>
		Byte RefrenceIssureType;
		/// <summary>
		/// ����ˮ�ŷ����߻�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ RefrenceIssure;
		/// <summary>
		/// ԭʼ���ش���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ OriginReturnCode;
		/// <summary>
		/// ԭʼ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ OriginDescrInfoForReturnCode;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ת�ʽ��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
	};

	/// <summary>
	/// �����ļ���������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqDayEndFileReadyField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ļ�ҵ����
		/// </summary>
		System::Byte FileBusinessCode;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
	};

	/// <summary>
	/// ���ؽ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReturnResultField_M
	{
		/// <summary>
		/// ���ش���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ReturnCode;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ DescrInfoForReturnCode;
	};

	/// <summary>
	/// ��֤�ڻ��ʽ�����
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcVerifyFuturePasswordField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ��֤�ͻ���Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcVerifyCustInfoField_M
	{
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
	};

	/// <summary>
	/// ��֤�ڻ��ʽ�����Ϳͻ���Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcVerifyFuturePasswordAndCustInfoField_M
	{
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
	};

	/// <summary>
	/// ��֤�ڻ��ʽ�����Ϳͻ���Ϣ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcDepositResultInformField_M
	{
		/// <summary>
		/// �������ˮ�ţ�����ˮ��Ϊ���ڱ��̷��ص���ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		System::String^ DepositSeqNo;
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �����
		/// </summary>
		double Deposit;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ���ش���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ ReturnCode;
		/// <summary>
		/// ����������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ DescrInfoForReturnCode;
	};

	/// <summary>
	/// ���׺��������ڱ��̷�����Կͬ������
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcReqSyncKeyField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ���׺��ĸ����ڱ��̵���Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// ���׺��������ڱ��̷�����Կͬ����Ӧ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcRspSyncKeyField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ���׺��ĸ����ڱ��̵���Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ��ѯ�˻���Ϣ֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcNotifyQueryAccountField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ CustomerName;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// �ͻ�����
		/// </summary>
		Byte CustType;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankPassWord;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// �ڻ�����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ Password;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ��֤�ͻ�֤�������־
		/// </summary>
		System::Byte VerifyCertNoFlag;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���λ�ʺ�����
		/// </summary>
		Byte BankSecuAccType;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// �ڻ���λ�ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankSecuAcc;
		/// <summary>
		/// ���������־
		/// </summary>
		System::Byte BankPwdFlag;
		/// <summary>
		/// �ڻ��ʽ�����˶Ա�־
		/// </summary>
		System::Byte SecuPwdFlag;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// ���п��ý��
		/// </summary>
		double BankUseAmount;
		/// <summary>
		/// ���п�ȡ���
		/// </summary>
		double BankFetchAmount;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ����ת�˽�����ˮ��
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcTransferSerialField_M
	{
		/// <summary>
		/// ƽ̨��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ���׷�������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ���״���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// �Ự���
		/// </summary>
		int SessionID;
		/// <summary>
		/// ���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// �����ʺ�����
		/// </summary>
		Byte BankAccType;
		/// <summary>
		/// �����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankAccount;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// �ڻ���˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// �ڻ���˾�ʺ�����
		/// </summary>
		Byte FutureAccType;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// Ͷ���ߴ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ InvestorID;
		/// <summary>
		/// �ڻ���˾��ˮ��
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// ֤������
		/// </summary>
		Byte IdCardType;
		/// <summary>
		/// ֤������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		System::String^ IdentifiedCardNo;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ���׽��
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// Ӧ�տͻ�����
		/// </summary>
		double CustFee;
		/// <summary>
		/// Ӧ���ڻ���˾����
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// ��Ч��־
		/// </summary>
		System::Byte AvailabilityFlag;
		/// <summary>
		/// ����Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperatorCode;
		/// <summary>
		/// �������ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		System::String^ BankNewAccount;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// �����ѯת����ˮ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcQryTransferSerialField_M
	{
		/// <summary>
		/// ���͹�˾����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// Ͷ�����ʺ�
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ AccountID;
		/// <summary>
		/// ���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
	};

	/// <summary>
	/// ����ǩ��֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcNotifyFutureSignInField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
		/// <summary>
		/// PIN��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ PinKey;
		/// <summary>
		/// MAC��Կ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ MacKey;
	};

	/// <summary>
	/// ����ǩ��֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcNotifyFutureSignOutField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ժҪ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		System::String^ Digest;
		/// <summary>
		/// ���ִ���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ CurrencyID;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

	/// <summary>
	/// ���׺��������ڱ��̷�����Կͬ����������֪ͨ
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct CThostFtdcNotifySyncKeyField_M
	{
		/// <summary>
		/// ҵ������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		System::String^ TradeCode;
		/// <summary>
		/// ���д���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		System::String^ BankID;
		/// <summary>
		/// ���з�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		System::String^ BankBranchID;
		/// <summary>
		/// ���̴���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		System::String^ BrokerID;
		/// <summary>
		/// ���̷�֧��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		System::String^ BrokerBranchID;
		/// <summary>
		/// ��������
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeDate;
		/// <summary>
		/// ����ʱ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradeTime;
		/// <summary>
		/// ������ˮ��
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		System::String^ BankSerial;
		/// <summary>
		/// ����ϵͳ����
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		System::String^ TradingDay;
		/// <summary>
		/// ����ƽ̨��Ϣ��ˮ��
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// ����Ƭ��־
		/// </summary>
		System::Byte LastFragment;
		/// <summary>
		/// �Ự��
		/// </summary>
		int SessionID;
		/// <summary>
		/// ��װ���
		/// </summary>
		int InstallID;
		/// <summary>
		/// �û���ʶ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		System::String^ UserID;
		/// <summary>
		/// ���׺��ĸ����ڱ��̵���Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		System::String^ Message;
		/// <summary>
		/// ������־
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		System::String^ DeviceID;
		/// <summary>
		/// �ڻ���˾���б���
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		System::String^ BrokerIDByBank;
		/// <summary>
		/// ���׹�Ա
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		System::String^ OperNo;
		/// <summary>
		/// ������
		/// </summary>
		int RequestID;
		/// <summary>
		/// ����ID
		/// </summary>
		int TID;
		/// <summary>
		/// �������
		/// </summary>
		int ErrorID;
		/// <summary>
		/// ������Ϣ
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		System::String^ ErrorMsg;
	};

}

#endif