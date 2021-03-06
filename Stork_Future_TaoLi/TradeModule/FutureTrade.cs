﻿using Stork_Future_TaoLi.TradeModule;
using Stork_Future_TaoLi.Variables_Type;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using Stork_Future_TaoLi.Modulars;
using System.Web;
using Stork_Future_TaoLi.Queues;
using CTP_CLI;
using MCStockLib;
using Stork_Future_TaoLi.Database;

namespace Stork_Future_TaoLi
{
    public class FutureTrade
    {
        private  static LogWirter sublog = new LogWirter();//子线程日志记录
        private static CTP_CLI.CCTPClient _client;
        private static FutureTradeThreadStatus status = FutureTradeThreadStatus.DISCONNECTED;

        /// <summary>
        /// Rtn Order 锁变量
        /// </summary>
        private static object syncRtnOrderObject = new object();

        /// <summary>
        /// Rtn Trade 锁变量
        /// </summary>
        private static object syncRtnTradeObject = new object();

        #region 委托参数
        /// <summary>
        /// 经纪公司代码
        /// </summary>
        public string BrokerID ;
        /// <summary>
        /// 业务单元
        /// </summary>
        public string BusinessUnit;
        /// <summary>
        /// 组合开平标志
        /// </summary>
        public byte CombHedgeFlag_0;
        /// <summary>
        /// 组合开平标志
        /// </summary>
        public byte CombHedgeFlag_1;
        /// <summary>
        /// 组合开平标志
        /// </summary>
        public byte CombHedgeFlag_2;
        /// <summary>
        /// 组合开平标志
        /// </summary>
        public byte CombHedgeFlag_3;
        /// <summary>
        /// 组合开平标志
        /// </summary>
        public byte CombHedgeFlag_4;
        /// <summary>
        /// 组合投机套保标志
        /// </summary>
        public byte CombOffsetFlag_0;
        /// <summary>
        /// 组合投机套保标志
        /// </summary>
        public byte CombOffsetFlag_1;
        /// <summary>
        /// 组合投机套保标志
        /// </summary>
        public byte CombOffsetFlag_2;
        /// <summary>
        /// 组合投机套保标志
        /// </summary>
        public byte CombOffsetFlag_3;
        /// <summary>
        /// 组合投机套保标志
        /// </summary>
        public byte CombOffsetFlag_4;
        /// <summary>
        /// 触发条件
        /// </summary>
        public byte ContingentCondition;
        /// <summary>
        /// 买卖方向
        /// </summary>
        public byte Direction;
        /// <summary>
        /// 强平原因
        /// </summary>
        public byte ForceCloseReason;
        /// <summary>
        /// GTD日期
        /// </summary>
        public string GTDDate;
        /// <summary>
        /// 合约代码
        /// </summary>
        public string InstrumentID;
        /// <summary>
        /// 投资者代码
        /// </summary>
        public string InvestorID ;
        /// <summary>
        /// 自动挂起标志
        /// </summary>
        public int IsAutoSuspend;
        ///互换单标志
        public int IsSwapOrder;
        /// <summary>
        /// 价格
        /// </summary>
        public double LimitPrice;
        /// <summary>
        /// 最小成交量
        /// </summary>
        public int MinVolume;
        /// <summary>
        /// 报单价格条件
        /// </summary>
        public byte OrderPriceType;
        /// <summary>
        /// 报单引用
        /// </summary>
        public string OrderRef;
        /// <summary>
        /// 请求编号
        /// </summary>
        public int RequestID;
        /// <summary>
        /// 止损价
        /// </summary>
        public double StopPrice;
        /// <summary>
        /// 有效期类型
        /// </summary>
        public byte TimeCondition;
        /// <summary>
        /// 用户强评标志
        /// </summary>
        public int UserForceClose;
        /// <summary>
        /// 用户代码
        /// </summary>
        public string UserID;
        /// <summary>
        /// 成交量类型
        /// </summary>
        public byte VolumeCondition;
        /// <summary>
        /// 数量
        /// </summary>
        public int VolumeTotalOriginal;

        #endregion


