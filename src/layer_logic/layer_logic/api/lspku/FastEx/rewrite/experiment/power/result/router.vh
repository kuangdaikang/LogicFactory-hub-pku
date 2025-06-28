// Benchmark "router" written by ABC on Thu Sep 14 22:44:44 2023

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
    new_n194_, new_n195_, new_n197_, new_n198_, new_n199_, new_n200_,
    new_n201_, new_n202_, new_n203_, new_n204_, new_n205_, new_n206_,
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
    new_n304_, new_n305_, new_n306_, new_n307_, new_n308_, new_n309_,
    new_n310_, new_n311_, new_n312_, new_n313_, new_n314_, new_n315_,
    new_n316_, new_n317_, new_n318_, new_n319_, new_n320_, new_n321_,
    new_n322_, new_n323_, new_n324_, new_n325_, new_n326_, new_n327_,
    new_n328_, new_n329_, new_n330_, new_n331_, new_n332_, new_n333_;
  INV_X1     g000(.I(\dest_x[28] ), .ZN(new_n91_));
  INV_X1     g001(.I(\dest_x[22] ), .ZN(new_n92_));
  NOR2_X1    g002(.A1(\dest_x[23] ), .A2(\dest_x[24] ), .ZN(new_n93_));
  INV_X1     g003(.I(\dest_x[10] ), .ZN(new_n94_));
  INV_X1     g004(.I(\dest_x[13] ), .ZN(new_n95_));
  NOR2_X1    g005(.A1(\dest_x[14] ), .A2(\dest_x[15] ), .ZN(new_n96_));
  AOI21_X1   g006(.A1(\dest_x[11] ), .A2(\dest_x[12] ), .B(\dest_x[9] ), .ZN(new_n97_));
  NOR4_X1    g007(.A1(new_n97_), .A2(new_n94_), .A3(new_n96_), .A4(new_n95_), .ZN(new_n98_));
  NAND2_X1   g008(.A1(\dest_x[17] ), .A2(\dest_x[18] ), .ZN(new_n99_));
  INV_X1     g009(.I(new_n99_), .ZN(new_n100_));
  OAI21_X1   g010(.A1(new_n98_), .A2(new_n100_), .B(\dest_x[16] ), .ZN(new_n101_));
  NOR3_X1    g011(.A1(\dest_x[19] ), .A2(\dest_x[20] ), .A3(\dest_x[21] ), .ZN(new_n102_));
  NOR4_X1    g012(.A1(new_n101_), .A2(new_n92_), .A3(new_n93_), .A4(new_n102_), .ZN(new_n103_));
  INV_X1     g013(.I(\dest_x[26] ), .ZN(new_n104_));
  INV_X1     g014(.I(\dest_x[27] ), .ZN(new_n105_));
  NOR2_X1    g015(.A1(new_n104_), .A2(new_n105_), .ZN(new_n106_));
  OAI21_X1   g016(.A1(new_n103_), .A2(new_n106_), .B(\dest_x[25] ), .ZN(new_n107_));
  NOR2_X1    g017(.A1(new_n107_), .A2(new_n91_), .ZN(new_n108_));
  OAI21_X1   g018(.A1(\dest_x[26] ), .A2(\dest_x[27] ), .B(\dest_x[25] ), .ZN(new_n109_));
  XOR2_X1    g019(.A1(new_n103_), .A2(new_n109_), .Z(new_n110_));
  NAND2_X1   g020(.A1(new_n103_), .A2(\dest_x[25] ), .ZN(new_n111_));
  INV_X1     g021(.I(\dest_x[25] ), .ZN(new_n112_));
  NOR2_X1    g022(.A1(new_n112_), .A2(\dest_x[26] ), .ZN(new_n113_));
  AOI22_X1   g023(.A1(new_n111_), .A2(\dest_x[26] ), .B1(new_n103_), .B2(new_n113_), .ZN(new_n114_));
  INV_X1     g024(.I(new_n114_), .ZN(new_n115_));
  XOR2_X1    g025(.A1(new_n103_), .A2(new_n112_), .Z(new_n116_));
  AOI21_X1   g026(.A1(new_n101_), .A2(\dest_x[19] ), .B(\dest_x[20] ), .ZN(new_n117_));
  INV_X1     g027(.I(\dest_x[19] ), .ZN(new_n118_));
  INV_X1     g028(.I(\dest_x[20] ), .ZN(new_n119_));
  INV_X1     g029(.I(\dest_x[16] ), .ZN(new_n120_));
  INV_X1     g030(.I(new_n96_), .ZN(new_n121_));
  NOR2_X1    g031(.A1(new_n97_), .A2(new_n94_), .ZN(new_n122_));
  NAND3_X1   g032(.A1(new_n122_), .A2(\dest_x[13] ), .A3(new_n121_), .ZN(new_n123_));
  AOI21_X1   g033(.A1(new_n123_), .A2(new_n99_), .B(new_n120_), .ZN(new_n124_));
  NOR3_X1    g034(.A1(new_n124_), .A2(new_n118_), .A3(new_n119_), .ZN(new_n125_));
  INV_X1     g035(.I(new_n93_), .ZN(new_n126_));
  NOR4_X1    g036(.A1(new_n101_), .A2(new_n92_), .A3(new_n126_), .A4(new_n102_), .ZN(new_n127_));
  OAI21_X1   g037(.A1(new_n125_), .A2(new_n117_), .B(new_n127_), .ZN(new_n128_));
  INV_X1     g038(.I(new_n128_), .ZN(new_n129_));
  NOR3_X1    g039(.A1(new_n101_), .A2(\dest_x[22] ), .A3(new_n102_), .ZN(new_n130_));
  NOR2_X1    g040(.A1(new_n130_), .A2(\dest_x[23] ), .ZN(new_n131_));
  NAND2_X1   g041(.A1(new_n92_), .A2(\dest_x[23] ), .ZN(new_n132_));
  NOR3_X1    g042(.A1(new_n101_), .A2(new_n102_), .A3(new_n132_), .ZN(new_n133_));
  NOR2_X1    g043(.A1(new_n131_), .A2(new_n133_), .ZN(new_n134_));
  NOR2_X1    g044(.A1(new_n101_), .A2(new_n118_), .ZN(new_n135_));
  NAND2_X1   g045(.A1(new_n101_), .A2(new_n118_), .ZN(new_n136_));
  INV_X1     g046(.I(new_n136_), .ZN(new_n137_));
  NAND3_X1   g047(.A1(\dest_x[19] ), .A2(\dest_x[20] ), .A3(\dest_x[21] ), .ZN(new_n138_));
  INV_X1     g048(.I(new_n138_), .ZN(new_n139_));
  NAND2_X1   g049(.A1(new_n101_), .A2(new_n139_), .ZN(new_n140_));
  INV_X1     g050(.I(new_n140_), .ZN(new_n141_));
  NOR2_X1    g051(.A1(new_n101_), .A2(new_n139_), .ZN(new_n142_));
  OAI22_X1   g052(.A1(new_n135_), .A2(new_n137_), .B1(new_n141_), .B2(new_n142_), .ZN(new_n143_));
  NOR2_X1    g053(.A1(new_n98_), .A2(\dest_x[16] ), .ZN(new_n144_));
  NAND2_X1   g054(.A1(new_n120_), .A2(\dest_x[17] ), .ZN(new_n145_));
  OAI22_X1   g055(.A1(new_n144_), .A2(\dest_x[17] ), .B1(new_n98_), .B2(new_n145_), .ZN(new_n146_));
  XOR2_X1    g056(.A1(new_n98_), .A2(\dest_x[16] ), .Z(new_n147_));
  OAI21_X1   g057(.A1(\dest_x[17] ), .A2(\dest_x[18] ), .B(\dest_x[16] ), .ZN(new_n148_));
  XNOR2_X1   g058(.A1(new_n98_), .A2(new_n148_), .ZN(new_n149_));
  NOR3_X1    g059(.A1(new_n97_), .A2(new_n94_), .A3(\dest_x[13] ), .ZN(new_n150_));
  NOR2_X1    g060(.A1(new_n150_), .A2(\dest_x[14] ), .ZN(new_n151_));
  NAND2_X1   g061(.A1(new_n95_), .A2(\dest_x[14] ), .ZN(new_n152_));
  NOR3_X1    g062(.A1(new_n152_), .A2(new_n94_), .A3(new_n97_), .ZN(new_n153_));
  NOR2_X1    g063(.A1(new_n151_), .A2(new_n153_), .ZN(new_n154_));
  NAND3_X1   g064(.A1(new_n122_), .A2(\dest_x[13] ), .A3(new_n96_), .ZN(new_n155_));
  OAI21_X1   g065(.A1(\dest_x[11] ), .A2(\dest_x[12] ), .B(\dest_x[10] ), .ZN(new_n156_));
  XOR2_X1    g066(.A1(new_n156_), .A2(\dest_x[9] ), .Z(new_n157_));
  INV_X1     g067(.I(\dest_x[9] ), .ZN(new_n158_));
  AOI21_X1   g068(.A1(new_n158_), .A2(new_n94_), .B(\dest_x[11] ), .ZN(new_n159_));
  INV_X1     g069(.I(\dest_x[11] ), .ZN(new_n160_));
  NOR3_X1    g070(.A1(new_n160_), .A2(\dest_x[9] ), .A3(\dest_x[10] ), .ZN(new_n161_));
  NOR2_X1    g071(.A1(new_n159_), .A2(new_n161_), .ZN(new_n162_));
  INV_X1     g072(.I(new_n162_), .ZN(new_n163_));
  NAND4_X1   g073(.A1(\dest_x[7] ), .A2(\dest_x[8] ), .A3(\dest_x[9] ), .A4(\dest_x[10] ), .ZN(new_n164_));
  OR2_X2     g074(.A1(\dest_x[1] ), .A2(\dest_x[2] ), .Z(new_n165_));
  NAND4_X1   g075(.A1(\dest_x[3] ), .A2(\dest_x[4] ), .A3(\dest_x[5] ), .A4(\dest_x[6] ), .ZN(new_n166_));
  NOR3_X1    g076(.A1(new_n164_), .A2(new_n165_), .A3(new_n166_), .ZN(new_n167_));
  NAND2_X1   g077(.A1(new_n163_), .A2(new_n167_), .ZN(new_n168_));
  NOR4_X1    g078(.A1(new_n168_), .A2(new_n154_), .A3(new_n155_), .A4(new_n157_), .ZN(new_n169_));
  NAND4_X1   g079(.A1(new_n169_), .A2(new_n146_), .A3(new_n147_), .A4(new_n149_), .ZN(new_n170_));
  NOR3_X1    g080(.A1(new_n170_), .A2(new_n143_), .A3(new_n134_), .ZN(new_n171_));
  NAND4_X1   g081(.A1(new_n171_), .A2(new_n115_), .A3(new_n116_), .A4(new_n129_), .ZN(new_n172_));
  NAND2_X1   g082(.A1(new_n107_), .A2(new_n91_), .ZN(new_n173_));
  INV_X1     g083(.I(new_n173_), .ZN(new_n174_));
  INV_X1     g084(.I(\dest_x[29] ), .ZN(new_n175_));
  NOR3_X1    g085(.A1(new_n107_), .A2(new_n91_), .A3(new_n175_), .ZN(new_n176_));
  NOR3_X1    g086(.A1(new_n174_), .A2(new_n108_), .A3(new_n176_), .ZN(new_n177_));
  AOI21_X1   g087(.A1(new_n172_), .A2(new_n177_), .B(new_n110_), .ZN(new_n178_));
  AOI21_X1   g088(.A1(new_n178_), .A2(\dest_x[29] ), .B(new_n108_), .ZN(new_n179_));
  INV_X1     g089(.I(new_n108_), .ZN(new_n180_));
  NAND2_X1   g090(.A1(new_n180_), .A2(new_n173_), .ZN(new_n181_));
  NAND2_X1   g091(.A1(\dest_x[0] ), .A2(\dest_x[1] ), .ZN(new_n182_));
  NAND4_X1   g092(.A1(\dest_x[2] ), .A2(\dest_x[3] ), .A3(\dest_x[4] ), .A4(\dest_x[5] ), .ZN(new_n183_));
  NOR2_X1    g093(.A1(new_n183_), .A2(new_n182_), .ZN(new_n184_));
  INV_X1     g094(.I(\dest_x[8] ), .ZN(new_n185_));
  NAND2_X1   g095(.A1(\dest_x[6] ), .A2(\dest_x[7] ), .ZN(new_n186_));
  NOR4_X1    g096(.A1(new_n186_), .A2(new_n185_), .A3(new_n158_), .A4(\dest_x[10] ), .ZN(new_n187_));
  NAND3_X1   g097(.A1(new_n163_), .A2(new_n184_), .A3(new_n187_), .ZN(new_n188_));
  NOR4_X1    g098(.A1(new_n188_), .A2(new_n154_), .A3(new_n155_), .A4(new_n157_), .ZN(new_n189_));
  NAND4_X1   g099(.A1(new_n189_), .A2(new_n146_), .A3(new_n147_), .A4(new_n149_), .ZN(new_n190_));
  NOR4_X1    g100(.A1(new_n190_), .A2(new_n143_), .A3(new_n128_), .A4(new_n134_), .ZN(new_n191_));
  NAND4_X1   g101(.A1(new_n103_), .A2(\dest_x[25] ), .A3(new_n104_), .A4(new_n105_), .ZN(new_n192_));
  INV_X1     g102(.I(new_n192_), .ZN(new_n193_));
  NAND4_X1   g103(.A1(new_n181_), .A2(new_n191_), .A3(new_n193_), .A4(new_n115_), .ZN(new_n194_));
  NOR2_X1    g104(.A1(new_n178_), .A2(\dest_x[29] ), .ZN(new_n195_));
  NOR3_X1    g105(.A1(new_n179_), .A2(new_n195_), .A3(new_n194_), .ZN(\outport[0] ));
  INV_X1     g106(.I(new_n176_), .ZN(new_n197_));
  NAND2_X1   g107(.A1(new_n194_), .A2(new_n197_), .ZN(new_n198_));
  INV_X1     g108(.I(\dest_x[0] ), .ZN(new_n199_));
  INV_X1     g109(.I(\dest_y[22] ), .ZN(new_n200_));
  NOR2_X1    g110(.A1(\dest_y[23] ), .A2(\dest_y[24] ), .ZN(new_n201_));
  INV_X1     g111(.I(\dest_y[10] ), .ZN(new_n202_));
  INV_X1     g112(.I(\dest_y[13] ), .ZN(new_n203_));
  NOR2_X1    g113(.A1(\dest_y[14] ), .A2(\dest_y[15] ), .ZN(new_n204_));
  AOI21_X1   g114(.A1(\dest_y[11] ), .A2(\dest_y[12] ), .B(\dest_y[9] ), .ZN(new_n205_));
  NOR4_X1    g115(.A1(new_n205_), .A2(new_n202_), .A3(new_n204_), .A4(new_n203_), .ZN(new_n206_));
  INV_X1     g116(.I(\dest_y[17] ), .ZN(new_n207_));
  INV_X1     g117(.I(\dest_y[18] ), .ZN(new_n208_));
  NOR2_X1    g118(.A1(new_n207_), .A2(new_n208_), .ZN(new_n209_));
  OAI21_X1   g119(.A1(new_n206_), .A2(new_n209_), .B(\dest_y[16] ), .ZN(new_n210_));
  NOR3_X1    g120(.A1(\dest_y[19] ), .A2(\dest_y[20] ), .A3(\dest_y[21] ), .ZN(new_n211_));
  NOR4_X1    g121(.A1(new_n210_), .A2(new_n200_), .A3(new_n201_), .A4(new_n211_), .ZN(new_n212_));
  INV_X1     g122(.I(\dest_y[26] ), .ZN(new_n213_));
  INV_X1     g123(.I(\dest_y[27] ), .ZN(new_n214_));
  NOR2_X1    g124(.A1(new_n213_), .A2(new_n214_), .ZN(new_n215_));
  OAI21_X1   g125(.A1(new_n212_), .A2(new_n215_), .B(\dest_y[25] ), .ZN(new_n216_));
  INV_X1     g126(.I(new_n216_), .ZN(new_n217_));
  NAND3_X1   g127(.A1(new_n217_), .A2(\dest_y[28] ), .A3(\dest_y[29] ), .ZN(new_n218_));
  INV_X1     g128(.I(new_n218_), .ZN(new_n219_));
  OAI22_X1   g129(.A1(new_n219_), .A2(new_n199_), .B1(\dest_x[29] ), .B2(new_n108_), .ZN(new_n220_));
  NOR2_X1    g130(.A1(new_n178_), .A2(new_n220_), .ZN(new_n221_));
  INV_X1     g131(.I(\dest_y[25] ), .ZN(new_n222_));
  AOI21_X1   g132(.A1(new_n213_), .A2(new_n214_), .B(new_n222_), .ZN(new_n223_));
  XOR2_X1    g133(.A1(new_n212_), .A2(new_n223_), .Z(new_n224_));
  NAND2_X1   g134(.A1(new_n212_), .A2(\dest_y[25] ), .ZN(new_n225_));
  NOR2_X1    g135(.A1(new_n222_), .A2(\dest_y[26] ), .ZN(new_n226_));
  AOI22_X1   g136(.A1(new_n225_), .A2(\dest_y[26] ), .B1(new_n212_), .B2(new_n226_), .ZN(new_n227_));
  XOR2_X1    g137(.A1(new_n212_), .A2(\dest_y[25] ), .Z(new_n228_));
  AOI21_X1   g138(.A1(new_n210_), .A2(\dest_y[19] ), .B(\dest_y[20] ), .ZN(new_n229_));
  AND3_X2    g139(.A1(new_n210_), .A2(\dest_y[19] ), .A3(\dest_y[20] ), .Z(new_n230_));
  INV_X1     g140(.I(new_n201_), .ZN(new_n231_));
  NOR4_X1    g141(.A1(new_n210_), .A2(new_n200_), .A3(new_n231_), .A4(new_n211_), .ZN(new_n232_));
  OAI21_X1   g142(.A1(new_n230_), .A2(new_n229_), .B(new_n232_), .ZN(new_n233_));
  OR2_X2     g143(.A1(\dest_y[14] ), .A2(\dest_y[15] ), .Z(new_n234_));
  INV_X1     g144(.I(\dest_y[9] ), .ZN(new_n235_));
  NAND2_X1   g145(.A1(\dest_y[11] ), .A2(\dest_y[12] ), .ZN(new_n236_));
  NAND2_X1   g146(.A1(new_n236_), .A2(new_n235_), .ZN(new_n237_));
  NAND4_X1   g147(.A1(new_n237_), .A2(\dest_y[10] ), .A3(new_n234_), .A4(\dest_y[13] ), .ZN(new_n238_));
  INV_X1     g148(.I(new_n209_), .ZN(new_n239_));
  NAND2_X1   g149(.A1(new_n238_), .A2(new_n239_), .ZN(new_n240_));
  INV_X1     g150(.I(new_n211_), .ZN(new_n241_));
  NAND3_X1   g151(.A1(new_n240_), .A2(\dest_y[16] ), .A3(new_n241_), .ZN(new_n242_));
  NOR3_X1    g152(.A1(new_n210_), .A2(\dest_y[22] ), .A3(new_n211_), .ZN(new_n243_));
  NAND2_X1   g153(.A1(new_n200_), .A2(\dest_y[23] ), .ZN(new_n244_));
  OAI22_X1   g154(.A1(new_n242_), .A2(new_n244_), .B1(new_n243_), .B2(\dest_y[23] ), .ZN(new_n245_));
  NAND3_X1   g155(.A1(new_n240_), .A2(\dest_y[16] ), .A3(\dest_y[19] ), .ZN(new_n246_));
  INV_X1     g156(.I(\dest_y[19] ), .ZN(new_n247_));
  NAND2_X1   g157(.A1(new_n210_), .A2(new_n247_), .ZN(new_n248_));
  NAND4_X1   g158(.A1(new_n210_), .A2(\dest_y[19] ), .A3(\dest_y[20] ), .A4(\dest_y[21] ), .ZN(new_n249_));
  NAND3_X1   g159(.A1(\dest_y[19] ), .A2(\dest_y[20] ), .A3(\dest_y[21] ), .ZN(new_n250_));
  NAND3_X1   g160(.A1(new_n240_), .A2(\dest_y[16] ), .A3(new_n250_), .ZN(new_n251_));
  AOI22_X1   g161(.A1(new_n246_), .A2(new_n248_), .B1(new_n251_), .B2(new_n249_), .ZN(new_n252_));
  INV_X1     g162(.I(\dest_y[16] ), .ZN(new_n253_));
  NAND2_X1   g163(.A1(new_n238_), .A2(new_n253_), .ZN(new_n254_));
  NOR3_X1    g164(.A1(new_n206_), .A2(\dest_y[16] ), .A3(new_n207_), .ZN(new_n255_));
  AOI21_X1   g165(.A1(new_n254_), .A2(new_n207_), .B(new_n255_), .ZN(new_n256_));
  AND2_X2    g166(.A1(\dest_y[11] ), .A2(\dest_y[12] ), .Z(new_n257_));
  OAI21_X1   g167(.A1(new_n257_), .A2(\dest_y[9] ), .B(\dest_y[10] ), .ZN(new_n258_));
  NOR3_X1    g168(.A1(new_n205_), .A2(new_n202_), .A3(\dest_y[13] ), .ZN(new_n259_));
  NAND2_X1   g169(.A1(new_n203_), .A2(\dest_y[14] ), .ZN(new_n260_));
  OAI22_X1   g170(.A1(new_n258_), .A2(new_n260_), .B1(new_n259_), .B2(\dest_y[14] ), .ZN(new_n261_));
  NOR3_X1    g171(.A1(new_n258_), .A2(new_n203_), .A3(new_n234_), .ZN(new_n262_));
  OAI21_X1   g172(.A1(\dest_y[11] ), .A2(\dest_y[12] ), .B(\dest_y[10] ), .ZN(new_n263_));
  XOR2_X1    g173(.A1(new_n263_), .A2(new_n235_), .Z(new_n264_));
  AOI21_X1   g174(.A1(new_n235_), .A2(new_n202_), .B(\dest_y[11] ), .ZN(new_n265_));
  INV_X1     g175(.I(\dest_y[11] ), .ZN(new_n266_));
  NOR3_X1    g176(.A1(new_n266_), .A2(\dest_y[9] ), .A3(\dest_y[10] ), .ZN(new_n267_));
  NOR2_X1    g177(.A1(new_n265_), .A2(new_n267_), .ZN(new_n268_));
  NAND4_X1   g178(.A1(\dest_y[7] ), .A2(\dest_y[8] ), .A3(\dest_y[9] ), .A4(\dest_y[10] ), .ZN(new_n269_));
  NOR2_X1    g179(.A1(\dest_y[1] ), .A2(\dest_y[2] ), .ZN(new_n270_));
  AND2_X2    g180(.A1(\dest_y[5] ), .A2(\dest_y[6] ), .Z(new_n271_));
  NAND4_X1   g181(.A1(new_n271_), .A2(\dest_y[3] ), .A3(\dest_y[4] ), .A4(new_n270_), .ZN(new_n272_));
  NOR3_X1    g182(.A1(new_n268_), .A2(new_n272_), .A3(new_n269_), .ZN(new_n273_));
  NAND4_X1   g183(.A1(new_n273_), .A2(new_n261_), .A3(new_n262_), .A4(new_n264_), .ZN(new_n274_));
  OAI21_X1   g184(.A1(\dest_y[17] ), .A2(\dest_y[18] ), .B(\dest_y[16] ), .ZN(new_n275_));
  XOR2_X1    g185(.A1(new_n206_), .A2(new_n275_), .Z(new_n276_));
  XOR2_X1    g186(.A1(new_n206_), .A2(new_n253_), .Z(new_n277_));
  NOR4_X1    g187(.A1(new_n274_), .A2(new_n256_), .A3(new_n276_), .A4(new_n277_), .ZN(new_n278_));
  NAND3_X1   g188(.A1(new_n252_), .A2(new_n278_), .A3(new_n245_), .ZN(new_n279_));
  NOR4_X1    g189(.A1(new_n279_), .A2(new_n227_), .A3(new_n228_), .A4(new_n233_), .ZN(new_n280_));
  NAND2_X1   g190(.A1(new_n217_), .A2(\dest_y[28] ), .ZN(new_n281_));
  INV_X1     g191(.I(\dest_y[28] ), .ZN(new_n282_));
  NAND2_X1   g192(.A1(new_n216_), .A2(new_n282_), .ZN(new_n283_));
  NAND3_X1   g193(.A1(new_n218_), .A2(new_n281_), .A3(new_n283_), .ZN(new_n284_));
  OAI21_X1   g194(.A1(new_n280_), .A2(new_n284_), .B(new_n224_), .ZN(new_n285_));
  NAND2_X1   g195(.A1(new_n281_), .A2(new_n283_), .ZN(new_n286_));
  INV_X1     g196(.I(new_n261_), .ZN(new_n287_));
  INV_X1     g197(.I(new_n268_), .ZN(new_n288_));
  NAND4_X1   g198(.A1(\dest_y[8] ), .A2(\dest_y[9] ), .A3(\dest_y[10] ), .A4(\dest_y[29] ), .ZN(new_n289_));
  NAND4_X1   g199(.A1(\dest_y[4] ), .A2(\dest_y[5] ), .A3(\dest_y[6] ), .A4(\dest_y[7] ), .ZN(new_n290_));
  NAND4_X1   g200(.A1(\dest_y[0] ), .A2(\dest_y[1] ), .A3(\dest_y[2] ), .A4(\dest_y[3] ), .ZN(new_n291_));
  NOR3_X1    g201(.A1(new_n289_), .A2(new_n290_), .A3(new_n291_), .ZN(new_n292_));
  NAND4_X1   g202(.A1(new_n262_), .A2(new_n288_), .A3(new_n264_), .A4(new_n292_), .ZN(new_n293_));
  NAND4_X1   g203(.A1(new_n238_), .A2(\dest_y[16] ), .A3(new_n207_), .A4(new_n208_), .ZN(new_n294_));
  NOR4_X1    g204(.A1(new_n256_), .A2(new_n293_), .A3(new_n287_), .A4(new_n294_), .ZN(new_n295_));
  NAND3_X1   g205(.A1(new_n252_), .A2(new_n295_), .A3(new_n245_), .ZN(new_n296_));
  NAND4_X1   g206(.A1(new_n212_), .A2(\dest_y[25] ), .A3(new_n213_), .A4(new_n214_), .ZN(new_n297_));
  NOR4_X1    g207(.A1(new_n296_), .A2(new_n227_), .A3(new_n233_), .A4(new_n297_), .ZN(new_n298_));
  NOR2_X1    g208(.A1(\dest_x[0] ), .A2(\dest_y[0] ), .ZN(new_n299_));
  INV_X1     g209(.I(new_n299_), .ZN(new_n300_));
  AOI22_X1   g210(.A1(new_n298_), .A2(new_n286_), .B1(new_n219_), .B2(new_n300_), .ZN(new_n301_));
  NAND2_X1   g211(.A1(new_n301_), .A2(new_n285_), .ZN(new_n302_));
  AOI21_X1   g212(.A1(new_n221_), .A2(new_n198_), .B(new_n302_), .ZN(\outport[1] ));
  INV_X1     g213(.I(new_n110_), .ZN(new_n304_));
  XOR2_X1    g214(.A1(new_n103_), .A2(\dest_x[25] ), .Z(new_n305_));
  NAND2_X1   g215(.A1(new_n123_), .A2(new_n99_), .ZN(new_n306_));
  INV_X1     g216(.I(new_n102_), .ZN(new_n307_));
  NAND3_X1   g217(.A1(new_n306_), .A2(\dest_x[16] ), .A3(new_n307_), .ZN(new_n308_));
  OAI22_X1   g218(.A1(new_n308_), .A2(new_n132_), .B1(\dest_x[23] ), .B2(new_n130_), .ZN(new_n309_));
  INV_X1     g219(.I(new_n135_), .ZN(new_n310_));
  NAND2_X1   g220(.A1(new_n124_), .A2(new_n138_), .ZN(new_n311_));
  AOI22_X1   g221(.A1(new_n310_), .A2(new_n136_), .B1(new_n311_), .B2(new_n140_), .ZN(new_n312_));
  INV_X1     g222(.I(\dest_x[17] ), .ZN(new_n313_));
  NAND2_X1   g223(.A1(new_n123_), .A2(new_n120_), .ZN(new_n314_));
  NOR2_X1    g224(.A1(new_n98_), .A2(new_n145_), .ZN(new_n315_));
  AOI21_X1   g225(.A1(new_n314_), .A2(new_n313_), .B(new_n315_), .ZN(new_n316_));
  XOR2_X1    g226(.A1(new_n98_), .A2(new_n120_), .Z(new_n317_));
  XOR2_X1    g227(.A1(new_n98_), .A2(new_n148_), .Z(new_n318_));
  AND2_X2    g228(.A1(\dest_x[11] ), .A2(\dest_x[12] ), .Z(new_n319_));
  OAI21_X1   g229(.A1(new_n319_), .A2(\dest_x[9] ), .B(\dest_x[10] ), .ZN(new_n320_));
  OAI22_X1   g230(.A1(new_n320_), .A2(new_n152_), .B1(new_n150_), .B2(\dest_x[14] ), .ZN(new_n321_));
  NOR3_X1    g231(.A1(new_n320_), .A2(new_n95_), .A3(new_n121_), .ZN(new_n322_));
  XOR2_X1    g232(.A1(new_n156_), .A2(new_n158_), .Z(new_n323_));
  NOR4_X1    g233(.A1(new_n162_), .A2(new_n164_), .A3(new_n165_), .A4(new_n166_), .ZN(new_n324_));
  NAND4_X1   g234(.A1(new_n324_), .A2(new_n321_), .A3(new_n322_), .A4(new_n323_), .ZN(new_n325_));
  NOR4_X1    g235(.A1(new_n325_), .A2(new_n316_), .A3(new_n317_), .A4(new_n318_), .ZN(new_n326_));
  NAND3_X1   g236(.A1(new_n312_), .A2(new_n326_), .A3(new_n309_), .ZN(new_n327_));
  NOR4_X1    g237(.A1(new_n327_), .A2(new_n114_), .A3(new_n305_), .A4(new_n128_), .ZN(new_n328_));
  NAND3_X1   g238(.A1(new_n197_), .A2(new_n180_), .A3(new_n173_), .ZN(new_n329_));
  OAI21_X1   g239(.A1(new_n328_), .A2(new_n329_), .B(new_n304_), .ZN(new_n330_));
  OAI21_X1   g240(.A1(new_n330_), .A2(new_n175_), .B(new_n180_), .ZN(new_n331_));
  AOI21_X1   g241(.A1(new_n330_), .A2(new_n175_), .B(new_n194_), .ZN(new_n332_));
  AOI21_X1   g242(.A1(new_n285_), .A2(new_n299_), .B(new_n218_), .ZN(new_n333_));
  AOI21_X1   g243(.A1(new_n331_), .A2(new_n332_), .B(new_n333_), .ZN(\outport[2] ));
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


