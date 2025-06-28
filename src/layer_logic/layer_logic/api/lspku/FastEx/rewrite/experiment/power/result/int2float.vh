// Benchmark "int2float" written by ABC on Thu Sep 14 22:41:44 2023

module int2float ( 
    \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] , \B[8] ,
    \B[9] , \B[10] ,
    \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2]   );
  input  \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] ,
    \B[8] , \B[9] , \B[10] ;
  output \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2] ;
  wire new_n19_, new_n20_, new_n21_, new_n22_, new_n23_, new_n24_, new_n25_,
    new_n27_, new_n28_, new_n29_, new_n30_, new_n31_, new_n32_, new_n33_,
    new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n41_,
    new_n42_, new_n43_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_,
    new_n86_, new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_,
    new_n93_, new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_,
    new_n100_, new_n101_, new_n102_, new_n103_, new_n104_, new_n105_,
    new_n106_, new_n107_, new_n108_, new_n109_, new_n110_, new_n111_,
    new_n112_, new_n113_, new_n114_, new_n116_, new_n117_, new_n118_,
    new_n119_, new_n120_, new_n121_, new_n122_, new_n123_, new_n124_,
    new_n125_, new_n126_, new_n127_, new_n128_, new_n129_, new_n130_,
    new_n131_, new_n132_, new_n133_, new_n134_, new_n135_, new_n137_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n142_, new_n143_,
    new_n144_, new_n145_, new_n146_, new_n147_, new_n148_, new_n149_,
    new_n150_, new_n151_, new_n152_, new_n153_, new_n154_, new_n155_,
    new_n156_, new_n157_, new_n158_, new_n159_, new_n160_, new_n161_,
    new_n163_, new_n165_, new_n166_, new_n168_, new_n169_, new_n170_,
    new_n171_, new_n172_, new_n173_, new_n174_, new_n175_, new_n176_,
    new_n177_, new_n178_, new_n179_, new_n180_, new_n181_, new_n182_,
    new_n183_, new_n185_, new_n186_, new_n187_, new_n188_, new_n189_,
    new_n190_, new_n191_, new_n192_, new_n193_, new_n195_, new_n196_;
  INV_X1     g000(.I(\B[10] ), .ZN(new_n19_));
  NAND2_X1   g001(.A1(\B[8] ), .A2(\B[9] ), .ZN(new_n20_));
  INV_X1     g002(.I(new_n20_), .ZN(new_n21_));
  INV_X1     g003(.I(\B[2] ), .ZN(new_n22_));
  NAND2_X1   g004(.A1(new_n22_), .A2(\B[3] ), .ZN(new_n23_));
  INV_X1     g005(.I(\B[3] ), .ZN(new_n24_));
  NAND2_X1   g006(.A1(new_n24_), .A2(\B[2] ), .ZN(new_n25_));
  NAND4_X1   g007(.A1(new_n21_), .A2(\B[6] ), .A3(\B[7] ), .A4(\B[10] ), .ZN(new_n27_));
  INV_X1     g008(.I(\B[6] ), .ZN(new_n28_));
  NOR2_X1    g009(.A1(new_n28_), .A2(\B[7] ), .ZN(new_n29_));
  NAND2_X1   g010(.A1(new_n20_), .A2(new_n19_), .ZN(new_n30_));
  AOI21_X1   g011(.A1(new_n23_), .A2(new_n25_), .B(new_n20_), .ZN(new_n31_));
  AOI22_X1   g012(.A1(new_n31_), .A2(new_n30_), .B1(\B[7] ), .B2(new_n21_), .ZN(new_n32_));
  NAND2_X1   g013(.A1(\B[6] ), .A2(\B[10] ), .ZN(new_n33_));
  OAI21_X1   g014(.A1(new_n32_), .A2(new_n33_), .B(new_n29_), .ZN(new_n34_));
  AOI21_X1   g015(.A1(new_n34_), .A2(new_n27_), .B(new_n19_), .ZN(new_n35_));
  INV_X1     g016(.I(\B[5] ), .ZN(new_n36_));
  INV_X1     g017(.I(\B[9] ), .ZN(new_n37_));
  INV_X1     g018(.I(\B[1] ), .ZN(new_n38_));
  NAND2_X1   g019(.A1(new_n38_), .A2(new_n22_), .ZN(new_n39_));
  NAND2_X1   g020(.A1(new_n24_), .A2(\B[4] ), .ZN(new_n41_));
  NAND3_X1   g021(.A1(\B[4] ), .A2(\B[7] ), .A3(\B[8] ), .ZN(new_n42_));
  XOR2_X1    g022(.A1(new_n41_), .A2(new_n42_), .Z(new_n43_));
  NAND3_X1   g023(.A1(new_n36_), .A2(new_n37_), .A3(\B[6] ), .ZN(new_n45_));
  NOR2_X1    g024(.A1(new_n36_), .A2(new_n28_), .ZN(new_n46_));
  NAND3_X1   g025(.A1(new_n36_), .A2(new_n37_), .A3(\B[6] ), .ZN(new_n47_));
  NAND4_X1   g026(.A1(new_n43_), .A2(new_n39_), .A3(new_n46_), .A4(new_n47_), .ZN(new_n48_));
  NAND2_X1   g027(.A1(new_n48_), .A2(new_n45_), .ZN(new_n49_));
  NOR2_X1    g028(.A1(new_n35_), .A2(new_n49_), .ZN(new_n50_));
  INV_X1     g029(.I(\B[4] ), .ZN(new_n51_));
  INV_X1     g030(.I(\B[7] ), .ZN(new_n52_));
  NAND2_X1   g031(.A1(new_n28_), .A2(new_n52_), .ZN(new_n53_));
  NAND2_X1   g032(.A1(\B[4] ), .A2(\B[8] ), .ZN(new_n54_));
  XOR2_X1    g033(.A1(new_n54_), .A2(\B[1] ), .Z(new_n55_));
  INV_X1     g034(.I(\B[0] ), .ZN(new_n56_));
  INV_X1     g035(.I(\B[8] ), .ZN(new_n57_));
  NAND2_X1   g036(.A1(new_n56_), .A2(new_n57_), .ZN(new_n58_));
  NAND2_X1   g037(.A1(new_n58_), .A2(\B[8] ), .ZN(new_n59_));
  OAI22_X1   g038(.A1(new_n55_), .A2(new_n59_), .B1(new_n51_), .B2(new_n53_), .ZN(new_n60_));
  XNOR2_X1   g039(.A1(\B[3] ), .A2(\B[4] ), .ZN(new_n61_));
  NAND4_X1   g040(.A1(\B[1] ), .A2(\B[2] ), .A3(\B[5] ), .A4(\B[7] ), .ZN(new_n62_));
  OAI22_X1   g041(.A1(new_n61_), .A2(new_n62_), .B1(new_n51_), .B2(new_n52_), .ZN(new_n63_));
  NAND4_X1   g042(.A1(new_n63_), .A2(\B[4] ), .A3(\B[5] ), .A4(\B[8] ), .ZN(new_n64_));
  NOR2_X1    g043(.A1(new_n57_), .A2(\B[4] ), .ZN(new_n65_));
  XOR2_X1    g044(.A1(\B[3] ), .A2(\B[4] ), .Z(new_n66_));
  INV_X1     g045(.I(new_n62_), .ZN(new_n67_));
  AOI22_X1   g046(.A1(new_n66_), .A2(new_n67_), .B1(\B[4] ), .B2(\B[7] ), .ZN(new_n68_));
  NAND2_X1   g047(.A1(\B[5] ), .A2(\B[8] ), .ZN(new_n69_));
  OAI21_X1   g048(.A1(new_n68_), .A2(new_n69_), .B(new_n65_), .ZN(new_n70_));
  AOI21_X1   g049(.A1(new_n64_), .A2(new_n70_), .B(new_n37_), .ZN(new_n71_));
  OAI21_X1   g050(.A1(new_n71_), .A2(\B[5] ), .B(new_n60_), .ZN(new_n72_));
  NOR2_X1    g051(.A1(new_n50_), .A2(new_n72_), .ZN(\M[0] ));
  NOR2_X1    g052(.A1(new_n28_), .A2(new_n52_), .ZN(new_n74_));
  NAND3_X1   g053(.A1(new_n74_), .A2(new_n21_), .A3(\B[10] ), .ZN(new_n75_));
  NAND2_X1   g054(.A1(new_n51_), .A2(\B[9] ), .ZN(new_n76_));
  NAND3_X1   g055(.A1(\B[7] ), .A2(\B[8] ), .A3(\B[9] ), .ZN(new_n77_));
  XOR2_X1    g056(.A1(new_n76_), .A2(new_n77_), .Z(new_n78_));
  NAND2_X1   g057(.A1(new_n78_), .A2(\B[3] ), .ZN(new_n79_));
  NOR4_X1    g058(.A1(new_n53_), .A2(new_n51_), .A3(new_n57_), .A4(new_n37_), .ZN(new_n80_));
  NOR4_X1    g059(.A1(new_n51_), .A2(new_n37_), .A3(\B[6] ), .A4(\B[7] ), .ZN(new_n81_));
  NOR3_X1    g060(.A1(new_n81_), .A2(new_n51_), .A3(\B[8] ), .ZN(new_n82_));
  NOR2_X1    g061(.A1(\B[1] ), .A2(\B[2] ), .ZN(new_n83_));
  NAND4_X1   g062(.A1(\B[4] ), .A2(\B[7] ), .A3(\B[8] ), .A4(\B[9] ), .ZN(new_n84_));
  AOI21_X1   g063(.A1(new_n84_), .A2(new_n83_), .B(new_n28_), .ZN(new_n85_));
  OAI21_X1   g064(.A1(new_n82_), .A2(new_n80_), .B(new_n85_), .ZN(new_n86_));
  NAND2_X1   g065(.A1(new_n79_), .A2(new_n86_), .ZN(new_n87_));
  NAND2_X1   g066(.A1(new_n78_), .A2(\B[5] ), .ZN(new_n88_));
  NAND2_X1   g067(.A1(\B[3] ), .A2(\B[4] ), .ZN(new_n89_));
  NAND2_X1   g068(.A1(new_n89_), .A2(\B[7] ), .ZN(new_n90_));
  INV_X1     g069(.I(new_n89_), .ZN(new_n91_));
  NAND2_X1   g070(.A1(new_n91_), .A2(new_n52_), .ZN(new_n92_));
  OAI21_X1   g071(.A1(new_n20_), .A2(\B[7] ), .B(\B[6] ), .ZN(new_n93_));
  AOI21_X1   g072(.A1(new_n92_), .A2(new_n90_), .B(new_n93_), .ZN(new_n94_));
  AOI22_X1   g073(.A1(\B[2] ), .A2(\B[9] ), .B1(\B[4] ), .B2(\B[7] ), .ZN(new_n95_));
  OAI22_X1   g074(.A1(new_n95_), .A2(new_n57_), .B1(new_n38_), .B2(new_n37_), .ZN(new_n96_));
  NOR2_X1    g075(.A1(new_n51_), .A2(\B[7] ), .ZN(new_n97_));
  NAND2_X1   g076(.A1(new_n97_), .A2(new_n22_), .ZN(new_n98_));
  OAI21_X1   g077(.A1(new_n51_), .A2(\B[7] ), .B(\B[2] ), .ZN(new_n99_));
  NOR2_X1    g078(.A1(\B[0] ), .A2(\B[2] ), .ZN(new_n100_));
  OAI21_X1   g079(.A1(new_n100_), .A2(new_n38_), .B(\B[6] ), .ZN(new_n101_));
  AOI21_X1   g080(.A1(new_n98_), .A2(new_n99_), .B(new_n101_), .ZN(new_n102_));
  OAI21_X1   g081(.A1(new_n94_), .A2(new_n96_), .B(new_n102_), .ZN(new_n103_));
  AOI21_X1   g082(.A1(new_n103_), .A2(new_n88_), .B(new_n19_), .ZN(new_n104_));
  OAI21_X1   g083(.A1(new_n104_), .A2(\B[5] ), .B(new_n87_), .ZN(new_n105_));
  NOR2_X1    g084(.A1(new_n36_), .A2(\B[6] ), .ZN(new_n106_));
  NOR3_X1    g085(.A1(new_n28_), .A2(\B[4] ), .A3(\B[9] ), .ZN(new_n107_));
  AOI21_X1   g086(.A1(new_n107_), .A2(\B[3] ), .B(new_n106_), .ZN(new_n108_));
  AOI21_X1   g087(.A1(new_n107_), .A2(\B[2] ), .B(new_n106_), .ZN(new_n109_));
  NAND2_X1   g088(.A1(\B[2] ), .A2(\B[3] ), .ZN(new_n110_));
  NOR3_X1    g089(.A1(new_n110_), .A2(new_n38_), .A3(new_n37_), .ZN(new_n111_));
  NAND4_X1   g090(.A1(new_n111_), .A2(\B[6] ), .A3(new_n91_), .A4(\B[10] ), .ZN(new_n112_));
  NOR3_X1    g091(.A1(new_n112_), .A2(new_n108_), .A3(new_n109_), .ZN(new_n113_));
  OAI21_X1   g092(.A1(new_n113_), .A2(new_n74_), .B(\B[8] ), .ZN(new_n114_));
  AOI21_X1   g093(.A1(new_n105_), .A2(new_n75_), .B(new_n114_), .ZN(\M[1] ));
  AND2_X2    g094(.A1(\B[2] ), .A2(\B[6] ), .Z(new_n116_));
  OR2_X2     g095(.A1(\B[3] ), .A2(\B[6] ), .Z(new_n117_));
  NAND3_X1   g096(.A1(new_n117_), .A2(new_n116_), .A3(\B[7] ), .ZN(new_n118_));
  NAND3_X1   g097(.A1(\B[2] ), .A2(\B[6] ), .A3(\B[7] ), .ZN(new_n119_));
  NOR3_X1    g098(.A1(new_n52_), .A2(\B[3] ), .A3(\B[6] ), .ZN(new_n120_));
  NAND2_X1   g099(.A1(\B[4] ), .A2(\B[5] ), .ZN(new_n121_));
  AOI21_X1   g100(.A1(new_n120_), .A2(new_n119_), .B(new_n121_), .ZN(new_n122_));
  NAND4_X1   g101(.A1(\B[4] ), .A2(\B[5] ), .A3(\B[6] ), .A4(\B[7] ), .ZN(new_n123_));
  AOI21_X1   g102(.A1(new_n122_), .A2(new_n118_), .B(new_n123_), .ZN(new_n124_));
  NOR2_X1    g103(.A1(new_n120_), .A2(new_n119_), .ZN(new_n125_));
  NOR3_X1    g104(.A1(new_n117_), .A2(new_n116_), .A3(new_n52_), .ZN(new_n126_));
  NOR4_X1    g105(.A1(new_n126_), .A2(new_n125_), .A3(new_n74_), .A4(new_n121_), .ZN(new_n127_));
  OAI21_X1   g106(.A1(new_n127_), .A2(new_n124_), .B(\B[9] ), .ZN(new_n128_));
  NAND2_X1   g107(.A1(new_n128_), .A2(new_n57_), .ZN(new_n129_));
  NAND2_X1   g108(.A1(\B[0] ), .A2(\B[1] ), .ZN(new_n130_));
  INV_X1     g109(.I(new_n130_), .ZN(new_n131_));
  AOI21_X1   g110(.A1(new_n24_), .A2(new_n51_), .B(new_n36_), .ZN(new_n132_));
  NAND2_X1   g111(.A1(new_n132_), .A2(new_n131_), .ZN(new_n133_));
  NAND2_X1   g112(.A1(\B[2] ), .A2(\B[4] ), .ZN(new_n134_));
  AOI21_X1   g113(.A1(new_n133_), .A2(new_n28_), .B(new_n134_), .ZN(new_n135_));
  OAI21_X1   g114(.A1(\B[3] ), .A2(\B[5] ), .B(\B[4] ), .ZN(new_n137_));
  INV_X1     g115(.I(new_n137_), .ZN(new_n138_));
  OAI21_X1   g116(.A1(new_n135_), .A2(\B[1] ), .B(new_n138_), .ZN(new_n139_));
  NOR2_X1    g117(.A1(new_n46_), .A2(new_n91_), .ZN(new_n140_));
  NAND2_X1   g118(.A1(\B[1] ), .A2(\B[5] ), .ZN(new_n141_));
  NAND4_X1   g119(.A1(new_n141_), .A2(new_n22_), .A3(new_n36_), .A4(\B[6] ), .ZN(new_n142_));
  AND2_X2    g120(.A1(\B[1] ), .A2(\B[5] ), .Z(new_n143_));
  NAND2_X1   g121(.A1(new_n22_), .A2(new_n36_), .ZN(new_n144_));
  NAND3_X1   g122(.A1(new_n144_), .A2(new_n143_), .A3(\B[6] ), .ZN(new_n145_));
  AOI21_X1   g123(.A1(new_n145_), .A2(new_n142_), .B(new_n89_), .ZN(new_n146_));
  OAI21_X1   g124(.A1(new_n146_), .A2(new_n140_), .B(\B[7] ), .ZN(new_n147_));
  NAND2_X1   g125(.A1(new_n139_), .A2(new_n147_), .ZN(new_n148_));
  INV_X1     g126(.I(new_n23_), .ZN(new_n149_));
  NAND2_X1   g127(.A1(new_n46_), .A2(\B[3] ), .ZN(new_n150_));
  OAI21_X1   g128(.A1(new_n150_), .A2(new_n149_), .B(\B[4] ), .ZN(new_n151_));
  AOI21_X1   g129(.A1(new_n149_), .A2(new_n150_), .B(new_n151_), .ZN(new_n152_));
  NAND3_X1   g130(.A1(new_n129_), .A2(new_n148_), .A3(new_n152_), .ZN(new_n153_));
  AOI21_X1   g131(.A1(\B[8] ), .A2(\B[10] ), .B(\B[5] ), .ZN(new_n154_));
  NOR3_X1    g132(.A1(new_n154_), .A2(new_n28_), .A3(new_n52_), .ZN(new_n155_));
  NOR4_X1    g133(.A1(new_n36_), .A2(new_n57_), .A3(new_n37_), .A4(new_n19_), .ZN(new_n156_));
  OAI21_X1   g134(.A1(new_n155_), .A2(new_n156_), .B(\B[10] ), .ZN(new_n157_));
  NAND2_X1   g135(.A1(\B[5] ), .A2(\B[7] ), .ZN(new_n158_));
  NOR2_X1    g136(.A1(new_n158_), .A2(\B[6] ), .ZN(new_n159_));
  XNOR2_X1   g137(.A1(\B[4] ), .A2(\B[6] ), .ZN(new_n160_));
  OAI21_X1   g138(.A1(new_n160_), .A2(new_n159_), .B(\B[8] ), .ZN(new_n161_));
  AOI21_X1   g139(.A1(new_n153_), .A2(new_n157_), .B(new_n161_), .ZN(\M[2] ));
  INV_X1     g140(.I(new_n74_), .ZN(new_n163_));
  NOR2_X1    g141(.A1(\B[4] ), .A2(\B[8] ), .ZN(new_n165_));
  NAND3_X1   g142(.A1(\B[5] ), .A2(\B[9] ), .A3(\B[10] ), .ZN(new_n166_));
  NOR4_X1    g143(.A1(new_n163_), .A2(new_n23_), .A3(new_n165_), .A4(new_n166_), .ZN(\M[3] ));
  NOR3_X1    g144(.A1(new_n163_), .A2(new_n121_), .A3(new_n37_), .ZN(new_n168_));
  NAND3_X1   g145(.A1(new_n168_), .A2(\B[2] ), .A3(\B[3] ), .ZN(new_n169_));
  NAND3_X1   g146(.A1(new_n168_), .A2(new_n22_), .A3(new_n24_), .ZN(new_n170_));
  AOI21_X1   g147(.A1(new_n169_), .A2(new_n170_), .B(new_n20_), .ZN(new_n171_));
  NOR3_X1    g148(.A1(new_n36_), .A2(new_n28_), .A3(new_n19_), .ZN(new_n172_));
  OAI21_X1   g149(.A1(new_n171_), .A2(\B[7] ), .B(new_n172_), .ZN(new_n173_));
  NAND2_X1   g150(.A1(\B[1] ), .A2(\B[2] ), .ZN(new_n174_));
  OAI21_X1   g151(.A1(new_n51_), .A2(new_n37_), .B(new_n28_), .ZN(new_n175_));
  AOI22_X1   g152(.A1(new_n175_), .A2(\B[7] ), .B1(new_n106_), .B2(new_n174_), .ZN(new_n176_));
  NAND3_X1   g153(.A1(new_n46_), .A2(\B[3] ), .A3(\B[7] ), .ZN(new_n177_));
  OAI21_X1   g154(.A1(new_n176_), .A2(new_n177_), .B(new_n52_), .ZN(new_n178_));
  NAND3_X1   g155(.A1(new_n97_), .A2(\B[5] ), .A3(\B[6] ), .ZN(new_n179_));
  NAND2_X1   g156(.A1(new_n46_), .A2(new_n97_), .ZN(new_n180_));
  NAND4_X1   g157(.A1(new_n180_), .A2(new_n36_), .A3(\B[6] ), .A4(new_n130_), .ZN(new_n181_));
  NAND4_X1   g158(.A1(new_n181_), .A2(\B[2] ), .A3(\B[3] ), .A4(new_n179_), .ZN(new_n182_));
  NAND3_X1   g159(.A1(new_n182_), .A2(new_n106_), .A3(new_n178_), .ZN(new_n183_));
  AOI21_X1   g160(.A1(new_n173_), .A2(new_n57_), .B(new_n183_), .ZN(\E[0] ));
  NOR4_X1    g161(.A1(new_n24_), .A2(\B[5] ), .A3(\B[7] ), .A4(\B[8] ), .ZN(new_n185_));
  NOR4_X1    g162(.A1(new_n158_), .A2(new_n22_), .A3(new_n28_), .A4(new_n57_), .ZN(new_n186_));
  OAI21_X1   g163(.A1(new_n186_), .A2(new_n185_), .B(new_n131_), .ZN(new_n187_));
  XOR2_X1    g164(.A1(new_n110_), .A2(new_n28_), .Z(new_n188_));
  NAND3_X1   g165(.A1(new_n28_), .A2(\B[4] ), .A3(\B[5] ), .ZN(new_n189_));
  NOR2_X1    g166(.A1(\B[9] ), .A2(\B[10] ), .ZN(new_n190_));
  NOR4_X1    g167(.A1(new_n190_), .A2(new_n51_), .A3(\B[7] ), .A4(\B[8] ), .ZN(new_n191_));
  NAND3_X1   g168(.A1(new_n188_), .A2(new_n189_), .A3(new_n191_), .ZN(new_n192_));
  NAND4_X1   g169(.A1(new_n46_), .A2(\B[3] ), .A3(\B[7] ), .A4(\B[8] ), .ZN(new_n193_));
  AOI21_X1   g170(.A1(new_n192_), .A2(new_n187_), .B(new_n193_), .ZN(\E[1] ));
  NAND3_X1   g171(.A1(new_n190_), .A2(new_n52_), .A3(new_n57_), .ZN(new_n195_));
  NOR2_X1    g172(.A1(new_n46_), .A2(\B[2] ), .ZN(new_n196_));
  AOI21_X1   g173(.A1(new_n196_), .A2(new_n195_), .B(new_n89_), .ZN(\E[2] ));
endmodule


