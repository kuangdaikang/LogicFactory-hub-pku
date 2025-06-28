// Benchmark "top" written by ABC on Fri Sep 15 19:21:45 2023

module top ( 
    n_1, n_2, n_3, n_4,
    n_9  );
  input  n_1, n_2, n_3, n_4;
  output n_9;
  wire new_n6_, new_n7_, new_n8_, new_n9_, new_n10_, new_n11_, new_n12_,
    new_n13_, new_n14_, new_n15_;
  assign new_n6_ = ~n_2 & n_3;
  assign new_n7_ = n_2 & ~n_3;
  assign new_n8_ = ~new_n6_ & ~new_n7_;
  assign new_n9_ = ~n_1 & n_2;
  assign new_n10_ = n_1 & ~n_2;
  assign new_n11_ = ~new_n9_ & ~new_n10_;
  assign new_n12_ = ~n_3 & new_n11_;
  assign new_n13_ = ~n_4 & ~new_n12_;
  assign new_n14_ = new_n8_ & new_n13_;
  assign new_n15_ = ~new_n8_ & ~new_n13_;
  assign n_9 = new_n14_ | new_n15_;
endmodule


