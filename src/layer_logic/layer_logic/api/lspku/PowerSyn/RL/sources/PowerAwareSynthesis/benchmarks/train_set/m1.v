// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:36 2022

module m1  ( 
    v0, v1, v2, v3, v4, v5,
    \v6.0 , \v6.1 , \v6.2 , \v6.3 , \v6.4 , \v6.5 , \v6.6 , \v6.7 , \v6.8 ,
    \v6.9 , \v6.10 , \v6.11   );
  input  v0, v1, v2, v3, v4, v5;
  output \v6.0 , \v6.1 , \v6.2 , \v6.3 , \v6.4 , \v6.5 , \v6.6 , \v6.7 ,
    \v6.8 , \v6.9 , \v6.10 , \v6.11 ;
  wire new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_, new_n25_,
    new_n27_, new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_,
    new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_,
    new_n41_, new_n42_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n73_, new_n74_, new_n75_, new_n77_, new_n78_, new_n79_, new_n80_,
    new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n87_,
    new_n88_, new_n89_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_,
    new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n111_, new_n112_, new_n113_, new_n114_,
    new_n115_, new_n116_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n125_;
  assign new_n19_ = ~v1 & v2;
  assign new_n20_ = ~v1 & ~new_n19_;
  assign new_n21_ = ~v1 & ~v2;
  assign new_n22_ = v4 & v5;
  assign new_n23_ = v3 & new_n22_;
  assign new_n24_ = new_n21_ & new_n23_;
  assign new_n25_ = new_n20_ & ~new_n24_;
  assign \v6.3  = ~v0 & ~new_n25_;
  assign new_n27_ = ~v3 & v4;
  assign new_n28_ = v3 & ~v4;
  assign new_n29_ = ~new_n27_ & ~new_n28_;
  assign new_n30_ = ~v1 & ~new_n21_;
  assign new_n31_ = ~new_n29_ & ~new_n30_;
  assign new_n32_ = v3 & v4;
  assign new_n33_ = ~v3 & ~v4;
  assign new_n34_ = ~new_n32_ & ~new_n33_;
  assign new_n35_ = v1 & ~new_n34_;
  assign new_n36_ = new_n19_ & new_n32_;
  assign new_n37_ = ~new_n35_ & ~new_n36_;
  assign new_n38_ = ~new_n31_ & new_n37_;
  assign new_n39_ = v4 & ~v5;
  assign new_n40_ = v3 & new_n39_;
  assign new_n41_ = new_n21_ & new_n40_;
  assign new_n42_ = new_n38_ & ~new_n41_;
  assign \v6.4  = ~v0 & ~new_n42_;
  assign new_n44_ = v2 & ~new_n29_;
  assign new_n45_ = ~v2 & new_n28_;
  assign new_n46_ = ~new_n44_ & ~new_n45_;
  assign new_n47_ = v2 & ~new_n34_;
  assign new_n48_ = ~v2 & new_n32_;
  assign new_n49_ = ~new_n47_ & ~new_n48_;
  assign new_n50_ = v1 & ~new_n49_;
  assign new_n51_ = new_n21_ & new_n33_;
  assign new_n52_ = ~new_n50_ & ~new_n51_;
  assign new_n53_ = new_n46_ & new_n52_;
  assign new_n54_ = ~new_n41_ & new_n53_;
  assign \v6.5  = ~v0 & ~new_n54_;
  assign new_n56_ = ~v0 & ~v1;
  assign new_n57_ = ~v2 & new_n56_;
  assign new_n58_ = ~v3 & new_n57_;
  assign new_n59_ = ~v4 & new_n58_;
  assign \v6.6  = ~v5 & new_n59_;
  assign new_n61_ = v4 & ~new_n39_;
  assign new_n62_ = ~v3 & ~new_n61_;
  assign new_n63_ = ~v2 & new_n62_;
  assign new_n64_ = ~v1 & new_n63_;
  assign \v6.7  = ~v0 & new_n64_;
  assign new_n66_ = ~v3 & v5;
  assign new_n67_ = v3 & ~v5;
  assign new_n68_ = ~new_n66_ & ~new_n67_;
  assign new_n69_ = v3 & v5;
  assign new_n70_ = ~v3 & ~v5;
  assign new_n71_ = ~new_n69_ & ~new_n70_;
  assign new_n72_ = ~v4 & ~new_n71_;
  assign new_n73_ = new_n68_ & ~new_n72_;
  assign new_n74_ = ~v2 & ~new_n73_;
  assign new_n75_ = ~v1 & new_n74_;
  assign \v6.8  = ~v0 & new_n75_;
  assign new_n77_ = ~v4 & ~v5;
  assign new_n78_ = ~new_n22_ & ~new_n77_;
  assign new_n79_ = v2 & ~v3;
  assign new_n80_ = v2 & ~new_n79_;
  assign new_n81_ = ~new_n78_ & ~new_n80_;
  assign new_n82_ = ~v4 & v5;
  assign new_n83_ = ~new_n39_ & ~new_n82_;
  assign new_n84_ = ~v3 & ~new_n83_;
  assign new_n85_ = v3 & new_n77_;
  assign new_n86_ = ~new_n84_ & ~new_n85_;
  assign new_n87_ = v2 & ~new_n86_;
  assign new_n88_ = ~new_n81_ & ~new_n87_;
  assign new_n89_ = ~v1 & ~new_n88_;
  assign \v6.9  = ~v0 & new_n89_;
  assign new_n91_ = ~v1 & v4;
  assign new_n92_ = ~v1 & ~new_n91_;
  assign new_n93_ = ~v2 & ~new_n92_;
  assign new_n94_ = v2 & ~v4;
  assign new_n95_ = ~v1 & new_n94_;
  assign new_n96_ = ~new_n93_ & ~new_n95_;
  assign new_n97_ = ~v3 & ~new_n96_;
  assign new_n98_ = ~new_n36_ & ~new_n97_;
  assign new_n99_ = ~v3 & new_n77_;
  assign new_n100_ = ~new_n69_ & ~new_n99_;
  assign new_n101_ = ~v1 & ~new_n100_;
  assign new_n102_ = v1 & v3;
  assign new_n103_ = new_n77_ & new_n102_;
  assign new_n104_ = ~new_n101_ & ~new_n103_;
  assign new_n105_ = ~v2 & ~new_n104_;
  assign new_n106_ = v3 & new_n82_;
  assign new_n107_ = new_n19_ & new_n106_;
  assign new_n108_ = ~new_n105_ & ~new_n107_;
  assign new_n109_ = new_n98_ & new_n108_;
  assign \v6.10  = ~v0 & ~new_n109_;
  assign new_n111_ = v1 & v2;
  assign new_n112_ = ~new_n21_ & ~new_n111_;
  assign new_n113_ = ~new_n34_ & ~new_n112_;
  assign new_n114_ = ~new_n44_ & ~new_n48_;
  assign new_n115_ = v1 & ~new_n114_;
  assign new_n116_ = ~new_n36_ & ~new_n115_;
  assign new_n117_ = ~new_n113_ & new_n116_;
  assign new_n118_ = ~v3 & new_n39_;
  assign new_n119_ = ~new_n106_ & ~new_n118_;
  assign new_n120_ = v2 & ~new_n119_;
  assign new_n121_ = ~v1 & new_n120_;
  assign new_n122_ = v1 & ~v2;
  assign new_n123_ = new_n106_ & new_n122_;
  assign new_n124_ = ~new_n121_ & ~new_n123_;
  assign new_n125_ = new_n117_ & new_n124_;
  assign \v6.11  = ~v0 & ~new_n125_;
  assign \v6.0  = ~v0;
  assign \v6.1  = \v6.0 ;
  assign \v6.2  = \v6.0 ;
endmodule


