﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;
using managedSTY;
using marketinfosys;
using Stork_Future_TaoLi.Variables_Type;
using Stork_Future_TaoLi.Modulars;
using Newtonsoft.Json;
using System.Web.Helpers;

namespace Stork_Future_TaoLi.StrategyModule
{
    /// <summary>
    /// 开仓参数
    /// </summary>
    public class OPENPARA
    {
        /// <summary>
        /// 权重文件列表
        /// </summary>
        public Dictionary<String, double> WeightList { get; set; }

        /// <summary>
        /// 开仓点位
        /// </summary>
        public float OP { get; set; }

        /// <summary>
        /// 开仓指数类型
        /// </summary>
        public String INDEX { get; set; }
    }

    /// <summary>
    /// 平仓参数
    /// </summary>
    public class CLOSEPARA
    {
        /// <summary>
        /// 权重文件列表
        /// </summary>
        public Dictionary<String, double> WeightList { get; set; }

        /// <summary>
        /// 空头点位 dFutureSellPoint
        /// </summary>
        public float SP { set; get; }

        /// <summary>
        /// 股票成本 dStockOpenCost
        /// </summary>
        public decimal COE { get; set; }

        /// <summary>
        /// 股票分红  dStockBonus
        /// </summary>
        public decimal SD { get; set; }

        /// <summary>
        /// 股票配股 dGiftValue
        /// </summary>
        public decimal SA { get; set; }

        /// <summary>
        /// 预期收益 dExpectedGain
        /// </summary>
        public decimal PE { get; set; }

        /// <summary>
        /// 开仓基差 dOpenedPoint
        /// </summary> 
        public float BASIS { get; set; }

        /// <summary>
        /// 开仓指数类型 indexCode
        /// </summary>
        public String INDEX { get; set; }

        /// <summary>
        /// 预付费率 dShortCharge 
        /// </summary>
        public float Charge { get; set; }

    }

    public class StrategyWorker
    {

        #region public variables
        /// <summary>
        /// 策略实例ID
        /// </summary>
        public String StrategyInstanceID
        {
            get;
            set;
        }

        /// <summary>
        /// 使用用户
        /// </summary>
        public String User
        { get; set; }

        /// <summary>
        /// 开仓参数
        /// </summary>
        public OPENPARA open_para { get; set; }

        /// <summary>
        /// 平仓参数
        /// </summary>
        public CLOSEPARA close_para { get; set; }

        /// <summary>
        /// 交易类型 
        /// OPEN:开仓
        /// CLOSE：平仓
        /// </summary>
        public String Type { get; set; }

        /// <summary>
        /// 期货合约
        /// </summary>
        public String CT { get; set; }

        /// <summary>
        /// 手数
        /// </summary>
        public int HD { get; set; }

        /// <summary>
        /// 允许实例运行
        /// </summary>
        public bool bRun
        {
            get { return _brun; }
            set { _brun = value; }
        }
        private bool _brun = false;

        /// <summary>
        /// 允许实例交易
        /// </summary>
        public bool bAllow { get; set; }

        /// <summary>
        /// 股票交易量列表
        /// </summary>
        public Dictionary<string, int> LiStockOrder = new Dictionary<string,int>();

        /// <summary>
        /// 策略实例结束标志
        /// </summary>
        public  bool breaklabel = false;

        /// <summary>
        /// 获取订阅列表
        /// </summary>
        public List<string> SubscribeList
        {
            get { return _subscribe; }
        }

        /// <summary>
        /// 行情订阅内容修改标志
        /// </summary>
        public bool bSubscribeChange = true;

        /// <summary>
        /// 标记当前状态
        /// </summary>
        public int Status { get; set; }

        /// <summary>
        /// 线程内更新时间变量，上级系统抓取该变量判断系统运行状态
        /// </summary>
        public DateTime RunningMark { get; set; }

        #endregion

        #region private variables
        /// <summary>
        /// 定义线程
        /// </summary>
        private Thread excutedThread;
        private delegate void ThreadProc();

        /// <summary>
        /// 行情获取队列
        /// 行情模块发送行情，本线程收取
        /// </summary>
        private Queue _marketQueue = new Queue();

        /// <summary>
        /// 开仓库
        /// </summary>
        private Strategy_OPEN m_strategy_open = new Strategy_OPEN();

        /// <summary>
        /// 平仓库
        /// </summary>
        private Strategy_CLOSE m_strategy_close = new Strategy_CLOSE();

        /// <summary>
        /// 行情订阅信息
        /// </summary>
        private List<string> _subscribe = new List<string>();


        /// <summary>
        /// 同步锁 
        /// </summary>
        private object lockSync = new object();

