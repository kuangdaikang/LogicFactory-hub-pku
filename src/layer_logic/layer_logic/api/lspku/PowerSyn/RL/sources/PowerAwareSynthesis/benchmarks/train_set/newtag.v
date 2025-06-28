// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:36 2022

module newtag  ( 
    \busB<31> , \busA<31> , \busA<30> , \busB<30> , \busB<29> , \busA<29> ,
    \busB<28> , \busA<28> ,
    ptagcompare  );
  input  \busB<31> , \busA<31> , \busA<30> , \busB<30> , \busB<29> ,
    \busA<29> , \busB<28> , \busA<28> ;
  output ptagcompare;
  wire new_n10_, new_n11_, new_n12_, new_n13_, new_n14_, new_n15_, new_n16_,
    new_n17_;
  assign new_n10_ = \busB<29>  & \busA<29> ;
  assign new_n11_ = \busB<28>  & \busA<28> ;
  assign new_n12_ = ~new_n10_ & ~new_n11_;
  assign new_n13_ = ~\busB<29>  & ~\busA<29> ;
  assign new_n14_ = ~new_n12_ & ~new_n13_;
  assign new_n15_ = \busB<30>  & ~new_n14_;
  assign new_n16_ = \busA<31>  & ~\busA<30> ;
  assign new_n17_ = ~\busB<31>  & new_n16_;
  assign ptagcompare = new_n15_ | ~new_n17_;
endmodule