        public static void InitRespFunc()
        {
            _client = new CTP_CLI.CCTPClient(CommConfig.INVESTOR, CommConfig.PASSWORD, CommConfig.BROKER, CommConfig.ADDRESS);

            //CTP后台成功建立连接的回调函数
            _client.FrontConnected += _client_FrontConnected;
            //CTP后台连接丢失回调函数
            _client.FrontDisconnected += _client_FrontDisconnected;
            //登陆成功回调函数
            _client.RspUserLogin += _client_RspUserLogin;
            //报单变化回调函数
            _client.RtnOrder += _client_RtnOrder;
            //成交变化回调函数
            _client.RtnTrade += _client_RtnTrade;
            //报单修改操作回调函数（暂时不用）
            _client.RspOrderAction += _client_RspOrderAction;
            //报单失败回调函数
            _client.RspOrderInsert += _client_RspOrderInsert;
            //报单问题回调函数
            _client.ErrRtnOrderInsert += _client_ErrRtnOrderInsert;
            //保单查询回调函数
            _client.RspQryOrder += _client_RspQryOrder;
        }

       

        /// <summary>
        /// 期货交易工作线程
        /// </summary>
        /// <param name="para"></param>
        public void FutureTradeSubThreadProc(object para)
        {
            string ErrorMsg = string.Empty;

            //令该线程为前台线程
            Thread.CurrentThread.IsBackground = true;

            DateTime lastmessagetime = DateTime.Now;

            TradeParaPackage _tpp = (TradeParaPackage)para;

            //当前线程编号
            int _threadNo = _tpp._threadNo;

            sublog.LogEvent("线程 ：" + _threadNo.ToString() + " 开始执行");

            //用作发送心跳包的时间标记
            DateTime _markedTime = DateTime.Now;

            //控制期货交易线程执行
            bool _threadRunControl = true;

            //获取未成交期货委托
            List<ER_TAOLI_TABLE> ERs = DBAccessLayer.GetInCompletedERRecord("F");

            if (ERs != null)
            {
                foreach (ER_TAOLI_TABLE ER in ERs)
                {
                    decimal price = (ER.ER_VOLUME_TOTAL_ORIGINAL == 0 ? 0 : Convert.ToDecimal(ER.ER_FROZEN_MONEY / ER.ER_VOLUME_TOTAL_ORIGINAL));
                    string code = ER.ER_CODE;

                    TradeRecord.GetInstance().SubscribeIncompleteOrder("F", ER.ER_CODE, ER.ER_ID, ER.ER_DIRECTION.ToString(), Convert.ToInt16(ER.ER_VOLUME_TOTAL_ORIGINAL), price, Convert.ToInt16(ER.ER_ORDER_REF), Convert.ToInt16("0"), Convert.ToInt16(ER.ER_OFFSETFLAG.Trim()), ER.ER_USER);
                }
            }

            while (_threadRunControl)
            {
                //初始化完成前，不接收实际交易
                queue_future_excuteThread.SetThreadBusy(_threadNo);

                _client.Connect();

                //状态 DISCONNECTED -> CONNECTED
                while (status != FutureTradeThreadStatus.CONNECTED)
                {
                    Thread.Sleep(10);
                }

                _client.ReqUserLogin();

                //状态 CONNECTED -> LOGIN
                while (status != FutureTradeThreadStatus.LOGIN)
                {
                    Thread.Sleep(10);
                }


                if (ERs != null)
                {
                    foreach (ER_TAOLI_TABLE ER in ERs)
                    {
                        _client.QryOrder(ER.ER_ORDER_EXCHANGE_ID, "", "", "", ER.ER_ID.PadLeft(12));
                    }
                }

                while (true)
                {

                    Thread.Sleep(10);

                    if ((DateTime.Now - GlobalHeartBeat.GetGlobalTime()).TotalMinutes > 10)
                    {
                        sublog.LogEvent("线程 ：" + _threadNo.ToString() + "心跳停止 ， 最后心跳 ： " + GlobalHeartBeat.GetGlobalTime().ToString());
                        _threadRunControl = false;
                        break;
                    }

                    if (lastmessagetime.Second != DateTime.Now.Second)
                    {
                        KeyValuePair<string, object> message1 = new KeyValuePair<string, object>("THREAD_FUTURE_TRADE_WORKER", (object)_threadNo);
                        queue_system_status.GetQueue().Enqueue((object)message1);
                    }

                    if (queue_future_excuteThread.GetQueue(_threadNo).Count < 2)
                    {
                        queue_future_excuteThread.SetThreadFree(_threadNo);
                        status = FutureTradeThreadStatus.FREE;
                    }
                    else
                    {
                        status = FutureTradeThreadStatus.BUSY;
                    }

                    if (queue_future_excuteThread.GetQueue(_threadNo).Count > 0)
                    {
                        List<TradeOrderStruct> trades = (List<TradeOrderStruct>)queue_future_excuteThread.FutureExcuteQueue[_threadNo].Dequeue();
                        if (trades == null) continue;
                        if (trades.Count > 0) { sublog.LogEvent("线程 ：" + _threadNo.ToString() + " 执行交易数量 ： " + trades.Count); }

                        if (trades.Count == 0) { continue; }

                        foreach (TradeOrderStruct order in trades)
                        {


                            CTP_CLI.CThostFtdcInputOrderField_M args = new CThostFtdcInputOrderField_M();

                            //填写委托参数

                            args.BrokerID = CommConfig.BROKER;
                            args.InvestorID = CommConfig.INVESTOR;
                            args.InstrumentID = order.cSecurityCode;
                            args.Direction = Convert.ToByte(order.cTradeDirection);
                            args.CombOffsetFlag_0 =  Convert.ToByte(order.cOffsetFlag);
                            args.VolumeTotalOriginal = Convert.ToInt16(order.nSecurityAmount);
                            args.LimitPrice = Convert.ToDouble(order.dOrderPrice);
                            args.OrderRef = order.OrderRef.ToString();
                            args.OrderPriceType =Convert.ToByte("50");
                            args.CombHedgeFlag_0 = Convert.ToByte('1');
                            args.MinVolume = 1;
                            args.ContingentCondition = Convert.ToByte('1');      
                            args.TimeCondition = Convert.ToByte('3');
                            args.VolumeCondition = Convert.ToByte('1');
                            args.UserID = order.cUser;
                            args.ForceCloseReason = Convert.ToByte('0');
                            args.IsAutoSuspend = 0;
                            args.UserForceClose = 0;

                            //提交报单委托
                            //步骤完成后线程任务结束
                            //返回工作交由回调函数处理
                            _client.OrderInsert(args);

                            //创建记录
                            RecordItem item = new RecordItem();
                            item.AveragePrice = 0;
                            item.Code = order.cSecurityCode;
                            item.CombOffsetFlag = Convert.ToInt16(order.cOffsetFlag);
                            item.OrderRef = order.OrderRef;
                            item.OrderStatus = 0;
                            item.OrderSysID = "0";
                            item.Orientation = order.cTradeDirection;
                            item.Price = Convert.ToDecimal(order.dOrderPrice);
                            item.Status = TradeDealStatus.ORDERING;
                            item.StrategyId = order.belongStrategy;
                            item.Type = "1";
                            item.VolumeTotalOriginal = item.VolumeTotal = Convert.ToInt32(order.nSecurityAmount);
                            item.VolumeTraded = 0;
                            item.User = order.cUser;

                            
                            TradeRecord.GetInstance().CreateOrder(order.OrderRef, item);
                        }

                    }
                }
            }
        }

