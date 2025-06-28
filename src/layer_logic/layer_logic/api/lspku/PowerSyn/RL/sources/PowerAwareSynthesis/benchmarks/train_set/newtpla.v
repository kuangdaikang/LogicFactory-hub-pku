// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:04 2022

module newtpla  ( 
    tagcompare, \tCPIPE1s<0> , \tCPIPE1s<1> , \tCPIPE1s<2> , \tCPIPE1s<3> ,
    \tCPIPE1s<4> , \tCPIPE1s<5> , \tCPIPE1s<7> , \tbusA<31> , \tbusB<31> ,
    \tbusB<30> , \tbusB<29> , \tbusB<28> , \tCPIPE1s<6> , \tCPIPE1s<8> ,
    GStrap, trapinstr, TAGtrap, pov_unflow, skipCONDenable  );
  input  tagcompare, \tCPIPE1s<0> , \tCPIPE1s<1> , \tCPIPE1s<2> ,
    \tCPIPE1s<3> , \tCPIPE1s<4> , \tCPIPE1s<5> , \tCPIPE1s<7> ,
    \tbusA<31> , \tbusB<31> , \tbusB<30> , \tbusB<29> , \tbusB<28> ,
    \tCPIPE1s<6> , \tCPIPE1s<8> ;
  output GStrap, trapinstr, TAGtrap, pov_unflow, skipCONDenable;
  wire new_n21_, new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_,
    new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n41_, new_n42_, new_n43_,
    new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_, new_n50_,
    new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n71_, new_n72_,
    new_n73_, new_n74_, new_n75_, new_n76_, new_n78_, new_n79_, new_n80_,
    new_n81_, new_n82_;
  assign new_n21_ = ~\tbusB<31>  & ~\tbusB<30> ;
  assign new_n22_ = ~\tbusB<29>  & ~\tbusB<28> ;
  assign new_n23_ = new_n21_ & new_n22_;
  assign new_n24_ = tagcompare & ~new_n23_;
  assign new_n25_ = \tCPIPE1s<4>  & ~new_n24_;
  assign new_n26_ = ~\tCPIPE1s<2>  & new_n25_;
  assign new_n27_ = ~\tCPIPE1s<1>  & new_n26_;
  assign new_n28_ = ~\tCPIPE1s<0>  & new_n27_;
  assign new_n29_ = ~\tCPIPE1s<4>  & \tbusA<31> ;
  assign new_n30_ = ~new_n28_ & ~new_n29_;
  assign new_n31_ = \tCPIPE1s<6>  & ~new_n30_;
  assign new_n32_ = \tCPIPE1s<7>  & new_n31_;
  assign new_n33_ = ~\tCPIPE1s<5>  & new_n32_;
  assign GStrap = \tCPIPE1s<3>  & new_n33_;
  assign new_n35_ = ~\tCPIPE1s<1>  & ~\tCPIPE1s<2> ;
  assign new_n36_ = ~\tCPIPE1s<0>  & new_n35_;
  assign new_n37_ = \tCPIPE1s<7>  & ~new_n36_;
  assign new_n38_ = ~\tCPIPE1s<5>  & new_n37_;
  assign new_n39_ = \tCPIPE1s<4>  & new_n38_;
  assign trapinstr = ~\tCPIPE1s<3>  & new_n39_;
  assign new_n41_ = ~\tbusB<31>  & ~\tCPIPE1s<8> ;
  assign new_n42_ = ~\tbusA<31>  & ~new_n41_;
  assign new_n43_ = \tCPIPE1s<2>  & \tCPIPE1s<3> ;
  assign new_n44_ = ~\tCPIPE1s<0>  & ~new_n43_;
  assign new_n45_ = \tCPIPE1s<2>  & ~\tCPIPE1s<3> ;
  assign new_n46_ = \tCPIPE1s<1>  & new_n45_;
  assign new_n47_ = ~\tCPIPE1s<2>  & \tCPIPE1s<3> ;
  assign new_n48_ = ~\tCPIPE1s<1>  & new_n47_;
  assign new_n49_ = ~new_n46_ & ~new_n48_;
  assign new_n50_ = ~new_n44_ & new_n49_;
  assign new_n51_ = \tCPIPE1s<5>  & ~new_n50_;
  assign new_n52_ = ~\tCPIPE1s<4>  & new_n51_;
  assign new_n53_ = \tCPIPE1s<4>  & ~\tCPIPE1s<5> ;
  assign new_n54_ = ~\tCPIPE1s<3>  & new_n53_;
  assign new_n55_ = ~new_n52_ & ~new_n54_;
  assign new_n56_ = ~new_n42_ & ~new_n55_;
  assign new_n57_ = \tCPIPE1s<3>  & new_n42_;
  assign new_n58_ = \tbusA<31>  & new_n41_;
  assign new_n59_ = ~new_n57_ & ~new_n58_;
  assign new_n60_ = \tCPIPE1s<2>  & ~new_n59_;
  assign new_n61_ = ~\tCPIPE1s<0>  & ~\tCPIPE1s<2> ;
  assign new_n62_ = \tCPIPE1s<3>  & ~\tbusA<31> ;
  assign new_n63_ = new_n61_ & new_n62_;
  assign new_n64_ = ~new_n60_ & ~new_n63_;
  assign new_n65_ = ~\tCPIPE1s<5>  & ~new_n64_;
  assign new_n66_ = \tCPIPE1s<4>  & new_n65_;
  assign new_n67_ = ~\tCPIPE1s<1>  & new_n66_;
  assign new_n68_ = ~new_n56_ & ~new_n67_;
  assign new_n69_ = \tCPIPE1s<6>  & ~new_n68_;
  assign TAGtrap = \tCPIPE1s<7>  & new_n69_;
  assign new_n71_ = \tCPIPE1s<0>  & \tCPIPE1s<1> ;
  assign new_n72_ = \tCPIPE1s<6>  & ~new_n71_;
  assign new_n73_ = \tCPIPE1s<7>  & new_n72_;
  assign new_n74_ = \tCPIPE1s<5>  & new_n73_;
  assign new_n75_ = ~\tCPIPE1s<4>  & new_n74_;
  assign new_n76_ = \tCPIPE1s<3>  & new_n75_;
  assign pov_unflow = ~\tCPIPE1s<2>  & new_n76_;
  assign new_n78_ = ~\tCPIPE1s<0>  & ~\tCPIPE1s<1> ;
  assign new_n79_ = ~\tCPIPE1s<2>  & new_n78_;
  assign new_n80_ = ~\tCPIPE1s<3>  & new_n79_;
  assign new_n81_ = \tCPIPE1s<4>  & new_n80_;
  assign new_n82_ = ~\tCPIPE1s<5>  & new_n81_;
  assign skipCONDenable = \tCPIPE1s<7>  & new_n82_;
endmodule


