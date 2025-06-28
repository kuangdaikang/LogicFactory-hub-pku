// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:38 2022

module sex  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8,
    \v9.0 , \v9.1 , \v9.2 , \v9.3 , \v9.4 , \v9.5 , \v9.6 , \v9.7 , \v9.8 ,
    \v9.9 , \v9.10 , \v9.11 , \v9.12 , \v9.13   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8;
  output \v9.0 , \v9.1 , \v9.2 , \v9.3 , \v9.4 , \v9.5 , \v9.6 , \v9.7 ,
    \v9.8 , \v9.9 , \v9.10 , \v9.11 , \v9.12 , \v9.13 ;
  wire new_n24_, new_n26_, new_n27_, new_n28_, new_n29_, new_n31_, new_n32_,
    new_n33_, new_n34_, new_n36_, new_n37_, new_n38_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n51_, new_n52_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n62_, new_n63_, new_n64_, new_n66_, new_n67_;
  assign new_n24_ = v0 & ~v7;
  assign \v9.0  = ~v8 & new_n24_;
  assign new_n26_ = ~v1 & ~v2;
  assign new_n27_ = v8 & ~new_n26_;
  assign new_n28_ = ~v7 & new_n27_;
  assign new_n29_ = ~v3 & new_n28_;
  assign \v9.1  = ~v0 & new_n29_;
  assign new_n31_ = ~v6 & v8;
  assign new_n32_ = ~v4 & new_n31_;
  assign new_n33_ = v6 & ~v8;
  assign new_n34_ = ~new_n32_ & ~new_n33_;
  assign \v9.2  = v5 & ~new_n34_;
  assign new_n36_ = v6 & v8;
  assign new_n37_ = ~v6 & ~v8;
  assign new_n38_ = new_n26_ & new_n37_;
  assign \v9.3  = new_n36_ | new_n38_;
  assign new_n40_ = ~v7 & ~new_n26_;
  assign new_n41_ = ~v6 & new_n40_;
  assign new_n42_ = ~v3 & new_n41_;
  assign new_n43_ = ~v0 & new_n42_;
  assign new_n44_ = v6 & v7;
  assign \v9.4  = new_n43_ | new_n44_;
  assign new_n46_ = ~v4 & ~v7;
  assign new_n47_ = ~v6 & ~new_n46_;
  assign new_n48_ = v6 & ~v7;
  assign new_n49_ = v0 & new_n48_;
  assign \v9.5  = new_n47_ | new_n49_;
  assign new_n51_ = v0 & ~new_n31_;
  assign new_n52_ = ~new_n33_ & ~new_n51_;
  assign \v9.7  = ~v7 & ~new_n52_;
  assign new_n54_ = ~v3 & v8;
  assign new_n55_ = v6 & ~new_n54_;
  assign new_n56_ = ~v0 & ~new_n55_;
  assign new_n57_ = ~v7 & ~new_n31_;
  assign new_n58_ = ~new_n56_ & new_n57_;
  assign \v9.8  = v1 & ~new_n58_;
  assign \v9.6  = \v9.7  | \v9.8 ;
  assign \v9.9  = v2 & ~new_n58_;
  assign new_n62_ = ~v4 & ~v5;
  assign new_n63_ = new_n31_ & new_n62_;
  assign new_n64_ = ~new_n33_ & ~new_n63_;
  assign \v9.10  = ~v7 & ~new_n64_;
  assign new_n66_ = ~v6 & new_n62_;
  assign new_n67_ = ~v7 & new_n66_;
  assign \v9.11  = v8 & new_n67_;
  assign \v9.12  = ~v6 & v7;
  assign \v9.13  = ~v8 & new_n48_;
endmodule


