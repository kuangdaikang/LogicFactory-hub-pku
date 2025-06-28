// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:39 2022

module alu3  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9,
    \v10.0 , \v10.1 , \v10.2 , \v10.3 , \v10.4 , \v10.5 , \v10.6 , \v10.7   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9;
  output \v10.0 , \v10.1 , \v10.2 , \v10.3 , \v10.4 , \v10.5 , \v10.6 ,
    \v10.7 ;
  wire new_n19_, new_n20_, new_n21_, new_n22_, new_n24_, new_n25_, new_n26_,
    new_n27_, new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_,
    new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n73_, new_n74_, new_n76_, new_n77_, new_n78_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n95_;
  assign new_n19_ = v2 & ~v6;
  assign new_n20_ = v0 & ~v1;
  assign new_n21_ = ~new_n19_ & ~new_n20_;
  assign new_n22_ = new_n19_ & new_n20_;
  assign \v10.0  = new_n21_ | new_n22_;
  assign new_n24_ = v3 & ~v7;
  assign new_n25_ = ~v0 & ~v6;
  assign new_n26_ = v2 & ~new_n25_;
  assign new_n27_ = ~v1 & new_n26_;
  assign new_n28_ = ~new_n24_ & ~new_n27_;
  assign new_n29_ = v0 & v2;
  assign new_n30_ = ~v6 & ~new_n29_;
  assign new_n31_ = ~v7 & ~new_n30_;
  assign new_n32_ = v3 & new_n31_;
  assign new_n33_ = ~v1 & new_n32_;
  assign \v10.1  = new_n28_ | new_n33_;
  assign new_n35_ = v4 & ~v8;
  assign new_n36_ = v3 & ~new_n30_;
  assign new_n37_ = ~v7 & ~new_n36_;
  assign new_n38_ = ~new_n35_ & ~new_n37_;
  assign new_n39_ = ~v1 & new_n38_;
  assign new_n40_ = ~v7 & ~new_n26_;
  assign new_n41_ = ~v1 & v3;
  assign new_n42_ = ~new_n40_ & new_n41_;
  assign new_n43_ = ~v8 & ~new_n42_;
  assign new_n44_ = v4 & new_n43_;
  assign \v10.2  = new_n39_ | new_n44_;
  assign new_n46_ = ~v3 & v8;
  assign new_n47_ = v7 & ~v8;
  assign new_n48_ = v4 & new_n47_;
  assign new_n49_ = ~new_n46_ & ~new_n48_;
  assign new_n50_ = ~v2 & ~new_n49_;
  assign new_n51_ = v3 & v4;
  assign new_n52_ = ~v7 & ~v8;
  assign new_n53_ = v6 & new_n52_;
  assign new_n54_ = new_n51_ & new_n53_;
  assign new_n55_ = ~new_n50_ & ~new_n54_;
  assign new_n56_ = ~v0 & ~new_n55_;
  assign new_n57_ = v2 & v3;
  assign new_n58_ = v0 & new_n57_;
  assign new_n59_ = v4 & ~v6;
  assign new_n60_ = new_n52_ & new_n59_;
  assign new_n61_ = new_n58_ & new_n60_;
  assign new_n62_ = ~new_n56_ & ~new_n61_;
  assign new_n63_ = ~v9 & ~new_n62_;
  assign new_n64_ = v5 & new_n63_;
  assign new_n65_ = ~v1 & new_n64_;
  assign new_n66_ = v5 & ~v9;
  assign new_n67_ = ~new_n19_ & ~new_n24_;
  assign new_n68_ = ~new_n35_ & new_n67_;
  assign new_n69_ = v1 & new_n68_;
  assign new_n70_ = ~v0 & ~v2;
  assign new_n71_ = ~v3 & ~v4;
  assign new_n72_ = new_n70_ & new_n71_;
  assign new_n73_ = ~new_n69_ & ~new_n72_;
  assign new_n74_ = ~new_n66_ & ~new_n73_;
  assign \v10.3  = new_n65_ | new_n74_;
  assign new_n76_ = v4 & ~new_n37_;
  assign new_n77_ = ~v8 & ~new_n76_;
  assign new_n78_ = v5 & ~new_n77_;
  assign \v10.4  = v9 | new_n78_;
  assign new_n80_ = ~new_n66_ & ~new_n77_;
  assign new_n81_ = ~v1 & new_n80_;
  assign new_n82_ = v3 & ~new_n40_;
  assign new_n83_ = ~v8 & ~new_n82_;
  assign new_n84_ = ~v1 & v4;
  assign new_n85_ = ~new_n83_ & new_n84_;
  assign new_n86_ = ~v9 & ~new_n85_;
  assign new_n87_ = v5 & new_n86_;
  assign \v10.5  = new_n81_ | new_n87_;
  assign new_n89_ = ~v6 & ~v7;
  assign new_n90_ = v3 & ~new_n89_;
  assign new_n91_ = ~v8 & ~new_n90_;
  assign new_n92_ = v4 & ~new_n91_;
  assign new_n93_ = ~v9 & ~new_n92_;
  assign \v10.6  = ~v5 | new_n93_;
  assign new_n95_ = v4 & new_n57_;
  assign \v10.7  = v5 & new_n95_;
endmodule


