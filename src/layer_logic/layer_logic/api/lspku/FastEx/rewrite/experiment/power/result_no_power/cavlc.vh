// Benchmark "cavlc" written by ABC on Mon Sep 11 23:40:16 2023

module cavlc ( 
    \totalcoeffs[0] , \totalcoeffs[1] , \totalcoeffs[2] , \totalcoeffs[3] ,
    \totalcoeffs[4] , \ctable[0] , \ctable[1] , \ctable[2] ,
    \trailingones[0] , \trailingones[1] ,
    \coeff_token[0] , \coeff_token[1] , \coeff_token[2] , \coeff_token[3] ,
    \coeff_token[4] , \coeff_token[5] , \ctoken_len[0] , \ctoken_len[1] ,
    \ctoken_len[2] , \ctoken_len[3] , \ctoken_len[4]   );
  input  \totalcoeffs[0] , \totalcoeffs[1] , \totalcoeffs[2] ,
    \totalcoeffs[3] , \totalcoeffs[4] , \ctable[0] , \ctable[1] ,
    \ctable[2] , \trailingones[0] , \trailingones[1] ;
  output \coeff_token[0] , \coeff_token[1] , \coeff_token[2] ,
    \coeff_token[3] , \coeff_token[4] , \coeff_token[5] , \ctoken_len[0] ,
    \ctoken_len[1] , \ctoken_len[2] , \ctoken_len[3] , \ctoken_len[4] ;
  wire new_n22_, new_n23_, new_n24_, new_n25_, new_n26_, new_n27_, new_n28_,
    new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_,
    new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_,
    new_n78_, new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n84_,
    new_n85_, new_n86_, new_n87_, new_n88_, new_n89_, new_n90_, new_n91_,
    new_n92_, new_n93_, new_n94_, new_n95_, new_n96_, new_n97_, new_n98_,
    new_n99_, new_n100_, new_n101_, new_n102_, new_n103_, new_n104_,
    new_n105_, new_n106_, new_n107_, new_n108_, new_n109_, new_n110_,
    new_n111_, new_n112_, new_n113_, new_n114_, new_n115_, new_n116_,
    new_n117_, new_n118_, new_n119_, new_n120_, new_n121_, new_n123_,
    new_n124_, new_n125_, new_n126_, new_n127_, new_n128_, new_n129_,
    new_n130_, new_n131_, new_n132_, new_n133_, new_n134_, new_n135_,
    new_n136_, new_n137_, new_n138_, new_n139_, new_n140_, new_n141_,
    new_n142_, new_n143_, new_n144_, new_n145_, new_n146_, new_n147_,
    new_n148_, new_n149_, new_n150_, new_n151_, new_n152_, new_n153_,
    new_n154_, new_n155_, new_n156_, new_n157_, new_n158_, new_n159_,
    new_n160_, new_n161_, new_n162_, new_n163_, new_n164_, new_n165_,
    new_n166_, new_n167_, new_n168_, new_n169_, new_n170_, new_n171_,
    new_n172_, new_n173_, new_n174_, new_n175_, new_n176_, new_n177_,
    new_n178_, new_n179_, new_n180_, new_n181_, new_n182_, new_n183_,
    new_n184_, new_n185_, new_n186_, new_n187_, new_n188_, new_n189_,
    new_n190_, new_n191_, new_n192_, new_n193_, new_n194_, new_n195_,
    new_n196_, new_n197_, new_n198_, new_n199_, new_n200_, new_n201_,
    new_n202_, new_n203_, new_n204_, new_n205_, new_n206_, new_n207_,
    new_n208_, new_n209_, new_n210_, new_n211_, new_n212_, new_n214_,
    new_n215_, new_n216_, new_n217_, new_n218_, new_n219_, new_n220_,
    new_n221_, new_n222_, new_n223_, new_n224_, new_n225_, new_n226_,
    new_n227_, new_n228_, new_n229_, new_n230_, new_n231_, new_n232_,
    new_n233_, new_n234_, new_n235_, new_n236_, new_n237_, new_n238_,
    new_n239_, new_n240_, new_n241_, new_n242_, new_n243_, new_n244_,
    new_n245_, new_n246_, new_n247_, new_n249_, new_n250_, new_n251_,
    new_n252_, new_n253_, new_n254_, new_n255_, new_n256_, new_n257_,
    new_n258_, new_n259_, new_n260_, new_n261_, new_n262_, new_n263_,
    new_n264_, new_n265_, new_n266_, new_n267_, new_n268_, new_n269_,
    new_n270_, new_n271_, new_n272_, new_n273_, new_n274_, new_n275_,
    new_n276_, new_n278_, new_n279_, new_n280_, new_n281_, new_n282_,
    new_n283_, new_n284_, new_n285_, new_n286_, new_n287_, new_n288_,
    new_n289_, new_n290_, new_n291_, new_n292_, new_n293_, new_n294_,
    new_n295_, new_n296_, new_n297_, new_n298_, new_n299_, new_n300_,
    new_n301_, new_n302_, new_n303_, new_n304_, new_n305_, new_n306_,
    new_n307_, new_n308_, new_n309_, new_n310_, new_n311_, new_n312_,
    new_n313_, new_n314_, new_n315_, new_n316_, new_n317_, new_n318_,
    new_n319_, new_n320_, new_n321_, new_n322_, new_n323_, new_n324_,
    new_n325_, new_n326_, new_n327_, new_n329_, new_n330_, new_n331_,
    new_n332_, new_n333_, new_n334_, new_n335_, new_n337_, new_n338_,
    new_n339_, new_n341_, new_n342_, new_n343_, new_n344_, new_n345_,
    new_n346_, new_n347_, new_n348_, new_n349_, new_n350_, new_n351_,
    new_n352_, new_n353_, new_n354_, new_n355_, new_n356_, new_n357_,
    new_n358_, new_n359_, new_n360_, new_n361_, new_n362_, new_n363_,
    new_n364_, new_n365_, new_n366_, new_n367_, new_n368_, new_n369_,
    new_n370_, new_n371_, new_n372_, new_n373_, new_n374_, new_n375_,
    new_n376_, new_n377_, new_n378_, new_n379_, new_n380_, new_n381_,
    new_n382_, new_n383_, new_n384_, new_n385_, new_n386_, new_n387_,
    new_n388_, new_n389_, new_n390_, new_n391_, new_n392_, new_n394_,
    new_n395_, new_n396_, new_n397_, new_n398_, new_n399_, new_n400_,
    new_n401_, new_n402_, new_n403_, new_n404_, new_n405_, new_n406_,
    new_n407_, new_n408_, new_n409_, new_n410_, new_n411_, new_n412_,
    new_n413_, new_n414_, new_n415_, new_n416_, new_n417_, new_n418_,
    new_n419_, new_n420_, new_n421_, new_n422_, new_n423_, new_n424_,
    new_n425_, new_n426_, new_n427_, new_n429_, new_n430_, new_n431_,
    new_n432_, new_n433_, new_n434_, new_n435_, new_n436_, new_n437_,
    new_n438_, new_n439_, new_n440_, new_n441_, new_n442_, new_n443_,
    new_n444_, new_n445_, new_n446_, new_n447_, new_n448_, new_n449_,
    new_n451_, new_n452_, new_n453_, new_n454_, new_n455_, new_n456_,
    new_n457_, new_n458_, new_n459_, new_n460_, new_n461_, new_n462_,
    new_n463_, new_n464_, new_n465_, new_n466_, new_n467_, new_n468_,
    new_n469_, new_n470_, new_n471_, new_n472_, new_n473_, new_n474_,
    new_n475_, new_n476_, new_n477_, new_n478_, new_n479_, new_n480_,
    new_n481_, new_n482_, new_n483_, new_n484_, new_n485_, new_n486_,
    new_n487_, new_n488_, new_n489_, new_n490_, new_n491_, new_n492_,
    new_n493_, new_n495_, new_n496_, new_n497_, new_n498_, new_n499_,
    new_n500_, new_n501_, new_n502_, new_n503_, new_n504_, new_n505_,
    new_n506_, new_n507_, new_n508_, new_n509_, new_n510_, new_n511_,
    new_n512_, new_n513_, new_n514_, new_n515_, new_n516_, new_n517_,
    new_n518_, new_n519_, new_n520_, new_n521_, new_n523_, new_n524_,
    new_n525_, new_n526_;
  INV_X1     g000(.I(\ctable[1] ), .ZN(new_n22_));
  NAND3_X1   g001(.A1(new_n22_), .A2(\totalcoeffs[4] ), .A3(\trailingones[1] ), .ZN(new_n23_));
  INV_X1     g002(.I(\trailingones[1] ), .ZN(new_n24_));
  OAI21_X1   g003(.A1(new_n24_), .A2(\totalcoeffs[4] ), .B(\ctable[1] ), .ZN(new_n25_));
  NAND2_X1   g004(.A1(new_n25_), .A2(new_n23_), .ZN(new_n26_));
  INV_X1     g005(.I(\ctable[0] ), .ZN(new_n27_));
  NOR2_X1    g006(.A1(new_n27_), .A2(new_n22_), .ZN(new_n28_));
  NOR2_X1    g007(.A1(new_n28_), .A2(\trailingones[0] ), .ZN(new_n29_));
  NAND3_X1   g008(.A1(new_n22_), .A2(\totalcoeffs[4] ), .A3(\trailingones[1] ), .ZN(new_n30_));
  AOI21_X1   g009(.A1(new_n22_), .A2(new_n24_), .B(\totalcoeffs[4] ), .ZN(new_n31_));
  INV_X1     g010(.I(\trailingones[0] ), .ZN(new_n32_));
  NOR2_X1    g011(.A1(new_n32_), .A2(\ctable[1] ), .ZN(new_n33_));
  NAND2_X1   g012(.A1(new_n32_), .A2(\ctable[1] ), .ZN(new_n34_));
  NAND2_X1   g013(.A1(new_n34_), .A2(\ctable[0] ), .ZN(new_n35_));
  NOR3_X1    g014(.A1(new_n35_), .A2(new_n31_), .A3(new_n33_), .ZN(new_n36_));
  AOI22_X1   g015(.A1(new_n36_), .A2(new_n30_), .B1(new_n26_), .B2(new_n29_), .ZN(new_n37_));
  INV_X1     g016(.I(\totalcoeffs[0] ), .ZN(new_n38_));
  INV_X1     g017(.I(\ctable[2] ), .ZN(new_n39_));
  NOR2_X1    g018(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .ZN(new_n40_));
  INV_X1     g019(.I(new_n40_), .ZN(new_n41_));
  NOR2_X1    g020(.A1(new_n41_), .A2(\totalcoeffs[3] ), .ZN(new_n42_));
  NAND3_X1   g021(.A1(new_n42_), .A2(new_n38_), .A3(new_n39_), .ZN(new_n43_));
  INV_X1     g022(.I(\totalcoeffs[1] ), .ZN(new_n44_));
  NAND2_X1   g023(.A1(new_n27_), .A2(\trailingones[0] ), .ZN(new_n45_));
  AOI21_X1   g024(.A1(new_n39_), .A2(new_n24_), .B(new_n45_), .ZN(new_n46_));
  NOR2_X1    g025(.A1(new_n32_), .A2(\ctable[0] ), .ZN(new_n47_));
  NOR3_X1    g026(.A1(new_n47_), .A2(\ctable[2] ), .A3(new_n24_), .ZN(new_n48_));
  NOR3_X1    g027(.A1(new_n46_), .A2(new_n48_), .A3(new_n44_), .ZN(new_n49_));
  INV_X1     g028(.I(\totalcoeffs[2] ), .ZN(new_n50_));
  NOR2_X1    g029(.A1(\ctable[0] ), .A2(\trailingones[1] ), .ZN(new_n51_));
  NAND2_X1   g030(.A1(new_n39_), .A2(\totalcoeffs[1] ), .ZN(new_n52_));
  OAI21_X1   g031(.A1(new_n52_), .A2(new_n51_), .B(new_n50_), .ZN(new_n53_));
  OAI21_X1   g032(.A1(new_n49_), .A2(new_n53_), .B(new_n38_), .ZN(new_n54_));
  NAND2_X1   g033(.A1(new_n24_), .A2(\totalcoeffs[2] ), .ZN(new_n55_));
  NAND2_X1   g034(.A1(new_n38_), .A2(new_n44_), .ZN(new_n56_));
  NOR2_X1    g035(.A1(new_n56_), .A2(new_n55_), .ZN(new_n57_));
  NOR2_X1    g036(.A1(new_n45_), .A2(new_n39_), .ZN(new_n58_));
  AOI21_X1   g037(.A1(new_n57_), .A2(new_n58_), .B(\totalcoeffs[3] ), .ZN(new_n59_));
  INV_X1     g038(.I(\totalcoeffs[3] ), .ZN(new_n60_));
  NAND2_X1   g039(.A1(new_n60_), .A2(new_n27_), .ZN(new_n61_));
  NOR2_X1    g040(.A1(new_n38_), .A2(new_n44_), .ZN(new_n62_));
  NOR2_X1    g041(.A1(new_n24_), .A2(\totalcoeffs[1] ), .ZN(new_n63_));
  NOR2_X1    g042(.A1(new_n44_), .A2(\trailingones[1] ), .ZN(new_n64_));
  NOR2_X1    g043(.A1(new_n63_), .A2(new_n64_), .ZN(new_n65_));
  AOI21_X1   g044(.A1(new_n61_), .A2(new_n62_), .B(new_n65_), .ZN(new_n66_));
  NAND2_X1   g045(.A1(new_n38_), .A2(new_n24_), .ZN(new_n67_));
  AND3_X2    g046(.A1(new_n65_), .A2(new_n39_), .A3(new_n67_), .Z(new_n68_));
  OAI21_X1   g047(.A1(new_n68_), .A2(new_n66_), .B(new_n50_), .ZN(new_n69_));
  NAND2_X1   g048(.A1(new_n67_), .A2(\totalcoeffs[3] ), .ZN(new_n70_));
  NAND2_X1   g049(.A1(\totalcoeffs[2] ), .A2(\trailingones[1] ), .ZN(new_n71_));
  NAND3_X1   g050(.A1(new_n70_), .A2(new_n44_), .A3(new_n71_), .ZN(new_n72_));
  NOR2_X1    g051(.A1(new_n44_), .A2(\totalcoeffs[3] ), .ZN(new_n73_));
  OAI21_X1   g052(.A1(\totalcoeffs[2] ), .A2(\ctable[0] ), .B(new_n38_), .ZN(new_n74_));
  AOI21_X1   g053(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .B(\trailingones[1] ), .ZN(new_n75_));
  AOI21_X1   g054(.A1(new_n74_), .A2(new_n75_), .B(new_n73_), .ZN(new_n76_));
  NAND2_X1   g055(.A1(new_n39_), .A2(new_n32_), .ZN(new_n77_));
  AOI21_X1   g056(.A1(new_n72_), .A2(new_n76_), .B(new_n77_), .ZN(new_n78_));
  AOI22_X1   g057(.A1(new_n69_), .A2(new_n78_), .B1(new_n54_), .B2(new_n59_), .ZN(new_n79_));
  NOR2_X1    g058(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n80_));
  NAND2_X1   g059(.A1(new_n80_), .A2(new_n24_), .ZN(new_n81_));
  INV_X1     g060(.I(new_n81_), .ZN(new_n82_));
  NOR2_X1    g061(.A1(\totalcoeffs[2] ), .A2(\totalcoeffs[3] ), .ZN(new_n83_));
  NAND3_X1   g062(.A1(new_n82_), .A2(new_n38_), .A3(new_n83_), .ZN(new_n84_));
  NAND3_X1   g063(.A1(new_n60_), .A2(\totalcoeffs[2] ), .A3(\trailingones[1] ), .ZN(new_n85_));
  NAND2_X1   g064(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n86_));
  INV_X1     g065(.I(new_n86_), .ZN(new_n87_));
  AOI21_X1   g066(.A1(new_n85_), .A2(new_n44_), .B(new_n87_), .ZN(new_n88_));
  NAND2_X1   g067(.A1(new_n85_), .A2(new_n44_), .ZN(new_n89_));
  OAI21_X1   g068(.A1(new_n89_), .A2(new_n86_), .B(new_n38_), .ZN(new_n90_));
  NOR2_X1    g069(.A1(new_n90_), .A2(new_n88_), .ZN(new_n91_));
  OAI21_X1   g070(.A1(new_n22_), .A2(\totalcoeffs[2] ), .B(\totalcoeffs[3] ), .ZN(new_n92_));
  NAND2_X1   g071(.A1(new_n44_), .A2(new_n24_), .ZN(new_n93_));
  NOR2_X1    g072(.A1(new_n93_), .A2(new_n71_), .ZN(new_n94_));
  AOI21_X1   g073(.A1(new_n94_), .A2(new_n92_), .B(\trailingones[0] ), .ZN(new_n95_));
  OAI21_X1   g074(.A1(new_n91_), .A2(new_n95_), .B(new_n27_), .ZN(new_n96_));
  NOR4_X1    g075(.A1(new_n40_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[3] ), .A4(new_n22_), .ZN(new_n97_));
  NAND2_X1   g076(.A1(new_n50_), .A2(\trailingones[1] ), .ZN(new_n98_));
  AOI21_X1   g077(.A1(new_n55_), .A2(new_n98_), .B(new_n97_), .ZN(new_n99_));
  NOR2_X1    g078(.A1(new_n38_), .A2(\trailingones[1] ), .ZN(new_n100_));
  OAI21_X1   g079(.A1(new_n100_), .A2(\totalcoeffs[2] ), .B(\ctable[1] ), .ZN(new_n101_));
  NAND2_X1   g080(.A1(\totalcoeffs[0] ), .A2(\trailingones[1] ), .ZN(new_n102_));
  AOI21_X1   g081(.A1(new_n67_), .A2(new_n102_), .B(new_n44_), .ZN(new_n103_));
  NAND2_X1   g082(.A1(new_n103_), .A2(new_n83_), .ZN(new_n104_));
  AOI21_X1   g083(.A1(new_n104_), .A2(new_n101_), .B(new_n27_), .ZN(new_n105_));
  OAI21_X1   g084(.A1(new_n105_), .A2(new_n99_), .B(\trailingones[0] ), .ZN(new_n106_));
  NOR2_X1    g085(.A1(new_n50_), .A2(new_n27_), .ZN(new_n107_));
  INV_X1     g086(.I(new_n63_), .ZN(new_n108_));
  NOR2_X1    g087(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .ZN(new_n109_));
  INV_X1     g088(.I(new_n109_), .ZN(new_n110_));
  NAND2_X1   g089(.A1(new_n108_), .A2(new_n110_), .ZN(new_n111_));
  NOR2_X1    g090(.A1(new_n22_), .A2(\ctable[0] ), .ZN(new_n112_));
  AOI22_X1   g091(.A1(new_n111_), .A2(new_n112_), .B1(new_n103_), .B2(new_n107_), .ZN(new_n113_));
  NOR2_X1    g092(.A1(new_n24_), .A2(\totalcoeffs[0] ), .ZN(new_n114_));
  OAI21_X1   g093(.A1(new_n114_), .A2(\totalcoeffs[1] ), .B(new_n32_), .ZN(new_n115_));
  NOR2_X1    g094(.A1(new_n50_), .A2(\totalcoeffs[1] ), .ZN(new_n116_));
  AOI21_X1   g095(.A1(new_n100_), .A2(new_n116_), .B(\ctable[0] ), .ZN(new_n117_));
  AOI21_X1   g096(.A1(new_n117_), .A2(new_n115_), .B(\totalcoeffs[3] ), .ZN(new_n118_));
  OAI21_X1   g097(.A1(new_n113_), .A2(new_n32_), .B(new_n118_), .ZN(new_n119_));
  AOI22_X1   g098(.A1(new_n106_), .A2(new_n119_), .B1(new_n96_), .B2(new_n84_), .ZN(new_n120_));
  NOR4_X1    g099(.A1(new_n120_), .A2(\ctable[1] ), .A3(\ctable[2] ), .A4(new_n79_), .ZN(new_n121_));
  OAI22_X1   g100(.A1(new_n121_), .A2(\totalcoeffs[4] ), .B1(new_n37_), .B2(new_n43_), .ZN(\coeff_token[0] ));
  NOR2_X1    g101(.A1(new_n32_), .A2(\totalcoeffs[2] ), .ZN(new_n123_));
  NAND2_X1   g102(.A1(new_n64_), .A2(new_n123_), .ZN(new_n124_));
  NAND2_X1   g103(.A1(new_n56_), .A2(\totalcoeffs[2] ), .ZN(new_n125_));
  NAND2_X1   g104(.A1(new_n63_), .A2(new_n38_), .ZN(new_n126_));
  NAND4_X1   g105(.A1(new_n125_), .A2(new_n126_), .A3(new_n50_), .A4(new_n32_), .ZN(new_n127_));
  AOI21_X1   g106(.A1(new_n127_), .A2(new_n124_), .B(new_n39_), .ZN(new_n128_));
  NOR3_X1    g107(.A1(new_n61_), .A2(\totalcoeffs[4] ), .A3(\ctable[1] ), .ZN(new_n129_));
  OAI21_X1   g108(.A1(new_n128_), .A2(new_n57_), .B(new_n129_), .ZN(new_n130_));
  NOR3_X1    g109(.A1(new_n55_), .A2(\ctable[1] ), .A3(new_n32_), .ZN(new_n131_));
  NOR2_X1    g110(.A1(new_n22_), .A2(new_n32_), .ZN(new_n132_));
  NOR2_X1    g111(.A1(new_n22_), .A2(new_n24_), .ZN(new_n133_));
  NOR3_X1    g112(.A1(new_n132_), .A2(new_n133_), .A3(new_n47_), .ZN(new_n134_));
  NOR2_X1    g113(.A1(new_n27_), .A2(\totalcoeffs[0] ), .ZN(new_n135_));
  NOR2_X1    g114(.A1(new_n24_), .A2(\trailingones[0] ), .ZN(new_n136_));
  AOI21_X1   g115(.A1(new_n135_), .A2(new_n136_), .B(\totalcoeffs[2] ), .ZN(new_n137_));
  OAI21_X1   g116(.A1(new_n134_), .A2(\totalcoeffs[0] ), .B(new_n137_), .ZN(new_n138_));
  NAND2_X1   g117(.A1(new_n38_), .A2(\ctable[1] ), .ZN(new_n139_));
  AOI21_X1   g118(.A1(new_n139_), .A2(new_n50_), .B(\ctable[0] ), .ZN(new_n140_));
  AOI21_X1   g119(.A1(new_n140_), .A2(\trailingones[0] ), .B(new_n22_), .ZN(new_n141_));
  NOR2_X1    g120(.A1(new_n22_), .A2(\totalcoeffs[0] ), .ZN(new_n142_));
  OAI21_X1   g121(.A1(new_n142_), .A2(\totalcoeffs[2] ), .B(new_n27_), .ZN(new_n143_));
  NAND3_X1   g122(.A1(new_n143_), .A2(new_n22_), .A3(\trailingones[0] ), .ZN(new_n144_));
  NAND2_X1   g123(.A1(new_n144_), .A2(new_n24_), .ZN(new_n145_));
  OAI21_X1   g124(.A1(new_n145_), .A2(new_n141_), .B(new_n138_), .ZN(new_n146_));
  AOI21_X1   g125(.A1(new_n146_), .A2(\totalcoeffs[1] ), .B(new_n131_), .ZN(new_n147_));
  NAND2_X1   g126(.A1(new_n24_), .A2(\ctable[1] ), .ZN(new_n148_));
  NAND2_X1   g127(.A1(new_n27_), .A2(new_n32_), .ZN(new_n149_));
  INV_X1     g128(.I(\totalcoeffs[4] ), .ZN(new_n150_));
  AOI21_X1   g129(.A1(new_n150_), .A2(\trailingones[0] ), .B(\ctable[1] ), .ZN(new_n151_));
  AOI22_X1   g130(.A1(new_n151_), .A2(new_n149_), .B1(\totalcoeffs[4] ), .B2(\trailingones[1] ), .ZN(new_n152_));
  AOI21_X1   g131(.A1(new_n109_), .A2(new_n148_), .B(new_n152_), .ZN(new_n153_));
  NAND2_X1   g132(.A1(new_n32_), .A2(\trailingones[1] ), .ZN(new_n154_));
  NAND3_X1   g133(.A1(new_n24_), .A2(\ctable[0] ), .A3(\ctable[1] ), .ZN(new_n155_));
  NAND2_X1   g134(.A1(new_n24_), .A2(\trailingones[0] ), .ZN(new_n156_));
  OAI21_X1   g135(.A1(\ctable[0] ), .A2(\trailingones[1] ), .B(new_n22_), .ZN(new_n157_));
  NAND4_X1   g136(.A1(new_n157_), .A2(new_n154_), .A3(new_n155_), .A4(new_n156_), .ZN(new_n158_));
  AOI22_X1   g137(.A1(new_n27_), .A2(\trailingones[0] ), .B1(\ctable[1] ), .B2(\trailingones[1] ), .ZN(new_n159_));
  AOI21_X1   g138(.A1(new_n159_), .A2(new_n38_), .B(\totalcoeffs[2] ), .ZN(new_n160_));
  NAND2_X1   g139(.A1(new_n158_), .A2(new_n160_), .ZN(new_n161_));
  NOR2_X1    g140(.A1(new_n32_), .A2(\trailingones[1] ), .ZN(new_n162_));
  NOR2_X1    g141(.A1(new_n136_), .A2(new_n162_), .ZN(new_n163_));
  NOR2_X1    g142(.A1(new_n50_), .A2(\trailingones[0] ), .ZN(new_n164_));
  NOR2_X1    g143(.A1(new_n123_), .A2(new_n164_), .ZN(new_n165_));
  NOR2_X1    g144(.A1(new_n50_), .A2(\totalcoeffs[0] ), .ZN(new_n166_));
  NOR2_X1    g145(.A1(new_n38_), .A2(\totalcoeffs[2] ), .ZN(new_n167_));
  NOR2_X1    g146(.A1(new_n166_), .A2(new_n167_), .ZN(new_n168_));
  NAND4_X1   g147(.A1(new_n163_), .A2(new_n165_), .A3(new_n168_), .A4(\ctable[0] ), .ZN(new_n169_));
  AOI21_X1   g148(.A1(new_n161_), .A2(new_n169_), .B(\totalcoeffs[4] ), .ZN(new_n170_));
  OAI21_X1   g149(.A1(new_n170_), .A2(new_n153_), .B(new_n44_), .ZN(new_n171_));
  OAI21_X1   g150(.A1(new_n147_), .A2(\totalcoeffs[4] ), .B(new_n171_), .ZN(new_n172_));
  NAND2_X1   g151(.A1(new_n32_), .A2(\totalcoeffs[2] ), .ZN(new_n173_));
  NOR2_X1    g152(.A1(new_n173_), .A2(new_n27_), .ZN(new_n174_));
  NAND2_X1   g153(.A1(new_n38_), .A2(\ctable[0] ), .ZN(new_n175_));
  NAND2_X1   g154(.A1(new_n27_), .A2(\totalcoeffs[0] ), .ZN(new_n176_));
  NAND3_X1   g155(.A1(new_n175_), .A2(new_n176_), .A3(\totalcoeffs[1] ), .ZN(new_n177_));
  OAI21_X1   g156(.A1(new_n60_), .A2(new_n32_), .B(new_n50_), .ZN(new_n178_));
  NAND2_X1   g157(.A1(new_n178_), .A2(new_n38_), .ZN(new_n179_));
  OAI21_X1   g158(.A1(new_n174_), .A2(new_n177_), .B(new_n179_), .ZN(new_n180_));
  NAND3_X1   g159(.A1(new_n50_), .A2(new_n32_), .A3(\ctable[0] ), .ZN(new_n181_));
  NOR2_X1    g160(.A1(new_n32_), .A2(\totalcoeffs[3] ), .ZN(new_n182_));
  NOR2_X1    g161(.A1(new_n27_), .A2(new_n32_), .ZN(new_n183_));
  OAI21_X1   g162(.A1(new_n183_), .A2(new_n182_), .B(\totalcoeffs[0] ), .ZN(new_n184_));
  AOI21_X1   g163(.A1(new_n184_), .A2(new_n181_), .B(\totalcoeffs[1] ), .ZN(new_n185_));
  AOI21_X1   g164(.A1(new_n180_), .A2(new_n185_), .B(\ctable[1] ), .ZN(new_n186_));
  NAND2_X1   g165(.A1(new_n38_), .A2(\trailingones[0] ), .ZN(new_n187_));
  NAND2_X1   g166(.A1(new_n187_), .A2(new_n50_), .ZN(new_n188_));
  NOR2_X1    g167(.A1(new_n22_), .A2(\totalcoeffs[1] ), .ZN(new_n189_));
  NOR2_X1    g168(.A1(new_n44_), .A2(\totalcoeffs[0] ), .ZN(new_n190_));
  NOR2_X1    g169(.A1(new_n189_), .A2(new_n190_), .ZN(new_n191_));
  NOR2_X1    g170(.A1(new_n80_), .A2(new_n60_), .ZN(new_n192_));
  NAND2_X1   g171(.A1(new_n189_), .A2(new_n50_), .ZN(new_n193_));
  OAI21_X1   g172(.A1(new_n193_), .A2(new_n192_), .B(new_n27_), .ZN(new_n194_));
  AOI21_X1   g173(.A1(new_n188_), .A2(new_n191_), .B(new_n194_), .ZN(new_n195_));
  OAI21_X1   g174(.A1(new_n186_), .A2(new_n195_), .B(\trailingones[1] ), .ZN(new_n196_));
  NAND2_X1   g175(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .ZN(new_n197_));
  NAND2_X1   g176(.A1(\totalcoeffs[3] ), .A2(\ctable[0] ), .ZN(new_n198_));
  NOR3_X1    g177(.A1(new_n197_), .A2(new_n198_), .A3(\trailingones[0] ), .ZN(new_n199_));
  AOI21_X1   g178(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .B(\ctable[0] ), .ZN(new_n200_));
  NOR2_X1    g179(.A1(new_n60_), .A2(\trailingones[0] ), .ZN(new_n201_));
  NAND2_X1   g180(.A1(new_n201_), .A2(new_n40_), .ZN(new_n202_));
  NOR2_X1    g181(.A1(new_n44_), .A2(new_n27_), .ZN(new_n203_));
  INV_X1     g182(.I(new_n203_), .ZN(new_n204_));
  AOI21_X1   g183(.A1(new_n202_), .A2(new_n204_), .B(new_n38_), .ZN(new_n205_));
  NAND2_X1   g184(.A1(new_n27_), .A2(\totalcoeffs[2] ), .ZN(new_n206_));
  NAND2_X1   g185(.A1(new_n50_), .A2(\ctable[0] ), .ZN(new_n207_));
  AOI21_X1   g186(.A1(new_n206_), .A2(new_n207_), .B(\totalcoeffs[3] ), .ZN(new_n208_));
  NOR4_X1    g187(.A1(new_n205_), .A2(\ctable[1] ), .A3(new_n208_), .A4(new_n200_), .ZN(new_n209_));
  OAI21_X1   g188(.A1(new_n209_), .A2(new_n199_), .B(\trailingones[1] ), .ZN(new_n210_));
  NAND3_X1   g189(.A1(new_n196_), .A2(new_n150_), .A3(new_n210_), .ZN(new_n211_));
  AOI21_X1   g190(.A1(new_n172_), .A2(new_n60_), .B(new_n211_), .ZN(new_n212_));
  OAI21_X1   g191(.A1(new_n212_), .A2(\ctable[2] ), .B(new_n130_), .ZN(\coeff_token[1] ));
  INV_X1     g192(.I(new_n80_), .ZN(new_n214_));
  INV_X1     g193(.I(new_n100_), .ZN(new_n215_));
  NOR2_X1    g194(.A1(new_n215_), .A2(new_n214_), .ZN(new_n216_));
  NOR3_X1    g195(.A1(new_n39_), .A2(new_n32_), .A3(\trailingones[1] ), .ZN(new_n217_));
  NAND2_X1   g196(.A1(new_n38_), .A2(\trailingones[1] ), .ZN(new_n218_));
  NAND2_X1   g197(.A1(new_n215_), .A2(new_n218_), .ZN(new_n219_));
  NOR3_X1    g198(.A1(new_n219_), .A2(new_n44_), .A3(new_n217_), .ZN(new_n220_));
  INV_X1     g199(.I(new_n83_), .ZN(new_n221_));
  NOR2_X1    g200(.A1(\ctable[0] ), .A2(\ctable[1] ), .ZN(new_n222_));
  INV_X1     g201(.I(new_n222_), .ZN(new_n223_));
  NOR3_X1    g202(.A1(new_n223_), .A2(new_n221_), .A3(\totalcoeffs[4] ), .ZN(new_n224_));
  OAI21_X1   g203(.A1(new_n220_), .A2(new_n216_), .B(new_n224_), .ZN(new_n225_));
  NAND3_X1   g204(.A1(new_n163_), .A2(new_n50_), .A3(new_n93_), .ZN(new_n226_));
  NAND2_X1   g205(.A1(new_n71_), .A2(new_n27_), .ZN(new_n227_));
  NAND3_X1   g206(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .A3(\trailingones[1] ), .ZN(new_n228_));
  NOR2_X1    g207(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n229_));
  NOR2_X1    g208(.A1(new_n229_), .A2(new_n27_), .ZN(new_n230_));
  NAND2_X1   g209(.A1(new_n230_), .A2(new_n228_), .ZN(new_n231_));
  NAND2_X1   g210(.A1(new_n231_), .A2(new_n227_), .ZN(new_n232_));
  NAND4_X1   g211(.A1(new_n230_), .A2(new_n27_), .A3(new_n71_), .A4(new_n228_), .ZN(new_n233_));
  NAND3_X1   g212(.A1(new_n232_), .A2(\totalcoeffs[1] ), .A3(new_n233_), .ZN(new_n234_));
  AOI21_X1   g213(.A1(new_n234_), .A2(new_n226_), .B(\totalcoeffs[3] ), .ZN(new_n235_));
  OAI21_X1   g214(.A1(new_n60_), .A2(\totalcoeffs[1] ), .B(\ctable[0] ), .ZN(new_n236_));
  AOI21_X1   g215(.A1(new_n236_), .A2(new_n50_), .B(new_n229_), .ZN(new_n237_));
  NOR3_X1    g216(.A1(new_n108_), .A2(new_n32_), .A3(new_n83_), .ZN(new_n238_));
  NOR3_X1    g217(.A1(new_n238_), .A2(new_n38_), .A3(new_n237_), .ZN(new_n239_));
  OAI21_X1   g218(.A1(new_n235_), .A2(new_n239_), .B(new_n22_), .ZN(new_n240_));
  INV_X1     g219(.I(new_n176_), .ZN(new_n241_));
  XOR2_X1    g220(.A1(new_n55_), .A2(\trailingones[0] ), .Z(new_n242_));
  INV_X1     g221(.I(new_n71_), .ZN(new_n243_));
  OAI21_X1   g222(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .B(new_n243_), .ZN(new_n244_));
  NAND3_X1   g223(.A1(new_n71_), .A2(new_n44_), .A3(\trailingones[0] ), .ZN(new_n245_));
  NAND3_X1   g224(.A1(new_n244_), .A2(\ctable[1] ), .A3(new_n245_), .ZN(new_n246_));
  AOI21_X1   g225(.A1(new_n246_), .A2(new_n242_), .B(new_n60_), .ZN(new_n247_));
  AND4_X2    g226(.A1(new_n50_), .A2(new_n65_), .A3(new_n60_), .A4(new_n32_), .Z(new_n249_));
  OAI21_X1   g227(.A1(new_n247_), .A2(new_n249_), .B(new_n241_), .ZN(new_n250_));
  AOI21_X1   g228(.A1(new_n240_), .A2(new_n250_), .B(\totalcoeffs[4] ), .ZN(new_n251_));
  MUX2_X1    g229(.I0(\ctable[1] ), .I1(\trailingones[1] ), .S(\trailingones[0] ), .Z(new_n252_));
  NOR2_X1    g230(.A1(new_n150_), .A2(\totalcoeffs[3] ), .ZN(new_n253_));
  NAND2_X1   g231(.A1(new_n253_), .A2(new_n40_), .ZN(new_n254_));
  AOI21_X1   g232(.A1(new_n27_), .A2(new_n252_), .B(new_n254_), .ZN(new_n255_));
  INV_X1     g233(.I(new_n112_), .ZN(new_n256_));
  NOR3_X1    g234(.A1(new_n256_), .A2(\totalcoeffs[3] ), .A3(new_n214_), .ZN(new_n257_));
  NOR2_X1    g235(.A1(new_n60_), .A2(\ctable[0] ), .ZN(new_n258_));
  NOR2_X1    g236(.A1(new_n258_), .A2(\trailingones[0] ), .ZN(new_n259_));
  AOI21_X1   g237(.A1(new_n208_), .A2(new_n259_), .B(new_n44_), .ZN(new_n260_));
  OAI21_X1   g238(.A1(new_n260_), .A2(new_n257_), .B(new_n24_), .ZN(new_n261_));
  AOI22_X1   g239(.A1(new_n178_), .A2(new_n44_), .B1(new_n50_), .B2(new_n33_), .ZN(new_n262_));
  NOR2_X1    g240(.A1(new_n262_), .A2(\ctable[0] ), .ZN(new_n263_));
  NAND2_X1   g241(.A1(new_n80_), .A2(\trailingones[1] ), .ZN(new_n264_));
  NAND2_X1   g242(.A1(new_n60_), .A2(new_n22_), .ZN(new_n265_));
  NOR2_X1    g243(.A1(new_n265_), .A2(new_n73_), .ZN(new_n266_));
  NAND2_X1   g244(.A1(new_n24_), .A2(\totalcoeffs[3] ), .ZN(new_n267_));
  NAND4_X1   g245(.A1(new_n266_), .A2(new_n154_), .A3(new_n264_), .A4(new_n267_), .ZN(new_n268_));
  NAND2_X1   g246(.A1(new_n73_), .A2(\trailingones[1] ), .ZN(new_n269_));
  NOR2_X1    g247(.A1(\totalcoeffs[2] ), .A2(\trailingones[1] ), .ZN(new_n270_));
  OAI21_X1   g248(.A1(\ctable[1] ), .A2(new_n86_), .B(new_n270_), .ZN(new_n271_));
  OAI21_X1   g249(.A1(new_n269_), .A2(new_n34_), .B(new_n271_), .ZN(new_n272_));
  NOR3_X1    g250(.A1(new_n263_), .A2(new_n272_), .A3(new_n268_), .ZN(new_n273_));
  AOI21_X1   g251(.A1(new_n273_), .A2(new_n261_), .B(\totalcoeffs[4] ), .ZN(new_n274_));
  OAI21_X1   g252(.A1(new_n274_), .A2(new_n255_), .B(new_n38_), .ZN(new_n275_));
  OAI21_X1   g253(.A1(new_n251_), .A2(new_n275_), .B(new_n39_), .ZN(new_n276_));
  NAND2_X1   g254(.A1(new_n276_), .A2(new_n225_), .ZN(\coeff_token[2] ));
  NOR2_X1    g255(.A1(\totalcoeffs[1] ), .A2(\ctable[1] ), .ZN(new_n278_));
  NAND4_X1   g256(.A1(new_n278_), .A2(new_n50_), .A3(new_n32_), .A4(\ctable[0] ), .ZN(new_n279_));
  NAND2_X1   g257(.A1(new_n112_), .A2(new_n60_), .ZN(new_n280_));
  AOI21_X1   g258(.A1(new_n280_), .A2(new_n279_), .B(\trailingones[1] ), .ZN(new_n281_));
  OAI22_X1   g259(.A1(new_n201_), .A2(\ctable[1] ), .B1(\totalcoeffs[3] ), .B2(new_n27_), .ZN(new_n282_));
  NOR2_X1    g260(.A1(new_n27_), .A2(new_n24_), .ZN(new_n283_));
  AOI21_X1   g261(.A1(new_n283_), .A2(new_n32_), .B(\totalcoeffs[3] ), .ZN(new_n284_));
  OAI21_X1   g262(.A1(\totalcoeffs[2] ), .A2(new_n284_), .B(new_n282_), .ZN(new_n285_));
  INV_X1     g263(.I(new_n183_), .ZN(new_n286_));
  AOI21_X1   g264(.A1(new_n182_), .A2(new_n50_), .B(new_n286_), .ZN(new_n287_));
  NOR4_X1    g265(.A1(new_n32_), .A2(\totalcoeffs[2] ), .A3(\totalcoeffs[3] ), .A4(\ctable[0] ), .ZN(new_n288_));
  NOR3_X1    g266(.A1(new_n287_), .A2(\trailingones[1] ), .A3(new_n288_), .ZN(new_n289_));
  AOI21_X1   g267(.A1(new_n289_), .A2(new_n285_), .B(new_n44_), .ZN(new_n290_));
  OAI21_X1   g268(.A1(new_n290_), .A2(new_n281_), .B(\totalcoeffs[0] ), .ZN(new_n291_));
  NAND3_X1   g269(.A1(new_n87_), .A2(new_n112_), .A3(new_n24_), .ZN(new_n292_));
  NOR2_X1    g270(.A1(new_n44_), .A2(new_n24_), .ZN(new_n293_));
  NOR2_X1    g271(.A1(new_n183_), .A2(new_n293_), .ZN(new_n294_));
  NOR3_X1    g272(.A1(new_n294_), .A2(\ctable[1] ), .A3(new_n283_), .ZN(new_n295_));
  NOR2_X1    g273(.A1(\ctable[1] ), .A2(\trailingones[0] ), .ZN(new_n296_));
  OAI21_X1   g274(.A1(new_n51_), .A2(new_n296_), .B(new_n50_), .ZN(new_n297_));
  OAI21_X1   g275(.A1(new_n295_), .A2(new_n297_), .B(\totalcoeffs[3] ), .ZN(new_n298_));
  INV_X1     g276(.I(new_n51_), .ZN(new_n299_));
  NAND2_X1   g277(.A1(new_n299_), .A2(\ctable[1] ), .ZN(new_n300_));
  OR2_X2     g278(.A1(new_n300_), .A2(new_n265_), .Z(new_n301_));
  NAND2_X1   g279(.A1(new_n300_), .A2(new_n265_), .ZN(new_n302_));
  NOR2_X1    g280(.A1(new_n50_), .A2(new_n60_), .ZN(new_n303_));
  NAND2_X1   g281(.A1(new_n303_), .A2(new_n22_), .ZN(new_n304_));
  OAI21_X1   g282(.A1(new_n83_), .A2(new_n256_), .B(new_n304_), .ZN(new_n305_));
  NAND4_X1   g283(.A1(new_n301_), .A2(new_n136_), .A3(new_n305_), .A4(new_n302_), .ZN(new_n306_));
  AOI22_X1   g284(.A1(new_n306_), .A2(new_n44_), .B1(new_n298_), .B2(new_n292_), .ZN(new_n307_));
  AOI21_X1   g285(.A1(new_n291_), .A2(new_n307_), .B(\totalcoeffs[4] ), .ZN(new_n308_));
  NAND2_X1   g286(.A1(new_n34_), .A2(new_n60_), .ZN(new_n309_));
  OAI21_X1   g287(.A1(\ctable[0] ), .A2(new_n34_), .B(new_n309_), .ZN(new_n310_));
  NOR2_X1    g288(.A1(new_n27_), .A2(\trailingones[0] ), .ZN(new_n311_));
  NOR2_X1    g289(.A1(new_n47_), .A2(new_n311_), .ZN(new_n312_));
  OAI21_X1   g290(.A1(new_n22_), .A2(\trailingones[1] ), .B(\ctable[0] ), .ZN(new_n313_));
  NAND4_X1   g291(.A1(new_n310_), .A2(new_n116_), .A3(new_n312_), .A4(new_n313_), .ZN(new_n314_));
  NAND2_X1   g292(.A1(new_n112_), .A2(\totalcoeffs[2] ), .ZN(new_n315_));
  AOI21_X1   g293(.A1(new_n314_), .A2(new_n315_), .B(\totalcoeffs[4] ), .ZN(new_n316_));
  NOR2_X1    g294(.A1(new_n27_), .A2(\ctable[1] ), .ZN(new_n317_));
  NAND2_X1   g295(.A1(new_n83_), .A2(\totalcoeffs[4] ), .ZN(new_n318_));
  NAND2_X1   g296(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n319_));
  INV_X1     g297(.I(new_n319_), .ZN(new_n320_));
  NOR2_X1    g298(.A1(new_n320_), .A2(\ctable[0] ), .ZN(new_n321_));
  OAI22_X1   g299(.A1(new_n321_), .A2(new_n318_), .B1(new_n112_), .B2(new_n317_), .ZN(new_n322_));
  INV_X1     g300(.I(new_n148_), .ZN(new_n323_));
  AOI21_X1   g301(.A1(\totalcoeffs[2] ), .A2(\ctable[1] ), .B(\totalcoeffs[3] ), .ZN(new_n324_));
  OAI21_X1   g302(.A1(new_n323_), .A2(new_n324_), .B(new_n150_), .ZN(new_n325_));
  AOI21_X1   g303(.A1(new_n322_), .A2(new_n325_), .B(\totalcoeffs[1] ), .ZN(new_n326_));
  OAI21_X1   g304(.A1(new_n316_), .A2(new_n326_), .B(new_n38_), .ZN(new_n327_));
  OAI21_X1   g305(.A1(new_n308_), .A2(new_n327_), .B(new_n39_), .ZN(\coeff_token[3] ));
  NOR2_X1    g306(.A1(new_n41_), .A2(\totalcoeffs[0] ), .ZN(new_n329_));
  INV_X1     g307(.I(new_n253_), .ZN(new_n330_));
  NAND2_X1   g308(.A1(new_n150_), .A2(\totalcoeffs[3] ), .ZN(new_n331_));
  NAND2_X1   g309(.A1(new_n330_), .A2(new_n331_), .ZN(new_n332_));
  NAND2_X1   g310(.A1(new_n125_), .A2(\totalcoeffs[4] ), .ZN(new_n333_));
  NOR3_X1    g311(.A1(new_n27_), .A2(new_n22_), .A3(\ctable[2] ), .ZN(new_n334_));
  NAND2_X1   g312(.A1(new_n333_), .A2(new_n334_), .ZN(new_n335_));
  AOI21_X1   g313(.A1(new_n329_), .A2(new_n332_), .B(new_n335_), .ZN(\coeff_token[4] ));
  OAI21_X1   g314(.A1(new_n329_), .A2(\totalcoeffs[4] ), .B(new_n60_), .ZN(new_n337_));
  NOR2_X1    g315(.A1(new_n318_), .A2(new_n56_), .ZN(new_n338_));
  INV_X1     g316(.I(new_n338_), .ZN(new_n339_));
  AND3_X2    g317(.A1(new_n337_), .A2(new_n334_), .A3(new_n339_), .Z(\coeff_token[5] ));
  NOR2_X1    g318(.A1(new_n338_), .A2(new_n28_), .ZN(new_n341_));
  MUX2_X1    g319(.I0(\trailingones[0] ), .I1(\ctable[0] ), .S(\totalcoeffs[0] ), .Z(new_n342_));
  NOR2_X1    g320(.A1(new_n38_), .A2(new_n22_), .ZN(new_n343_));
  OAI21_X1   g321(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .B(new_n343_), .ZN(new_n344_));
  OR3_X2     g322(.A1(new_n343_), .A2(new_n44_), .A3(\trailingones[0] ), .Z(new_n345_));
  NAND3_X1   g323(.A1(new_n345_), .A2(new_n50_), .A3(new_n344_), .ZN(new_n346_));
  NOR2_X1    g324(.A1(new_n44_), .A2(\trailingones[0] ), .ZN(new_n347_));
  AOI21_X1   g325(.A1(new_n347_), .A2(\totalcoeffs[0] ), .B(\trailingones[1] ), .ZN(new_n348_));
  AOI22_X1   g326(.A1(new_n346_), .A2(new_n348_), .B1(new_n64_), .B2(new_n342_), .ZN(new_n349_));
  OAI21_X1   g327(.A1(\totalcoeffs[0] ), .A2(\ctable[1] ), .B(new_n80_), .ZN(new_n350_));
  AOI21_X1   g328(.A1(new_n197_), .A2(new_n350_), .B(new_n65_), .ZN(new_n351_));
  OAI21_X1   g329(.A1(new_n82_), .A2(new_n293_), .B(\totalcoeffs[0] ), .ZN(new_n352_));
  OAI21_X1   g330(.A1(new_n351_), .A2(new_n352_), .B(new_n27_), .ZN(new_n353_));
  NOR2_X1    g331(.A1(new_n349_), .A2(new_n353_), .ZN(new_n354_));
  AOI21_X1   g332(.A1(new_n27_), .A2(\totalcoeffs[2] ), .B(\ctable[1] ), .ZN(new_n355_));
  OAI21_X1   g333(.A1(\totalcoeffs[0] ), .A2(new_n355_), .B(new_n219_), .ZN(new_n356_));
  NAND3_X1   g334(.A1(new_n215_), .A2(new_n218_), .A3(new_n207_), .ZN(new_n357_));
  AOI21_X1   g335(.A1(new_n356_), .A2(new_n357_), .B(\trailingones[0] ), .ZN(new_n358_));
  OR2_X2     g336(.A1(new_n123_), .A2(new_n164_), .Z(new_n359_));
  AOI21_X1   g337(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .B(\totalcoeffs[2] ), .ZN(new_n360_));
  AOI21_X1   g338(.A1(new_n359_), .A2(new_n24_), .B(new_n360_), .ZN(new_n361_));
  OAI21_X1   g339(.A1(new_n361_), .A2(new_n22_), .B(\totalcoeffs[1] ), .ZN(new_n362_));
  OAI21_X1   g340(.A1(\totalcoeffs[0] ), .A2(\ctable[1] ), .B(new_n32_), .ZN(new_n363_));
  NAND3_X1   g341(.A1(new_n363_), .A2(new_n176_), .A3(new_n270_), .ZN(new_n364_));
  NAND2_X1   g342(.A1(new_n114_), .A2(\totalcoeffs[2] ), .ZN(new_n365_));
  NOR2_X1    g343(.A1(new_n365_), .A2(new_n32_), .ZN(new_n366_));
  NOR2_X1    g344(.A1(new_n366_), .A2(\totalcoeffs[1] ), .ZN(new_n367_));
  AOI21_X1   g345(.A1(new_n367_), .A2(new_n364_), .B(new_n60_), .ZN(new_n368_));
  OAI21_X1   g346(.A1(new_n358_), .A2(new_n362_), .B(new_n368_), .ZN(new_n369_));
  NOR2_X1    g347(.A1(new_n354_), .A2(new_n369_), .ZN(new_n370_));
  OAI21_X1   g348(.A1(new_n39_), .A2(\trailingones[1] ), .B(\trailingones[0] ), .ZN(new_n371_));
  NAND2_X1   g349(.A1(new_n371_), .A2(\totalcoeffs[2] ), .ZN(new_n372_));
  NOR2_X1    g350(.A1(new_n44_), .A2(\totalcoeffs[2] ), .ZN(new_n373_));
  NOR3_X1    g351(.A1(new_n116_), .A2(new_n373_), .A3(new_n270_), .ZN(new_n374_));
  AOI21_X1   g352(.A1(new_n374_), .A2(new_n372_), .B(\totalcoeffs[0] ), .ZN(new_n375_));
  NOR3_X1    g353(.A1(new_n38_), .A2(new_n44_), .A3(\trailingones[1] ), .ZN(new_n376_));
  NAND3_X1   g354(.A1(new_n163_), .A2(new_n50_), .A3(\ctable[2] ), .ZN(new_n377_));
  OAI21_X1   g355(.A1(new_n377_), .A2(new_n376_), .B(new_n223_), .ZN(new_n378_));
  NOR2_X1    g356(.A1(new_n378_), .A2(new_n375_), .ZN(new_n379_));
  NAND2_X1   g357(.A1(new_n299_), .A2(new_n166_), .ZN(new_n380_));
  NAND2_X1   g358(.A1(new_n44_), .A2(new_n27_), .ZN(new_n381_));
  NAND2_X1   g359(.A1(new_n381_), .A2(\totalcoeffs[2] ), .ZN(new_n382_));
  NOR2_X1    g360(.A1(\ctable[1] ), .A2(\trailingones[1] ), .ZN(new_n383_));
  AOI22_X1   g361(.A1(new_n382_), .A2(new_n383_), .B1(\ctable[0] ), .B2(new_n293_), .ZN(new_n384_));
  OAI21_X1   g362(.A1(new_n384_), .A2(new_n38_), .B(new_n380_), .ZN(new_n385_));
  AOI21_X1   g363(.A1(new_n365_), .A2(new_n81_), .B(new_n27_), .ZN(new_n386_));
  AOI21_X1   g364(.A1(new_n359_), .A2(new_n22_), .B(new_n163_), .ZN(new_n387_));
  NOR3_X1    g365(.A1(new_n387_), .A2(new_n32_), .A3(new_n386_), .ZN(new_n388_));
  AOI21_X1   g366(.A1(new_n388_), .A2(new_n385_), .B(\ctable[2] ), .ZN(new_n389_));
  NOR2_X1    g367(.A1(\totalcoeffs[3] ), .A2(\ctable[2] ), .ZN(new_n390_));
  OAI21_X1   g368(.A1(new_n389_), .A2(new_n379_), .B(new_n390_), .ZN(new_n391_));
  NOR2_X1    g369(.A1(new_n370_), .A2(new_n391_), .ZN(new_n392_));
  OAI22_X1   g370(.A1(new_n392_), .A2(\totalcoeffs[4] ), .B1(\ctable[2] ), .B2(new_n341_), .ZN(\ctoken_len[0] ));
  INV_X1     g371(.I(new_n61_), .ZN(new_n394_));
  NAND2_X1   g372(.A1(new_n394_), .A2(new_n109_), .ZN(new_n395_));
  NAND4_X1   g373(.A1(new_n395_), .A2(\totalcoeffs[4] ), .A3(new_n39_), .A4(new_n278_), .ZN(new_n396_));
  NOR3_X1    g374(.A1(new_n154_), .A2(new_n50_), .A3(new_n27_), .ZN(new_n397_));
  NOR2_X1    g375(.A1(\totalcoeffs[0] ), .A2(\ctable[0] ), .ZN(new_n398_));
  NOR2_X1    g376(.A1(new_n398_), .A2(\trailingones[1] ), .ZN(new_n399_));
  NOR3_X1    g377(.A1(new_n399_), .A2(new_n38_), .A3(\totalcoeffs[2] ), .ZN(new_n400_));
  NOR3_X1    g378(.A1(new_n167_), .A2(\trailingones[1] ), .A3(new_n398_), .ZN(new_n401_));
  NOR3_X1    g379(.A1(new_n400_), .A2(new_n32_), .A3(new_n401_), .ZN(new_n402_));
  OAI21_X1   g380(.A1(new_n402_), .A2(new_n397_), .B(new_n60_), .ZN(new_n403_));
  NOR2_X1    g381(.A1(new_n60_), .A2(\totalcoeffs[2] ), .ZN(new_n404_));
  AOI21_X1   g382(.A1(new_n24_), .A2(\totalcoeffs[2] ), .B(\totalcoeffs[0] ), .ZN(new_n405_));
  AOI22_X1   g383(.A1(new_n405_), .A2(new_n198_), .B1(new_n404_), .B2(\ctable[0] ), .ZN(new_n406_));
  OAI21_X1   g384(.A1(new_n207_), .A2(new_n267_), .B(new_n32_), .ZN(new_n407_));
  NOR2_X1    g385(.A1(new_n406_), .A2(new_n407_), .ZN(new_n408_));
  AOI21_X1   g386(.A1(new_n403_), .A2(new_n408_), .B(new_n44_), .ZN(new_n409_));
  INV_X1     g387(.I(new_n229_), .ZN(new_n410_));
  NOR4_X1    g388(.A1(new_n410_), .A2(new_n38_), .A3(new_n50_), .A4(new_n60_), .ZN(new_n411_));
  NAND4_X1   g389(.A1(new_n163_), .A2(new_n38_), .A3(new_n50_), .A4(\totalcoeffs[3] ), .ZN(new_n412_));
  AOI21_X1   g390(.A1(new_n412_), .A2(\ctable[0] ), .B(new_n411_), .ZN(new_n413_));
  NAND3_X1   g391(.A1(new_n283_), .A2(new_n303_), .A3(\trailingones[0] ), .ZN(new_n414_));
  OAI21_X1   g392(.A1(new_n413_), .A2(\totalcoeffs[1] ), .B(new_n414_), .ZN(new_n415_));
  OAI21_X1   g393(.A1(new_n409_), .A2(new_n415_), .B(new_n22_), .ZN(new_n416_));
  NOR4_X1    g394(.A1(new_n34_), .A2(\totalcoeffs[2] ), .A3(new_n60_), .A4(\trailingones[1] ), .ZN(new_n417_));
  NOR2_X1    g395(.A1(new_n163_), .A2(new_n142_), .ZN(new_n418_));
  NOR4_X1    g396(.A1(new_n320_), .A2(new_n100_), .A3(\totalcoeffs[2] ), .A4(\ctable[1] ), .ZN(new_n419_));
  OAI21_X1   g397(.A1(new_n418_), .A2(new_n419_), .B(\totalcoeffs[3] ), .ZN(new_n420_));
  NOR3_X1    g398(.A1(new_n50_), .A2(new_n22_), .A3(\trailingones[0] ), .ZN(new_n421_));
  AOI21_X1   g399(.A1(new_n50_), .A2(new_n32_), .B(\ctable[1] ), .ZN(new_n422_));
  AOI21_X1   g400(.A1(new_n60_), .A2(new_n32_), .B(\ctable[1] ), .ZN(new_n423_));
  NAND4_X1   g401(.A1(new_n24_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[2] ), .A4(\trailingones[0] ), .ZN(new_n424_));
  NOR4_X1    g402(.A1(new_n421_), .A2(new_n422_), .A3(new_n423_), .A4(new_n424_), .ZN(new_n425_));
  NAND2_X1   g403(.A1(new_n420_), .A2(new_n425_), .ZN(new_n426_));
  AOI21_X1   g404(.A1(new_n426_), .A2(new_n44_), .B(new_n417_), .ZN(new_n427_));
  NOR2_X1    g405(.A1(new_n22_), .A2(\trailingones[0] ), .ZN(new_n429_));
  NOR4_X1    g406(.A1(new_n60_), .A2(new_n32_), .A3(\totalcoeffs[0] ), .A4(\ctable[1] ), .ZN(new_n430_));
  NOR3_X1    g407(.A1(new_n430_), .A2(new_n24_), .A3(new_n429_), .ZN(new_n431_));
  INV_X1     g408(.I(new_n133_), .ZN(new_n432_));
  NOR2_X1    g409(.A1(new_n182_), .A2(new_n38_), .ZN(new_n433_));
  AOI22_X1   g410(.A1(new_n433_), .A2(new_n432_), .B1(new_n24_), .B2(new_n132_), .ZN(new_n434_));
  OAI21_X1   g411(.A1(new_n434_), .A2(new_n431_), .B(new_n50_), .ZN(new_n435_));
  NOR2_X1    g412(.A1(new_n319_), .A2(\totalcoeffs[3] ), .ZN(new_n436_));
  AOI21_X1   g413(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .B(\ctable[1] ), .ZN(new_n437_));
  NOR3_X1    g414(.A1(new_n436_), .A2(\totalcoeffs[2] ), .A3(new_n437_), .ZN(new_n438_));
  OAI21_X1   g415(.A1(new_n410_), .A2(new_n265_), .B(new_n44_), .ZN(new_n439_));
  NOR2_X1    g416(.A1(new_n438_), .A2(new_n439_), .ZN(new_n440_));
  NAND2_X1   g417(.A1(new_n435_), .A2(new_n440_), .ZN(new_n441_));
  OAI21_X1   g418(.A1(new_n427_), .A2(new_n441_), .B(new_n27_), .ZN(new_n442_));
  NAND2_X1   g419(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .ZN(new_n443_));
  AOI21_X1   g420(.A1(new_n162_), .A2(\ctable[2] ), .B(new_n443_), .ZN(new_n444_));
  OAI21_X1   g421(.A1(new_n320_), .A2(new_n229_), .B(\totalcoeffs[2] ), .ZN(new_n445_));
  NOR2_X1    g422(.A1(new_n445_), .A2(new_n444_), .ZN(new_n446_));
  NAND2_X1   g423(.A1(new_n394_), .A2(new_n278_), .ZN(new_n447_));
  OAI21_X1   g424(.A1(new_n446_), .A2(new_n447_), .B(new_n39_), .ZN(new_n448_));
  AOI21_X1   g425(.A1(new_n442_), .A2(new_n416_), .B(new_n448_), .ZN(new_n449_));
  OAI21_X1   g426(.A1(new_n449_), .A2(\totalcoeffs[4] ), .B(new_n396_), .ZN(\ctoken_len[1] ));
  NAND4_X1   g427(.A1(new_n329_), .A2(new_n394_), .A3(\totalcoeffs[4] ), .A4(new_n39_), .ZN(new_n451_));
  NAND2_X1   g428(.A1(new_n108_), .A2(\ctable[1] ), .ZN(new_n452_));
  NOR2_X1    g429(.A1(new_n229_), .A2(\totalcoeffs[1] ), .ZN(new_n453_));
  OAI21_X1   g430(.A1(new_n50_), .A2(new_n453_), .B(new_n452_), .ZN(new_n454_));
  NOR2_X1    g431(.A1(new_n64_), .A2(new_n32_), .ZN(new_n455_));
  NAND2_X1   g432(.A1(new_n452_), .A2(new_n455_), .ZN(new_n456_));
  OAI21_X1   g433(.A1(new_n347_), .A2(\ctable[1] ), .B(\totalcoeffs[2] ), .ZN(new_n457_));
  NOR2_X1    g434(.A1(new_n176_), .A2(\totalcoeffs[3] ), .ZN(new_n458_));
  NAND4_X1   g435(.A1(new_n454_), .A2(new_n456_), .A3(new_n457_), .A4(new_n458_), .ZN(new_n459_));
  NAND3_X1   g436(.A1(new_n241_), .A2(new_n201_), .A3(new_n40_), .ZN(new_n460_));
  NAND2_X1   g437(.A1(new_n207_), .A2(new_n198_), .ZN(new_n461_));
  NOR2_X1    g438(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[3] ), .ZN(new_n462_));
  NAND3_X1   g439(.A1(new_n461_), .A2(new_n123_), .A3(new_n462_), .ZN(new_n463_));
  AOI21_X1   g440(.A1(new_n463_), .A2(new_n460_), .B(new_n24_), .ZN(new_n464_));
  MUX2_X1    g441(.I0(new_n187_), .I1(\totalcoeffs[3] ), .S(\ctable[0] ), .Z(new_n465_));
  NOR2_X1    g442(.A1(new_n203_), .A2(new_n258_), .ZN(new_n466_));
  AOI21_X1   g443(.A1(new_n38_), .A2(new_n60_), .B(\totalcoeffs[2] ), .ZN(new_n467_));
  AOI22_X1   g444(.A1(new_n466_), .A2(new_n467_), .B1(new_n241_), .B2(new_n462_), .ZN(new_n468_));
  OAI22_X1   g445(.A1(new_n468_), .A2(new_n32_), .B1(new_n197_), .B2(new_n465_), .ZN(new_n469_));
  AOI21_X1   g446(.A1(new_n469_), .A2(new_n24_), .B(new_n464_), .ZN(new_n470_));
  MUX2_X1    g447(.I0(new_n44_), .I1(new_n60_), .S(\trailingones[1] ), .Z(new_n471_));
  OAI22_X1   g448(.A1(new_n471_), .A2(\totalcoeffs[2] ), .B1(new_n203_), .B2(new_n258_), .ZN(new_n472_));
  NAND2_X1   g449(.A1(new_n60_), .A2(\totalcoeffs[2] ), .ZN(new_n473_));
  NOR3_X1    g450(.A1(new_n27_), .A2(new_n24_), .A3(\totalcoeffs[1] ), .ZN(new_n474_));
  AOI21_X1   g451(.A1(new_n381_), .A2(\trailingones[1] ), .B(new_n44_), .ZN(new_n475_));
  OAI21_X1   g452(.A1(new_n475_), .A2(new_n474_), .B(new_n473_), .ZN(new_n476_));
  INV_X1     g453(.I(new_n269_), .ZN(new_n477_));
  NOR3_X1    g454(.A1(new_n41_), .A2(new_n27_), .A3(\trailingones[1] ), .ZN(new_n478_));
  OAI21_X1   g455(.A1(new_n477_), .A2(new_n478_), .B(new_n38_), .ZN(new_n479_));
  NAND4_X1   g456(.A1(new_n479_), .A2(new_n476_), .A3(new_n472_), .A4(new_n32_), .ZN(new_n480_));
  OAI21_X1   g457(.A1(new_n470_), .A2(new_n480_), .B(new_n22_), .ZN(new_n481_));
  OAI21_X1   g458(.A1(new_n173_), .A2(\totalcoeffs[0] ), .B(\totalcoeffs[1] ), .ZN(new_n482_));
  NOR2_X1    g459(.A1(new_n164_), .A2(new_n24_), .ZN(new_n483_));
  NAND2_X1   g460(.A1(new_n173_), .A2(\totalcoeffs[0] ), .ZN(new_n484_));
  OAI21_X1   g461(.A1(\trailingones[1] ), .A2(new_n173_), .B(new_n484_), .ZN(new_n485_));
  NOR2_X1    g462(.A1(new_n264_), .A2(new_n110_), .ZN(new_n486_));
  NOR4_X1    g463(.A1(new_n485_), .A2(new_n482_), .A3(new_n483_), .A4(new_n486_), .ZN(new_n487_));
  NOR3_X1    g464(.A1(new_n485_), .A2(new_n482_), .A3(new_n483_), .ZN(new_n488_));
  INV_X1     g465(.I(new_n486_), .ZN(new_n489_));
  NOR2_X1    g466(.A1(new_n61_), .A2(\ctable[1] ), .ZN(new_n490_));
  OAI21_X1   g467(.A1(new_n488_), .A2(new_n489_), .B(new_n490_), .ZN(new_n491_));
  OAI21_X1   g468(.A1(new_n491_), .A2(new_n487_), .B(new_n39_), .ZN(new_n492_));
  AOI21_X1   g469(.A1(new_n481_), .A2(new_n459_), .B(new_n492_), .ZN(new_n493_));
  OAI21_X1   g470(.A1(new_n493_), .A2(\totalcoeffs[4] ), .B(new_n451_), .ZN(\ctoken_len[2] ));
  NOR2_X1    g471(.A1(new_n283_), .A2(\trailingones[0] ), .ZN(new_n495_));
  NAND2_X1   g472(.A1(new_n299_), .A2(new_n60_), .ZN(new_n496_));
  NOR3_X1    g473(.A1(new_n495_), .A2(new_n496_), .A3(new_n50_), .ZN(new_n497_));
  INV_X1     g474(.I(new_n187_), .ZN(new_n498_));
  AOI21_X1   g475(.A1(new_n498_), .A2(\ctable[0] ), .B(\ctable[1] ), .ZN(new_n499_));
  XOR2_X1    g476(.A1(new_n187_), .A2(\ctable[1] ), .Z(new_n500_));
  NOR2_X1    g477(.A1(new_n500_), .A2(\trailingones[1] ), .ZN(new_n501_));
  NAND3_X1   g478(.A1(new_n223_), .A2(new_n60_), .A3(\totalcoeffs[4] ), .ZN(new_n502_));
  NAND2_X1   g479(.A1(new_n223_), .A2(new_n253_), .ZN(new_n503_));
  NOR3_X1    g480(.A1(new_n501_), .A2(new_n60_), .A3(new_n499_), .ZN(new_n504_));
  AOI21_X1   g481(.A1(new_n504_), .A2(new_n503_), .B(\totalcoeffs[2] ), .ZN(new_n505_));
  AOI21_X1   g482(.A1(new_n505_), .A2(new_n502_), .B(new_n497_), .ZN(new_n506_));
  NAND3_X1   g483(.A1(new_n432_), .A2(\totalcoeffs[3] ), .A3(new_n187_), .ZN(new_n507_));
  OAI21_X1   g484(.A1(new_n507_), .A2(new_n496_), .B(new_n50_), .ZN(new_n508_));
  AOI21_X1   g485(.A1(new_n283_), .A2(\trailingones[0] ), .B(\ctable[1] ), .ZN(new_n509_));
  OAI21_X1   g486(.A1(\ctable[0] ), .A2(new_n320_), .B(new_n304_), .ZN(new_n510_));
  OAI21_X1   g487(.A1(\totalcoeffs[3] ), .A2(new_n509_), .B(new_n510_), .ZN(new_n511_));
  NAND3_X1   g488(.A1(new_n511_), .A2(new_n44_), .A3(new_n508_), .ZN(new_n512_));
  OAI21_X1   g489(.A1(new_n41_), .A2(\totalcoeffs[3] ), .B(\totalcoeffs[4] ), .ZN(new_n513_));
  NAND2_X1   g490(.A1(new_n473_), .A2(new_n27_), .ZN(new_n514_));
  NAND2_X1   g491(.A1(new_n473_), .A2(\ctable[2] ), .ZN(new_n515_));
  NAND4_X1   g492(.A1(new_n513_), .A2(new_n514_), .A3(new_n515_), .A4(\ctable[1] ), .ZN(new_n516_));
  NOR2_X1    g493(.A1(new_n304_), .A2(new_n176_), .ZN(new_n517_));
  OAI22_X1   g494(.A1(new_n517_), .A2(\ctable[2] ), .B1(\totalcoeffs[1] ), .B2(new_n229_), .ZN(new_n518_));
  NOR2_X1    g495(.A1(new_n42_), .A2(\ctable[2] ), .ZN(new_n519_));
  NOR3_X1    g496(.A1(new_n519_), .A2(new_n38_), .A3(\totalcoeffs[1] ), .ZN(new_n520_));
  NAND4_X1   g497(.A1(new_n512_), .A2(new_n516_), .A3(new_n518_), .A4(new_n520_), .ZN(new_n521_));
  NOR2_X1    g498(.A1(new_n506_), .A2(new_n521_), .ZN(\ctoken_len[3] ));
  NAND2_X1   g499(.A1(new_n410_), .A2(new_n38_), .ZN(new_n523_));
  NAND2_X1   g500(.A1(new_n498_), .A2(new_n63_), .ZN(new_n524_));
  NAND4_X1   g501(.A1(new_n524_), .A2(new_n523_), .A3(new_n150_), .A4(new_n303_), .ZN(new_n525_));
  NAND2_X1   g502(.A1(new_n222_), .A2(new_n39_), .ZN(new_n526_));
  AOI21_X1   g503(.A1(new_n525_), .A2(new_n339_), .B(new_n526_), .ZN(\ctoken_len[4] ));
endmodule


