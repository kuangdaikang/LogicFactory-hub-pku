// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:26 2022

module inc  ( 
    v0, v1, v2, v3, v4, v5, v6,
    \v7.0 , \v7.1 , \v7.2 , \v7.3 , \v7.4 , \v7.5 , \v7.6 , \v7.7 , \v7.8   );
  input  v0, v1, v2, v3, v4, v5, v6;
  output \v7.0 , \v7.1 , \v7.2 , \v7.3 , \v7.4 , \v7.5 , \v7.6 , \v7.7 ,
    \v7.8 ;
  wire new_n17_, new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_,
    new_n24_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_,
    new_n31_, new_n32_, new_n33_, new_n34_, new_n36_, new_n37_, new_n38_,
    new_n39_, new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_,
    new_n53_, new_n54_, new_n55_, new_n56_, new_n58_, new_n59_, new_n60_,
    new_n61_, new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_,
    new_n68_, new_n69_, new_n70_, new_n71_, new_n72_, new_n73_, new_n74_,
    new_n75_, new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n81_,
    new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n88_, new_n89_,
    new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_,
    new_n97_, new_n98_, new_n99_, new_n100_, new_n101_, new_n102_,
    new_n103_, new_n104_, new_n105_, new_n106_, new_n107_, new_n108_,
    new_n109_, new_n110_, new_n111_, new_n112_, new_n113_, new_n114_,
    new_n115_, new_n116_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n126_, new_n127_,
    new_n128_, new_n129_, new_n130_, new_n131_, new_n132_, new_n133_,
    new_n134_, new_n135_, new_n136_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n141_, new_n142_, new_n144_, new_n145_, new_n146_,
    new_n147_, new_n148_, new_n149_, new_n151_, new_n152_, new_n153_,
    new_n154_, new_n156_, new_n157_, new_n158_, new_n159_, new_n160_,
    new_n161_, new_n162_, new_n164_, new_n165_, new_n166_, new_n167_,
    new_n168_, new_n169_, new_n170_, new_n171_, new_n172_, new_n173_;
  assign new_n17_ = v3 & v6;
  assign new_n18_ = v3 & ~new_n17_;
  assign new_n19_ = ~v2 & ~new_n18_;
  assign new_n20_ = ~v2 & ~new_n19_;
  assign new_n21_ = ~v1 & ~new_n20_;
  assign new_n22_ = ~v2 & ~v3;
  assign new_n23_ = v1 & new_n22_;
  assign new_n24_ = ~new_n21_ & ~new_n23_;
  assign new_n25_ = v0 & ~new_n24_;
  assign new_n26_ = v3 & v5;
  assign new_n27_ = ~v3 & v6;
  assign new_n28_ = ~new_n26_ & ~new_n27_;
  assign new_n29_ = ~v2 & ~new_n28_;
  assign new_n30_ = v3 & ~v6;
  assign new_n31_ = v2 & new_n30_;
  assign new_n32_ = ~new_n29_ & ~new_n31_;
  assign new_n33_ = v1 & ~new_n32_;
  assign new_n34_ = ~v0 & new_n33_;
  assign \v7.0  = new_n25_ | new_n34_;
  assign new_n36_ = ~v1 & v2;
  assign new_n37_ = new_n26_ & new_n36_;
  assign new_n38_ = ~new_n23_ & ~new_n37_;
  assign new_n39_ = v0 & ~new_n38_;
  assign new_n40_ = v4 & v6;
  assign new_n41_ = v6 & ~new_n40_;
  assign new_n42_ = ~v4 & v6;
  assign new_n43_ = new_n41_ & ~new_n42_;
  assign new_n44_ = ~v3 & ~new_n43_;
  assign new_n45_ = ~new_n17_ & ~new_n44_;
  assign new_n46_ = v2 & ~new_n45_;
  assign new_n47_ = ~v3 & ~v6;
  assign new_n48_ = ~v3 & ~new_n47_;
  assign new_n49_ = ~v5 & ~new_n48_;
  assign new_n50_ = ~v2 & new_n49_;
  assign new_n51_ = ~new_n46_ & ~new_n50_;
  assign new_n52_ = v1 & ~new_n51_;
  assign new_n53_ = v2 & v5;
  assign new_n54_ = ~v1 & new_n53_;
  assign new_n55_ = ~new_n52_ & ~new_n54_;
  assign new_n56_ = ~v0 & ~new_n55_;
  assign \v7.1  = new_n39_ | new_n56_;
  assign new_n58_ = v1 & ~new_n41_;
  assign new_n59_ = ~v0 & new_n58_;
  assign new_n60_ = v0 & ~v1;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = ~v0 & ~v1;
  assign new_n63_ = new_n61_ & ~new_n62_;
  assign new_n64_ = ~v3 & ~new_n63_;
  assign new_n65_ = ~v1 & ~v5;
  assign new_n66_ = v1 & v6;
  assign new_n67_ = ~new_n65_ & ~new_n66_;
  assign new_n68_ = ~v0 & ~new_n67_;
  assign new_n69_ = v0 & new_n65_;
  assign new_n70_ = ~new_n68_ & ~new_n69_;
  assign new_n71_ = v3 & ~new_n70_;
  assign new_n72_ = ~new_n64_ & ~new_n71_;
  assign new_n73_ = v2 & ~new_n72_;
  assign new_n74_ = ~v3 & new_n40_;
  assign new_n75_ = ~new_n30_ & ~new_n74_;
  assign new_n76_ = v0 & ~new_n75_;
  assign new_n77_ = ~v0 & new_n26_;
  assign new_n78_ = ~new_n76_ & ~new_n77_;
  assign new_n79_ = ~v1 & ~new_n78_;
  assign new_n80_ = v5 & ~v6;
  assign new_n81_ = ~v6 & ~new_n80_;
  assign new_n82_ = ~v3 & ~new_n81_;
  assign new_n83_ = v1 & new_n82_;
  assign new_n84_ = ~v0 & new_n83_;
  assign new_n85_ = ~new_n79_ & ~new_n84_;
  assign new_n86_ = ~v2 & ~new_n85_;
  assign \v7.2  = new_n73_ | new_n86_;
  assign new_n88_ = ~v2 & v4;
  assign new_n89_ = v2 & ~v4;
  assign new_n90_ = ~v5 & v6;
  assign new_n91_ = new_n89_ & new_n90_;
  assign new_n92_ = ~new_n88_ & ~new_n91_;
  assign new_n93_ = ~v1 & ~new_n92_;
  assign new_n94_ = v5 & ~new_n41_;
  assign new_n95_ = ~new_n42_ & ~new_n94_;
  assign new_n96_ = v2 & ~new_n95_;
  assign new_n97_ = v1 & new_n96_;
  assign new_n98_ = ~new_n93_ & ~new_n97_;
  assign new_n99_ = ~v3 & ~new_n98_;
  assign new_n100_ = v1 & ~v2;
  assign new_n101_ = v2 & v6;
  assign new_n102_ = ~v1 & new_n101_;
  assign new_n103_ = ~new_n100_ & ~new_n102_;
  assign new_n104_ = v5 & ~new_n103_;
  assign new_n105_ = ~v2 & ~v5;
  assign new_n106_ = ~v2 & ~new_n105_;
  assign new_n107_ = v6 & ~new_n106_;
  assign new_n108_ = v1 & new_n107_;
  assign new_n109_ = ~new_n65_ & ~new_n108_;
  assign new_n110_ = ~new_n104_ & new_n109_;
  assign new_n111_ = v3 & ~new_n110_;
  assign new_n112_ = ~new_n99_ & ~new_n111_;
  assign new_n113_ = ~v0 & ~new_n112_;
  assign new_n114_ = ~v3 & v5;
  assign new_n115_ = v3 & ~v5;
  assign new_n116_ = ~new_n114_ & ~new_n115_;
  assign new_n117_ = v2 & ~new_n116_;
  assign new_n118_ = ~v3 & ~v4;
  assign new_n119_ = ~v3 & ~new_n118_;
  assign new_n120_ = v6 & ~new_n119_;
  assign new_n121_ = ~v2 & new_n120_;
  assign new_n122_ = ~new_n117_ & ~new_n121_;
  assign new_n123_ = ~v1 & ~new_n122_;
  assign new_n124_ = v0 & new_n123_;
  assign \v7.3  = new_n113_ | new_n124_;
  assign new_n126_ = ~v1 & new_n42_;
  assign new_n127_ = new_n41_ & ~new_n126_;
  assign new_n128_ = ~v5 & ~new_n127_;
  assign new_n129_ = v1 & new_n42_;
  assign new_n130_ = ~v1 & v5;
  assign new_n131_ = ~new_n129_ & ~new_n130_;
  assign new_n132_ = ~new_n128_ & new_n131_;
  assign new_n133_ = ~v3 & ~new_n132_;
  assign new_n134_ = ~v1 & v3;
  assign new_n135_ = ~new_n133_ & ~new_n134_;
  assign new_n136_ = v2 & ~new_n135_;
  assign new_n137_ = v1 & new_n47_;
  assign new_n138_ = ~new_n134_ & ~new_n137_;
  assign new_n139_ = v1 & new_n115_;
  assign new_n140_ = new_n138_ & ~new_n139_;
  assign new_n141_ = ~v2 & ~new_n140_;
  assign new_n142_ = ~new_n136_ & ~new_n141_;
  assign \v7.4  = ~v0 & ~new_n142_;
  assign new_n144_ = v3 & ~new_n115_;
  assign new_n145_ = v2 & ~new_n144_;
  assign new_n146_ = v0 & new_n145_;
  assign new_n147_ = ~v0 & ~v2;
  assign new_n148_ = new_n118_ & new_n147_;
  assign new_n149_ = ~new_n146_ & ~new_n148_;
  assign \v7.5  = ~v1 & ~new_n149_;
  assign new_n151_ = ~v5 & ~new_n41_;
  assign new_n152_ = ~new_n130_ & ~new_n151_;
  assign new_n153_ = ~v3 & ~new_n152_;
  assign new_n154_ = v2 & new_n153_;
  assign \v7.6  = ~v0 & new_n154_;
  assign new_n156_ = ~v3 & v4;
  assign new_n157_ = ~v0 & new_n156_;
  assign new_n158_ = ~new_n76_ & ~new_n157_;
  assign new_n159_ = ~v1 & ~new_n158_;
  assign new_n160_ = ~v0 & v1;
  assign new_n161_ = new_n27_ & new_n160_;
  assign new_n162_ = ~new_n159_ & ~new_n161_;
  assign \v7.7  = ~v2 & ~new_n162_;
  assign new_n164_ = v2 & ~new_n41_;
  assign new_n165_ = ~v2 & ~v6;
  assign new_n166_ = ~new_n164_ & ~new_n165_;
  assign new_n167_ = v2 & ~new_n89_;
  assign new_n168_ = v6 & ~new_n167_;
  assign new_n169_ = new_n166_ & ~new_n168_;
  assign new_n170_ = ~v3 & ~new_n169_;
  assign new_n171_ = ~v2 & v3;
  assign new_n172_ = ~new_n170_ & ~new_n171_;
  assign new_n173_ = v1 & ~new_n172_;
  assign \v7.8  = ~v0 & new_n173_;
endmodule