        /// <summary>
        /// 设置日志
        /// </summary>
        /// <param name="log"></param>
        public void SetLog(LogWirter log) { sublog = log; }

        public FutureTrade()
        {
        }

        /// <summary>
        /// 发出报单出现问题回调函数
        /// </summary>
        /// <param name="pInputOrder"></param>
        /// <param name="pRspInfo"></param>
        public static void _client_ErrRtnOrderInsert(CThostFtdcInputOrderField_M pInputOrder, CThostFtdcRspInfoField_M pRspInfo)
        {
            TradeRecord.GetInstance().MarkFailure(Convert.ToInt16(pInputOrder.OrderRef), pRspInfo.ErrorMsg);

            if (pInputOrder.CombOffsetFlag_0 == (byte)(FutureTradeOffSet.Open))
            {
                //只有开仓涉及冻结资金
                //交易失败，需要释放冻结掉的期货交易资金
                accountMonitor.UpdateRiskFrozonAccount(pInputOrder.UserID, pInputOrder.InstrumentID, pInputOrder.VolumeTotalOriginal * (-1), pInputOrder.VolumeTotalOriginal * pInputOrder.LimitPrice * (-1), "F", pInputOrder.Direction.ToString());
            }
        }

        /// <summary>
        /// 连接成功
        /// </summary>
        static void _client_FrontConnected()
        {
            status = FutureTradeThreadStatus.CONNECTED;
        }

