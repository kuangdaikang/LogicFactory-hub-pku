// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:32 2022

module newcpla1  ( 
    WAIT, \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> ,
    \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> , RESET,
    changeCWP2t, trap, lastPCload, pDATABUSintoLOADL, enableINTS1,
    changeCWP1, PCtoMAL1, pALUtoMAL, pPCIncr, pALUtoPC, DST2step1,
    PCstuffoncall1, SRC2smin1, DST1min1, CPIPE1flush, CPIPE1load1  );
  input  WAIT, \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> ,
    \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> , RESET;
  output changeCWP2t, trap, lastPCload, pDATABUSintoLOADL, enableINTS1,
    changeCWP1, PCtoMAL1, pALUtoMAL, pPCIncr, pALUtoPC, DST2step1,
    PCstuffoncall1, SRC2smin1, DST1min1, CPIPE1flush, CPIPE1load1;
  wire new_n26_, new_n27_, new_n28_, new_n29_, new_n31_, new_n32_, new_n33_,
    new_n34_, new_n35_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_,
    new_n78_, new_n80_, new_n81_, new_n82_, new_n84_, new_n86_, new_n87_,
    new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_,
    new_n95_, new_n96_, new_n97_, new_n98_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n125_, new_n126_,
    new_n128_, new_n129_, new_n130_, new_n131_, new_n133_, new_n135_,
    new_n136_, new_n137_, new_n138_, new_n139_, new_n140_, new_n141_,
    new_n143_, new_n144_, new_n145_, new_n146_, new_n147_, new_n149_,
    new_n150_, new_n151_, new_n152_, new_n153_, new_n154_, new_n156_,
    new_n157_;
  assign new_n26_ = ~WAIT & \CPIPE1s<0> ;
  assign new_n27_ = \CPIPE1s<3>  & new_n26_;
  assign new_n28_ = ~\CPIPE1s<4>  & new_n27_;
  assign new_n29_ = ~\CPIPE1s<5>  & new_n28_;
  assign changeCWP2t = \CPIPE1s<7>  & new_n29_;
  assign new_n31_ = \CPIPE1s<0>  & ~\CPIPE1s<1> ;
  assign new_n32_ = \CPIPE1s<2>  & new_n31_;
  assign new_n33_ = ~\CPIPE1s<3>  & new_n32_;
  assign new_n34_ = ~\CPIPE1s<4>  & new_n33_;
  assign new_n35_ = ~\CPIPE1s<5>  & new_n34_;
  assign trap = \CPIPE1s<7>  & new_n35_;
  assign new_n37_ = \CPIPE1s<2>  & ~\CPIPE1s<4> ;
  assign new_n38_ = ~\CPIPE1s<0>  & new_n37_;
  assign new_n39_ = \CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n40_ = ~new_n38_ & ~new_n39_;
  assign new_n41_ = ~\CPIPE1s<3>  & ~new_n40_;
  assign new_n42_ = ~\CPIPE1s<1>  & \CPIPE1s<3> ;
  assign new_n43_ = ~\CPIPE1s<1>  & ~new_n42_;
  assign new_n44_ = ~\CPIPE1s<5>  & ~new_n43_;
  assign new_n45_ = \CPIPE1s<2>  & new_n44_;
  assign new_n46_ = \CPIPE1s<2>  & ~new_n45_;
  assign new_n47_ = ~new_n41_ & new_n46_;
  assign new_n48_ = \CPIPE1s<7>  & ~new_n47_;
  assign new_n49_ = ~\CPIPE1s<5>  & ~\CPIPE1s<7> ;
  assign new_n50_ = ~\CPIPE1s<5>  & ~new_n49_;
  assign new_n51_ = ~new_n48_ & new_n50_;
  assign lastPCload = ~WAIT & ~new_n51_;
  assign new_n53_ = ~\CPIPE1s<3>  & \CPIPE1s<4> ;
  assign new_n54_ = \CPIPE1s<5>  & \CPIPE1s<7> ;
  assign new_n55_ = new_n53_ & new_n54_;
  assign new_n56_ = \CPIPE1s<5>  & ~new_n55_;
  assign new_n57_ = \CPIPE1s<0>  & ~new_n56_;
  assign new_n58_ = \CPIPE1s<4>  & \CPIPE1s<5> ;
  assign new_n59_ = ~\CPIPE1s<3>  & new_n58_;
  assign new_n60_ = \CPIPE1s<2>  & ~\CPIPE1s<5> ;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = \CPIPE1s<1>  & ~new_n61_;
  assign new_n63_ = ~\CPIPE1s<2>  & \CPIPE1s<5> ;
  assign new_n64_ = ~\CPIPE1s<0>  & new_n63_;
  assign new_n65_ = \CPIPE1s<3>  & ~\CPIPE1s<5> ;
  assign new_n66_ = \CPIPE1s<2>  & new_n65_;
  assign new_n67_ = ~new_n64_ & ~new_n66_;
  assign new_n68_ = ~\CPIPE1s<1>  & ~new_n67_;
  assign new_n69_ = \CPIPE1s<2>  & \CPIPE1s<5> ;
  assign new_n70_ = \CPIPE1s<5>  & ~new_n69_;
  assign new_n71_ = \CPIPE1s<4>  & ~new_n70_;
  assign new_n72_ = ~\CPIPE1s<3>  & new_n71_;
  assign new_n73_ = ~new_n68_ & ~new_n72_;
  assign new_n74_ = ~new_n62_ & new_n73_;
  assign new_n75_ = \CPIPE1s<7>  & ~new_n74_;
  assign new_n76_ = \CPIPE1s<4>  & \CPIPE1s<7> ;
  assign new_n77_ = ~new_n75_ & new_n76_;
  assign new_n78_ = ~new_n57_ & new_n77_;
  assign pDATABUSintoLOADL = ~WAIT & ~new_n78_;
  assign new_n80_ = \CPIPE1s<2>  & \CPIPE1s<3> ;
  assign new_n81_ = ~\CPIPE1s<4>  & new_n80_;
  assign new_n82_ = ~\CPIPE1s<5>  & new_n81_;
  assign enableINTS1 = \CPIPE1s<7>  & new_n82_;
  assign new_n84_ = ~WAIT & ~\CPIPE1s<5> ;
  assign changeCWP1 = ~\CPIPE1s<7>  & new_n84_;
  assign new_n86_ = ~\CPIPE1s<1>  & ~\CPIPE1s<2> ;
  assign new_n87_ = \CPIPE1s<4>  & ~new_n86_;
  assign new_n88_ = ~\CPIPE1s<0>  & ~new_n87_;
  assign new_n89_ = ~\CPIPE1s<2>  & \CPIPE1s<3> ;
  assign new_n90_ = ~\CPIPE1s<1>  & new_n89_;
  assign new_n91_ = \CPIPE1s<2>  & ~\CPIPE1s<3> ;
  assign new_n92_ = \CPIPE1s<1>  & new_n91_;
  assign new_n93_ = ~new_n90_ & ~new_n92_;
  assign new_n94_ = ~\CPIPE1s<4>  & ~new_n93_;
  assign new_n95_ = ~new_n88_ & ~new_n94_;
  assign new_n96_ = \CPIPE1s<5>  & ~new_n95_;
  assign new_n97_ = ~new_n41_ & ~new_n96_;
  assign new_n98_ = \CPIPE1s<7>  & ~new_n97_;
  assign PCtoMAL1 = ~WAIT & new_n98_;
  assign new_n100_ = \CPIPE1s<3>  & ~\CPIPE1s<4> ;
  assign new_n101_ = ~\CPIPE1s<5>  & \CPIPE1s<7> ;
  assign new_n102_ = new_n100_ & new_n101_;
  assign new_n103_ = ~new_n58_ & ~new_n102_;
  assign new_n104_ = \CPIPE1s<0>  & ~new_n103_;
  assign new_n105_ = \CPIPE1s<7>  & ~new_n86_;
  assign new_n106_ = \CPIPE1s<4>  & new_n105_;
  assign new_n107_ = \CPIPE1s<7>  & ~new_n106_;
  assign new_n108_ = \CPIPE1s<5>  & ~new_n107_;
  assign new_n109_ = \CPIPE1s<2>  & \CPIPE1s<7> ;
  assign new_n110_ = ~\CPIPE1s<1>  & new_n109_;
  assign new_n111_ = \CPIPE1s<0>  & ~new_n110_;
  assign new_n112_ = \CPIPE1s<3>  & ~new_n111_;
  assign new_n113_ = \CPIPE1s<7>  & ~new_n112_;
  assign new_n114_ = ~\CPIPE1s<5>  & ~new_n113_;
  assign new_n115_ = ~new_n108_ & ~new_n114_;
  assign new_n116_ = ~new_n104_ & new_n115_;
  assign pALUtoMAL = ~WAIT & ~new_n116_;
  assign new_n118_ = ~\CPIPE1s<0>  & ~\CPIPE1s<4> ;
  assign new_n119_ = ~\CPIPE1s<1>  & ~\CPIPE1s<5> ;
  assign new_n120_ = ~new_n118_ & ~new_n119_;
  assign new_n121_ = \CPIPE1s<2>  & ~new_n120_;
  assign new_n122_ = ~new_n39_ & ~new_n121_;
  assign new_n123_ = ~\CPIPE1s<3>  & ~new_n122_;
  assign new_n124_ = ~new_n96_ & ~new_n123_;
  assign new_n125_ = ~RESET & ~new_n124_;
  assign new_n126_ = \CPIPE1s<7>  & new_n125_;
  assign pPCIncr = ~WAIT & new_n126_;
  assign new_n128_ = ~\CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n129_ = \CPIPE1s<3>  & new_n128_;
  assign new_n130_ = \CPIPE1s<7>  & ~new_n129_;
  assign new_n131_ = ~RESET & ~new_n130_;
  assign pALUtoPC = ~WAIT & new_n131_;
  assign new_n133_ = ~\CPIPE1s<5>  & ~new_n48_;
  assign DST2step1 = ~WAIT & ~new_n133_;
  assign new_n135_ = ~\CPIPE1s<0>  & ~\CPIPE1s<2> ;
  assign new_n136_ = ~\CPIPE1s<5>  & ~new_n135_;
  assign new_n137_ = \CPIPE1s<1>  & ~new_n136_;
  assign new_n138_ = ~new_n69_ & ~new_n137_;
  assign new_n139_ = \CPIPE1s<7>  & ~new_n138_;
  assign new_n140_ = \CPIPE1s<4>  & new_n139_;
  assign new_n141_ = \CPIPE1s<3>  & new_n140_;
  assign SRC2smin1 = ~WAIT & new_n141_;
  assign new_n143_ = ~\CPIPE1s<0>  & new_n86_;
  assign new_n144_ = \CPIPE1s<7>  & ~new_n143_;
  assign new_n145_ = \CPIPE1s<5>  & new_n144_;
  assign new_n146_ = \CPIPE1s<4>  & new_n145_;
  assign new_n147_ = ~\CPIPE1s<3>  & new_n146_;
  assign DST1min1 = ~WAIT & new_n147_;
  assign new_n149_ = ~\CPIPE1s<1>  & \CPIPE1s<2> ;
  assign new_n150_ = \CPIPE1s<0>  & new_n149_;
  assign new_n151_ = ~\CPIPE1s<3>  & ~new_n150_;
  assign new_n152_ = ~RESET & ~new_n151_;
  assign new_n153_ = \CPIPE1s<7>  & new_n152_;
  assign new_n154_ = ~\CPIPE1s<5>  & new_n153_;
  assign CPIPE1flush = ~\CPIPE1s<4>  & new_n154_;
  assign new_n156_ = \CPIPE1s<4>  & new_n54_;
  assign new_n157_ = ~RESET & ~new_n156_;
  assign CPIPE1load1 = ~WAIT & new_n157_;
  assign PCstuffoncall1 = changeCWP1;
endmodule


