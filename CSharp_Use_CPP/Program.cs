﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CSharp_Use_CPP
{
    class Program
    {
        static void Main(string[] args)
        {
            #region 之前的测试
            //StockTradeAPIBrage _StockTradeDLLApi = new StockTradeAPIBrage();
          
            //unsafe
            //{
            //    Logininfor vlogin = new Logininfor();

            //    /* ToDu ***********/
            //    /* 登陆参数初始化 */

            //    string str = "Hello Cheng";

            //    byte[] bytes = Encoding.ASCII.GetBytes(str);
            //    sbyte[] sbytes = new sbyte[bytes.Length];

            //    for (int i = 0; i < bytes.Length; i++)
            //    {
            //        if (bytes[i] > 127)
            //            sbytes[i] = (sbyte)(bytes[i] - 256);
            //        else
            //            sbytes[i] = (sbyte)bytes[i];
            //    }
            //    StringBuilder sb = new StringBuilder();

            //    fixed (sbyte* pError = sbytes)
            //    {
            //        _StockTradeDLLApi.TestApi(pError,vlogin);

            //        //for (int i = 0; pError[i] != '\0'; i++)
            //        //{
                        
            //        //}


            //        int i = 0;
            //        StringBuilder str1 = new StringBuilder();
            //        StringBuilder str2 = new StringBuilder();

            //        while (Convert.ToChar(pError[i]) != '\0')
            //        {
            //            i++;
            //            str1.Append(Convert.ToChar(pError[i]));
            //        }

            //        i = 0;

            //        while (Convert.ToChar(vlogin.BROKER_ID[i]) != '\0')
            //        {
            //            i++;
            //            str2.Append(Convert.ToChar(vlogin.BROKER_ID[i]));
            //        }


            //        Console.WriteLine(str1);
            //        Console.WriteLine(str2);
              
                    

            //    }

            //    Console.ReadLine();
            #endregion


            MCStockLib.managedStockClass stockLib = new MCStockLib.managedStockClass();

            Logininfor login;
            
            
            //stockLib.Init(




        }
        


    }
}
