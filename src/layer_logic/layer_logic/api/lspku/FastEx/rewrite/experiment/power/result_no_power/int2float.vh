// Benchmark "int2float" written by ABC on Mon Sep 11 23:42:08 2023

module int2float ( 
    \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] , \B[8] ,
    \B[9] , \B[10] ,
    \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2]   );
  input  \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] ,
    \B[8] , \B[9] , \B[10] ;
  output \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2] ;
  wire new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_, new_n25_,
    new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n31_, new_n32_,
    new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_,
    new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_,
    new_n69_, new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_,
    new_n77_, new_n78_, new_n79_, new_n80_, new_n81_, new_n82_, new_n83_,
    new_n84_, new_n85_, new_n86_, new_n87_, new_n88_, new_n89_, new_n90_,
    new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n97_, new_n98_,
    new_n99_, new_n100_, new_n101_, new_n102_, new_n103_, new_n104_,
    new_n105_, new_n106_, new_n107_, new_n108_, new_n109_, new_n110_,
    new_n111_, new_n112_, new_n113_, new_n114_, new_n115_, new_n116_,
    new_n117_, new_n118_, new_n119_, new_n120_, new_n121_, new_n122_,
    new_n123_, new_n124_, new_n125_, new_n126_, new_n127_, new_n128_,
    new_n129_, new_n130_, new_n132_, new_n133_, new_n134_, new_n135_,
    new_n137_, new_n138_, new_n139_, new_n140_, new_n141_, new_n142_,
    new_n143_, new_n144_, new_n145_, new_n146_, new_n147_, new_n148_,
    new_n149_, new_n151_, new_n152_, new_n153_, new_n154_, new_n155_,
    new_n157_, new_n158_, new_n159_, new_n160_, new_n161_, new_n162_,
    new_n163_, new_n164_, new_n165_, new_n166_, new_n168_;
  INV_X1     g000(.I(\B[10] ), .ZN(new_n19_));
  AOI21_X1   g001(.A1(\B[7] ), .A2(\B[10] ), .B(\B[6] ), .ZN(new_n20_));
  NOR2_X1    g002(.A1(\B[8] ), .A2(\B[9] ), .ZN(new_n21_));
  XOR2_X1    g003(.A1(\B[2] ), .A2(\B[3] ), .Z(new_n22_));
  AOI21_X1   g004(.A1(new_n22_), .A2(new_n21_), .B(\B[10] ), .ZN(new_n23_));
  NAND2_X1   g005(.A1(\B[8] ), .A2(\B[9] ), .ZN(new_n24_));
  OAI22_X1   g006(.A1(new_n23_), .A2(\B[7] ), .B1(new_n19_), .B2(new_n24_), .ZN(new_n25_));
  NAND3_X1   g007(.A1(new_n25_), .A2(\B[6] ), .A3(new_n20_), .ZN(new_n26_));
  INV_X1     g008(.I(new_n20_), .ZN(new_n27_));
  NAND2_X1   g009(.A1(new_n25_), .A2(\B[6] ), .ZN(new_n28_));
  NAND2_X1   g010(.A1(new_n28_), .A2(new_n27_), .ZN(new_n29_));
  INV_X1     g011(.I(\B[2] ), .ZN(new_n30_));
  INV_X1     g012(.I(\B[4] ), .ZN(new_n31_));
  INV_X1     g013(.I(\B[3] ), .ZN(new_n32_));
  INV_X1     g014(.I(\B[8] ), .ZN(new_n33_));
  NAND2_X1   g015(.A1(new_n32_), .A2(new_n33_), .ZN(new_n34_));
  OAI21_X1   g016(.A1(new_n34_), .A2(new_n31_), .B(\B[7] ), .ZN(new_n35_));
  INV_X1     g017(.I(\B[7] ), .ZN(new_n36_));
  NAND3_X1   g018(.A1(new_n34_), .A2(\B[4] ), .A3(new_n36_), .ZN(new_n37_));
  NAND3_X1   g019(.A1(new_n35_), .A2(new_n37_), .A3(new_n30_), .ZN(new_n38_));
  INV_X1     g020(.I(\B[5] ), .ZN(new_n39_));
  INV_X1     g021(.I(\B[6] ), .ZN(new_n40_));
  NOR3_X1    g022(.A1(new_n39_), .A2(new_n40_), .A3(\B[9] ), .ZN(new_n41_));
  NOR4_X1    g023(.A1(new_n30_), .A2(\B[1] ), .A3(\B[7] ), .A4(\B[8] ), .ZN(new_n42_));
  INV_X1     g024(.I(\B[1] ), .ZN(new_n43_));
  NAND2_X1   g025(.A1(new_n43_), .A2(\B[5] ), .ZN(new_n44_));
  NOR4_X1    g026(.A1(new_n42_), .A2(new_n41_), .A3(\B[9] ), .A4(new_n44_), .ZN(new_n45_));
  NAND2_X1   g027(.A1(new_n38_), .A2(new_n45_), .ZN(new_n46_));
  AOI22_X1   g028(.A1(new_n29_), .A2(new_n26_), .B1(new_n19_), .B2(new_n46_), .ZN(\M[0] ));
  INV_X1     g029(.I(\B[9] ), .ZN(new_n48_));
  NAND2_X1   g030(.A1(new_n31_), .A2(new_n48_), .ZN(new_n49_));
  NAND2_X1   g031(.A1(new_n30_), .A2(new_n36_), .ZN(new_n50_));
  AOI21_X1   g032(.A1(new_n49_), .A2(new_n50_), .B(\B[1] ), .ZN(new_n51_));
  NAND2_X1   g033(.A1(new_n48_), .A2(\B[8] ), .ZN(new_n52_));
  NOR2_X1    g034(.A1(new_n31_), .A2(\B[7] ), .ZN(new_n53_));
  NAND2_X1   g035(.A1(new_n43_), .A2(\B[0] ), .ZN(new_n54_));
  NOR2_X1    g036(.A1(new_n53_), .A2(new_n54_), .ZN(new_n55_));
  XNOR2_X1   g037(.A1(\B[0] ), .A2(\B[2] ), .ZN(new_n56_));
  OAI21_X1   g038(.A1(new_n55_), .A2(new_n56_), .B(new_n52_), .ZN(new_n57_));
  OAI21_X1   g039(.A1(new_n57_), .A2(new_n51_), .B(new_n40_), .ZN(new_n58_));
  NAND2_X1   g040(.A1(\B[3] ), .A2(\B[4] ), .ZN(new_n59_));
  NAND2_X1   g041(.A1(new_n36_), .A2(new_n48_), .ZN(new_n60_));
  AOI21_X1   g042(.A1(new_n33_), .A2(new_n59_), .B(new_n60_), .ZN(new_n61_));
  AOI21_X1   g043(.A1(new_n58_), .A2(new_n61_), .B(\B[5] ), .ZN(new_n62_));
  NAND2_X1   g044(.A1(new_n36_), .A2(\B[9] ), .ZN(new_n63_));
  NOR2_X1    g045(.A1(new_n49_), .A2(new_n33_), .ZN(new_n64_));
  OAI21_X1   g046(.A1(new_n64_), .A2(new_n63_), .B(new_n40_), .ZN(new_n65_));
  AOI21_X1   g047(.A1(new_n63_), .A2(new_n64_), .B(new_n65_), .ZN(new_n66_));
  OAI21_X1   g048(.A1(\B[6] ), .A2(\B[7] ), .B(new_n31_), .ZN(new_n67_));
  OAI21_X1   g049(.A1(\B[8] ), .A2(\B[9] ), .B(\B[4] ), .ZN(new_n68_));
  NOR2_X1    g050(.A1(\B[6] ), .A2(\B[7] ), .ZN(new_n69_));
  NAND2_X1   g051(.A1(\B[1] ), .A2(\B[2] ), .ZN(new_n70_));
  AOI21_X1   g052(.A1(new_n67_), .A2(new_n68_), .B(new_n70_), .ZN(new_n71_));
  NOR4_X1    g053(.A1(new_n31_), .A2(new_n36_), .A3(\B[8] ), .A4(\B[9] ), .ZN(new_n72_));
  NOR3_X1    g054(.A1(new_n71_), .A2(new_n32_), .A3(new_n72_), .ZN(new_n73_));
  NOR2_X1    g055(.A1(new_n36_), .A2(new_n48_), .ZN(new_n74_));
  NOR4_X1    g056(.A1(new_n74_), .A2(new_n31_), .A3(new_n33_), .A4(\B[9] ), .ZN(new_n75_));
  OAI21_X1   g057(.A1(new_n36_), .A2(new_n48_), .B(\B[6] ), .ZN(new_n77_));
  OAI21_X1   g058(.A1(new_n75_), .A2(new_n77_), .B(\B[5] ), .ZN(new_n78_));
  NOR2_X1    g059(.A1(new_n73_), .A2(new_n78_), .ZN(new_n79_));
  OAI21_X1   g060(.A1(new_n62_), .A2(new_n66_), .B(new_n79_), .ZN(new_n80_));
  NOR2_X1    g061(.A1(new_n40_), .A2(new_n36_), .ZN(new_n81_));
  NOR2_X1    g062(.A1(new_n52_), .A2(new_n19_), .ZN(new_n82_));
  AOI21_X1   g063(.A1(new_n82_), .A2(new_n81_), .B(\B[10] ), .ZN(new_n83_));
  NOR2_X1    g064(.A1(new_n19_), .A2(\B[6] ), .ZN(new_n84_));
  NAND3_X1   g065(.A1(new_n31_), .A2(new_n48_), .A3(\B[6] ), .ZN(new_n85_));
  NOR2_X1    g066(.A1(new_n39_), .A2(\B[6] ), .ZN(new_n86_));
  NAND2_X1   g067(.A1(new_n86_), .A2(new_n32_), .ZN(new_n87_));
  AOI21_X1   g068(.A1(new_n87_), .A2(new_n85_), .B(\B[2] ), .ZN(new_n88_));
  NAND2_X1   g069(.A1(new_n86_), .A2(new_n43_), .ZN(new_n89_));
  AOI21_X1   g070(.A1(new_n89_), .A2(new_n85_), .B(\B[3] ), .ZN(new_n90_));
  NAND2_X1   g071(.A1(\B[2] ), .A2(\B[3] ), .ZN(new_n91_));
  NOR4_X1    g072(.A1(new_n91_), .A2(new_n31_), .A3(new_n40_), .A4(\B[9] ), .ZN(new_n92_));
  NAND2_X1   g073(.A1(new_n36_), .A2(new_n19_), .ZN(new_n93_));
  NOR4_X1    g074(.A1(new_n88_), .A2(new_n90_), .A3(new_n92_), .A4(new_n93_), .ZN(new_n94_));
  OAI21_X1   g075(.A1(new_n94_), .A2(new_n84_), .B(new_n33_), .ZN(new_n95_));
  AOI21_X1   g076(.A1(new_n80_), .A2(new_n83_), .B(new_n95_), .ZN(\M[1] ));
  NOR3_X1    g077(.A1(new_n40_), .A2(new_n36_), .A3(\B[3] ), .ZN(new_n97_));
  NOR3_X1    g078(.A1(new_n97_), .A2(new_n30_), .A3(new_n40_), .ZN(new_n98_));
  NAND2_X1   g079(.A1(new_n39_), .A2(\B[4] ), .ZN(new_n99_));
  MUX2_X1    g080(.I0(new_n98_), .I1(new_n81_), .S(new_n99_), .Z(new_n100_));
  OAI21_X1   g081(.A1(\B[2] ), .A2(\B[6] ), .B(\B[3] ), .ZN(new_n101_));
  OAI21_X1   g082(.A1(\B[3] ), .A2(\B[5] ), .B(new_n101_), .ZN(new_n102_));
  OR3_X2     g083(.A1(new_n101_), .A2(\B[3] ), .A3(\B[5] ), .Z(new_n103_));
  NAND3_X1   g084(.A1(new_n103_), .A2(\B[4] ), .A3(new_n102_), .ZN(new_n104_));
  NOR3_X1    g085(.A1(new_n32_), .A2(new_n39_), .A3(\B[4] ), .ZN(new_n105_));
  INV_X1     g086(.I(\B[0] ), .ZN(new_n106_));
  NOR4_X1    g087(.A1(new_n106_), .A2(new_n31_), .A3(\B[3] ), .A4(\B[6] ), .ZN(new_n107_));
  NOR3_X1    g088(.A1(new_n107_), .A2(new_n105_), .A3(new_n43_), .ZN(new_n108_));
  AOI21_X1   g089(.A1(\B[0] ), .A2(\B[1] ), .B(new_n59_), .ZN(new_n109_));
  NOR2_X1    g090(.A1(\B[4] ), .A2(\B[6] ), .ZN(new_n110_));
  OAI21_X1   g091(.A1(new_n109_), .A2(new_n110_), .B(new_n39_), .ZN(new_n111_));
  OAI21_X1   g092(.A1(new_n111_), .A2(new_n108_), .B(\B[2] ), .ZN(new_n112_));
  NOR3_X1    g093(.A1(new_n39_), .A2(new_n40_), .A3(\B[2] ), .ZN(new_n113_));
  NAND4_X1   g094(.A1(\B[1] ), .A2(\B[3] ), .A3(\B[4] ), .A4(\B[5] ), .ZN(new_n114_));
  NAND2_X1   g095(.A1(\B[5] ), .A2(\B[6] ), .ZN(new_n115_));
  AOI21_X1   g096(.A1(new_n59_), .A2(new_n115_), .B(\B[7] ), .ZN(new_n116_));
  OAI21_X1   g097(.A1(new_n113_), .A2(new_n114_), .B(new_n116_), .ZN(new_n117_));
  AOI21_X1   g098(.A1(new_n112_), .A2(new_n104_), .B(new_n117_), .ZN(new_n118_));
  OAI21_X1   g099(.A1(new_n118_), .A2(\B[8] ), .B(new_n100_), .ZN(new_n119_));
  XOR2_X1    g100(.A1(\B[6] ), .A2(\B[7] ), .Z(new_n120_));
  OAI21_X1   g101(.A1(new_n31_), .A2(new_n39_), .B(new_n36_), .ZN(new_n121_));
  NAND2_X1   g102(.A1(new_n120_), .A2(new_n121_), .ZN(new_n122_));
  AOI21_X1   g103(.A1(new_n122_), .A2(\B[8] ), .B(\B[9] ), .ZN(new_n123_));
  NOR3_X1    g104(.A1(new_n39_), .A2(new_n48_), .A3(\B[8] ), .ZN(new_n124_));
  NOR3_X1    g105(.A1(new_n39_), .A2(new_n48_), .A3(\B[8] ), .ZN(new_n125_));
  NAND2_X1   g106(.A1(\B[8] ), .A2(\B[10] ), .ZN(new_n126_));
  OAI21_X1   g107(.A1(new_n125_), .A2(new_n126_), .B(new_n81_), .ZN(new_n127_));
  NAND3_X1   g108(.A1(new_n33_), .A2(\B[5] ), .A3(\B[7] ), .ZN(new_n128_));
  AOI21_X1   g109(.A1(new_n128_), .A2(\B[9] ), .B(\B[10] ), .ZN(new_n129_));
  OAI21_X1   g110(.A1(new_n127_), .A2(new_n124_), .B(new_n129_), .ZN(new_n130_));
  AOI21_X1   g111(.A1(new_n119_), .A2(new_n123_), .B(new_n130_), .ZN(\M[2] ));
  NOR2_X1    g112(.A1(new_n31_), .A2(\B[2] ), .ZN(new_n132_));
  NAND4_X1   g113(.A1(new_n81_), .A2(new_n132_), .A3(\B[5] ), .A4(\B[8] ), .ZN(new_n133_));
  NAND4_X1   g114(.A1(new_n69_), .A2(new_n31_), .A3(new_n39_), .A4(new_n33_), .ZN(new_n134_));
  NOR2_X1    g115(.A1(\B[3] ), .A2(\B[9] ), .ZN(new_n135_));
  NAND4_X1   g116(.A1(new_n133_), .A2(new_n19_), .A3(new_n134_), .A4(new_n135_), .ZN(\M[3] ));
  AOI21_X1   g117(.A1(\B[2] ), .A2(new_n33_), .B(new_n32_), .ZN(new_n137_));
  INV_X1     g118(.I(new_n81_), .ZN(new_n138_));
  NOR4_X1    g119(.A1(new_n138_), .A2(new_n31_), .A3(new_n39_), .A4(\B[9] ), .ZN(new_n139_));
  NAND3_X1   g120(.A1(\B[5] ), .A2(\B[6] ), .A3(\B[7] ), .ZN(new_n140_));
  INV_X1     g121(.I(new_n140_), .ZN(new_n141_));
  AOI22_X1   g122(.A1(new_n139_), .A2(new_n137_), .B1(new_n141_), .B2(new_n48_), .ZN(new_n142_));
  INV_X1     g123(.I(new_n86_), .ZN(new_n143_));
  NAND2_X1   g124(.A1(\B[0] ), .A2(\B[1] ), .ZN(new_n144_));
  AOI21_X1   g125(.A1(new_n144_), .A2(new_n40_), .B(\B[5] ), .ZN(new_n145_));
  OAI21_X1   g126(.A1(new_n143_), .A2(new_n53_), .B(new_n145_), .ZN(new_n146_));
  OR3_X2     g127(.A1(new_n143_), .A2(new_n53_), .A3(new_n145_), .Z(new_n147_));
  NAND4_X1   g128(.A1(new_n147_), .A2(\B[2] ), .A3(\B[3] ), .A4(new_n146_), .ZN(new_n148_));
  OAI21_X1   g129(.A1(new_n40_), .A2(\B[7] ), .B(new_n31_), .ZN(new_n149_));
  NAND3_X1   g130(.A1(new_n36_), .A2(\B[5] ), .A3(\B[6] ), .ZN(new_n151_));
  AOI21_X1   g131(.A1(new_n149_), .A2(new_n48_), .B(new_n151_), .ZN(new_n152_));
  OAI21_X1   g132(.A1(new_n86_), .A2(\B[7] ), .B(new_n32_), .ZN(new_n153_));
  NOR2_X1    g133(.A1(new_n152_), .A2(new_n153_), .ZN(new_n154_));
  AOI21_X1   g134(.A1(new_n148_), .A2(new_n154_), .B(\B[8] ), .ZN(new_n155_));
  OAI21_X1   g135(.A1(new_n155_), .A2(new_n142_), .B(new_n19_), .ZN(\E[0] ));
  NOR4_X1    g136(.A1(new_n138_), .A2(new_n32_), .A3(new_n39_), .A4(new_n33_), .ZN(new_n157_));
  NOR2_X1    g137(.A1(\B[7] ), .A2(\B[8] ), .ZN(new_n158_));
  NAND3_X1   g138(.A1(new_n158_), .A2(\B[3] ), .A3(new_n39_), .ZN(new_n159_));
  OAI22_X1   g139(.A1(new_n159_), .A2(new_n144_), .B1(new_n33_), .B2(new_n140_), .ZN(new_n160_));
  AOI21_X1   g140(.A1(new_n160_), .A2(\B[2] ), .B(new_n157_), .ZN(new_n161_));
  NOR2_X1    g141(.A1(new_n40_), .A2(\B[5] ), .ZN(new_n162_));
  NOR3_X1    g142(.A1(new_n91_), .A2(new_n31_), .A3(\B[6] ), .ZN(new_n163_));
  NOR3_X1    g143(.A1(new_n163_), .A2(new_n162_), .A3(new_n86_), .ZN(new_n164_));
  NOR2_X1    g144(.A1(new_n164_), .A2(new_n158_), .ZN(new_n165_));
  NAND2_X1   g145(.A1(new_n48_), .A2(\B[4] ), .ZN(new_n166_));
  NOR4_X1    g146(.A1(new_n161_), .A2(\B[10] ), .A3(new_n165_), .A4(new_n166_), .ZN(\E[1] ));
  NOR4_X1    g147(.A1(\B[7] ), .A2(\B[8] ), .A3(\B[9] ), .A4(\B[10] ), .ZN(new_n168_));
  NOR4_X1    g148(.A1(new_n168_), .A2(new_n30_), .A3(new_n59_), .A4(new_n115_), .ZN(\E[2] ));
endmodule


