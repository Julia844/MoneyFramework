﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Threading;
using System.Threading.Tasks;
using System.Collections;
using marketinfosys;
using Stork_Future_TaoLi.Queues;



namespace Stork_Future_TaoLi
{
    public class MarketInfo
    {
        private static LogWirter log = new LogWirter();

        private static Dictionary<String, Queue> refStrategyQueue = new Dictionary<String, Queue>();
        private static object lockSync = new object();



        private Dictionary<String, List<String>> subscribeList = new Dictionary<string, List<String>>();
        private Hashtable StockTable = new Hashtable();
        private static Queue MarketChangeQueue = new Queue();

        /// <summary>
        /// 启动行情获取新示例
        /// </summary>
        public void Run()
        {

            
            Thread excuteCalDelay = new Thread(new ThreadStart(ThreadCalDelay));
            excuteCalDelay.Start();

            List<Thread> excuteThread3 = new List<Thread>();
            for (int i = 0; i < 20; i++)
            {
                excuteThread3.Add(new Thread(new ThreadStart(ThreadProc3)));
                excuteThread3[i].Start();
            }

            List<Thread> excuteThread2 = new List<Thread>();
            for (int i = 0; i < 20; i++)
            {
                excuteThread2.Add(new Thread(new ThreadStart(TreadProc2)));
                excuteThread2[i].Start();
            }

            List<Thread> excuteThread = new List<Thread>();
            for (int i = 0; i < 20; i++)
            {
                excuteThread.Add(new Thread(new ThreadStart(ThreadProc)));
                excuteThread[i].Start();
            }

            

            
            Thread.Sleep(1000);
        }

        /// <summary>
        /// 设置策略实例行情消息队列的关系
        /// </summary>
        /// <param name="para"></param>
        public static void SetStrategyQueue(KeyValuePair<String, Queue> para)
        {
            lock (lockSync)
            {
                if (refStrategyQueue.ContainsKey(para.Key))
                {
                    refStrategyQueue.Remove(para.Key);
                }
                else
                {
                    refStrategyQueue.Add(para.Key, para.Value);
                }
            }
        }

        public MarketInfo()
        {
            log.EventSourceName = "行情获取模块";
            log.EventLogType = System.Diagnostics.EventLogEntryType.Information;
            log.EventLogID = 63003;
        }

        /// <summary>
        /// 更新本地行情订阅列表
        /// </summary>
        private void updateNewSubscribeList()
        {
            if (MapMarketStratgy.bSubscribeListChangeLabel)
            {
                subscribeList = MapMarketStratgy.GetMapSS();

                Dictionary<String, List<String>> dic = MapMarketStratgy.GetMapMS();
                bool mark = true;
                while (mark)
                    try
                    {
                        foreach (KeyValuePair<String, List<String>> pair in dic)
                        {
                            if (!subscribeList.Keys.Contains(pair.Key))
                            {
                                subscribeList.Add(pair.Key, new List<string>());
                            }
                            foreach (String module in pair.Value)
                            {
                                if (!subscribeList[pair.Key].Contains(module))
                                {
                                    subscribeList[pair.Key].Add(module);
                                }
                            }
                        }

                        mark = false;
                    }
                    catch (Exception ex)
                    {
                        GlobalErrorLog.LogInstance.LogEvent(ex.ToString());
                    }

                MapMarketStratgy.bSubscribeListChangeLabel = false;
            }
        }

        private void ThreadProc()
        {
            //本地股市信息存入stockTable 中
            StockInfoClient client = new StockInfoClient();

            KeyValuePair<string, object> message1 = new KeyValuePair<string, object>("THREAD_MARKET", (object)true);
            queue_system_status.GetQueue().Enqueue((object)message1);
            DateTime lastmessage = DateTime.Now;

            MarketData info = new MarketData();

            while (true)
            {
                if (DateTime.Now.Second != lastmessage.Second)
                {
                    KeyValuePair<string, object> message3 = new KeyValuePair<string, object>("THREAD_MARKET", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message3);
                    lastmessage = DateTime.Now;

                    Thread.Sleep(1);
                }

                if ((DateTime.Now - GlobalHeartBeat.GetGlobalTime()).TotalMinutes > 10)
                {
                    log.LogEvent("本模块供血不足，线程即将死亡");
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_MARKET", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    break;
                }



                int count = 0;
                while (count < 100)
                {
                    try { info = client.DeQueueInfo(); }
                    catch { break; }
                    
                    if (info == null)
                    {
                        
                        break;
                    }
                    else
                    {
                        lock (Queue_Operation_Data.GetQueue()) { Queue_Operation_Data.GetQueue().Enqueue((object)info); }
                    }
                    count++;
                }


            }
        }

