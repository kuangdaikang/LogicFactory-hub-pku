// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:09 2022

module wim  ( 
    v0, v1, v2, v3,
    \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6   );
  input  v0, v1, v2, v3;
  output \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6 ;
  wire new_n12_, new_n13_, new_n14_, new_n15_, new_n16_, new_n18_, new_n19_,
    new_n20_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n30_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n40_, new_n41_, new_n42_, new_n43_,
    new_n45_, new_n46_, new_n47_, new_n48_, new_n50_, new_n51_, new_n52_,
    new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_;
  assign new_n12_ = ~v1 & v2;
  assign new_n13_ = ~v1 & ~new_n12_;
  assign new_n14_ = ~v0 & ~new_n13_;
  assign new_n15_ = ~v1 & ~v2;
  assign new_n16_ = v0 & new_n15_;
  assign \v4.4  = new_n14_ | new_n16_;
  assign new_n18_ = ~v0 & ~v1;
  assign new_n19_ = ~v2 & ~v3;
  assign new_n20_ = new_n18_ & new_n19_;
  assign \v4.0  = \v4.4  | new_n20_;
  assign new_n22_ = ~v0 & v1;
  assign new_n23_ = v0 & ~v1;
  assign new_n24_ = ~new_n22_ & ~new_n23_;
  assign new_n25_ = ~v1 & ~v3;
  assign new_n26_ = ~v0 & new_n25_;
  assign new_n27_ = new_n24_ & ~new_n26_;
  assign new_n28_ = ~v2 & ~new_n27_;
  assign new_n29_ = v2 & ~v3;
  assign new_n30_ = new_n22_ & new_n29_;
  assign \v4.1  = new_n28_ | new_n30_;
  assign new_n32_ = v0 & ~v2;
  assign new_n33_ = v0 & ~new_n32_;
  assign new_n34_ = ~v1 & ~new_n33_;
  assign new_n35_ = v2 & v3;
  assign new_n36_ = ~new_n19_ & ~new_n35_;
  assign new_n37_ = v1 & ~new_n36_;
  assign new_n38_ = ~v0 & new_n37_;
  assign \v4.2  = new_n34_ | new_n38_;
  assign new_n40_ = v1 & v2;
  assign new_n41_ = v1 & ~new_n40_;
  assign new_n42_ = ~v0 & ~new_n41_;
  assign new_n43_ = ~new_n16_ & ~new_n42_;
  assign \v4.3  = ~v3 & ~new_n43_;
  assign new_n45_ = ~v1 & ~new_n15_;
  assign new_n46_ = ~v0 & ~new_n45_;
  assign new_n47_ = ~new_n16_ & ~new_n46_;
  assign new_n48_ = new_n18_ & new_n35_;
  assign \v4.5  = ~new_n47_ | new_n48_;
  assign new_n50_ = ~v0 & v2;
  assign new_n51_ = ~new_n32_ & ~new_n50_;
  assign new_n52_ = ~v0 & new_n19_;
  assign new_n53_ = new_n51_ & ~new_n52_;
  assign new_n54_ = ~v1 & ~new_n53_;
  assign new_n55_ = ~v2 & v3;
  assign new_n56_ = ~new_n29_ & ~new_n55_;
  assign new_n57_ = v1 & ~new_n56_;
  assign new_n58_ = ~v0 & new_n57_;
  assign \v4.6  = new_n54_ | new_n58_;
endmodule


