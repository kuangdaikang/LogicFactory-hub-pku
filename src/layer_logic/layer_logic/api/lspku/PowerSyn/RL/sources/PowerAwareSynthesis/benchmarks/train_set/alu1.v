// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:55 2022

module alu1  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,
    \v12.0 , \v12.1 , \v12.2 , \v12.3 , \v12.4 , \v12.5 , \v12.6 , \v12.7   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
  output \v12.0 , \v12.1 , \v12.2 , \v12.3 , \v12.4 , \v12.5 , \v12.6 ,
    \v12.7 ;
  wire new_n21_, new_n22_, new_n23_, new_n25_, new_n26_, new_n27_, new_n29_,
    new_n30_, new_n31_, new_n33_, new_n34_, new_n35_, new_n37_, new_n38_,
    new_n39_, new_n41_, new_n42_, new_n43_, new_n45_, new_n46_, new_n47_,
    new_n49_;
  assign new_n21_ = v4 & ~v11;
  assign new_n22_ = ~v4 & ~v10;
  assign new_n23_ = ~new_n21_ & ~new_n22_;
  assign \v12.0  = ~v0 | ~new_n23_;
  assign new_n25_ = v5 & ~v11;
  assign new_n26_ = ~v5 & ~v10;
  assign new_n27_ = ~new_n25_ & ~new_n26_;
  assign \v12.1  = ~v1 | ~new_n27_;
  assign new_n29_ = v6 & ~v11;
  assign new_n30_ = ~v6 & ~v10;
  assign new_n31_ = ~new_n29_ & ~new_n30_;
  assign \v12.2  = ~v2 | ~new_n31_;
  assign new_n33_ = v7 & ~v11;
  assign new_n34_ = ~v7 & ~v10;
  assign new_n35_ = ~new_n33_ & ~new_n34_;
  assign \v12.3  = ~v3 | ~new_n35_;
  assign new_n37_ = v4 & ~v8;
  assign new_n38_ = ~v4 & ~v9;
  assign new_n39_ = ~new_n37_ & ~new_n38_;
  assign \v12.4  = ~v0 & ~new_n39_;
  assign new_n41_ = v5 & ~v8;
  assign new_n42_ = ~v5 & ~v9;
  assign new_n43_ = ~new_n41_ & ~new_n42_;
  assign \v12.5  = ~v1 & ~new_n43_;
  assign new_n45_ = v6 & ~v8;
  assign new_n46_ = ~v6 & ~v9;
  assign new_n47_ = ~new_n45_ & ~new_n46_;
  assign \v12.6  = ~v2 & ~new_n47_;
  assign new_n49_ = ~v3 & v7;
  assign \v12.7  = ~v8 & new_n49_;
endmodule