        /// <summary>
        /// 链接失败，记入日志
        /// </summary>
        /// <param name="nReason"></param>
        static void _client_FrontDisconnected(int nReason)
        {
            sublog.LogEvent("期货交易所链接失败，失败码：" + nReason.ToString());
        }

        /// <summary>
        /// 交易提交出现问题回掉函数
        /// </summary>
        /// <param name="pInputOrder"></param>
        /// <param name="pRspInfo"></param>
        /// <param name="nRequestID"></param>
        /// <param name="bIsLast"></param>
        public static void _client_RspOrderInsert(CTP_CLI.CThostFtdcInputOrderField_M pInputOrder, CTP_CLI.CThostFtdcRspInfoField_M pRspInfo, int nRequestID, bool bIsLast)
        {
            TradeRecord.GetInstance().MarkFailure(Convert.ToInt16(pInputOrder.OrderRef), pRspInfo.ErrorMsg);
            if (pInputOrder.CombOffsetFlag_0 == (byte)(FutureTradeOffSet.Open))
            {
                //只有开仓涉及冻结资金
                //交易失败，需要释放冻结掉的期货交易资金
                accountMonitor.UpdateRiskFrozonAccount(pInputOrder.UserID, pInputOrder.InstrumentID, pInputOrder.VolumeTotalOriginal * (-1), pInputOrder.VolumeTotalOriginal * pInputOrder.LimitPrice * (-1), "F", pInputOrder.Direction.ToString());
            }
        }

        /// <summary>
        /// 提交报单请求响应处理函数， 当报单内容有问题时，通过该函数响应
        /// </summary>
        /// <param name="pInputOrderAction">报单请求内容</param>
        /// <param name="pRspInfo">返回信息</param>
        /// <param name="nRequestID"></param>
        /// <param name="bIsLast"></param>
        public static void _client_RspOrderAction(CTP_CLI.CThostFtdcInputOrderActionField_M pInputOrderAction, 
            CTP_CLI.CThostFtdcRspInfoField_M pRspInfo, int nRequestID, bool bIsLast)
        {
            GlobalErrorLog.LogInstance.LogEvent("期货报单失败，" + pRspInfo.ErrorMsg);
        }

        /// <summary>
        /// 成交回报（私有回报）
        /// 此函数通知交易的变化
        /// </summary>
        /// <param name="pTrade"></param>
        public static void _client_RtnTrade(CTP_CLI.CThostFtdcTradeField_M pTrade)
        {
            CThostFtdcTradeField_M Trade = new CThostFtdcTradeField_M()
            {
                BrokerID = pTrade.BrokerID,
                BrokerOrderSeq = pTrade.BrokerOrderSeq,
                BusinessUnit = pTrade.BusinessUnit,
                ClearingPartID = pTrade.ClearingPartID,
                ClientID = pTrade.ClientID,
                Direction = pTrade.Direction,
                ExchangeID = pTrade.ExchangeID,
                ExchangeInstID = pTrade.ExchangeInstID,
                HedgeFlag = pTrade.HedgeFlag,
                InstrumentID = pTrade.InstrumentID,
                InvestorID = pTrade.InvestorID,
                OffsetFlag = pTrade.OffsetFlag,
                OrderLocalID = pTrade.OrderLocalID,
                OrderRef = pTrade.OrderRef,
                OrderSysID = pTrade.OrderSysID,
                ParticipantID = pTrade.ParticipantID,
                Price = pTrade.Price,
                PriceSource = pTrade.PriceSource,
                SequenceNo = pTrade.SequenceNo,
                SettlementID = pTrade.SettlementID,
                TradeDate = pTrade.TradeDate,
                TradeID = pTrade.TradeID,
                TraderID = pTrade.TraderID,
                TradeTime = pTrade.TradeTime,
                TradeType = pTrade.TradeType,
                TradingDay = pTrade.TradingDay,
                TradingRole = pTrade.TradingRole,
                UserID = pTrade.UserID,
                Volume = pTrade.Volume
            };
            ThreadPool.QueueUserWorkItem(new WaitCallback(FutureTrade.RtnTradeProc), (object)Trade);
        }

