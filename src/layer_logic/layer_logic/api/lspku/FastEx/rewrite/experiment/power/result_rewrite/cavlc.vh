// Benchmark "cavlc" written by ABC on Fri Sep 15 11:25:06 2023

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
    new_n111_, new_n112_, new_n113_, new_n114_, new_n115_, new_n117_,
    new_n118_, new_n119_, new_n120_, new_n121_, new_n122_, new_n123_,
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
    new_n196_, new_n197_, new_n198_, new_n200_, new_n201_, new_n202_,
    new_n203_, new_n204_, new_n205_, new_n206_, new_n207_, new_n208_,
    new_n209_, new_n210_, new_n211_, new_n212_, new_n213_, new_n214_,
    new_n215_, new_n216_, new_n217_, new_n218_, new_n219_, new_n220_,
    new_n221_, new_n222_, new_n223_, new_n224_, new_n225_, new_n226_,
    new_n227_, new_n228_, new_n229_, new_n230_, new_n231_, new_n232_,
    new_n233_, new_n234_, new_n235_, new_n236_, new_n237_, new_n238_,
    new_n239_, new_n240_, new_n241_, new_n242_, new_n243_, new_n244_,
    new_n245_, new_n246_, new_n247_, new_n248_, new_n249_, new_n250_,
    new_n251_, new_n252_, new_n253_, new_n254_, new_n255_, new_n256_,
    new_n257_, new_n259_, new_n260_, new_n261_, new_n262_, new_n263_,
    new_n264_, new_n265_, new_n266_, new_n267_, new_n268_, new_n269_,
    new_n270_, new_n271_, new_n272_, new_n273_, new_n274_, new_n275_,
    new_n276_, new_n277_, new_n278_, new_n279_, new_n280_, new_n281_,
    new_n282_, new_n283_, new_n284_, new_n285_, new_n286_, new_n287_,
    new_n288_, new_n289_, new_n290_, new_n291_, new_n292_, new_n293_,
    new_n294_, new_n295_, new_n296_, new_n297_, new_n298_, new_n299_,
    new_n301_, new_n302_, new_n303_, new_n304_, new_n305_, new_n306_,
    new_n307_, new_n309_, new_n310_, new_n312_, new_n313_, new_n314_,
    new_n315_, new_n316_, new_n317_, new_n318_, new_n319_, new_n320_,
    new_n321_, new_n322_, new_n323_, new_n324_, new_n325_, new_n326_,
    new_n327_, new_n328_, new_n329_, new_n330_, new_n331_, new_n332_,
    new_n333_, new_n334_, new_n335_, new_n336_, new_n337_, new_n338_,
    new_n339_, new_n340_, new_n341_, new_n342_, new_n343_, new_n344_,
    new_n345_, new_n346_, new_n347_, new_n348_, new_n349_, new_n350_,
    new_n351_, new_n352_, new_n353_, new_n354_, new_n355_, new_n356_,
    new_n357_, new_n359_, new_n360_, new_n361_, new_n362_, new_n363_,
    new_n364_, new_n365_, new_n366_, new_n367_, new_n368_, new_n369_,
    new_n370_, new_n371_, new_n372_, new_n373_, new_n374_, new_n375_,
    new_n376_, new_n377_, new_n378_, new_n379_, new_n380_, new_n381_,
    new_n382_, new_n383_, new_n384_, new_n385_, new_n386_, new_n387_,
    new_n388_, new_n389_, new_n390_, new_n391_, new_n392_, new_n393_,
    new_n394_, new_n395_, new_n396_, new_n397_, new_n398_, new_n399_,
    new_n400_, new_n401_, new_n402_, new_n403_, new_n404_, new_n405_,
    new_n406_, new_n407_, new_n408_, new_n410_, new_n411_, new_n412_,
    new_n413_, new_n414_, new_n415_, new_n416_, new_n417_, new_n418_,
    new_n419_, new_n420_, new_n421_, new_n422_, new_n423_, new_n424_,
    new_n425_, new_n426_, new_n427_, new_n428_, new_n429_, new_n430_,
    new_n431_, new_n432_, new_n433_, new_n434_, new_n435_, new_n436_,
    new_n437_, new_n438_, new_n439_, new_n440_, new_n441_, new_n442_,
    new_n443_, new_n445_, new_n446_, new_n447_, new_n448_, new_n449_,
    new_n450_, new_n451_, new_n452_, new_n453_, new_n454_, new_n455_,
    new_n456_, new_n457_, new_n458_, new_n459_, new_n460_, new_n461_,
    new_n462_, new_n463_, new_n464_, new_n465_, new_n466_, new_n468_,
    new_n469_, new_n470_;
  INV_X1     g000(.I(\totalcoeffs[0] ), .ZN(new_n22_));
  INV_X1     g001(.I(\ctable[2] ), .ZN(new_n23_));
  NOR2_X1    g002(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .ZN(new_n24_));
  INV_X1     g003(.I(new_n24_), .ZN(new_n25_));
  NOR2_X1    g004(.A1(new_n25_), .A2(\totalcoeffs[3] ), .ZN(new_n26_));
  NAND3_X1   g005(.A1(new_n26_), .A2(new_n22_), .A3(new_n23_), .ZN(new_n27_));
  INV_X1     g006(.I(\ctable[0] ), .ZN(new_n28_));
  INV_X1     g007(.I(\ctable[1] ), .ZN(new_n29_));
  NOR2_X1    g008(.A1(new_n28_), .A2(new_n29_), .ZN(new_n30_));
  NOR2_X1    g009(.A1(new_n30_), .A2(\trailingones[0] ), .ZN(new_n31_));
  NAND2_X1   g010(.A1(\totalcoeffs[4] ), .A2(\trailingones[1] ), .ZN(new_n32_));
  INV_X1     g011(.I(\trailingones[1] ), .ZN(new_n33_));
  NAND2_X1   g012(.A1(new_n33_), .A2(\ctable[1] ), .ZN(new_n34_));
  NAND2_X1   g013(.A1(new_n34_), .A2(new_n32_), .ZN(new_n35_));
  INV_X1     g014(.I(\trailingones[0] ), .ZN(new_n36_));
  NOR2_X1    g015(.A1(new_n36_), .A2(\ctable[1] ), .ZN(new_n37_));
  NOR2_X1    g016(.A1(\ctable[1] ), .A2(\trailingones[1] ), .ZN(new_n38_));
  INV_X1     g017(.I(\totalcoeffs[4] ), .ZN(new_n39_));
  NOR2_X1    g018(.A1(new_n39_), .A2(new_n36_), .ZN(new_n40_));
  NOR2_X1    g019(.A1(new_n40_), .A2(new_n38_), .ZN(new_n41_));
  NOR3_X1    g020(.A1(new_n41_), .A2(new_n28_), .A3(new_n37_), .ZN(new_n42_));
  AOI21_X1   g021(.A1(new_n31_), .A2(new_n35_), .B(new_n42_), .ZN(new_n43_));
  INV_X1     g022(.I(\totalcoeffs[3] ), .ZN(new_n44_));
  NAND2_X1   g023(.A1(new_n22_), .A2(new_n44_), .ZN(new_n45_));
  INV_X1     g024(.I(\totalcoeffs[2] ), .ZN(new_n46_));
  NOR2_X1    g025(.A1(new_n46_), .A2(new_n33_), .ZN(new_n47_));
  NOR2_X1    g026(.A1(\totalcoeffs[2] ), .A2(\trailingones[1] ), .ZN(new_n48_));
  NAND2_X1   g027(.A1(new_n48_), .A2(\totalcoeffs[1] ), .ZN(new_n49_));
  INV_X1     g028(.I(new_n49_), .ZN(new_n50_));
  NOR2_X1    g029(.A1(new_n50_), .A2(new_n47_), .ZN(new_n51_));
  NOR3_X1    g030(.A1(new_n51_), .A2(new_n29_), .A3(new_n45_), .ZN(new_n52_));
  NOR2_X1    g031(.A1(new_n22_), .A2(\trailingones[1] ), .ZN(new_n53_));
  OAI21_X1   g032(.A1(new_n53_), .A2(\totalcoeffs[2] ), .B(\ctable[1] ), .ZN(new_n54_));
  NAND2_X1   g033(.A1(new_n22_), .A2(new_n33_), .ZN(new_n55_));
  NAND2_X1   g034(.A1(\totalcoeffs[0] ), .A2(\trailingones[1] ), .ZN(new_n56_));
  NAND2_X1   g035(.A1(new_n55_), .A2(new_n56_), .ZN(new_n57_));
  NOR2_X1    g036(.A1(\totalcoeffs[2] ), .A2(\totalcoeffs[3] ), .ZN(new_n58_));
  NAND3_X1   g037(.A1(new_n57_), .A2(\totalcoeffs[1] ), .A3(new_n58_), .ZN(new_n59_));
  AOI21_X1   g038(.A1(new_n59_), .A2(new_n54_), .B(new_n28_), .ZN(new_n60_));
  OAI21_X1   g039(.A1(new_n60_), .A2(new_n52_), .B(\trailingones[0] ), .ZN(new_n61_));
  NOR2_X1    g040(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .ZN(new_n62_));
  INV_X1     g041(.I(new_n62_), .ZN(new_n63_));
  NOR3_X1    g042(.A1(new_n63_), .A2(\totalcoeffs[1] ), .A3(new_n33_), .ZN(new_n64_));
  OAI21_X1   g043(.A1(new_n64_), .A2(\ctable[0] ), .B(\ctable[1] ), .ZN(new_n65_));
  NOR2_X1    g044(.A1(new_n46_), .A2(new_n28_), .ZN(new_n66_));
  NAND3_X1   g045(.A1(new_n57_), .A2(\totalcoeffs[1] ), .A3(new_n66_), .ZN(new_n67_));
  AOI21_X1   g046(.A1(new_n65_), .A2(new_n67_), .B(new_n36_), .ZN(new_n68_));
  NOR2_X1    g047(.A1(new_n33_), .A2(\totalcoeffs[0] ), .ZN(new_n69_));
  OAI21_X1   g048(.A1(new_n69_), .A2(\totalcoeffs[1] ), .B(new_n36_), .ZN(new_n70_));
  INV_X1     g049(.I(\totalcoeffs[1] ), .ZN(new_n71_));
  NAND3_X1   g050(.A1(new_n53_), .A2(new_n71_), .A3(\totalcoeffs[2] ), .ZN(new_n72_));
  AOI21_X1   g051(.A1(new_n70_), .A2(new_n72_), .B(\ctable[0] ), .ZN(new_n73_));
  OAI21_X1   g052(.A1(new_n68_), .A2(new_n73_), .B(\totalcoeffs[3] ), .ZN(new_n74_));
  NOR2_X1    g053(.A1(\totalcoeffs[1] ), .A2(\trailingones[1] ), .ZN(new_n75_));
  OAI21_X1   g054(.A1(new_n29_), .A2(\totalcoeffs[2] ), .B(\totalcoeffs[3] ), .ZN(new_n76_));
  AOI21_X1   g055(.A1(new_n75_), .A2(new_n76_), .B(new_n47_), .ZN(new_n77_));
  NOR2_X1    g056(.A1(new_n33_), .A2(\totalcoeffs[1] ), .ZN(new_n78_));
  NOR2_X1    g057(.A1(new_n46_), .A2(\totalcoeffs[3] ), .ZN(new_n79_));
  AOI22_X1   g058(.A1(new_n78_), .A2(new_n79_), .B1(\totalcoeffs[1] ), .B2(new_n36_), .ZN(new_n80_));
  OAI22_X1   g059(.A1(\trailingones[0] ), .A2(new_n77_), .B1(new_n80_), .B2(\totalcoeffs[0] ), .ZN(new_n81_));
  NOR2_X1    g060(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n82_));
  NAND2_X1   g061(.A1(new_n82_), .A2(new_n33_), .ZN(new_n83_));
  NOR3_X1    g062(.A1(new_n83_), .A2(new_n63_), .A3(\totalcoeffs[3] ), .ZN(new_n84_));
  AOI21_X1   g063(.A1(new_n81_), .A2(new_n28_), .B(new_n84_), .ZN(new_n85_));
  NAND3_X1   g064(.A1(new_n74_), .A2(new_n61_), .A3(new_n85_), .ZN(new_n86_));
  NAND2_X1   g065(.A1(new_n46_), .A2(\totalcoeffs[0] ), .ZN(new_n87_));
  NOR2_X1    g066(.A1(new_n33_), .A2(\ctable[2] ), .ZN(new_n88_));
  NOR3_X1    g067(.A1(new_n23_), .A2(new_n36_), .A3(\ctable[0] ), .ZN(new_n89_));
  OAI21_X1   g068(.A1(new_n89_), .A2(new_n88_), .B(\totalcoeffs[1] ), .ZN(new_n90_));
  NOR2_X1    g069(.A1(\ctable[0] ), .A2(\trailingones[1] ), .ZN(new_n91_));
  OAI21_X1   g070(.A1(new_n71_), .A2(\ctable[2] ), .B(new_n91_), .ZN(new_n92_));
  AOI21_X1   g071(.A1(new_n90_), .A2(new_n92_), .B(new_n87_), .ZN(new_n93_));
  NOR2_X1    g072(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[1] ), .ZN(new_n94_));
  NOR2_X1    g073(.A1(new_n46_), .A2(\trailingones[1] ), .ZN(new_n95_));
  NAND2_X1   g074(.A1(new_n95_), .A2(new_n94_), .ZN(new_n96_));
  NOR4_X1    g075(.A1(new_n96_), .A2(\ctable[0] ), .A3(new_n23_), .A4(new_n36_), .ZN(new_n97_));
  NOR2_X1    g076(.A1(new_n93_), .A2(new_n97_), .ZN(new_n98_));
  NAND2_X1   g077(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .ZN(new_n99_));
  NOR2_X1    g078(.A1(\totalcoeffs[2] ), .A2(\ctable[0] ), .ZN(new_n100_));
  AOI21_X1   g079(.A1(\totalcoeffs[0] ), .A2(new_n99_), .B(new_n100_), .ZN(new_n101_));
  AOI22_X1   g080(.A1(new_n101_), .A2(new_n33_), .B1(\totalcoeffs[1] ), .B2(new_n44_), .ZN(new_n102_));
  INV_X1     g081(.I(new_n58_), .ZN(new_n103_));
  OAI21_X1   g082(.A1(new_n22_), .A2(new_n44_), .B(new_n33_), .ZN(new_n104_));
  NAND3_X1   g083(.A1(new_n104_), .A2(new_n103_), .A3(new_n71_), .ZN(new_n105_));
  AOI21_X1   g084(.A1(new_n102_), .A2(new_n105_), .B(\ctable[2] ), .ZN(new_n106_));
  NOR2_X1    g085(.A1(\totalcoeffs[3] ), .A2(\ctable[0] ), .ZN(new_n107_));
  NOR2_X1    g086(.A1(new_n71_), .A2(\trailingones[1] ), .ZN(new_n108_));
  NOR2_X1    g087(.A1(new_n78_), .A2(new_n108_), .ZN(new_n109_));
  NAND3_X1   g088(.A1(new_n109_), .A2(new_n56_), .A3(new_n107_), .ZN(new_n110_));
  NAND3_X1   g089(.A1(new_n109_), .A2(new_n23_), .A3(new_n55_), .ZN(new_n111_));
  AOI21_X1   g090(.A1(new_n110_), .A2(new_n111_), .B(\totalcoeffs[2] ), .ZN(new_n112_));
  NOR2_X1    g091(.A1(new_n112_), .A2(new_n106_), .ZN(new_n113_));
  OAI22_X1   g092(.A1(new_n113_), .A2(\trailingones[0] ), .B1(\totalcoeffs[3] ), .B2(new_n98_), .ZN(new_n114_));
  AOI22_X1   g093(.A1(new_n29_), .A2(new_n114_), .B1(new_n86_), .B2(new_n23_), .ZN(new_n115_));
  OAI22_X1   g094(.A1(new_n115_), .A2(\totalcoeffs[4] ), .B1(new_n27_), .B2(new_n43_), .ZN(\coeff_token[0] ));
  OAI21_X1   g095(.A1(new_n78_), .A2(new_n22_), .B(new_n46_), .ZN(new_n117_));
  NOR2_X1    g096(.A1(new_n94_), .A2(new_n46_), .ZN(new_n118_));
  NOR2_X1    g097(.A1(new_n118_), .A2(\trailingones[0] ), .ZN(new_n119_));
  NOR2_X1    g098(.A1(new_n36_), .A2(\totalcoeffs[2] ), .ZN(new_n120_));
  AOI22_X1   g099(.A1(new_n119_), .A2(new_n117_), .B1(new_n108_), .B2(new_n120_), .ZN(new_n121_));
  OAI21_X1   g100(.A1(new_n121_), .A2(new_n23_), .B(new_n96_), .ZN(new_n122_));
  NAND2_X1   g101(.A1(new_n28_), .A2(new_n29_), .ZN(new_n123_));
  NOR3_X1    g102(.A1(new_n123_), .A2(\totalcoeffs[3] ), .A3(\totalcoeffs[4] ), .ZN(new_n124_));
  NAND2_X1   g103(.A1(new_n122_), .A2(new_n124_), .ZN(new_n125_));
  INV_X1     g104(.I(new_n82_), .ZN(new_n126_));
  OAI21_X1   g105(.A1(new_n29_), .A2(\totalcoeffs[1] ), .B(\totalcoeffs[2] ), .ZN(new_n127_));
  NAND3_X1   g106(.A1(new_n127_), .A2(new_n126_), .A3(\totalcoeffs[3] ), .ZN(new_n128_));
  NOR2_X1    g107(.A1(new_n36_), .A2(\totalcoeffs[0] ), .ZN(new_n129_));
  INV_X1     g108(.I(new_n129_), .ZN(new_n130_));
  NAND2_X1   g109(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[1] ), .ZN(new_n131_));
  NAND2_X1   g110(.A1(new_n71_), .A2(new_n29_), .ZN(new_n132_));
  NAND4_X1   g111(.A1(new_n130_), .A2(new_n46_), .A3(new_n131_), .A4(new_n132_), .ZN(new_n133_));
  AOI21_X1   g112(.A1(new_n133_), .A2(new_n128_), .B(\ctable[0] ), .ZN(new_n134_));
  AOI21_X1   g113(.A1(\totalcoeffs[3] ), .A2(\trailingones[0] ), .B(\totalcoeffs[2] ), .ZN(new_n135_));
  NOR2_X1    g114(.A1(new_n135_), .A2(\totalcoeffs[0] ), .ZN(new_n136_));
  NAND2_X1   g115(.A1(new_n120_), .A2(\totalcoeffs[0] ), .ZN(new_n137_));
  NOR2_X1    g116(.A1(new_n22_), .A2(\ctable[0] ), .ZN(new_n138_));
  INV_X1     g117(.I(new_n138_), .ZN(new_n139_));
  NAND2_X1   g118(.A1(new_n22_), .A2(\ctable[0] ), .ZN(new_n140_));
  NAND3_X1   g119(.A1(new_n137_), .A2(new_n139_), .A3(new_n140_), .ZN(new_n141_));
  AOI21_X1   g120(.A1(new_n141_), .A2(\totalcoeffs[1] ), .B(new_n136_), .ZN(new_n142_));
  NAND2_X1   g121(.A1(new_n46_), .A2(new_n36_), .ZN(new_n143_));
  NAND2_X1   g122(.A1(new_n28_), .A2(\trailingones[0] ), .ZN(new_n144_));
  NOR2_X1    g123(.A1(\totalcoeffs[3] ), .A2(\trailingones[0] ), .ZN(new_n145_));
  INV_X1     g124(.I(new_n145_), .ZN(new_n146_));
  NAND2_X1   g125(.A1(new_n146_), .A2(new_n144_), .ZN(new_n147_));
  OAI22_X1   g126(.A1(new_n147_), .A2(new_n22_), .B1(new_n28_), .B2(new_n143_), .ZN(new_n148_));
  NAND2_X1   g127(.A1(new_n148_), .A2(new_n71_), .ZN(new_n149_));
  AOI21_X1   g128(.A1(new_n149_), .A2(new_n142_), .B(\ctable[1] ), .ZN(new_n150_));
  OAI21_X1   g129(.A1(new_n150_), .A2(new_n134_), .B(new_n33_), .ZN(new_n151_));
  NAND2_X1   g130(.A1(new_n36_), .A2(\totalcoeffs[3] ), .ZN(new_n152_));
  OAI22_X1   g131(.A1(new_n25_), .A2(new_n152_), .B1(new_n71_), .B2(new_n28_), .ZN(new_n153_));
  NAND2_X1   g132(.A1(new_n153_), .A2(\totalcoeffs[0] ), .ZN(new_n154_));
  INV_X1     g133(.I(new_n99_), .ZN(new_n155_));
  AOI22_X1   g134(.A1(\ctable[0] ), .A2(new_n103_), .B1(new_n155_), .B2(\totalcoeffs[3] ), .ZN(new_n156_));
  AOI21_X1   g135(.A1(new_n154_), .A2(new_n156_), .B(new_n29_), .ZN(new_n157_));
  NAND2_X1   g136(.A1(new_n36_), .A2(\ctable[0] ), .ZN(new_n158_));
  NOR3_X1    g137(.A1(new_n158_), .A2(new_n44_), .A3(new_n99_), .ZN(new_n159_));
  OAI21_X1   g138(.A1(new_n157_), .A2(new_n159_), .B(\trailingones[1] ), .ZN(new_n160_));
  AOI21_X1   g139(.A1(new_n151_), .A2(new_n160_), .B(\totalcoeffs[4] ), .ZN(new_n161_));
  NOR2_X1    g140(.A1(\ctable[1] ), .A2(\trailingones[0] ), .ZN(new_n162_));
  AOI21_X1   g141(.A1(new_n22_), .A2(\ctable[1] ), .B(\totalcoeffs[2] ), .ZN(new_n163_));
  NOR2_X1    g142(.A1(new_n163_), .A2(new_n144_), .ZN(new_n164_));
  OAI21_X1   g143(.A1(new_n164_), .A2(new_n162_), .B(new_n33_), .ZN(new_n165_));
  NAND2_X1   g144(.A1(\ctable[1] ), .A2(\trailingones[0] ), .ZN(new_n166_));
  INV_X1     g145(.I(new_n166_), .ZN(new_n167_));
  NOR2_X1    g146(.A1(new_n29_), .A2(new_n33_), .ZN(new_n168_));
  AOI21_X1   g147(.A1(new_n28_), .A2(\trailingones[0] ), .B(new_n168_), .ZN(new_n169_));
  NOR3_X1    g148(.A1(new_n169_), .A2(new_n22_), .A3(new_n167_), .ZN(new_n170_));
  NOR2_X1    g149(.A1(new_n33_), .A2(\trailingones[0] ), .ZN(new_n171_));
  INV_X1     g150(.I(new_n171_), .ZN(new_n172_));
  NOR2_X1    g151(.A1(new_n172_), .A2(new_n140_), .ZN(new_n173_));
  OAI21_X1   g152(.A1(new_n170_), .A2(new_n173_), .B(new_n46_), .ZN(new_n174_));
  AOI21_X1   g153(.A1(new_n174_), .A2(new_n165_), .B(new_n71_), .ZN(new_n175_));
  INV_X1     g154(.I(new_n37_), .ZN(new_n176_));
  NOR3_X1    g155(.A1(new_n176_), .A2(new_n46_), .A3(\trailingones[1] ), .ZN(new_n177_));
  OAI21_X1   g156(.A1(new_n175_), .A2(new_n177_), .B(new_n39_), .ZN(new_n178_));
  INV_X1     g157(.I(new_n158_), .ZN(new_n179_));
  OAI21_X1   g158(.A1(new_n179_), .A2(new_n40_), .B(new_n29_), .ZN(new_n180_));
  NAND2_X1   g159(.A1(new_n29_), .A2(\trailingones[1] ), .ZN(new_n181_));
  NAND2_X1   g160(.A1(new_n181_), .A2(new_n62_), .ZN(new_n182_));
  AOI21_X1   g161(.A1(new_n180_), .A2(new_n32_), .B(new_n182_), .ZN(new_n183_));
  NOR2_X1    g162(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n184_));
  NAND2_X1   g163(.A1(new_n184_), .A2(new_n28_), .ZN(new_n185_));
  NAND2_X1   g164(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n186_));
  OAI21_X1   g165(.A1(new_n29_), .A2(new_n186_), .B(new_n185_), .ZN(new_n187_));
  NOR2_X1    g166(.A1(new_n169_), .A2(\totalcoeffs[0] ), .ZN(new_n188_));
  OAI21_X1   g167(.A1(new_n188_), .A2(new_n187_), .B(\totalcoeffs[2] ), .ZN(new_n189_));
  INV_X1     g168(.I(new_n184_), .ZN(new_n190_));
  INV_X1     g169(.I(new_n186_), .ZN(new_n191_));
  NAND2_X1   g170(.A1(new_n191_), .A2(\totalcoeffs[0] ), .ZN(new_n192_));
  OAI21_X1   g171(.A1(\totalcoeffs[2] ), .A2(new_n190_), .B(new_n192_), .ZN(new_n193_));
  NAND3_X1   g172(.A1(new_n193_), .A2(\ctable[0] ), .A3(new_n87_), .ZN(new_n194_));
  AOI21_X1   g173(.A1(new_n189_), .A2(new_n194_), .B(\totalcoeffs[4] ), .ZN(new_n195_));
  OAI21_X1   g174(.A1(new_n195_), .A2(new_n183_), .B(new_n71_), .ZN(new_n196_));
  AOI21_X1   g175(.A1(new_n178_), .A2(new_n196_), .B(\totalcoeffs[3] ), .ZN(new_n197_));
  OAI21_X1   g176(.A1(new_n197_), .A2(new_n161_), .B(new_n23_), .ZN(new_n198_));
  NAND2_X1   g177(.A1(new_n198_), .A2(new_n125_), .ZN(\coeff_token[1] ));
  NOR3_X1    g178(.A1(new_n103_), .A2(new_n123_), .A3(\totalcoeffs[4] ), .ZN(new_n200_));
  NOR2_X1    g179(.A1(new_n83_), .A2(new_n22_), .ZN(new_n201_));
  NAND4_X1   g180(.A1(\totalcoeffs[0] ), .A2(\ctable[2] ), .A3(\trailingones[0] ), .A4(\trailingones[1] ), .ZN(new_n202_));
  AOI21_X1   g181(.A1(new_n55_), .A2(new_n202_), .B(new_n71_), .ZN(new_n203_));
  OAI21_X1   g182(.A1(new_n201_), .A2(new_n203_), .B(new_n200_), .ZN(new_n204_));
  AOI21_X1   g183(.A1(new_n192_), .A2(new_n190_), .B(new_n28_), .ZN(new_n205_));
  NAND2_X1   g184(.A1(new_n28_), .A2(\totalcoeffs[2] ), .ZN(new_n206_));
  NOR2_X1    g185(.A1(new_n206_), .A2(new_n33_), .ZN(new_n207_));
  OAI21_X1   g186(.A1(new_n205_), .A2(new_n207_), .B(\totalcoeffs[1] ), .ZN(new_n208_));
  INV_X1     g187(.I(new_n75_), .ZN(new_n209_));
  NOR2_X1    g188(.A1(new_n36_), .A2(\trailingones[1] ), .ZN(new_n210_));
  NOR2_X1    g189(.A1(new_n171_), .A2(new_n210_), .ZN(new_n211_));
  NAND2_X1   g190(.A1(new_n211_), .A2(new_n209_), .ZN(new_n212_));
  NAND2_X1   g191(.A1(new_n212_), .A2(\totalcoeffs[2] ), .ZN(new_n213_));
  AOI21_X1   g192(.A1(new_n208_), .A2(new_n213_), .B(\totalcoeffs[3] ), .ZN(new_n214_));
  OAI21_X1   g193(.A1(new_n44_), .A2(\totalcoeffs[1] ), .B(\ctable[0] ), .ZN(new_n215_));
  NAND3_X1   g194(.A1(new_n215_), .A2(new_n46_), .A3(new_n184_), .ZN(new_n216_));
  NAND3_X1   g195(.A1(new_n103_), .A2(new_n191_), .A3(new_n71_), .ZN(new_n217_));
  AOI21_X1   g196(.A1(new_n217_), .A2(new_n216_), .B(new_n22_), .ZN(new_n218_));
  OAI21_X1   g197(.A1(new_n214_), .A2(new_n218_), .B(new_n29_), .ZN(new_n219_));
  NOR2_X1    g198(.A1(new_n78_), .A2(new_n29_), .ZN(new_n220_));
  OAI21_X1   g199(.A1(new_n220_), .A2(new_n108_), .B(\trailingones[0] ), .ZN(new_n221_));
  NAND2_X1   g200(.A1(new_n109_), .A2(new_n145_), .ZN(new_n222_));
  AOI21_X1   g201(.A1(new_n221_), .A2(new_n222_), .B(\totalcoeffs[2] ), .ZN(new_n223_));
  NAND2_X1   g202(.A1(\totalcoeffs[2] ), .A2(\trailingones[0] ), .ZN(new_n224_));
  OAI22_X1   g203(.A1(new_n95_), .A2(\trailingones[0] ), .B1(\trailingones[1] ), .B2(new_n224_), .ZN(new_n225_));
  INV_X1     g204(.I(new_n108_), .ZN(new_n226_));
  NAND2_X1   g205(.A1(new_n46_), .A2(\totalcoeffs[1] ), .ZN(new_n227_));
  NAND4_X1   g206(.A1(new_n226_), .A2(\ctable[1] ), .A3(new_n126_), .A4(new_n227_), .ZN(new_n228_));
  AOI21_X1   g207(.A1(new_n228_), .A2(new_n225_), .B(new_n44_), .ZN(new_n229_));
  OAI21_X1   g208(.A1(new_n223_), .A2(new_n229_), .B(new_n138_), .ZN(new_n230_));
  AOI21_X1   g209(.A1(new_n219_), .A2(new_n230_), .B(\totalcoeffs[4] ), .ZN(new_n231_));
  NAND2_X1   g210(.A1(new_n36_), .A2(\ctable[1] ), .ZN(new_n232_));
  INV_X1     g211(.I(new_n232_), .ZN(new_n233_));
  OAI21_X1   g212(.A1(new_n233_), .A2(new_n191_), .B(new_n28_), .ZN(new_n234_));
  NAND3_X1   g213(.A1(new_n234_), .A2(new_n26_), .A3(\totalcoeffs[4] ), .ZN(new_n235_));
  NAND2_X1   g214(.A1(new_n44_), .A2(\ctable[0] ), .ZN(new_n236_));
  NAND2_X1   g215(.A1(new_n236_), .A2(new_n36_), .ZN(new_n237_));
  OAI21_X1   g216(.A1(new_n66_), .A2(new_n100_), .B(\totalcoeffs[3] ), .ZN(new_n238_));
  NAND3_X1   g217(.A1(new_n238_), .A2(\totalcoeffs[1] ), .A3(new_n237_), .ZN(new_n239_));
  NOR3_X1    g218(.A1(new_n29_), .A2(\totalcoeffs[3] ), .A3(\ctable[0] ), .ZN(new_n240_));
  NAND2_X1   g219(.A1(new_n240_), .A2(new_n82_), .ZN(new_n241_));
  AOI21_X1   g220(.A1(new_n239_), .A2(new_n241_), .B(\trailingones[1] ), .ZN(new_n242_));
  NOR3_X1    g221(.A1(new_n71_), .A2(new_n33_), .A3(\totalcoeffs[3] ), .ZN(new_n243_));
  NAND2_X1   g222(.A1(new_n233_), .A2(new_n243_), .ZN(new_n244_));
  OAI21_X1   g223(.A1(new_n71_), .A2(\totalcoeffs[3] ), .B(new_n172_), .ZN(new_n245_));
  NAND2_X1   g224(.A1(new_n44_), .A2(\trailingones[1] ), .ZN(new_n246_));
  NAND3_X1   g225(.A1(new_n245_), .A2(new_n29_), .A3(new_n246_), .ZN(new_n247_));
  OAI22_X1   g226(.A1(new_n37_), .A2(new_n46_), .B1(new_n135_), .B2(\totalcoeffs[1] ), .ZN(new_n248_));
  NAND2_X1   g227(.A1(new_n248_), .A2(\ctable[0] ), .ZN(new_n249_));
  NAND2_X1   g228(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n250_));
  AOI21_X1   g229(.A1(new_n250_), .A2(\ctable[1] ), .B(\trailingones[1] ), .ZN(new_n251_));
  OAI22_X1   g230(.A1(new_n251_), .A2(\totalcoeffs[2] ), .B1(new_n126_), .B2(new_n33_), .ZN(new_n252_));
  NAND2_X1   g231(.A1(new_n252_), .A2(\totalcoeffs[3] ), .ZN(new_n253_));
  NAND4_X1   g232(.A1(new_n247_), .A2(new_n244_), .A3(new_n249_), .A4(new_n253_), .ZN(new_n254_));
  OAI21_X1   g233(.A1(new_n254_), .A2(new_n242_), .B(new_n39_), .ZN(new_n255_));
  AOI21_X1   g234(.A1(new_n255_), .A2(new_n235_), .B(\totalcoeffs[0] ), .ZN(new_n256_));
  OAI21_X1   g235(.A1(new_n256_), .A2(new_n231_), .B(new_n23_), .ZN(new_n257_));
  NAND2_X1   g236(.A1(new_n257_), .A2(new_n204_), .ZN(\coeff_token[2] ));
  NAND4_X1   g237(.A1(new_n29_), .A2(\ctable[0] ), .A3(\trailingones[0] ), .A4(\trailingones[1] ), .ZN(new_n259_));
  AOI21_X1   g238(.A1(new_n185_), .A2(new_n259_), .B(new_n46_), .ZN(new_n260_));
  AOI22_X1   g239(.A1(new_n176_), .A2(\ctable[0] ), .B1(new_n44_), .B2(new_n232_), .ZN(new_n261_));
  OAI21_X1   g240(.A1(new_n261_), .A2(new_n260_), .B(\totalcoeffs[1] ), .ZN(new_n262_));
  NOR2_X1    g241(.A1(new_n29_), .A2(\ctable[0] ), .ZN(new_n263_));
  NAND2_X1   g242(.A1(new_n263_), .A2(\totalcoeffs[2] ), .ZN(new_n264_));
  AOI21_X1   g243(.A1(new_n262_), .A2(new_n264_), .B(\totalcoeffs[4] ), .ZN(new_n265_));
  NOR2_X1    g244(.A1(new_n103_), .A2(new_n39_), .ZN(new_n266_));
  NOR2_X1    g245(.A1(new_n123_), .A2(new_n186_), .ZN(new_n267_));
  OAI21_X1   g246(.A1(new_n30_), .A2(new_n267_), .B(new_n266_), .ZN(new_n268_));
  OAI21_X1   g247(.A1(new_n46_), .A2(new_n29_), .B(new_n44_), .ZN(new_n269_));
  NAND3_X1   g248(.A1(new_n269_), .A2(new_n39_), .A3(new_n181_), .ZN(new_n270_));
  AOI21_X1   g249(.A1(new_n268_), .A2(new_n270_), .B(\totalcoeffs[1] ), .ZN(new_n271_));
  OAI21_X1   g250(.A1(new_n265_), .A2(new_n271_), .B(new_n22_), .ZN(new_n272_));
  NOR3_X1    g251(.A1(new_n132_), .A2(new_n143_), .A3(new_n28_), .ZN(new_n273_));
  OAI21_X1   g252(.A1(new_n273_), .A2(new_n240_), .B(new_n33_), .ZN(new_n274_));
  NOR2_X1    g253(.A1(new_n28_), .A2(new_n33_), .ZN(new_n275_));
  AOI21_X1   g254(.A1(new_n275_), .A2(new_n36_), .B(\totalcoeffs[3] ), .ZN(new_n276_));
  AOI22_X1   g255(.A1(new_n147_), .A2(\totalcoeffs[2] ), .B1(\ctable[0] ), .B2(new_n120_), .ZN(new_n277_));
  OAI22_X1   g256(.A1(new_n277_), .A2(\trailingones[1] ), .B1(\totalcoeffs[2] ), .B2(new_n276_), .ZN(new_n278_));
  NOR2_X1    g257(.A1(new_n44_), .A2(\ctable[0] ), .ZN(new_n279_));
  AOI21_X1   g258(.A1(new_n29_), .A2(new_n152_), .B(new_n279_), .ZN(new_n280_));
  OAI21_X1   g259(.A1(new_n278_), .A2(new_n280_), .B(\totalcoeffs[1] ), .ZN(new_n281_));
  AOI21_X1   g260(.A1(new_n281_), .A2(new_n274_), .B(new_n22_), .ZN(new_n282_));
  NAND3_X1   g261(.A1(new_n108_), .A2(new_n263_), .A3(\trailingones[0] ), .ZN(new_n283_));
  NOR2_X1    g262(.A1(new_n91_), .A2(new_n162_), .ZN(new_n284_));
  NOR2_X1    g263(.A1(new_n284_), .A2(\totalcoeffs[2] ), .ZN(new_n285_));
  NOR2_X1    g264(.A1(new_n71_), .A2(new_n33_), .ZN(new_n286_));
  AOI21_X1   g265(.A1(\ctable[0] ), .A2(\trailingones[0] ), .B(new_n286_), .ZN(new_n287_));
  NOR3_X1    g266(.A1(new_n287_), .A2(\ctable[1] ), .A3(new_n275_), .ZN(new_n288_));
  OAI21_X1   g267(.A1(new_n288_), .A2(new_n285_), .B(\totalcoeffs[3] ), .ZN(new_n289_));
  NOR2_X1    g268(.A1(new_n44_), .A2(\ctable[1] ), .ZN(new_n290_));
  INV_X1     g269(.I(new_n290_), .ZN(new_n291_));
  NAND3_X1   g270(.A1(new_n28_), .A2(new_n33_), .A3(\ctable[1] ), .ZN(new_n292_));
  AOI21_X1   g271(.A1(new_n291_), .A2(new_n292_), .B(\trailingones[0] ), .ZN(new_n293_));
  NAND2_X1   g272(.A1(new_n290_), .A2(\totalcoeffs[2] ), .ZN(new_n294_));
  NAND2_X1   g273(.A1(new_n103_), .A2(new_n263_), .ZN(new_n295_));
  AOI21_X1   g274(.A1(new_n295_), .A2(new_n294_), .B(new_n33_), .ZN(new_n296_));
  OAI21_X1   g275(.A1(new_n296_), .A2(new_n293_), .B(new_n71_), .ZN(new_n297_));
  NAND3_X1   g276(.A1(new_n289_), .A2(new_n283_), .A3(new_n297_), .ZN(new_n298_));
  OAI21_X1   g277(.A1(new_n282_), .A2(new_n298_), .B(new_n39_), .ZN(new_n299_));
  AOI21_X1   g278(.A1(new_n299_), .A2(new_n272_), .B(\ctable[2] ), .ZN(\coeff_token[3] ));
  INV_X1     g279(.I(new_n30_), .ZN(new_n301_));
  NOR2_X1    g280(.A1(new_n25_), .A2(\totalcoeffs[0] ), .ZN(new_n302_));
  NOR2_X1    g281(.A1(new_n44_), .A2(\totalcoeffs[4] ), .ZN(new_n303_));
  INV_X1     g282(.I(new_n303_), .ZN(new_n304_));
  NAND2_X1   g283(.A1(new_n44_), .A2(\totalcoeffs[4] ), .ZN(new_n305_));
  NAND2_X1   g284(.A1(new_n304_), .A2(new_n305_), .ZN(new_n306_));
  AOI22_X1   g285(.A1(new_n306_), .A2(new_n302_), .B1(new_n39_), .B2(new_n118_), .ZN(new_n307_));
  NOR3_X1    g286(.A1(new_n307_), .A2(\ctable[2] ), .A3(new_n301_), .ZN(\coeff_token[4] ));
  NAND2_X1   g287(.A1(new_n266_), .A2(new_n94_), .ZN(new_n309_));
  OAI21_X1   g288(.A1(new_n302_), .A2(new_n304_), .B(new_n309_), .ZN(new_n310_));
  AND3_X2    g289(.A1(new_n310_), .A2(new_n23_), .A3(new_n30_), .Z(\coeff_token[5] ));
  NAND2_X1   g290(.A1(new_n309_), .A2(new_n301_), .ZN(new_n312_));
  INV_X1     g291(.I(new_n69_), .ZN(new_n313_));
  AOI21_X1   g292(.A1(new_n29_), .A2(new_n206_), .B(new_n313_), .ZN(new_n314_));
  NAND2_X1   g293(.A1(new_n46_), .A2(\ctable[0] ), .ZN(new_n315_));
  AOI21_X1   g294(.A1(new_n55_), .A2(new_n56_), .B(new_n315_), .ZN(new_n316_));
  OAI21_X1   g295(.A1(new_n314_), .A2(new_n316_), .B(new_n36_), .ZN(new_n317_));
  OAI21_X1   g296(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .B(\totalcoeffs[2] ), .ZN(new_n318_));
  NAND2_X1   g297(.A1(new_n192_), .A2(new_n318_), .ZN(new_n319_));
  NAND2_X1   g298(.A1(new_n319_), .A2(\ctable[1] ), .ZN(new_n320_));
  NAND3_X1   g299(.A1(new_n317_), .A2(\totalcoeffs[1] ), .A3(new_n320_), .ZN(new_n321_));
  NAND3_X1   g300(.A1(new_n69_), .A2(\totalcoeffs[2] ), .A3(\trailingones[0] ), .ZN(new_n322_));
  AOI22_X1   g301(.A1(new_n232_), .A2(new_n22_), .B1(\ctable[0] ), .B2(\trailingones[0] ), .ZN(new_n323_));
  NAND2_X1   g302(.A1(new_n323_), .A2(new_n48_), .ZN(new_n324_));
  NAND3_X1   g303(.A1(new_n324_), .A2(new_n71_), .A3(new_n322_), .ZN(new_n325_));
  NAND2_X1   g304(.A1(new_n36_), .A2(\totalcoeffs[1] ), .ZN(new_n326_));
  AOI21_X1   g305(.A1(new_n22_), .A2(\totalcoeffs[2] ), .B(new_n326_), .ZN(new_n327_));
  NAND3_X1   g306(.A1(\totalcoeffs[0] ), .A2(\ctable[1] ), .A3(\trailingones[0] ), .ZN(new_n328_));
  NOR2_X1    g307(.A1(new_n328_), .A2(\totalcoeffs[2] ), .ZN(new_n329_));
  OAI21_X1   g308(.A1(new_n327_), .A2(new_n329_), .B(\trailingones[1] ), .ZN(new_n330_));
  NAND3_X1   g309(.A1(new_n126_), .A2(new_n22_), .A3(new_n29_), .ZN(new_n331_));
  OAI22_X1   g310(.A1(new_n331_), .A2(new_n109_), .B1(new_n46_), .B2(new_n226_), .ZN(new_n332_));
  INV_X1     g311(.I(new_n286_), .ZN(new_n333_));
  AOI21_X1   g312(.A1(new_n333_), .A2(new_n83_), .B(new_n22_), .ZN(new_n334_));
  OAI21_X1   g313(.A1(new_n332_), .A2(new_n334_), .B(new_n28_), .ZN(new_n335_));
  NOR2_X1    g314(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .ZN(new_n336_));
  OR3_X2     g315(.A1(new_n226_), .A2(new_n138_), .A3(new_n336_), .Z(new_n337_));
  NAND3_X1   g316(.A1(new_n335_), .A2(new_n330_), .A3(new_n337_), .ZN(new_n338_));
  AOI22_X1   g317(.A1(new_n338_), .A2(\totalcoeffs[3] ), .B1(new_n321_), .B2(new_n325_), .ZN(new_n339_));
  OAI21_X1   g318(.A1(new_n131_), .A2(new_n186_), .B(new_n190_), .ZN(new_n340_));
  NAND3_X1   g319(.A1(new_n340_), .A2(new_n46_), .A3(\ctable[2] ), .ZN(new_n341_));
  AOI21_X1   g320(.A1(\ctable[2] ), .A2(new_n33_), .B(new_n36_), .ZN(new_n342_));
  NOR3_X1    g321(.A1(new_n342_), .A2(\totalcoeffs[1] ), .A3(new_n46_), .ZN(new_n343_));
  OAI21_X1   g322(.A1(new_n343_), .A2(new_n50_), .B(new_n22_), .ZN(new_n344_));
  AOI21_X1   g323(.A1(new_n344_), .A2(new_n341_), .B(new_n123_), .ZN(new_n345_));
  OAI21_X1   g324(.A1(new_n313_), .A2(new_n46_), .B(new_n83_), .ZN(new_n346_));
  AOI21_X1   g325(.A1(new_n190_), .A2(new_n186_), .B(new_n29_), .ZN(new_n347_));
  NAND2_X1   g326(.A1(new_n143_), .A2(new_n224_), .ZN(new_n348_));
  AOI22_X1   g327(.A1(new_n346_), .A2(\ctable[0] ), .B1(new_n347_), .B2(new_n348_), .ZN(new_n349_));
  NAND2_X1   g328(.A1(new_n22_), .A2(\totalcoeffs[2] ), .ZN(new_n350_));
  OAI21_X1   g329(.A1(\totalcoeffs[1] ), .A2(\ctable[0] ), .B(\totalcoeffs[2] ), .ZN(new_n351_));
  AOI22_X1   g330(.A1(new_n286_), .A2(\ctable[0] ), .B1(new_n38_), .B2(new_n351_), .ZN(new_n352_));
  OAI22_X1   g331(.A1(new_n352_), .A2(new_n22_), .B1(new_n91_), .B2(new_n350_), .ZN(new_n353_));
  NAND2_X1   g332(.A1(new_n353_), .A2(\trailingones[0] ), .ZN(new_n354_));
  NAND2_X1   g333(.A1(new_n354_), .A2(new_n349_), .ZN(new_n355_));
  AOI21_X1   g334(.A1(new_n355_), .A2(new_n23_), .B(new_n345_), .ZN(new_n356_));
  OAI22_X1   g335(.A1(new_n339_), .A2(\ctable[2] ), .B1(new_n356_), .B2(\totalcoeffs[3] ), .ZN(new_n357_));
  AOI22_X1   g336(.A1(new_n357_), .A2(new_n39_), .B1(new_n23_), .B2(new_n312_), .ZN(\ctoken_len[0] ));
  NAND3_X1   g337(.A1(new_n107_), .A2(\totalcoeffs[4] ), .A3(new_n23_), .ZN(new_n359_));
  NOR3_X1    g338(.A1(new_n359_), .A2(new_n63_), .A3(new_n132_), .ZN(new_n360_));
  NAND2_X1   g339(.A1(new_n190_), .A2(new_n186_), .ZN(new_n361_));
  NAND2_X1   g340(.A1(new_n210_), .A2(\ctable[2] ), .ZN(new_n362_));
  OAI22_X1   g341(.A1(new_n361_), .A2(new_n350_), .B1(new_n362_), .B2(new_n87_), .ZN(new_n363_));
  NAND4_X1   g342(.A1(new_n363_), .A2(new_n71_), .A3(new_n29_), .A4(new_n107_), .ZN(new_n364_));
  NOR4_X1    g343(.A1(new_n190_), .A2(new_n22_), .A3(new_n46_), .A4(new_n44_), .ZN(new_n365_));
  OAI21_X1   g344(.A1(new_n211_), .A2(\totalcoeffs[3] ), .B(\totalcoeffs[2] ), .ZN(new_n366_));
  NAND3_X1   g345(.A1(new_n211_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[3] ), .ZN(new_n367_));
  AOI21_X1   g346(.A1(new_n366_), .A2(new_n367_), .B(new_n28_), .ZN(new_n368_));
  OAI21_X1   g347(.A1(new_n368_), .A2(new_n365_), .B(new_n71_), .ZN(new_n369_));
  NOR2_X1    g348(.A1(new_n44_), .A2(new_n28_), .ZN(new_n370_));
  NAND3_X1   g349(.A1(new_n47_), .A2(new_n370_), .A3(\trailingones[0] ), .ZN(new_n371_));
  OAI21_X1   g350(.A1(new_n370_), .A2(new_n95_), .B(new_n22_), .ZN(new_n372_));
  NAND3_X1   g351(.A1(new_n46_), .A2(\totalcoeffs[3] ), .A3(\ctable[0] ), .ZN(new_n373_));
  AOI21_X1   g352(.A1(new_n372_), .A2(new_n373_), .B(\trailingones[0] ), .ZN(new_n374_));
  MUX2_X1    g353(.I0(new_n28_), .I1(new_n46_), .S(\totalcoeffs[0] ), .Z(new_n375_));
  NAND3_X1   g354(.A1(new_n46_), .A2(\totalcoeffs[0] ), .A3(\trailingones[1] ), .ZN(new_n376_));
  OAI21_X1   g355(.A1(new_n375_), .A2(\trailingones[1] ), .B(new_n376_), .ZN(new_n377_));
  NOR3_X1    g356(.A1(new_n158_), .A2(new_n46_), .A3(new_n33_), .ZN(new_n378_));
  AOI21_X1   g357(.A1(new_n377_), .A2(\trailingones[0] ), .B(new_n378_), .ZN(new_n379_));
  NAND2_X1   g358(.A1(new_n370_), .A2(new_n48_), .ZN(new_n380_));
  OAI21_X1   g359(.A1(new_n379_), .A2(\totalcoeffs[3] ), .B(new_n380_), .ZN(new_n381_));
  OAI21_X1   g360(.A1(new_n381_), .A2(new_n374_), .B(\totalcoeffs[1] ), .ZN(new_n382_));
  NAND3_X1   g361(.A1(new_n382_), .A2(new_n369_), .A3(new_n371_), .ZN(new_n383_));
  NOR4_X1    g362(.A1(new_n232_), .A2(\totalcoeffs[2] ), .A3(new_n44_), .A4(\trailingones[1] ), .ZN(new_n384_));
  NOR4_X1    g363(.A1(new_n191_), .A2(new_n53_), .A3(\totalcoeffs[2] ), .A4(\ctable[1] ), .ZN(new_n385_));
  AOI21_X1   g364(.A1(new_n22_), .A2(new_n347_), .B(new_n385_), .ZN(new_n386_));
  NAND2_X1   g365(.A1(new_n62_), .A2(new_n36_), .ZN(new_n387_));
  AOI21_X1   g366(.A1(new_n387_), .A2(new_n328_), .B(\trailingones[1] ), .ZN(new_n388_));
  AOI21_X1   g367(.A1(new_n146_), .A2(new_n29_), .B(new_n318_), .ZN(new_n389_));
  NOR2_X1    g368(.A1(new_n388_), .A2(new_n389_), .ZN(new_n390_));
  OAI21_X1   g369(.A1(new_n386_), .A2(new_n44_), .B(new_n390_), .ZN(new_n391_));
  AOI21_X1   g370(.A1(new_n391_), .A2(new_n71_), .B(new_n384_), .ZN(new_n392_));
  NOR2_X1    g371(.A1(new_n186_), .A2(\totalcoeffs[3] ), .ZN(new_n393_));
  NOR3_X1    g372(.A1(new_n36_), .A2(new_n33_), .A3(\totalcoeffs[0] ), .ZN(new_n394_));
  AOI21_X1   g373(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .B(\totalcoeffs[3] ), .ZN(new_n395_));
  NOR3_X1    g374(.A1(new_n394_), .A2(\ctable[1] ), .A3(new_n395_), .ZN(new_n396_));
  OAI21_X1   g375(.A1(new_n396_), .A2(new_n393_), .B(\totalcoeffs[2] ), .ZN(new_n397_));
  NAND4_X1   g376(.A1(new_n22_), .A2(new_n29_), .A3(\totalcoeffs[3] ), .A4(\trailingones[0] ), .ZN(new_n398_));
  AOI21_X1   g377(.A1(new_n398_), .A2(new_n232_), .B(new_n33_), .ZN(new_n399_));
  AOI22_X1   g378(.A1(new_n44_), .A2(\trailingones[0] ), .B1(\ctable[1] ), .B2(\trailingones[1] ), .ZN(new_n400_));
  OAI22_X1   g379(.A1(new_n400_), .A2(new_n22_), .B1(\trailingones[1] ), .B2(new_n166_), .ZN(new_n401_));
  OAI21_X1   g380(.A1(new_n401_), .A2(new_n399_), .B(new_n46_), .ZN(new_n402_));
  NAND2_X1   g381(.A1(new_n38_), .A2(new_n145_), .ZN(new_n403_));
  NAND3_X1   g382(.A1(new_n402_), .A2(new_n397_), .A3(new_n403_), .ZN(new_n404_));
  NAND2_X1   g383(.A1(new_n404_), .A2(\totalcoeffs[1] ), .ZN(new_n405_));
  AOI21_X1   g384(.A1(new_n392_), .A2(new_n405_), .B(\ctable[0] ), .ZN(new_n406_));
  AOI21_X1   g385(.A1(new_n383_), .A2(new_n29_), .B(new_n406_), .ZN(new_n407_));
  OAI21_X1   g386(.A1(new_n407_), .A2(\ctable[2] ), .B(new_n364_), .ZN(new_n408_));
  AOI21_X1   g387(.A1(new_n408_), .A2(new_n39_), .B(new_n360_), .ZN(\ctoken_len[1] ));
  INV_X1     g388(.I(new_n359_), .ZN(new_n410_));
  NAND2_X1   g389(.A1(new_n348_), .A2(new_n22_), .ZN(new_n411_));
  NAND2_X1   g390(.A1(new_n411_), .A2(new_n137_), .ZN(new_n412_));
  AOI22_X1   g391(.A1(new_n412_), .A2(new_n33_), .B1(new_n47_), .B2(new_n336_), .ZN(new_n413_));
  OAI22_X1   g392(.A1(new_n413_), .A2(\totalcoeffs[1] ), .B1(new_n333_), .B2(new_n387_), .ZN(new_n414_));
  NAND3_X1   g393(.A1(new_n414_), .A2(new_n29_), .A3(new_n107_), .ZN(new_n415_));
  OAI21_X1   g394(.A1(new_n120_), .A2(new_n44_), .B(\totalcoeffs[1] ), .ZN(new_n416_));
  AOI21_X1   g395(.A1(\totalcoeffs[2] ), .A2(new_n28_), .B(new_n370_), .ZN(new_n417_));
  NOR2_X1    g396(.A1(new_n417_), .A2(new_n416_), .ZN(new_n418_));
  AND4_X2    g397(.A1(new_n71_), .A2(new_n120_), .A3(new_n140_), .A4(\totalcoeffs[3] ), .Z(new_n419_));
  OAI21_X1   g398(.A1(new_n418_), .A2(new_n419_), .B(\trailingones[1] ), .ZN(new_n420_));
  NAND2_X1   g399(.A1(new_n129_), .A2(new_n28_), .ZN(new_n421_));
  AOI21_X1   g400(.A1(new_n421_), .A2(new_n236_), .B(new_n99_), .ZN(new_n422_));
  AOI21_X1   g401(.A1(\totalcoeffs[1] ), .A2(\ctable[0] ), .B(new_n279_), .ZN(new_n423_));
  NAND3_X1   g402(.A1(new_n423_), .A2(new_n46_), .A3(new_n45_), .ZN(new_n424_));
  NAND3_X1   g403(.A1(new_n138_), .A2(new_n71_), .A3(new_n44_), .ZN(new_n425_));
  AOI21_X1   g404(.A1(new_n424_), .A2(new_n425_), .B(new_n36_), .ZN(new_n426_));
  OAI21_X1   g405(.A1(new_n426_), .A2(new_n422_), .B(new_n33_), .ZN(new_n427_));
  NOR2_X1    g406(.A1(new_n209_), .A2(new_n315_), .ZN(new_n428_));
  OAI21_X1   g407(.A1(new_n428_), .A2(new_n243_), .B(new_n22_), .ZN(new_n429_));
  NAND4_X1   g408(.A1(new_n423_), .A2(new_n46_), .A3(new_n209_), .A4(new_n246_), .ZN(new_n430_));
  NAND2_X1   g409(.A1(new_n275_), .A2(new_n71_), .ZN(new_n431_));
  NAND3_X1   g410(.A1(new_n431_), .A2(new_n79_), .A3(new_n226_), .ZN(new_n432_));
  NAND3_X1   g411(.A1(new_n430_), .A2(new_n429_), .A3(new_n432_), .ZN(new_n433_));
  NAND2_X1   g412(.A1(new_n433_), .A2(new_n36_), .ZN(new_n434_));
  NAND3_X1   g413(.A1(new_n427_), .A2(new_n434_), .A3(new_n420_), .ZN(new_n435_));
  NAND2_X1   g414(.A1(new_n326_), .A2(new_n29_), .ZN(new_n436_));
  NAND2_X1   g415(.A1(new_n226_), .A2(\trailingones[0] ), .ZN(new_n437_));
  AOI22_X1   g416(.A1(new_n437_), .A2(new_n220_), .B1(\totalcoeffs[2] ), .B2(new_n436_), .ZN(new_n438_));
  AOI21_X1   g417(.A1(new_n190_), .A2(new_n71_), .B(new_n46_), .ZN(new_n439_));
  OAI21_X1   g418(.A1(new_n439_), .A2(new_n220_), .B(\totalcoeffs[0] ), .ZN(new_n440_));
  NAND2_X1   g419(.A1(new_n438_), .A2(new_n440_), .ZN(new_n441_));
  AOI22_X1   g420(.A1(new_n435_), .A2(new_n29_), .B1(new_n279_), .B2(new_n441_), .ZN(new_n442_));
  OAI21_X1   g421(.A1(new_n442_), .A2(\ctable[2] ), .B(new_n415_), .ZN(new_n443_));
  AOI22_X1   g422(.A1(new_n443_), .A2(new_n39_), .B1(new_n302_), .B2(new_n410_), .ZN(\ctoken_len[2] ));
  OAI21_X1   g423(.A1(new_n25_), .A2(\totalcoeffs[3] ), .B(\totalcoeffs[4] ), .ZN(new_n445_));
  OAI21_X1   g424(.A1(new_n46_), .A2(\totalcoeffs[3] ), .B(\ctable[2] ), .ZN(new_n446_));
  OAI21_X1   g425(.A1(new_n79_), .A2(\ctable[0] ), .B(\ctable[1] ), .ZN(new_n447_));
  OAI21_X1   g426(.A1(new_n26_), .A2(\ctable[2] ), .B(\totalcoeffs[0] ), .ZN(new_n448_));
  NAND4_X1   g427(.A1(new_n448_), .A2(new_n445_), .A3(new_n446_), .A4(new_n447_), .ZN(new_n449_));
  NAND3_X1   g428(.A1(new_n138_), .A2(new_n290_), .A3(\totalcoeffs[2] ), .ZN(new_n450_));
  AOI22_X1   g429(.A1(new_n450_), .A2(new_n23_), .B1(new_n71_), .B2(new_n190_), .ZN(new_n451_));
  NOR3_X1    g430(.A1(new_n91_), .A2(new_n46_), .A3(\totalcoeffs[3] ), .ZN(new_n452_));
  OAI21_X1   g431(.A1(\trailingones[0] ), .A2(new_n275_), .B(new_n452_), .ZN(new_n453_));
  OAI22_X1   g432(.A1(\ctable[1] ), .A2(new_n275_), .B1(new_n168_), .B2(new_n129_), .ZN(new_n454_));
  NAND2_X1   g433(.A1(new_n454_), .A2(\totalcoeffs[3] ), .ZN(new_n455_));
  NAND3_X1   g434(.A1(new_n123_), .A2(new_n44_), .A3(\totalcoeffs[4] ), .ZN(new_n456_));
  NAND3_X1   g435(.A1(new_n455_), .A2(new_n46_), .A3(new_n456_), .ZN(new_n457_));
  AOI21_X1   g436(.A1(new_n457_), .A2(new_n453_), .B(\totalcoeffs[1] ), .ZN(new_n458_));
  NAND2_X1   g437(.A1(new_n275_), .A2(\trailingones[0] ), .ZN(new_n459_));
  NAND2_X1   g438(.A1(new_n459_), .A2(new_n29_), .ZN(new_n460_));
  NOR2_X1    g439(.A1(new_n294_), .A2(\ctable[0] ), .ZN(new_n461_));
  AOI22_X1   g440(.A1(new_n460_), .A2(new_n44_), .B1(new_n461_), .B2(new_n186_), .ZN(new_n462_));
  OAI21_X1   g441(.A1(new_n29_), .A2(new_n33_), .B(\totalcoeffs[3] ), .ZN(new_n463_));
  OAI21_X1   g442(.A1(\totalcoeffs[3] ), .A2(new_n91_), .B(new_n130_), .ZN(new_n464_));
  NAND3_X1   g443(.A1(new_n464_), .A2(new_n46_), .A3(new_n463_), .ZN(new_n465_));
  AOI21_X1   g444(.A1(new_n462_), .A2(new_n465_), .B(new_n71_), .ZN(new_n466_));
  NOR4_X1    g445(.A1(new_n458_), .A2(new_n449_), .A3(new_n466_), .A4(new_n451_), .ZN(\ctoken_len[3] ));
  AOI21_X1   g446(.A1(new_n186_), .A2(\totalcoeffs[1] ), .B(\totalcoeffs[0] ), .ZN(new_n468_));
  NOR2_X1    g447(.A1(new_n304_), .A2(new_n468_), .ZN(new_n469_));
  AOI22_X1   g448(.A1(new_n469_), .A2(new_n439_), .B1(new_n94_), .B2(new_n266_), .ZN(new_n470_));
  NOR3_X1    g449(.A1(new_n470_), .A2(\ctable[2] ), .A3(new_n123_), .ZN(\ctoken_len[4] ));
endmodule


