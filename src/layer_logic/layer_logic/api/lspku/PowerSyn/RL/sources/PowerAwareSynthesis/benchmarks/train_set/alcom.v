// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:38 2022

module alcom  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    \v15.0 , \v15.1 , \v15.2 , \v15.3 , \v15.4 , \v15.5 , \v15.6 , \v15.7 ,
    \v15.8 , \v15.9 , \v15.10 , \v15.11 , \v15.12 , \v15.13 , \v15.14 ,
    \v15.15 , \v15.16 , \v15.17 , \v15.18 , \v15.19 , \v15.20 , \v15.21 ,
    \v15.22 , \v15.23 , \v15.24 , \v15.25 , \v15.26 , \v15.27 , \v15.28 ,
    \v15.29 , \v15.30 , \v15.31 , \v15.32 , \v15.33 , \v15.34 , \v15.35 ,
    \v15.36 , \v15.37   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14;
  output \v15.0 , \v15.1 , \v15.2 , \v15.3 , \v15.4 , \v15.5 , \v15.6 ,
    \v15.7 , \v15.8 , \v15.9 , \v15.10 , \v15.11 , \v15.12 , \v15.13 ,
    \v15.14 , \v15.15 , \v15.16 , \v15.17 , \v15.18 , \v15.19 , \v15.20 ,
    \v15.21 , \v15.22 , \v15.23 , \v15.24 , \v15.25 , \v15.26 , \v15.27 ,
    \v15.28 , \v15.29 , \v15.30 , \v15.31 , \v15.32 , \v15.33 , \v15.34 ,
    \v15.35 , \v15.36 , \v15.37 ;
  wire new_n54_, new_n55_, new_n57_, new_n59_, new_n60_, new_n61_, new_n62_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n72_, new_n73_, new_n74_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n85_, new_n86_, new_n89_,
    new_n92_, new_n93_, new_n96_, new_n98_, new_n99_, new_n102_, new_n105_,
    new_n106_, new_n109_, new_n112_, new_n113_, new_n114_, new_n117_,
    new_n120_, new_n121_, new_n124_, new_n127_, new_n128_, new_n129_,
    new_n132_, new_n135_, new_n136_, new_n140_;
  assign new_n54_ = v3 & ~v4;
  assign new_n55_ = ~v1 & new_n54_;
  assign \v15.0  = v0 & new_n55_;
  assign new_n57_ = ~v2 & new_n54_;
  assign \v15.1  = v1 & new_n57_;
  assign new_n59_ = v0 & ~v1;
  assign new_n60_ = v0 & ~new_n59_;
  assign new_n61_ = ~v4 & ~new_n60_;
  assign new_n62_ = v3 & new_n61_;
  assign \v15.2  = v2 & new_n62_;
  assign new_n64_ = v5 & v6;
  assign new_n65_ = v4 & ~new_n64_;
  assign new_n66_ = v0 & ~new_n65_;
  assign new_n67_ = ~v1 & ~v3;
  assign new_n68_ = ~v1 & ~new_n67_;
  assign new_n69_ = ~v4 & ~new_n68_;
  assign new_n70_ = ~v0 & new_n69_;
  assign \v15.3  = new_n66_ | new_n70_;
  assign new_n72_ = v0 & v1;
  assign new_n73_ = ~v2 & new_n72_;
  assign new_n74_ = v3 & new_n73_;
  assign \v15.4  = ~v4 & new_n74_;
  assign new_n76_ = ~v0 & ~v1;
  assign new_n77_ = ~new_n72_ & ~new_n76_;
  assign new_n78_ = ~v2 & ~v3;
  assign new_n79_ = ~v2 & ~new_n78_;
  assign new_n80_ = ~new_n77_ & ~new_n79_;
  assign new_n81_ = ~v0 & v1;
  assign new_n82_ = ~new_n59_ & ~new_n81_;
  assign new_n83_ = ~new_n80_ & new_n82_;
  assign \v15.5  = ~v4 & ~new_n83_;
  assign new_n85_ = ~v7 & ~v8;
  assign new_n86_ = ~v9 & new_n85_;
  assign \v15.6  = ~v10 & new_n86_;
  assign \v15.7  = v10 & new_n86_;
  assign new_n89_ = v9 & new_n85_;
  assign \v15.8  = ~v10 & new_n89_;
  assign \v15.9  = v10 & new_n89_;
  assign new_n92_ = ~v7 & v8;
  assign new_n93_ = ~v9 & new_n92_;
  assign \v15.10  = v10 & new_n93_;
  assign \v15.11  = ~v10 & new_n93_;
  assign new_n96_ = v9 & new_n92_;
  assign \v15.12  = v10 & new_n96_;
  assign new_n98_ = v7 & ~v8;
  assign new_n99_ = ~v9 & new_n98_;
  assign \v15.13  = ~v10 & new_n99_;
  assign \v15.14  = v10 & new_n99_;
  assign new_n102_ = v9 & new_n98_;
  assign \v15.15  = ~v10 & new_n102_;
  assign \v15.16  = v10 & new_n102_;
  assign new_n105_ = v7 & v8;
  assign new_n106_ = ~v9 & new_n105_;
  assign \v15.17  = ~v10 & new_n106_;
  assign \v15.18  = v10 & new_n106_;
  assign new_n109_ = v9 & new_n105_;
  assign \v15.19  = ~v10 & new_n109_;
  assign \v15.20  = v10 & new_n109_;
  assign new_n112_ = v3 & ~v11;
  assign new_n113_ = ~v12 & new_n112_;
  assign new_n114_ = ~v13 & new_n113_;
  assign \v15.21  = ~v14 & new_n114_;
  assign \v15.22  = v14 & new_n114_;
  assign new_n117_ = v13 & new_n113_;
  assign \v15.23  = ~v14 & new_n117_;
  assign \v15.24  = v14 & new_n117_;
  assign new_n120_ = v12 & new_n112_;
  assign new_n121_ = ~v13 & new_n120_;
  assign \v15.25  = ~v14 & new_n121_;
  assign \v15.26  = v14 & new_n121_;
  assign new_n124_ = v13 & new_n120_;
  assign \v15.27  = ~v14 & new_n124_;
  assign \v15.28  = v14 & new_n124_;
  assign new_n127_ = v3 & v11;
  assign new_n128_ = ~v12 & new_n127_;
  assign new_n129_ = ~v13 & new_n128_;
  assign \v15.29  = ~v14 & new_n129_;
  assign \v15.30  = v14 & new_n129_;
  assign new_n132_ = v13 & new_n128_;
  assign \v15.31  = ~v14 & new_n132_;
  assign \v15.32  = v14 & new_n132_;
  assign new_n135_ = v12 & new_n127_;
  assign new_n136_ = ~v13 & new_n135_;
  assign \v15.33  = ~v14 & new_n136_;
  assign \v15.34  = ~v10 & new_n96_;
  assign \v15.35  = v14 & new_n136_;
  assign new_n140_ = v13 & new_n135_;
  assign \v15.36  = ~v14 & new_n140_;
  assign \v15.37  = v14 & new_n140_;
endmodule


