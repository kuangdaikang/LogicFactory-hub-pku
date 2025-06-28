// Benchmark "top" written by ABC on Fri Sep 15 19:21:48 2023

module top ( 
    n_1, n_2, n_3, n_4,
    n_6  );
  input  n_1, n_2, n_3, n_4;
  output n_6;
  wire new_n6_, new_n7_, new_n8_, new_n9_, new_n10_;
  assign new_n6_ = ~n_2 & n_3;
  assign new_n7_ = n_2 & ~n_3;
  assign new_n8_ = ~new_n6_ & ~new_n7_;
  assign new_n9_ = ~n_1 & ~new_n8_;
  assign new_n10_ = n_1 & new_n8_;
  assign n_6 = new_n9_ | new_n10_;
endmodule


