//------------------------------------------------------------------------------
// <auto-generated>
//    This code was generated from a template.
//
//    Manual changes to this file may cause unexpected behavior in your application.
//    Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Stork_Future_TaoLi.Database
{
    using System;
    using System.Collections.Generic;
    
    public partial class ER_TAOLI_TABLE
    {
        public System.Guid ER_GUID { get; set; }
        public string ER_ID { get; set; }
        public string ER_STRATEGY { get; set; }
        public string ER_CODE { get; set; }
        public string ER_ORDER_EXCHANGE_ID { get; set; }
        public string ER_ORDER_STATUS { get; set; }
        public string ER_ORDER_TYPE { get; set; }
        public Nullable<int> ER_VOLUME_TOTAL_ORIGINAL { get; set; }
        public Nullable<int> ER_VOLUME_TRADED { get; set; }
        public Nullable<int> ER_VOLUME_REMAIN { get; set; }
        public Nullable<int> ER_WITHDRAW_AMOUNT { get; set; }
        public Nullable<double> ER_FROZEN_MONEY { get; set; }
        public Nullable<double> ER_FROZEN_AMOUNT { get; set; }
        public Nullable<System.DateTime> ER_DATE { get; set; }
        public Nullable<System.DateTime> ER_ORDER_TIME { get; set; }
        public Nullable<System.DateTime> ER_CANCEL_TIME { get; set; }
        public Nullable<bool> ER_COMPLETED { get; set; }
        public Nullable<int> ER_DIRECTION { get; set; }
        public string ER_ORDER_REF { get; set; }
        public string ER_USER { get; set; }
        public string ER_OFFSETFLAG { get; set; }
    }
}
