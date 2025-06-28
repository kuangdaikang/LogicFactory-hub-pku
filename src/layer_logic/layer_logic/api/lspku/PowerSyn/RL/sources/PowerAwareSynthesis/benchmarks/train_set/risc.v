// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:39 2022

module risc  ( 
    v0, v1, v2, v3, v4, v5, v6, v7,
    \v8.0 , \v8.1 , \v8.2 , \v8.3 , \v8.4 , \v8.5 , \v8.6 , \v8.7 , \v8.8 ,
    \v8.9 , \v8.10 , \v8.11 , \v8.12 , \v8.13 , \v8.14 , \v8.15 , \v8.16 ,
    \v8.17 , \v8.18 , \v8.19 , \v8.20 , \v8.21 , \v8.22 , \v8.23 , \v8.24 ,
    \v8.25 , \v8.26 , \v8.27 , \v8.28 , \v8.29 , \v8.30   );
  input  v0, v1, v2, v3, v4, v5, v6, v7;
  output \v8.0 , \v8.1 , \v8.2 , \v8.3 , \v8.4 , \v8.5 , \v8.6 , \v8.7 ,
    \v8.8 , \v8.9 , \v8.10 , \v8.11 , \v8.12 , \v8.13 , \v8.14 , \v8.15 ,
    \v8.16 , \v8.17 , \v8.18 , \v8.19 , \v8.20 , \v8.21 , \v8.22 , \v8.23 ,
    \v8.24 , \v8.25 , \v8.26 , \v8.27 , \v8.28 , \v8.29 , \v8.30 ;
  wire new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_,
    new_n47_, new_n48_, new_n49_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_,
    new_n63_, new_n64_, new_n65_, new_n66_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n73_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n82_, new_n83_, new_n85_, new_n86_, new_n88_,
    new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n96_,
    new_n99_, new_n101_, new_n102_, new_n103_, new_n104_, new_n105_,
    new_n106_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n114_, new_n116_, new_n119_, new_n120_, new_n121_, new_n123_,
    new_n124_, new_n126_, new_n130_, new_n131_, new_n132_, new_n133_,
    new_n135_, new_n136_, new_n138_, new_n139_, new_n140_, new_n142_,
    new_n143_, new_n145_, new_n146_, new_n147_, new_n148_, new_n150_,
    new_n152_, new_n153_, new_n154_, new_n155_, new_n157_, new_n159_,
    new_n160_, new_n161_, new_n163_, new_n164_;
  assign new_n40_ = v5 & ~v6;
  assign new_n41_ = v5 & ~new_n40_;
  assign new_n42_ = ~v4 & ~new_n41_;
  assign new_n43_ = ~v3 & new_n42_;
  assign new_n44_ = ~v2 & new_n43_;
  assign new_n45_ = v1 & new_n44_;
  assign new_n46_ = ~v1 & v2;
  assign new_n47_ = v3 & v4;
  assign new_n48_ = new_n46_ & new_n47_;
  assign new_n49_ = ~new_n45_ & ~new_n48_;
  assign \v8.0  = ~v0 & ~new_n49_;
  assign new_n51_ = ~v0 & ~v1;
  assign new_n52_ = v2 & new_n51_;
  assign new_n53_ = v3 & new_n52_;
  assign new_n54_ = ~v4 & new_n53_;
  assign \v8.1  = v5 & new_n54_;
  assign new_n56_ = ~v4 & v5;
  assign new_n57_ = ~v1 & new_n56_;
  assign new_n58_ = ~v1 & ~new_n57_;
  assign new_n59_ = v3 & ~new_n58_;
  assign new_n60_ = v1 & ~v3;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = v2 & ~new_n61_;
  assign new_n63_ = ~v0 & new_n62_;
  assign new_n64_ = v0 & v1;
  assign new_n65_ = ~v2 & ~v3;
  assign new_n66_ = new_n64_ & new_n65_;
  assign \v8.2  = new_n63_ | new_n66_;
  assign new_n68_ = ~v3 & v7;
  assign new_n69_ = ~v3 & ~new_n68_;
  assign new_n70_ = ~v4 & ~new_n69_;
  assign new_n71_ = ~v1 & new_n70_;
  assign new_n72_ = ~new_n60_ & ~new_n71_;
  assign new_n73_ = ~v2 & ~new_n72_;
  assign \v8.3  = v0 & new_n73_;
  assign new_n75_ = v0 & v2;
  assign new_n76_ = ~v0 & new_n65_;
  assign new_n77_ = ~new_n75_ & ~new_n76_;
  assign new_n78_ = ~v2 & v3;
  assign new_n79_ = ~v0 & new_n78_;
  assign new_n80_ = new_n77_ & ~new_n79_;
  assign \v8.4  = ~v1 & ~new_n80_;
  assign new_n82_ = v2 & v3;
  assign new_n83_ = ~v1 & new_n82_;
  assign \v8.5  = ~v0 & new_n83_;
  assign new_n85_ = v2 & ~v3;
  assign new_n86_ = ~v1 & new_n85_;
  assign \v8.6  = ~v0 & new_n86_;
  assign new_n88_ = ~v4 & ~v5;
  assign new_n89_ = ~v4 & ~new_n88_;
  assign new_n90_ = v3 & ~new_n89_;
  assign new_n91_ = ~v3 & ~v5;
  assign new_n92_ = ~new_n90_ & ~new_n91_;
  assign new_n93_ = v2 & ~new_n92_;
  assign new_n94_ = ~v1 & new_n93_;
  assign \v8.7  = ~v0 & new_n94_;
  assign new_n96_ = v1 & v2;
  assign \v8.8  = ~v0 & new_n96_;
  assign \v8.9  = ~v0 & new_n45_;
  assign new_n99_ = v1 & new_n65_;
  assign \v8.10  = ~v0 & new_n99_;
  assign new_n101_ = v5 & v6;
  assign new_n102_ = v5 & ~new_n101_;
  assign new_n103_ = ~v4 & ~new_n102_;
  assign new_n104_ = ~v3 & new_n103_;
  assign new_n105_ = ~v2 & new_n104_;
  assign new_n106_ = v1 & new_n105_;
  assign \v8.11  = ~v0 & new_n106_;
  assign new_n108_ = ~v4 & new_n40_;
  assign new_n109_ = ~v4 & ~new_n108_;
  assign new_n110_ = ~v3 & ~new_n109_;
  assign new_n111_ = ~v2 & new_n110_;
  assign new_n112_ = v1 & new_n111_;
  assign \v8.12  = ~v0 & new_n112_;
  assign new_n114_ = v1 & ~v2;
  assign \v8.13  = ~v0 & new_n114_;
  assign new_n116_ = ~v1 & ~v2;
  assign \v8.14  = ~v0 & new_n116_;
  assign \v8.15  = v2 | ~new_n51_;
  assign new_n119_ = ~v3 & v5;
  assign new_n120_ = v2 & new_n119_;
  assign new_n121_ = ~v1 & new_n120_;
  assign \v8.16  = v0 & new_n121_;
  assign new_n123_ = v2 & new_n91_;
  assign new_n124_ = ~v1 & new_n123_;
  assign \v8.17  = v0 & new_n124_;
  assign new_n126_ = ~v3 & ~\v8.15 ;
  assign \v8.18  = ~v4 & new_n126_;
  assign \v8.19  = v3 & ~\v8.15 ;
  assign \v8.20  = v2 & new_n64_;
  assign new_n130_ = v3 & ~v4;
  assign new_n131_ = ~v1 & new_n130_;
  assign new_n132_ = ~new_n60_ & ~new_n131_;
  assign new_n133_ = ~v2 & ~new_n132_;
  assign \v8.21  = v0 & new_n133_;
  assign new_n135_ = ~v2 & new_n130_;
  assign new_n136_ = ~v1 & new_n135_;
  assign \v8.22  = v0 & new_n136_;
  assign new_n138_ = ~v3 & ~v4;
  assign new_n139_ = ~v2 & new_n138_;
  assign new_n140_ = ~v1 & new_n139_;
  assign \v8.23  = v0 & new_n140_;
  assign new_n142_ = ~v2 & new_n56_;
  assign new_n143_ = ~v1 & new_n142_;
  assign \v8.24  = v0 & new_n143_;
  assign new_n145_ = ~v1 & v4;
  assign new_n146_ = ~v1 & ~new_n145_;
  assign new_n147_ = v3 & ~new_n146_;
  assign new_n148_ = ~v2 & new_n147_;
  assign \v8.25  = v0 & new_n148_;
  assign new_n150_ = ~new_n96_ & ~new_n143_;
  assign \v8.26  = v0 & ~new_n150_;
  assign new_n152_ = ~v3 & v4;
  assign new_n153_ = ~v3 & ~new_n152_;
  assign new_n154_ = ~new_n138_ & new_n153_;
  assign new_n155_ = v1 & ~new_n154_;
  assign \v8.27  = ~v0 & new_n155_;
  assign new_n157_ = ~v3 & new_n52_;
  assign \v8.28  = v5 & new_n157_;
  assign new_n159_ = v0 & ~v1;
  assign new_n160_ = v2 & new_n159_;
  assign new_n161_ = v3 & new_n160_;
  assign \v8.29  = ~v4 & new_n161_;
  assign new_n163_ = v2 & new_n138_;
  assign new_n164_ = ~v1 & new_n163_;
  assign \v8.30  = v0 & new_n164_;
endmodule


