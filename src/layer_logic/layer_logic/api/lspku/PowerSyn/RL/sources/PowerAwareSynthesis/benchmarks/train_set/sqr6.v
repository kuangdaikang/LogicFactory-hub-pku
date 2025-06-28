// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:03 2022

module sqr6  ( 
    v0, v1, v2, v3, v4, v5,
    \v6.0 , \v6.1 , \v6.2 , \v6.3 , \v6.4 , \v6.5 , \v6.6 , \v6.7 , \v6.8 ,
    \v6.9 , \v6.10 , \v6.11   );
  input  v0, v1, v2, v3, v4, v5;
  output \v6.0 , \v6.1 , \v6.2 , \v6.3 , \v6.4 , \v6.5 , \v6.6 , \v6.7 ,
    \v6.8 , \v6.9 , \v6.10 , \v6.11 ;
  wire new_n20_, new_n21_, new_n22_, new_n23_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_,
    new_n86_, new_n87_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n113_, new_n114_, new_n115_, new_n117_, new_n118_, new_n119_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n125_, new_n126_,
    new_n127_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n136_, new_n137_, new_n138_,
    new_n139_, new_n140_, new_n141_, new_n142_, new_n143_, new_n144_,
    new_n145_, new_n146_, new_n147_, new_n148_, new_n149_, new_n150_,
    new_n151_, new_n152_, new_n153_, new_n154_, new_n155_, new_n156_,
    new_n157_, new_n158_, new_n159_, new_n160_, new_n161_, new_n163_,
    new_n164_, new_n165_, new_n166_, new_n167_, new_n168_, new_n169_,
    new_n170_, new_n171_, new_n172_, new_n173_, new_n174_, new_n176_,
    new_n177_, new_n178_, new_n180_, new_n181_;
  assign new_n20_ = ~v1 & v2;
  assign new_n21_ = v3 & v4;
  assign new_n22_ = new_n20_ & new_n21_;
  assign new_n23_ = ~v1 & ~new_n22_;
  assign \v6.0  = v0 & ~new_n23_;
  assign new_n25_ = v1 & v2;
  assign new_n26_ = ~v1 & ~v2;
  assign new_n27_ = ~new_n25_ & ~new_n26_;
  assign new_n28_ = v2 & ~v3;
  assign new_n29_ = ~v1 & new_n28_;
  assign new_n30_ = new_n27_ & ~new_n29_;
  assign new_n31_ = v3 & ~v4;
  assign new_n32_ = new_n20_ & new_n31_;
  assign new_n33_ = new_n30_ & ~new_n32_;
  assign \v6.1  = v0 & ~new_n33_;
  assign new_n35_ = ~v0 & v2;
  assign new_n36_ = ~v0 & ~new_n35_;
  assign new_n37_ = v3 & ~new_n36_;
  assign new_n38_ = ~v0 & new_n28_;
  assign new_n39_ = ~new_n37_ & ~new_n38_;
  assign new_n40_ = v1 & ~new_n39_;
  assign new_n41_ = v0 & ~v1;
  assign new_n42_ = new_n28_ & new_n41_;
  assign new_n43_ = ~new_n40_ & ~new_n42_;
  assign new_n44_ = v2 & new_n31_;
  assign new_n45_ = new_n41_ & new_n44_;
  assign new_n46_ = new_n43_ & ~new_n45_;
  assign new_n47_ = ~v0 & v3;
  assign new_n48_ = v0 & ~v3;
  assign new_n49_ = ~new_n47_ & ~new_n48_;
  assign new_n50_ = v5 & ~new_n49_;
  assign new_n51_ = v4 & new_n50_;
  assign new_n52_ = ~v2 & new_n51_;
  assign new_n53_ = v1 & new_n52_;
  assign \v6.2  = ~new_n46_ | new_n53_;
  assign new_n55_ = v2 & v3;
  assign new_n56_ = ~v2 & ~v3;
  assign new_n57_ = ~new_n55_ & ~new_n56_;
  assign new_n58_ = v1 & ~new_n57_;
  assign new_n59_ = ~v0 & new_n58_;
  assign new_n60_ = ~v2 & v3;
  assign new_n61_ = new_n41_ & new_n60_;
  assign new_n62_ = ~new_n59_ & ~new_n61_;
  assign new_n63_ = ~v2 & ~new_n60_;
  assign new_n64_ = v4 & ~new_n63_;
  assign new_n65_ = ~v3 & ~v4;
  assign new_n66_ = ~v2 & new_n65_;
  assign new_n67_ = ~new_n64_ & ~new_n66_;
  assign new_n68_ = v1 & ~new_n67_;
  assign new_n69_ = ~new_n32_ & ~new_n68_;
  assign new_n70_ = v0 & ~new_n69_;
  assign new_n71_ = ~v0 & v1;
  assign new_n72_ = ~v2 & new_n31_;
  assign new_n73_ = new_n71_ & new_n72_;
  assign new_n74_ = ~new_n70_ & ~new_n73_;
  assign new_n75_ = new_n62_ & new_n74_;
  assign new_n76_ = v2 & v5;
  assign new_n77_ = ~v1 & new_n76_;
  assign new_n78_ = ~v2 & ~v5;
  assign new_n79_ = v1 & new_n78_;
  assign new_n80_ = ~new_n77_ & ~new_n79_;
  assign new_n81_ = ~v3 & ~new_n80_;
  assign new_n82_ = v0 & new_n81_;
  assign new_n83_ = v3 & ~v5;
  assign new_n84_ = ~v2 & new_n83_;
  assign new_n85_ = new_n71_ & new_n84_;
  assign new_n86_ = ~new_n82_ & ~new_n85_;
  assign new_n87_ = v4 & ~new_n86_;
  assign \v6.3  = ~new_n75_ | new_n87_;
  assign new_n89_ = ~v0 & new_n25_;
  assign new_n90_ = v0 & new_n26_;
  assign new_n91_ = ~new_n89_ & ~new_n90_;
  assign new_n92_ = ~v0 & ~v1;
  assign new_n93_ = new_n55_ & new_n92_;
  assign new_n94_ = new_n91_ & ~new_n93_;
  assign new_n95_ = v4 & ~new_n94_;
  assign new_n96_ = v1 & ~v2;
  assign new_n97_ = ~new_n20_ & ~new_n96_;
  assign new_n98_ = ~v4 & ~new_n97_;
  assign new_n99_ = v3 & new_n98_;
  assign new_n100_ = ~new_n95_ & ~new_n99_;
  assign new_n101_ = v3 & v5;
  assign new_n102_ = ~v3 & ~v5;
  assign new_n103_ = ~new_n101_ & ~new_n102_;
  assign new_n104_ = ~new_n97_ & ~new_n103_;
  assign new_n105_ = v1 & new_n76_;
  assign new_n106_ = ~new_n104_ & ~new_n105_;
  assign new_n107_ = v4 & ~new_n106_;
  assign new_n108_ = ~v1 & ~v3;
  assign new_n109_ = ~v1 & ~new_n108_;
  assign new_n110_ = v5 & ~new_n109_;
  assign new_n111_ = ~v4 & new_n110_;
  assign new_n112_ = v2 & new_n111_;
  assign new_n113_ = ~new_n107_ & ~new_n112_;
  assign new_n114_ = v0 & ~new_n113_;
  assign new_n115_ = ~v0 & new_n96_;
  assign \v6.9  = v4 & ~v5;
  assign new_n117_ = v3 & \v6.9 ;
  assign new_n118_ = new_n115_ & new_n117_;
  assign new_n119_ = ~new_n114_ & ~new_n118_;
  assign \v6.4  = ~new_n100_ | ~new_n119_;
  assign new_n121_ = v0 & v3;
  assign new_n122_ = ~v0 & ~v3;
  assign new_n123_ = ~new_n121_ & ~new_n122_;
  assign new_n124_ = ~v2 & ~new_n123_;
  assign new_n125_ = v1 & new_n124_;
  assign new_n126_ = ~v0 & new_n20_;
  assign new_n127_ = ~new_n125_ & ~new_n126_;
  assign new_n128_ = v4 & ~new_n127_;
  assign new_n129_ = v2 & new_n65_;
  assign new_n130_ = ~v0 & new_n129_;
  assign new_n131_ = ~new_n128_ & ~new_n130_;
  assign new_n132_ = new_n71_ & new_n101_;
  assign new_n133_ = new_n41_ & new_n102_;
  assign new_n134_ = ~new_n132_ & ~new_n133_;
  assign new_n135_ = v2 & ~new_n134_;
  assign new_n136_ = ~v2 & v5;
  assign new_n137_ = ~v1 & new_n136_;
  assign new_n138_ = v0 & new_n137_;
  assign new_n139_ = ~new_n135_ & ~new_n138_;
  assign new_n140_ = ~v3 & v5;
  assign new_n141_ = v2 & new_n140_;
  assign new_n142_ = ~new_n84_ & ~new_n141_;
  assign new_n143_ = ~v0 & ~new_n142_;
  assign new_n144_ = v0 & ~v2;
  assign new_n145_ = new_n102_ & new_n144_;
  assign new_n146_ = ~new_n143_ & ~new_n145_;
  assign new_n147_ = v4 & ~new_n146_;
  assign new_n148_ = v2 & new_n102_;
  assign new_n149_ = ~new_n136_ & ~new_n148_;
  assign new_n150_ = ~v4 & ~new_n149_;
  assign new_n151_ = v0 & new_n150_;
  assign new_n152_ = ~new_n147_ & ~new_n151_;
  assign new_n153_ = v1 & ~new_n152_;
  assign new_n154_ = ~v4 & v5;
  assign new_n155_ = ~\v6.9  & ~new_n154_;
  assign new_n156_ = v3 & ~new_n155_;
  assign new_n157_ = v2 & new_n156_;
  assign new_n158_ = ~v1 & new_n157_;
  assign new_n159_ = v0 & new_n158_;
  assign new_n160_ = ~new_n153_ & ~new_n159_;
  assign new_n161_ = new_n139_ & new_n160_;
  assign \v6.5  = ~new_n131_ | ~new_n161_;
  assign new_n163_ = ~v1 & new_n55_;
  assign new_n164_ = v1 & new_n56_;
  assign new_n165_ = ~new_n163_ & ~new_n164_;
  assign new_n166_ = ~new_n28_ & ~new_n60_;
  assign new_n167_ = ~v1 & v4;
  assign new_n168_ = v1 & ~v4;
  assign new_n169_ = ~new_n167_ & ~new_n168_;
  assign new_n170_ = ~new_n166_ & ~new_n169_;
  assign new_n171_ = new_n165_ & ~new_n170_;
  assign new_n172_ = v5 & ~new_n171_;
  assign new_n173_ = ~v5 & ~new_n166_;
  assign new_n174_ = v4 & new_n173_;
  assign \v6.6  = new_n172_ | new_n174_;
  assign new_n176_ = v5 & ~new_n166_;
  assign new_n177_ = ~v4 & ~v5;
  assign new_n178_ = v3 & new_n177_;
  assign \v6.7  = new_n176_ | new_n178_;
  assign new_n180_ = ~v3 & v4;
  assign new_n181_ = ~new_n31_ & ~new_n180_;
  assign \v6.8  = v5 & ~new_n181_;
  assign \v6.10  = 1'b0;
  assign \v6.11  = v5;
endmodule


