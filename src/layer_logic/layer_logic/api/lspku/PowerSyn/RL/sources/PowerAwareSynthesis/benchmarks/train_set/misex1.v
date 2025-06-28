// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:06 2022

module misex1  ( 
    dmpst3, dmpst2, dmpst1, dmpst0, xskip, yskip, page, rmwB,
    dmnst3B, dmnst2B, dmnst1B, dmnst0B, adctlp2B, adctlp1B, adctlp0B  );
  input  dmpst3, dmpst2, dmpst1, dmpst0, xskip, yskip, page, rmwB;
  output dmnst3B, dmnst2B, dmnst1B, dmnst0B, adctlp2B, adctlp1B, adctlp0B;
  wire new_n16_, new_n17_, new_n18_, new_n19_, new_n20_, new_n22_, new_n23_,
    new_n24_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_,
    new_n31_, new_n32_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_,
    new_n39_, new_n40_, new_n41_, new_n42_, new_n43_, new_n45_, new_n46_,
    new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n70_, new_n71_, new_n72_, new_n74_, new_n75_, new_n76_, new_n77_,
    new_n78_, new_n79_, new_n80_;
  assign new_n16_ = dmpst2 & dmpst0;
  assign new_n17_ = ~dmpst3 & new_n16_;
  assign new_n18_ = ~dmpst2 & ~dmpst0;
  assign new_n19_ = dmpst3 & new_n18_;
  assign new_n20_ = ~new_n17_ & ~new_n19_;
  assign dmnst3B = dmpst1 & ~new_n20_;
  assign new_n22_ = ~dmpst0 & ~yskip;
  assign new_n23_ = dmpst1 & ~new_n22_;
  assign new_n24_ = ~dmpst2 & new_n23_;
  assign new_n25_ = ~dmpst0 & page;
  assign new_n26_ = ~dmpst2 & ~new_n25_;
  assign new_n27_ = ~dmpst1 & ~new_n26_;
  assign new_n28_ = ~new_n24_ & ~new_n27_;
  assign new_n29_ = ~dmpst3 & ~new_n28_;
  assign new_n30_ = dmpst3 & ~dmpst2;
  assign new_n31_ = ~dmpst1 & dmpst0;
  assign new_n32_ = new_n30_ & new_n31_;
  assign dmnst2B = new_n29_ | new_n32_;
  assign new_n34_ = ~dmpst1 & xskip;
  assign new_n35_ = ~dmpst0 & ~new_n34_;
  assign new_n36_ = dmpst2 & ~new_n35_;
  assign new_n37_ = dmpst1 & ~yskip;
  assign new_n38_ = ~dmpst1 & ~page;
  assign new_n39_ = ~new_n37_ & ~new_n38_;
  assign new_n40_ = ~dmpst0 & ~new_n39_;
  assign new_n41_ = ~dmpst2 & new_n40_;
  assign new_n42_ = ~new_n36_ & ~new_n41_;
  assign new_n43_ = ~dmpst3 & ~new_n42_;
  assign dmnst1B = new_n32_ | new_n43_;
  assign new_n45_ = ~dmpst0 & ~xskip;
  assign new_n46_ = rmwB & ~new_n45_;
  assign new_n47_ = ~dmpst1 & ~new_n46_;
  assign new_n48_ = dmpst2 & new_n47_;
  assign new_n49_ = ~dmpst3 & new_n48_;
  assign new_n50_ = ~dmpst3 & yskip;
  assign new_n51_ = ~dmpst0 & ~new_n50_;
  assign new_n52_ = dmpst1 & new_n51_;
  assign new_n53_ = ~dmpst2 & new_n52_;
  assign dmnst0B = new_n49_ | new_n53_;
  assign new_n55_ = dmpst3 & new_n31_;
  assign new_n56_ = dmpst1 & ~dmpst0;
  assign new_n57_ = ~new_n55_ & ~new_n56_;
  assign new_n58_ = ~dmpst2 & ~new_n57_;
  assign new_n59_ = ~dmpst2 & dmpst0;
  assign new_n60_ = ~dmpst1 & ~new_n59_;
  assign new_n61_ = dmpst1 & dmpst0;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = ~dmpst3 & ~new_n62_;
  assign adctlp2B = new_n58_ | new_n63_;
  assign new_n65_ = ~new_n31_ & ~new_n56_;
  assign new_n66_ = dmpst3 & ~new_n65_;
  assign new_n67_ = dmpst1 & yskip;
  assign new_n68_ = ~dmpst3 & new_n67_;
  assign new_n69_ = ~new_n66_ & ~new_n68_;
  assign new_n70_ = ~dmpst2 & ~new_n69_;
  assign new_n71_ = ~new_n27_ & ~new_n61_;
  assign new_n72_ = ~dmpst3 & ~new_n71_;
  assign adctlp1B = new_n70_ | new_n72_;
  assign new_n74_ = dmpst1 & new_n22_;
  assign new_n75_ = ~new_n66_ & ~new_n74_;
  assign new_n76_ = ~dmpst2 & ~new_n75_;
  assign new_n77_ = ~dmpst1 & ~xskip;
  assign new_n78_ = ~dmpst0 & ~new_n77_;
  assign new_n79_ = dmpst2 & ~new_n78_;
  assign new_n80_ = ~dmpst3 & new_n79_;
  assign adctlp0B = new_n76_ | new_n80_;
endmodule