        /// <summary>
        /// DLL 的接口
        /// </summary>
        //private strategyDLLInterface StrategyDLL = new strategyDLLInterface();

        /// <summary>
        /// 线程运行状态计时
        /// 如果线程运行超过24小时，则强制关闭。
        /// </summary>
        private DateTime RunningTime = new DateTime();

        private DateTime dt = new DateTime();
        #endregion

        #region public methods

        /// <summary>
        /// 启动策略执行线程
        /// </summary>
        public void RUN()
        {

            ThreadProc _thread = new ThreadProc(_threadProc);
            excutedThread = new Thread(new ThreadStart(_thread));

            //获取订阅列表
            List<managedsecurityindex> subscribelist = new List<managedsecurityindex>();

            if (Type == "OPEN")
            {
                //开仓
                open_args args = InitArgs(open_para.WeightList, LiStockOrder, CT, open_para.OP, open_para.INDEX, HD);

                m_strategy_open.init(args);

                 subscribelist = m_strategy_open.getsubscribelist().ToList();

            }
            else if (Type == "CLOSE")
            {
                //平仓
                //预付费率和期货开仓点
                close_args args = InitArgs(close_para.WeightList, LiStockOrder, CT, close_para.INDEX, HD, 
                    (double)close_para.SD, (double)close_para.SA, (double)close_para.COE, close_para.SP, (double)close_para.SD, (double)close_para.PE, close_para.Charge);

                m_strategy_close.init(args);

                subscribelist = m_strategy_close.getsubscribelist().ToList();
            }


            RunningTime = DateTime.Now;


            //获取订阅列表

            bool change = false;
            foreach (var item in subscribelist)
            {
                _subscribe.Add(item.cSecurity_code);
                change = true;
            }


            bSubscribeChange = change;


            excutedThread.Start();

            Thread.Sleep(100);
        }

        /// <summary>
        /// 向本地传送市场行情信息
        /// </summary>
        /// <param name="mInfo">市场行情信息</param>
        /// <returns>当前队列长度</returns>
        public int EnqueueMarketInfo(object mInfo)
        {
            if(_marketQueue != null)
            {
                _marketQueue.Enqueue(mInfo); 
            }

            return _marketQueue.Count;
        }

        /// <summary>
        /// 获取最新的行情内容
        /// </summary>
        /// <returns></returns>
        private object DeQueueInfo()
        {
            if (_marketQueue.Count == 0) return null;

            return _marketQueue.Dequeue();
        }

        /// <summary>
        /// 获取实例的行情队列
        /// </summary>
        /// <returns></returns>
        public Queue GetRefQueue()
        {
            return _marketQueue;
        }

        /// <summary>
        /// 获取当前策略订阅列表
        /// </summary>
        /// <returns></returns>
        public List<string> GetSubscribeList()
        {
            bSubscribeChange = false;
            return _subscribe;
        }

        public void SetSubscribeList(List<String> markets)
        {
            foreach(String s in markets)
            {
                _subscribe.Add(s);
            }
            bSubscribeChange = true;
        }

        /// <summary>
        /// 修改实例运行参数
        /// </summary>
        /// <param name="para">开仓参数</param>
        /// <param name="tradeList">开仓交易列表</param>
        public void UpdateBaseParas(object v)
        {
            lock(lockSync)
            {
                if(v is OPENMODIFY)
                {
                    OPENMODIFY value = (OPENMODIFY)v;
                    HD = value.HD;

                    Dictionary<string, int> oli = new Dictionary<string, int>();

                    foreach (var item in value.POSITION.Split('\n'))
                    {
                        if (item.Trim() == string.Empty) { continue; }
                        else
                        {
                            oli.Add(item.Split(';')[1] + item.Split(';')[0], Convert.ToInt32(item.Split(';')[2]));
                        }
                    }

                    LiStockOrder = oli;

                    open_para.OP = value.OP;

                    Dictionary<string, double> wli = new Dictionary<string, double>();

                    foreach (var item in value.weightli.Split('\n'))
                    {
                        if (item.Trim() == String.Empty) { continue; }
                        else
                        {
                            wli.Add(item.Split(';')[1] + item.Split(';')[0], Convert.ToDouble(item.Split(';')[2]));
                        }
                    }

                    open_para.WeightList = wli;
                }
                else
                {
                    CLOSEMODIFY value = (CLOSEMODIFY)v;
                    HD = value.HD;


                    Dictionary<string, double> wli = new Dictionary<string, double>();

                    foreach (var item in value.WEIGHT.Split('\n'))
                    {
                        if (item.Trim() == String.Empty) { continue; }
                        else
                        {
                            wli.Add(item.Split(';')[1] + item.Split(';')[0], Convert.ToDouble(item.Split(';')[2]));
                        }
                    }

                    Dictionary<string, int> oli = new Dictionary<string, int>();

                    foreach (var item in value.POSITION.Split('\n'))
                    {
                        if (item.Trim() == string.Empty) { continue; }
                        else
                        {
                            oli.Add(item.Split(';')[0], Convert.ToInt32(item.Split(';')[1]));
                        }
                    }

                    LiStockOrder = oli;

                    close_para.BASIS = value.OB;
                    


                    close_para.COE = value.COSTOFEQUITY;
                    close_para.SA = value.STOCKALLOTMENT;
                    close_para.SD = value.STOCKDIVIDENDS;
                    close_para.SP = value.SP;
                    close_para.PE = value.PROSPECTIVEARNINGS;

                    close_para.Charge = value.CHARGE;
                }
            }
        }

