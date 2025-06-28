// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:53 2022

module rd53  ( 
    i_0_, i_1_, i_2_, i_3_, i_4_,
    o_0_, o_1_, o_2_  );
  input  i_0_, i_1_, i_2_, i_3_, i_4_;
  output o_0_, o_1_, o_2_;
  wire new_n9_, new_n10_, new_n11_, new_n12_, new_n13_, new_n14_, new_n15_,
    new_n16_, new_n17_, new_n18_, new_n20_, new_n21_, new_n22_, new_n23_,
    new_n24_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_,
    new_n31_, new_n32_, new_n33_, new_n34_, new_n35_, new_n36_, new_n38_,
    new_n39_, new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_,
    new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_, new_n59_,
    new_n60_, new_n61_, new_n62_;
  assign new_n9_ = ~i_3_ & ~i_4_;
  assign new_n10_ = i_2_ & ~new_n9_;
  assign new_n11_ = i_3_ & i_4_;
  assign new_n12_ = ~new_n10_ & ~new_n11_;
  assign new_n13_ = i_1_ & ~new_n12_;
  assign new_n14_ = i_2_ & new_n11_;
  assign new_n15_ = ~new_n13_ & ~new_n14_;
  assign new_n16_ = i_0_ & ~new_n15_;
  assign new_n17_ = i_1_ & i_2_;
  assign new_n18_ = new_n11_ & new_n17_;
  assign o_0_ = new_n16_ | new_n18_;
  assign new_n20_ = ~new_n9_ & ~new_n11_;
  assign new_n21_ = ~i_1_ & ~i_2_;
  assign new_n22_ = ~new_n17_ & ~new_n21_;
  assign new_n23_ = i_0_ & ~new_n22_;
  assign new_n24_ = ~i_1_ & i_2_;
  assign new_n25_ = i_1_ & ~i_2_;
  assign new_n26_ = ~new_n24_ & ~new_n25_;
  assign new_n27_ = ~i_0_ & ~new_n26_;
  assign new_n28_ = ~new_n23_ & ~new_n27_;
  assign new_n29_ = ~new_n20_ & ~new_n28_;
  assign new_n30_ = ~i_3_ & i_4_;
  assign new_n31_ = i_3_ & ~i_4_;
  assign new_n32_ = ~new_n30_ & ~new_n31_;
  assign new_n33_ = i_0_ & ~new_n26_;
  assign new_n34_ = ~i_0_ & ~new_n22_;
  assign new_n35_ = ~new_n33_ & ~new_n34_;
  assign new_n36_ = ~new_n32_ & ~new_n35_;
  assign o_1_ = new_n29_ | new_n36_;
  assign new_n38_ = ~i_2_ & i_4_;
  assign new_n39_ = i_2_ & ~i_4_;
  assign new_n40_ = ~new_n38_ & ~new_n39_;
  assign new_n41_ = ~i_3_ & ~new_n40_;
  assign new_n42_ = ~i_1_ & i_3_;
  assign new_n43_ = i_1_ & ~i_4_;
  assign new_n44_ = ~new_n42_ & ~new_n43_;
  assign new_n45_ = ~i_2_ & ~new_n44_;
  assign new_n46_ = ~new_n41_ & ~new_n45_;
  assign new_n47_ = i_0_ & ~new_n46_;
  assign new_n48_ = ~i_0_ & i_4_;
  assign new_n49_ = ~new_n43_ & ~new_n48_;
  assign new_n50_ = ~i_2_ & ~new_n49_;
  assign new_n51_ = ~i_1_ & new_n39_;
  assign new_n52_ = ~new_n50_ & ~new_n51_;
  assign new_n53_ = i_3_ & ~new_n52_;
  assign new_n54_ = ~new_n30_ & ~new_n39_;
  assign new_n55_ = i_1_ & ~new_n54_;
  assign new_n56_ = i_2_ & i_4_;
  assign new_n57_ = ~i_1_ & new_n56_;
  assign new_n58_ = ~new_n55_ & ~new_n57_;
  assign new_n59_ = ~i_0_ & ~new_n58_;
  assign new_n60_ = new_n24_ & new_n30_;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = ~new_n53_ & new_n61_;
  assign o_2_ = new_n47_ | ~new_n62_;
endmodule


