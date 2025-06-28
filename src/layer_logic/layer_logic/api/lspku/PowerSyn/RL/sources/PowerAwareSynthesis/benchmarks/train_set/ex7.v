// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:34 2022

module ex7  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    \v16.0 , \v16.1 , \v16.2 , \v16.3 , \v16.4   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15;
  output \v16.0 , \v16.1 , \v16.2 , \v16.3 , \v16.4 ;
  wire new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_, new_n28_,
    new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n127_, new_n128_, new_n129_, new_n131_, new_n132_,
    new_n133_, new_n134_, new_n135_, new_n136_;
  assign new_n22_ = v4 & ~v5;
  assign new_n23_ = v0 & new_n22_;
  assign new_n24_ = v5 & v12;
  assign new_n25_ = ~v4 & new_n24_;
  assign new_n26_ = ~new_n23_ & ~new_n25_;
  assign new_n27_ = ~v6 & ~new_n26_;
  assign new_n28_ = v5 & ~new_n24_;
  assign new_n29_ = ~v4 & ~new_n28_;
  assign new_n30_ = ~v5 & ~v12;
  assign new_n31_ = v4 & new_n30_;
  assign new_n32_ = ~new_n29_ & ~new_n31_;
  assign new_n33_ = v6 & ~new_n32_;
  assign new_n34_ = v7 & v12;
  assign new_n35_ = ~v7 & ~v12;
  assign new_n36_ = ~new_n34_ & ~new_n35_;
  assign new_n37_ = v5 & ~new_n36_;
  assign new_n38_ = v4 & new_n37_;
  assign new_n39_ = ~new_n33_ & ~new_n38_;
  assign new_n40_ = v8 & ~new_n39_;
  assign new_n41_ = ~v7 & v12;
  assign new_n42_ = v7 & ~v12;
  assign new_n43_ = ~new_n41_ & ~new_n42_;
  assign new_n44_ = v5 & ~new_n43_;
  assign new_n45_ = v6 & v12;
  assign new_n46_ = ~v5 & new_n45_;
  assign new_n47_ = ~new_n44_ & ~new_n46_;
  assign new_n48_ = ~v8 & ~new_n47_;
  assign new_n49_ = v4 & new_n48_;
  assign new_n50_ = ~new_n40_ & ~new_n49_;
  assign \v16.0  = new_n27_ | ~new_n50_;
  assign new_n52_ = v9 & v13;
  assign new_n53_ = ~v9 & ~v13;
  assign new_n54_ = ~new_n52_ & ~new_n53_;
  assign new_n55_ = v0 & v7;
  assign new_n56_ = v8 & v12;
  assign new_n57_ = ~new_n55_ & ~new_n56_;
  assign new_n58_ = ~new_n54_ & ~new_n57_;
  assign new_n59_ = ~v9 & v13;
  assign new_n60_ = v9 & ~v13;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = new_n57_ & ~new_n61_;
  assign new_n63_ = ~new_n58_ & ~new_n62_;
  assign new_n64_ = v5 & ~new_n63_;
  assign new_n65_ = v6 & ~new_n61_;
  assign new_n66_ = v1 & ~v6;
  assign new_n67_ = ~new_n65_ & ~new_n66_;
  assign new_n68_ = ~v5 & ~new_n67_;
  assign new_n69_ = ~new_n64_ & ~new_n68_;
  assign new_n70_ = v4 & ~new_n69_;
  assign new_n71_ = v6 & v9;
  assign new_n72_ = v6 & ~new_n71_;
  assign new_n73_ = v13 & ~new_n72_;
  assign new_n74_ = v5 & new_n73_;
  assign new_n75_ = ~v5 & new_n71_;
  assign new_n76_ = ~new_n74_ & ~new_n75_;
  assign new_n77_ = ~v4 & ~new_n76_;
  assign \v16.1  = new_n70_ | new_n77_;
  assign new_n79_ = v10 & v14;
  assign new_n80_ = ~v10 & ~v14;
  assign new_n81_ = ~new_n79_ & ~new_n80_;
  assign new_n82_ = v1 & ~new_n57_;
  assign new_n83_ = ~new_n52_ & ~new_n82_;
  assign new_n84_ = ~new_n81_ & ~new_n83_;
  assign new_n85_ = ~v10 & v14;
  assign new_n86_ = v10 & ~v14;
  assign new_n87_ = ~new_n85_ & ~new_n86_;
  assign new_n88_ = new_n83_ & ~new_n87_;
  assign new_n89_ = ~new_n84_ & ~new_n88_;
  assign new_n90_ = v5 & ~new_n89_;
  assign new_n91_ = v6 & ~new_n87_;
  assign new_n92_ = v2 & ~v6;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = ~v5 & ~new_n93_;
  assign new_n95_ = ~new_n90_ & ~new_n94_;
  assign new_n96_ = v4 & ~new_n95_;
  assign new_n97_ = v6 & v10;
  assign new_n98_ = v6 & ~new_n97_;
  assign new_n99_ = v14 & ~new_n98_;
  assign new_n100_ = v5 & new_n99_;
  assign new_n101_ = ~v5 & new_n97_;
  assign new_n102_ = ~new_n100_ & ~new_n101_;
  assign new_n103_ = ~v4 & ~new_n102_;
  assign \v16.2  = new_n96_ | new_n103_;
  assign new_n105_ = v11 & v15;
  assign new_n106_ = ~v11 & ~v15;
  assign new_n107_ = ~new_n105_ & ~new_n106_;
  assign new_n108_ = v2 & ~new_n83_;
  assign new_n109_ = ~new_n79_ & ~new_n108_;
  assign new_n110_ = ~new_n107_ & ~new_n109_;
  assign new_n111_ = ~v11 & v15;
  assign new_n112_ = v11 & ~v15;
  assign new_n113_ = ~new_n111_ & ~new_n112_;
  assign new_n114_ = new_n109_ & ~new_n113_;
  assign new_n115_ = ~new_n110_ & ~new_n114_;
  assign new_n116_ = v5 & ~new_n115_;
  assign new_n117_ = v6 & ~new_n113_;
  assign new_n118_ = v3 & ~v6;
  assign new_n119_ = ~new_n117_ & ~new_n118_;
  assign new_n120_ = ~v5 & ~new_n119_;
  assign new_n121_ = ~new_n116_ & ~new_n120_;
  assign new_n122_ = v4 & ~new_n121_;
  assign new_n123_ = v6 & v11;
  assign new_n124_ = v6 & ~new_n123_;
  assign new_n125_ = v15 & ~new_n124_;
  assign new_n126_ = v5 & new_n125_;
  assign new_n127_ = ~v5 & new_n123_;
  assign new_n128_ = ~new_n126_ & ~new_n127_;
  assign new_n129_ = ~v4 & ~new_n128_;
  assign \v16.3  = new_n122_ | new_n129_;
  assign new_n131_ = v1 & new_n56_;
  assign new_n132_ = ~new_n52_ & ~new_n131_;
  assign new_n133_ = ~new_n55_ & new_n132_;
  assign new_n134_ = v2 & ~new_n133_;
  assign new_n135_ = ~new_n79_ & ~new_n134_;
  assign new_n136_ = v3 & ~new_n135_;
  assign \v16.4  = new_n105_ | new_n136_;
endmodule


