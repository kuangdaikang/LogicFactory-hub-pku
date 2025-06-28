// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:55 2022

module newbyte  ( 
    EX_INSpass, byteEX, s1, s0, phi3,
    ex3, ex2, ex1, ex0, ins3, ins2, ins1, ins0  );
  input  EX_INSpass, byteEX, s1, s0, phi3;
  output ex3, ex2, ex1, ex0, ins3, ins2, ins1, ins0;
  wire new_n14_, new_n15_, new_n16_, new_n18_, new_n20_, new_n21_, new_n23_,
    new_n25_, new_n26_, new_n27_, new_n29_, new_n31_, new_n32_, new_n34_;
  assign new_n14_ = ~EX_INSpass & byteEX;
  assign new_n15_ = s1 & new_n14_;
  assign new_n16_ = s0 & new_n15_;
  assign ex3 = phi3 & new_n16_;
  assign new_n18_ = ~s0 & new_n15_;
  assign ex2 = phi3 & new_n18_;
  assign new_n20_ = ~s1 & new_n14_;
  assign new_n21_ = s0 & new_n20_;
  assign ex1 = phi3 & new_n21_;
  assign new_n23_ = ~s0 & new_n20_;
  assign ex0 = phi3 & new_n23_;
  assign new_n25_ = ~EX_INSpass & ~byteEX;
  assign new_n26_ = s1 & new_n25_;
  assign new_n27_ = s0 & new_n26_;
  assign ins3 = phi3 & new_n27_;
  assign new_n29_ = ~s0 & new_n26_;
  assign ins2 = phi3 & new_n29_;
  assign new_n31_ = ~s1 & new_n25_;
  assign new_n32_ = s0 & new_n31_;
  assign ins1 = phi3 & new_n32_;
  assign new_n34_ = ~s0 & new_n31_;
  assign ins0 = phi3 & new_n34_;
endmodule


