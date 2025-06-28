// Benchmark "router" written by ABC on Mon Sep 11 23:43:07 2023

module router ( 
    \dest_x[0] , \dest_x[1] , \dest_x[2] , \dest_x[3] , \dest_x[4] ,
    \dest_x[5] , \dest_x[6] , \dest_x[7] , \dest_x[8] , \dest_x[9] ,
    \dest_x[10] , \dest_x[11] , \dest_x[12] , \dest_x[13] , \dest_x[14] ,
    \dest_x[15] , \dest_x[16] , \dest_x[17] , \dest_x[18] , \dest_x[19] ,
    \dest_x[20] , \dest_x[21] , \dest_x[22] , \dest_x[23] , \dest_x[24] ,
    \dest_x[25] , \dest_x[26] , \dest_x[27] , \dest_x[28] , \dest_x[29] ,
    \dest_y[0] , \dest_y[1] , \dest_y[2] , \dest_y[3] , \dest_y[4] ,
    \dest_y[5] , \dest_y[6] , \dest_y[7] , \dest_y[8] , \dest_y[9] ,
    \dest_y[10] , \dest_y[11] , \dest_y[12] , \dest_y[13] , \dest_y[14] ,
    \dest_y[15] , \dest_y[16] , \dest_y[17] , \dest_y[18] , \dest_y[19] ,
    \dest_y[20] , \dest_y[21] , \dest_y[22] , \dest_y[23] , \dest_y[24] ,
    \dest_y[25] , \dest_y[26] , \dest_y[27] , \dest_y[28] , \dest_y[29] ,
    \outport[0] , \outport[1] , \outport[2] , \outport[3] , \outport[4] ,
    \outport[5] , \outport[6] , \outport[7] , \outport[8] , \outport[9] ,
    \outport[10] , \outport[11] , \outport[12] , \outport[13] ,
    \outport[14] , \outport[15] , \outport[16] , \outport[17] ,
    \outport[18] , \outport[19] , \outport[20] , \outport[21] ,
    \outport[22] , \outport[23] , \outport[24] , \outport[25] ,
    \outport[26] , \outport[27] , \outport[28] , \outport[29]   );
  input  \dest_x[0] , \dest_x[1] , \dest_x[2] , \dest_x[3] , \dest_x[4] ,
    \dest_x[5] , \dest_x[6] , \dest_x[7] , \dest_x[8] , \dest_x[9] ,
    \dest_x[10] , \dest_x[11] , \dest_x[12] , \dest_x[13] , \dest_x[14] ,
    \dest_x[15] , \dest_x[16] , \dest_x[17] , \dest_x[18] , \dest_x[19] ,
    \dest_x[20] , \dest_x[21] , \dest_x[22] , \dest_x[23] , \dest_x[24] ,
    \dest_x[25] , \dest_x[26] , \dest_x[27] , \dest_x[28] , \dest_x[29] ,
    \dest_y[0] , \dest_y[1] , \dest_y[2] , \dest_y[3] , \dest_y[4] ,
    \dest_y[5] , \dest_y[6] , \dest_y[7] , \dest_y[8] , \dest_y[9] ,
    \dest_y[10] , \dest_y[11] , \dest_y[12] , \dest_y[13] , \dest_y[14] ,
    \dest_y[15] , \dest_y[16] , \dest_y[17] , \dest_y[18] , \dest_y[19] ,
    \dest_y[20] , \dest_y[21] , \dest_y[22] , \dest_y[23] , \dest_y[24] ,
    \dest_y[25] , \dest_y[26] , \dest_y[27] , \dest_y[28] , \dest_y[29] ;
  output \outport[0] , \outport[1] , \outport[2] , \outport[3] , \outport[4] ,
    \outport[5] , \outport[6] , \outport[7] , \outport[8] , \outport[9] ,
    \outport[10] , \outport[11] , \outport[12] , \outport[13] ,
    \outport[14] , \outport[15] , \outport[16] , \outport[17] ,
    \outport[18] , \outport[19] , \outport[20] , \outport[21] ,
    \outport[22] , \outport[23] , \outport[24] , \outport[25] ,
    \outport[26] , \outport[27] , \outport[28] , \outport[29] ;
  wire new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_, new_n97_,
    new_n98_, new_n99_, new_n100_, new_n101_, new_n102_, new_n103_,
    new_n104_, new_n105_, new_n106_, new_n107_, new_n108_, new_n109_,
    new_n110_, new_n111_, new_n112_, new_n113_, new_n114_, new_n115_,
    new_n116_, new_n117_, new_n118_, new_n119_, new_n120_, new_n121_,
    new_n122_, new_n123_, new_n124_, new_n125_, new_n126_, new_n127_,
    new_n128_, new_n129_, new_n130_, new_n131_, new_n132_, new_n133_,
    new_n134_, new_n135_, new_n136_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n141_, new_n142_, new_n143_, new_n144_, new_n145_,
    new_n146_, new_n147_, new_n148_, new_n149_, new_n150_, new_n151_,
    new_n152_, new_n153_, new_n154_, new_n155_, new_n156_, new_n157_,
    new_n158_, new_n159_, new_n160_, new_n161_, new_n162_, new_n163_,
    new_n164_, new_n165_, new_n166_, new_n167_, new_n168_, new_n169_,
    new_n170_, new_n171_, new_n172_, new_n173_, new_n174_, new_n175_,
    new_n176_, new_n177_, new_n178_, new_n179_, new_n180_, new_n181_,
    new_n182_, new_n183_, new_n184_, new_n185_, new_n186_, new_n187_,
    new_n188_, new_n189_, new_n190_, new_n191_, new_n192_, new_n193_,
    new_n194_, new_n195_, new_n196_, new_n197_, new_n198_, new_n199_,
    new_n200_, new_n201_, new_n202_, new_n203_, new_n204_, new_n206_,
    new_n207_, new_n208_, new_n209_, new_n210_, new_n211_, new_n212_,
    new_n213_, new_n214_, new_n215_, new_n216_, new_n217_, new_n218_,
    new_n219_, new_n220_, new_n221_, new_n222_, new_n223_, new_n224_,
    new_n225_, new_n226_, new_n227_, new_n228_, new_n229_, new_n230_,
    new_n231_, new_n232_, new_n233_, new_n234_, new_n235_, new_n236_,
    new_n237_, new_n238_, new_n239_, new_n240_, new_n241_, new_n242_,
    new_n243_, new_n244_, new_n245_, new_n246_, new_n247_, new_n248_,
    new_n249_, new_n250_, new_n251_, new_n252_, new_n253_, new_n254_,
    new_n255_, new_n256_, new_n257_, new_n258_, new_n259_, new_n260_,
    new_n261_, new_n262_, new_n263_, new_n264_, new_n265_, new_n266_,
    new_n267_, new_n268_, new_n269_, new_n270_, new_n271_, new_n272_,
    new_n273_, new_n274_, new_n275_, new_n276_, new_n277_, new_n278_,
    new_n279_, new_n280_, new_n281_, new_n282_, new_n283_, new_n284_,
    new_n285_, new_n286_, new_n287_, new_n288_, new_n289_, new_n290_,
    new_n291_, new_n292_, new_n293_, new_n294_, new_n295_, new_n296_,
    new_n297_, new_n298_, new_n299_, new_n300_, new_n301_, new_n302_,
    new_n303_, new_n304_, new_n305_, new_n306_, new_n307_, new_n308_,
    new_n309_, new_n310_, new_n311_, new_n312_, new_n313_, new_n314_,
    new_n315_, new_n316_, new_n317_, new_n318_, new_n319_, new_n320_,
    new_n322_, new_n323_, new_n324_, new_n325_;
  INV_X1     g000(.I(\dest_x[27] ), .ZN(new_n91_));
  INV_X1     g001(.I(\dest_x[25] ), .ZN(new_n92_));
  INV_X1     g002(.I(\dest_x[26] ), .ZN(new_n93_));
  INV_X1     g003(.I(\dest_x[16] ), .ZN(new_n94_));
  INV_X1     g004(.I(\dest_x[12] ), .ZN(new_n95_));
  OAI21_X1   g005(.A1(\dest_x[9] ), .A2(\dest_x[10] ), .B(\dest_x[11] ), .ZN(new_n96_));
  AOI21_X1   g006(.A1(new_n96_), .A2(new_n95_), .B(\dest_x[13] ), .ZN(new_n97_));
  NAND2_X1   g007(.A1(\dest_x[14] ), .A2(\dest_x[15] ), .ZN(new_n98_));
  OAI21_X1   g008(.A1(new_n97_), .A2(new_n98_), .B(new_n94_), .ZN(new_n99_));
  AOI21_X1   g009(.A1(new_n99_), .A2(\dest_x[17] ), .B(\dest_x[18] ), .ZN(new_n100_));
  AND2_X2    g010(.A1(\dest_x[19] ), .A2(\dest_x[20] ), .Z(new_n101_));
  AOI21_X1   g011(.A1(new_n100_), .A2(new_n101_), .B(\dest_x[21] ), .ZN(new_n102_));
  AND2_X2    g012(.A1(\dest_x[23] ), .A2(\dest_x[24] ), .Z(new_n103_));
  OAI21_X1   g013(.A1(new_n102_), .A2(\dest_x[22] ), .B(new_n103_), .ZN(new_n104_));
  OAI21_X1   g014(.A1(new_n104_), .A2(new_n92_), .B(new_n93_), .ZN(new_n105_));
  XOR2_X1    g015(.A1(new_n105_), .A2(new_n91_), .Z(new_n106_));
  INV_X1     g016(.I(new_n106_), .ZN(new_n107_));
  NOR2_X1    g017(.A1(new_n104_), .A2(new_n92_), .ZN(new_n108_));
  NAND2_X1   g018(.A1(new_n93_), .A2(\dest_x[25] ), .ZN(new_n109_));
  OAI22_X1   g019(.A1(new_n108_), .A2(new_n93_), .B1(new_n104_), .B2(new_n109_), .ZN(new_n110_));
  XOR2_X1    g020(.A1(new_n104_), .A2(\dest_x[25] ), .Z(new_n111_));
  NAND2_X1   g021(.A1(new_n100_), .A2(new_n101_), .ZN(new_n112_));
  INV_X1     g022(.I(\dest_x[19] ), .ZN(new_n113_));
  INV_X1     g023(.I(\dest_x[17] ), .ZN(new_n114_));
  OR2_X2     g024(.A1(\dest_x[9] ), .A2(\dest_x[10] ), .Z(new_n115_));
  AOI21_X1   g025(.A1(new_n115_), .A2(\dest_x[11] ), .B(\dest_x[12] ), .ZN(new_n116_));
  INV_X1     g026(.I(new_n98_), .ZN(new_n117_));
  OAI21_X1   g027(.A1(new_n116_), .A2(\dest_x[13] ), .B(new_n117_), .ZN(new_n118_));
  AOI21_X1   g028(.A1(new_n118_), .A2(new_n94_), .B(new_n114_), .ZN(new_n119_));
  NOR3_X1    g029(.A1(new_n119_), .A2(\dest_x[18] ), .A3(new_n113_), .ZN(new_n120_));
  OAI21_X1   g030(.A1(new_n120_), .A2(\dest_x[20] ), .B(new_n112_), .ZN(new_n121_));
  XOR2_X1    g031(.A1(new_n100_), .A2(new_n113_), .Z(new_n122_));
  INV_X1     g032(.I(\dest_x[18] ), .ZN(new_n123_));
  NAND2_X1   g033(.A1(new_n99_), .A2(\dest_x[17] ), .ZN(new_n124_));
  XOR2_X1    g034(.A1(new_n124_), .A2(new_n123_), .Z(new_n125_));
  NOR2_X1    g035(.A1(new_n97_), .A2(new_n98_), .ZN(new_n126_));
  INV_X1     g036(.I(new_n99_), .ZN(new_n127_));
  NAND2_X1   g037(.A1(new_n94_), .A2(\dest_x[17] ), .ZN(new_n128_));
  OAI22_X1   g038(.A1(new_n127_), .A2(\dest_x[17] ), .B1(new_n126_), .B2(new_n128_), .ZN(new_n129_));
  NOR2_X1    g039(.A1(new_n126_), .A2(new_n94_), .ZN(new_n130_));
  NOR3_X1    g040(.A1(new_n97_), .A2(\dest_x[16] ), .A3(new_n98_), .ZN(new_n131_));
  NOR2_X1    g041(.A1(new_n130_), .A2(new_n131_), .ZN(new_n132_));
  INV_X1     g042(.I(\dest_x[13] ), .ZN(new_n133_));
  NAND3_X1   g043(.A1(new_n96_), .A2(new_n95_), .A3(new_n133_), .ZN(new_n134_));
  NAND2_X1   g044(.A1(new_n96_), .A2(new_n95_), .ZN(new_n135_));
  NAND2_X1   g045(.A1(new_n135_), .A2(\dest_x[13] ), .ZN(new_n136_));
  NAND2_X1   g046(.A1(new_n136_), .A2(new_n134_), .ZN(new_n137_));
  XOR2_X1    g047(.A1(new_n96_), .A2(new_n95_), .Z(new_n138_));
  XNOR2_X1   g048(.A1(new_n115_), .A2(\dest_x[11] ), .ZN(new_n139_));
  INV_X1     g049(.I(\dest_x[9] ), .ZN(new_n140_));
  NOR4_X1    g050(.A1(\dest_x[3] ), .A2(\dest_x[4] ), .A3(\dest_x[5] ), .A4(\dest_x[6] ), .ZN(new_n141_));
  INV_X1     g051(.I(\dest_x[1] ), .ZN(new_n142_));
  INV_X1     g052(.I(\dest_x[2] ), .ZN(new_n143_));
  INV_X1     g053(.I(\dest_x[7] ), .ZN(new_n144_));
  INV_X1     g054(.I(\dest_x[8] ), .ZN(new_n145_));
  NAND4_X1   g055(.A1(new_n142_), .A2(new_n143_), .A3(new_n144_), .A4(new_n145_), .ZN(new_n146_));
  NOR4_X1    g056(.A1(new_n146_), .A2(new_n140_), .A3(\dest_x[10] ), .A4(new_n141_), .ZN(new_n147_));
  NAND4_X1   g057(.A1(new_n139_), .A2(new_n137_), .A3(new_n138_), .A4(new_n147_), .ZN(new_n148_));
  INV_X1     g058(.I(\dest_x[14] ), .ZN(new_n149_));
  INV_X1     g059(.I(new_n97_), .ZN(new_n150_));
  NOR2_X1    g060(.A1(new_n149_), .A2(\dest_x[13] ), .ZN(new_n151_));
  AOI22_X1   g061(.A1(new_n150_), .A2(new_n149_), .B1(new_n135_), .B2(new_n151_), .ZN(new_n152_));
  INV_X1     g062(.I(\dest_x[15] ), .ZN(new_n153_));
  NOR2_X1    g063(.A1(new_n133_), .A2(\dest_x[14] ), .ZN(new_n154_));
  NAND4_X1   g064(.A1(new_n154_), .A2(new_n95_), .A3(new_n96_), .A4(new_n153_), .ZN(new_n155_));
  NAND2_X1   g065(.A1(new_n149_), .A2(\dest_x[13] ), .ZN(new_n156_));
  OAI21_X1   g066(.A1(new_n135_), .A2(new_n156_), .B(\dest_x[15] ), .ZN(new_n157_));
  NAND2_X1   g067(.A1(new_n157_), .A2(new_n155_), .ZN(new_n158_));
  NAND2_X1   g068(.A1(new_n152_), .A2(new_n158_), .ZN(new_n159_));
  NOR4_X1    g069(.A1(new_n129_), .A2(new_n148_), .A3(new_n159_), .A4(new_n132_), .ZN(new_n160_));
  NAND4_X1   g070(.A1(new_n121_), .A2(new_n122_), .A3(new_n160_), .A4(new_n125_), .ZN(new_n161_));
  INV_X1     g071(.I(\dest_x[22] ), .ZN(new_n162_));
  AND2_X2    g072(.A1(new_n102_), .A2(new_n162_), .Z(new_n163_));
  NOR2_X1    g073(.A1(new_n102_), .A2(new_n162_), .ZN(new_n164_));
  INV_X1     g074(.I(\dest_x[21] ), .ZN(new_n165_));
  NAND4_X1   g075(.A1(new_n100_), .A2(\dest_x[19] ), .A3(\dest_x[20] ), .A4(new_n165_), .ZN(new_n166_));
  NAND3_X1   g076(.A1(new_n100_), .A2(\dest_x[19] ), .A3(\dest_x[20] ), .ZN(new_n167_));
  NAND2_X1   g077(.A1(new_n167_), .A2(\dest_x[21] ), .ZN(new_n168_));
  NAND2_X1   g078(.A1(new_n168_), .A2(new_n166_), .ZN(new_n169_));
  OAI21_X1   g079(.A1(new_n163_), .A2(new_n164_), .B(new_n169_), .ZN(new_n170_));
  INV_X1     g080(.I(\dest_x[24] ), .ZN(new_n171_));
  NOR2_X1    g081(.A1(new_n162_), .A2(\dest_x[23] ), .ZN(new_n172_));
  AND3_X2    g082(.A1(new_n102_), .A2(new_n171_), .A3(new_n172_), .Z(new_n173_));
  AOI21_X1   g083(.A1(new_n102_), .A2(new_n172_), .B(new_n171_), .ZN(new_n174_));
  NOR2_X1    g084(.A1(new_n173_), .A2(new_n174_), .ZN(new_n175_));
  NOR2_X1    g085(.A1(new_n102_), .A2(\dest_x[22] ), .ZN(new_n176_));
  NAND2_X1   g086(.A1(new_n162_), .A2(\dest_x[23] ), .ZN(new_n177_));
  OAI22_X1   g087(.A1(new_n176_), .A2(\dest_x[23] ), .B1(new_n102_), .B2(new_n177_), .ZN(new_n178_));
  NOR4_X1    g088(.A1(new_n170_), .A2(new_n161_), .A3(new_n175_), .A4(new_n178_), .ZN(new_n179_));
  NAND3_X1   g089(.A1(new_n179_), .A2(new_n110_), .A3(new_n111_), .ZN(new_n180_));
  NAND3_X1   g090(.A1(new_n105_), .A2(\dest_x[27] ), .A3(\dest_x[28] ), .ZN(new_n181_));
  INV_X1     g091(.I(new_n181_), .ZN(new_n182_));
  NAND2_X1   g092(.A1(new_n182_), .A2(\dest_x[29] ), .ZN(new_n183_));
  INV_X1     g093(.I(new_n183_), .ZN(new_n184_));
  AOI21_X1   g094(.A1(new_n105_), .A2(\dest_x[27] ), .B(\dest_x[28] ), .ZN(new_n185_));
  NOR2_X1    g095(.A1(new_n182_), .A2(new_n185_), .ZN(new_n186_));
  NOR4_X1    g096(.A1(new_n184_), .A2(new_n180_), .A3(new_n107_), .A4(new_n186_), .ZN(new_n187_));
  NAND2_X1   g097(.A1(new_n140_), .A2(\dest_x[10] ), .ZN(new_n188_));
  INV_X1     g098(.I(\dest_x[0] ), .ZN(new_n189_));
  NOR2_X1    g099(.A1(new_n140_), .A2(\dest_x[10] ), .ZN(new_n190_));
  NOR3_X1    g100(.A1(new_n190_), .A2(new_n189_), .A3(new_n142_), .ZN(new_n191_));
  INV_X1     g101(.I(\dest_x[6] ), .ZN(new_n192_));
  NOR4_X1    g102(.A1(new_n192_), .A2(new_n144_), .A3(new_n145_), .A4(\dest_x[9] ), .ZN(new_n193_));
  AND4_X2    g103(.A1(\dest_x[2] ), .A2(\dest_x[3] ), .A3(\dest_x[4] ), .A4(\dest_x[5] ), .Z(new_n194_));
  NAND4_X1   g104(.A1(new_n191_), .A2(new_n188_), .A3(new_n193_), .A4(new_n194_), .ZN(new_n195_));
  NOR4_X1    g105(.A1(new_n139_), .A2(new_n137_), .A3(new_n195_), .A4(new_n138_), .ZN(new_n196_));
  NOR2_X1    g106(.A1(new_n152_), .A2(new_n158_), .ZN(new_n197_));
  NAND4_X1   g107(.A1(new_n129_), .A2(new_n196_), .A3(new_n197_), .A4(new_n132_), .ZN(new_n198_));
  NOR4_X1    g108(.A1(new_n121_), .A2(new_n122_), .A3(new_n198_), .A4(new_n125_), .ZN(new_n199_));
  NOR3_X1    g109(.A1(new_n169_), .A2(new_n163_), .A3(new_n164_), .ZN(new_n200_));
  NAND4_X1   g110(.A1(new_n200_), .A2(new_n199_), .A3(new_n175_), .A4(new_n178_), .ZN(new_n201_));
  NOR4_X1    g111(.A1(new_n106_), .A2(new_n110_), .A3(new_n111_), .A4(new_n201_), .ZN(new_n202_));
  NAND4_X1   g112(.A1(new_n202_), .A2(\dest_x[29] ), .A3(new_n181_), .A4(new_n186_), .ZN(new_n203_));
  NAND2_X1   g113(.A1(new_n182_), .A2(\dest_x[29] ), .ZN(new_n204_));
  AOI21_X1   g114(.A1(new_n203_), .A2(new_n204_), .B(new_n187_), .ZN(\outport[0] ));
  INV_X1     g115(.I(\dest_y[25] ), .ZN(new_n206_));
  INV_X1     g116(.I(\dest_y[26] ), .ZN(new_n207_));
  INV_X1     g117(.I(\dest_y[16] ), .ZN(new_n208_));
  INV_X1     g118(.I(\dest_y[12] ), .ZN(new_n209_));
  OAI21_X1   g119(.A1(\dest_y[9] ), .A2(\dest_y[10] ), .B(\dest_y[11] ), .ZN(new_n210_));
  AOI21_X1   g120(.A1(new_n210_), .A2(new_n209_), .B(\dest_y[13] ), .ZN(new_n211_));
  NAND2_X1   g121(.A1(\dest_y[14] ), .A2(\dest_y[15] ), .ZN(new_n212_));
  OAI21_X1   g122(.A1(new_n211_), .A2(new_n212_), .B(new_n208_), .ZN(new_n213_));
  AOI21_X1   g123(.A1(new_n213_), .A2(\dest_y[17] ), .B(\dest_y[18] ), .ZN(new_n214_));
  INV_X1     g124(.I(\dest_y[19] ), .ZN(new_n215_));
  INV_X1     g125(.I(\dest_y[20] ), .ZN(new_n216_));
  NOR2_X1    g126(.A1(new_n215_), .A2(new_n216_), .ZN(new_n217_));
  AOI21_X1   g127(.A1(new_n214_), .A2(new_n217_), .B(\dest_y[21] ), .ZN(new_n218_));
  INV_X1     g128(.I(\dest_y[23] ), .ZN(new_n219_));
  INV_X1     g129(.I(\dest_y[24] ), .ZN(new_n220_));
  NOR2_X1    g130(.A1(new_n219_), .A2(new_n220_), .ZN(new_n221_));
  OAI21_X1   g131(.A1(new_n218_), .A2(\dest_y[22] ), .B(new_n221_), .ZN(new_n222_));
  OAI21_X1   g132(.A1(new_n222_), .A2(new_n206_), .B(new_n207_), .ZN(new_n223_));
  XNOR2_X1   g133(.A1(new_n223_), .A2(\dest_y[27] ), .ZN(new_n224_));
  NOR2_X1    g134(.A1(new_n222_), .A2(new_n206_), .ZN(new_n225_));
  NOR2_X1    g135(.A1(new_n206_), .A2(\dest_y[26] ), .ZN(new_n226_));
  INV_X1     g136(.I(new_n226_), .ZN(new_n227_));
  OAI22_X1   g137(.A1(new_n225_), .A2(new_n207_), .B1(new_n222_), .B2(new_n227_), .ZN(new_n228_));
  INV_X1     g138(.I(new_n228_), .ZN(new_n229_));
  XOR2_X1    g139(.A1(new_n222_), .A2(new_n206_), .Z(new_n230_));
  NAND2_X1   g140(.A1(new_n214_), .A2(\dest_y[19] ), .ZN(new_n231_));
  AOI22_X1   g141(.A1(new_n231_), .A2(new_n216_), .B1(new_n214_), .B2(new_n217_), .ZN(new_n232_));
  INV_X1     g142(.I(new_n232_), .ZN(new_n233_));
  AND2_X2    g143(.A1(new_n214_), .A2(new_n215_), .Z(new_n234_));
  NOR2_X1    g144(.A1(new_n214_), .A2(new_n215_), .ZN(new_n235_));
  NAND2_X1   g145(.A1(new_n213_), .A2(\dest_y[17] ), .ZN(new_n236_));
  XOR2_X1    g146(.A1(new_n236_), .A2(\dest_y[18] ), .Z(new_n237_));
  INV_X1     g147(.I(\dest_y[17] ), .ZN(new_n238_));
  NOR2_X1    g148(.A1(new_n211_), .A2(new_n212_), .ZN(new_n239_));
  NOR3_X1    g149(.A1(new_n239_), .A2(\dest_y[16] ), .A3(new_n238_), .ZN(new_n240_));
  AOI21_X1   g150(.A1(new_n238_), .A2(new_n213_), .B(new_n240_), .ZN(new_n241_));
  OAI21_X1   g151(.A1(new_n211_), .A2(new_n212_), .B(\dest_y[16] ), .ZN(new_n242_));
  NAND2_X1   g152(.A1(new_n239_), .A2(new_n208_), .ZN(new_n243_));
  NAND2_X1   g153(.A1(new_n243_), .A2(new_n242_), .ZN(new_n244_));
  NAND2_X1   g154(.A1(new_n210_), .A2(new_n209_), .ZN(new_n245_));
  XOR2_X1    g155(.A1(new_n245_), .A2(\dest_y[13] ), .Z(new_n246_));
  XOR2_X1    g156(.A1(new_n210_), .A2(\dest_y[12] ), .Z(new_n247_));
  NOR2_X1    g157(.A1(\dest_y[9] ), .A2(\dest_y[10] ), .ZN(new_n248_));
  XNOR2_X1   g158(.A1(new_n248_), .A2(\dest_y[11] ), .ZN(new_n249_));
  NOR4_X1    g159(.A1(\dest_y[3] ), .A2(\dest_y[4] ), .A3(\dest_y[5] ), .A4(\dest_y[6] ), .ZN(new_n250_));
  OR2_X2     g160(.A1(\dest_y[1] ), .A2(\dest_y[2] ), .Z(new_n251_));
  INV_X1     g161(.I(\dest_y[7] ), .ZN(new_n252_));
  INV_X1     g162(.I(\dest_y[8] ), .ZN(new_n253_));
  INV_X1     g163(.I(\dest_y[10] ), .ZN(new_n254_));
  NAND4_X1   g164(.A1(new_n252_), .A2(new_n253_), .A3(new_n254_), .A4(\dest_y[9] ), .ZN(new_n255_));
  OR3_X2     g165(.A1(new_n255_), .A2(new_n250_), .A3(new_n251_), .Z(new_n256_));
  NOR4_X1    g166(.A1(new_n246_), .A2(new_n247_), .A3(new_n249_), .A4(new_n256_), .ZN(new_n257_));
  INV_X1     g167(.I(\dest_y[14] ), .ZN(new_n258_));
  NAND2_X1   g168(.A1(new_n258_), .A2(\dest_y[13] ), .ZN(new_n259_));
  OR3_X2     g169(.A1(new_n245_), .A2(\dest_y[15] ), .A3(new_n259_), .Z(new_n260_));
  OAI21_X1   g170(.A1(new_n245_), .A2(new_n259_), .B(\dest_y[15] ), .ZN(new_n261_));
  NOR2_X1    g171(.A1(new_n258_), .A2(\dest_y[13] ), .ZN(new_n262_));
  NAND2_X1   g172(.A1(new_n245_), .A2(new_n262_), .ZN(new_n263_));
  OAI21_X1   g173(.A1(\dest_y[14] ), .A2(new_n211_), .B(new_n263_), .ZN(new_n264_));
  AOI21_X1   g174(.A1(new_n260_), .A2(new_n261_), .B(new_n264_), .ZN(new_n265_));
  NAND4_X1   g175(.A1(new_n257_), .A2(new_n265_), .A3(new_n241_), .A4(new_n244_), .ZN(new_n266_));
  NOR4_X1    g176(.A1(new_n266_), .A2(new_n234_), .A3(new_n237_), .A4(new_n235_), .ZN(new_n267_));
  XOR2_X1    g177(.A1(new_n218_), .A2(\dest_y[22] ), .Z(new_n268_));
  NAND3_X1   g178(.A1(new_n214_), .A2(\dest_y[19] ), .A3(\dest_y[20] ), .ZN(new_n269_));
  XNOR2_X1   g179(.A1(new_n269_), .A2(\dest_y[21] ), .ZN(new_n270_));
  NAND4_X1   g180(.A1(new_n267_), .A2(new_n268_), .A3(new_n270_), .A4(new_n233_), .ZN(new_n271_));
  NAND4_X1   g181(.A1(new_n218_), .A2(\dest_y[22] ), .A3(new_n219_), .A4(new_n220_), .ZN(new_n272_));
  NAND3_X1   g182(.A1(new_n218_), .A2(\dest_y[22] ), .A3(new_n219_), .ZN(new_n273_));
  NAND2_X1   g183(.A1(new_n273_), .A2(\dest_y[24] ), .ZN(new_n274_));
  NAND2_X1   g184(.A1(new_n274_), .A2(new_n272_), .ZN(new_n275_));
  NOR2_X1    g185(.A1(new_n218_), .A2(\dest_y[22] ), .ZN(new_n276_));
  NOR2_X1    g186(.A1(new_n276_), .A2(\dest_y[23] ), .ZN(new_n277_));
  NOR2_X1    g187(.A1(new_n219_), .A2(\dest_y[22] ), .ZN(new_n278_));
  INV_X1     g188(.I(new_n278_), .ZN(new_n279_));
  NOR2_X1    g189(.A1(new_n218_), .A2(new_n279_), .ZN(new_n280_));
  NOR2_X1    g190(.A1(new_n277_), .A2(new_n280_), .ZN(new_n281_));
  NAND2_X1   g191(.A1(new_n275_), .A2(new_n281_), .ZN(new_n282_));
  NOR4_X1    g192(.A1(new_n271_), .A2(new_n229_), .A3(new_n282_), .A4(new_n230_), .ZN(new_n283_));
  INV_X1     g193(.I(\dest_y[29] ), .ZN(new_n284_));
  NAND3_X1   g194(.A1(new_n223_), .A2(\dest_y[27] ), .A3(\dest_y[28] ), .ZN(new_n285_));
  NOR2_X1    g195(.A1(new_n285_), .A2(new_n284_), .ZN(new_n286_));
  INV_X1     g196(.I(new_n286_), .ZN(new_n287_));
  INV_X1     g197(.I(\dest_y[28] ), .ZN(new_n288_));
  NAND2_X1   g198(.A1(new_n223_), .A2(\dest_y[27] ), .ZN(new_n289_));
  NAND2_X1   g199(.A1(new_n289_), .A2(new_n288_), .ZN(new_n290_));
  NAND2_X1   g200(.A1(new_n290_), .A2(new_n285_), .ZN(new_n291_));
  NAND4_X1   g201(.A1(new_n283_), .A2(new_n224_), .A3(new_n287_), .A4(new_n291_), .ZN(new_n292_));
  INV_X1     g202(.I(new_n224_), .ZN(new_n293_));
  XOR2_X1    g203(.A1(new_n222_), .A2(\dest_y[25] ), .Z(new_n294_));
  XNOR2_X1   g204(.A1(new_n218_), .A2(\dest_y[22] ), .ZN(new_n295_));
  XOR2_X1    g205(.A1(new_n269_), .A2(\dest_y[21] ), .Z(new_n296_));
  NOR2_X1    g206(.A1(new_n234_), .A2(new_n235_), .ZN(new_n297_));
  XNOR2_X1   g207(.A1(new_n236_), .A2(\dest_y[18] ), .ZN(new_n298_));
  INV_X1     g208(.I(new_n244_), .ZN(new_n299_));
  AND2_X2    g209(.A1(new_n260_), .A2(new_n261_), .Z(new_n300_));
  XNOR2_X1   g210(.A1(new_n245_), .A2(\dest_y[13] ), .ZN(new_n301_));
  NOR4_X1    g211(.A1(new_n253_), .A2(new_n284_), .A3(\dest_y[9] ), .A4(\dest_y[10] ), .ZN(new_n302_));
  NAND4_X1   g212(.A1(\dest_y[4] ), .A2(\dest_y[5] ), .A3(\dest_y[6] ), .A4(\dest_y[7] ), .ZN(new_n303_));
  NAND4_X1   g213(.A1(\dest_y[0] ), .A2(\dest_y[1] ), .A3(\dest_y[2] ), .A4(\dest_y[3] ), .ZN(new_n304_));
  NOR2_X1    g214(.A1(new_n303_), .A2(new_n304_), .ZN(new_n305_));
  NAND4_X1   g215(.A1(new_n247_), .A2(new_n249_), .A3(new_n302_), .A4(new_n305_), .ZN(new_n306_));
  NOR2_X1    g216(.A1(new_n306_), .A2(new_n301_), .ZN(new_n307_));
  NAND4_X1   g217(.A1(new_n299_), .A2(new_n307_), .A3(new_n300_), .A4(new_n264_), .ZN(new_n308_));
  NOR4_X1    g218(.A1(new_n297_), .A2(new_n308_), .A3(new_n298_), .A4(new_n241_), .ZN(new_n309_));
  NAND4_X1   g219(.A1(new_n309_), .A2(new_n232_), .A3(new_n295_), .A4(new_n296_), .ZN(new_n310_));
  OAI22_X1   g220(.A1(new_n276_), .A2(\dest_y[23] ), .B1(new_n218_), .B2(new_n279_), .ZN(new_n311_));
  NAND3_X1   g221(.A1(new_n311_), .A2(new_n274_), .A3(new_n272_), .ZN(new_n312_));
  NOR4_X1    g222(.A1(new_n310_), .A2(new_n228_), .A3(new_n294_), .A4(new_n312_), .ZN(new_n313_));
  NAND4_X1   g223(.A1(new_n293_), .A2(new_n313_), .A3(new_n285_), .A4(new_n290_), .ZN(new_n314_));
  OAI21_X1   g224(.A1(\dest_x[0] ), .A2(\dest_y[0] ), .B(new_n286_), .ZN(new_n315_));
  NAND3_X1   g225(.A1(new_n314_), .A2(new_n292_), .A3(new_n315_), .ZN(new_n316_));
  NOR3_X1    g226(.A1(new_n201_), .A2(new_n110_), .A3(new_n111_), .ZN(new_n317_));
  NAND3_X1   g227(.A1(new_n317_), .A2(new_n107_), .A3(new_n186_), .ZN(new_n318_));
  OAI22_X1   g228(.A1(new_n286_), .A2(new_n189_), .B1(new_n182_), .B2(\dest_x[29] ), .ZN(new_n319_));
  AOI21_X1   g229(.A1(new_n318_), .A2(new_n183_), .B(new_n319_), .ZN(new_n320_));
  AOI21_X1   g230(.A1(new_n316_), .A2(new_n320_), .B(new_n187_), .ZN(\outport[1] ));
  INV_X1     g231(.I(new_n187_), .ZN(new_n322_));
  NAND2_X1   g232(.A1(new_n203_), .A2(new_n204_), .ZN(new_n323_));
  NAND3_X1   g233(.A1(new_n286_), .A2(\dest_x[0] ), .A3(\dest_y[0] ), .ZN(new_n324_));
  NAND2_X1   g234(.A1(new_n292_), .A2(new_n324_), .ZN(new_n325_));
  AOI21_X1   g235(.A1(new_n323_), .A2(new_n322_), .B(new_n325_), .ZN(\outport[2] ));
  assign     \outport[3]  = 1'b1;
  assign     \outport[4]  = 1'b1;
  assign     \outport[5]  = 1'b1;
  assign     \outport[6]  = 1'b1;
  assign     \outport[7]  = 1'b1;
  assign     \outport[8]  = 1'b1;
  assign     \outport[9]  = 1'b1;
  assign     \outport[10]  = 1'b1;
  assign     \outport[11]  = 1'b1;
  assign     \outport[12]  = 1'b1;
  assign     \outport[13]  = 1'b1;
  assign     \outport[14]  = 1'b1;
  assign     \outport[15]  = 1'b1;
  assign     \outport[16]  = 1'b1;
  assign     \outport[17]  = 1'b1;
  assign     \outport[18]  = 1'b1;
  assign     \outport[19]  = 1'b1;
  assign     \outport[20]  = 1'b1;
  assign     \outport[21]  = 1'b1;
  assign     \outport[22]  = 1'b1;
  assign     \outport[23]  = 1'b1;
  assign     \outport[24]  = 1'b1;
  assign     \outport[25]  = 1'b1;
  assign     \outport[26]  = 1'b1;
  assign     \outport[27]  = 1'b1;
  assign     \outport[28]  = 1'b1;
  assign     \outport[29]  = 1'b1;
endmodule


