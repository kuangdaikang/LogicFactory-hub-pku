// Benchmark "top" written by ABC on Fri Sep 15 19:21:45 2023

module top ( 
    n_1, n_2, n_3, n_4,
    n_7  );
  input  n_1, n_2, n_3, n_4;
  output n_7;
  wire new_n6_, new_n7_;
  assign new_n6_ = ~n_1 & ~n_3;
  assign new_n7_ = ~n_2 & n_3;
  assign n_7 = new_n6_ & new_n7_;
endmodule


