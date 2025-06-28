// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:31 2022

module sqn  ( 
    v0, v1, v2, v3, v4, v5, v6,
    \v7.0 , \v7.1 , \v7.2   );
  input  v0, v1, v2, v3, v4, v5, v6;
  output \v7.0 , \v7.1 , \v7.2 ;
  wire new_n11_, new_n12_, new_n13_, new_n14_, new_n15_, new_n16_, new_n17_,
    new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_,
    new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n31_,
    new_n32_, new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_,
    new_n39_, new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n51_, new_n52_, new_n53_,
    new_n54_, new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_,
    new_n61_, new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_,
    new_n68_, new_n69_, new_n70_, new_n71_, new_n72_, new_n73_, new_n74_,
    new_n75_, new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n81_,
    new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n87_, new_n88_,
    new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_,
    new_n96_, new_n97_, new_n99_, new_n100_, new_n101_, new_n102_,
    new_n103_, new_n104_, new_n105_, new_n106_, new_n107_, new_n108_,
    new_n109_, new_n110_, new_n111_, new_n112_, new_n113_, new_n114_,
    new_n115_, new_n116_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n125_, new_n126_,
    new_n127_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n136_, new_n137_, new_n138_,
    new_n139_, new_n140_, new_n141_, new_n142_, new_n143_, new_n144_,
    new_n145_, new_n146_, new_n147_, new_n148_;
  assign new_n11_ = ~v4 & v6;
  assign new_n12_ = v1 & new_n11_;
  assign new_n13_ = v4 & ~v6;
  assign new_n14_ = ~v1 & new_n13_;
  assign new_n15_ = ~new_n12_ & ~new_n14_;
  assign new_n16_ = ~v0 & v2;
  assign new_n17_ = ~v0 & ~new_n16_;
  assign new_n18_ = ~v2 & ~v3;
  assign new_n19_ = ~v0 & new_n18_;
  assign new_n20_ = new_n17_ & ~new_n19_;
  assign new_n21_ = ~v5 & ~new_n20_;
  assign new_n22_ = v0 & v2;
  assign new_n23_ = ~v3 & v5;
  assign new_n24_ = new_n22_ & new_n23_;
  assign new_n25_ = ~new_n21_ & ~new_n24_;
  assign new_n26_ = ~new_n15_ & ~new_n25_;
  assign new_n27_ = v4 & v6;
  assign new_n28_ = v1 & new_n27_;
  assign new_n29_ = ~v4 & ~v6;
  assign new_n30_ = ~v1 & new_n29_;
  assign new_n31_ = ~new_n28_ & ~new_n30_;
  assign new_n32_ = ~v2 & ~v5;
  assign new_n33_ = ~v2 & ~new_n32_;
  assign new_n34_ = ~v3 & ~new_n33_;
  assign new_n35_ = v0 & new_n34_;
  assign new_n36_ = v3 & ~v5;
  assign new_n37_ = new_n16_ & new_n36_;
  assign new_n38_ = ~new_n35_ & ~new_n37_;
  assign new_n39_ = ~new_n31_ & ~new_n38_;
  assign new_n40_ = ~v1 & new_n27_;
  assign new_n41_ = v1 & new_n29_;
  assign new_n42_ = ~new_n40_ & ~new_n41_;
  assign new_n43_ = ~v1 & new_n11_;
  assign new_n44_ = v1 & new_n13_;
  assign new_n45_ = ~new_n43_ & ~new_n44_;
  assign new_n46_ = ~v3 & ~new_n45_;
  assign new_n47_ = new_n42_ & ~new_n46_;
  assign new_n48_ = v0 & ~new_n47_;
  assign new_n49_ = ~new_n39_ & ~new_n48_;
  assign \v7.0  = new_n26_ | ~new_n49_;
  assign new_n51_ = ~v0 & ~v2;
  assign new_n52_ = new_n36_ & new_n51_;
  assign new_n53_ = ~new_n24_ & ~new_n52_;
  assign new_n54_ = v2 & v3;
  assign new_n55_ = ~v0 & new_n54_;
  assign new_n56_ = v0 & new_n18_;
  assign new_n57_ = ~new_n55_ & ~new_n56_;
  assign new_n58_ = v3 & v5;
  assign new_n59_ = new_n51_ & new_n58_;
  assign new_n60_ = ~v3 & ~v5;
  assign new_n61_ = new_n22_ & new_n60_;
  assign new_n62_ = ~new_n59_ & ~new_n61_;
  assign new_n63_ = new_n57_ & new_n62_;
  assign new_n64_ = v1 & ~new_n63_;
  assign new_n65_ = new_n53_ & ~new_n64_;
  assign new_n66_ = ~v6 & ~new_n65_;
  assign new_n67_ = ~v0 & new_n58_;
  assign new_n68_ = v0 & new_n60_;
  assign new_n69_ = ~new_n67_ & ~new_n68_;
  assign new_n70_ = v6 & ~new_n69_;
  assign new_n71_ = v1 & new_n70_;
  assign new_n72_ = ~new_n66_ & ~new_n71_;
  assign new_n73_ = v0 & new_n58_;
  assign new_n74_ = ~v0 & new_n60_;
  assign new_n75_ = ~new_n73_ & ~new_n74_;
  assign new_n76_ = ~v2 & ~v6;
  assign new_n77_ = ~v2 & ~new_n76_;
  assign new_n78_ = ~v4 & ~new_n77_;
  assign new_n79_ = v1 & new_n78_;
  assign new_n80_ = ~v1 & v2;
  assign new_n81_ = new_n13_ & new_n80_;
  assign new_n82_ = ~new_n79_ & ~new_n81_;
  assign new_n83_ = ~new_n75_ & ~new_n82_;
  assign new_n84_ = v0 & ~v2;
  assign new_n85_ = new_n23_ & new_n84_;
  assign new_n86_ = ~new_n37_ & ~new_n85_;
  assign new_n87_ = v1 & v6;
  assign new_n88_ = ~v1 & ~v6;
  assign new_n89_ = ~new_n87_ & ~new_n88_;
  assign new_n90_ = ~new_n86_ & ~new_n89_;
  assign new_n91_ = ~v0 & new_n23_;
  assign new_n92_ = v0 & new_n36_;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = v1 & ~new_n93_;
  assign new_n95_ = ~new_n90_ & ~new_n94_;
  assign new_n96_ = ~v4 & ~new_n95_;
  assign new_n97_ = ~new_n83_ & ~new_n96_;
  assign \v7.1  = ~new_n72_ | ~new_n97_;
  assign new_n99_ = ~new_n58_ & ~new_n60_;
  assign new_n100_ = ~new_n91_ & new_n99_;
  assign new_n101_ = v2 & ~new_n100_;
  assign new_n102_ = new_n23_ & new_n51_;
  assign new_n103_ = ~new_n101_ & ~new_n102_;
  assign new_n104_ = ~new_n42_ & ~new_n103_;
  assign new_n105_ = ~v2 & v5;
  assign new_n106_ = v2 & ~v5;
  assign new_n107_ = ~new_n105_ & ~new_n106_;
  assign new_n108_ = ~v3 & ~new_n107_;
  assign new_n109_ = v0 & new_n108_;
  assign new_n110_ = new_n16_ & new_n58_;
  assign new_n111_ = ~new_n109_ & ~new_n110_;
  assign new_n112_ = ~new_n31_ & ~new_n111_;
  assign new_n113_ = ~v1 & v6;
  assign new_n114_ = v1 & ~v6;
  assign new_n115_ = ~new_n113_ & ~new_n114_;
  assign new_n116_ = v0 & new_n23_;
  assign new_n117_ = ~v0 & new_n36_;
  assign new_n118_ = ~new_n116_ & ~new_n117_;
  assign new_n119_ = ~new_n115_ & ~new_n118_;
  assign new_n120_ = ~new_n53_ & ~new_n89_;
  assign new_n121_ = ~v0 & v1;
  assign new_n122_ = ~v0 & ~new_n121_;
  assign new_n123_ = ~v5 & ~new_n122_;
  assign new_n124_ = v1 & v5;
  assign new_n125_ = ~v0 & new_n124_;
  assign new_n126_ = ~new_n123_ & ~new_n125_;
  assign new_n127_ = v0 & v1;
  assign new_n128_ = new_n105_ & new_n127_;
  assign new_n129_ = new_n126_ & ~new_n128_;
  assign new_n130_ = v6 & ~new_n129_;
  assign new_n131_ = ~v3 & new_n130_;
  assign new_n132_ = ~new_n120_ & ~new_n131_;
  assign new_n133_ = ~new_n119_ & new_n132_;
  assign new_n134_ = ~v4 & ~new_n133_;
  assign new_n135_ = ~v0 & ~v1;
  assign new_n136_ = ~v0 & ~new_n135_;
  assign new_n137_ = ~v5 & ~new_n136_;
  assign new_n138_ = ~v1 & v5;
  assign new_n139_ = ~v0 & new_n138_;
  assign new_n140_ = ~new_n137_ & ~new_n139_;
  assign new_n141_ = v0 & ~v1;
  assign new_n142_ = new_n105_ & new_n141_;
  assign new_n143_ = new_n140_ & ~new_n142_;
  assign new_n144_ = ~v6 & ~new_n143_;
  assign new_n145_ = v4 & new_n144_;
  assign new_n146_ = ~v3 & new_n145_;
  assign new_n147_ = ~new_n134_ & ~new_n146_;
  assign new_n148_ = ~new_n112_ & new_n147_;
  assign \v7.2  = new_n104_ | ~new_n148_;
endmodule


