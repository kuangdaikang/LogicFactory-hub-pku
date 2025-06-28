// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:28 2022

module ryy6  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    \v16.0   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15;
  output \v16.0 ;
  wire new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_,
    new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n31_,
    new_n32_;
  assign new_n18_ = v5 & v6;
  assign new_n19_ = v3 & v4;
  assign new_n20_ = v12 & v13;
  assign new_n21_ = v14 & v15;
  assign new_n22_ = new_n20_ & new_n21_;
  assign new_n23_ = v0 & v1;
  assign new_n24_ = ~v2 & ~new_n23_;
  assign new_n25_ = v10 & v11;
  assign new_n26_ = v7 & v8;
  assign new_n27_ = ~new_n25_ & ~new_n26_;
  assign new_n28_ = v9 & ~new_n27_;
  assign new_n29_ = ~v1 & ~new_n28_;
  assign new_n30_ = ~new_n24_ & ~new_n29_;
  assign new_n31_ = ~new_n22_ & ~new_n30_;
  assign new_n32_ = ~new_n19_ & new_n31_;
  assign \v16.0  = ~new_n18_ & new_n32_;
endmodule