        #endregion

        #region private methods
        /// <summary>
        /// 线程工作函数
        /// </summary>
        private void _threadProc()
        {
            while (!bRun) {
                //标记最后扫描时间，交付上级判断
                RunningMark = DateTime.Now;

                //尚未运行的策略，直接丢弃队列中新的行情
                while (_marketQueue.Count > 0)
                {
                    DeQueueInfo();
                }
                //标记线程状态为正在空转
                Status = 1;
                
                Thread.Sleep(10); 

            }

            if (DBAccessLayer.DBEnable)
            {
                DBAccessLayer.UpdateStrategyStatusRecord(StrategyInstanceID, 1);
            }

            while (!breaklabel)
            { 


                /****
                 * 循环工作：
                 * 1. 更新行情信息
                 * 2. 计算中间参数
                 * 3. 判断运行条件
                 * 4. 生成交易列表
                 * ****/

                //标记最后扫描时间，交付上级判断
                RunningMark = DateTime.Now;

                if (Status == 1)
                {
                    if (DBAccessLayer.DBEnable)
                    {
                        DBAccessLayer.UpdateStrategyStatusRecord(StrategyInstanceID, 2);
                    }
                }
                if(bRun)
                {
                    //标记线程状态为正在运行
                    Status = 2;
                    Thread.Sleep(1);

                    //策略实例运算
                    List<managedMarketInforStruct> infos = new List<managedMarketInforStruct>();
                    List<MarketData> dataList = new List<MarketData>();

                    
                    while (_marketQueue.Count > 0)
                    {
                        MarketData d = (MarketData)DeQueueInfo();


                        if (d == null)
                        {
                            Thread.Sleep(10);
                            continue;
                        }

                        dataList.Add(d);
                    }

                    
                    
                    foreach(MarketData data in dataList)
                    {
                        
                        managedMarketInforStruct info = new managedMarketInforStruct();

                        info.dAskPrice = new double[10];
                        info.dAskVol = new double[10];
                        info.dBidPrice  = new double[10];
                        info.dBidVol = new double[10];

                        if (data.AskPrice != null)
                        {
                            for (int i = 0; i < data.AskPrice.Count(); i++)
                            {
                                info.dAskPrice[i] = Convert.ToDouble(data.AskPrice[i]) / 10000;
                                info.dAskVol[i] = Convert.ToDouble(data.AskVol[i]) ;
                                info.dBidPrice[i] = Convert.ToDouble(data.BidPrice[i]) / 10000;
                                info.dBidVol[i] = Convert.ToDouble(data.BidVol[i]) ;
                            }
                        }

                        managedsecurityindex index = new managedsecurityindex();
                        index.cSecurity_code = data.Code;
                        

                        info.msecurity = index;
                        info.security_name = data.Code;
                        info.nTime = data.Time / 1000;
                        info.nStatus = data.Status;
                        info.nPreClose = Convert.ToDouble(data.PreClose) / 10000;
                        info.dLastPrice = Convert.ToDouble(data.Match) / 10000;
                        info.dHighLimited = Convert.ToDouble(data.HighLimited) / 10000;
                        info.dLowLimited = Convert.ToDouble(data.LowLimited) /10000;
                        info.exchangeID = data.WindCode.Split('.')[1];

                        if (data.Status == 68)
                        {
                            info.bstoped = true;
                        }

                        switch(data.IOPV)
                        {
                            case 0:
                                {
                                    index.cSecuritytype = 115;
                                    break;
                                }
                            case 1:
                                {
                                    index.cSecuritytype = 102;
                                    break;
                                }
                            case 2:
                                {
                                    index.cSecuritytype = 105;
                                    break;
                                }
                            

                        }
                        info.LastUpdateTime = Int32.Parse(DateTime.Now.Hour.ToString().PadLeft(2, '0') + DateTime.Now.Minute.ToString().PadLeft(2, '0') + DateTime.Now.Second.ToString().PadLeft(2, '0'));

                        //MarketDelayCalculation.cal(data.Time, 3);
                        if (data.Status == 68 || data.Status == 66)
                        {
                            info.bstoped = true;
                        }
                        else
                        {
                            info.bstoped = false;
                        }

                        info.nInfotLag = info.LastUpdateTime - info.nTime ;
                        infos.Add(info);
                    }


                    
                    

                    if(infos.Count > 0)
                    {
                        if (Type == "OPEN")
                        {
                            DateTime d1 = DateTime.Now;

                            m_strategy_open.updateSecurityInfo(infos.ToArray(), infos.Count);

                            d1 = DateTime.Now;

                            m_strategy_open.calculateSimTradeStrikeAndDelta();


                        }
                        else
                        {
                            m_strategy_close.updateSecurityInfo(infos.ToArray(), infos.Count);
                            m_strategy_close.calculateSimTradeStrikeAndDelta();
                        }
                    }
                    else { continue; }
                    
                }

                

                if(bRun && bAllow)
                {
                    bool _reached = false;
                    if (Type == "OPEN")
                    {
                        _reached = m_strategy_open.isOpenPointReached();
                    }
                    else
                    {
                        _reached = m_strategy_close.isOpenPointReached();
                    }


                  //  _reached = true; //测试使用，注意删除

                    // 生成交易列表
                    if (_reached)
                    {


                        List<managedTraderorderstruct> ol = (Type == "OPEN") ? m_strategy_open.getTradeList().ToList() : m_strategy_close.getTradeList().ToList();



                        //交易列表送往交易线程下单（下单的线程，股票和期货是分开的）
                        List<TradeOrderStruct> orderli = new List<TradeOrderStruct>();

                        foreach (managedTraderorderstruct item in ol)
                        {
                            TradeOrderStruct order = new TradeOrderStruct();
                            order.cExhcnageID = item.cExchangeID;
                            order.cSecurityCode = item.cSecurity_code;
                            order.SecurityName = item.cSecurity_code;
                            order.nSecurityAmount = item.nSecurity_amount;
                            order.dOrderPrice = item.dOrderprice;
                            order.cTradeDirection = item.cTraderdirection.ToString();
                            order.cOffsetFlag = item.cOffsetFlag.ToString();
                            order.cOrderPriceType = item.cOrderPriceType.ToString();

                            order.cSecurityType = item.cSecuritytype.ToString();
                            order.cOrderLevel = item.cOrderlevel.ToString();
                            order.cOrderexecutedetail = item.cOrderexecutedetail.ToString();
                            order.belongStrategy = StrategyInstanceID;
                            order.OrderRef = REQUEST_ID.ApplyNewID();
                            order.cUser = User;

                            orderli.Add(order);

                            UserRequestMap.GetInstance().AddOrUpdate(order.OrderRef, User, (key, oldvalue) => oldvalue = User);
                        }

                        if (DBAccessLayer.DBEnable == true)
                        {
                            string json = Json.Encode(orderli);
                            DBAccessLayer.InsertORDERLIST(StrategyInstanceID, json);
                        }

                        //提交风控模块

                        //下单到交易预处理模块
                        queue_prd_trade.GetQueue().Enqueue((object)orderli);

                        if (DBAccessLayer.DBEnable)
                        {
                            //写入数据库，策略状态为已下单
                            DBAccessLayer.UpdateStrategyStatusRecord(StrategyInstanceID, 3);
                            DBAccessLayer.UpdateSGOPENStatus(StrategyInstanceID, 3);

                        }


                        // 列表只会生成一次
                        breaklabel = true;
                    }
                   
                }

                //获取中间显示参数
                //gettaderargs   getshowstatus

                if (Type == "OPEN")
                {
                    string status = m_strategy_open.getshowstatus();

                    List<String> statusLi = status.Split(' ').ToList();

                    status = string.Empty;
                    
                    foreach (string i in statusLi)
                    {
                        if (i.Trim() != string.Empty)
                        {
                            status += (i + "&");
                        }
                    }

                    PushStrategyInfo.Instance.UpdateStrategyInfo(StrategyInstanceID, status);
                }
                else
                {
                    string status = m_strategy_close.getshowstatus();

                    List<string> statusLi = status.Split(' ').ToList();

                    status = string.Empty;

                    foreach (string i in statusLi)
                    {
                        if (i.Trim() != string.Empty)
                        {
                            status += (i + "&");
                        }
                    }

                    PushStrategyInfo.Instance.UpdateStrategyInfo(StrategyInstanceID, status);
                }
                Thread.Sleep(1);
            }
        }


