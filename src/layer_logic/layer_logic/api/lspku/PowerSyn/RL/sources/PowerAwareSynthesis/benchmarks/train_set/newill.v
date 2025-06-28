// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:42 2022

module newill  ( 
    \CPIPE1s<9> , \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> ,
    \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> ,
    pillegalopc  );
  input  \CPIPE1s<9> , \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> ,
    \CPIPE1s<3> , \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> ;
  output pillegalopc;
  wire new_n10_, new_n11_, new_n12_, new_n13_, new_n14_, new_n15_, new_n16_,
    new_n17_, new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_,
    new_n24_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_,
    new_n31_, new_n32_, new_n33_;
  assign new_n10_ = ~\CPIPE1s<4>  & \CPIPE1s<5> ;
  assign new_n11_ = \CPIPE1s<1>  & new_n10_;
  assign new_n12_ = \CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n13_ = \CPIPE1s<3>  & new_n12_;
  assign new_n14_ = ~new_n11_ & ~new_n13_;
  assign new_n15_ = ~\CPIPE1s<2>  & ~new_n14_;
  assign new_n16_ = \CPIPE1s<3>  & \CPIPE1s<4> ;
  assign new_n17_ = ~\CPIPE1s<3>  & ~\CPIPE1s<4> ;
  assign new_n18_ = ~new_n16_ & ~new_n17_;
  assign new_n19_ = ~\CPIPE1s<5>  & ~new_n18_;
  assign new_n20_ = \CPIPE1s<1>  & new_n19_;
  assign new_n21_ = \CPIPE1s<2>  & \CPIPE1s<3> ;
  assign new_n22_ = ~\CPIPE1s<1>  & ~\CPIPE1s<3> ;
  assign new_n23_ = ~new_n21_ & ~new_n22_;
  assign new_n24_ = \CPIPE1s<5>  & ~new_n23_;
  assign new_n25_ = ~\CPIPE1s<4>  & new_n24_;
  assign new_n26_ = ~new_n20_ & ~new_n25_;
  assign new_n27_ = ~new_n15_ & new_n26_;
  assign new_n28_ = \CPIPE1s<0>  & ~new_n27_;
  assign new_n29_ = ~\CPIPE1s<2>  & ~\CPIPE1s<3> ;
  assign new_n30_ = ~\CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n31_ = new_n29_ & new_n30_;
  assign new_n32_ = ~new_n28_ & ~new_n31_;
  assign new_n33_ = \CPIPE1s<7>  & ~new_n32_;
  assign pillegalopc = \CPIPE1s<9>  | new_n33_;
endmodule


