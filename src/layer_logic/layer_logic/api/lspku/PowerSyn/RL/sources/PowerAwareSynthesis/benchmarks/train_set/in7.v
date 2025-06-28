// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:05 2022

module in7  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,
    \v26.0 , \v26.1 , \v26.2 , \v26.3 , \v26.4 , \v26.5 , \v26.6 , \v26.7 ,
    \v26.8 , \v26.9   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25;
  output \v26.0 , \v26.1 , \v26.2 , \v26.3 , \v26.4 , \v26.5 , \v26.6 ,
    \v26.7 , \v26.8 , \v26.9 ;
  wire new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_, new_n44_,
    new_n45_, new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_,
    new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_, new_n65_,
    new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n85_, new_n86_, new_n87_,
    new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_,
    new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n108_,
    new_n109_, new_n110_, new_n111_, new_n112_, new_n113_, new_n114_,
    new_n115_, new_n116_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n125_, new_n126_,
    new_n127_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n136_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n141_, new_n142_, new_n143_, new_n144_, new_n145_,
    new_n146_, new_n147_, new_n148_, new_n149_, new_n150_, new_n152_,
    new_n153_, new_n154_, new_n155_, new_n156_, new_n157_, new_n158_,
    new_n159_, new_n160_, new_n161_, new_n162_, new_n163_, new_n164_,
    new_n165_, new_n166_, new_n167_, new_n168_, new_n169_, new_n170_,
    new_n171_, new_n172_, new_n173_, new_n174_, new_n175_, new_n176_,
    new_n177_, new_n178_, new_n179_, new_n180_, new_n181_, new_n182_,
    new_n183_, new_n184_, new_n185_, new_n186_, new_n187_, new_n190_,
    new_n192_, new_n193_, new_n194_, new_n195_, new_n196_, new_n197_,
    new_n198_, new_n199_, new_n201_, new_n202_;
  assign new_n37_ = v14 & v15;
  assign new_n38_ = ~v13 & ~new_n37_;
  assign new_n39_ = ~v12 & ~new_n38_;
  assign new_n40_ = ~v11 & new_n39_;
  assign new_n41_ = ~v10 & new_n40_;
  assign new_n42_ = ~v9 & new_n41_;
  assign \v26.0  = v16 | new_n42_;
  assign new_n44_ = v21 & ~v25;
  assign new_n45_ = ~v11 & ~v12;
  assign new_n46_ = ~v10 & new_n45_;
  assign new_n47_ = ~v2 & ~new_n46_;
  assign new_n48_ = ~v9 & ~new_n47_;
  assign new_n49_ = ~v1 & v9;
  assign new_n50_ = ~v0 & ~new_n49_;
  assign new_n51_ = ~new_n48_ & new_n50_;
  assign new_n52_ = v19 & ~new_n51_;
  assign new_n53_ = v3 & v8;
  assign new_n54_ = v0 & new_n53_;
  assign new_n55_ = ~v19 & ~new_n54_;
  assign new_n56_ = v15 & ~v18;
  assign new_n57_ = ~new_n55_ & new_n56_;
  assign new_n58_ = ~new_n52_ & new_n57_;
  assign new_n59_ = ~new_n44_ & ~new_n58_;
  assign new_n60_ = ~v18 & v19;
  assign new_n61_ = ~v0 & ~v21;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = ~v24 & ~new_n49_;
  assign new_n64_ = ~new_n48_ & new_n63_;
  assign new_n65_ = ~new_n62_ & ~new_n64_;
  assign new_n66_ = v19 & ~v24;
  assign new_n67_ = ~new_n54_ & ~new_n66_;
  assign new_n68_ = v0 & v19;
  assign new_n69_ = ~v22 & ~new_n68_;
  assign new_n70_ = v15 & new_n69_;
  assign new_n71_ = ~new_n67_ & new_n70_;
  assign new_n72_ = ~v18 & ~new_n71_;
  assign new_n73_ = v0 & ~new_n53_;
  assign new_n74_ = ~v3 & ~v25;
  assign new_n75_ = ~v19 & ~new_n74_;
  assign new_n76_ = v8 & new_n75_;
  assign new_n77_ = v24 & ~new_n76_;
  assign new_n78_ = ~new_n73_ & ~new_n77_;
  assign new_n79_ = ~v21 & ~new_n78_;
  assign new_n80_ = v22 & v25;
  assign new_n81_ = ~new_n79_ & ~new_n80_;
  assign new_n82_ = ~new_n72_ & new_n81_;
  assign new_n83_ = ~new_n65_ & new_n82_;
  assign \v26.1  = new_n59_ | ~new_n83_;
  assign new_n85_ = ~v10 & v12;
  assign new_n86_ = ~v10 & ~new_n85_;
  assign new_n87_ = v15 & ~new_n86_;
  assign new_n88_ = ~v2 & new_n87_;
  assign new_n89_ = ~v4 & ~v5;
  assign new_n90_ = ~v6 & ~v7;
  assign new_n91_ = new_n89_ & new_n90_;
  assign new_n92_ = ~v15 & ~new_n91_;
  assign new_n93_ = ~v12 & new_n92_;
  assign new_n94_ = ~v10 & new_n93_;
  assign new_n95_ = ~new_n88_ & ~new_n94_;
  assign new_n96_ = ~v11 & ~new_n95_;
  assign new_n97_ = v11 & v15;
  assign new_n98_ = ~v2 & new_n97_;
  assign new_n99_ = ~new_n96_ & ~new_n98_;
  assign new_n100_ = ~v24 & ~new_n99_;
  assign new_n101_ = ~v22 & new_n100_;
  assign new_n102_ = v19 & new_n101_;
  assign new_n103_ = ~v18 & new_n102_;
  assign new_n104_ = ~v9 & new_n103_;
  assign new_n105_ = ~v0 & new_n104_;
  assign new_n106_ = v18 & ~v25;
  assign \v26.2  = new_n105_ | new_n106_;
  assign new_n108_ = ~v15 & v19;
  assign new_n109_ = v15 & ~v19;
  assign new_n110_ = v8 & new_n109_;
  assign new_n111_ = ~new_n108_ & ~new_n110_;
  assign new_n112_ = v3 & ~new_n111_;
  assign new_n113_ = v0 & new_n112_;
  assign new_n114_ = ~v11 & v12;
  assign new_n115_ = ~v11 & ~new_n114_;
  assign new_n116_ = v15 & ~new_n115_;
  assign new_n117_ = ~v2 & new_n116_;
  assign new_n118_ = ~v15 & ~new_n90_;
  assign new_n119_ = ~v12 & new_n118_;
  assign new_n120_ = ~v11 & new_n119_;
  assign new_n121_ = ~new_n117_ & ~new_n120_;
  assign new_n122_ = ~v10 & ~new_n121_;
  assign new_n123_ = ~v9 & new_n122_;
  assign new_n124_ = v9 & v15;
  assign new_n125_ = v1 & new_n124_;
  assign new_n126_ = v2 & ~v15;
  assign new_n127_ = ~new_n125_ & ~new_n126_;
  assign new_n128_ = ~new_n123_ & new_n127_;
  assign new_n129_ = ~v24 & ~new_n128_;
  assign new_n130_ = v19 & new_n129_;
  assign new_n131_ = ~v0 & new_n130_;
  assign new_n132_ = ~new_n113_ & ~new_n131_;
  assign new_n133_ = ~v22 & ~new_n132_;
  assign new_n134_ = ~v18 & new_n133_;
  assign \v26.3  = new_n106_ | new_n134_;
  assign new_n136_ = ~v5 & ~v7;
  assign new_n137_ = ~v15 & ~new_n136_;
  assign new_n138_ = ~v12 & new_n137_;
  assign new_n139_ = ~v10 & new_n138_;
  assign new_n140_ = ~new_n88_ & ~new_n139_;
  assign new_n141_ = ~v11 & ~new_n140_;
  assign new_n142_ = ~v9 & new_n141_;
  assign new_n143_ = new_n127_ & ~new_n142_;
  assign new_n144_ = ~v24 & ~new_n143_;
  assign new_n145_ = v19 & new_n144_;
  assign new_n146_ = ~v0 & new_n145_;
  assign new_n147_ = ~new_n113_ & ~new_n146_;
  assign new_n148_ = ~v22 & ~new_n147_;
  assign new_n149_ = ~v18 & new_n148_;
  assign new_n150_ = v17 & new_n106_;
  assign \v26.4  = new_n149_ | new_n150_;
  assign new_n152_ = v19 & ~v23;
  assign new_n153_ = ~v15 & new_n152_;
  assign new_n154_ = ~new_n110_ & ~new_n153_;
  assign new_n155_ = v3 & ~new_n154_;
  assign new_n156_ = v0 & new_n155_;
  assign new_n157_ = v15 & ~new_n46_;
  assign new_n158_ = ~v2 & new_n157_;
  assign new_n159_ = ~v23 & ~new_n91_;
  assign new_n160_ = ~v15 & new_n159_;
  assign new_n161_ = ~v12 & new_n160_;
  assign new_n162_ = ~v11 & new_n161_;
  assign new_n163_ = ~v10 & new_n162_;
  assign new_n164_ = ~new_n158_ & ~new_n163_;
  assign new_n165_ = ~v9 & ~new_n164_;
  assign new_n166_ = ~v15 & ~v23;
  assign new_n167_ = v2 & new_n166_;
  assign new_n168_ = ~new_n125_ & ~new_n167_;
  assign new_n169_ = ~new_n165_ & new_n168_;
  assign new_n170_ = ~v24 & ~new_n169_;
  assign new_n171_ = v19 & new_n170_;
  assign new_n172_ = ~v0 & new_n171_;
  assign new_n173_ = ~new_n156_ & ~new_n172_;
  assign new_n174_ = ~v22 & ~new_n173_;
  assign new_n175_ = ~v20 & new_n174_;
  assign new_n176_ = v15 & ~v22;
  assign new_n177_ = ~new_n55_ & new_n176_;
  assign new_n178_ = v23 & ~new_n177_;
  assign new_n179_ = ~new_n175_ & ~new_n178_;
  assign new_n180_ = ~v18 & ~new_n179_;
  assign new_n181_ = v23 & v25;
  assign new_n182_ = ~v20 & ~v25;
  assign new_n183_ = ~new_n181_ & ~new_n182_;
  assign new_n184_ = v18 & ~new_n183_;
  assign new_n185_ = ~v19 & ~v20;
  assign new_n186_ = v23 & ~new_n185_;
  assign new_n187_ = ~new_n184_ & ~new_n186_;
  assign \v26.5  = new_n180_ | ~new_n187_;
  assign \v26.6  = ~v18 & new_n175_;
  assign new_n190_ = v18 & ~v20;
  assign \v26.7  = ~v25 & new_n190_;
  assign new_n192_ = ~v0 & new_n63_;
  assign new_n193_ = ~new_n48_ & new_n192_;
  assign new_n194_ = v19 & ~new_n193_;
  assign new_n195_ = new_n177_ & ~new_n194_;
  assign new_n196_ = ~v18 & ~new_n195_;
  assign new_n197_ = v18 & v25;
  assign new_n198_ = ~v20 & ~new_n197_;
  assign new_n199_ = ~new_n196_ & new_n198_;
  assign \v26.8  = v23 & ~new_n199_;
  assign new_n201_ = ~v9 & ~v10;
  assign new_n202_ = ~v11 & new_n201_;
  assign \v26.9  = v12 & new_n202_;
endmodule


