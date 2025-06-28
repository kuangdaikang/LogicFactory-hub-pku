// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:01 2022

module newcond  ( 
    cAin0, cselaluSUM, caluZout, cBIprocessedMSB, cAIprocessedMSB, cALUmsb,
    \cDST1s<0> , \cDST1s<1> , \cDST1s<2> , \cDST1s<3> , \cDST1s<4> ,
    pCONDvalid, aluVout  );
  input  cAin0, cselaluSUM, caluZout, cBIprocessedMSB, cAIprocessedMSB,
    cALUmsb, \cDST1s<0> , \cDST1s<1> , \cDST1s<2> , \cDST1s<3> ,
    \cDST1s<4> ;
  output pCONDvalid, aluVout;
  wire new_n14_, new_n15_, new_n16_, new_n17_, new_n18_, new_n19_, new_n20_,
    new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_,
    new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_,
    new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_,
    new_n63_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_,
    new_n77_, new_n78_, new_n80_, new_n81_, new_n82_;
  assign new_n14_ = ~cALUmsb & ~\cDST1s<3> ;
  assign new_n15_ = ~cselaluSUM & ~new_n14_;
  assign new_n16_ = ~cAIprocessedMSB & cALUmsb;
  assign new_n17_ = cAIprocessedMSB & ~\cDST1s<3> ;
  assign new_n18_ = cselaluSUM & new_n17_;
  assign new_n19_ = ~new_n16_ & ~new_n18_;
  assign new_n20_ = cBIprocessedMSB & ~new_n19_;
  assign new_n21_ = cAIprocessedMSB & cALUmsb;
  assign new_n22_ = ~cAIprocessedMSB & \cDST1s<3> ;
  assign new_n23_ = ~new_n21_ & ~new_n22_;
  assign new_n24_ = ~cBIprocessedMSB & ~new_n23_;
  assign new_n25_ = caluZout & \cDST1s<2> ;
  assign new_n26_ = ~new_n24_ & ~new_n25_;
  assign new_n27_ = ~new_n20_ & new_n26_;
  assign new_n28_ = ~new_n15_ & new_n27_;
  assign new_n29_ = \cDST1s<1>  & ~new_n28_;
  assign new_n30_ = \cDST1s<2>  & ~\cDST1s<3> ;
  assign new_n31_ = caluZout & new_n30_;
  assign new_n32_ = ~new_n29_ & ~new_n31_;
  assign new_n33_ = ~\cDST1s<0>  & ~new_n32_;
  assign new_n34_ = ~cAIprocessedMSB & ~cALUmsb;
  assign new_n35_ = cAIprocessedMSB & \cDST1s<3> ;
  assign new_n36_ = ~new_n34_ & ~new_n35_;
  assign new_n37_ = cBIprocessedMSB & ~new_n36_;
  assign new_n38_ = cAIprocessedMSB & ~cALUmsb;
  assign new_n39_ = ~cBIprocessedMSB & new_n38_;
  assign new_n40_ = ~new_n37_ & ~new_n39_;
  assign new_n41_ = \cDST1s<1>  & ~new_n40_;
  assign new_n42_ = ~cAIprocessedMSB & ~\cDST1s<3> ;
  assign new_n43_ = ~cBIprocessedMSB & new_n42_;
  assign new_n44_ = ~new_n41_ & ~new_n43_;
  assign new_n45_ = cselaluSUM & ~new_n44_;
  assign new_n46_ = ~cselaluSUM & ~cALUmsb;
  assign new_n47_ = \cDST1s<1>  & ~new_n46_;
  assign new_n48_ = ~\cDST1s<3>  & ~new_n47_;
  assign new_n49_ = ~new_n45_ & ~new_n48_;
  assign new_n50_ = ~new_n25_ & ~new_n49_;
  assign new_n51_ = \cDST1s<0>  & new_n50_;
  assign new_n52_ = ~new_n33_ & ~new_n51_;
  assign new_n53_ = ~\cDST1s<4>  & ~new_n52_;
  assign new_n54_ = ~cBIprocessedMSB & cAIprocessedMSB;
  assign new_n55_ = cBIprocessedMSB & ~cAIprocessedMSB;
  assign new_n56_ = ~new_n54_ & ~new_n55_;
  assign new_n57_ = cselaluSUM & ~caluZout;
  assign new_n58_ = ~cALUmsb & \cDST1s<0> ;
  assign new_n59_ = new_n57_ & new_n58_;
  assign new_n60_ = cALUmsb & ~\cDST1s<0> ;
  assign new_n61_ = ~cAin0 & new_n60_;
  assign new_n62_ = ~new_n59_ & ~new_n61_;
  assign new_n63_ = ~new_n56_ & ~new_n62_;
  assign new_n64_ = cBIprocessedMSB & cAIprocessedMSB;
  assign new_n65_ = new_n57_ & new_n64_;
  assign new_n66_ = ~cAin0 & ~new_n65_;
  assign new_n67_ = \cDST1s<0>  & ~new_n66_;
  assign new_n68_ = ~cBIprocessedMSB & ~cAIprocessedMSB;
  assign new_n69_ = ~caluZout & ~new_n68_;
  assign new_n70_ = cselaluSUM & new_n69_;
  assign new_n71_ = ~\cDST1s<0>  & ~new_n70_;
  assign new_n72_ = ~cAin0 & new_n71_;
  assign new_n73_ = ~new_n67_ & ~new_n72_;
  assign new_n74_ = \cDST1s<4>  & ~new_n73_;
  assign new_n75_ = ~new_n63_ & ~new_n74_;
  assign new_n76_ = ~\cDST1s<3>  & ~new_n75_;
  assign new_n77_ = ~\cDST1s<2>  & new_n76_;
  assign new_n78_ = \cDST1s<1>  & new_n77_;
  assign pCONDvalid = new_n53_ | new_n78_;
  assign new_n80_ = ~cBIprocessedMSB & new_n16_;
  assign new_n81_ = cBIprocessedMSB & new_n38_;
  assign new_n82_ = ~new_n80_ & ~new_n81_;
  assign aluVout = cselaluSUM & ~new_n82_;
endmodule


