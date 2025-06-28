// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:53 2022

module newcwp  ( 
    \CWP<6> , \CWP<5> , \CWP<4> , changeCWP2,
    \CWP+1<2> , \CWP+1<1> , \CWP+1<0> , \CWPm1<1> , \CWPm1<2>   );
  input  \CWP<6> , \CWP<5> , \CWP<4> , changeCWP2;
  output \CWP+1<2> , \CWP+1<1> , \CWP+1<0> , \CWPm1<1> , \CWPm1<2> ;
  wire new_n10_, new_n11_, new_n12_, new_n13_, new_n14_, new_n15_, new_n17_,
    new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n25_,
    new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n32_, new_n33_,
    new_n34_;
  assign new_n10_ = ~\CWP<5>  & \CWP<4> ;
  assign new_n11_ = \CWP<5>  & ~\CWP<4> ;
  assign new_n12_ = ~new_n10_ & ~new_n11_;
  assign new_n13_ = \CWP<6>  & ~new_n12_;
  assign new_n14_ = \CWP<5>  & \CWP<4> ;
  assign new_n15_ = ~\CWP<5>  & ~\CWP<4> ;
  assign \CWPm1<1>  = new_n14_ | new_n15_;
  assign new_n17_ = ~\CWP<6>  & \CWPm1<1> ;
  assign new_n18_ = ~\CWP<4>  & changeCWP2;
  assign new_n19_ = ~\CWP<5>  & new_n18_;
  assign new_n20_ = \CWP<4>  & ~changeCWP2;
  assign new_n21_ = \CWP<5>  & new_n20_;
  assign new_n22_ = ~new_n19_ & ~new_n21_;
  assign new_n23_ = ~new_n17_ & new_n22_;
  assign \CWP+1<2>  = new_n13_ | ~new_n23_;
  assign new_n25_ = ~new_n18_ & ~new_n20_;
  assign new_n26_ = \CWP<5>  & ~new_n25_;
  assign new_n27_ = \CWP<4>  & changeCWP2;
  assign new_n28_ = ~\CWP<4>  & ~changeCWP2;
  assign new_n29_ = ~new_n27_ & ~new_n28_;
  assign new_n30_ = ~\CWP<5>  & ~new_n29_;
  assign \CWP+1<1>  = new_n26_ | new_n30_;
  assign new_n32_ = ~\CWP<5>  & ~new_n10_;
  assign new_n33_ = \CWP<6>  & ~new_n32_;
  assign new_n34_ = ~\CWP<6>  & new_n15_;
  assign \CWPm1<2>  = new_n33_ | new_n34_;
  assign \CWP+1<0>  = ~\CWP<4> ;
endmodule


