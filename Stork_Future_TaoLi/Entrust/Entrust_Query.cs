﻿using MCStockLib;
using Stork_Future_TaoLi.Queues;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;

namespace Stork_Future_TaoLi.Entrust
{
    public class Entrust_Query
    {

        #region 变量
        private static LogWirter log = new LogWirter();
        MCStockLib.managedStockClass _classTradeStock = new managedStockClass();
        #endregion

        #region 单例模式
        private static readonly Entrust_Query _instance = new Entrust_Query();
        public static Entrust_Query Instance{
            get{
                return _instance;
            }
        }
        private Entrust_Query()
        {
            log.EventSourceName = "交易预处理模块";
            log.EventLogType = System.Diagnostics.EventLogEntryType.Information;
            log.EventLogID = 65001;
        }
        #endregion

        #region 启动线程
        public void Run()
        {
            Thread mythread = new Thread(new ThreadStart(threadproc));
            mythread.Start();
        }
        #endregion

        #region 线程执行函数
        private void threadproc()
        {
            while (true) {
            
                if((DateTime.Now - GlobalHeartBeat.GetGlobalTime()).TotalMinutes > 5)
                {
                    log.LogEvent("由于供血不足，委托查询线程即将退出。");
                    break;
                }

                //单次循环最多查询100个交易的委托情况
                int maxCount = 100;
                

                while (maxCount > 0 && queue_query_entrust.GetQueueNumber() > 0)
                {
                    maxCount--;
                    managedQueryEntrustorderstruct item = (managedQueryEntrustorderstruct)queue_query_entrust.GetQueue().Dequeue();
                    string err = string.Empty;
                    List<managedEntrustreturnstruct> rets = _classTradeStock.QueryEntrust(item, err).ToList();

                    //标记委托已经处理完毕
                    bool isCompleted = true;

                    //将委托变动返回更新数据库
                    if (DBAccessLayer.DBEnable == true)
                    {
                        foreach(var rec in rets){

                            //此处判断，相应代码的委托是否完成
                            //此处逻辑需要待返回报文内容确认后修改
                            if (rec.nVolumeTotal != 0 && rec.withdraw_ammount != rec.nVolumeTotal)
                            {
                                isCompleted = false;
                            }

                            ThreadPool.QueueUserWorkItem(new WaitCallback(DBAccessLayer.UpdateERRecord), (object)(rec));
                        }
                    }

                    if(isCompleted == false)
                    {
                        //该委托尚未完成，重新入队列，等待下次再查询
                        queue_query_entrust.GetQueue().Enqueue((object)item);
                    }
                    else
                    {
                        //该委托已经完成，进入计算成本状态
                        //未完成的委托，是没有成本的

                    }
                }
            }
        }
        #endregion
    }
}