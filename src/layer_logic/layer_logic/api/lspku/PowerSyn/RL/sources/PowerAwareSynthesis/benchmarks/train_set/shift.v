// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:32 2022

module shift  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18,
    \v19.0 , \v19.1 , \v19.2 , \v19.3 , \v19.4 , \v19.5 , \v19.6 , \v19.7 ,
    \v19.8 , \v19.9 , \v19.10 , \v19.11 , \v19.12 , \v19.13 , \v19.14 ,
    \v19.15   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18;
  output \v19.0 , \v19.1 , \v19.2 , \v19.3 , \v19.4 , \v19.5 , \v19.6 ,
    \v19.7 , \v19.8 , \v19.9 , \v19.10 , \v19.11 , \v19.12 , \v19.13 ,
    \v19.14 , \v19.15 ;
  wire new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n46_, new_n47_, new_n48_, new_n49_, new_n50_,
    new_n51_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n65_, new_n66_,
    new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_, new_n74_,
    new_n75_, new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n81_,
    new_n82_, new_n83_, new_n84_, new_n85_, new_n87_, new_n88_, new_n89_,
    new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_,
    new_n98_, new_n99_, new_n100_, new_n101_, new_n102_, new_n103_,
    new_n104_, new_n105_, new_n106_, new_n107_, new_n108_, new_n109_,
    new_n111_, new_n112_, new_n113_, new_n114_, new_n115_, new_n116_,
    new_n117_, new_n118_, new_n120_, new_n121_, new_n122_, new_n123_,
    new_n124_, new_n125_, new_n126_, new_n127_, new_n129_, new_n130_,
    new_n131_, new_n132_, new_n133_, new_n134_, new_n135_, new_n136_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n142_, new_n143_,
    new_n144_, new_n145_, new_n147_, new_n148_, new_n149_, new_n150_,
    new_n151_, new_n152_, new_n153_, new_n154_, new_n156_, new_n157_,
    new_n158_, new_n159_, new_n160_, new_n161_, new_n162_, new_n163_,
    new_n165_, new_n166_, new_n167_, new_n168_, new_n169_, new_n170_,
    new_n171_, new_n172_, new_n174_, new_n175_, new_n176_, new_n177_,
    new_n178_, new_n179_, new_n180_, new_n181_;
  assign new_n36_ = ~v0 & v1;
  assign new_n37_ = ~v0 & ~new_n36_;
  assign new_n38_ = ~v1 & v2;
  assign new_n39_ = ~v0 & new_n38_;
  assign new_n40_ = new_n37_ & ~new_n39_;
  assign new_n41_ = v3 & ~new_n40_;
  assign new_n42_ = ~v0 & ~v1;
  assign new_n43_ = ~v2 & v4;
  assign new_n44_ = new_n42_ & new_n43_;
  assign \v19.1  = new_n41_ | new_n44_;
  assign new_n46_ = v3 & ~new_n37_;
  assign new_n47_ = v2 & v4;
  assign new_n48_ = ~v2 & v5;
  assign new_n49_ = ~new_n47_ & ~new_n48_;
  assign new_n50_ = ~v1 & ~new_n49_;
  assign new_n51_ = ~v0 & new_n50_;
  assign \v19.2  = new_n46_ | new_n51_;
  assign new_n53_ = v1 & v2;
  assign new_n54_ = ~v0 & new_n53_;
  assign new_n55_ = ~v0 & ~new_n54_;
  assign new_n56_ = v3 & ~new_n55_;
  assign new_n57_ = v2 & v5;
  assign new_n58_ = ~v2 & v6;
  assign new_n59_ = ~new_n57_ & ~new_n58_;
  assign new_n60_ = ~v1 & ~new_n59_;
  assign new_n61_ = v1 & new_n43_;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = ~v0 & ~new_n62_;
  assign \v19.3  = new_n56_ | new_n63_;
  assign new_n65_ = v0 & v3;
  assign new_n66_ = v1 & ~new_n49_;
  assign new_n67_ = v2 & v6;
  assign new_n68_ = ~v2 & v7;
  assign new_n69_ = ~new_n67_ & ~new_n68_;
  assign new_n70_ = ~v1 & ~new_n69_;
  assign new_n71_ = ~new_n66_ & ~new_n70_;
  assign new_n72_ = ~v0 & ~new_n71_;
  assign \v19.4  = new_n65_ | new_n72_;
  assign new_n74_ = ~v1 & ~new_n38_;
  assign new_n75_ = v3 & ~new_n74_;
  assign new_n76_ = ~v1 & new_n43_;
  assign new_n77_ = ~new_n75_ & ~new_n76_;
  assign new_n78_ = v0 & ~new_n77_;
  assign new_n79_ = v1 & ~new_n59_;
  assign new_n80_ = v2 & v7;
  assign new_n81_ = ~v2 & v8;
  assign new_n82_ = ~new_n80_ & ~new_n81_;
  assign new_n83_ = ~v1 & ~new_n82_;
  assign new_n84_ = ~new_n79_ & ~new_n83_;
  assign new_n85_ = ~v0 & ~new_n84_;
  assign \v19.5  = new_n78_ | new_n85_;
  assign new_n87_ = v1 & v3;
  assign new_n88_ = ~new_n50_ & ~new_n87_;
  assign new_n89_ = v0 & ~new_n88_;
  assign new_n90_ = v1 & ~new_n69_;
  assign new_n91_ = v2 & v8;
  assign new_n92_ = ~v2 & v9;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = ~v1 & ~new_n93_;
  assign new_n95_ = ~new_n90_ & ~new_n94_;
  assign new_n96_ = ~v0 & ~new_n95_;
  assign \v19.6  = new_n89_ | new_n96_;
  assign new_n98_ = v2 & v3;
  assign new_n99_ = ~new_n43_ & ~new_n98_;
  assign new_n100_ = v1 & ~new_n99_;
  assign new_n101_ = ~new_n60_ & ~new_n100_;
  assign new_n102_ = v0 & ~new_n101_;
  assign new_n103_ = v1 & ~new_n82_;
  assign new_n104_ = v2 & v9;
  assign new_n105_ = ~v2 & v10;
  assign new_n106_ = ~new_n104_ & ~new_n105_;
  assign new_n107_ = ~v1 & ~new_n106_;
  assign new_n108_ = ~new_n103_ & ~new_n107_;
  assign new_n109_ = ~v0 & ~new_n108_;
  assign \v19.7  = new_n102_ | new_n109_;
  assign new_n111_ = v0 & ~new_n71_;
  assign new_n112_ = v1 & ~new_n93_;
  assign new_n113_ = v2 & v10;
  assign new_n114_ = ~v2 & v11;
  assign new_n115_ = ~new_n113_ & ~new_n114_;
  assign new_n116_ = ~v1 & ~new_n115_;
  assign new_n117_ = ~new_n112_ & ~new_n116_;
  assign new_n118_ = ~v0 & ~new_n117_;
  assign \v19.8  = new_n111_ | new_n118_;
  assign new_n120_ = v0 & ~new_n84_;
  assign new_n121_ = v1 & ~new_n106_;
  assign new_n122_ = v2 & v11;
  assign new_n123_ = ~v2 & v12;
  assign new_n124_ = ~new_n122_ & ~new_n123_;
  assign new_n125_ = ~v1 & ~new_n124_;
  assign new_n126_ = ~new_n121_ & ~new_n125_;
  assign new_n127_ = ~v0 & ~new_n126_;
  assign \v19.9  = new_n120_ | new_n127_;
  assign new_n129_ = v0 & ~new_n95_;
  assign new_n130_ = v1 & ~new_n115_;
  assign new_n131_ = v2 & v12;
  assign new_n132_ = ~v2 & v13;
  assign new_n133_ = ~new_n131_ & ~new_n132_;
  assign new_n134_ = ~v1 & ~new_n133_;
  assign new_n135_ = ~new_n130_ & ~new_n134_;
  assign new_n136_ = ~v0 & ~new_n135_;
  assign \v19.10  = new_n129_ | new_n136_;
  assign new_n138_ = v0 & ~new_n108_;
  assign new_n139_ = v1 & ~new_n124_;
  assign new_n140_ = v2 & v13;
  assign new_n141_ = ~v2 & v14;
  assign new_n142_ = ~new_n140_ & ~new_n141_;
  assign new_n143_ = ~v1 & ~new_n142_;
  assign new_n144_ = ~new_n139_ & ~new_n143_;
  assign new_n145_ = ~v0 & ~new_n144_;
  assign \v19.11  = new_n138_ | new_n145_;
  assign new_n147_ = v0 & ~new_n117_;
  assign new_n148_ = v1 & ~new_n133_;
  assign new_n149_ = v2 & v14;
  assign new_n150_ = ~v2 & v15;
  assign new_n151_ = ~new_n149_ & ~new_n150_;
  assign new_n152_ = ~v1 & ~new_n151_;
  assign new_n153_ = ~new_n148_ & ~new_n152_;
  assign new_n154_ = ~v0 & ~new_n153_;
  assign \v19.12  = new_n147_ | new_n154_;
  assign new_n156_ = v0 & ~new_n126_;
  assign new_n157_ = v1 & ~new_n142_;
  assign new_n158_ = v2 & v15;
  assign new_n159_ = ~v2 & v16;
  assign new_n160_ = ~new_n158_ & ~new_n159_;
  assign new_n161_ = ~v1 & ~new_n160_;
  assign new_n162_ = ~new_n157_ & ~new_n161_;
  assign new_n163_ = ~v0 & ~new_n162_;
  assign \v19.13  = new_n156_ | new_n163_;
  assign new_n165_ = v0 & ~new_n135_;
  assign new_n166_ = v1 & ~new_n151_;
  assign new_n167_ = v2 & v16;
  assign new_n168_ = ~v2 & v17;
  assign new_n169_ = ~new_n167_ & ~new_n168_;
  assign new_n170_ = ~v1 & ~new_n169_;
  assign new_n171_ = ~new_n166_ & ~new_n170_;
  assign new_n172_ = ~v0 & ~new_n171_;
  assign \v19.14  = new_n165_ | new_n172_;
  assign new_n174_ = v0 & ~new_n144_;
  assign new_n175_ = v1 & ~new_n160_;
  assign new_n176_ = v2 & v17;
  assign new_n177_ = ~v2 & v18;
  assign new_n178_ = ~new_n176_ & ~new_n177_;
  assign new_n179_ = ~v1 & ~new_n178_;
  assign new_n180_ = ~new_n175_ & ~new_n179_;
  assign new_n181_ = ~v0 & ~new_n180_;
  assign \v19.15  = new_n174_ | new_n181_;
  assign \v19.0  = v3;
endmodule


