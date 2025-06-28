// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:51 2022

module t3  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,
    \v12.0 , \v12.1 , \v12.2 , \v12.3 , \v12.4 , \v12.5 , \v12.6 , \v12.7   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
  output \v12.0 , \v12.1 , \v12.2 , \v12.3 , \v12.4 , \v12.5 , \v12.6 ,
    \v12.7 ;
  wire new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_,
    new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n106_, new_n107_, new_n108_,
    new_n109_, new_n110_, new_n112_, new_n113_, new_n114_, new_n116_,
    new_n117_, new_n118_, new_n119_;
  assign new_n21_ = ~v9 & ~v11;
  assign new_n22_ = ~v5 & new_n21_;
  assign new_n23_ = ~v11 & ~new_n22_;
  assign new_n24_ = ~v6 & ~new_n23_;
  assign new_n25_ = v7 & ~new_n23_;
  assign new_n26_ = v5 & ~v7;
  assign new_n27_ = v9 & v11;
  assign new_n28_ = new_n26_ & new_n27_;
  assign new_n29_ = ~new_n25_ & ~new_n28_;
  assign new_n30_ = ~v8 & ~new_n29_;
  assign new_n31_ = v6 & new_n30_;
  assign new_n32_ = ~new_n24_ & ~new_n31_;
  assign new_n33_ = v10 & ~new_n32_;
  assign new_n34_ = v4 & new_n33_;
  assign new_n35_ = v4 & ~new_n34_;
  assign new_n36_ = ~v3 & ~new_n35_;
  assign new_n37_ = ~v1 & new_n36_;
  assign new_n38_ = ~v0 & new_n37_;
  assign new_n39_ = v0 & v4;
  assign new_n40_ = ~v7 & ~v8;
  assign new_n41_ = new_n39_ & new_n40_;
  assign new_n42_ = ~new_n38_ & ~new_n41_;
  assign \v12.0  = ~v2 & ~new_n42_;
  assign new_n44_ = ~v10 & ~new_n32_;
  assign new_n45_ = ~v3 & new_n44_;
  assign new_n46_ = ~v1 & new_n45_;
  assign new_n47_ = ~v0 & new_n46_;
  assign new_n48_ = v7 & v8;
  assign new_n49_ = v0 & new_n48_;
  assign new_n50_ = ~new_n47_ & ~new_n49_;
  assign new_n51_ = v4 & ~new_n50_;
  assign \v12.1  = ~v2 & new_n51_;
  assign new_n53_ = ~v5 & v9;
  assign new_n54_ = v5 & ~v9;
  assign new_n55_ = ~new_n53_ & ~new_n54_;
  assign new_n56_ = v6 & ~v8;
  assign new_n57_ = v6 & ~new_n56_;
  assign new_n58_ = ~v11 & ~new_n57_;
  assign new_n59_ = v6 & ~v7;
  assign new_n60_ = ~v8 & v11;
  assign new_n61_ = new_n59_ & new_n60_;
  assign new_n62_ = ~new_n58_ & ~new_n61_;
  assign new_n63_ = ~new_n55_ & ~new_n62_;
  assign new_n64_ = v9 & new_n58_;
  assign new_n65_ = v5 & new_n64_;
  assign new_n66_ = ~new_n63_ & ~new_n65_;
  assign new_n67_ = ~v3 & ~new_n66_;
  assign new_n68_ = ~v1 & new_n67_;
  assign new_n69_ = ~v0 & new_n68_;
  assign new_n70_ = v7 & ~v8;
  assign new_n71_ = v0 & new_n70_;
  assign new_n72_ = ~new_n69_ & ~new_n71_;
  assign new_n73_ = v4 & ~new_n72_;
  assign \v12.2  = ~v2 & new_n73_;
  assign new_n75_ = v6 & v8;
  assign new_n76_ = v4 & new_n75_;
  assign new_n77_ = ~v3 & new_n76_;
  assign new_n78_ = ~v2 & new_n77_;
  assign new_n79_ = ~v1 & new_n78_;
  assign new_n80_ = ~v0 & new_n79_;
  assign new_n81_ = v0 & v2;
  assign new_n82_ = ~v4 & ~v8;
  assign new_n83_ = new_n81_ & new_n82_;
  assign new_n84_ = ~new_n80_ & ~new_n83_;
  assign new_n85_ = v6 & ~v9;
  assign new_n86_ = ~v5 & new_n85_;
  assign new_n87_ = v4 & new_n86_;
  assign new_n88_ = ~v3 & new_n87_;
  assign new_n89_ = ~v1 & new_n88_;
  assign new_n90_ = ~v0 & new_n89_;
  assign new_n91_ = v0 & ~v4;
  assign new_n92_ = ~new_n90_ & ~new_n91_;
  assign new_n93_ = ~v8 & ~new_n92_;
  assign new_n94_ = ~v7 & new_n93_;
  assign new_n95_ = ~v2 & new_n94_;
  assign \v12.3  = ~new_n84_ | new_n95_;
  assign new_n97_ = ~v2 & ~v7;
  assign new_n98_ = ~v2 & ~new_n97_;
  assign new_n99_ = v8 & ~new_n98_;
  assign new_n100_ = ~v4 & new_n99_;
  assign new_n101_ = v0 & new_n100_;
  assign new_n102_ = ~v0 & ~v1;
  assign new_n103_ = ~v2 & v3;
  assign new_n104_ = new_n102_ & new_n103_;
  assign \v12.4  = new_n101_ | new_n104_;
  assign new_n106_ = ~v1 & v2;
  assign new_n107_ = ~v0 & new_n106_;
  assign new_n108_ = v0 & ~v2;
  assign new_n109_ = ~v4 & new_n70_;
  assign new_n110_ = new_n108_ & new_n109_;
  assign \v12.5  = new_n107_ | new_n110_;
  assign new_n112_ = ~v0 & v1;
  assign new_n113_ = ~v4 & new_n48_;
  assign new_n114_ = new_n108_ & new_n113_;
  assign \v12.6  = new_n112_ | new_n114_;
  assign new_n116_ = ~v7 & v8;
  assign new_n117_ = ~v2 & new_n116_;
  assign new_n118_ = ~v2 & ~new_n117_;
  assign new_n119_ = v4 & ~new_n118_;
  assign \v12.7  = v0 & new_n119_;
endmodule


