// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:41 2022

module dekoder  ( 
    v0, v1, v2, v3,
    \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6   );
  input  v0, v1, v2, v3;
  output \v4.0 , \v4.1 , \v4.2 , \v4.3 , \v4.4 , \v4.5 , \v4.6 ;
  wire new_n12_, new_n13_, new_n14_, new_n15_, new_n16_, new_n17_, new_n18_,
    new_n19_, new_n20_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_,
    new_n27_, new_n28_, new_n29_, new_n31_, new_n32_, new_n33_, new_n34_,
    new_n35_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n45_, new_n47_, new_n48_, new_n49_, new_n50_,
    new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n60_, new_n61_, new_n62_, new_n63_, new_n64_;
  assign new_n12_ = ~v0 & v2;
  assign new_n13_ = ~v1 & ~v2;
  assign new_n14_ = v0 & new_n13_;
  assign new_n15_ = ~new_n12_ & ~new_n14_;
  assign new_n16_ = v1 & v3;
  assign new_n17_ = ~v1 & ~v3;
  assign new_n18_ = ~new_n16_ & ~new_n17_;
  assign new_n19_ = ~v2 & ~new_n18_;
  assign new_n20_ = ~v0 & new_n19_;
  assign \v4.0  = ~new_n15_ | new_n20_;
  assign new_n22_ = v0 & ~v2;
  assign new_n23_ = v0 & ~new_n22_;
  assign new_n24_ = ~v1 & ~new_n23_;
  assign new_n25_ = v2 & v3;
  assign new_n26_ = ~v2 & ~v3;
  assign new_n27_ = ~new_n25_ & ~new_n26_;
  assign new_n28_ = v1 & ~new_n27_;
  assign new_n29_ = ~v0 & new_n28_;
  assign \v4.1  = new_n24_ | new_n29_;
  assign new_n31_ = ~v1 & ~new_n13_;
  assign new_n32_ = ~v0 & ~new_n31_;
  assign new_n33_ = ~new_n14_ & ~new_n32_;
  assign new_n34_ = ~v0 & ~v1;
  assign new_n35_ = new_n25_ & new_n34_;
  assign \v4.2  = ~new_n33_ | new_n35_;
  assign new_n37_ = ~new_n12_ & ~new_n22_;
  assign new_n38_ = ~v0 & new_n26_;
  assign new_n39_ = new_n37_ & ~new_n38_;
  assign new_n40_ = ~v1 & ~new_n39_;
  assign new_n41_ = ~v2 & v3;
  assign new_n42_ = v2 & ~v3;
  assign new_n43_ = ~new_n41_ & ~new_n42_;
  assign new_n44_ = v1 & ~new_n43_;
  assign new_n45_ = ~v0 & new_n44_;
  assign \v4.3  = new_n40_ | new_n45_;
  assign new_n47_ = v1 & v2;
  assign new_n48_ = v1 & ~new_n47_;
  assign new_n49_ = ~v0 & ~new_n48_;
  assign new_n50_ = ~new_n14_ & ~new_n49_;
  assign \v4.4  = ~v3 & ~new_n50_;
  assign new_n52_ = ~v0 & v1;
  assign new_n53_ = v0 & ~v1;
  assign new_n54_ = ~new_n52_ & ~new_n53_;
  assign new_n55_ = ~v0 & new_n17_;
  assign new_n56_ = new_n54_ & ~new_n55_;
  assign new_n57_ = ~v2 & ~new_n56_;
  assign new_n58_ = new_n42_ & new_n52_;
  assign \v4.5  = new_n57_ | new_n58_;
  assign new_n60_ = ~v1 & v2;
  assign new_n61_ = v1 & ~v2;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = ~v0 & ~new_n62_;
  assign new_n64_ = ~new_n14_ & ~new_n63_;
  assign \v4.6  = new_n58_ | ~new_n64_;
endmodule


