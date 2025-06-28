// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:01 2022

module newcpla2  ( 
    \CPIPE2s<0> , \CPIPE2s<1> , \CPIPE2s<2> , \CPIPE2s<3> , \CPIPE2s<4> ,
    \CPIPE2s<5> , \CPIPE2s<7> ,
    writeRFaccess2, lastPCtobusD1, busDtobusB2, busDtobusA2, DSTtobusD2,
    nillonreturn, pLOADwrite, opc2load, DSTvalid, pbusDtoINA  );
  input  \CPIPE2s<0> , \CPIPE2s<1> , \CPIPE2s<2> , \CPIPE2s<3> ,
    \CPIPE2s<4> , \CPIPE2s<5> , \CPIPE2s<7> ;
  output writeRFaccess2, lastPCtobusD1, busDtobusB2, busDtobusA2, DSTtobusD2,
    nillonreturn, pLOADwrite, opc2load, DSTvalid, pbusDtoINA;
  wire new_n18_, new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_,
    new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n31_,
    new_n32_, new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_,
    new_n39_, new_n40_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_,
    new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n61_, new_n62_, new_n63_,
    new_n65_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n73_,
    new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_, new_n80_,
    new_n81_, new_n82_, new_n83_, new_n85_, new_n86_, new_n87_, new_n88_,
    new_n89_, new_n90_, new_n91_, new_n92_;
  assign new_n18_ = ~\CPIPE2s<3>  & ~\CPIPE2s<4> ;
  assign new_n19_ = \CPIPE2s<0>  & \CPIPE2s<3> ;
  assign new_n20_ = \CPIPE2s<4>  & ~\CPIPE2s<5> ;
  assign new_n21_ = new_n19_ & new_n20_;
  assign new_n22_ = ~new_n18_ & ~new_n21_;
  assign new_n23_ = ~\CPIPE2s<2>  & ~new_n22_;
  assign new_n24_ = \CPIPE2s<3>  & ~\CPIPE2s<5> ;
  assign new_n25_ = \CPIPE2s<4>  & ~new_n24_;
  assign new_n26_ = \CPIPE2s<0>  & ~new_n25_;
  assign new_n27_ = ~\CPIPE2s<4>  & ~\CPIPE2s<5> ;
  assign new_n28_ = \CPIPE2s<3>  & new_n27_;
  assign new_n29_ = ~new_n26_ & ~new_n28_;
  assign new_n30_ = \CPIPE2s<1>  & ~new_n29_;
  assign new_n31_ = ~\CPIPE2s<3>  & \CPIPE2s<4> ;
  assign new_n32_ = \CPIPE2s<4>  & ~new_n31_;
  assign new_n33_ = \CPIPE2s<5>  & ~new_n32_;
  assign new_n34_ = ~new_n30_ & ~new_n33_;
  assign new_n35_ = ~new_n23_ & new_n34_;
  assign new_n36_ = \CPIPE2s<7>  & ~new_n35_;
  assign new_n37_ = \CPIPE2s<0>  & ~\CPIPE2s<1> ;
  assign new_n38_ = \CPIPE2s<2>  & new_n18_;
  assign new_n39_ = new_n37_ & new_n38_;
  assign new_n40_ = \CPIPE2s<7>  & ~new_n39_;
  assign lastPCtobusD1 = ~\CPIPE2s<5>  & ~new_n40_;
  assign writeRFaccess2 = new_n36_ | lastPCtobusD1;
  assign new_n43_ = ~\CPIPE2s<3>  & \CPIPE2s<5> ;
  assign new_n44_ = \CPIPE2s<2>  & new_n43_;
  assign new_n45_ = ~new_n24_ & ~new_n44_;
  assign new_n46_ = \CPIPE2s<1>  & ~new_n45_;
  assign new_n47_ = ~\CPIPE2s<2>  & \CPIPE2s<3> ;
  assign new_n48_ = ~\CPIPE2s<1>  & new_n47_;
  assign new_n49_ = \CPIPE2s<0>  & ~new_n48_;
  assign new_n50_ = \CPIPE2s<5>  & ~new_n49_;
  assign new_n51_ = ~new_n46_ & ~new_n50_;
  assign new_n52_ = \CPIPE2s<7>  & ~new_n51_;
  assign new_n53_ = ~\CPIPE2s<3>  & ~\CPIPE2s<5> ;
  assign new_n54_ = \CPIPE2s<2>  & new_n53_;
  assign new_n55_ = new_n37_ & new_n54_;
  assign new_n56_ = ~new_n52_ & ~new_n55_;
  assign new_n57_ = ~\CPIPE2s<4>  & ~new_n56_;
  assign new_n58_ = ~\CPIPE2s<5>  & ~\CPIPE2s<7> ;
  assign busDtobusB2 = new_n57_ | new_n58_;
  assign DSTtobusD2 = ~\CPIPE2s<4>  & new_n52_;
  assign new_n61_ = \CPIPE2s<1>  & \CPIPE2s<3> ;
  assign new_n62_ = ~\CPIPE2s<4>  & new_n61_;
  assign new_n63_ = ~\CPIPE2s<5>  & new_n62_;
  assign nillonreturn = \CPIPE2s<7>  & new_n63_;
  assign new_n65_ = \CPIPE2s<5>  & new_n31_;
  assign pLOADwrite = \CPIPE2s<7>  & new_n65_;
  assign new_n67_ = ~\CPIPE2s<0>  & ~\CPIPE2s<1> ;
  assign new_n68_ = ~\CPIPE2s<2>  & new_n67_;
  assign new_n69_ = ~\CPIPE2s<3>  & new_n68_;
  assign new_n70_ = \CPIPE2s<4>  & new_n69_;
  assign new_n71_ = \CPIPE2s<5>  & new_n70_;
  assign opc2load = \CPIPE2s<7>  & new_n71_;
  assign new_n73_ = \CPIPE2s<1>  & ~new_n25_;
  assign new_n74_ = new_n20_ & new_n47_;
  assign new_n75_ = ~new_n73_ & ~new_n74_;
  assign new_n76_ = \CPIPE2s<0>  & ~new_n75_;
  assign new_n77_ = ~\CPIPE2s<2>  & ~\CPIPE2s<4> ;
  assign new_n78_ = \CPIPE2s<4>  & \CPIPE2s<5> ;
  assign new_n79_ = ~new_n77_ & ~new_n78_;
  assign new_n80_ = ~\CPIPE2s<3>  & ~new_n79_;
  assign new_n81_ = ~\CPIPE2s<4>  & ~new_n53_;
  assign new_n82_ = ~new_n80_ & ~new_n81_;
  assign new_n83_ = ~new_n76_ & new_n82_;
  assign DSTvalid = \CPIPE2s<7>  & ~new_n83_;
  assign new_n85_ = ~\CPIPE2s<1>  & \CPIPE2s<3> ;
  assign new_n86_ = ~\CPIPE2s<5>  & ~new_n85_;
  assign new_n87_ = \CPIPE2s<2>  & ~new_n86_;
  assign new_n88_ = \CPIPE2s<5>  & ~new_n67_;
  assign new_n89_ = ~\CPIPE2s<0>  & new_n24_;
  assign new_n90_ = ~new_n88_ & ~new_n89_;
  assign new_n91_ = ~new_n87_ & new_n90_;
  assign new_n92_ = \CPIPE2s<7>  & ~new_n91_;
  assign pbusDtoINA = \CPIPE2s<4>  & new_n92_;
  assign busDtobusA2 = busDtobusB2;
endmodule


