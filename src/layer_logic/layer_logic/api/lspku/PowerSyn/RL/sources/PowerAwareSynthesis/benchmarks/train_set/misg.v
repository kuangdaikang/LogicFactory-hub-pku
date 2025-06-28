// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:57 2022

module misg  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,
    v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,
    v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55,
    \v56.0 , \v56.1 , \v56.2 , \v56.3 , \v56.4 , \v56.5 , \v56.6 , \v56.7 ,
    \v56.8 , \v56.9 , \v56.10 , \v56.11 , \v56.12 , \v56.13 , \v56.14 ,
    \v56.15 , \v56.16 , \v56.17 , \v56.18 , \v56.19 , \v56.20 , \v56.21 ,
    \v56.22   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28,
    v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42,
    v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55;
  output \v56.0 , \v56.1 , \v56.2 , \v56.3 , \v56.4 , \v56.5 , \v56.6 ,
    \v56.7 , \v56.8 , \v56.9 , \v56.10 , \v56.11 , \v56.12 , \v56.13 ,
    \v56.14 , \v56.15 , \v56.16 , \v56.17 , \v56.18 , \v56.19 , \v56.20 ,
    \v56.21 , \v56.22 ;
  wire new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n87_,
    new_n88_, new_n91_, new_n92_, new_n95_, new_n98_, new_n101_, new_n105_,
    new_n106_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n113_, new_n114_, new_n115_, new_n116_, new_n117_, new_n118_,
    new_n119_, new_n120_, new_n121_, new_n122_, new_n123_, new_n124_,
    new_n125_, new_n126_, new_n127_, new_n128_, new_n129_, new_n130_,
    new_n131_, new_n132_, new_n133_, new_n134_, new_n135_, new_n136_,
    new_n137_, new_n138_, new_n139_, new_n140_, new_n141_, new_n142_;
  assign new_n80_ = v6 & v7;
  assign new_n81_ = v4 & v5;
  assign new_n82_ = ~new_n80_ & ~new_n81_;
  assign new_n83_ = v2 & v3;
  assign new_n84_ = v0 & v1;
  assign new_n85_ = ~new_n83_ & ~new_n84_;
  assign \v56.0  = ~new_n82_ | ~new_n85_;
  assign new_n87_ = v11 & v13;
  assign new_n88_ = v9 & ~new_n87_;
  assign \v56.2  = v10 | ~new_n88_;
  assign \v56.3  = ~v8 | ~v14;
  assign new_n91_ = v22 & v49;
  assign new_n92_ = ~v10 & v21;
  assign \v56.8  = ~new_n91_ | ~new_n92_;
  assign \v56.9  = ~v23 | ~v24;
  assign new_n95_ = v18 & v19;
  assign \v56.10  = v20 & new_n95_;
  assign \v56.11  = ~v25 | ~v26;
  assign new_n98_ = ~v17 & ~v27;
  assign \v56.12  = ~v28 | ~new_n98_;
  assign \v56.13  = v27 | ~v29;
  assign new_n101_ = v49 & ~v50;
  assign \v56.14  = v27 | new_n101_;
  assign \v56.15  = v30 | v31;
  assign \v56.18  = ~v41 | ~v42;
  assign new_n105_ = v33 & v54;
  assign new_n106_ = v20 & new_n105_;
  assign \v56.19  = ~v46 | new_n106_;
  assign new_n108_ = v40 & v45;
  assign new_n109_ = v34 & v54;
  assign new_n110_ = v38 & v44;
  assign new_n111_ = ~v43 & ~new_n110_;
  assign new_n112_ = ~v36 & ~v44;
  assign new_n113_ = ~new_n111_ & ~new_n112_;
  assign new_n114_ = ~new_n109_ & ~new_n113_;
  assign new_n115_ = ~new_n108_ & new_n114_;
  assign new_n116_ = ~v38 & ~v45;
  assign new_n117_ = ~v36 & new_n116_;
  assign new_n118_ = v53 & ~new_n117_;
  assign new_n119_ = ~new_n109_ & ~new_n118_;
  assign new_n120_ = ~v39 & ~v45;
  assign new_n121_ = v40 & ~new_n120_;
  assign new_n122_ = ~v37 & ~v44;
  assign new_n123_ = v38 & ~new_n122_;
  assign new_n124_ = ~v35 & ~v43;
  assign new_n125_ = v36 & ~new_n124_;
  assign new_n126_ = ~new_n123_ & ~new_n125_;
  assign new_n127_ = ~new_n121_ & new_n126_;
  assign new_n128_ = v39 & v40;
  assign new_n129_ = v37 & v38;
  assign new_n130_ = ~v35 & ~new_n129_;
  assign new_n131_ = ~v36 & ~v37;
  assign new_n132_ = ~new_n130_ & ~new_n131_;
  assign new_n133_ = ~new_n128_ & ~new_n132_;
  assign new_n134_ = ~v38 & ~v39;
  assign new_n135_ = ~v36 & new_n134_;
  assign new_n136_ = ~new_n133_ & ~new_n135_;
  assign new_n137_ = ~v53 & ~new_n136_;
  assign new_n138_ = v47 & v49;
  assign new_n139_ = v32 & new_n138_;
  assign new_n140_ = ~new_n137_ & new_n139_;
  assign new_n141_ = ~new_n127_ & new_n140_;
  assign new_n142_ = ~new_n119_ & new_n141_;
  assign \v56.20  = new_n115_ | ~new_n142_;
  assign \v56.22  = ~v32 | new_n106_;
  assign \v56.1  = ~v48;
  assign \v56.4  = ~v15;
  assign \v56.5  = ~v16;
  assign \v56.6  = ~v17;
  assign \v56.7  = ~v12;
  assign \v56.16  = ~v51;
  assign \v56.17  = ~v52;
  assign \v56.21  = ~v55;
endmodule


