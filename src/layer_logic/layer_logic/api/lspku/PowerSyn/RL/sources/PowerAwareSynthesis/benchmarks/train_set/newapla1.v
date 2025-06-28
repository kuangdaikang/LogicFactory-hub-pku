// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:52 2022

module newapla1  ( 
    \SRC1s<0> , \SRC1s<1> , \SRC1s<2> , \SRC1s<3> , \SRC1s<4> ,
    \CPIPE1s<7> , pbusDtoINA, SRC2equal16, SRC2equalDST2, opc2load,
    DSTvalid, SRC1equalDST2,
    pbusStobusA, pSHAtobusA, pSHBtobusA, preadPSWtoA, preadCWPtoA,
    LoadforwtoINB1, LoadforwtoINA1  );
  input  \SRC1s<0> , \SRC1s<1> , \SRC1s<2> , \SRC1s<3> , \SRC1s<4> ,
    \CPIPE1s<7> , pbusDtoINA, SRC2equal16, SRC2equalDST2, opc2load,
    DSTvalid, SRC1equalDST2;
  output pbusStobusA, pSHAtobusA, pSHBtobusA, preadPSWtoA, preadCWPtoA,
    LoadforwtoINB1, LoadforwtoINA1;
  wire new_n20_, new_n21_, new_n22_, new_n23_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n37_, new_n38_, new_n39_, new_n40_, new_n42_, new_n43_, new_n44_,
    new_n45_, new_n47_, new_n48_, new_n49_, new_n51_, new_n52_, new_n53_,
    new_n54_, new_n55_, new_n56_, new_n57_, new_n58_;
  assign new_n20_ = \CPIPE1s<7>  & ~pbusDtoINA;
  assign new_n21_ = \SRC1s<4>  & new_n20_;
  assign new_n22_ = ~\SRC1s<3>  & new_n21_;
  assign new_n23_ = \SRC1s<2>  & new_n22_;
  assign pbusStobusA = \SRC1s<1>  & new_n23_;
  assign new_n25_ = \SRC1s<0>  & \SRC1s<1> ;
  assign new_n26_ = ~\SRC1s<2>  & new_n25_;
  assign new_n27_ = ~\SRC1s<3>  & new_n26_;
  assign new_n28_ = \SRC1s<4>  & new_n27_;
  assign new_n29_ = \CPIPE1s<7>  & new_n28_;
  assign pSHAtobusA = ~pbusDtoINA & new_n29_;
  assign new_n31_ = ~\SRC1s<0>  & \SRC1s<1> ;
  assign new_n32_ = ~\SRC1s<2>  & new_n31_;
  assign new_n33_ = ~\SRC1s<3>  & new_n32_;
  assign new_n34_ = \SRC1s<4>  & new_n33_;
  assign new_n35_ = \CPIPE1s<7>  & new_n34_;
  assign pSHBtobusA = ~pbusDtoINA & new_n35_;
  assign new_n37_ = \SRC1s<2>  & new_n25_;
  assign new_n38_ = ~\SRC1s<3>  & new_n37_;
  assign new_n39_ = \SRC1s<4>  & new_n38_;
  assign new_n40_ = \CPIPE1s<7>  & new_n39_;
  assign preadPSWtoA = ~pbusDtoINA & new_n40_;
  assign new_n42_ = \SRC1s<2>  & new_n31_;
  assign new_n43_ = ~\SRC1s<3>  & new_n42_;
  assign new_n44_ = \SRC1s<4>  & new_n43_;
  assign new_n45_ = \CPIPE1s<7>  & new_n44_;
  assign preadCWPtoA = ~pbusDtoINA & new_n45_;
  assign new_n47_ = ~SRC2equal16 & new_n20_;
  assign new_n48_ = SRC2equalDST2 & new_n47_;
  assign new_n49_ = opc2load & new_n48_;
  assign LoadforwtoINB1 = DSTvalid & new_n49_;
  assign new_n51_ = ~\SRC1s<0>  & ~\SRC1s<1> ;
  assign new_n52_ = ~\SRC1s<3>  & \SRC1s<4> ;
  assign new_n53_ = ~\SRC1s<2>  & new_n52_;
  assign new_n54_ = new_n51_ & new_n53_;
  assign new_n55_ = SRC1equalDST2 & ~new_n54_;
  assign new_n56_ = DSTvalid & new_n55_;
  assign new_n57_ = opc2load & new_n56_;
  assign new_n58_ = ~pbusDtoINA & new_n57_;
  assign LoadforwtoINA1 = \CPIPE1s<7>  & new_n58_;
endmodule


