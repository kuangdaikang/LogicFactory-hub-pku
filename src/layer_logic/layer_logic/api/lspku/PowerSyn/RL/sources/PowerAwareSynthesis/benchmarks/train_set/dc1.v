// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:45 2022

module dc1  ( 
    v0, v1, v2, v3,
    \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6   );
  input  v0, v1, v2, v3;
  output \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6 ;
  wire new_n12_, new_n13_, new_n14_, new_n15_, new_n16_, new_n17_, new_n18_,
    new_n20_, new_n21_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n39_, new_n40_, new_n41_, new_n42_, new_n43_,
    new_n44_, new_n46_, new_n47_, new_n48_, new_n49_, new_n51_, new_n52_;
  assign new_n12_ = v2 & v3;
  assign new_n13_ = v1 & ~new_n12_;
  assign new_n14_ = ~v2 & ~v3;
  assign new_n15_ = ~new_n13_ & ~new_n14_;
  assign new_n16_ = ~v0 & ~new_n15_;
  assign new_n17_ = ~v1 & ~v2;
  assign new_n18_ = v0 & new_n17_;
  assign \v4.0  = new_n16_ | new_n18_;
  assign new_n20_ = ~v0 & v2;
  assign new_n21_ = ~new_n17_ & ~new_n20_;
  assign \v4.1  = ~v3 & ~new_n21_;
  assign new_n23_ = ~v1 & v2;
  assign new_n24_ = v1 & v3;
  assign new_n25_ = ~new_n23_ & ~new_n24_;
  assign new_n26_ = ~v0 & ~new_n25_;
  assign new_n27_ = ~v0 & v3;
  assign new_n28_ = ~v2 & ~new_n27_;
  assign new_n29_ = ~v1 & new_n28_;
  assign \v4.2  = new_n26_ | new_n29_;
  assign new_n31_ = v0 & ~v2;
  assign new_n32_ = ~new_n20_ & ~new_n31_;
  assign new_n33_ = ~v1 & ~new_n32_;
  assign new_n34_ = v1 & ~v2;
  assign new_n35_ = v2 & ~v3;
  assign new_n36_ = ~new_n34_ & ~new_n35_;
  assign new_n37_ = ~v0 & ~new_n36_;
  assign \v4.3  = new_n33_ | new_n37_;
  assign new_n39_ = ~new_n14_ & ~new_n20_;
  assign new_n40_ = ~v1 & ~new_n39_;
  assign new_n41_ = ~v2 & v3;
  assign new_n42_ = v1 & new_n41_;
  assign new_n43_ = ~new_n35_ & ~new_n42_;
  assign new_n44_ = ~v0 & ~new_n43_;
  assign \v4.4  = new_n40_ | new_n44_;
  assign new_n46_ = ~new_n12_ & ~new_n14_;
  assign new_n47_ = v1 & ~new_n46_;
  assign new_n48_ = v1 & ~new_n47_;
  assign new_n49_ = ~v0 & ~new_n48_;
  assign \v4.5  = new_n17_ | new_n49_;
  assign new_n51_ = ~v1 & ~v3;
  assign new_n52_ = ~v0 & ~new_n51_;
  assign \v4.6  = new_n17_ | new_n52_;
endmodule