        /// <summary>
        /// 初始化开仓参数列表
        /// </summary>
        /// <param name="WeightList">权重列表</param>
        /// <param name="LiStockOrder">持仓列表</param>
        /// <param name="CT">期货</param>
        /// <param name="OP">开仓点位</param>
        /// <param name="INDEX">开仓指数</param>
        /// <param name="HD">手数</param>
        /// <returns>开仓参数实例</returns>
        open_args InitArgs(Dictionary<String, double> WeightList, Dictionary<string, int> LiStockOrder,
            String CT, double OP, string INDEX, int HD)
        {
            open_args args = new open_args();
            List<managedIndexWeights> weight = new List<managedIndexWeights>();
            List<managedstockposition> position = new List<managedstockposition>();

            string weightString = String.Empty;
            string positionString = String.Empty;
            int weightNum = 0;
            int positionNum = 0;

            foreach (var item in WeightList)
            {

                string code = item.Key.Substring(1);
                string type = item.Key.Substring(0, 1);
                double weightvalue = item.Value;

                weightString += (code + ";" + type + ";" + weightvalue.ToString() + "|");
                weightNum++;
            }

            weightString += "*";
            foreach (var item in LiStockOrder)
            {
                string code = item.Key.Substring(1);
                string type = item.Key.Substring(0, 1);
                int tradeVolume = item.Value;

                positionString += (code + ";" + type + ";" + tradeVolume.ToString() + "|");
                positionNum++;
            }

            positionString += "*";

            args.bTradingAllowed = false;

            args.contractCode = CT;
            args.dPositiveOpenDelta = OP;
            args.indexCode = INDEX;
            args.nHands = HD;
            args.WEIGHTLIST = weightString;
            args.POSITIONLIST = positionString;
            args.WEIGHTNUM = weightNum;
            args.POSITIONNUM = positionNum;
            
            return args;

        }

