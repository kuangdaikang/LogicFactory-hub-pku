// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:40 2022

module con1  ( 
    f, b, c, d, a, h, g,
    f0, f1  );
  input  f, b, c, d, a, h, g;
  output f0, f1;
  wire new_n10_, new_n11_, new_n12_, new_n13_, new_n14_, new_n15_, new_n16_,
    new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_,
    new_n25_;
  assign new_n10_ = ~f & h;
  assign new_n11_ = ~a & ~new_n10_;
  assign new_n12_ = b & ~new_n11_;
  assign new_n13_ = f & c;
  assign new_n14_ = ~b & ~c;
  assign new_n15_ = ~new_n13_ & ~new_n14_;
  assign new_n16_ = d & ~new_n15_;
  assign f0 = new_n12_ | new_n16_;
  assign new_n18_ = ~b & ~d;
  assign new_n19_ = a & ~new_n18_;
  assign new_n20_ = f & ~new_n19_;
  assign new_n21_ = b & a;
  assign new_n22_ = g & ~new_n21_;
  assign new_n23_ = ~f & ~new_n22_;
  assign new_n24_ = ~b & ~a;
  assign new_n25_ = ~new_n23_ & ~new_n24_;
  assign f1 = new_n20_ | ~new_n25_;
endmodule


