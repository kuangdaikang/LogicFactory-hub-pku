// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:26 2022

module 5xp1  ( 
    i_0_, i_1_, i_2_, i_3_, i_4_, i_5_, i_6_,
    o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_, o_8_, o_9_  );
  input  i_0_, i_1_, i_2_, i_3_, i_4_, i_5_, i_6_;
  output o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_, o_8_, o_9_;
  wire new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_,
    new_n25_, new_n26_, new_n27_, new_n28_, new_n30_, new_n31_, new_n32_,
    new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_,
    new_n47_, new_n48_, new_n49_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_,
    new_n69_, new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_,
    new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n81_, new_n82_,
    new_n83_, new_n84_, new_n85_, new_n86_, new_n87_, new_n88_, new_n90_,
    new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_, new_n97_,
    new_n98_, new_n99_, new_n100_, new_n101_, new_n102_, new_n103_,
    new_n104_, new_n105_, new_n106_, new_n107_, new_n108_, new_n109_,
    new_n110_, new_n111_, new_n112_, new_n113_, new_n114_, new_n115_,
    new_n116_, new_n117_, new_n118_, new_n120_, new_n121_, new_n122_,
    new_n123_, new_n124_, new_n125_, new_n126_, new_n127_, new_n128_,
    new_n129_, new_n130_, new_n131_, new_n132_, new_n134_, new_n135_,
    new_n136_, new_n137_, new_n138_, new_n139_, new_n140_, new_n141_,
    new_n142_, new_n144_, new_n145_;
  assign new_n18_ = i_2_ & i_3_;
  assign new_n19_ = i_1_ & new_n18_;
  assign new_n20_ = ~i_6_ & ~new_n19_;
  assign new_n21_ = ~i_0_ & new_n20_;
  assign new_n22_ = i_5_ & ~new_n21_;
  assign new_n23_ = i_4_ & ~new_n22_;
  assign new_n24_ = ~i_1_ & ~new_n18_;
  assign new_n25_ = ~i_0_ & new_n24_;
  assign new_n26_ = i_6_ & ~new_n25_;
  assign new_n27_ = i_5_ & new_n26_;
  assign new_n28_ = ~i_4_ & new_n27_;
  assign o_0_ = new_n23_ | new_n28_;
  assign new_n30_ = i_1_ & i_4_;
  assign new_n31_ = ~i_6_ & ~new_n30_;
  assign new_n32_ = i_2_ & ~new_n31_;
  assign new_n33_ = i_3_ & i_4_;
  assign new_n34_ = ~i_6_ & ~new_n33_;
  assign new_n35_ = i_1_ & ~new_n34_;
  assign new_n36_ = ~new_n32_ & ~new_n35_;
  assign new_n37_ = i_0_ & ~new_n36_;
  assign new_n38_ = i_4_ & i_6_;
  assign new_n39_ = ~new_n37_ & ~new_n38_;
  assign new_n40_ = ~i_5_ & ~new_n39_;
  assign new_n41_ = ~i_1_ & ~i_4_;
  assign new_n42_ = i_6_ & ~new_n41_;
  assign new_n43_ = ~new_n18_ & ~new_n42_;
  assign new_n44_ = ~i_1_ & ~i_6_;
  assign new_n45_ = ~new_n43_ & ~new_n44_;
  assign new_n46_ = ~i_0_ & ~new_n45_;
  assign new_n47_ = ~i_4_ & ~i_6_;
  assign new_n48_ = ~new_n46_ & ~new_n47_;
  assign new_n49_ = i_5_ & ~new_n48_;
  assign o_1_ = new_n40_ | new_n49_;
  assign new_n51_ = ~i_2_ & ~i_3_;
  assign new_n52_ = i_0_ & ~new_n51_;
  assign new_n53_ = i_3_ & i_5_;
  assign new_n54_ = i_2_ & new_n53_;
  assign new_n55_ = ~new_n52_ & ~new_n54_;
  assign new_n56_ = i_1_ & ~new_n55_;
  assign new_n57_ = i_0_ & i_5_;
  assign new_n58_ = ~new_n56_ & ~new_n57_;
  assign new_n59_ = ~i_4_ & ~new_n58_;
  assign new_n60_ = ~i_3_ & ~i_5_;
  assign new_n61_ = i_0_ & ~new_n60_;
  assign new_n62_ = ~i_2_ & ~new_n61_;
  assign new_n63_ = ~i_0_ & ~new_n53_;
  assign new_n64_ = ~i_1_ & ~i_5_;
  assign new_n65_ = ~new_n63_ & ~new_n64_;
  assign new_n66_ = ~new_n62_ & new_n65_;
  assign new_n67_ = i_4_ & ~new_n66_;
  assign new_n68_ = ~new_n59_ & ~new_n67_;
  assign new_n69_ = ~i_6_ & ~new_n68_;
  assign new_n70_ = ~i_0_ & ~i_5_;
  assign new_n71_ = i_1_ & ~new_n70_;
  assign new_n72_ = ~i_2_ & ~i_5_;
  assign new_n73_ = i_0_ & ~new_n72_;
  assign new_n74_ = ~new_n71_ & ~new_n73_;
  assign new_n75_ = i_4_ & ~new_n74_;
  assign new_n76_ = ~i_0_ & ~new_n18_;
  assign new_n77_ = ~new_n72_ & ~new_n76_;
  assign new_n78_ = ~i_1_ & ~new_n77_;
  assign new_n79_ = ~new_n70_ & ~new_n78_;
  assign new_n80_ = ~i_4_ & ~new_n79_;
  assign new_n81_ = ~new_n75_ & ~new_n80_;
  assign new_n82_ = i_6_ & ~new_n81_;
  assign new_n83_ = ~i_1_ & i_2_;
  assign new_n84_ = ~i_0_ & new_n83_;
  assign new_n85_ = i_4_ & i_5_;
  assign new_n86_ = i_3_ & new_n85_;
  assign new_n87_ = new_n84_ & new_n86_;
  assign new_n88_ = ~new_n82_ & ~new_n87_;
  assign o_2_ = new_n69_ | ~new_n88_;
  assign new_n90_ = i_3_ & ~i_5_;
  assign new_n91_ = ~i_0_ & new_n90_;
  assign new_n92_ = ~new_n57_ & ~new_n91_;
  assign new_n93_ = ~new_n44_ & ~new_n92_;
  assign new_n94_ = i_2_ & new_n93_;
  assign new_n95_ = ~i_3_ & ~i_6_;
  assign new_n96_ = i_5_ & ~new_n95_;
  assign new_n97_ = i_0_ & new_n96_;
  assign new_n98_ = ~i_5_ & i_6_;
  assign new_n99_ = ~i_0_ & new_n98_;
  assign new_n100_ = ~new_n97_ & ~new_n99_;
  assign new_n101_ = i_1_ & ~new_n100_;
  assign new_n102_ = i_2_ & i_6_;
  assign new_n103_ = ~i_0_ & i_5_;
  assign new_n104_ = i_0_ & ~i_5_;
  assign new_n105_ = ~new_n103_ & ~new_n104_;
  assign new_n106_ = ~new_n102_ & ~new_n105_;
  assign new_n107_ = ~i_3_ & i_5_;
  assign new_n108_ = ~i_0_ & new_n107_;
  assign new_n109_ = ~new_n106_ & ~new_n108_;
  assign new_n110_ = ~i_1_ & ~new_n109_;
  assign new_n111_ = i_5_ & ~new_n18_;
  assign new_n112_ = ~i_0_ & new_n111_;
  assign new_n113_ = i_0_ & ~i_2_;
  assign new_n114_ = new_n60_ & new_n113_;
  assign new_n115_ = ~new_n112_ & ~new_n114_;
  assign new_n116_ = ~i_6_ & ~new_n115_;
  assign new_n117_ = ~new_n110_ & ~new_n116_;
  assign new_n118_ = ~new_n101_ & new_n117_;
  assign o_3_ = new_n94_ | ~new_n118_;
  assign new_n120_ = ~new_n18_ & ~new_n52_;
  assign new_n121_ = i_6_ & ~new_n120_;
  assign new_n122_ = ~new_n51_ & ~new_n76_;
  assign new_n123_ = ~i_6_ & ~new_n122_;
  assign new_n124_ = ~new_n121_ & ~new_n123_;
  assign new_n125_ = i_1_ & ~new_n124_;
  assign new_n126_ = ~i_0_ & ~i_3_;
  assign new_n127_ = ~i_6_ & ~new_n126_;
  assign new_n128_ = i_2_ & new_n127_;
  assign new_n129_ = i_2_ & ~new_n126_;
  assign new_n130_ = i_6_ & ~new_n129_;
  assign new_n131_ = ~new_n128_ & ~new_n130_;
  assign new_n132_ = ~i_1_ & ~new_n131_;
  assign o_4_ = new_n125_ | new_n132_;
  assign new_n134_ = ~i_2_ & i_3_;
  assign new_n135_ = i_1_ & new_n134_;
  assign new_n136_ = i_2_ & ~i_3_;
  assign new_n137_ = ~new_n135_ & ~new_n136_;
  assign new_n138_ = ~i_0_ & ~new_n137_;
  assign new_n139_ = i_1_ & i_3_;
  assign new_n140_ = ~i_2_ & ~new_n139_;
  assign new_n141_ = ~new_n18_ & ~new_n140_;
  assign new_n142_ = i_0_ & ~new_n141_;
  assign o_5_ = new_n138_ | new_n142_;
  assign new_n144_ = ~i_1_ & new_n134_;
  assign new_n145_ = i_1_ & ~new_n134_;
  assign o_6_ = new_n144_ | new_n145_;
  assign o_7_ = new_n134_ | new_n136_;
  assign o_9_ = i_4_ & new_n22_;
  assign o_8_ = ~i_3_;
endmodule


