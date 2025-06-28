// Benchmark "cavlc" written by ABC on Thu Sep 14 22:39:28 2023

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
    new_n36_, new_n38_, new_n39_, new_n40_, new_n41_, new_n42_, new_n43_,
    new_n44_, new_n45_, new_n46_, new_n47_, new_n49_, new_n50_, new_n51_,
    new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n59_, new_n60_, new_n61_, new_n62_, new_n63_, new_n64_, new_n65_,
    new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_, new_n80_,
    new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n87_,
    new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_,
    new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n124_, new_n125_, new_n126_,
    new_n127_, new_n128_, new_n129_, new_n130_, new_n131_, new_n132_,
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
    new_n200_, new_n201_, new_n202_, new_n203_, new_n204_, new_n205_,
    new_n206_, new_n207_, new_n208_, new_n209_, new_n210_, new_n211_,
    new_n212_, new_n213_, new_n215_, new_n216_, new_n217_, new_n218_,
    new_n219_, new_n220_, new_n222_, new_n223_, new_n224_, new_n225_,
    new_n226_, new_n227_, new_n228_, new_n229_, new_n230_, new_n231_,
    new_n232_, new_n233_, new_n234_, new_n235_, new_n236_, new_n237_,
    new_n238_, new_n239_, new_n240_, new_n241_, new_n242_, new_n243_,
    new_n244_, new_n245_, new_n246_, new_n247_, new_n248_, new_n249_,
    new_n250_, new_n251_, new_n252_, new_n253_, new_n254_, new_n255_,
    new_n256_, new_n257_, new_n258_, new_n259_, new_n260_, new_n261_,
    new_n262_, new_n263_, new_n264_, new_n265_, new_n266_, new_n267_,
    new_n268_, new_n269_, new_n270_, new_n271_, new_n272_, new_n273_,
    new_n274_, new_n275_, new_n276_, new_n277_, new_n278_, new_n279_,
    new_n280_, new_n281_, new_n282_, new_n283_, new_n284_, new_n285_,
    new_n286_, new_n288_, new_n289_, new_n290_, new_n291_, new_n292_,
    new_n293_, new_n294_, new_n295_, new_n296_, new_n297_, new_n298_,
    new_n299_, new_n300_, new_n301_, new_n302_, new_n303_, new_n304_,
    new_n305_, new_n306_, new_n307_, new_n308_, new_n309_, new_n310_,
    new_n311_, new_n312_, new_n313_, new_n314_, new_n315_, new_n316_,
    new_n317_, new_n318_, new_n319_, new_n320_, new_n321_, new_n322_,
    new_n323_, new_n324_, new_n325_, new_n326_, new_n327_, new_n328_,
    new_n329_, new_n331_, new_n332_, new_n333_, new_n334_, new_n335_,
    new_n336_, new_n338_, new_n340_, new_n341_, new_n342_, new_n343_,
    new_n344_, new_n345_, new_n346_, new_n347_, new_n348_, new_n349_,
    new_n351_, new_n352_, new_n353_, new_n354_, new_n355_, new_n356_,
    new_n357_, new_n358_, new_n359_, new_n360_, new_n361_, new_n362_,
    new_n363_, new_n364_, new_n365_, new_n366_, new_n367_, new_n368_,
    new_n369_, new_n370_, new_n371_, new_n372_, new_n373_, new_n374_,
    new_n375_, new_n376_, new_n377_, new_n378_, new_n379_, new_n380_,
    new_n381_, new_n382_, new_n383_, new_n384_, new_n385_, new_n386_,
    new_n387_, new_n388_, new_n389_, new_n390_, new_n391_, new_n392_,
    new_n393_, new_n395_, new_n396_, new_n397_, new_n398_, new_n399_,
    new_n400_, new_n401_, new_n402_, new_n403_, new_n404_, new_n405_,
    new_n406_, new_n407_, new_n408_, new_n409_, new_n410_, new_n411_,
    new_n412_, new_n413_, new_n414_, new_n415_, new_n416_, new_n417_,
    new_n418_, new_n419_, new_n420_, new_n421_, new_n422_, new_n423_,
    new_n424_, new_n425_, new_n426_, new_n427_, new_n428_, new_n429_,
    new_n430_, new_n431_, new_n432_, new_n433_, new_n434_, new_n435_,
    new_n436_, new_n437_, new_n438_, new_n439_, new_n440_, new_n441_,
    new_n442_, new_n443_, new_n444_, new_n445_, new_n446_, new_n448_,
    new_n449_, new_n450_, new_n451_, new_n452_, new_n453_, new_n454_,
    new_n455_, new_n456_, new_n457_, new_n458_, new_n459_, new_n460_,
    new_n461_, new_n462_, new_n463_, new_n464_, new_n465_, new_n466_,
    new_n467_, new_n468_, new_n469_, new_n470_, new_n471_, new_n472_,
    new_n473_, new_n474_, new_n475_, new_n476_, new_n477_, new_n478_,
    new_n479_, new_n480_, new_n481_, new_n482_, new_n483_, new_n484_,
    new_n486_, new_n487_, new_n488_, new_n489_, new_n490_, new_n491_,
    new_n492_, new_n493_, new_n494_, new_n495_, new_n496_, new_n497_,
    new_n498_, new_n499_, new_n500_, new_n501_, new_n502_, new_n503_,
    new_n504_, new_n505_, new_n506_, new_n507_, new_n508_, new_n509_,
    new_n510_, new_n512_, new_n513_, new_n514_, new_n515_, new_n516_;
  INV_X1     g000(.I(\totalcoeffs[0] ), .ZN(new_n22_));
  INV_X1     g001(.I(\totalcoeffs[1] ), .ZN(new_n23_));
  INV_X1     g002(.I(\ctable[2] ), .ZN(new_n24_));
  AOI21_X1   g003(.A1(new_n23_), .A2(new_n24_), .B(new_n22_), .ZN(new_n25_));
  INV_X1     g004(.I(\trailingones[1] ), .ZN(new_n26_));
  NOR2_X1    g005(.A1(new_n26_), .A2(\totalcoeffs[1] ), .ZN(new_n27_));
  INV_X1     g006(.I(new_n27_), .ZN(new_n28_));
  NAND2_X1   g007(.A1(new_n26_), .A2(\totalcoeffs[1] ), .ZN(new_n29_));
  NAND2_X1   g008(.A1(new_n28_), .A2(new_n29_), .ZN(new_n30_));
  INV_X1     g009(.I(new_n30_), .ZN(new_n31_));
  NAND2_X1   g010(.A1(\totalcoeffs[3] ), .A2(\trailingones[1] ), .ZN(new_n32_));
  INV_X1     g011(.I(new_n32_), .ZN(new_n33_));
  INV_X1     g012(.I(\totalcoeffs[2] ), .ZN(new_n34_));
  INV_X1     g013(.I(\ctable[0] ), .ZN(new_n35_));
  NOR2_X1    g014(.A1(new_n34_), .A2(new_n35_), .ZN(new_n36_));
  AOI21_X1   g015(.A1(new_n33_), .A2(\ctable[2] ), .B(\totalcoeffs[1] ), .ZN(new_n38_));
  OAI21_X1   g016(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[3] ), .B(\totalcoeffs[2] ), .ZN(new_n39_));
  OAI22_X1   g017(.A1(new_n31_), .A2(new_n25_), .B1(new_n38_), .B2(new_n39_), .ZN(new_n40_));
  INV_X1     g018(.I(\trailingones[0] ), .ZN(new_n41_));
  NAND2_X1   g019(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n42_));
  INV_X1     g020(.I(new_n42_), .ZN(new_n43_));
  NAND3_X1   g021(.A1(new_n43_), .A2(\ctable[0] ), .A3(\ctable[2] ), .ZN(new_n44_));
  NAND3_X1   g022(.A1(new_n42_), .A2(new_n35_), .A3(\ctable[2] ), .ZN(new_n45_));
  AOI21_X1   g023(.A1(new_n44_), .A2(new_n45_), .B(new_n23_), .ZN(new_n46_));
  NOR2_X1    g024(.A1(new_n23_), .A2(new_n34_), .ZN(new_n47_));
  NAND2_X1   g025(.A1(new_n22_), .A2(new_n34_), .ZN(new_n49_));
  NOR2_X1    g026(.A1(\ctable[0] ), .A2(\trailingones[1] ), .ZN(new_n50_));
  INV_X1     g027(.I(new_n50_), .ZN(new_n51_));
  NAND4_X1   g028(.A1(new_n51_), .A2(new_n49_), .A3(\totalcoeffs[1] ), .A4(new_n24_), .ZN(new_n52_));
  INV_X1     g029(.I(\ctable[1] ), .ZN(new_n53_));
  NOR2_X1    g030(.A1(new_n53_), .A2(\totalcoeffs[3] ), .ZN(new_n54_));
  OAI21_X1   g031(.A1(new_n46_), .A2(new_n52_), .B(new_n54_), .ZN(new_n55_));
  NOR2_X1    g032(.A1(\totalcoeffs[1] ), .A2(\trailingones[1] ), .ZN(new_n56_));
  NOR2_X1    g033(.A1(\totalcoeffs[3] ), .A2(\ctable[0] ), .ZN(new_n57_));
  INV_X1     g034(.I(new_n57_), .ZN(new_n58_));
  NOR2_X1    g035(.A1(new_n58_), .A2(\trailingones[1] ), .ZN(new_n59_));
  NOR2_X1    g036(.A1(new_n57_), .A2(new_n26_), .ZN(new_n60_));
  OAI22_X1   g037(.A1(new_n59_), .A2(new_n60_), .B1(new_n22_), .B2(new_n56_), .ZN(new_n61_));
  AOI21_X1   g038(.A1(new_n55_), .A2(new_n41_), .B(new_n61_), .ZN(new_n62_));
  NAND2_X1   g039(.A1(\ctable[0] ), .A2(\ctable[1] ), .ZN(new_n63_));
  NAND4_X1   g040(.A1(new_n63_), .A2(\totalcoeffs[4] ), .A3(new_n41_), .A4(\trailingones[1] ), .ZN(new_n64_));
  INV_X1     g041(.I(\totalcoeffs[4] ), .ZN(new_n65_));
  NAND4_X1   g042(.A1(new_n63_), .A2(new_n65_), .A3(new_n41_), .A4(new_n26_), .ZN(new_n66_));
  NAND2_X1   g043(.A1(new_n66_), .A2(new_n64_), .ZN(new_n67_));
  NOR2_X1    g044(.A1(\totalcoeffs[1] ), .A2(\totalcoeffs[2] ), .ZN(new_n68_));
  INV_X1     g045(.I(new_n68_), .ZN(new_n69_));
  NOR2_X1    g046(.A1(new_n69_), .A2(\totalcoeffs[3] ), .ZN(new_n70_));
  NOR2_X1    g047(.A1(new_n53_), .A2(\totalcoeffs[0] ), .ZN(new_n71_));
  NAND4_X1   g048(.A1(new_n67_), .A2(new_n24_), .A3(new_n70_), .A4(new_n71_), .ZN(new_n72_));
  NOR3_X1    g049(.A1(new_n53_), .A2(\trailingones[0] ), .A3(\trailingones[1] ), .ZN(new_n74_));
  NOR3_X1    g050(.A1(new_n65_), .A2(new_n53_), .A3(new_n41_), .ZN(new_n75_));
  OAI21_X1   g051(.A1(new_n75_), .A2(new_n74_), .B(\totalcoeffs[4] ), .ZN(new_n76_));
  AOI21_X1   g052(.A1(new_n72_), .A2(new_n35_), .B(new_n76_), .ZN(new_n77_));
  AOI21_X1   g053(.A1(new_n62_), .A2(new_n40_), .B(new_n77_), .ZN(new_n78_));
  NOR2_X1    g054(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n79_));
  NAND2_X1   g055(.A1(new_n79_), .A2(new_n26_), .ZN(new_n80_));
  INV_X1     g056(.I(new_n80_), .ZN(new_n81_));
  NOR2_X1    g057(.A1(\totalcoeffs[2] ), .A2(\totalcoeffs[3] ), .ZN(new_n82_));
  INV_X1     g058(.I(new_n82_), .ZN(new_n83_));
  NOR2_X1    g059(.A1(new_n83_), .A2(\totalcoeffs[0] ), .ZN(new_n84_));
  NAND2_X1   g060(.A1(\totalcoeffs[2] ), .A2(\totalcoeffs[3] ), .ZN(new_n85_));
  NOR2_X1    g061(.A1(new_n53_), .A2(\totalcoeffs[2] ), .ZN(new_n86_));
  NOR3_X1    g062(.A1(new_n86_), .A2(new_n26_), .A3(new_n85_), .ZN(new_n87_));
  XOR2_X1    g063(.A1(new_n87_), .A2(new_n27_), .Z(new_n88_));
  NAND2_X1   g064(.A1(new_n88_), .A2(\totalcoeffs[0] ), .ZN(new_n89_));
  NOR2_X1    g065(.A1(new_n34_), .A2(\totalcoeffs[3] ), .ZN(new_n90_));
  NOR2_X1    g066(.A1(new_n90_), .A2(new_n23_), .ZN(new_n91_));
  NOR2_X1    g067(.A1(new_n42_), .A2(new_n23_), .ZN(new_n92_));
  XOR2_X1    g068(.A1(new_n91_), .A2(new_n92_), .Z(new_n93_));
  AOI21_X1   g069(.A1(new_n93_), .A2(\trailingones[0] ), .B(\ctable[0] ), .ZN(new_n94_));
  AOI22_X1   g070(.A1(new_n94_), .A2(new_n89_), .B1(new_n81_), .B2(new_n84_), .ZN(new_n95_));
  NOR2_X1    g071(.A1(new_n22_), .A2(new_n26_), .ZN(new_n96_));
  NOR2_X1    g072(.A1(\totalcoeffs[0] ), .A2(\trailingones[1] ), .ZN(new_n97_));
  OAI21_X1   g073(.A1(new_n96_), .A2(new_n97_), .B(\totalcoeffs[1] ), .ZN(new_n98_));
  NAND2_X1   g074(.A1(new_n36_), .A2(\trailingones[0] ), .ZN(new_n99_));
  OAI21_X1   g075(.A1(new_n98_), .A2(new_n99_), .B(new_n53_), .ZN(new_n100_));
  INV_X1     g076(.I(\totalcoeffs[3] ), .ZN(new_n101_));
  NOR3_X1    g077(.A1(new_n27_), .A2(\totalcoeffs[2] ), .A3(\ctable[0] ), .ZN(new_n102_));
  NOR3_X1    g078(.A1(new_n102_), .A2(new_n22_), .A3(new_n101_), .ZN(new_n103_));
  AOI21_X1   g079(.A1(new_n100_), .A2(new_n103_), .B(\ctable[0] ), .ZN(new_n104_));
  NAND2_X1   g080(.A1(new_n22_), .A2(\trailingones[1] ), .ZN(new_n105_));
  INV_X1     g081(.I(new_n105_), .ZN(new_n106_));
  INV_X1     g082(.I(new_n96_), .ZN(new_n107_));
  INV_X1     g083(.I(new_n47_), .ZN(new_n108_));
  NOR3_X1    g084(.A1(new_n107_), .A2(new_n108_), .A3(new_n41_), .ZN(new_n109_));
  OAI21_X1   g085(.A1(new_n109_), .A2(new_n106_), .B(\totalcoeffs[1] ), .ZN(new_n110_));
  OAI21_X1   g086(.A1(new_n104_), .A2(new_n110_), .B(new_n24_), .ZN(new_n111_));
  NOR4_X1    g087(.A1(new_n53_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[3] ), .A4(\trailingones[1] ), .ZN(new_n112_));
  NOR2_X1    g088(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[3] ), .ZN(new_n113_));
  AOI21_X1   g089(.A1(new_n113_), .A2(\ctable[1] ), .B(new_n26_), .ZN(new_n114_));
  NOR2_X1    g090(.A1(\totalcoeffs[2] ), .A2(\trailingones[1] ), .ZN(new_n115_));
  NOR2_X1    g091(.A1(new_n115_), .A2(new_n23_), .ZN(new_n116_));
  NOR2_X1    g092(.A1(new_n116_), .A2(new_n41_), .ZN(new_n117_));
  OAI21_X1   g093(.A1(new_n112_), .A2(new_n114_), .B(new_n117_), .ZN(new_n118_));
  AOI21_X1   g094(.A1(\totalcoeffs[2] ), .A2(\ctable[1] ), .B(\totalcoeffs[0] ), .ZN(new_n119_));
  OAI22_X1   g095(.A1(new_n98_), .A2(new_n83_), .B1(new_n26_), .B2(new_n119_), .ZN(new_n120_));
  AOI21_X1   g096(.A1(new_n35_), .A2(new_n118_), .B(new_n120_), .ZN(new_n121_));
  OAI21_X1   g097(.A1(new_n95_), .A2(new_n111_), .B(new_n121_), .ZN(new_n122_));
  NOR2_X1    g098(.A1(new_n122_), .A2(new_n78_), .ZN(\coeff_token[0] ));
  NOR2_X1    g099(.A1(new_n41_), .A2(\ctable[0] ), .ZN(new_n124_));
  NAND4_X1   g100(.A1(new_n34_), .A2(\totalcoeffs[0] ), .A3(\ctable[1] ), .A4(\trailingones[0] ), .ZN(new_n125_));
  XOR2_X1    g101(.A1(new_n125_), .A2(new_n124_), .Z(new_n126_));
  NOR2_X1    g102(.A1(new_n126_), .A2(new_n34_), .ZN(new_n127_));
  NAND2_X1   g103(.A1(\ctable[1] ), .A2(\trailingones[0] ), .ZN(new_n128_));
  NAND2_X1   g104(.A1(\ctable[0] ), .A2(\trailingones[1] ), .ZN(new_n129_));
  INV_X1     g105(.I(new_n129_), .ZN(new_n130_));
  NAND2_X1   g106(.A1(\totalcoeffs[0] ), .A2(\ctable[0] ), .ZN(new_n131_));
  INV_X1     g107(.I(new_n131_), .ZN(new_n132_));
  NOR2_X1    g108(.A1(new_n128_), .A2(new_n26_), .ZN(new_n134_));
  NOR4_X1    g109(.A1(new_n128_), .A2(new_n34_), .A3(new_n65_), .A4(new_n26_), .ZN(new_n135_));
  OAI22_X1   g110(.A1(new_n127_), .A2(new_n134_), .B1(\totalcoeffs[1] ), .B2(new_n135_), .ZN(new_n136_));
  NOR3_X1    g111(.A1(new_n65_), .A2(new_n53_), .A3(new_n41_), .ZN(new_n137_));
  NOR3_X1    g112(.A1(new_n41_), .A2(\totalcoeffs[4] ), .A3(\ctable[1] ), .ZN(new_n138_));
  NOR2_X1    g113(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .ZN(new_n139_));
  NAND2_X1   g114(.A1(\ctable[1] ), .A2(\trailingones[1] ), .ZN(new_n140_));
  NOR3_X1    g115(.A1(new_n139_), .A2(new_n140_), .A3(new_n35_), .ZN(new_n141_));
  OAI21_X1   g116(.A1(new_n137_), .A2(new_n138_), .B(new_n141_), .ZN(new_n142_));
  AOI21_X1   g117(.A1(new_n142_), .A2(new_n26_), .B(new_n65_), .ZN(new_n143_));
  NAND2_X1   g118(.A1(\ctable[0] ), .A2(\trailingones[0] ), .ZN(new_n144_));
  NAND4_X1   g119(.A1(new_n144_), .A2(new_n53_), .A3(new_n41_), .A4(\trailingones[1] ), .ZN(new_n145_));
  NOR2_X1    g120(.A1(new_n26_), .A2(\ctable[1] ), .ZN(new_n146_));
  NAND3_X1   g121(.A1(\ctable[0] ), .A2(\trailingones[0] ), .A3(\trailingones[1] ), .ZN(new_n147_));
  AOI21_X1   g122(.A1(new_n145_), .A2(new_n147_), .B(new_n34_), .ZN(new_n148_));
  AOI21_X1   g123(.A1(new_n128_), .A2(new_n129_), .B(new_n65_), .ZN(new_n149_));
  OAI21_X1   g124(.A1(new_n148_), .A2(\totalcoeffs[0] ), .B(new_n149_), .ZN(new_n150_));
  NAND2_X1   g125(.A1(new_n22_), .A2(\trailingones[0] ), .ZN(new_n151_));
  NAND2_X1   g126(.A1(new_n41_), .A2(\totalcoeffs[0] ), .ZN(new_n152_));
  NAND2_X1   g127(.A1(new_n151_), .A2(new_n152_), .ZN(new_n153_));
  NAND2_X1   g128(.A1(new_n26_), .A2(\totalcoeffs[0] ), .ZN(new_n154_));
  NAND2_X1   g129(.A1(new_n34_), .A2(\totalcoeffs[0] ), .ZN(new_n155_));
  NAND2_X1   g130(.A1(new_n22_), .A2(\totalcoeffs[2] ), .ZN(new_n156_));
  AOI22_X1   g131(.A1(new_n105_), .A2(new_n154_), .B1(new_n155_), .B2(new_n156_), .ZN(new_n157_));
  NAND2_X1   g132(.A1(new_n157_), .A2(new_n153_), .ZN(new_n158_));
  AOI21_X1   g133(.A1(new_n150_), .A2(new_n35_), .B(new_n158_), .ZN(new_n159_));
  OAI21_X1   g134(.A1(new_n159_), .A2(new_n143_), .B(new_n23_), .ZN(new_n160_));
  NAND2_X1   g135(.A1(new_n160_), .A2(new_n136_), .ZN(new_n161_));
  NOR2_X1    g136(.A1(new_n107_), .A2(new_n108_), .ZN(new_n162_));
  NOR3_X1    g137(.A1(new_n58_), .A2(\totalcoeffs[4] ), .A3(\ctable[1] ), .ZN(new_n163_));
  AOI21_X1   g138(.A1(new_n162_), .A2(new_n163_), .B(\ctable[2] ), .ZN(new_n164_));
  NAND3_X1   g139(.A1(new_n34_), .A2(new_n26_), .A3(\totalcoeffs[1] ), .ZN(new_n165_));
  NOR2_X1    g140(.A1(new_n165_), .A2(new_n41_), .ZN(new_n166_));
  NOR2_X1    g141(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[1] ), .ZN(new_n167_));
  NOR2_X1    g142(.A1(new_n167_), .A2(new_n34_), .ZN(new_n168_));
  NOR3_X1    g143(.A1(new_n166_), .A2(\trailingones[0] ), .A3(new_n168_), .ZN(new_n169_));
  NAND2_X1   g144(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .ZN(new_n170_));
  INV_X1     g145(.I(new_n170_), .ZN(new_n171_));
  NOR2_X1    g146(.A1(new_n171_), .A2(\trailingones[1] ), .ZN(new_n172_));
  NAND2_X1   g147(.A1(\totalcoeffs[1] ), .A2(\ctable[2] ), .ZN(new_n173_));
  NOR4_X1    g148(.A1(new_n164_), .A2(new_n169_), .A3(new_n172_), .A4(new_n173_), .ZN(new_n174_));
  AOI21_X1   g149(.A1(new_n161_), .A2(new_n101_), .B(new_n174_), .ZN(new_n175_));
  NAND3_X1   g150(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[3] ), .A3(\trailingones[0] ), .ZN(new_n176_));
  NAND3_X1   g151(.A1(new_n101_), .A2(new_n41_), .A3(\totalcoeffs[0] ), .ZN(new_n177_));
  AOI21_X1   g152(.A1(new_n177_), .A2(new_n176_), .B(new_n35_), .ZN(new_n178_));
  NAND3_X1   g153(.A1(new_n34_), .A2(new_n35_), .A3(\totalcoeffs[0] ), .ZN(new_n179_));
  AOI21_X1   g154(.A1(new_n179_), .A2(new_n41_), .B(\totalcoeffs[2] ), .ZN(new_n180_));
  NOR3_X1    g155(.A1(new_n22_), .A2(\totalcoeffs[2] ), .A3(\ctable[0] ), .ZN(new_n181_));
  NOR3_X1    g156(.A1(new_n181_), .A2(new_n34_), .A3(\trailingones[0] ), .ZN(new_n182_));
  OAI21_X1   g157(.A1(new_n180_), .A2(new_n182_), .B(\totalcoeffs[0] ), .ZN(new_n183_));
  NOR2_X1    g158(.A1(new_n101_), .A2(new_n41_), .ZN(new_n184_));
  NOR3_X1    g159(.A1(new_n184_), .A2(new_n23_), .A3(\totalcoeffs[2] ), .ZN(new_n185_));
  INV_X1     g160(.I(new_n185_), .ZN(new_n186_));
  AOI21_X1   g161(.A1(new_n183_), .A2(new_n186_), .B(new_n23_), .ZN(new_n187_));
  OAI21_X1   g162(.A1(new_n79_), .A2(new_n85_), .B(new_n53_), .ZN(new_n188_));
  NAND2_X1   g163(.A1(new_n188_), .A2(\totalcoeffs[1] ), .ZN(new_n189_));
  NOR2_X1    g164(.A1(new_n23_), .A2(\totalcoeffs[0] ), .ZN(new_n190_));
  NOR2_X1    g165(.A1(new_n53_), .A2(\totalcoeffs[1] ), .ZN(new_n191_));
  NOR3_X1    g166(.A1(new_n190_), .A2(new_n191_), .A3(\totalcoeffs[2] ), .ZN(new_n192_));
  NOR2_X1    g167(.A1(\totalcoeffs[2] ), .A2(\trailingones[0] ), .ZN(new_n193_));
  NAND2_X1   g168(.A1(new_n193_), .A2(\ctable[0] ), .ZN(new_n194_));
  NOR2_X1    g169(.A1(new_n194_), .A2(new_n151_), .ZN(new_n195_));
  INV_X1     g170(.I(new_n195_), .ZN(new_n196_));
  AOI21_X1   g171(.A1(new_n189_), .A2(new_n192_), .B(new_n196_), .ZN(new_n197_));
  OAI21_X1   g172(.A1(new_n187_), .A2(new_n178_), .B(new_n197_), .ZN(new_n198_));
  INV_X1     g173(.I(new_n63_), .ZN(new_n199_));
  NOR2_X1    g174(.A1(new_n199_), .A2(new_n26_), .ZN(new_n200_));
  NOR2_X1    g175(.A1(new_n65_), .A2(new_n26_), .ZN(new_n201_));
  INV_X1     g176(.I(new_n201_), .ZN(new_n202_));
  AOI21_X1   g177(.A1(new_n198_), .A2(new_n200_), .B(new_n202_), .ZN(new_n203_));
  INV_X1     g178(.I(new_n178_), .ZN(new_n204_));
  OAI21_X1   g179(.A1(new_n181_), .A2(\trailingones[0] ), .B(new_n34_), .ZN(new_n205_));
  NAND3_X1   g180(.A1(new_n179_), .A2(\totalcoeffs[2] ), .A3(new_n41_), .ZN(new_n206_));
  AOI21_X1   g181(.A1(new_n206_), .A2(new_n205_), .B(new_n22_), .ZN(new_n207_));
  OAI21_X1   g182(.A1(new_n207_), .A2(new_n185_), .B(\totalcoeffs[1] ), .ZN(new_n208_));
  NAND2_X1   g183(.A1(new_n189_), .A2(new_n192_), .ZN(new_n209_));
  NAND2_X1   g184(.A1(new_n209_), .A2(new_n195_), .ZN(new_n210_));
  AOI21_X1   g185(.A1(new_n208_), .A2(new_n204_), .B(new_n210_), .ZN(new_n211_));
  NOR4_X1    g186(.A1(new_n211_), .A2(\totalcoeffs[4] ), .A3(new_n26_), .A4(new_n199_), .ZN(new_n212_));
  XOR2_X1    g187(.A1(new_n85_), .A2(new_n23_), .Z(new_n213_));
  NOR2_X1    g188(.A1(new_n23_), .A2(new_n34_), .ZN(new_n215_));
  AOI21_X1   g189(.A1(new_n213_), .A2(\ctable[0] ), .B(new_n215_), .ZN(new_n216_));
  NOR4_X1    g190(.A1(new_n69_), .A2(new_n22_), .A3(new_n101_), .A4(\trailingones[0] ), .ZN(new_n217_));
  OAI21_X1   g191(.A1(new_n217_), .A2(\ctable[0] ), .B(\totalcoeffs[1] ), .ZN(new_n218_));
  NOR2_X1    g192(.A1(new_n216_), .A2(new_n218_), .ZN(new_n219_));
  OAI21_X1   g193(.A1(new_n212_), .A2(new_n203_), .B(new_n219_), .ZN(new_n220_));
  NOR2_X1    g194(.A1(new_n220_), .A2(new_n175_), .ZN(\coeff_token[1] ));
  AOI21_X1   g195(.A1(\totalcoeffs[2] ), .A2(new_n26_), .B(new_n41_), .ZN(new_n222_));
  NOR2_X1    g196(.A1(new_n23_), .A2(new_n101_), .ZN(new_n223_));
  AOI21_X1   g197(.A1(new_n222_), .A2(new_n223_), .B(\totalcoeffs[1] ), .ZN(new_n224_));
  NOR2_X1    g198(.A1(new_n35_), .A2(\totalcoeffs[2] ), .ZN(new_n225_));
  NOR2_X1    g199(.A1(new_n42_), .A2(new_n22_), .ZN(new_n226_));
  NOR2_X1    g200(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .ZN(new_n227_));
  NOR4_X1    g201(.A1(new_n226_), .A2(new_n129_), .A3(new_n225_), .A4(new_n227_), .ZN(new_n228_));
  INV_X1     g202(.I(new_n225_), .ZN(new_n229_));
  NOR3_X1    g203(.A1(new_n226_), .A2(new_n129_), .A3(new_n227_), .ZN(new_n230_));
  NOR2_X1    g204(.A1(new_n230_), .A2(new_n229_), .ZN(new_n231_));
  OAI21_X1   g205(.A1(new_n231_), .A2(new_n228_), .B(\ctable[1] ), .ZN(new_n232_));
  OAI21_X1   g206(.A1(new_n232_), .A2(new_n224_), .B(new_n22_), .ZN(new_n233_));
  NAND3_X1   g207(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .A3(\trailingones[1] ), .ZN(new_n234_));
  INV_X1     g208(.I(new_n234_), .ZN(new_n235_));
  NAND2_X1   g209(.A1(new_n235_), .A2(new_n82_), .ZN(new_n236_));
  NOR2_X1    g210(.A1(new_n227_), .A2(\totalcoeffs[2] ), .ZN(new_n237_));
  NAND2_X1   g211(.A1(new_n23_), .A2(\totalcoeffs[3] ), .ZN(new_n238_));
  NOR2_X1    g212(.A1(new_n65_), .A2(new_n35_), .ZN(new_n239_));
  NAND2_X1   g213(.A1(new_n239_), .A2(new_n238_), .ZN(new_n240_));
  AOI21_X1   g214(.A1(new_n236_), .A2(new_n237_), .B(new_n240_), .ZN(new_n241_));
  AOI22_X1   g215(.A1(new_n233_), .A2(new_n241_), .B1(\totalcoeffs[0] ), .B2(new_n35_), .ZN(new_n242_));
  NAND3_X1   g216(.A1(new_n42_), .A2(\totalcoeffs[1] ), .A3(new_n34_), .ZN(new_n243_));
  NAND3_X1   g217(.A1(new_n43_), .A2(\totalcoeffs[1] ), .A3(\totalcoeffs[2] ), .ZN(new_n244_));
  NAND3_X1   g218(.A1(new_n244_), .A2(\ctable[1] ), .A3(new_n243_), .ZN(new_n245_));
  NOR2_X1    g219(.A1(new_n34_), .A2(new_n41_), .ZN(new_n246_));
  NAND2_X1   g220(.A1(new_n246_), .A2(new_n26_), .ZN(new_n247_));
  OAI21_X1   g221(.A1(new_n34_), .A2(\trailingones[1] ), .B(new_n41_), .ZN(new_n248_));
  AOI21_X1   g222(.A1(new_n247_), .A2(new_n248_), .B(new_n34_), .ZN(new_n249_));
  INV_X1     g223(.I(new_n184_), .ZN(new_n250_));
  NAND2_X1   g224(.A1(new_n28_), .A2(\ctable[1] ), .ZN(new_n251_));
  OAI21_X1   g225(.A1(new_n31_), .A2(new_n250_), .B(new_n251_), .ZN(new_n252_));
  NOR2_X1    g226(.A1(new_n29_), .A2(new_n101_), .ZN(new_n253_));
  AOI22_X1   g227(.A1(new_n252_), .A2(new_n253_), .B1(new_n245_), .B2(new_n249_), .ZN(new_n254_));
  NAND2_X1   g228(.A1(new_n41_), .A2(\totalcoeffs[2] ), .ZN(new_n255_));
  NAND2_X1   g229(.A1(new_n34_), .A2(\trailingones[0] ), .ZN(new_n256_));
  AOI21_X1   g230(.A1(new_n255_), .A2(new_n256_), .B(\ctable[0] ), .ZN(new_n257_));
  AOI21_X1   g231(.A1(new_n41_), .A2(\totalcoeffs[3] ), .B(\totalcoeffs[2] ), .ZN(new_n258_));
  XOR2_X1    g232(.A1(new_n257_), .A2(new_n258_), .Z(new_n259_));
  NOR2_X1    g233(.A1(new_n53_), .A2(\ctable[0] ), .ZN(new_n260_));
  NAND2_X1   g234(.A1(\totalcoeffs[1] ), .A2(\trailingones[0] ), .ZN(new_n261_));
  NOR2_X1    g235(.A1(new_n32_), .A2(new_n261_), .ZN(new_n262_));
  AOI21_X1   g236(.A1(new_n262_), .A2(new_n260_), .B(\totalcoeffs[1] ), .ZN(new_n263_));
  NAND3_X1   g237(.A1(new_n101_), .A2(\totalcoeffs[1] ), .A3(\trailingones[1] ), .ZN(new_n264_));
  NOR3_X1    g238(.A1(new_n264_), .A2(new_n53_), .A3(\trailingones[0] ), .ZN(new_n265_));
  NAND3_X1   g239(.A1(new_n32_), .A2(new_n261_), .A3(new_n53_), .ZN(new_n266_));
  AOI21_X1   g240(.A1(new_n33_), .A2(new_n266_), .B(new_n265_), .ZN(new_n267_));
  OAI21_X1   g241(.A1(new_n108_), .A2(new_n85_), .B(new_n41_), .ZN(new_n268_));
  NAND2_X1   g242(.A1(new_n268_), .A2(new_n199_), .ZN(new_n269_));
  OAI22_X1   g243(.A1(new_n259_), .A2(new_n263_), .B1(new_n267_), .B2(new_n269_), .ZN(new_n270_));
  NOR2_X1    g244(.A1(new_n22_), .A2(new_n101_), .ZN(new_n271_));
  NOR2_X1    g245(.A1(new_n41_), .A2(\ctable[1] ), .ZN(new_n272_));
  XNOR2_X1   g246(.A1(new_n272_), .A2(new_n144_), .ZN(new_n273_));
  NAND4_X1   g247(.A1(new_n273_), .A2(new_n68_), .A3(new_n271_), .A4(new_n201_), .ZN(new_n274_));
  AOI21_X1   g248(.A1(new_n140_), .A2(new_n41_), .B(new_n23_), .ZN(new_n275_));
  AOI21_X1   g249(.A1(new_n79_), .A2(\trailingones[1] ), .B(new_n101_), .ZN(new_n276_));
  OAI21_X1   g250(.A1(\totalcoeffs[2] ), .A2(new_n275_), .B(new_n276_), .ZN(new_n277_));
  AOI21_X1   g251(.A1(new_n274_), .A2(new_n65_), .B(new_n277_), .ZN(new_n278_));
  NAND2_X1   g252(.A1(\totalcoeffs[0] ), .A2(\trailingones[0] ), .ZN(new_n279_));
  NOR2_X1    g253(.A1(new_n279_), .A2(\totalcoeffs[4] ), .ZN(new_n280_));
  NOR2_X1    g254(.A1(\ctable[0] ), .A2(\ctable[1] ), .ZN(new_n281_));
  NOR2_X1    g255(.A1(new_n23_), .A2(new_n26_), .ZN(new_n282_));
  NAND4_X1   g256(.A1(new_n280_), .A2(new_n282_), .A3(new_n82_), .A4(new_n281_), .ZN(new_n283_));
  NAND3_X1   g257(.A1(new_n279_), .A2(\ctable[2] ), .A3(new_n26_), .ZN(new_n284_));
  AOI21_X1   g258(.A1(new_n283_), .A2(new_n23_), .B(new_n284_), .ZN(new_n285_));
  AOI21_X1   g259(.A1(new_n270_), .A2(new_n278_), .B(new_n285_), .ZN(new_n286_));
  NOR3_X1    g260(.A1(new_n286_), .A2(new_n242_), .A3(new_n254_), .ZN(\coeff_token[2] ));
  AOI21_X1   g261(.A1(\ctable[1] ), .A2(\trailingones[0] ), .B(\totalcoeffs[3] ), .ZN(new_n288_));
  AOI21_X1   g262(.A1(new_n53_), .A2(new_n41_), .B(\ctable[0] ), .ZN(new_n289_));
  NOR3_X1    g263(.A1(new_n289_), .A2(new_n23_), .A3(new_n288_), .ZN(new_n290_));
  NAND2_X1   g264(.A1(new_n53_), .A2(\totalcoeffs[4] ), .ZN(new_n291_));
  NOR4_X1    g265(.A1(new_n291_), .A2(new_n35_), .A3(\trailingones[0] ), .A4(\trailingones[1] ), .ZN(new_n292_));
  AOI21_X1   g266(.A1(new_n290_), .A2(new_n292_), .B(\totalcoeffs[2] ), .ZN(new_n293_));
  NAND2_X1   g267(.A1(new_n260_), .A2(\totalcoeffs[0] ), .ZN(new_n294_));
  OAI21_X1   g268(.A1(new_n293_), .A2(new_n294_), .B(new_n23_), .ZN(new_n295_));
  OAI21_X1   g269(.A1(\ctable[0] ), .A2(\ctable[1] ), .B(new_n43_), .ZN(new_n296_));
  NAND2_X1   g270(.A1(new_n82_), .A2(\totalcoeffs[4] ), .ZN(new_n297_));
  XOR2_X1    g271(.A1(new_n297_), .A2(new_n53_), .Z(new_n298_));
  AOI21_X1   g272(.A1(new_n101_), .A2(new_n26_), .B(new_n34_), .ZN(new_n299_));
  NAND2_X1   g273(.A1(new_n140_), .A2(new_n65_), .ZN(new_n300_));
  OAI21_X1   g274(.A1(new_n299_), .A2(new_n300_), .B(\ctable[2] ), .ZN(new_n301_));
  AOI21_X1   g275(.A1(new_n298_), .A2(new_n296_), .B(new_n301_), .ZN(new_n302_));
  AOI21_X1   g276(.A1(new_n302_), .A2(new_n295_), .B(\totalcoeffs[4] ), .ZN(new_n303_));
  INV_X1     g277(.I(new_n260_), .ZN(new_n304_));
  NOR2_X1    g278(.A1(\totalcoeffs[1] ), .A2(\ctable[1] ), .ZN(new_n305_));
  NAND2_X1   g279(.A1(new_n305_), .A2(\trailingones[1] ), .ZN(new_n306_));
  OAI21_X1   g280(.A1(new_n306_), .A2(new_n194_), .B(new_n304_), .ZN(new_n307_));
  AOI21_X1   g281(.A1(new_n307_), .A2(new_n271_), .B(\totalcoeffs[1] ), .ZN(new_n308_));
  NAND4_X1   g282(.A1(new_n101_), .A2(new_n53_), .A3(new_n41_), .A4(\ctable[0] ), .ZN(new_n309_));
  INV_X1     g283(.I(new_n85_), .ZN(new_n310_));
  OAI21_X1   g284(.A1(new_n310_), .A2(new_n130_), .B(\trailingones[0] ), .ZN(new_n311_));
  NAND2_X1   g285(.A1(new_n311_), .A2(new_n309_), .ZN(new_n312_));
  XOR2_X1    g286(.A1(new_n184_), .A2(\ctable[0] ), .Z(new_n313_));
  NAND4_X1   g287(.A1(new_n313_), .A2(new_n312_), .A3(\trailingones[1] ), .A4(new_n83_), .ZN(new_n314_));
  INV_X1     g288(.I(new_n282_), .ZN(new_n315_));
  NAND2_X1   g289(.A1(new_n315_), .A2(new_n144_), .ZN(new_n316_));
  NOR2_X1    g290(.A1(new_n130_), .A2(\ctable[1] ), .ZN(new_n317_));
  NOR2_X1    g291(.A1(new_n304_), .A2(new_n101_), .ZN(new_n318_));
  AOI22_X1   g292(.A1(new_n316_), .A2(new_n317_), .B1(new_n318_), .B2(new_n92_), .ZN(new_n319_));
  OAI21_X1   g293(.A1(new_n51_), .A2(new_n34_), .B(new_n41_), .ZN(new_n320_));
  NAND2_X1   g294(.A1(new_n320_), .A2(\ctable[1] ), .ZN(new_n321_));
  OAI22_X1   g295(.A1(new_n314_), .A2(new_n308_), .B1(new_n319_), .B2(new_n321_), .ZN(new_n322_));
  NOR2_X1    g296(.A1(new_n32_), .A2(new_n53_), .ZN(new_n323_));
  XOR2_X1    g297(.A1(new_n323_), .A2(new_n260_), .Z(new_n324_));
  NAND2_X1   g298(.A1(new_n310_), .A2(new_n53_), .ZN(new_n325_));
  NAND2_X1   g299(.A1(new_n83_), .A2(new_n260_), .ZN(new_n326_));
  NAND3_X1   g300(.A1(new_n324_), .A2(new_n325_), .A3(new_n326_), .ZN(new_n327_));
  AOI21_X1   g301(.A1(new_n327_), .A2(new_n42_), .B(new_n23_), .ZN(new_n328_));
  NAND2_X1   g302(.A1(new_n322_), .A2(new_n328_), .ZN(new_n329_));
  NOR2_X1    g303(.A1(new_n329_), .A2(new_n303_), .ZN(\coeff_token[3] ));
  NOR2_X1    g304(.A1(new_n69_), .A2(\totalcoeffs[0] ), .ZN(new_n331_));
  NAND2_X1   g305(.A1(new_n331_), .A2(\totalcoeffs[3] ), .ZN(new_n332_));
  NOR2_X1    g306(.A1(new_n65_), .A2(\totalcoeffs[3] ), .ZN(new_n333_));
  NOR2_X1    g307(.A1(new_n101_), .A2(\totalcoeffs[4] ), .ZN(new_n334_));
  OAI21_X1   g308(.A1(new_n333_), .A2(new_n334_), .B(new_n168_), .ZN(new_n335_));
  NAND2_X1   g309(.A1(new_n199_), .A2(\ctable[2] ), .ZN(new_n336_));
  AOI21_X1   g310(.A1(new_n332_), .A2(new_n335_), .B(new_n336_), .ZN(\coeff_token[4] ));
  NOR2_X1    g311(.A1(\totalcoeffs[3] ), .A2(\totalcoeffs[4] ), .ZN(new_n338_));
  NOR4_X1    g312(.A1(new_n336_), .A2(\totalcoeffs[0] ), .A3(new_n69_), .A4(new_n338_), .ZN(\coeff_token[5] ));
  NOR2_X1    g313(.A1(new_n105_), .A2(new_n34_), .ZN(new_n340_));
  NAND2_X1   g314(.A1(new_n340_), .A2(\trailingones[0] ), .ZN(new_n341_));
  NAND2_X1   g315(.A1(new_n341_), .A2(new_n115_), .ZN(new_n342_));
  OAI21_X1   g316(.A1(\totalcoeffs[0] ), .A2(\ctable[0] ), .B(\ctable[1] ), .ZN(new_n343_));
  AOI21_X1   g317(.A1(new_n343_), .A2(new_n144_), .B(\totalcoeffs[1] ), .ZN(new_n344_));
  NAND2_X1   g318(.A1(new_n342_), .A2(new_n344_), .ZN(new_n345_));
  NOR2_X1    g319(.A1(new_n42_), .A2(\totalcoeffs[0] ), .ZN(new_n346_));
  NOR2_X1    g320(.A1(new_n43_), .A2(new_n22_), .ZN(new_n347_));
  OAI21_X1   g321(.A1(new_n347_), .A2(new_n346_), .B(\totalcoeffs[2] ), .ZN(new_n348_));
  AOI21_X1   g322(.A1(new_n348_), .A2(new_n22_), .B(new_n41_), .ZN(new_n349_));
  NOR4_X1    g323(.A1(new_n229_), .A2(new_n22_), .A3(new_n53_), .A4(new_n26_), .ZN(new_n351_));
  OAI21_X1   g324(.A1(new_n349_), .A2(new_n351_), .B(\totalcoeffs[1] ), .ZN(new_n352_));
  NAND2_X1   g325(.A1(new_n352_), .A2(new_n345_), .ZN(new_n353_));
  AOI21_X1   g326(.A1(new_n353_), .A2(\ctable[2] ), .B(\totalcoeffs[3] ), .ZN(new_n354_));
  INV_X1     g327(.I(new_n154_), .ZN(new_n355_));
  OAI22_X1   g328(.A1(new_n106_), .A2(new_n355_), .B1(\trailingones[1] ), .B2(new_n261_), .ZN(new_n356_));
  NOR4_X1    g329(.A1(new_n24_), .A2(\totalcoeffs[2] ), .A3(\ctable[0] ), .A4(\ctable[1] ), .ZN(new_n357_));
  AOI21_X1   g330(.A1(new_n356_), .A2(new_n357_), .B(\totalcoeffs[0] ), .ZN(new_n358_));
  NAND2_X1   g331(.A1(new_n26_), .A2(\ctable[2] ), .ZN(new_n359_));
  NAND3_X1   g332(.A1(new_n47_), .A2(new_n359_), .A3(\trailingones[0] ), .ZN(new_n360_));
  XOR2_X1    g333(.A1(new_n360_), .A2(new_n165_), .Z(new_n361_));
  NAND2_X1   g334(.A1(new_n361_), .A2(\totalcoeffs[3] ), .ZN(new_n362_));
  OAI21_X1   g335(.A1(new_n362_), .A2(new_n358_), .B(new_n24_), .ZN(new_n363_));
  AOI21_X1   g336(.A1(new_n23_), .A2(new_n35_), .B(new_n34_), .ZN(new_n364_));
  NAND2_X1   g337(.A1(new_n355_), .A2(new_n53_), .ZN(new_n365_));
  OAI21_X1   g338(.A1(new_n365_), .A2(new_n364_), .B(new_n35_), .ZN(new_n366_));
  NAND2_X1   g339(.A1(new_n366_), .A2(new_n282_), .ZN(new_n367_));
  INV_X1     g340(.I(new_n36_), .ZN(new_n368_));
  XOR2_X1    g341(.A1(\trailingones[0] ), .A2(\trailingones[1] ), .Z(new_n369_));
  INV_X1     g342(.I(new_n369_), .ZN(new_n370_));
  NOR2_X1    g343(.A1(new_n53_), .A2(\trailingones[0] ), .ZN(new_n371_));
  NOR2_X1    g344(.A1(new_n371_), .A2(new_n272_), .ZN(new_n372_));
  NOR3_X1    g345(.A1(new_n370_), .A2(new_n368_), .A3(new_n372_), .ZN(new_n373_));
  NOR2_X1    g346(.A1(new_n80_), .A2(new_n41_), .ZN(new_n374_));
  OAI21_X1   g347(.A1(new_n373_), .A2(new_n340_), .B(new_n374_), .ZN(new_n375_));
  NAND3_X1   g348(.A1(new_n51_), .A2(new_n22_), .A3(\totalcoeffs[2] ), .ZN(new_n376_));
  AOI21_X1   g349(.A1(new_n375_), .A2(new_n367_), .B(new_n376_), .ZN(new_n377_));
  NOR2_X1    g350(.A1(new_n65_), .A2(new_n24_), .ZN(new_n378_));
  NAND4_X1   g351(.A1(new_n378_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[1] ), .A4(new_n82_), .ZN(new_n379_));
  NAND2_X1   g352(.A1(new_n379_), .A2(new_n53_), .ZN(new_n380_));
  AOI22_X1   g353(.A1(new_n363_), .A2(new_n377_), .B1(new_n239_), .B2(new_n380_), .ZN(new_n381_));
  NOR3_X1    g354(.A1(new_n29_), .A2(new_n22_), .A3(new_n35_), .ZN(new_n382_));
  NOR3_X1    g355(.A1(new_n29_), .A2(\totalcoeffs[0] ), .A3(\ctable[0] ), .ZN(new_n383_));
  NOR2_X1    g356(.A1(new_n382_), .A2(new_n383_), .ZN(new_n384_));
  NOR2_X1    g357(.A1(new_n261_), .A2(new_n53_), .ZN(new_n385_));
  XOR2_X1    g358(.A1(new_n385_), .A2(new_n151_), .Z(new_n386_));
  NOR2_X1    g359(.A1(new_n315_), .A2(new_n152_), .ZN(new_n387_));
  NOR2_X1    g360(.A1(new_n387_), .A2(\totalcoeffs[2] ), .ZN(new_n388_));
  OAI22_X1   g361(.A1(new_n388_), .A2(new_n386_), .B1(new_n41_), .B2(new_n384_), .ZN(new_n389_));
  AOI21_X1   g362(.A1(new_n22_), .A2(new_n53_), .B(new_n234_), .ZN(new_n390_));
  NAND3_X1   g363(.A1(new_n30_), .A2(\totalcoeffs[0] ), .A3(new_n34_), .ZN(new_n391_));
  OAI21_X1   g364(.A1(new_n391_), .A2(new_n390_), .B(new_n315_), .ZN(new_n392_));
  NAND4_X1   g365(.A1(new_n389_), .A2(new_n392_), .A3(\ctable[0] ), .A4(new_n81_), .ZN(new_n393_));
  NOR3_X1    g366(.A1(new_n381_), .A2(new_n354_), .A3(new_n393_), .ZN(\ctoken_len[0] ));
  NAND2_X1   g367(.A1(\totalcoeffs[3] ), .A2(\ctable[0] ), .ZN(new_n395_));
  NOR2_X1    g368(.A1(new_n395_), .A2(new_n26_), .ZN(new_n396_));
  AOI21_X1   g369(.A1(new_n396_), .A2(new_n246_), .B(\trailingones[0] ), .ZN(new_n397_));
  NOR2_X1    g370(.A1(new_n131_), .A2(\totalcoeffs[2] ), .ZN(new_n398_));
  NOR2_X1    g371(.A1(new_n132_), .A2(new_n34_), .ZN(new_n399_));
  OAI21_X1   g372(.A1(new_n399_), .A2(new_n398_), .B(new_n51_), .ZN(new_n400_));
  AOI21_X1   g373(.A1(new_n36_), .A2(new_n33_), .B(\totalcoeffs[1] ), .ZN(new_n401_));
  OAI21_X1   g374(.A1(new_n400_), .A2(new_n397_), .B(new_n401_), .ZN(new_n402_));
  NAND2_X1   g375(.A1(new_n184_), .A2(new_n225_), .ZN(new_n403_));
  AOI22_X1   g376(.A1(new_n403_), .A2(new_n22_), .B1(new_n368_), .B2(new_n32_), .ZN(new_n404_));
  NAND2_X1   g377(.A1(new_n310_), .A2(\trailingones[0] ), .ZN(new_n405_));
  OAI21_X1   g378(.A1(new_n405_), .A2(new_n129_), .B(new_n53_), .ZN(new_n406_));
  AOI21_X1   g379(.A1(new_n402_), .A2(new_n404_), .B(new_n406_), .ZN(new_n407_));
  NOR2_X1    g380(.A1(new_n370_), .A2(new_n22_), .ZN(new_n408_));
  NAND3_X1   g381(.A1(new_n369_), .A2(new_n22_), .A3(\totalcoeffs[3] ), .ZN(new_n409_));
  OAI21_X1   g382(.A1(new_n370_), .A2(new_n101_), .B(\totalcoeffs[0] ), .ZN(new_n410_));
  AOI21_X1   g383(.A1(new_n410_), .A2(new_n409_), .B(new_n34_), .ZN(new_n411_));
  NAND4_X1   g384(.A1(new_n310_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[1] ), .A4(new_n227_), .ZN(new_n412_));
  AOI21_X1   g385(.A1(new_n412_), .A2(new_n35_), .B(new_n24_), .ZN(new_n413_));
  OAI21_X1   g386(.A1(new_n411_), .A2(new_n408_), .B(new_n413_), .ZN(new_n414_));
  OAI21_X1   g387(.A1(new_n414_), .A2(new_n407_), .B(new_n35_), .ZN(new_n415_));
  NAND3_X1   g388(.A1(new_n90_), .A2(new_n53_), .A3(new_n227_), .ZN(new_n416_));
  NAND2_X1   g389(.A1(\ctable[1] ), .A2(\trailingones[0] ), .ZN(new_n417_));
  NAND3_X1   g390(.A1(new_n416_), .A2(new_n107_), .A3(new_n417_), .ZN(new_n418_));
  NAND2_X1   g391(.A1(\totalcoeffs[3] ), .A2(\ctable[1] ), .ZN(new_n419_));
  OAI21_X1   g392(.A1(\trailingones[0] ), .A2(new_n419_), .B(new_n153_), .ZN(new_n420_));
  NAND3_X1   g393(.A1(new_n420_), .A2(new_n418_), .A3(\trailingones[1] ), .ZN(new_n421_));
  NAND4_X1   g394(.A1(\totalcoeffs[0] ), .A2(\totalcoeffs[2] ), .A3(\ctable[1] ), .A4(\trailingones[0] ), .ZN(new_n422_));
  OAI21_X1   g395(.A1(\totalcoeffs[3] ), .A2(\trailingones[0] ), .B(new_n146_), .ZN(new_n423_));
  NAND3_X1   g396(.A1(new_n282_), .A2(new_n310_), .A3(new_n371_), .ZN(new_n424_));
  NAND3_X1   g397(.A1(new_n424_), .A2(new_n423_), .A3(new_n422_), .ZN(new_n425_));
  NOR2_X1    g398(.A1(new_n53_), .A2(\trailingones[1] ), .ZN(new_n426_));
  NOR2_X1    g399(.A1(new_n426_), .A2(new_n146_), .ZN(new_n427_));
  NAND2_X1   g400(.A1(new_n271_), .A2(\trailingones[0] ), .ZN(new_n428_));
  OAI22_X1   g401(.A1(new_n427_), .A2(new_n428_), .B1(\totalcoeffs[2] ), .B2(\ctable[1] ), .ZN(new_n429_));
  NAND2_X1   g402(.A1(new_n154_), .A2(new_n42_), .ZN(new_n430_));
  NAND4_X1   g403(.A1(new_n425_), .A2(new_n429_), .A3(\totalcoeffs[1] ), .A4(new_n430_), .ZN(new_n431_));
  NOR3_X1    g404(.A1(new_n42_), .A2(new_n34_), .A3(\totalcoeffs[3] ), .ZN(new_n432_));
  NOR4_X1    g405(.A1(new_n41_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[3] ), .A4(\trailingones[1] ), .ZN(new_n433_));
  OAI21_X1   g406(.A1(new_n432_), .A2(\ctable[1] ), .B(new_n433_), .ZN(new_n434_));
  AOI21_X1   g407(.A1(new_n431_), .A2(new_n421_), .B(new_n434_), .ZN(new_n435_));
  NAND2_X1   g408(.A1(new_n415_), .A2(new_n435_), .ZN(new_n436_));
  NOR2_X1    g409(.A1(new_n395_), .A2(new_n65_), .ZN(new_n437_));
  NAND4_X1   g410(.A1(new_n437_), .A2(new_n378_), .A3(new_n171_), .A4(new_n305_), .ZN(new_n438_));
  INV_X1     g411(.I(new_n227_), .ZN(new_n439_));
  NAND2_X1   g412(.A1(new_n439_), .A2(new_n42_), .ZN(new_n440_));
  NOR3_X1    g413(.A1(new_n24_), .A2(new_n41_), .A3(\trailingones[1] ), .ZN(new_n441_));
  NAND3_X1   g414(.A1(new_n440_), .A2(\totalcoeffs[0] ), .A3(\totalcoeffs[2] ), .ZN(new_n442_));
  NAND2_X1   g415(.A1(new_n440_), .A2(new_n171_), .ZN(new_n443_));
  NOR2_X1    g416(.A1(new_n441_), .A2(new_n155_), .ZN(new_n444_));
  NAND2_X1   g417(.A1(new_n443_), .A2(new_n444_), .ZN(new_n445_));
  NAND4_X1   g418(.A1(new_n445_), .A2(new_n57_), .A3(new_n442_), .A4(new_n305_), .ZN(new_n446_));
  AOI21_X1   g419(.A1(new_n436_), .A2(new_n438_), .B(new_n446_), .ZN(\ctoken_len[1] ));
  NOR3_X1    g420(.A1(new_n238_), .A2(new_n131_), .A3(new_n193_), .ZN(new_n448_));
  NOR2_X1    g421(.A1(new_n223_), .A2(\trailingones[0] ), .ZN(new_n449_));
  NOR4_X1    g422(.A1(new_n449_), .A2(new_n34_), .A3(new_n101_), .A4(new_n35_), .ZN(new_n450_));
  OAI21_X1   g423(.A1(new_n450_), .A2(new_n448_), .B(\trailingones[1] ), .ZN(new_n451_));
  NOR2_X1    g424(.A1(new_n41_), .A2(\totalcoeffs[0] ), .ZN(new_n452_));
  NAND3_X1   g425(.A1(new_n47_), .A2(new_n452_), .A3(\ctable[0] ), .ZN(new_n453_));
  NAND3_X1   g426(.A1(new_n47_), .A2(new_n151_), .A3(new_n35_), .ZN(new_n454_));
  AOI21_X1   g427(.A1(new_n453_), .A2(new_n454_), .B(new_n32_), .ZN(new_n455_));
  NOR2_X1    g428(.A1(new_n23_), .A2(new_n35_), .ZN(new_n456_));
  AOI21_X1   g429(.A1(\totalcoeffs[3] ), .A2(new_n35_), .B(new_n456_), .ZN(new_n457_));
  NOR2_X1    g430(.A1(new_n113_), .A2(\totalcoeffs[2] ), .ZN(new_n458_));
  AOI22_X1   g431(.A1(new_n457_), .A2(new_n458_), .B1(new_n271_), .B2(new_n456_), .ZN(new_n459_));
  OAI21_X1   g432(.A1(\trailingones[0] ), .A2(new_n455_), .B(new_n459_), .ZN(new_n460_));
  NAND2_X1   g433(.A1(new_n460_), .A2(new_n451_), .ZN(new_n461_));
  OAI21_X1   g434(.A1(new_n34_), .A2(new_n53_), .B(new_n23_), .ZN(new_n462_));
  NOR2_X1    g435(.A1(new_n251_), .A2(new_n41_), .ZN(new_n463_));
  AOI21_X1   g436(.A1(new_n463_), .A2(new_n462_), .B(\trailingones[0] ), .ZN(new_n464_));
  OAI21_X1   g437(.A1(new_n251_), .A2(new_n22_), .B(new_n34_), .ZN(new_n465_));
  NOR2_X1    g438(.A1(new_n227_), .A2(\totalcoeffs[1] ), .ZN(new_n466_));
  NOR3_X1    g439(.A1(new_n29_), .A2(new_n24_), .A3(new_n57_), .ZN(new_n467_));
  NAND3_X1   g440(.A1(new_n465_), .A2(new_n466_), .A3(new_n467_), .ZN(new_n468_));
  OAI21_X1   g441(.A1(new_n468_), .A2(new_n464_), .B(new_n53_), .ZN(new_n469_));
  AOI21_X1   g442(.A1(new_n90_), .A2(new_n26_), .B(new_n23_), .ZN(new_n470_));
  OAI21_X1   g443(.A1(new_n368_), .A2(new_n315_), .B(new_n264_), .ZN(new_n471_));
  AOI22_X1   g444(.A1(new_n471_), .A2(new_n22_), .B1(\ctable[0] ), .B2(new_n470_), .ZN(new_n472_));
  NOR2_X1    g445(.A1(new_n34_), .A2(new_n26_), .ZN(new_n473_));
  XNOR2_X1   g446(.A1(new_n473_), .A2(new_n27_), .ZN(new_n474_));
  NOR4_X1    g447(.A1(new_n472_), .A2(new_n250_), .A3(new_n457_), .A4(new_n474_), .ZN(new_n475_));
  NAND3_X1   g448(.A1(new_n461_), .A2(new_n469_), .A3(new_n475_), .ZN(new_n476_));
  NAND4_X1   g449(.A1(new_n331_), .A2(\totalcoeffs[4] ), .A3(new_n57_), .A4(\ctable[2] ), .ZN(new_n477_));
  AOI21_X1   g450(.A1(new_n139_), .A2(new_n41_), .B(new_n23_), .ZN(new_n478_));
  XOR2_X1    g451(.A1(new_n115_), .A2(\trailingones[0] ), .Z(new_n479_));
  AOI21_X1   g452(.A1(new_n473_), .A2(new_n22_), .B(new_n315_), .ZN(new_n480_));
  OAI21_X1   g453(.A1(new_n22_), .A2(new_n473_), .B(new_n480_), .ZN(new_n481_));
  OAI21_X1   g454(.A1(new_n481_), .A2(new_n479_), .B(new_n478_), .ZN(new_n482_));
  OR3_X2     g455(.A1(new_n481_), .A2(new_n478_), .A3(new_n479_), .Z(new_n483_));
  NAND4_X1   g456(.A1(new_n483_), .A2(new_n53_), .A3(new_n57_), .A4(new_n482_), .ZN(new_n484_));
  AOI21_X1   g457(.A1(new_n476_), .A2(new_n477_), .B(new_n484_), .ZN(\ctoken_len[2] ));
  NAND2_X1   g458(.A1(new_n452_), .A2(\trailingones[1] ), .ZN(new_n486_));
  XOR2_X1    g459(.A1(new_n486_), .A2(\ctable[0] ), .Z(new_n487_));
  OAI22_X1   g460(.A1(new_n487_), .A2(new_n53_), .B1(new_n35_), .B2(new_n151_), .ZN(new_n488_));
  NAND4_X1   g461(.A1(new_n488_), .A2(\totalcoeffs[3] ), .A3(\totalcoeffs[4] ), .A4(new_n281_), .ZN(new_n489_));
  NOR2_X1    g462(.A1(new_n281_), .A2(new_n101_), .ZN(new_n490_));
  NAND3_X1   g463(.A1(new_n488_), .A2(\totalcoeffs[3] ), .A3(\totalcoeffs[4] ), .ZN(new_n491_));
  NAND2_X1   g464(.A1(new_n491_), .A2(new_n490_), .ZN(new_n492_));
  AOI22_X1   g465(.A1(new_n70_), .A2(\ctable[2] ), .B1(\totalcoeffs[4] ), .B2(new_n90_), .ZN(new_n493_));
  OAI21_X1   g466(.A1(new_n493_), .A2(new_n53_), .B(new_n35_), .ZN(new_n494_));
  NAND3_X1   g467(.A1(new_n494_), .A2(\totalcoeffs[0] ), .A3(new_n90_), .ZN(new_n495_));
  NAND2_X1   g468(.A1(new_n495_), .A2(new_n24_), .ZN(new_n496_));
  AOI21_X1   g469(.A1(new_n41_), .A2(new_n419_), .B(new_n129_), .ZN(new_n497_));
  NAND2_X1   g470(.A1(new_n325_), .A2(new_n35_), .ZN(new_n498_));
  OAI21_X1   g471(.A1(new_n498_), .A2(new_n497_), .B(new_n92_), .ZN(new_n499_));
  NAND2_X1   g472(.A1(new_n499_), .A2(new_n34_), .ZN(new_n500_));
  NAND2_X1   g473(.A1(new_n129_), .A2(new_n41_), .ZN(new_n501_));
  NOR3_X1    g474(.A1(new_n108_), .A2(\totalcoeffs[3] ), .A3(new_n50_), .ZN(new_n502_));
  AOI21_X1   g475(.A1(new_n502_), .A2(new_n501_), .B(\totalcoeffs[2] ), .ZN(new_n503_));
  AOI22_X1   g476(.A1(new_n466_), .A2(\ctable[2] ), .B1(new_n310_), .B2(new_n53_), .ZN(new_n504_));
  INV_X1     g477(.I(new_n140_), .ZN(new_n505_));
  NAND2_X1   g478(.A1(new_n151_), .A2(new_n140_), .ZN(new_n506_));
  AOI22_X1   g479(.A1(new_n506_), .A2(new_n50_), .B1(\totalcoeffs[3] ), .B2(new_n505_), .ZN(new_n507_));
  NAND3_X1   g480(.A1(new_n70_), .A2(\totalcoeffs[0] ), .A3(new_n35_), .ZN(new_n508_));
  NOR4_X1    g481(.A1(new_n503_), .A2(new_n504_), .A3(new_n507_), .A4(new_n508_), .ZN(new_n509_));
  NAND3_X1   g482(.A1(new_n496_), .A2(new_n500_), .A3(new_n509_), .ZN(new_n510_));
  AOI21_X1   g483(.A1(new_n489_), .A2(new_n492_), .B(new_n510_), .ZN(\ctoken_len[3] ));
  NAND3_X1   g484(.A1(new_n82_), .A2(new_n167_), .A3(\totalcoeffs[4] ), .ZN(new_n512_));
  AOI21_X1   g485(.A1(new_n227_), .A2(new_n23_), .B(new_n22_), .ZN(new_n513_));
  NOR2_X1    g486(.A1(new_n513_), .A2(new_n235_), .ZN(new_n514_));
  NOR2_X1    g487(.A1(new_n281_), .A2(\ctable[2] ), .ZN(new_n515_));
  NAND2_X1   g488(.A1(new_n310_), .A2(\totalcoeffs[4] ), .ZN(new_n516_));
  NOR4_X1    g489(.A1(new_n514_), .A2(new_n512_), .A3(new_n515_), .A4(new_n516_), .ZN(\ctoken_len[4] ));
endmodule