        /// <summary>
        /// 初始化平仓参数列表
        /// </summary>
        /// <param name="WeightList">权重列表</param>
        /// <param name="LiStockOrder">持仓列表</param>
        /// <param name="CT">期货</param>
        /// <param name="OP">开仓点位</param>
        /// <param name="INDEX">开仓指数</param>
        /// <param name="HD">手数</param>
        /// <returns>开仓参数实例</returns>
        /// <param name="dStockBonus">分红</param>
        /// <param name="dGiftValue">送股</param>
        /// <param name="dStockOpenCost">开仓成本</param>
        /// <param name="dFutureSellPoint">期货开仓点</param>
        /// <param name="dOpenedPoint">开仓基差点位</param>
        /// <param name="dExpectedGain">预期收益</param>
        /// <param name="dShortCharge">预估费率</param>
        /// <returns></returns>
        close_args InitArgs(Dictionary<String, double> WeightList, Dictionary<string, int> LiStockOrder,
            String CT, string INDEX, int HD, double dStockBonus, double dGiftValue, double dStockOpenCost, double dFutureSellPoint, double dOpenedPoint, double dExpectedGain, double dShortCharge)
        {
            close_args args = new close_args();

            //List<managedstockposition> position = new List<managedstockposition>();

            String POSITIONLIST = string.Empty;
            int positionNum = 0;

            foreach (var item in LiStockOrder)
            {
                managedstockposition s = new managedstockposition();
                managedsecurityindex si = new managedsecurityindex();

                string code = item.Key.Substring(1);
                string type = item.Key.Substring(0, 1);
                string count = item.Value.ToString();

                s.tradevolume = item.Value;

                POSITIONLIST += (code + ";" + type + ";" + count + "|");
                positionNum++;
            }

            POSITIONLIST += "*";

            args.bTradingAllowed = false;

            args.contractCode = CT;
            args.indexCode = (INDEX == null) ? "300" : INDEX;
            args.nHands = HD;
           

            args.dStockBonus = dStockBonus;
            args.dGiftValue = dGiftValue;
            args.dStockOpenCost = dStockOpenCost;
            args.dFutureSellPoint = dFutureSellPoint;
            args.dOpenedPoint = dOpenedPoint;
            args.dExpectedGain = dExpectedGain;
            args.dShortCharge = dShortCharge;
            args.positionNum = positionNum;
            args.bTradingAllowed = false;
            args.POSITION = POSITIONLIST;

            return args;

        }
        #endregion
    }
}