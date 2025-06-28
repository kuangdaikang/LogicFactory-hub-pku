// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:44 2022

module newapla2  ( 
    \DST2s<0> , \DST2s<1> , \DST2s<2> , \DST2s<3> , \DST2s<4> , DSTvalid,
    writetoSHA1, writetoSHB1, writetoPSW1, writetoCWP1, pwritetoTB,
    pwritetoSWP, pwritetoPC  );
  input  \DST2s<0> , \DST2s<1> , \DST2s<2> , \DST2s<3> , \DST2s<4> ,
    DSTvalid;
  output writetoSHA1, writetoSHB1, writetoPSW1, writetoCWP1, pwritetoTB,
    pwritetoSWP, pwritetoPC;
  wire new_n14_, new_n15_, new_n16_, new_n17_, new_n19_, new_n20_, new_n21_,
    new_n22_, new_n24_, new_n25_, new_n26_, new_n28_, new_n29_, new_n30_,
    new_n32_, new_n33_, new_n34_, new_n35_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n42_, new_n43_, new_n44_;
  assign new_n14_ = \DST2s<0>  & \DST2s<1> ;
  assign new_n15_ = ~\DST2s<2>  & new_n14_;
  assign new_n16_ = ~\DST2s<3>  & new_n15_;
  assign new_n17_ = \DST2s<4>  & new_n16_;
  assign writetoSHA1 = DSTvalid & new_n17_;
  assign new_n19_ = ~\DST2s<0>  & \DST2s<1> ;
  assign new_n20_ = ~\DST2s<2>  & new_n19_;
  assign new_n21_ = ~\DST2s<3>  & new_n20_;
  assign new_n22_ = \DST2s<4>  & new_n21_;
  assign writetoSHB1 = DSTvalid & new_n22_;
  assign new_n24_ = \DST2s<2>  & new_n14_;
  assign new_n25_ = ~\DST2s<3>  & new_n24_;
  assign new_n26_ = \DST2s<4>  & new_n25_;
  assign writetoPSW1 = DSTvalid & new_n26_;
  assign new_n28_ = \DST2s<2>  & new_n19_;
  assign new_n29_ = ~\DST2s<3>  & new_n28_;
  assign new_n30_ = \DST2s<4>  & new_n29_;
  assign writetoCWP1 = DSTvalid & new_n30_;
  assign new_n32_ = \DST2s<0>  & ~\DST2s<1> ;
  assign new_n33_ = \DST2s<2>  & new_n32_;
  assign new_n34_ = ~\DST2s<3>  & new_n33_;
  assign new_n35_ = \DST2s<4>  & new_n34_;
  assign pwritetoTB = DSTvalid & new_n35_;
  assign new_n37_ = ~\DST2s<0>  & ~\DST2s<1> ;
  assign new_n38_ = \DST2s<2>  & new_n37_;
  assign new_n39_ = ~\DST2s<3>  & new_n38_;
  assign new_n40_ = \DST2s<4>  & new_n39_;
  assign pwritetoSWP = DSTvalid & new_n40_;
  assign new_n42_ = ~\DST2s<2>  & new_n32_;
  assign new_n43_ = ~\DST2s<3>  & new_n42_;
  assign new_n44_ = \DST2s<4>  & new_n43_;
  assign pwritetoPC = DSTvalid & new_n44_;
endmodule


