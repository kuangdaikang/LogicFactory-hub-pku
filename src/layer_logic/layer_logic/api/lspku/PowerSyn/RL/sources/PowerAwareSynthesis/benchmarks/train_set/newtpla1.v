// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:54 2022

module newtpla1  ( 
    \CPIPE1s<6> , \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> ,
    \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> , \AIprocessed<31> ,
    \AIprocessed<30> ,
    shiftAbus31, shiftAbus30  );
  input  \CPIPE1s<6> , \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> ,
    \CPIPE1s<3> , \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> ,
    \AIprocessed<31> , \AIprocessed<30> ;
  output shiftAbus31, shiftAbus30;
  wire new_n13_, new_n14_, new_n15_, new_n16_, new_n17_, new_n18_, new_n19_,
    new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_;
  assign new_n13_ = ~\CPIPE1s<6>  & ~\CPIPE1s<1> ;
  assign new_n14_ = \AIprocessed<31>  & ~new_n13_;
  assign new_n15_ = \CPIPE1s<7>  & new_n14_;
  assign new_n16_ = \CPIPE1s<5>  & new_n15_;
  assign new_n17_ = ~\CPIPE1s<4>  & new_n16_;
  assign new_n18_ = ~\CPIPE1s<3>  & new_n17_;
  assign new_n19_ = ~\CPIPE1s<2>  & new_n18_;
  assign shiftAbus31 = ~\CPIPE1s<0>  & new_n19_;
  assign new_n21_ = ~\CPIPE1s<6>  & \AIprocessed<31> ;
  assign new_n22_ = \CPIPE1s<1>  & \AIprocessed<30> ;
  assign new_n23_ = \CPIPE1s<6>  & new_n22_;
  assign new_n24_ = ~new_n21_ & ~new_n23_;
  assign new_n25_ = \CPIPE1s<7>  & ~new_n24_;
  assign new_n26_ = \CPIPE1s<5>  & new_n25_;
  assign new_n27_ = ~\CPIPE1s<4>  & new_n26_;
  assign new_n28_ = ~\CPIPE1s<3>  & new_n27_;
  assign new_n29_ = ~\CPIPE1s<2>  & new_n28_;
  assign shiftAbus30 = ~\CPIPE1s<0>  & new_n29_;
endmodule


