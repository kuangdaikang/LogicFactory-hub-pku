// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:09 2022

module clpl  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,
    \v11.0 , \v11.1 , \v11.2 , \v11.3 , \v11.4   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
  output \v11.0 , \v11.1 , \v11.2 , \v11.3 , \v11.4 ;
  wire new_n17_, new_n19_, new_n21_, new_n23_, new_n25_;
  assign new_n17_ = v0 & v4;
  assign \v11.2  = v2 | new_n17_;
  assign new_n19_ = v5 & \v11.2 ;
  assign \v11.1  = v3 | new_n19_;
  assign new_n21_ = v6 & \v11.1 ;
  assign \v11.0  = v1 | new_n21_;
  assign new_n23_ = v8 & \v11.0 ;
  assign \v11.4  = v7 | new_n23_;
  assign new_n25_ = v9 & \v11.4 ;
  assign \v11.3  = v10 | new_n25_;
endmodule


