// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:34 2022

module p82  ( 
    v0, v1, v2, v3, v4,
    \v5.0 , \v5.1 , \v5.2 , \v5.3 , \v5.4 , \v5.5 , \v5.6 , \v5.7 , \v5.8 ,
    \v5.9 , \v5.10 , \v5.11 , \v5.12 , \v5.13   );
  input  v0, v1, v2, v3, v4;
  output \v5.0 , \v5.1 , \v5.2 , \v5.3 , \v5.4 , \v5.5 , \v5.6 , \v5.7 ,
    \v5.8 , \v5.9 , \v5.10 , \v5.11 , \v5.12 , \v5.13 ;
  wire new_n20_, new_n21_, new_n22_, new_n24_, new_n25_, new_n26_, new_n29_,
    new_n30_, new_n31_, new_n33_, new_n34_, new_n35_, new_n36_, new_n37_,
    new_n38_, new_n39_, new_n40_, new_n41_, new_n42_, new_n43_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_,
    new_n54_, new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_,
    new_n61_, new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_,
    new_n68_, new_n69_, new_n70_, new_n71_, new_n73_, new_n74_, new_n75_,
    new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n81_, new_n82_,
    new_n83_, new_n84_, new_n86_, new_n87_, new_n88_, new_n89_, new_n90_,
    new_n91_, new_n92_, new_n94_, new_n95_, new_n96_, new_n97_, new_n98_,
    new_n99_, new_n100_, new_n102_, new_n103_, new_n104_, new_n106_,
    new_n107_, new_n108_, new_n109_, new_n110_, new_n111_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n127_, new_n128_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n136_, new_n137_, new_n138_,
    new_n139_, new_n140_, new_n141_, new_n142_, new_n143_;
  assign new_n20_ = ~v0 & ~v1;
  assign new_n21_ = ~v2 & new_n20_;
  assign new_n22_ = ~v3 & new_n21_;
  assign \v5.0  = ~v4 & new_n22_;
  assign new_n24_ = ~v0 & v1;
  assign new_n25_ = ~v2 & new_n24_;
  assign new_n26_ = v3 & new_n25_;
  assign \v5.1  = v4 & new_n26_;
  assign \v5.2  = ~v4 & new_n26_;
  assign new_n29_ = v0 & ~v1;
  assign new_n30_ = v2 & new_n29_;
  assign new_n31_ = v3 & new_n30_;
  assign \v5.3  = v4 & new_n31_;
  assign new_n33_ = v1 & ~v2;
  assign new_n34_ = ~v0 & new_n33_;
  assign new_n35_ = v1 & ~new_n34_;
  assign new_n36_ = v4 & ~new_n35_;
  assign new_n37_ = ~v2 & ~v4;
  assign new_n38_ = new_n24_ & new_n37_;
  assign new_n39_ = ~new_n36_ & ~new_n38_;
  assign new_n40_ = v3 & ~new_n39_;
  assign new_n41_ = ~v3 & ~v4;
  assign new_n42_ = ~v2 & new_n41_;
  assign new_n43_ = new_n29_ & new_n42_;
  assign \v5.4  = new_n40_ | new_n43_;
  assign new_n45_ = v3 & v4;
  assign new_n46_ = v0 & ~v2;
  assign new_n47_ = new_n41_ & new_n46_;
  assign new_n48_ = ~new_n45_ & ~new_n47_;
  assign new_n49_ = ~v1 & ~new_n48_;
  assign new_n50_ = v3 & ~v4;
  assign new_n51_ = ~v2 & new_n50_;
  assign new_n52_ = new_n24_ & new_n51_;
  assign \v5.5  = new_n49_ | new_n52_;
  assign new_n54_ = ~v1 & v4;
  assign new_n55_ = v1 & ~v4;
  assign new_n56_ = ~new_n54_ & ~new_n55_;
  assign new_n57_ = v2 & v3;
  assign new_n58_ = ~v2 & ~v3;
  assign new_n59_ = ~new_n57_ & ~new_n58_;
  assign new_n60_ = ~new_n56_ & ~new_n59_;
  assign new_n61_ = ~v1 & v2;
  assign new_n62_ = ~v1 & ~new_n61_;
  assign new_n63_ = v4 & ~new_n62_;
  assign new_n64_ = ~v1 & new_n37_;
  assign new_n65_ = ~new_n63_ & ~new_n64_;
  assign new_n66_ = ~v3 & ~new_n65_;
  assign new_n67_ = ~new_n60_ & ~new_n66_;
  assign new_n68_ = ~v0 & ~new_n67_;
  assign new_n69_ = ~v4 & ~new_n42_;
  assign new_n70_ = ~v1 & ~new_n69_;
  assign new_n71_ = v0 & new_n70_;
  assign \v5.6  = new_n68_ | new_n71_;
  assign new_n73_ = v0 & v2;
  assign new_n74_ = v0 & ~new_n73_;
  assign new_n75_ = ~v1 & ~new_n74_;
  assign new_n76_ = ~new_n34_ & ~new_n75_;
  assign new_n77_ = v2 & ~v4;
  assign new_n78_ = new_n24_ & new_n77_;
  assign new_n79_ = new_n76_ & ~new_n78_;
  assign new_n80_ = ~v3 & ~new_n79_;
  assign new_n81_ = v4 & ~new_n74_;
  assign new_n82_ = ~v1 & new_n81_;
  assign new_n83_ = ~new_n38_ & ~new_n82_;
  assign new_n84_ = v3 & ~new_n83_;
  assign \v5.7  = new_n80_ | new_n84_;
  assign new_n86_ = ~new_n24_ & ~new_n29_;
  assign new_n87_ = ~v3 & ~new_n86_;
  assign new_n88_ = ~v0 & new_n45_;
  assign new_n89_ = ~new_n87_ & ~new_n88_;
  assign new_n90_ = ~v2 & ~new_n89_;
  assign new_n91_ = v2 & ~new_n56_;
  assign new_n92_ = ~v0 & new_n91_;
  assign \v5.8  = new_n90_ | new_n92_;
  assign new_n94_ = ~v3 & v4;
  assign new_n95_ = v1 & new_n94_;
  assign new_n96_ = ~v1 & new_n50_;
  assign new_n97_ = ~new_n95_ & ~new_n96_;
  assign new_n98_ = ~v0 & ~new_n97_;
  assign new_n99_ = new_n29_ & new_n50_;
  assign new_n100_ = ~new_n98_ & ~new_n99_;
  assign \v5.9  = ~v2 & ~new_n100_;
  assign new_n102_ = ~new_n50_ & ~new_n94_;
  assign new_n103_ = ~v2 & ~new_n102_;
  assign new_n104_ = ~v1 & new_n103_;
  assign \v5.10  = ~v0 & new_n104_;
  assign new_n106_ = v0 & v4;
  assign new_n107_ = v0 & ~new_n106_;
  assign new_n108_ = ~v1 & ~new_n107_;
  assign new_n109_ = ~v0 & new_n55_;
  assign new_n110_ = ~new_n108_ & ~new_n109_;
  assign new_n111_ = ~v3 & ~new_n110_;
  assign \v5.11  = ~v2 & new_n111_;
  assign new_n113_ = v1 & v2;
  assign new_n114_ = ~v0 & new_n113_;
  assign new_n115_ = ~v1 & ~v2;
  assign new_n116_ = v0 & new_n115_;
  assign new_n117_ = ~new_n114_ & ~new_n116_;
  assign new_n118_ = ~new_n102_ & ~new_n117_;
  assign new_n119_ = v1 & v4;
  assign new_n120_ = ~v1 & ~v4;
  assign new_n121_ = ~new_n119_ & ~new_n120_;
  assign new_n122_ = ~v2 & ~new_n121_;
  assign new_n123_ = new_n56_ & ~new_n122_;
  assign new_n124_ = ~v0 & ~new_n123_;
  assign new_n125_ = v2 & v4;
  assign new_n126_ = new_n29_ & new_n125_;
  assign new_n127_ = ~new_n124_ & ~new_n126_;
  assign new_n128_ = ~v3 & ~new_n127_;
  assign \v5.12  = new_n118_ | new_n128_;
  assign new_n130_ = ~v2 & new_n94_;
  assign new_n131_ = v2 & new_n50_;
  assign new_n132_ = ~new_n130_ & ~new_n131_;
  assign new_n133_ = v0 & ~new_n132_;
  assign new_n134_ = v2 & ~new_n57_;
  assign new_n135_ = ~v4 & ~new_n134_;
  assign new_n136_ = ~v0 & new_n135_;
  assign new_n137_ = ~new_n133_ & ~new_n136_;
  assign new_n138_ = ~v1 & ~new_n137_;
  assign new_n139_ = ~new_n41_ & ~new_n45_;
  assign new_n140_ = v2 & ~new_n139_;
  assign new_n141_ = ~new_n42_ & ~new_n140_;
  assign new_n142_ = v1 & ~new_n141_;
  assign new_n143_ = ~v0 & new_n142_;
  assign \v5.13  = new_n138_ | new_n143_;
endmodule


