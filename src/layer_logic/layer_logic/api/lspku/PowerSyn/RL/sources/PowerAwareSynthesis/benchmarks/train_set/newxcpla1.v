// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:56 2022

module newxcpla1  ( 
    \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> , \CPIPE1s<4> ,
    \CPIPE1s<5> , \CPIPE1s<7> , \CPIPE1s<8> , RESET,
    selaluSUM, aluCINbar1, aluselSR, selaluAND, selaluOR, selaluXOR,
    selBIbar, storeSXT, pbusLtoINB, RD_WR, predecodeEA, pSTOREwrite,
    pLOADLtobusL, pSXTtobusL, byteEX, \.p , 43, \--------1 ,
    00000000000000000010000, \---0--11- , 00000000100001000000000,
    \---1111-- , 10000000000010010000000  );
  input  \CPIPE1s<0> , \CPIPE1s<1> , \CPIPE1s<2> , \CPIPE1s<3> ,
    \CPIPE1s<4> , \CPIPE1s<5> , \CPIPE1s<7> , \CPIPE1s<8> , RESET;
  output selaluSUM, aluCINbar1, aluselSR, selaluAND, selaluOR, selaluXOR,
    selBIbar, storeSXT, pbusLtoINB, RD_WR, predecodeEA, pSTOREwrite,
    pLOADLtobusL, pSXTtobusL, byteEX, \.p , 43, \--------1 ,
    00000000000000000010000, \---0--11- , 00000000100001000000000,
    \---1111-- , 10000000000010010000000;
  wire new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_,
    new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_,
    new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_,
    new_n63_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n70_, new_n72_, new_n73_, new_n74_, new_n75_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n81_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n95_,
    new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n104_, new_n105_, new_n106_, new_n108_, new_n111_,
    new_n112_, new_n113_, new_n114_, new_n115_, new_n116_, new_n117_,
    new_n118_, new_n119_, new_n120_, new_n122_, new_n123_, new_n124_,
    new_n125_, new_n126_, new_n128_, new_n129_, new_n130_, new_n131_,
    new_n133_, new_n134_, new_n135_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n141_, new_n142_, new_n143_, new_n144_, new_n145_,
    new_n146_, new_n147_, new_n150_, new_n151_, new_n152_, new_n153_,
    new_n154_, new_n155_, new_n156_, new_n157_, new_n158_, new_n159_,
    new_n160_, new_n161_, new_n162_, new_n163_, new_n164_, new_n165_,
    new_n166_, new_n167_, new_n168_, new_n169_, new_n170_, new_n171_,
    new_n172_, new_n174_, new_n175_, new_n176_, new_n177_, new_n178_,
    new_n179_, new_n181_, new_n182_, new_n184_, new_n185_, new_n186_,
    new_n187_, new_n188_, new_n189_, new_n190_, new_n191_, new_n192_,
    new_n193_, new_n195_, new_n196_, new_n197_, new_n198_;
  assign new_n34_ = ~\CPIPE1s<2>  & ~\CPIPE1s<3> ;
  assign new_n35_ = ~\CPIPE1s<3>  & ~new_n34_;
  assign new_n36_ = \CPIPE1s<7>  & ~new_n35_;
  assign new_n37_ = \CPIPE1s<0>  & new_n36_;
  assign new_n38_ = \CPIPE1s<3>  & \CPIPE1s<5> ;
  assign new_n39_ = ~\CPIPE1s<2>  & new_n38_;
  assign new_n40_ = ~new_n37_ & ~new_n39_;
  assign new_n41_ = ~\CPIPE1s<4>  & ~new_n40_;
  assign new_n42_ = \CPIPE1s<0>  & ~\CPIPE1s<1> ;
  assign new_n43_ = ~\CPIPE1s<3>  & \CPIPE1s<4> ;
  assign new_n44_ = ~new_n42_ & ~new_n43_;
  assign new_n45_ = \CPIPE1s<5>  & \CPIPE1s<7> ;
  assign new_n46_ = new_n44_ & new_n45_;
  assign selaluSUM = new_n41_ | ~new_n46_;
  assign new_n48_ = ~\CPIPE1s<4>  & \CPIPE1s<5> ;
  assign new_n49_ = ~\CPIPE1s<1>  & \CPIPE1s<3> ;
  assign new_n50_ = \CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n51_ = new_n49_ & new_n50_;
  assign new_n52_ = ~new_n48_ & ~new_n51_;
  assign new_n53_ = \CPIPE1s<2>  & ~new_n52_;
  assign new_n54_ = \CPIPE1s<3>  & new_n50_;
  assign new_n55_ = ~\CPIPE1s<5>  & ~new_n54_;
  assign new_n56_ = ~\CPIPE1s<1>  & ~new_n55_;
  assign new_n57_ = ~\CPIPE1s<3>  & new_n48_;
  assign new_n58_ = ~new_n56_ & ~new_n57_;
  assign new_n59_ = ~\CPIPE1s<0>  & ~new_n58_;
  assign new_n60_ = ~\CPIPE1s<3>  & ~\CPIPE1s<4> ;
  assign new_n61_ = \CPIPE1s<0>  & new_n60_;
  assign new_n62_ = ~new_n59_ & ~new_n61_;
  assign new_n63_ = ~\CPIPE1s<2>  & ~new_n62_;
  assign new_n64_ = \CPIPE1s<4>  & \CPIPE1s<5> ;
  assign new_n65_ = \CPIPE1s<3>  & ~new_n64_;
  assign new_n66_ = \CPIPE1s<0>  & new_n65_;
  assign new_n67_ = ~\CPIPE1s<4>  & ~\CPIPE1s<5> ;
  assign new_n68_ = ~new_n66_ & ~new_n67_;
  assign new_n69_ = ~new_n63_ & new_n68_;
  assign new_n70_ = ~new_n53_ & new_n69_;
  assign aluCINbar1 = \CPIPE1s<7>  & ~new_n70_;
  assign new_n72_ = ~\CPIPE1s<0>  & ~\CPIPE1s<2> ;
  assign new_n73_ = ~\CPIPE1s<3>  & new_n72_;
  assign new_n74_ = ~\CPIPE1s<4>  & new_n73_;
  assign new_n75_ = \CPIPE1s<5>  & new_n74_;
  assign aluselSR = \CPIPE1s<7>  & new_n75_;
  assign new_n77_ = ~\CPIPE1s<0>  & \CPIPE1s<1> ;
  assign new_n78_ = \CPIPE1s<2>  & new_n77_;
  assign new_n79_ = ~\CPIPE1s<3>  & new_n78_;
  assign new_n80_ = ~\CPIPE1s<4>  & new_n79_;
  assign new_n81_ = \CPIPE1s<5>  & new_n80_;
  assign selaluAND = \CPIPE1s<7>  & new_n81_;
  assign new_n83_ = \CPIPE1s<0>  & \CPIPE1s<1> ;
  assign new_n84_ = \CPIPE1s<2>  & new_n83_;
  assign new_n85_ = ~\CPIPE1s<3>  & new_n84_;
  assign new_n86_ = ~\CPIPE1s<4>  & new_n85_;
  assign new_n87_ = \CPIPE1s<5>  & new_n86_;
  assign selaluOR = \CPIPE1s<7>  & new_n87_;
  assign new_n89_ = ~\CPIPE1s<0>  & ~\CPIPE1s<1> ;
  assign new_n90_ = \CPIPE1s<2>  & new_n89_;
  assign new_n91_ = ~\CPIPE1s<3>  & new_n90_;
  assign new_n92_ = ~\CPIPE1s<4>  & new_n91_;
  assign new_n93_ = \CPIPE1s<5>  & new_n92_;
  assign selaluXOR = \CPIPE1s<7>  & new_n93_;
  assign new_n95_ = ~\CPIPE1s<4>  & ~new_n39_;
  assign new_n96_ = \CPIPE1s<1>  & ~new_n95_;
  assign new_n97_ = ~\CPIPE1s<0>  & new_n96_;
  assign new_n98_ = \CPIPE1s<5>  & ~new_n72_;
  assign new_n99_ = ~\CPIPE1s<3>  & ~\CPIPE1s<5> ;
  assign new_n100_ = ~new_n98_ & ~new_n99_;
  assign new_n101_ = \CPIPE1s<4>  & ~new_n100_;
  assign new_n102_ = ~new_n97_ & ~new_n101_;
  assign selBIbar = \CPIPE1s<7>  & ~new_n102_;
  assign new_n104_ = \CPIPE1s<3>  & new_n72_;
  assign new_n105_ = \CPIPE1s<4>  & new_n104_;
  assign new_n106_ = ~\CPIPE1s<5>  & new_n105_;
  assign storeSXT = \CPIPE1s<7>  & new_n106_;
  assign new_n108_ = \CPIPE1s<8>  & ~new_n64_;
  assign pSXTtobusL = \CPIPE1s<7>  & new_n108_;
  assign pbusLtoINB = ~\CPIPE1s<7>  | pSXTtobusL;
  assign new_n111_ = ~\CPIPE1s<0>  & \CPIPE1s<5> ;
  assign new_n112_ = ~\CPIPE1s<0>  & ~new_n111_;
  assign new_n113_ = \CPIPE1s<7>  & ~new_n112_;
  assign new_n114_ = ~\CPIPE1s<3>  & new_n113_;
  assign new_n115_ = ~new_n38_ & ~new_n114_;
  assign new_n116_ = ~\CPIPE1s<2>  & ~new_n115_;
  assign new_n117_ = \CPIPE1s<2>  & new_n45_;
  assign new_n118_ = ~new_n116_ & ~new_n117_;
  assign new_n119_ = ~\CPIPE1s<4>  & ~new_n118_;
  assign new_n120_ = ~new_n43_ & new_n45_;
  assign RD_WR = new_n119_ | ~new_n120_;
  assign new_n122_ = ~\CPIPE1s<2>  & ~new_n72_;
  assign new_n123_ = \CPIPE1s<7>  & ~new_n122_;
  assign new_n124_ = ~\CPIPE1s<5>  & new_n123_;
  assign new_n125_ = \CPIPE1s<4>  & new_n124_;
  assign new_n126_ = \CPIPE1s<3>  & new_n125_;
  assign predecodeEA = ~\CPIPE1s<1>  & new_n126_;
  assign new_n128_ = ~\CPIPE1s<2>  & new_n89_;
  assign new_n129_ = \CPIPE1s<3>  & new_n128_;
  assign new_n130_ = \CPIPE1s<4>  & new_n129_;
  assign new_n131_ = \CPIPE1s<5>  & new_n130_;
  assign pSTOREwrite = \CPIPE1s<7>  & new_n131_;
  assign new_n133_ = \CPIPE1s<3>  & new_n90_;
  assign new_n134_ = ~\CPIPE1s<4>  & new_n133_;
  assign new_n135_ = \CPIPE1s<5>  & new_n134_;
  assign byteEX = \CPIPE1s<7>  & new_n135_;
  assign new_n137_ = \CPIPE1s<2>  & \CPIPE1s<5> ;
  assign new_n138_ = \CPIPE1s<1>  & new_n137_;
  assign new_n139_ = \CPIPE1s<2>  & ~new_n138_;
  assign new_n140_ = \CPIPE1s<0>  & ~new_n139_;
  assign new_n141_ = ~new_n111_ & ~new_n140_;
  assign new_n142_ = ~\CPIPE1s<3>  & ~new_n141_;
  assign new_n143_ = \CPIPE1s<0>  & \CPIPE1s<3> ;
  assign new_n144_ = ~new_n142_ & ~new_n143_;
  assign new_n145_ = \CPIPE1s<7>  & ~new_n144_;
  assign new_n146_ = ~new_n39_ & ~new_n145_;
  assign new_n147_ = ~\CPIPE1s<4>  & ~new_n146_;
  assign \.p  = ~new_n46_ | new_n147_;
  assign 43 = ~new_n45_ | new_n119_;
  assign new_n150_ = ~\CPIPE1s<1>  & \CPIPE1s<2> ;
  assign new_n151_ = \CPIPE1s<0>  & ~new_n150_;
  assign new_n152_ = ~\CPIPE1s<3>  & \CPIPE1s<7> ;
  assign new_n153_ = ~new_n151_ & ~new_n152_;
  assign new_n154_ = \CPIPE1s<4>  & ~new_n153_;
  assign new_n155_ = ~\CPIPE1s<3>  & ~new_n42_;
  assign new_n156_ = ~new_n154_ & ~new_n155_;
  assign new_n157_ = ~\CPIPE1s<5>  & ~new_n156_;
  assign new_n158_ = \CPIPE1s<1>  & ~new_n60_;
  assign new_n159_ = \CPIPE1s<7>  & ~new_n158_;
  assign new_n160_ = ~\CPIPE1s<0>  & new_n159_;
  assign new_n161_ = \CPIPE1s<3>  & ~\CPIPE1s<4> ;
  assign new_n162_ = ~new_n160_ & ~new_n161_;
  assign new_n163_ = \CPIPE1s<5>  & ~new_n162_;
  assign new_n164_ = \CPIPE1s<0>  & ~\CPIPE1s<3> ;
  assign new_n165_ = ~\CPIPE1s<4>  & \CPIPE1s<7> ;
  assign new_n166_ = new_n164_ & new_n165_;
  assign new_n167_ = ~new_n163_ & ~new_n166_;
  assign new_n168_ = ~\CPIPE1s<2>  & ~new_n167_;
  assign new_n169_ = \CPIPE1s<2>  & ~\CPIPE1s<4> ;
  assign new_n170_ = new_n45_ & new_n169_;
  assign new_n171_ = \CPIPE1s<7>  & ~new_n170_;
  assign new_n172_ = ~new_n168_ & new_n171_;
  assign 00000000000000000010000 = new_n157_ | ~new_n172_;
  assign new_n174_ = \CPIPE1s<1>  & ~\CPIPE1s<2> ;
  assign new_n175_ = ~\CPIPE1s<0>  & new_n174_;
  assign new_n176_ = ~new_n98_ & ~new_n175_;
  assign new_n177_ = ~RESET & ~new_n176_;
  assign new_n178_ = \CPIPE1s<7>  & new_n177_;
  assign new_n179_ = \CPIPE1s<4>  & new_n178_;
  assign \---0--11-  = \CPIPE1s<3>  & new_n179_;
  assign new_n181_ = ~\CPIPE1s<5>  & new_n130_;
  assign new_n182_ = \CPIPE1s<7>  & new_n181_;
  assign 00000000100001000000000 = ~RESET & new_n182_;
  assign new_n184_ = ~\CPIPE1s<3>  & \CPIPE1s<5> ;
  assign new_n185_ = ~\CPIPE1s<0>  & \CPIPE1s<2> ;
  assign new_n186_ = \CPIPE1s<3>  & ~\CPIPE1s<5> ;
  assign new_n187_ = new_n185_ & new_n186_;
  assign new_n188_ = ~new_n184_ & ~new_n187_;
  assign new_n189_ = \CPIPE1s<1>  & ~new_n188_;
  assign new_n190_ = ~\CPIPE1s<3>  & new_n98_;
  assign new_n191_ = ~new_n189_ & ~new_n190_;
  assign new_n192_ = ~RESET & ~new_n191_;
  assign new_n193_ = \CPIPE1s<7>  & new_n192_;
  assign \---1111--  = \CPIPE1s<4>  & new_n193_;
  assign new_n195_ = \CPIPE1s<3>  & new_n150_;
  assign new_n196_ = \CPIPE1s<4>  & new_n195_;
  assign new_n197_ = ~\CPIPE1s<5>  & new_n196_;
  assign new_n198_ = \CPIPE1s<7>  & new_n197_;
  assign 10000000000010010000000 = ~RESET & new_n198_;
  assign pLOADLtobusL = 1'b0;
  assign \--------1  = 43;
endmodule


