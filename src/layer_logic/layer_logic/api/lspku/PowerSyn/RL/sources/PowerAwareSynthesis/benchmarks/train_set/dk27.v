// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:45 2022

module dk27  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8,
    \v9.0 , \v9.1 , \v9.2 , \v9.3 , \v9.4 , \v9.5 , \v9.6 , \v9.7 , \v9.8   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8;
  output \v9.0 , \v9.1 , \v9.2 , \v9.3 , \v9.4 , \v9.5 , \v9.6 , \v9.7 ,
    \v9.8 ;
  wire new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_, new_n25_,
    new_n26_, new_n27_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_,
    new_n34_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n87_,
    new_n88_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_,
    new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n103_, new_n104_, new_n105_, new_n106_, new_n107_;
  assign new_n19_ = ~v2 & v4;
  assign new_n20_ = v2 & ~v4;
  assign new_n21_ = ~new_n19_ & ~new_n20_;
  assign new_n22_ = ~v8 & ~new_n21_;
  assign new_n23_ = v7 & new_n22_;
  assign new_n24_ = ~v6 & new_n23_;
  assign new_n25_ = ~v5 & new_n24_;
  assign new_n26_ = ~v3 & new_n25_;
  assign new_n27_ = ~v1 & new_n26_;
  assign \v9.0  = ~v0 & new_n27_;
  assign new_n29_ = v8 & ~new_n21_;
  assign new_n30_ = ~v7 & new_n29_;
  assign new_n31_ = ~v6 & new_n30_;
  assign new_n32_ = ~v5 & new_n31_;
  assign new_n33_ = ~v3 & new_n32_;
  assign new_n34_ = ~v1 & new_n33_;
  assign \v9.1  = ~v0 & new_n34_;
  assign new_n36_ = ~v7 & v8;
  assign new_n37_ = v7 & ~v8;
  assign new_n38_ = ~new_n36_ & ~new_n37_;
  assign new_n39_ = ~v6 & ~new_n38_;
  assign new_n40_ = v3 & new_n39_;
  assign new_n41_ = ~v3 & v6;
  assign new_n42_ = new_n36_ & new_n41_;
  assign new_n43_ = ~new_n40_ & ~new_n42_;
  assign new_n44_ = ~v0 & ~new_n43_;
  assign new_n45_ = v0 & ~v3;
  assign new_n46_ = ~v6 & new_n37_;
  assign new_n47_ = new_n45_ & new_n46_;
  assign new_n48_ = ~new_n44_ & ~new_n47_;
  assign new_n49_ = ~v5 & ~new_n48_;
  assign new_n50_ = ~v4 & new_n49_;
  assign new_n51_ = ~v2 & new_n50_;
  assign \v9.2  = ~v1 & new_n51_;
  assign new_n53_ = v0 & ~v1;
  assign new_n54_ = ~v2 & new_n53_;
  assign new_n55_ = ~v3 & new_n54_;
  assign new_n56_ = ~v4 & new_n55_;
  assign new_n57_ = ~v5 & new_n56_;
  assign new_n58_ = ~v6 & new_n57_;
  assign new_n59_ = ~v7 & new_n58_;
  assign \v9.3  = v8 & new_n59_;
  assign new_n61_ = ~v5 & v6;
  assign new_n62_ = v5 & ~v6;
  assign new_n63_ = ~new_n61_ & ~new_n62_;
  assign new_n64_ = ~v1 & ~new_n63_;
  assign new_n65_ = ~v5 & ~v6;
  assign new_n66_ = v1 & new_n65_;
  assign new_n67_ = ~new_n64_ & ~new_n66_;
  assign new_n68_ = ~v8 & ~new_n67_;
  assign new_n69_ = v7 & new_n68_;
  assign new_n70_ = ~v4 & new_n69_;
  assign new_n71_ = ~v3 & new_n70_;
  assign new_n72_ = ~v2 & new_n71_;
  assign \v9.4  = ~v0 & new_n72_;
  assign new_n74_ = ~v0 & v1;
  assign new_n75_ = ~v2 & new_n74_;
  assign new_n76_ = ~v3 & new_n75_;
  assign new_n77_ = ~v4 & new_n76_;
  assign new_n78_ = ~v5 & new_n77_;
  assign new_n79_ = ~v6 & new_n78_;
  assign new_n80_ = ~v7 & new_n79_;
  assign \v9.5  = v8 & new_n80_;
  assign new_n82_ = ~v0 & ~v1;
  assign new_n83_ = ~v2 & new_n82_;
  assign new_n84_ = ~v3 & new_n83_;
  assign new_n85_ = ~v4 & new_n84_;
  assign new_n86_ = v5 & new_n85_;
  assign new_n87_ = ~v6 & new_n86_;
  assign new_n88_ = ~v7 & new_n87_;
  assign \v9.6  = v8 & new_n88_;
  assign new_n90_ = v4 & new_n39_;
  assign new_n91_ = ~v4 & v6;
  assign new_n92_ = new_n36_ & new_n91_;
  assign new_n93_ = ~new_n90_ & ~new_n92_;
  assign new_n94_ = ~v3 & ~new_n93_;
  assign new_n95_ = v3 & ~v4;
  assign new_n96_ = ~v6 & new_n36_;
  assign new_n97_ = new_n95_ & new_n96_;
  assign new_n98_ = ~new_n94_ & ~new_n97_;
  assign new_n99_ = ~v5 & ~new_n98_;
  assign new_n100_ = ~v2 & new_n99_;
  assign new_n101_ = ~v1 & new_n100_;
  assign \v9.7  = ~v0 & new_n101_;
  assign new_n103_ = ~v5 & new_n39_;
  assign new_n104_ = ~v4 & new_n103_;
  assign new_n105_ = ~v3 & new_n104_;
  assign new_n106_ = v2 & new_n105_;
  assign new_n107_ = ~v1 & new_n106_;
  assign \v9.8  = ~v0 & new_n107_;
endmodule