        /// <summary>
        /// 报单回报（私有回报）
        /// 此函数通知报单的变化
        /// </summary>
        /// <param name="pOrder"></param>
        public static void _client_RtnOrder(CTP_CLI.CThostFtdcOrderField_M pOrder)
        {
            CTP_CLI.CThostFtdcOrderField_M order = new CThostFtdcOrderField_M()
            {
                ActiveTime = pOrder.ActiveTime,
                ExchangeID = pOrder.ExchangeID,
                ExchangeInstID = pOrder.ExchangeInstID,
                ForceCloseReason = pOrder.ForceCloseReason,
                Direction = pOrder.Direction,
                CombHedgeFlag_0 = pOrder.CombHedgeFlag_0,
                VolumeTotal = pOrder.VolumeTotal,
                VolumeTotalOriginal = pOrder.VolumeTotalOriginal,
                VolumeTraded = pOrder.VolumeTraded,
                StatusMsg = pOrder.StatusMsg,
                CombOffsetFlag_0 = pOrder.CombOffsetFlag_0,
                OrderSysID = pOrder.OrderSysID,
                OrderLocalID = pOrder.OrderLocalID,
                OrderStatus = pOrder.OrderStatus,
                OrderRef = pOrder.OrderRef,
                ActiveTraderID = pOrder.ActiveTraderID,
                ActiveUserID = pOrder.ActiveUserID,
                BrokerID = pOrder.BrokerID,
                BrokerOrderSeq = pOrder.BrokerOrderSeq,
                BusinessUnit = pOrder.BusinessUnit,
                CancelTime = pOrder.CancelTime,
                ClearingPartID = pOrder.ClearingPartID,
                ClientID = pOrder.ClientID,
                CombHedgeFlag_1 = pOrder.CombHedgeFlag_1,
                CombHedgeFlag_2 = pOrder.CombHedgeFlag_2,
                CombHedgeFlag_3 = pOrder.CombHedgeFlag_3,
                CombHedgeFlag_4 = pOrder.CombHedgeFlag_4,
                CombOffsetFlag_1 = pOrder.CombOffsetFlag_1,
                CombOffsetFlag_2 = pOrder.CombOffsetFlag_2,
                CombOffsetFlag_3 = pOrder.CombOffsetFlag_3,
                CombOffsetFlag_4 = pOrder.CombOffsetFlag_4,
                FrontID = pOrder.FrontID,
                InstrumentID = pOrder.InstrumentID,
                InsertTime = pOrder.InsertTime,
                InsertDate = pOrder.InsertDate,
                LimitPrice = pOrder.LimitPrice,
                OrderType = pOrder.OrderType,
                SessionID = pOrder.SessionID,
                UserID = pOrder.UserID,
                TraderID = pOrder.TraderID
            };

            ThreadPool.QueueUserWorkItem(new WaitCallback(FutureTrade.RtnOrderProc), (object)order);
        }

        /// <summary>
        /// 报单查询回报（私有回报）
        /// 此函数通知报单的变化
        /// </summary>
        /// <param name="pOrder"></param>
        public static void _client_RspQryOrder(CThostFtdcOrderField_M pOrder, CThostFtdcRspInfoField_M pRspInfo, int nRequestID, bool bIsLast)
        {
            ThreadPool.QueueUserWorkItem(new WaitCallback(FutureTrade.RtnOrderProc), (object)pOrder);
        }

        /// <summary>
        /// 登陆成功回掉函数
        /// </summary>
        /// <param name="pRspUserLogin">用户登录信息结构</param>
        /// <param name="pRspInfo">返回用户响应信息</param>
        /// <param name="nRequestID">返回用户登录请求的ID，该ID 由用户在登录时指定。</param>
        /// <param name="bIsLast">指示该次返回是否为针对nRequestID的最后一次返回。</param>
        public static void _client_RspUserLogin(CTP_CLI.CThostFtdcRspUserLoginField_M pRspUserLogin, CTP_CLI.CThostFtdcRspInfoField_M pRspInfo, int nRequestID, bool bIsLast)
        {
            if (pRspInfo.ErrorID == 0 && bIsLast == true)
            {
                status = FutureTradeThreadStatus.LOGIN;
            }
            //throw new NotImplementedException();
        }


