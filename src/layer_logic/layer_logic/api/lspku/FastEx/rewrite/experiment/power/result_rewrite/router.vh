// Benchmark "router" written by ABC on Fri Sep 15 11:27:30 2023

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
    new_n182_, new_n183_, new_n184_, new_n186_, new_n187_, new_n188_,
    new_n189_, new_n190_, new_n191_, new_n192_, new_n193_, new_n194_,
    new_n195_, new_n196_, new_n197_, new_n198_, new_n199_, new_n200_,
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
    new_n285_, new_n286_, new_n287_, new_n288_, new_n290_, new_n291_;
  INV_X1     g000(.I(\dest_x[29] ), .ZN(new_n91_));
  INV_X1     g001(.I(\dest_x[26] ), .ZN(new_n92_));
  INV_X1     g002(.I(\dest_x[27] ), .ZN(new_n93_));
  INV_X1     g003(.I(\dest_x[21] ), .ZN(new_n94_));
  INV_X1     g004(.I(\dest_x[22] ), .ZN(new_n95_));
  INV_X1     g005(.I(\dest_x[16] ), .ZN(new_n96_));
  INV_X1     g006(.I(\dest_x[17] ), .ZN(new_n97_));
  INV_X1     g007(.I(\dest_x[12] ), .ZN(new_n98_));
  INV_X1     g008(.I(\dest_x[13] ), .ZN(new_n99_));
  OAI21_X1   g009(.A1(\dest_x[9] ), .A2(\dest_x[10] ), .B(\dest_x[11] ), .ZN(new_n100_));
  NAND3_X1   g010(.A1(new_n100_), .A2(new_n98_), .A3(new_n99_), .ZN(new_n101_));
  NAND3_X1   g011(.A1(new_n101_), .A2(\dest_x[14] ), .A3(\dest_x[15] ), .ZN(new_n102_));
  AOI21_X1   g012(.A1(new_n102_), .A2(new_n96_), .B(new_n97_), .ZN(new_n103_));
  INV_X1     g013(.I(\dest_x[19] ), .ZN(new_n104_));
  INV_X1     g014(.I(\dest_x[20] ), .ZN(new_n105_));
  NOR2_X1    g015(.A1(new_n104_), .A2(new_n105_), .ZN(new_n106_));
  OAI21_X1   g016(.A1(new_n103_), .A2(\dest_x[18] ), .B(new_n106_), .ZN(new_n107_));
  NAND3_X1   g017(.A1(new_n107_), .A2(new_n94_), .A3(new_n95_), .ZN(new_n108_));
  NAND4_X1   g018(.A1(new_n108_), .A2(\dest_x[23] ), .A3(\dest_x[24] ), .A4(\dest_x[25] ), .ZN(new_n109_));
  AOI21_X1   g019(.A1(new_n109_), .A2(new_n92_), .B(new_n93_), .ZN(new_n110_));
  NAND2_X1   g020(.A1(new_n110_), .A2(\dest_x[28] ), .ZN(new_n111_));
  AOI21_X1   g021(.A1(new_n109_), .A2(new_n92_), .B(\dest_x[27] ), .ZN(new_n112_));
  AND3_X2    g022(.A1(new_n109_), .A2(new_n92_), .A3(\dest_x[27] ), .Z(new_n113_));
  INV_X1     g023(.I(new_n111_), .ZN(new_n114_));
  NOR2_X1    g024(.A1(new_n110_), .A2(\dest_x[28] ), .ZN(new_n115_));
  NOR2_X1    g025(.A1(new_n114_), .A2(new_n115_), .ZN(new_n116_));
  NAND3_X1   g026(.A1(new_n108_), .A2(\dest_x[23] ), .A3(\dest_x[24] ), .ZN(new_n117_));
  INV_X1     g027(.I(\dest_x[24] ), .ZN(new_n118_));
  NAND2_X1   g028(.A1(new_n108_), .A2(\dest_x[23] ), .ZN(new_n119_));
  NAND2_X1   g029(.A1(new_n119_), .A2(new_n118_), .ZN(new_n120_));
  NAND2_X1   g030(.A1(new_n120_), .A2(new_n117_), .ZN(new_n121_));
  XOR2_X1    g031(.A1(new_n109_), .A2(new_n92_), .Z(new_n122_));
  INV_X1     g032(.I(\dest_x[25] ), .ZN(new_n123_));
  NAND2_X1   g033(.A1(new_n117_), .A2(new_n123_), .ZN(new_n124_));
  NAND2_X1   g034(.A1(new_n124_), .A2(new_n109_), .ZN(new_n125_));
  XOR2_X1    g035(.A1(new_n103_), .A2(\dest_x[18] ), .Z(new_n126_));
  INV_X1     g036(.I(new_n102_), .ZN(new_n127_));
  AOI21_X1   g037(.A1(new_n101_), .A2(\dest_x[14] ), .B(\dest_x[15] ), .ZN(new_n128_));
  NOR2_X1    g038(.A1(new_n127_), .A2(new_n128_), .ZN(new_n129_));
  XOR2_X1    g039(.A1(new_n100_), .A2(new_n98_), .Z(new_n130_));
  INV_X1     g040(.I(\dest_x[7] ), .ZN(new_n131_));
  INV_X1     g041(.I(\dest_x[8] ), .ZN(new_n132_));
  INV_X1     g042(.I(\dest_x[10] ), .ZN(new_n133_));
  NAND4_X1   g043(.A1(new_n131_), .A2(new_n132_), .A3(new_n133_), .A4(\dest_x[9] ), .ZN(new_n134_));
  OR4_X2     g044(.A1(\dest_x[3] ), .A2(\dest_x[4] ), .A3(\dest_x[5] ), .A4(\dest_x[6] ), .Z(new_n135_));
  NOR2_X1    g045(.A1(\dest_x[9] ), .A2(\dest_x[10] ), .ZN(new_n136_));
  NAND2_X1   g046(.A1(new_n133_), .A2(\dest_x[11] ), .ZN(new_n137_));
  OAI22_X1   g047(.A1(new_n137_), .A2(\dest_x[9] ), .B1(\dest_x[11] ), .B2(new_n136_), .ZN(new_n138_));
  OR2_X2     g048(.A1(\dest_x[1] ), .A2(\dest_x[2] ), .Z(new_n139_));
  NOR4_X1    g049(.A1(new_n138_), .A2(new_n134_), .A3(new_n135_), .A4(new_n139_), .ZN(new_n140_));
  NAND2_X1   g050(.A1(new_n100_), .A2(new_n98_), .ZN(new_n141_));
  XOR2_X1    g051(.A1(new_n141_), .A2(\dest_x[13] ), .Z(new_n142_));
  XNOR2_X1   g052(.A1(new_n101_), .A2(\dest_x[14] ), .ZN(new_n143_));
  NAND4_X1   g053(.A1(new_n143_), .A2(new_n142_), .A3(new_n130_), .A4(new_n140_), .ZN(new_n144_));
  XOR2_X1    g054(.A1(new_n102_), .A2(\dest_x[16] ), .Z(new_n145_));
  NAND2_X1   g055(.A1(new_n102_), .A2(new_n96_), .ZN(new_n146_));
  XOR2_X1    g056(.A1(new_n146_), .A2(\dest_x[17] ), .Z(new_n147_));
  NOR4_X1    g057(.A1(new_n147_), .A2(new_n129_), .A3(new_n144_), .A4(new_n145_), .ZN(new_n148_));
  NOR2_X1    g058(.A1(new_n103_), .A2(\dest_x[18] ), .ZN(new_n149_));
  OAI21_X1   g059(.A1(new_n149_), .A2(new_n104_), .B(new_n105_), .ZN(new_n150_));
  NAND2_X1   g060(.A1(new_n150_), .A2(new_n107_), .ZN(new_n151_));
  XOR2_X1    g061(.A1(new_n149_), .A2(\dest_x[19] ), .Z(new_n152_));
  NAND4_X1   g062(.A1(new_n148_), .A2(new_n152_), .A3(new_n126_), .A4(new_n151_), .ZN(new_n153_));
  AOI21_X1   g063(.A1(new_n107_), .A2(new_n94_), .B(new_n95_), .ZN(new_n154_));
  XOR2_X1    g064(.A1(new_n107_), .A2(\dest_x[21] ), .Z(new_n155_));
  NOR4_X1    g065(.A1(new_n153_), .A2(new_n119_), .A3(new_n154_), .A4(new_n155_), .ZN(new_n156_));
  NAND4_X1   g066(.A1(new_n156_), .A2(new_n122_), .A3(new_n121_), .A4(new_n125_), .ZN(new_n157_));
  NOR4_X1    g067(.A1(new_n157_), .A2(new_n116_), .A3(new_n112_), .A4(new_n113_), .ZN(new_n158_));
  NOR3_X1    g068(.A1(new_n158_), .A2(new_n91_), .A3(new_n111_), .ZN(new_n159_));
  NOR2_X1    g069(.A1(new_n111_), .A2(new_n91_), .ZN(new_n160_));
  NOR2_X1    g070(.A1(new_n114_), .A2(\dest_x[29] ), .ZN(new_n161_));
  INV_X1     g071(.I(new_n161_), .ZN(new_n162_));
  NOR2_X1    g072(.A1(new_n113_), .A2(new_n112_), .ZN(new_n163_));
  XNOR2_X1   g073(.A1(new_n110_), .A2(\dest_x[28] ), .ZN(new_n164_));
  XNOR2_X1   g074(.A1(new_n108_), .A2(\dest_x[23] ), .ZN(new_n165_));
  INV_X1     g075(.I(new_n165_), .ZN(new_n166_));
  INV_X1     g076(.I(new_n147_), .ZN(new_n167_));
  INV_X1     g077(.I(\dest_x[6] ), .ZN(new_n168_));
  NOR4_X1    g078(.A1(new_n168_), .A2(new_n131_), .A3(new_n132_), .A4(\dest_x[9] ), .ZN(new_n169_));
  INV_X1     g079(.I(new_n136_), .ZN(new_n170_));
  NAND4_X1   g080(.A1(\dest_x[2] ), .A2(\dest_x[3] ), .A3(\dest_x[4] ), .A4(\dest_x[5] ), .ZN(new_n171_));
  NAND2_X1   g081(.A1(\dest_x[9] ), .A2(\dest_x[10] ), .ZN(new_n172_));
  AOI21_X1   g082(.A1(new_n170_), .A2(new_n172_), .B(new_n171_), .ZN(new_n173_));
  NAND4_X1   g083(.A1(new_n173_), .A2(\dest_x[0] ), .A3(\dest_x[1] ), .A4(new_n169_), .ZN(new_n174_));
  NOR3_X1    g084(.A1(new_n142_), .A2(new_n174_), .A3(new_n130_), .ZN(new_n175_));
  NAND2_X1   g085(.A1(new_n175_), .A2(new_n138_), .ZN(new_n176_));
  NAND2_X1   g086(.A1(new_n145_), .A2(new_n129_), .ZN(new_n177_));
  OR4_X2     g087(.A1(new_n126_), .A2(new_n143_), .A3(new_n176_), .A4(new_n177_), .Z(new_n178_));
  NAND4_X1   g088(.A1(new_n150_), .A2(new_n94_), .A3(new_n95_), .A4(new_n107_), .ZN(new_n179_));
  NOR4_X1    g089(.A1(new_n178_), .A2(new_n167_), .A3(new_n152_), .A4(new_n179_), .ZN(new_n180_));
  NOR2_X1    g090(.A1(new_n125_), .A2(new_n121_), .ZN(new_n181_));
  NAND3_X1   g091(.A1(new_n181_), .A2(new_n166_), .A3(new_n180_), .ZN(new_n182_));
  NOR4_X1    g092(.A1(new_n182_), .A2(new_n164_), .A3(new_n163_), .A4(new_n122_), .ZN(new_n183_));
  OAI21_X1   g093(.A1(new_n183_), .A2(new_n160_), .B(new_n162_), .ZN(new_n184_));
  OR2_X2     g094(.A1(new_n159_), .A2(new_n184_), .Z(\outport[0] ));
  INV_X1     g095(.I(\dest_y[23] ), .ZN(new_n186_));
  INV_X1     g096(.I(\dest_y[21] ), .ZN(new_n187_));
  INV_X1     g097(.I(\dest_y[22] ), .ZN(new_n188_));
  INV_X1     g098(.I(\dest_y[16] ), .ZN(new_n189_));
  INV_X1     g099(.I(\dest_y[17] ), .ZN(new_n190_));
  INV_X1     g100(.I(\dest_y[12] ), .ZN(new_n191_));
  INV_X1     g101(.I(\dest_y[13] ), .ZN(new_n192_));
  OAI21_X1   g102(.A1(\dest_y[9] ), .A2(\dest_y[10] ), .B(\dest_y[11] ), .ZN(new_n193_));
  NAND3_X1   g103(.A1(new_n193_), .A2(new_n191_), .A3(new_n192_), .ZN(new_n194_));
  NAND3_X1   g104(.A1(new_n194_), .A2(\dest_y[14] ), .A3(\dest_y[15] ), .ZN(new_n195_));
  AOI21_X1   g105(.A1(new_n195_), .A2(new_n189_), .B(new_n190_), .ZN(new_n196_));
  INV_X1     g106(.I(\dest_y[19] ), .ZN(new_n197_));
  INV_X1     g107(.I(\dest_y[20] ), .ZN(new_n198_));
  NOR2_X1    g108(.A1(new_n197_), .A2(new_n198_), .ZN(new_n199_));
  OAI21_X1   g109(.A1(new_n196_), .A2(\dest_y[18] ), .B(new_n199_), .ZN(new_n200_));
  NAND3_X1   g110(.A1(new_n200_), .A2(new_n187_), .A3(new_n188_), .ZN(new_n201_));
  XOR2_X1    g111(.A1(new_n201_), .A2(new_n186_), .Z(new_n202_));
  OAI21_X1   g112(.A1(new_n196_), .A2(\dest_y[18] ), .B(new_n197_), .ZN(new_n203_));
  INV_X1     g113(.I(\dest_y[18] ), .ZN(new_n204_));
  NAND2_X1   g114(.A1(new_n195_), .A2(new_n189_), .ZN(new_n205_));
  NAND2_X1   g115(.A1(new_n205_), .A2(\dest_y[17] ), .ZN(new_n206_));
  NAND3_X1   g116(.A1(new_n206_), .A2(new_n204_), .A3(\dest_y[19] ), .ZN(new_n207_));
  NAND2_X1   g117(.A1(new_n207_), .A2(new_n203_), .ZN(new_n208_));
  XOR2_X1    g118(.A1(new_n196_), .A2(new_n204_), .Z(new_n209_));
  AOI21_X1   g119(.A1(new_n195_), .A2(new_n189_), .B(\dest_y[17] ), .ZN(new_n210_));
  AND3_X2    g120(.A1(new_n195_), .A2(new_n189_), .A3(\dest_y[17] ), .Z(new_n211_));
  NOR2_X1    g121(.A1(new_n211_), .A2(new_n210_), .ZN(new_n212_));
  INV_X1     g122(.I(\dest_y[14] ), .ZN(new_n213_));
  NAND2_X1   g123(.A1(new_n194_), .A2(new_n213_), .ZN(new_n214_));
  NAND4_X1   g124(.A1(new_n193_), .A2(new_n191_), .A3(new_n192_), .A4(\dest_y[14] ), .ZN(new_n215_));
  NAND2_X1   g125(.A1(new_n214_), .A2(new_n215_), .ZN(new_n216_));
  NOR2_X1    g126(.A1(\dest_y[9] ), .A2(\dest_y[10] ), .ZN(new_n217_));
  NAND3_X1   g127(.A1(new_n217_), .A2(\dest_y[8] ), .A3(\dest_y[29] ), .ZN(new_n218_));
  NAND4_X1   g128(.A1(\dest_y[0] ), .A2(\dest_y[1] ), .A3(\dest_y[2] ), .A4(\dest_y[3] ), .ZN(new_n219_));
  NOR2_X1    g129(.A1(new_n217_), .A2(\dest_y[11] ), .ZN(new_n220_));
  INV_X1     g130(.I(\dest_y[11] ), .ZN(new_n221_));
  NOR3_X1    g131(.A1(new_n221_), .A2(\dest_y[9] ), .A3(\dest_y[10] ), .ZN(new_n222_));
  NOR2_X1    g132(.A1(new_n220_), .A2(new_n222_), .ZN(new_n223_));
  NAND4_X1   g133(.A1(\dest_y[4] ), .A2(\dest_y[5] ), .A3(\dest_y[6] ), .A4(\dest_y[7] ), .ZN(new_n224_));
  NOR4_X1    g134(.A1(new_n223_), .A2(new_n218_), .A3(new_n219_), .A4(new_n224_), .ZN(new_n225_));
  AOI21_X1   g135(.A1(new_n193_), .A2(new_n191_), .B(\dest_y[13] ), .ZN(new_n226_));
  AND3_X2    g136(.A1(new_n193_), .A2(new_n191_), .A3(\dest_y[13] ), .Z(new_n227_));
  NOR2_X1    g137(.A1(new_n227_), .A2(new_n226_), .ZN(new_n228_));
  XOR2_X1    g138(.A1(new_n193_), .A2(\dest_y[12] ), .Z(new_n229_));
  AND3_X2    g139(.A1(new_n225_), .A2(new_n228_), .A3(new_n229_), .Z(new_n230_));
  NAND2_X1   g140(.A1(new_n230_), .A2(new_n216_), .ZN(new_n231_));
  XOR2_X1    g141(.A1(new_n195_), .A2(new_n189_), .Z(new_n232_));
  NAND2_X1   g142(.A1(new_n194_), .A2(\dest_y[14] ), .ZN(new_n233_));
  XOR2_X1    g143(.A1(new_n233_), .A2(\dest_y[15] ), .Z(new_n234_));
  NOR4_X1    g144(.A1(new_n231_), .A2(new_n212_), .A3(new_n232_), .A4(new_n234_), .ZN(new_n235_));
  OAI21_X1   g145(.A1(new_n196_), .A2(\dest_y[18] ), .B(\dest_y[19] ), .ZN(new_n236_));
  AOI21_X1   g146(.A1(new_n198_), .A2(new_n236_), .B(new_n201_), .ZN(new_n237_));
  NAND4_X1   g147(.A1(new_n235_), .A2(new_n237_), .A3(new_n208_), .A4(new_n209_), .ZN(new_n238_));
  NAND3_X1   g148(.A1(new_n201_), .A2(\dest_y[23] ), .A3(\dest_y[24] ), .ZN(new_n239_));
  INV_X1     g149(.I(\dest_y[24] ), .ZN(new_n240_));
  NAND2_X1   g150(.A1(new_n201_), .A2(\dest_y[23] ), .ZN(new_n241_));
  NAND2_X1   g151(.A1(new_n241_), .A2(new_n240_), .ZN(new_n242_));
  NAND3_X1   g152(.A1(new_n242_), .A2(\dest_y[25] ), .A3(new_n239_), .ZN(new_n243_));
  NOR3_X1    g153(.A1(new_n243_), .A2(new_n238_), .A3(new_n202_), .ZN(new_n244_));
  INV_X1     g154(.I(\dest_y[26] ), .ZN(new_n245_));
  NAND4_X1   g155(.A1(new_n201_), .A2(\dest_y[23] ), .A3(\dest_y[24] ), .A4(\dest_y[25] ), .ZN(new_n246_));
  AOI21_X1   g156(.A1(new_n246_), .A2(new_n245_), .B(\dest_y[27] ), .ZN(new_n247_));
  AND3_X2    g157(.A1(new_n246_), .A2(new_n245_), .A3(\dest_y[27] ), .Z(new_n248_));
  NOR2_X1    g158(.A1(new_n248_), .A2(new_n247_), .ZN(new_n249_));
  INV_X1     g159(.I(new_n249_), .ZN(new_n250_));
  XOR2_X1    g160(.A1(new_n246_), .A2(\dest_y[26] ), .Z(new_n251_));
  INV_X1     g161(.I(\dest_y[28] ), .ZN(new_n252_));
  INV_X1     g162(.I(\dest_y[27] ), .ZN(new_n253_));
  AOI21_X1   g163(.A1(new_n246_), .A2(new_n245_), .B(new_n253_), .ZN(new_n254_));
  XOR2_X1    g164(.A1(new_n254_), .A2(new_n252_), .Z(new_n255_));
  INV_X1     g165(.I(new_n255_), .ZN(new_n256_));
  NAND4_X1   g166(.A1(new_n256_), .A2(new_n244_), .A3(new_n250_), .A4(new_n251_), .ZN(new_n257_));
  AND3_X2    g167(.A1(new_n254_), .A2(\dest_y[28] ), .A3(\dest_y[29] ), .Z(new_n258_));
  NAND2_X1   g168(.A1(new_n242_), .A2(new_n239_), .ZN(new_n259_));
  INV_X1     g169(.I(\dest_y[25] ), .ZN(new_n260_));
  XOR2_X1    g170(.A1(new_n239_), .A2(new_n260_), .Z(new_n261_));
  XOR2_X1    g171(.A1(new_n200_), .A2(new_n187_), .Z(new_n262_));
  INV_X1     g172(.I(\dest_y[9] ), .ZN(new_n263_));
  NOR4_X1    g173(.A1(new_n263_), .A2(\dest_y[7] ), .A3(\dest_y[8] ), .A4(\dest_y[10] ), .ZN(new_n264_));
  NOR4_X1    g174(.A1(\dest_y[3] ), .A2(\dest_y[4] ), .A3(\dest_y[5] ), .A4(\dest_y[6] ), .ZN(new_n265_));
  NOR2_X1    g175(.A1(\dest_y[1] ), .A2(\dest_y[2] ), .ZN(new_n266_));
  NAND4_X1   g176(.A1(new_n223_), .A2(new_n264_), .A3(new_n265_), .A4(new_n266_), .ZN(new_n267_));
  NOR4_X1    g177(.A1(new_n216_), .A2(new_n267_), .A3(new_n228_), .A4(new_n229_), .ZN(new_n268_));
  NAND4_X1   g178(.A1(new_n212_), .A2(new_n232_), .A3(new_n234_), .A4(new_n268_), .ZN(new_n269_));
  NAND2_X1   g179(.A1(new_n206_), .A2(new_n204_), .ZN(new_n270_));
  AOI22_X1   g180(.A1(new_n270_), .A2(new_n199_), .B1(new_n198_), .B2(new_n236_), .ZN(new_n271_));
  NOR4_X1    g181(.A1(new_n271_), .A2(new_n269_), .A3(new_n208_), .A4(new_n209_), .ZN(new_n272_));
  NAND2_X1   g182(.A1(new_n200_), .A2(new_n187_), .ZN(new_n273_));
  NAND2_X1   g183(.A1(new_n273_), .A2(new_n188_), .ZN(new_n274_));
  NAND3_X1   g184(.A1(new_n200_), .A2(new_n187_), .A3(\dest_y[22] ), .ZN(new_n275_));
  NAND2_X1   g185(.A1(new_n274_), .A2(new_n275_), .ZN(new_n276_));
  NAND4_X1   g186(.A1(new_n202_), .A2(new_n262_), .A3(new_n272_), .A4(new_n276_), .ZN(new_n277_));
  NOR3_X1    g187(.A1(new_n251_), .A2(new_n277_), .A3(new_n261_), .ZN(new_n278_));
  NAND4_X1   g188(.A1(new_n278_), .A2(new_n255_), .A3(new_n259_), .A4(new_n249_), .ZN(new_n279_));
  NAND2_X1   g189(.A1(new_n279_), .A2(new_n258_), .ZN(new_n280_));
  OAI21_X1   g190(.A1(\dest_x[0] ), .A2(\dest_y[0] ), .B(new_n258_), .ZN(new_n281_));
  NAND3_X1   g191(.A1(new_n280_), .A2(new_n257_), .A3(new_n281_), .ZN(new_n282_));
  INV_X1     g192(.I(new_n182_), .ZN(new_n283_));
  NOR4_X1    g193(.A1(new_n114_), .A2(new_n163_), .A3(new_n115_), .A4(new_n122_), .ZN(new_n284_));
  AOI21_X1   g194(.A1(new_n283_), .A2(new_n284_), .B(new_n160_), .ZN(new_n285_));
  INV_X1     g195(.I(\dest_x[0] ), .ZN(new_n286_));
  NOR2_X1    g196(.A1(new_n258_), .A2(new_n286_), .ZN(new_n287_));
  NOR3_X1    g197(.A1(new_n285_), .A2(new_n161_), .A3(new_n287_), .ZN(new_n288_));
  AOI21_X1   g198(.A1(new_n282_), .A2(new_n288_), .B(new_n159_), .ZN(\outport[1] ));
  AND2_X2    g199(.A1(\dest_x[0] ), .A2(\dest_y[0] ), .Z(new_n290_));
  OAI21_X1   g200(.A1(new_n279_), .A2(new_n290_), .B(new_n258_), .ZN(new_n291_));
  NOR3_X1    g201(.A1(new_n159_), .A2(new_n184_), .A3(new_n291_), .ZN(\outport[2] ));
  assign     \outport[3]  = 1'b0;
  assign     \outport[4]  = 1'b0;
  assign     \outport[5]  = 1'b0;
  assign     \outport[6]  = 1'b0;
  assign     \outport[7]  = 1'b0;
  assign     \outport[8]  = 1'b0;
  assign     \outport[9]  = 1'b0;
  assign     \outport[10]  = 1'b0;
  assign     \outport[11]  = 1'b0;
  assign     \outport[12]  = 1'b0;
  assign     \outport[13]  = 1'b0;
  assign     \outport[14]  = 1'b0;
  assign     \outport[15]  = 1'b0;
  assign     \outport[16]  = 1'b0;
  assign     \outport[17]  = 1'b0;
  assign     \outport[18]  = 1'b0;
  assign     \outport[19]  = 1'b0;
  assign     \outport[20]  = 1'b0;
  assign     \outport[21]  = 1'b0;
  assign     \outport[22]  = 1'b0;
  assign     \outport[23]  = 1'b0;
  assign     \outport[24]  = 1'b0;
  assign     \outport[25]  = 1'b0;
  assign     \outport[26]  = 1'b0;
  assign     \outport[27]  = 1'b0;
  assign     \outport[28]  = 1'b0;
  assign     \outport[29]  = 1'b0;
endmodule


