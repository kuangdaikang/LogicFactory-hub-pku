// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:39 2022

module bw  ( 
    i_0_, i_1_, i_2_, i_3_, i_4_,
    o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_, o_8_, o_9_, o_10_,
    o_11_, o_12_, o_13_, o_14_, o_15_, o_16_, o_17_, o_18_, o_19_, o_20_,
    o_21_, o_22_, o_23_, o_24_, o_25_, o_26_, o_27_  );
  input  i_0_, i_1_, i_2_, i_3_, i_4_;
  output o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_, o_8_, o_9_, o_10_,
    o_11_, o_12_, o_13_, o_14_, o_15_, o_16_, o_17_, o_18_, o_19_, o_20_,
    o_21_, o_22_, o_23_, o_24_, o_25_, o_26_, o_27_;
  wire new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_,
    new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n48_,
    new_n49_, new_n50_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n73_, new_n74_, new_n75_, new_n76_, new_n78_, new_n79_, new_n80_,
    new_n81_, new_n82_, new_n84_, new_n85_, new_n86_, new_n87_, new_n88_,
    new_n89_, new_n90_, new_n91_, new_n92_, new_n94_, new_n95_, new_n96_,
    new_n97_, new_n98_, new_n100_, new_n101_, new_n102_, new_n103_,
    new_n104_, new_n105_, new_n106_, new_n108_, new_n109_, new_n110_,
    new_n112_, new_n113_, new_n114_, new_n115_, new_n117_, new_n118_,
    new_n119_, new_n120_, new_n121_, new_n122_, new_n123_, new_n125_,
    new_n126_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n142_, new_n143_, new_n144_, new_n145_, new_n146_,
    new_n148_, new_n150_, new_n151_, new_n152_, new_n153_, new_n154_,
    new_n155_, new_n156_, new_n157_, new_n158_, new_n159_, new_n161_,
    new_n162_, new_n163_, new_n164_, new_n165_, new_n166_, new_n167_,
    new_n169_, new_n170_, new_n171_, new_n172_, new_n174_, new_n175_,
    new_n176_, new_n177_, new_n178_, new_n179_, new_n180_, new_n182_,
    new_n183_, new_n185_, new_n186_, new_n187_, new_n188_, new_n189_,
    new_n191_, new_n192_, new_n193_, new_n194_, new_n195_, new_n196_,
    new_n197_, new_n198_, new_n199_, new_n201_, new_n202_, new_n204_,
    new_n205_, new_n206_, new_n208_, new_n209_, new_n211_, new_n212_;
  assign new_n34_ = ~i_3_ & i_4_;
  assign new_n35_ = i_3_ & ~i_4_;
  assign new_n36_ = i_1_ & new_n35_;
  assign new_n37_ = ~new_n34_ & ~new_n36_;
  assign new_n38_ = i_0_ & ~new_n37_;
  assign new_n39_ = i_1_ & new_n34_;
  assign new_n40_ = ~new_n38_ & ~new_n39_;
  assign new_n41_ = ~i_2_ & ~new_n40_;
  assign new_n42_ = ~i_1_ & ~i_3_;
  assign new_n43_ = ~i_4_ & ~new_n42_;
  assign new_n44_ = ~new_n34_ & ~new_n43_;
  assign new_n45_ = i_2_ & ~new_n44_;
  assign new_n46_ = ~i_0_ & new_n45_;
  assign o_0_ = new_n41_ | new_n46_;
  assign new_n48_ = i_3_ & i_4_;
  assign new_n49_ = ~i_0_ & ~new_n48_;
  assign new_n50_ = i_2_ & ~new_n49_;
  assign o_1_ = i_1_ & ~new_n50_;
  assign new_n52_ = ~i_1_ & new_n34_;
  assign new_n53_ = ~new_n35_ & ~new_n52_;
  assign new_n54_ = ~i_0_ & ~new_n53_;
  assign new_n55_ = ~i_3_ & ~i_4_;
  assign new_n56_ = i_0_ & new_n55_;
  assign new_n57_ = ~new_n54_ & ~new_n56_;
  assign o_2_ = ~i_2_ & ~new_n57_;
  assign new_n59_ = i_0_ & ~new_n34_;
  assign new_n60_ = ~i_0_ & new_n34_;
  assign new_n61_ = ~new_n35_ & ~new_n60_;
  assign new_n62_ = ~new_n59_ & new_n61_;
  assign new_n63_ = ~i_2_ & ~new_n62_;
  assign new_n64_ = ~i_0_ & i_2_;
  assign new_n65_ = new_n55_ & new_n64_;
  assign o_3_ = new_n63_ | new_n65_;
  assign new_n67_ = i_1_ & i_4_;
  assign new_n68_ = i_3_ & ~new_n67_;
  assign new_n69_ = i_0_ & new_n68_;
  assign new_n70_ = ~i_1_ & i_4_;
  assign new_n71_ = ~i_0_ & new_n70_;
  assign new_n72_ = ~new_n69_ & ~new_n71_;
  assign new_n73_ = ~i_2_ & ~new_n72_;
  assign new_n74_ = ~i_0_ & ~i_1_;
  assign new_n75_ = i_2_ & new_n35_;
  assign new_n76_ = new_n74_ & new_n75_;
  assign o_4_ = new_n73_ | new_n76_;
  assign new_n78_ = i_2_ & ~i_3_;
  assign new_n79_ = i_4_ & ~new_n78_;
  assign new_n80_ = ~i_0_ & ~new_n79_;
  assign new_n81_ = ~i_0_ & new_n42_;
  assign new_n82_ = ~i_2_ & ~new_n81_;
  assign o_5_ = new_n80_ | new_n82_;
  assign new_n84_ = i_0_ & ~i_2_;
  assign new_n85_ = i_2_ & ~i_4_;
  assign new_n86_ = ~i_0_ & new_n85_;
  assign new_n87_ = ~new_n84_ & ~new_n86_;
  assign new_n88_ = ~new_n42_ & ~new_n87_;
  assign new_n89_ = i_1_ & i_3_;
  assign new_n90_ = ~i_0_ & ~new_n89_;
  assign new_n91_ = i_4_ & ~new_n90_;
  assign new_n92_ = ~i_2_ & new_n91_;
  assign o_6_ = new_n88_ | new_n92_;
  assign new_n94_ = ~i_2_ & i_3_;
  assign new_n95_ = i_1_ & new_n94_;
  assign new_n96_ = ~i_0_ & ~new_n95_;
  assign new_n97_ = i_0_ & new_n94_;
  assign new_n98_ = ~new_n96_ & ~new_n97_;
  assign o_7_ = ~i_4_ & ~new_n98_;
  assign new_n100_ = ~i_2_ & i_4_;
  assign new_n101_ = ~new_n86_ & ~new_n100_;
  assign new_n102_ = ~i_3_ & ~new_n101_;
  assign new_n103_ = ~i_1_ & new_n102_;
  assign new_n104_ = i_0_ & i_4_;
  assign new_n105_ = ~new_n43_ & ~new_n104_;
  assign new_n106_ = ~i_2_ & ~new_n105_;
  assign o_8_ = new_n103_ | new_n106_;
  assign new_n108_ = i_1_ & ~i_3_;
  assign new_n109_ = i_4_ & ~new_n108_;
  assign new_n110_ = ~i_0_ & ~new_n109_;
  assign o_9_ = ~i_2_ | new_n110_;
  assign new_n112_ = ~i_1_ & i_3_;
  assign new_n113_ = ~new_n108_ & ~new_n112_;
  assign new_n114_ = ~i_4_ & ~new_n113_;
  assign new_n115_ = ~i_2_ & new_n114_;
  assign o_10_ = ~i_0_ & new_n115_;
  assign new_n117_ = ~i_2_ & ~i_3_;
  assign new_n118_ = i_2_ & i_3_;
  assign new_n119_ = ~i_0_ & ~new_n118_;
  assign new_n120_ = ~new_n117_ & ~new_n119_;
  assign new_n121_ = ~i_4_ & ~new_n120_;
  assign new_n122_ = ~i_2_ & new_n48_;
  assign new_n123_ = ~new_n121_ & ~new_n122_;
  assign o_11_ = ~i_1_ & ~new_n123_;
  assign new_n125_ = i_4_ & ~new_n42_;
  assign new_n126_ = ~i_0_ & ~new_n125_;
  assign o_12_ = ~i_2_ | new_n126_;
  assign new_n128_ = ~i_4_ & ~new_n89_;
  assign new_n129_ = i_0_ & ~new_n128_;
  assign new_n130_ = ~i_0_ & i_1_;
  assign new_n131_ = new_n55_ & new_n130_;
  assign new_n132_ = ~new_n129_ & ~new_n131_;
  assign new_n133_ = ~i_2_ & ~new_n132_;
  assign new_n134_ = i_2_ & new_n55_;
  assign new_n135_ = new_n74_ & new_n134_;
  assign o_13_ = new_n133_ | new_n135_;
  assign new_n137_ = ~new_n48_ & ~new_n55_;
  assign new_n138_ = ~i_2_ & ~new_n137_;
  assign new_n139_ = i_1_ & new_n138_;
  assign new_n140_ = i_0_ & new_n139_;
  assign o_14_ = new_n65_ | new_n140_;
  assign new_n142_ = i_1_ & ~i_4_;
  assign new_n143_ = i_3_ & ~new_n142_;
  assign new_n144_ = ~new_n108_ & ~new_n143_;
  assign new_n145_ = ~i_2_ & ~new_n144_;
  assign new_n146_ = ~new_n75_ & ~new_n145_;
  assign o_15_ = ~i_0_ & ~new_n146_;
  assign new_n148_ = ~i_0_ & ~new_n143_;
  assign o_16_ = ~i_2_ | new_n148_;
  assign new_n150_ = ~i_0_ & ~i_3_;
  assign new_n151_ = ~new_n104_ & ~new_n150_;
  assign new_n152_ = i_1_ & ~new_n151_;
  assign new_n153_ = ~i_1_ & new_n55_;
  assign new_n154_ = ~new_n48_ & ~new_n153_;
  assign new_n155_ = i_0_ & ~new_n154_;
  assign new_n156_ = ~new_n35_ & ~new_n70_;
  assign new_n157_ = ~i_0_ & ~new_n156_;
  assign new_n158_ = ~new_n155_ & ~new_n157_;
  assign new_n159_ = ~new_n152_ & new_n158_;
  assign o_17_ = ~i_2_ & ~new_n159_;
  assign new_n161_ = ~i_2_ & new_n35_;
  assign new_n162_ = ~new_n78_ & ~new_n161_;
  assign new_n163_ = ~i_0_ & ~new_n162_;
  assign new_n164_ = ~i_0_ & ~i_4_;
  assign new_n165_ = ~i_3_ & ~new_n164_;
  assign new_n166_ = ~i_2_ & new_n165_;
  assign new_n167_ = ~new_n163_ & ~new_n166_;
  assign o_18_ = ~i_1_ & ~new_n167_;
  assign new_n169_ = ~i_4_ & ~new_n108_;
  assign new_n170_ = ~new_n60_ & ~new_n169_;
  assign new_n171_ = ~new_n59_ & new_n170_;
  assign new_n172_ = ~i_2_ & ~new_n171_;
  assign o_19_ = new_n65_ | new_n172_;
  assign new_n174_ = ~new_n34_ & ~new_n35_;
  assign new_n175_ = i_2_ & ~new_n174_;
  assign new_n176_ = ~i_2_ & new_n55_;
  assign new_n177_ = ~new_n175_ & ~new_n176_;
  assign new_n178_ = ~i_0_ & ~new_n177_;
  assign new_n179_ = i_4_ & ~new_n150_;
  assign new_n180_ = ~i_2_ & new_n179_;
  assign o_20_ = new_n178_ | new_n180_;
  assign new_n182_ = i_2_ & new_n130_;
  assign new_n183_ = ~i_3_ & new_n182_;
  assign o_21_ = ~i_4_ & new_n183_;
  assign new_n185_ = ~new_n48_ & ~new_n128_;
  assign new_n186_ = ~i_2_ & ~new_n185_;
  assign new_n187_ = ~new_n175_ & ~new_n186_;
  assign new_n188_ = ~i_0_ & ~new_n187_;
  assign new_n189_ = new_n34_ & new_n84_;
  assign o_22_ = new_n188_ | new_n189_;
  assign new_n191_ = ~i_1_ & ~i_4_;
  assign new_n192_ = ~new_n67_ & ~new_n191_;
  assign new_n193_ = i_0_ & ~new_n192_;
  assign new_n194_ = ~i_0_ & new_n142_;
  assign new_n195_ = ~new_n193_ & ~new_n194_;
  assign new_n196_ = i_3_ & ~new_n195_;
  assign new_n197_ = ~new_n71_ & ~new_n196_;
  assign new_n198_ = ~i_2_ & ~new_n197_;
  assign new_n199_ = new_n74_ & new_n85_;
  assign o_23_ = new_n198_ | new_n199_;
  assign new_n201_ = ~i_1_ & new_n35_;
  assign new_n202_ = ~i_2_ & ~new_n201_;
  assign o_24_ = new_n49_ | new_n202_;
  assign new_n204_ = i_4_ & ~new_n113_;
  assign new_n205_ = ~new_n155_ & ~new_n204_;
  assign new_n206_ = ~i_2_ & ~new_n205_;
  assign o_25_ = new_n86_ | new_n206_;
  assign new_n208_ = ~i_0_ & new_n128_;
  assign new_n209_ = ~i_2_ & ~new_n208_;
  assign o_26_ = new_n135_ | new_n209_;
  assign new_n211_ = ~i_2_ & new_n74_;
  assign new_n212_ = ~i_3_ & new_n211_;
  assign o_27_ = ~i_4_ & new_n212_;
endmodule


