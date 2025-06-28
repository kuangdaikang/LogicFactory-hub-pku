// Benchmark "top" written by ABC on Fri Sep 15 19:21:48 2023

module top ( 
    n_1, n_2, n_3, n_4,
    n_8  );
  input  n_1, n_2, n_3, n_4;
  output n_8;
  wire new_n6_, new_n7_, new_n8_, new_n9_, new_n10_;
  assign new_n6_ = n_2 & n_4;
  assign new_n7_ = ~n_3 & new_n6_;
  assign new_n8_ = ~n_2 & new_n7_;
  assign new_n9_ = n_2 & ~new_n7_;
  assign new_n10_ = ~new_n8_ & ~new_n9_;
  assign n_8 = n_1 & ~new_n10_;
endmodule


