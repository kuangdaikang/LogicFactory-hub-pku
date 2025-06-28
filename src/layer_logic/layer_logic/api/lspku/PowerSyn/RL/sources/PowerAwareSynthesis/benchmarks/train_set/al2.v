// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:31 2022

module al2  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    \v16.0 , \v16.1 , \v16.2 , \v16.3 , \v16.4 , \v16.5 , \v16.6 , \v16.7 ,
    \v16.8 , \v16.9 , \v16.10 , \v16.11 , \v16.12 , \v16.13 , \v16.14 ,
    \v16.15 , \v16.16 , \v16.17 , \v16.18 , \v16.19 , \v16.20 , \v16.21 ,
    \v16.22 , \v16.23 , \v16.24 , \v16.25 , \v16.26 , \v16.27 , \v16.28 ,
    \v16.29 , \v16.30 , \v16.31 , \v16.32 , \v16.33 , \v16.34 , \v16.35 ,
    \v16.36 , \v16.37 , \v16.38 , \v16.39 , \v16.40 , \v16.41 , \v16.42 ,
    \v16.43 , \v16.44 , \v16.45 , \v16.46   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15;
  output \v16.0 , \v16.1 , \v16.2 , \v16.3 , \v16.4 , \v16.5 , \v16.6 ,
    \v16.7 , \v16.8 , \v16.9 , \v16.10 , \v16.11 , \v16.12 , \v16.13 ,
    \v16.14 , \v16.15 , \v16.16 , \v16.17 , \v16.18 , \v16.19 , \v16.20 ,
    \v16.21 , \v16.22 , \v16.23 , \v16.24 , \v16.25 , \v16.26 , \v16.27 ,
    \v16.28 , \v16.29 , \v16.30 , \v16.31 , \v16.32 , \v16.33 , \v16.34 ,
    \v16.35 , \v16.36 , \v16.37 , \v16.38 , \v16.39 , \v16.40 , \v16.41 ,
    \v16.42 , \v16.43 , \v16.44 , \v16.45 , \v16.46 ;
  wire new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n75_, new_n76_, new_n77_, new_n79_, new_n80_,
    new_n82_, new_n83_, new_n85_, new_n87_, new_n89_, new_n91_, new_n92_,
    new_n93_, new_n95_, new_n96_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n104_, new_n105_, new_n106_, new_n107_, new_n108_,
    new_n109_, new_n110_, new_n111_, new_n112_, new_n114_, new_n115_,
    new_n116_, new_n117_, new_n119_, new_n120_, new_n121_, new_n122_,
    new_n123_, new_n125_, new_n126_, new_n129_, new_n132_, new_n133_,
    new_n136_, new_n139_, new_n140_, new_n143_, new_n146_, new_n147_,
    new_n150_, new_n153_, new_n154_, new_n155_, new_n157_, new_n158_,
    new_n159_, new_n161_, new_n162_, new_n164_, new_n165_, new_n167_,
    new_n169_, new_n171_, new_n173_;
  assign new_n64_ = ~v4 & ~v5;
  assign new_n65_ = ~v3 & ~new_n64_;
  assign new_n66_ = ~v2 & new_n65_;
  assign new_n67_ = ~v1 & new_n66_;
  assign new_n68_ = ~v0 & new_n67_;
  assign \v16.0  = v6 | new_n68_;
  assign new_n70_ = ~v6 & ~new_n64_;
  assign new_n71_ = v3 & new_n70_;
  assign new_n72_ = ~v2 & new_n71_;
  assign new_n73_ = ~v1 & new_n72_;
  assign \v16.1  = ~v0 & new_n73_;
  assign new_n75_ = ~v3 & new_n70_;
  assign new_n76_ = v2 & new_n75_;
  assign new_n77_ = ~v1 & new_n76_;
  assign \v16.2  = ~v0 & new_n77_;
  assign new_n79_ = v2 & new_n71_;
  assign new_n80_ = ~v1 & new_n79_;
  assign \v16.3  = ~v0 & new_n80_;
  assign new_n82_ = ~v2 & new_n75_;
  assign new_n83_ = v1 & new_n82_;
  assign \v16.4  = ~v0 & new_n83_;
  assign new_n85_ = v1 & new_n72_;
  assign \v16.5  = ~v0 & new_n85_;
  assign new_n87_ = v1 & new_n76_;
  assign \v16.6  = ~v0 & new_n87_;
  assign new_n89_ = v1 & new_n79_;
  assign \v16.7  = ~v0 & new_n89_;
  assign new_n91_ = v7 & ~v8;
  assign new_n92_ = ~v9 & new_n91_;
  assign new_n93_ = ~v10 & new_n92_;
  assign \v16.8  = v11 & new_n93_;
  assign new_n95_ = ~v2 & new_n70_;
  assign new_n96_ = v1 & new_n95_;
  assign \v16.9  = ~v0 & new_n96_;
  assign new_n98_ = v1 & ~v3;
  assign new_n99_ = v1 & ~new_n98_;
  assign new_n100_ = ~new_n64_ & ~new_n99_;
  assign new_n101_ = ~v6 & new_n100_;
  assign new_n102_ = v2 & new_n101_;
  assign \v16.10  = ~v0 & new_n102_;
  assign new_n104_ = ~v1 & v2;
  assign new_n105_ = v1 & ~v2;
  assign new_n106_ = ~new_n104_ & ~new_n105_;
  assign new_n107_ = ~new_n64_ & ~new_n106_;
  assign new_n108_ = ~v6 & new_n107_;
  assign new_n109_ = ~v0 & new_n108_;
  assign new_n110_ = ~v10 & v11;
  assign new_n111_ = ~v9 & new_n110_;
  assign new_n112_ = new_n91_ & new_n111_;
  assign \v16.11  = new_n109_ | new_n112_;
  assign new_n114_ = v1 & ~new_n105_;
  assign new_n115_ = ~new_n64_ & ~new_n114_;
  assign new_n116_ = ~v6 & new_n115_;
  assign new_n117_ = v3 & new_n116_;
  assign \v16.12  = ~v0 & new_n117_;
  assign new_n119_ = ~v2 & v3;
  assign new_n120_ = ~v1 & new_n119_;
  assign new_n121_ = new_n106_ & ~new_n120_;
  assign new_n122_ = ~new_n64_ & ~new_n121_;
  assign new_n123_ = ~v6 & new_n122_;
  assign \v16.13  = ~v0 & new_n123_;
  assign new_n125_ = ~v12 & ~v13;
  assign new_n126_ = ~v14 & new_n125_;
  assign \v16.15  = ~v15 & new_n126_;
  assign \v16.16  = v15 & new_n126_;
  assign new_n129_ = v14 & new_n125_;
  assign \v16.17  = ~v15 & new_n129_;
  assign \v16.18  = v15 & new_n129_;
  assign new_n132_ = ~v12 & v13;
  assign new_n133_ = ~v14 & new_n132_;
  assign \v16.19  = ~v15 & new_n133_;
  assign \v16.20  = v15 & new_n133_;
  assign new_n136_ = v14 & new_n132_;
  assign \v16.21  = ~v15 & new_n136_;
  assign \v16.22  = v15 & new_n136_;
  assign new_n139_ = v12 & ~v13;
  assign new_n140_ = ~v14 & new_n139_;
  assign \v16.23  = ~v15 & new_n140_;
  assign \v16.24  = v15 & new_n140_;
  assign new_n143_ = v14 & new_n139_;
  assign \v16.25  = ~v15 & new_n143_;
  assign \v16.26  = v15 & new_n143_;
  assign new_n146_ = v12 & v13;
  assign new_n147_ = ~v14 & new_n146_;
  assign \v16.27  = ~v15 & new_n147_;
  assign \v16.28  = v15 & new_n147_;
  assign new_n150_ = v14 & new_n146_;
  assign \v16.29  = ~v15 & new_n150_;
  assign \v16.30  = v15 & new_n150_;
  assign new_n153_ = ~v11 & ~new_n64_;
  assign new_n154_ = ~v10 & new_n153_;
  assign new_n155_ = ~v9 & new_n154_;
  assign \v16.31  = ~v8 & new_n155_;
  assign new_n157_ = v11 & ~new_n64_;
  assign new_n158_ = ~v10 & new_n157_;
  assign new_n159_ = ~v9 & new_n158_;
  assign \v16.32  = ~v8 & new_n159_;
  assign new_n161_ = v10 & new_n153_;
  assign new_n162_ = ~v9 & new_n161_;
  assign \v16.33  = ~v8 & new_n162_;
  assign new_n164_ = v10 & new_n157_;
  assign new_n165_ = ~v9 & new_n164_;
  assign \v16.34  = ~v8 & new_n165_;
  assign new_n167_ = v9 & new_n154_;
  assign \v16.35  = ~v8 & new_n167_;
  assign new_n169_ = v9 & new_n158_;
  assign \v16.36  = ~v8 & new_n169_;
  assign new_n171_ = v9 & new_n161_;
  assign \v16.37  = ~v8 & new_n171_;
  assign new_n173_ = v9 & new_n164_;
  assign \v16.38  = ~v8 & new_n173_;
  assign \v16.39  = v8 & new_n155_;
  assign \v16.40  = v8 & new_n159_;
  assign \v16.41  = v8 & new_n162_;
  assign \v16.42  = v8 & new_n165_;
  assign \v16.43  = v8 & new_n167_;
  assign \v16.44  = v8 & new_n169_;
  assign \v16.45  = v8 & new_n171_;
  assign \v16.46  = v8 & new_n173_;
  assign \v16.14  = \v16.6 ;
endmodule


