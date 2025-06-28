// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:31 2022

module sqrt8  ( 
    \v[7] , \v[6] , \v[5] , \v[4] , \v[3] , \v[2] , \v[1] , \v[0] ,
    \sqrt[0] , \sqrt[1] , \sqrt[2] , \sqrt[3]   );
  input  \v[7] , \v[6] , \v[5] , \v[4] , \v[3] , \v[2] , \v[1] , \v[0] ;
  output \sqrt[0] , \sqrt[1] , \sqrt[2] , \sqrt[3] ;
  wire new_n13_, new_n14_, new_n15_, new_n16_, new_n17_, new_n18_, new_n19_,
    new_n20_, new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_,
    new_n27_, new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_,
    new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_,
    new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_,
    new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n60_, new_n61_, new_n62_,
    new_n63_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n70_, new_n71_, new_n73_, new_n74_;
  assign new_n13_ = ~\v[1]  & ~\v[0] ;
  assign new_n14_ = \v[6]  & ~\v[5] ;
  assign new_n15_ = ~\v[3]  & ~new_n14_;
  assign new_n16_ = ~\v[7]  & ~new_n15_;
  assign new_n17_ = ~\v[6]  & \v[5] ;
  assign new_n18_ = ~new_n16_ & ~new_n17_;
  assign new_n19_ = \v[4]  & ~new_n18_;
  assign new_n20_ = \v[7]  & \v[3] ;
  assign new_n21_ = \v[6]  & ~\v[4] ;
  assign new_n22_ = ~\v[3]  & ~\v[2] ;
  assign new_n23_ = new_n21_ & new_n22_;
  assign new_n24_ = ~new_n20_ & ~new_n23_;
  assign new_n25_ = \v[5]  & ~new_n24_;
  assign new_n26_ = ~\v[6]  & ~\v[5] ;
  assign new_n27_ = ~\v[4]  & ~\v[2] ;
  assign new_n28_ = new_n26_ & new_n27_;
  assign new_n29_ = ~new_n25_ & ~new_n28_;
  assign new_n30_ = ~new_n19_ & new_n29_;
  assign new_n31_ = ~new_n13_ & ~new_n30_;
  assign new_n32_ = \v[6]  & ~new_n22_;
  assign new_n33_ = \v[7]  & ~new_n32_;
  assign new_n34_ = \v[3]  & \v[2] ;
  assign new_n35_ = ~\v[6]  & new_n34_;
  assign new_n36_ = ~new_n33_ & ~new_n35_;
  assign new_n37_ = ~\v[5]  & ~new_n36_;
  assign new_n38_ = ~\v[7]  & \v[5] ;
  assign new_n39_ = new_n22_ & new_n38_;
  assign new_n40_ = ~new_n37_ & ~new_n39_;
  assign new_n41_ = ~\v[4]  & ~new_n40_;
  assign new_n42_ = \v[7]  & \v[5] ;
  assign new_n43_ = ~\v[5]  & \v[4] ;
  assign new_n44_ = ~\v[7]  & new_n43_;
  assign new_n45_ = ~new_n42_ & ~new_n44_;
  assign new_n46_ = \v[6]  & ~new_n45_;
  assign new_n47_ = \v[5]  & \v[4] ;
  assign new_n48_ = ~\v[6]  & new_n47_;
  assign new_n49_ = ~new_n46_ & ~new_n48_;
  assign new_n50_ = ~new_n22_ & ~new_n49_;
  assign new_n51_ = ~\v[4]  & ~new_n34_;
  assign new_n52_ = \v[5]  & ~new_n51_;
  assign new_n53_ = \v[7]  & new_n52_;
  assign new_n54_ = ~\v[7]  & \v[4] ;
  assign new_n55_ = new_n34_ & new_n54_;
  assign new_n56_ = ~new_n53_ & ~new_n55_;
  assign new_n57_ = ~new_n50_ & new_n56_;
  assign new_n58_ = ~new_n41_ & new_n57_;
  assign \sqrt[0]  = new_n31_ | ~new_n58_;
  assign new_n60_ = ~\v[5]  & ~\v[4] ;
  assign new_n61_ = \v[6]  & ~new_n60_;
  assign new_n62_ = \v[6]  & new_n22_;
  assign new_n63_ = ~\v[4]  & ~new_n62_;
  assign new_n64_ = ~\v[5]  & new_n63_;
  assign new_n65_ = ~new_n61_ & ~new_n64_;
  assign new_n66_ = \v[7]  & ~new_n65_;
  assign new_n67_ = ~\v[6]  & new_n60_;
  assign new_n68_ = ~new_n38_ & ~new_n67_;
  assign new_n69_ = ~new_n22_ & ~new_n68_;
  assign new_n70_ = ~\v[7]  & new_n47_;
  assign new_n71_ = ~new_n69_ & ~new_n70_;
  assign \sqrt[1]  = new_n66_ | ~new_n71_;
  assign new_n73_ = ~\v[6]  & ~new_n60_;
  assign new_n74_ = \v[7]  & \v[6] ;
  assign \sqrt[2]  = new_n73_ | new_n74_;
  assign \sqrt[3]  = \v[7]  | \v[6] ;
endmodule