        public static void _client_RspError(CTP_CLI.CThostFtdcRspInfoField_M pRspInfo, int nRequestID, bool bIsLast)
        {

            throw new NotImplementedException();
        }


        public static void RtnOrderProc(object order)
        {
            CThostFtdcOrderField_M pOrder = (CThostFtdcOrderField_M)order;

            lock (syncRtnOrderObject)
            {
                switch (pOrder.OrderStatus)
                {
                    case 48:
                        {
                            //全部成交
                            TradeRecord.GetInstance().UpdateOrder(pOrder.VolumeTraded, Convert.ToInt16(pOrder.OrderRef), pOrder.OrderSysID, pOrder.StatusMsg, pOrder.OrderStatus, pOrder.VolumeTotal, pOrder.ExchangeID);

                            if (pOrder.CombOffsetFlag_0 == (byte)(FutureTradeOffSet.Open))
                            {
                                //只有开仓涉及冻结资金
                                //交易失败，需要释放冻结掉的期货交易资金
                                accountMonitor.UpdateRiskFrozonAccount(pOrder.UserID, pOrder.InstrumentID, pOrder.VolumeTotalOriginal * (-1), pOrder.VolumeTotalOriginal * pOrder.LimitPrice * (-1), "F", pOrder.Direction.ToString());
                            }
                        }
                        break;
                    case 49:
                        {
                            //部分成交
                            TradeRecord.GetInstance().UpdateOrder(pOrder.VolumeTraded, Convert.ToInt16(pOrder.OrderRef), pOrder.OrderSysID, pOrder.StatusMsg, pOrder.OrderStatus, pOrder.VolumeTotal, pOrder.ExchangeID);
                        }
                        break;
                    case 51:
                        {
                            //未成交状态
                            TradeRecord.GetInstance().UpdateOrder(pOrder.VolumeTraded, Convert.ToInt16(pOrder.OrderRef), pOrder.OrderSysID, pOrder.StatusMsg, pOrder.OrderStatus, pOrder.VolumeTotal, pOrder.ExchangeID);
                        }
                        break;
                    case 53:
                        {
                            //已撤单状态
                            TradeRecord.GetInstance().UpdateOrder(pOrder.VolumeTraded, Convert.ToInt16(pOrder.OrderRef), pOrder.OrderSysID, pOrder.StatusMsg, pOrder.OrderStatus, pOrder.VolumeTotal, pOrder.ExchangeID);
                        }
                        break;
                    case 97:
                        {
                            //报单已经提交，创建委托记录
                            if (CONFIG.CheckOrderRefAvailiable(Convert.ToInt16(pOrder.OrderRef)))
                            {
                                // 重复返回不需要记库
                                TradeRecord.GetInstance().SubscribeOrder("1", pOrder.InstrumentID, Convert.ToChar(pOrder.Direction).ToString(), pOrder.VolumeTotalOriginal, Convert.ToDecimal(pOrder.LimitPrice), Convert.ToInt16(pOrder.OrderRef), pOrder.OrderStatus, pOrder.CombOffsetFlag_0);
                            }
                        }
                        break;
                    default:
                        {
                            //如果是没有见过的状态，则默认更新委托信息
                            TradeRecord.GetInstance().UpdateOrder(pOrder.VolumeTraded, Convert.ToInt16(pOrder.OrderRef), pOrder.OrderSysID, pOrder.StatusMsg, pOrder.OrderStatus, pOrder.VolumeTotal, pOrder.ExchangeID);
                        }
                        break;
                }
            }
        }

        public static void RtnTradeProc(object trade)
        {
            CThostFtdcTradeField_M pTrade = (CThostFtdcTradeField_M)trade;

            lock (syncRtnTradeObject)
            {
                TradeRecord.GetInstance().UpdateTrade(Convert.ToInt16(pTrade.OrderRef), pTrade.Volume, Convert.ToDecimal(pTrade.Price), pTrade.TradeID);
            }
        
        }

    }


    
}