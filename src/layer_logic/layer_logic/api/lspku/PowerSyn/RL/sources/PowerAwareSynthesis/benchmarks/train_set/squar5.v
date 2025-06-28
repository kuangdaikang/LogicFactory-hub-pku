// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:27 2022

module squar5  ( 
    i_0_, i_1_, i_2_, i_3_, i_4_,
    o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_  );
  input  i_0_, i_1_, i_2_, i_3_, i_4_;
  output o_0_, o_1_, o_2_, o_3_, o_4_, o_5_, o_6_, o_7_;
  wire new_n14_, new_n15_, new_n16_, new_n17_, new_n19_, new_n20_, new_n21_,
    new_n22_, new_n23_, new_n24_, new_n26_, new_n27_, new_n29_, new_n30_,
    new_n31_, new_n32_, new_n33_, new_n34_, new_n35_, new_n36_, new_n37_,
    new_n38_, new_n39_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_,
    new_n53_, new_n54_, new_n55_, new_n56_, new_n58_, new_n59_, new_n60_,
    new_n61_, new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_,
    new_n68_, new_n69_, new_n70_, new_n72_, new_n73_, new_n74_, new_n76_;
  assign new_n14_ = ~i_1_ & i_2_;
  assign new_n15_ = i_3_ & i_4_;
  assign new_n16_ = new_n14_ & new_n15_;
  assign new_n17_ = ~i_1_ & ~new_n16_;
  assign o_0_ = i_0_ & ~new_n17_;
  assign new_n19_ = i_1_ & i_2_;
  assign new_n20_ = ~i_1_ & ~i_2_;
  assign new_n21_ = ~new_n19_ & ~new_n20_;
  assign new_n22_ = i_2_ & ~i_3_;
  assign new_n23_ = ~i_1_ & new_n22_;
  assign new_n24_ = new_n21_ & ~new_n23_;
  assign o_7_ = i_3_ & ~i_4_;
  assign new_n26_ = new_n14_ & o_7_;
  assign new_n27_ = new_n24_ & ~new_n26_;
  assign o_1_ = i_0_ & ~new_n27_;
  assign new_n29_ = ~i_0_ & i_2_;
  assign new_n30_ = ~i_0_ & ~new_n29_;
  assign new_n31_ = i_3_ & ~new_n30_;
  assign new_n32_ = ~i_0_ & new_n22_;
  assign new_n33_ = ~new_n31_ & ~new_n32_;
  assign new_n34_ = i_1_ & ~new_n33_;
  assign new_n35_ = i_0_ & ~i_1_;
  assign new_n36_ = new_n22_ & new_n35_;
  assign new_n37_ = ~new_n34_ & ~new_n36_;
  assign new_n38_ = i_2_ & o_7_;
  assign new_n39_ = new_n35_ & new_n38_;
  assign o_2_ = ~new_n37_ | new_n39_;
  assign new_n41_ = ~i_1_ & i_3_;
  assign new_n42_ = i_1_ & ~i_3_;
  assign new_n43_ = ~new_n41_ & ~new_n42_;
  assign new_n44_ = i_0_ & ~new_n43_;
  assign new_n45_ = ~i_0_ & i_1_;
  assign new_n46_ = ~new_n44_ & ~new_n45_;
  assign new_n47_ = ~i_2_ & ~new_n46_;
  assign new_n48_ = i_2_ & i_3_;
  assign new_n49_ = new_n45_ & new_n48_;
  assign new_n50_ = ~new_n47_ & ~new_n49_;
  assign new_n51_ = ~i_2_ & i_3_;
  assign new_n52_ = ~i_2_ & ~new_n51_;
  assign new_n53_ = i_4_ & ~new_n52_;
  assign new_n54_ = i_1_ & new_n53_;
  assign new_n55_ = ~new_n26_ & ~new_n54_;
  assign new_n56_ = i_0_ & ~new_n55_;
  assign o_3_ = ~new_n50_ | new_n56_;
  assign new_n58_ = ~i_0_ & new_n19_;
  assign new_n59_ = i_0_ & new_n20_;
  assign new_n60_ = ~new_n58_ & ~new_n59_;
  assign new_n61_ = i_1_ & ~i_2_;
  assign new_n62_ = ~new_n14_ & ~new_n61_;
  assign new_n63_ = ~i_0_ & i_3_;
  assign new_n64_ = i_0_ & ~i_3_;
  assign new_n65_ = ~new_n63_ & ~new_n64_;
  assign new_n66_ = ~new_n62_ & ~new_n65_;
  assign new_n67_ = new_n60_ & ~new_n66_;
  assign new_n68_ = i_4_ & ~new_n67_;
  assign new_n69_ = ~i_4_ & ~new_n62_;
  assign new_n70_ = i_3_ & new_n69_;
  assign o_4_ = new_n68_ | new_n70_;
  assign new_n72_ = i_4_ & ~new_n62_;
  assign new_n73_ = ~i_3_ & ~i_4_;
  assign new_n74_ = i_2_ & new_n73_;
  assign o_5_ = new_n72_ | new_n74_;
  assign new_n76_ = ~new_n22_ & ~new_n51_;
  assign o_6_ = i_4_ & ~new_n76_;
endmodule


