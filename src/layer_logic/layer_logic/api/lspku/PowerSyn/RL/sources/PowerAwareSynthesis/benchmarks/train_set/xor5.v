// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:27 2022

module xor5  ( 
    d, c, b, a, e,
    xor5  );
  input  d, c, b, a, e;
  output xor5;
  wire new_n7_, new_n8_, new_n9_, new_n10_, new_n11_, new_n12_, new_n13_,
    new_n14_, new_n15_, new_n16_, new_n17_, new_n18_, new_n19_, new_n20_,
    new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_;
  assign new_n7_ = a & e;
  assign new_n8_ = ~a & ~e;
  assign new_n9_ = ~new_n7_ & ~new_n8_;
  assign new_n10_ = c & b;
  assign new_n11_ = ~c & ~b;
  assign new_n12_ = ~new_n10_ & ~new_n11_;
  assign new_n13_ = d & ~new_n12_;
  assign new_n14_ = ~c & b;
  assign new_n15_ = c & ~b;
  assign new_n16_ = ~new_n14_ & ~new_n15_;
  assign new_n17_ = ~d & ~new_n16_;
  assign new_n18_ = ~new_n13_ & ~new_n17_;
  assign new_n19_ = ~new_n9_ & ~new_n18_;
  assign new_n20_ = ~a & e;
  assign new_n21_ = a & ~e;
  assign new_n22_ = ~new_n20_ & ~new_n21_;
  assign new_n23_ = d & ~new_n16_;
  assign new_n24_ = ~d & ~new_n12_;
  assign new_n25_ = ~new_n23_ & ~new_n24_;
  assign new_n26_ = ~new_n22_ & ~new_n25_;
  assign xor5 = new_n19_ | new_n26_;
endmodule


