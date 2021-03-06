﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MarketInfoSys
{
    /// <summary>
    /// 行情接收数据队列
    /// </summary>
    public class Queue_Data
    {
        private static Queue instance;

        public static bool Connected
        {
            get;
            set;
        }

        public static bool Suspend
        {
            get;
            set;
        }

        /// <summary>
        /// 获取队列的实例
        /// </summary>
        /// <returns>队列实例</returns>
        public static Queue GetQueue()
        {
            if (instance == null)
            {
                instance = new Queue();
            }

            return instance;
        }

        public void EnQueue(object obj)
        {
            if (Suspend == true)
                instance.Enqueue(obj);
            else return;
        }

        /// <summary>
        /// 获取该队列中的消息数量
        /// </summary>
        /// <returns>
        /// -1      队列未初始化或状态异常
        /// 其他    队列包含消息数量
        /// </returns>
        public static int GetQueueNumber()
        {
            if (instance != null)
            {
                return instance.Count;
            }
            else
            {
                return -1;
            }
        }
    }

    /// <summary>
    /// 模拟行情数据结构
    /// </summary>
    public class Sim_HQ_Struct
    {
        //代码
        public string CODE { get; set; }
        //类型
        public string TYPE { get; set; }
        //价格
        public decimal PRICE { get; set; }
    }
}