        private void TreadProc2()
        {
            //发现行情有变动，更新本地股市
            DateTime lastmessage = DateTime.Now;

           
            while (true)
            {
                Thread.Sleep(1);

               

                if (DateTime.Now.Second != lastmessage.Second)
                {
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_MARKET_2", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    lastmessage = DateTime.Now;

                    //更新本地行情列表,每秒一次
                    updateNewSubscribeList();
                    Thread.Sleep(1);
                }

                if ((DateTime.Now - GlobalHeartBeat.GetGlobalTime()).TotalMinutes > 10)
                {
                    log.LogEvent("本模块供血不足，线程即将死亡");
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_MARKET", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    break;
                }


                MarketData info = null;

                lock (Queue_Operation_Data.GetQueue())
                {
                    if (Queue_Operation_Data.GetQueueNumber() > 0)
                    {
                        info = (MarketData)Queue_Operation_Data.GetQueue().Dequeue();
                    }
                }

                if (info == null)
                {
                    continue;
                }

                string key = info.Code;

                if (key.Contains("."))
                {
                    key = key.Split('.')[0];
                }

                lock (MarketPrice.market)
                {
                    if (MarketPrice.market.ContainsKey(info.Code))
                    {
                        MarketPrice.market[info.Code] = info.Match;
                    }
                    else
                    {
                        MarketPrice.market.Add(info.Code, info.Match);
                    }
                }

                if (DateTime.Now.Second % 2 == 0)
                {
                    lock (Queue_Cal_Market.SyncLock)
                    {
                        Queue_Cal_Market.GetQueue().Enqueue((object)info.Time);
                    }
                }

                lock (Queue_Operation_Data_2.SyncLock) { Queue_Operation_Data_2.GetQueue().Enqueue((object)info); }
            }
        }

        private void ThreadProc3()
        {
            DateTime lastmessage = DateTime.Now;
            MarketData info = new MarketData();

            while (true)
            {

                if (DateTime.Now.Second != lastmessage.Second)
                {
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_MARKET_3", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    lastmessage = DateTime.Now;

                    Thread.Sleep(1);
                }

                if ((DateTime.Now - GlobalHeartBeat.GetGlobalTime()).TotalMinutes > 10)
                {
                    log.LogEvent("本模块供血不足，线程即将死亡");
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_MARKET", (object)false);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    break;
                }

                Thread.Sleep(1);

                if (Queue_Operation_Data_2.GetQueueNumber() > 0){
                    try
                    {
                        lock (Queue_Operation_Data_2.SyncLock)
                            info = (MarketData)Queue_Operation_Data_2.GetQueue().Dequeue();
                    }
                    catch
                    {
                        info = null;
                    }
                }

                if (info == null || info.Code == null)
                {
                    continue;
                }

                lock (StockTable)
                {
                    if (StockTable.ContainsKey(info.Code))
                    {
                        StockTable.Remove(info.Code);
                    }
                    StockTable.Add(info.Code, info);
                }

                if (!subscribeList.Keys.Contains(info.Code))
                {
                    try
                    {
                        subscribeList.Add(info.Code, new List<String>());
                    }
                    catch
                    {
                        continue;
                    }
                }

                if (subscribeList.Keys.Contains(info.Code))
                {
                    //如果没有实例订阅过该股票，就不用管了
                    List<String> _relatedStrategy = subscribeList[info.Code];

                    foreach (String strategy in _relatedStrategy)
                    {
                        if (refStrategyQueue.Keys.Contains(strategy))
                        {
                            try
                            {
                                refStrategyQueue[strategy].Enqueue((object)info);
                            }
                            catch
                            {
                                break;
                            }
                        }
                        else
                        {
                            //如果发现策略实例包含工作列表，却不包含消息队列，则应该报错。
                            continue;
                        }
                    }
                }
            }
        }

        /// <summary>
        /// 计算延迟的线程
        /// </summary>
        private void ThreadCalDelay()
        {
            DateTime dt = DateTime.Now;
            int time = 0;
            while (true)
            {
                if (DateTime.Now.Second % 3 == 0 && dt.Second != DateTime.Now.Second)
                {
                    Int32 len1 = Queue_Operation_Data.GetQueueNumber();
                    Int32 len2 = Queue_Operation_Data_2.GetQueueNumber();
                    GlobalErrorLog.LogInstance.LogEvent("队列空间：\r\n" + "Queue_Operation_Data：" + len1.ToString() + "\r\nQueue_Operation_Data_2：" + len2.ToString());
                    dt = DateTime.Now;
                }

                if(Queue_Cal_Market.GetQueueNumber() > 0)
                {
                    lock (Queue_Cal_Market.SyncLock)
                    {
                        object obj = Queue_Cal_Market.GetQueue().Dequeue();
                        time = Convert.ToInt32(obj);
                    }
                    
                }
                else
                {
                    continue;
                }
                
                MarketDelayCalculation.cal(time);
            }
        }
    }

   


