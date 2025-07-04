// Benchmark "apex7" written by ABC on Fri Feb 25 15:13:06 2022

module apex7 ( 
    CAPSD, CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, VACC, MMERR, IBT0, IBT1,
    IBT2, ICLR, LSD, ACCRPY, VERR_N, RATR, MARSSR, VLENESR, VSUMESR,
    PLUTO0, PLUTO1, PLUTO2, PLUTO3, PLUTO4, PLUTO5, ORWD_N, OWL_N, PY, END,
    FBI, WATCH, OVACC, KBG_N, DEL1, COMPPAR, VST0, VST1, STAR0, STAR1,
    STAR2, STAR3, BULL0, BULL1, BULL2, BULL3, BULL4, BULL5, BULL6,
    SDO, LSD_P, ACCRPY_P, VERR_F, RATR_P, MARSSR_P, VLENESR_P, VSUMESR_P,
    PLUTO0_P, PLUTO1_P, PLUTO2_P, PLUTO3_P, PLUTO4_P, PLUTO5_P, ORWD_F,
    OWL_F, PY_P, END_P, FBI_P, WATCH_P, OVACC_P, KBG_F, DEL1_P, COMPPAR_P,
    VST0_P, VST1_P, STAR0_P, STAR1_P, STAR2_P, STAR3_P, BULL0_P, BULL1_P,
    BULL2_P, BULL3_P, BULL4_P, BULL5_P, BULL6_P  );
  input  CAPSD, CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, VACC, MMERR, IBT0,
    IBT1, IBT2, ICLR, LSD, ACCRPY, VERR_N, RATR, MARSSR, VLENESR, VSUMESR,
    PLUTO0, PLUTO1, PLUTO2, PLUTO3, PLUTO4, PLUTO5, ORWD_N, OWL_N, PY, END,
    FBI, WATCH, OVACC, KBG_N, DEL1, COMPPAR, VST0, VST1, STAR0, STAR1,
    STAR2, STAR3, BULL0, BULL1, BULL2, BULL3, BULL4, BULL5, BULL6;
  output SDO, LSD_P, ACCRPY_P, VERR_F, RATR_P, MARSSR_P, VLENESR_P, VSUMESR_P,
    PLUTO0_P, PLUTO1_P, PLUTO2_P, PLUTO3_P, PLUTO4_P, PLUTO5_P, ORWD_F,
    OWL_F, PY_P, END_P, FBI_P, WATCH_P, OVACC_P, KBG_F, DEL1_P, COMPPAR_P,
    VST0_P, VST1_P, STAR0_P, STAR1_P, STAR2_P, STAR3_P, BULL0_P, BULL1_P,
    BULL2_P, BULL3_P, BULL4_P, BULL5_P, BULL6_P;
  wire new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n113_, new_n114_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n123_, new_n124_, new_n125_, new_n126_, new_n127_,
    new_n128_, new_n129_, new_n130_, new_n131_, new_n132_, new_n133_,
    new_n134_, new_n135_, new_n136_, new_n137_, new_n138_, new_n139_,
    new_n140_, new_n142_, new_n143_, new_n144_, new_n145_, new_n146_,
    new_n147_, new_n149_, new_n150_, new_n152_, new_n154_, new_n155_,
    new_n157_, new_n158_, new_n159_, new_n160_, new_n161_, new_n162_,
    new_n163_, new_n164_, new_n165_, new_n167_, new_n168_, new_n170_,
    new_n171_, new_n172_, new_n173_, new_n175_, new_n176_, new_n177_,
    new_n179_, new_n180_, new_n181_, new_n183_, new_n184_, new_n185_,
    new_n187_, new_n188_, new_n190_, new_n191_, new_n192_, new_n193_,
    new_n196_, new_n197_, new_n198_, new_n199_, new_n200_, new_n201_,
    new_n202_, new_n203_, new_n204_, new_n205_, new_n206_, new_n207_,
    new_n208_, new_n209_, new_n210_, new_n211_, new_n213_, new_n214_,
    new_n217_, new_n218_, new_n221_, new_n222_, new_n223_, new_n224_,
    new_n225_, new_n227_, new_n228_, new_n230_, new_n231_, new_n233_,
    new_n234_, new_n235_, new_n236_, new_n237_, new_n239_, new_n240_,
    new_n241_, new_n242_, new_n243_, new_n244_, new_n245_, new_n247_,
    new_n248_, new_n249_, new_n250_, new_n251_, new_n252_, new_n254_,
    new_n255_, new_n256_, new_n257_, new_n258_, new_n259_, new_n261_,
    new_n262_, new_n263_, new_n265_, new_n266_, new_n267_, new_n268_,
    new_n269_, new_n270_, new_n272_, new_n273_, new_n274_, new_n276_,
    new_n277_, new_n278_, new_n279_, new_n280_, new_n281_, new_n283_,
    new_n284_, new_n285_, new_n286_, new_n287_, new_n288_, new_n290_,
    new_n291_, new_n292_, new_n293_, new_n295_, new_n296_, new_n297_,
    new_n298_, new_n299_, new_n300_, new_n301_, new_n302_, new_n303_,
    new_n304_, new_n305_, new_n306_;
  assign new_n87_ = STAR0 & STAR1;
  assign new_n88_ = ~STAR2 & new_n87_;
  assign new_n89_ = IBT1 & ~IBT2;
  assign new_n90_ = ~CAT1 & IBT0;
  assign new_n91_ = ~CAT0 & ~IBT0;
  assign new_n92_ = ~new_n90_ & ~new_n91_;
  assign new_n93_ = new_n89_ & ~new_n92_;
  assign new_n94_ = ~CAT5 & IBT1;
  assign new_n95_ = ~CAT3 & ~IBT1;
  assign new_n96_ = ~new_n94_ & ~new_n95_;
  assign new_n97_ = IBT0 & ~new_n96_;
  assign new_n98_ = ~CAT4 & IBT1;
  assign new_n99_ = ~CAT2 & ~IBT1;
  assign new_n100_ = ~new_n98_ & ~new_n99_;
  assign new_n101_ = ~IBT0 & ~new_n100_;
  assign new_n102_ = ~new_n97_ & ~new_n101_;
  assign new_n103_ = IBT2 & ~new_n102_;
  assign new_n104_ = ~new_n93_ & ~new_n103_;
  assign new_n105_ = OWL_N & WATCH;
  assign new_n106_ = ~new_n104_ & new_n105_;
  assign new_n107_ = new_n88_ & new_n106_;
  assign new_n108_ = FBI & new_n107_;
  assign new_n109_ = LSD & OWL_N;
  assign new_n110_ = ~new_n108_ & ~new_n109_;
  assign new_n111_ = ~STAR3 & ~new_n110_;
  assign new_n112_ = FBI & new_n88_;
  assign new_n113_ = OWL_N & ~new_n112_;
  assign new_n114_ = LSD & new_n113_;
  assign LSD_P = new_n111_ | new_n114_;
  assign ORWD_F = ~WATCH | new_n104_;
  assign new_n117_ = OWL_N & FBI;
  assign new_n118_ = new_n88_ & ORWD_F;
  assign new_n119_ = new_n117_ & ~new_n118_;
  assign new_n120_ = new_n117_ & ~new_n119_;
  assign new_n121_ = ACCRPY & OWL_N;
  assign ACCRPY_P = new_n120_ | new_n121_;
  assign new_n123_ = STAR3 & new_n88_;
  assign new_n124_ = ~CAT0 & new_n89_;
  assign new_n125_ = ~CAT1 & WATCH;
  assign new_n126_ = new_n124_ & new_n125_;
  assign new_n127_ = ORWD_F & ~new_n126_;
  assign new_n128_ = ~new_n123_ & ~new_n127_;
  assign new_n129_ = ~BULL0 & ~BULL3;
  assign new_n130_ = BULL4 & new_n129_;
  assign new_n131_ = ~BULL5 & new_n130_;
  assign new_n132_ = BULL6 & new_n131_;
  assign new_n133_ = BULL1 & new_n132_;
  assign new_n134_ = ~BULL2 & new_n133_;
  assign new_n135_ = WATCH & new_n134_;
  assign new_n136_ = ~new_n119_ & ~new_n135_;
  assign new_n137_ = new_n128_ & ~new_n134_;
  assign new_n138_ = ~new_n136_ & ~new_n137_;
  assign new_n139_ = VERR_N & ~new_n138_;
  assign new_n140_ = ~OWL_N & ~new_n117_;
  assign VERR_F = new_n139_ | new_n140_;
  assign new_n142_ = OWL_N & END;
  assign new_n143_ = ~MMERR & ~VST0;
  assign new_n144_ = new_n142_ & new_n143_;
  assign new_n145_ = RATR & OWL_N;
  assign new_n146_ = ~COMPPAR & new_n142_;
  assign new_n147_ = ~new_n145_ & ~new_n146_;
  assign RATR_P = new_n144_ | ~new_n147_;
  assign new_n149_ = MARSSR & OWL_N;
  assign new_n150_ = new_n105_ & new_n134_;
  assign MARSSR_P = new_n149_ | new_n150_;
  assign new_n152_ = ~VLENESR & KBG_N;
  assign VLENESR_P = OWL_N & ~new_n152_;
  assign new_n154_ = VSUMESR & OWL_N;
  assign new_n155_ = VST1 & new_n142_;
  assign VSUMESR_P = new_n154_ | new_n155_;
  assign new_n157_ = COMPPAR & ~VST1;
  assign new_n158_ = new_n142_ & ~new_n157_;
  assign new_n159_ = OWL_N & ~KBG_N;
  assign new_n160_ = ~new_n150_ & ~new_n159_;
  assign new_n161_ = ~new_n144_ & new_n160_;
  assign new_n162_ = ~new_n158_ & new_n161_;
  assign new_n163_ = PLUTO0 & OWL_N;
  assign new_n164_ = new_n89_ & ~new_n162_;
  assign new_n165_ = ~IBT0 & new_n164_;
  assign PLUTO0_P = new_n163_ | new_n165_;
  assign new_n167_ = PLUTO1 & OWL_N;
  assign new_n168_ = IBT0 & new_n164_;
  assign PLUTO1_P = new_n167_ | new_n168_;
  assign new_n170_ = PLUTO2 & OWL_N;
  assign new_n171_ = IBT2 & ~new_n162_;
  assign new_n172_ = ~IBT0 & ~IBT1;
  assign new_n173_ = new_n171_ & new_n172_;
  assign PLUTO2_P = new_n170_ | new_n173_;
  assign new_n175_ = PLUTO3 & OWL_N;
  assign new_n176_ = IBT0 & ~IBT1;
  assign new_n177_ = new_n171_ & new_n176_;
  assign PLUTO3_P = new_n175_ | new_n177_;
  assign new_n179_ = PLUTO4 & OWL_N;
  assign new_n180_ = ~IBT0 & IBT1;
  assign new_n181_ = new_n171_ & new_n180_;
  assign PLUTO4_P = new_n179_ | new_n181_;
  assign new_n183_ = PLUTO5 & OWL_N;
  assign new_n184_ = IBT0 & IBT1;
  assign new_n185_ = new_n171_ & new_n184_;
  assign PLUTO5_P = new_n183_ | new_n185_;
  assign new_n187_ = KBG_N & ~new_n135_;
  assign new_n188_ = ~END & new_n187_;
  assign OWL_F = ~ICLR & new_n188_;
  assign new_n190_ = ~ICLR & ~FBI;
  assign new_n191_ = ~ICLR & FBI;
  assign new_n192_ = DEL1 & new_n191_;
  assign new_n193_ = PY & new_n190_;
  assign PY_P = new_n192_ | new_n193_;
  assign END_P = new_n120_ | new_n142_;
  assign new_n196_ = ~ORWD_N & new_n106_;
  assign new_n197_ = ~new_n117_ & ~new_n196_;
  assign new_n198_ = OWL_N & ~new_n87_;
  assign new_n199_ = ORWD_N & new_n87_;
  assign new_n200_ = new_n106_ & ~new_n197_;
  assign new_n201_ = ~new_n88_ & new_n117_;
  assign new_n202_ = ~new_n200_ & ~new_n201_;
  assign new_n203_ = ~new_n199_ & ~new_n202_;
  assign new_n204_ = STAR2 & new_n198_;
  assign new_n205_ = ~new_n117_ & ~new_n204_;
  assign new_n206_ = FBI & ~new_n205_;
  assign new_n207_ = new_n196_ & new_n204_;
  assign new_n208_ = ~new_n206_ & ~new_n207_;
  assign new_n209_ = ~new_n88_ & ~new_n208_;
  assign new_n210_ = FBI & new_n106_;
  assign new_n211_ = ~new_n209_ & ~new_n210_;
  assign FBI_P = new_n203_ | ~new_n211_;
  assign new_n213_ = OWL_N & OVACC;
  assign new_n214_ = ~VACC & new_n213_;
  assign WATCH_P = new_n105_ | new_n214_;
  assign OVACC_P = VACC & ~ICLR;
  assign new_n217_ = new_n119_ & ~new_n128_;
  assign new_n218_ = KBG_N & ~new_n217_;
  assign KBG_F = new_n140_ | new_n218_;
  assign DEL1_P = CAPSD & ~ICLR;
  assign new_n221_ = FBI & DEL1;
  assign new_n222_ = OWL_N & ~new_n221_;
  assign new_n223_ = COMPPAR & new_n222_;
  assign new_n224_ = ~COMPPAR & new_n117_;
  assign new_n225_ = DEL1 & new_n224_;
  assign COMPPAR_P = new_n223_ | new_n225_;
  assign new_n227_ = VST1 & new_n191_;
  assign new_n228_ = VST0 & new_n190_;
  assign VST0_P = new_n227_ | new_n228_;
  assign new_n230_ = VST1 & new_n190_;
  assign new_n231_ = PY & new_n191_;
  assign VST1_P = new_n230_ | new_n231_;
  assign new_n233_ = ~ORWD_N & ~ORWD_F;
  assign new_n234_ = OWL_N & ~new_n233_;
  assign new_n235_ = ~FBI & new_n234_;
  assign new_n236_ = STAR0 & new_n235_;
  assign new_n237_ = ~STAR0 & ~new_n197_;
  assign STAR0_P = new_n236_ | new_n237_;
  assign new_n239_ = ~STAR1 & new_n196_;
  assign new_n240_ = ~new_n87_ & new_n117_;
  assign new_n241_ = ~new_n239_ & ~new_n240_;
  assign new_n242_ = STAR0 & ~new_n241_;
  assign new_n243_ = ~STAR0 & new_n198_;
  assign new_n244_ = ~new_n235_ & ~new_n243_;
  assign new_n245_ = STAR1 & ~new_n244_;
  assign STAR1_P = new_n242_ | new_n245_;
  assign new_n247_ = ~new_n198_ & ~new_n235_;
  assign new_n248_ = STAR2 & ~new_n247_;
  assign new_n249_ = new_n88_ & new_n196_;
  assign new_n250_ = new_n87_ & new_n117_;
  assign new_n251_ = ~STAR2 & new_n250_;
  assign new_n252_ = ~new_n249_ & ~new_n251_;
  assign STAR2_P = new_n248_ | ~new_n252_;
  assign new_n254_ = OWL_N & ~STAR2;
  assign new_n255_ = new_n247_ & ~new_n254_;
  assign new_n256_ = STAR3 & ~new_n255_;
  assign new_n257_ = STAR2 & ~STAR3;
  assign new_n258_ = new_n87_ & ~new_n197_;
  assign new_n259_ = new_n257_ & new_n258_;
  assign STAR3_P = new_n256_ | new_n259_;
  assign new_n261_ = ~BULL0 & new_n105_;
  assign new_n262_ = OWL_N & ~WATCH;
  assign new_n263_ = BULL0 & new_n262_;
  assign BULL0_P = new_n261_ | new_n263_;
  assign new_n265_ = WATCH & BULL1;
  assign new_n266_ = BULL0 & new_n265_;
  assign new_n267_ = OWL_N & ~new_n266_;
  assign new_n268_ = BULL1 & new_n267_;
  assign new_n269_ = BULL0 & new_n105_;
  assign new_n270_ = ~BULL1 & new_n269_;
  assign BULL1_P = new_n268_ | new_n270_;
  assign new_n272_ = BULL2 & new_n267_;
  assign new_n273_ = BULL1 & ~BULL2;
  assign new_n274_ = new_n269_ & new_n273_;
  assign BULL2_P = new_n272_ | new_n274_;
  assign new_n276_ = WATCH & BULL0;
  assign new_n277_ = BULL1 & BULL2;
  assign new_n278_ = new_n276_ & new_n277_;
  assign new_n279_ = BULL3 & ~new_n278_;
  assign new_n280_ = ~BULL3 & new_n278_;
  assign new_n281_ = ~new_n279_ & ~new_n280_;
  assign BULL3_P = OWL_N & ~new_n281_;
  assign new_n283_ = OWL_N & BULL3;
  assign new_n284_ = new_n278_ & new_n283_;
  assign new_n285_ = ~BULL4 & new_n284_;
  assign new_n286_ = BULL3 & new_n278_;
  assign new_n287_ = OWL_N & ~new_n286_;
  assign new_n288_ = BULL4 & new_n287_;
  assign BULL4_P = new_n285_ | new_n288_;
  assign new_n290_ = ~new_n287_ & ~BULL4_P;
  assign new_n291_ = BULL5 & ~new_n290_;
  assign new_n292_ = BULL4 & new_n284_;
  assign new_n293_ = ~BULL5 & new_n292_;
  assign BULL5_P = new_n291_ | new_n293_;
  assign new_n295_ = ~BULL6 & new_n284_;
  assign new_n296_ = new_n267_ & new_n278_;
  assign new_n297_ = BULL3 & new_n296_;
  assign new_n298_ = ~new_n295_ & ~new_n297_;
  assign new_n299_ = BULL5 & ~new_n298_;
  assign new_n300_ = BULL4 & new_n299_;
  assign new_n301_ = BULL2 & BULL3;
  assign new_n302_ = BULL4 & BULL5;
  assign new_n303_ = new_n301_ & new_n302_;
  assign new_n304_ = OWL_N & ~new_n303_;
  assign new_n305_ = ~new_n267_ & ~new_n304_;
  assign new_n306_ = BULL6 & ~new_n305_;
  assign BULL6_P = new_n300_ | new_n306_;
  assign SDO = VST0;
endmodule


