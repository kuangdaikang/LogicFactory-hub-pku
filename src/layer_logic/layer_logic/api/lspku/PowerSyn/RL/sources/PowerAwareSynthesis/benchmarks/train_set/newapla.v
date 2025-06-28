// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:03 2022

module newapla  ( 
    \CPIPE1s<7> , \SRC1s<0> , \SRC1s<1> , \SRC1s<2> , \SRC1s<3> ,
    \SRC1s<4> , SRC1equalDST2, DSTvalid, pbusDtoINA, SRC2equal16,
    SRC2equalDST2, opc2load,
    readRFaccessA1, readRFaccessB1, AIzero1, AIzeroforce, busDtobusAa,
    DSTtobusDa2, preadTBtoA, preadSWPtoA, pForwardtoINB, preadPCtoA  );
  input  \CPIPE1s<7> , \SRC1s<0> , \SRC1s<1> , \SRC1s<2> , \SRC1s<3> ,
    \SRC1s<4> , SRC1equalDST2, DSTvalid, pbusDtoINA, SRC2equal16,
    SRC2equalDST2, opc2load;
  output readRFaccessA1, readRFaccessB1, AIzero1, AIzeroforce, busDtobusAa,
    DSTtobusDa2, preadTBtoA, preadSWPtoA, pForwardtoINB, preadPCtoA;
  wire new_n23_, new_n24_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_,
    new_n30_, new_n32_, new_n33_, new_n34_, new_n36_, new_n37_, new_n38_,
    new_n39_, new_n40_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_,
    new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n82_, new_n83_, new_n84_;
  assign new_n23_ = SRC1equalDST2 & DSTvalid;
  assign new_n24_ = ~\SRC1s<1>  & ~\SRC1s<2> ;
  assign new_n25_ = ~\SRC1s<0>  & new_n24_;
  assign new_n26_ = \SRC1s<4>  & ~pbusDtoINA;
  assign new_n27_ = ~\SRC1s<3>  & new_n26_;
  assign new_n28_ = new_n25_ & new_n27_;
  assign new_n29_ = ~pbusDtoINA & ~new_n28_;
  assign new_n30_ = new_n23_ & new_n29_;
  assign readRFaccessA1 = \CPIPE1s<7>  & ~new_n30_;
  assign new_n32_ = DSTvalid & ~pbusDtoINA;
  assign new_n33_ = ~SRC2equal16 & SRC2equalDST2;
  assign new_n34_ = new_n32_ & new_n33_;
  assign readRFaccessB1 = \CPIPE1s<7>  & ~new_n34_;
  assign new_n36_ = ~\SRC1s<0>  & ~\SRC1s<1> ;
  assign new_n37_ = \CPIPE1s<7>  & new_n36_;
  assign new_n38_ = ~\SRC1s<2>  & ~\SRC1s<3> ;
  assign new_n39_ = new_n26_ & new_n38_;
  assign new_n40_ = new_n37_ & new_n39_;
  assign AIzero1 = ~\CPIPE1s<7>  | new_n40_;
  assign new_n42_ = ~\SRC1s<0>  & \SRC1s<2> ;
  assign new_n43_ = ~\SRC1s<0>  & ~new_n42_;
  assign new_n44_ = \SRC1s<4>  & ~new_n43_;
  assign new_n45_ = ~\SRC1s<3>  & new_n44_;
  assign new_n46_ = ~\SRC1s<1>  & new_n45_;
  assign new_n47_ = ~\SRC1s<3>  & \SRC1s<4> ;
  assign new_n48_ = ~\SRC1s<1>  & new_n47_;
  assign new_n49_ = ~opc2load & ~new_n48_;
  assign new_n50_ = DSTvalid & new_n49_;
  assign new_n51_ = SRC1equalDST2 & new_n50_;
  assign new_n52_ = ~new_n46_ & ~new_n51_;
  assign new_n53_ = ~pbusDtoINA & ~new_n52_;
  assign busDtobusAa = \CPIPE1s<7>  & new_n53_;
  assign new_n55_ = ~pbusDtoINA & ~new_n48_;
  assign new_n56_ = ~\SRC1s<0>  & ~\SRC1s<2> ;
  assign new_n57_ = ~new_n55_ & new_n56_;
  assign new_n58_ = SRC1equalDST2 & ~new_n57_;
  assign new_n59_ = ~pbusDtoINA & new_n33_;
  assign new_n60_ = ~new_n58_ & ~new_n59_;
  assign new_n61_ = ~opc2load & ~new_n60_;
  assign new_n62_ = DSTvalid & new_n61_;
  assign new_n63_ = \CPIPE1s<7>  & new_n62_;
  assign DSTtobusDa2 = pbusDtoINA | new_n63_;
  assign new_n65_ = \CPIPE1s<7>  & \SRC1s<0> ;
  assign new_n66_ = ~\SRC1s<1>  & new_n65_;
  assign new_n67_ = \SRC1s<2>  & new_n66_;
  assign new_n68_ = ~\SRC1s<3>  & new_n67_;
  assign new_n69_ = \SRC1s<4>  & new_n68_;
  assign preadTBtoA = ~pbusDtoINA & new_n69_;
  assign new_n71_ = \CPIPE1s<7>  & ~\SRC1s<0> ;
  assign new_n72_ = ~\SRC1s<1>  & new_n71_;
  assign new_n73_ = \SRC1s<2>  & new_n72_;
  assign new_n74_ = ~\SRC1s<3>  & new_n73_;
  assign new_n75_ = \SRC1s<4>  & new_n74_;
  assign preadSWPtoA = ~pbusDtoINA & new_n75_;
  assign new_n77_ = \CPIPE1s<7>  & DSTvalid;
  assign new_n78_ = ~pbusDtoINA & new_n77_;
  assign new_n79_ = ~SRC2equal16 & new_n78_;
  assign new_n80_ = SRC2equalDST2 & new_n79_;
  assign pForwardtoINB = ~opc2load & new_n80_;
  assign new_n82_ = ~\SRC1s<2>  & new_n66_;
  assign new_n83_ = ~\SRC1s<3>  & new_n82_;
  assign new_n84_ = \SRC1s<4>  & new_n83_;
  assign preadPCtoA = ~pbusDtoINA & new_n84_;
  assign AIzeroforce = ~\CPIPE1s<7> ;
endmodule