    /// <summary>
    /// 股票代码与策略映射关系表
    /// 市场信息更新线程和每个策略执行线程均可访问
    /// </summary>
    public class MapMarketStratgy
    {
        //访问锁定对象
        public static object syncRoot = new object();

        //股票代码与注册该代码的行情映射表
        //public static List<KeyValuePair<String, List<String>>> MapSS = new List<KeyValuePair<string, List<string>>>();

        /// <summary>
        /// 策略<--->证券集 关系字典
        /// </summary>
        public static Dictionary<String, List<String>> MapSS = new Dictionary<String, List<String>>();
        /// <summary>
        /// 行情需求模块<--->证券集关系字典
        /// </summary>
        public static Dictionary<String, List<String>> MapMS = new Dictionary<string, List<string>>();
        public static bool bSubscribeListChangeLabel = false;

        /// <summary>
        /// 获取代码注册的策略
        /// </summary>
        /// <param name="code">代码</param>
        /// <returns>策略编号列表</returns>
        public static List<String> GetRegeditStrategy(String code)
        {

            var t = (from item in MapSS where item.Key == code select item.Value);

            if (t.Count() != 0)
            {
                return (List<String>)t;
            }
            else
            {
                return null;
            }

        }

        /// <summary>
        /// 获取策略所注册的代码
        /// </summary>
        /// <param name="Strategy">策略号</param>
        /// <returns>注册代码编号列表</returns>
        public static List<String> GetRegeditCode(String Strategy)
        {
            lock (syncRoot)
            {
                var t = (from item in MapSS where item.Value.Contains(Strategy) select item.Key);

                if (t.Count() != 0)
                {
                    return (List<String>)t;
                }
                else
                {
                    return null;
                }
            }
        }

        /// <summary>
        /// 输入策略及策略包含代码
        /// 包括添加新的代码和删除老的代码
        /// </summary>
        /// <param name="Strategy">策略名</param>
        /// <param name="Codes">策略包含代码</param>
        public static void SetRegeditStrategy(String Strategy, List<String> Codes)
        {
            //获取已经注册过的代码
            List<String> existRegedit = GetRegeditCode(Strategy);

            lock (syncRoot)
            {
                //获得尚未注册代码
                List<String> ToRegeditCodes = (from item in Codes where existRegedit.Contains(item) == false select item).ToList();

                foreach (String code in ToRegeditCodes)
                {
                    MapSS[code].Add(Strategy);
                }

                List<String> RemoveRegeditCodes = (from item in existRegedit where Codes.Contains(item) == false select item).ToList();

                foreach(String code in RemoveRegeditCodes)
                {
                    MapSS[code].Remove(Strategy);
                }
            }
        }

        /// <summary>
        /// 更新策略订阅列表
        /// </summary>
        /// <param name="para"></param>
        public static void SetMapSS(Dictionary<String,List<String>> para)
        {
            lock(syncRoot)
            {
                MapSS = para;
                bSubscribeListChangeLabel = true;
            }
        }

        /// <summary>
        /// 更新模块订阅列表
        /// </summary>
        /// <param name="module"></param>
        /// <param name="codelist"></param>
        public static void SetMapMS(String module ,List<String> codelist)
        {
            lock(syncRoot)
            {
                foreach(string code in codelist)
                {
                    if(MapMS.Keys.Contains(code))
                    {
                        if(!MapMS[code].Contains(module))
                        {
                            MapMS[code].Add(module);
                        }
                    }
                    else
                    {
                        MapMS.Add(code, new List<string>());
                        MapMS[code].Add(module);
                    }
                }

                bSubscribeListChangeLabel = true;
            }
        }

        /// <summary>
        /// 获取策略订阅列表
        /// 该函数由行情模块调用
        /// </summary>
        /// <returns></returns>
        public static Dictionary<String,List<String>> GetMapSS()
        {
            return MapSS;
        }

        /// <summary>
        /// 获取模块订阅列表
        /// 该函数由行情模块调用
        /// </summary>
        /// <returns></returns>
        public static Dictionary<String , List<String>> GetMapMS()
        {
            return MapMS;
        }
    }
}