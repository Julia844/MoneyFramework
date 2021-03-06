﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;
using Stork_Future_TaoLi;
using Stork_Future_TaoLi.TradeModule;
using System.Threading;
using Stork_Future_TaoLi.Entrust;
using Stork_Future_TaoLi.Queues;
using Stork_Future_TaoLi.Hubs;
using Stork_Future_TaoLi.StrategyModule;


namespace Stork_Future_TaoLi
{
    // 注意: 有关启用 IIS6 或 IIS7 经典模式的说明，
    // 请访问 http://go.microsoft.com/?LinkId=9394801

    public class MvcApplication : System.Web.HttpApplication
    {
        protected void Application_Start()
        {
            AreaRegistration.RegisterAllAreas();

            WebApiConfig.Register(GlobalConfiguration.Configuration);
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);
            AuthConfig.RegisterAuth();

            //模块初始化工作
            //ListCreate.Main();

            DBExamination.CheckDB();

            PreTradeModule.getInstance().Run();

            StockTradeThread.Main();

            FutureMonitor FM = new FutureMonitor();
            FM.Main();

            StrategyMonitorClass strategyMonitor = new StrategyMonitorClass();
            strategyMonitor.Run();

            MarketInfo marketInfo = new MarketInfo();
            marketInfo.Run();

            TestClass t = new TestClass();
            t.Run();

            UpdateMarketPanel MarketMonitor = new UpdateMarketPanel();
            MarketMonitor.Run();

            RefundTrade.Main();

            Entrust_Query.Instance.Run();

            ThreadHeartBeatControl.Run();

            SystemMonitorClass.getInstance().Run();

            riskmonitor.Init();

            accountMonitor.RUN();
            BatchTrade_MarketReciver.Run();

            AuthorizedStrategy.RUN();

            Thread.Sleep(3000);
           
        }
    }

    /// <summary>
    /// Global 心跳发射线程
    /// </summary>
    public class ThreadHeartBeatControl
    {
        private static Thread HeartThread = new Thread(new ThreadStart(threadProc));

        public static void Run()
        {
            HeartThread.Start();
            Thread.Sleep(1000);
        }

        private static void threadProc()
        {
            DateTime lastmessage = DateTime.Now;


            while(true)
            {
                Thread.Sleep(1000);
                if (DateTime.Now.Minute % 2 == 0)
                {
                    GlobalHeartBeat.SetGlobalTime();
                }

                if (lastmessage.Second != DateTime.Now.Second)
                {
                    KeyValuePair<string, object> message = new KeyValuePair<string, object>("THREAD_HEARTBEAT", (object)true);
                    queue_system_status.GetQueue().Enqueue((object)message);
                    lastmessage = DateTime.Now;
                }
            }
        }
    }
}