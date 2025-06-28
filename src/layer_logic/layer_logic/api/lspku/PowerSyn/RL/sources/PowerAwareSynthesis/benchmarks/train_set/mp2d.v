// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:58 2022

module mp2d  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,
    \v14.0 , \v14.1 , \v14.2 , \v14.3 , \v14.4 , \v14.5 , \v14.6 , \v14.7 ,
    \v14.8 , \v14.9 , \v14.10 , \v14.11 , \v14.12 , \v14.13   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13;
  output \v14.0 , \v14.1 , \v14.2 , \v14.3 , \v14.4 , \v14.5 , \v14.6 ,
    \v14.7 , \v14.8 , \v14.9 , \v14.10 , \v14.11 , \v14.12 , \v14.13 ;
  wire new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n49_, new_n50_,
    new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n113_, new_n114_, new_n115_, new_n116_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n136_, new_n137_, new_n138_,
    new_n139_, new_n140_, new_n141_, new_n142_, new_n143_, new_n145_,
    new_n146_, new_n147_, new_n148_, new_n149_, new_n150_, new_n151_,
    new_n153_, new_n154_, new_n155_, new_n156_, new_n157_, new_n159_,
    new_n160_, new_n161_, new_n163_, new_n164_, new_n165_, new_n167_,
    new_n168_, new_n169_, new_n170_, new_n171_, new_n172_, new_n174_,
    new_n175_, new_n176_, new_n177_, new_n178_, new_n179_, new_n180_,
    new_n181_, new_n183_, new_n184_, new_n185_, new_n186_, new_n187_,
    new_n188_, new_n190_, new_n191_, new_n192_, new_n193_, new_n194_,
    new_n195_, new_n196_;
  assign new_n29_ = ~v9 & v10;
  assign new_n30_ = ~v9 & ~new_n29_;
  assign new_n31_ = ~v8 & ~new_n30_;
  assign new_n32_ = ~v8 & ~new_n31_;
  assign new_n33_ = v7 & ~new_n32_;
  assign new_n34_ = v7 & ~new_n33_;
  assign new_n35_ = ~v6 & ~new_n34_;
  assign new_n36_ = ~v6 & ~new_n35_;
  assign new_n37_ = v5 & ~new_n36_;
  assign new_n38_ = v5 & ~new_n37_;
  assign new_n39_ = v4 & ~new_n38_;
  assign new_n40_ = v4 & ~new_n39_;
  assign new_n41_ = ~v3 & ~new_n40_;
  assign new_n42_ = ~v3 & ~new_n41_;
  assign new_n43_ = v2 & ~new_n42_;
  assign new_n44_ = v2 & ~new_n43_;
  assign new_n45_ = ~v1 & ~new_n44_;
  assign new_n46_ = ~v1 & ~new_n45_;
  assign new_n47_ = v0 & ~new_n46_;
  assign \v14.0  = ~v0 | new_n47_;
  assign new_n49_ = ~v9 & ~v10;
  assign new_n50_ = ~v9 & ~new_n49_;
  assign new_n51_ = ~v8 & ~new_n50_;
  assign new_n52_ = ~v8 & ~new_n51_;
  assign new_n53_ = v7 & ~new_n52_;
  assign new_n54_ = v7 & ~new_n53_;
  assign new_n55_ = ~v6 & ~new_n54_;
  assign new_n56_ = ~v6 & ~new_n55_;
  assign new_n57_ = ~v1 & ~v3;
  assign new_n58_ = ~v1 & ~new_n57_;
  assign new_n59_ = v2 & ~new_n58_;
  assign new_n60_ = ~v3 & ~v4;
  assign new_n61_ = ~v3 & ~new_n60_;
  assign new_n62_ = v1 & ~new_n61_;
  assign new_n63_ = ~v3 & v4;
  assign new_n64_ = ~v3 & ~new_n63_;
  assign new_n65_ = ~v1 & ~new_n64_;
  assign new_n66_ = ~new_n62_ & ~new_n65_;
  assign new_n67_ = ~v2 & ~new_n66_;
  assign new_n68_ = ~new_n59_ & ~new_n67_;
  assign new_n69_ = v0 & ~new_n68_;
  assign new_n70_ = v0 & ~new_n69_;
  assign new_n71_ = ~new_n56_ & ~new_n70_;
  assign new_n72_ = v2 & v3;
  assign new_n73_ = ~v2 & new_n60_;
  assign new_n74_ = ~new_n72_ & ~new_n73_;
  assign new_n75_ = ~v1 & ~new_n74_;
  assign new_n76_ = v1 & ~v2;
  assign new_n77_ = new_n63_ & new_n76_;
  assign new_n78_ = ~new_n75_ & ~new_n77_;
  assign new_n79_ = v0 & ~new_n78_;
  assign \v14.1  = new_n71_ | new_n79_;
  assign new_n81_ = v2 & ~v5;
  assign new_n82_ = v2 & ~new_n81_;
  assign new_n83_ = ~v4 & ~new_n82_;
  assign new_n84_ = ~v2 & v4;
  assign new_n85_ = ~v2 & ~new_n84_;
  assign new_n86_ = v9 & v10;
  assign new_n87_ = v9 & ~new_n86_;
  assign new_n88_ = ~v8 & ~new_n87_;
  assign new_n89_ = ~v8 & ~new_n88_;
  assign new_n90_ = v7 & ~new_n89_;
  assign new_n91_ = v7 & ~new_n90_;
  assign new_n92_ = ~v6 & ~new_n91_;
  assign new_n93_ = ~v6 & ~new_n92_;
  assign new_n94_ = ~new_n85_ & ~new_n93_;
  assign new_n95_ = v2 & v4;
  assign new_n96_ = ~v2 & ~v5;
  assign new_n97_ = ~new_n95_ & ~new_n96_;
  assign new_n98_ = ~new_n94_ & new_n97_;
  assign new_n99_ = ~new_n83_ & new_n98_;
  assign new_n100_ = ~v3 & ~new_n99_;
  assign new_n101_ = ~v3 & ~new_n100_;
  assign new_n102_ = ~v1 & ~new_n101_;
  assign new_n103_ = ~v2 & ~new_n73_;
  assign new_n104_ = ~new_n93_ & ~new_n103_;
  assign new_n105_ = v5 & ~new_n84_;
  assign new_n106_ = ~v3 & ~new_n105_;
  assign new_n107_ = ~v3 & ~new_n106_;
  assign new_n108_ = ~new_n104_ & new_n107_;
  assign new_n109_ = v1 & ~new_n108_;
  assign new_n110_ = ~new_n102_ & ~new_n109_;
  assign new_n111_ = v0 & ~new_n110_;
  assign new_n112_ = ~v3 & ~v5;
  assign new_n113_ = ~v6 & ~new_n112_;
  assign new_n114_ = ~v3 & new_n113_;
  assign new_n115_ = ~new_n92_ & new_n114_;
  assign new_n116_ = ~v0 & ~new_n115_;
  assign \v14.2  = new_n111_ | new_n116_;
  assign new_n118_ = v9 & ~v10;
  assign new_n119_ = v9 & ~new_n118_;
  assign new_n120_ = ~v8 & ~new_n119_;
  assign new_n121_ = ~v8 & ~new_n120_;
  assign new_n122_ = v7 & ~new_n121_;
  assign new_n123_ = v7 & ~new_n122_;
  assign new_n124_ = ~v6 & ~new_n123_;
  assign new_n125_ = ~v6 & ~new_n124_;
  assign new_n126_ = ~new_n70_ & ~new_n125_;
  assign \v14.3  = new_n79_ | new_n126_;
  assign new_n128_ = v8 & new_n49_;
  assign new_n129_ = new_n73_ & new_n128_;
  assign new_n130_ = ~new_n72_ & ~new_n129_;
  assign new_n131_ = ~v1 & ~new_n130_;
  assign new_n132_ = ~v2 & ~v3;
  assign new_n133_ = v1 & new_n132_;
  assign new_n134_ = v4 & v8;
  assign new_n135_ = new_n49_ & new_n134_;
  assign new_n136_ = new_n133_ & new_n135_;
  assign new_n137_ = ~new_n131_ & ~new_n136_;
  assign new_n138_ = v0 & ~new_n137_;
  assign new_n139_ = ~v6 & ~v7;
  assign new_n140_ = ~v6 & ~new_n139_;
  assign new_n141_ = ~v10 & ~new_n140_;
  assign new_n142_ = ~v9 & new_n141_;
  assign new_n143_ = v8 & new_n142_;
  assign \v14.4  = new_n138_ | new_n143_;
  assign new_n145_ = v8 & ~new_n50_;
  assign new_n146_ = v8 & ~new_n145_;
  assign new_n147_ = v7 & ~new_n146_;
  assign new_n148_ = v7 & ~new_n147_;
  assign new_n149_ = ~v6 & ~new_n148_;
  assign new_n150_ = ~v6 & ~new_n149_;
  assign new_n151_ = ~new_n70_ & ~new_n150_;
  assign \v14.5  = new_n79_ | new_n151_;
  assign new_n153_ = v6 & v8;
  assign new_n154_ = new_n86_ & new_n153_;
  assign new_n155_ = v6 & ~new_n154_;
  assign new_n156_ = ~new_n78_ & ~new_n155_;
  assign new_n157_ = v7 & new_n156_;
  assign \v14.6  = v0 & new_n157_;
  assign new_n159_ = v0 & ~v1;
  assign new_n160_ = ~v2 & new_n159_;
  assign new_n161_ = ~v3 & new_n160_;
  assign \v14.7  = ~v4 & new_n161_;
  assign new_n163_ = v0 & v1;
  assign new_n164_ = ~v2 & new_n163_;
  assign new_n165_ = ~v3 & new_n164_;
  assign \v14.8  = v4 & new_n165_;
  assign new_n167_ = v8 & ~new_n119_;
  assign new_n168_ = v8 & ~new_n167_;
  assign new_n169_ = v7 & ~new_n168_;
  assign new_n170_ = v7 & ~new_n169_;
  assign new_n171_ = v6 & ~new_n170_;
  assign new_n172_ = v6 & ~new_n171_;
  assign \v14.9  = new_n79_ | ~new_n172_;
  assign new_n174_ = v3 & ~v4;
  assign new_n175_ = ~new_n63_ & ~new_n174_;
  assign new_n176_ = v2 & ~new_n175_;
  assign new_n177_ = ~v2 & new_n63_;
  assign new_n178_ = ~new_n176_ & ~new_n177_;
  assign new_n179_ = ~v1 & ~new_n178_;
  assign new_n180_ = ~v0 & new_n179_;
  assign new_n181_ = new_n163_ & new_n177_;
  assign \v14.10  = new_n180_ | new_n181_;
  assign new_n183_ = v6 & v7;
  assign new_n184_ = v8 & new_n183_;
  assign new_n185_ = v9 & new_n184_;
  assign new_n186_ = v10 & new_n185_;
  assign new_n187_ = ~v11 & new_n186_;
  assign new_n188_ = v12 & new_n187_;
  assign \v14.11  = ~v13 & new_n188_;
  assign new_n190_ = v3 & v4;
  assign new_n191_ = v3 & ~new_n190_;
  assign new_n192_ = v2 & ~new_n191_;
  assign new_n193_ = v2 & ~new_n192_;
  assign new_n194_ = v1 & ~new_n193_;
  assign new_n195_ = v1 & ~new_n194_;
  assign new_n196_ = ~v0 & ~new_n195_;
  assign \v14.13  = v0 | new_n196_;
  assign \v14.12  = \v14.11 ;
endmodule


