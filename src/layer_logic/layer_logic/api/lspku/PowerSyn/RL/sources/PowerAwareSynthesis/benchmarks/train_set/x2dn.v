// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:28 2022

module x2dn  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,
    v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,
    v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57,
    v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71,
    v72, v73, v74, v75, v76, v77, v78, v79, v80, v81,
    \v82.0 , \v82.1 , \v82.2 , \v82.3 , \v82.4 , \v82.5 , \v82.6 , \v82.7 ,
    \v82.8 , \v82.9 , \v82.10 , \v82.11 , \v82.12 , \v82.13 , \v82.14 ,
    \v82.15 , \v82.16 , \v82.17 , \v82.18 , \v82.19 , \v82.20 , \v82.21 ,
    \v82.22 , \v82.23 , \v82.24 , \v82.25 , \v82.26 , \v82.27 , \v82.28 ,
    \v82.29 , \v82.30 , \v82.31 , \v82.32 , \v82.33 , \v82.34 , \v82.35 ,
    \v82.36 , \v82.37 , \v82.38 , \v82.39 , \v82.40 , \v82.41 , \v82.42 ,
    \v82.43 , \v82.44 , \v82.45 , \v82.46 , \v82.47 , \v82.48 , \v82.49 ,
    \v82.50 , \v82.51 , \v82.52 , \v82.53 , \v82.54 , \v82.55   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28,
    v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42,
    v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56,
    v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70,
    v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81;
  output \v82.0 , \v82.1 , \v82.2 , \v82.3 , \v82.4 , \v82.5 , \v82.6 ,
    \v82.7 , \v82.8 , \v82.9 , \v82.10 , \v82.11 , \v82.12 , \v82.13 ,
    \v82.14 , \v82.15 , \v82.16 , \v82.17 , \v82.18 , \v82.19 , \v82.20 ,
    \v82.21 , \v82.22 , \v82.23 , \v82.24 , \v82.25 , \v82.26 , \v82.27 ,
    \v82.28 , \v82.29 , \v82.30 , \v82.31 , \v82.32 , \v82.33 , \v82.34 ,
    \v82.35 , \v82.36 , \v82.37 , \v82.38 , \v82.39 , \v82.40 , \v82.41 ,
    \v82.42 , \v82.43 , \v82.44 , \v82.45 , \v82.46 , \v82.47 , \v82.48 ,
    \v82.49 , \v82.50 , \v82.51 , \v82.52 , \v82.53 , \v82.54 , \v82.55 ;
  wire new_n140_, new_n142_, new_n143_, new_n145_, new_n146_, new_n148_,
    new_n149_, new_n150_, new_n151_, new_n152_, new_n153_, new_n155_,
    new_n157_, new_n158_, new_n160_, new_n162_, new_n165_, new_n167_,
    new_n170_, new_n172_, new_n173_, new_n174_, new_n175_, new_n177_,
    new_n178_, new_n179_, new_n180_, new_n181_, new_n182_, new_n183_,
    new_n184_, new_n186_, new_n187_, new_n188_, new_n189_, new_n190_,
    new_n191_, new_n192_, new_n193_, new_n195_, new_n196_, new_n197_,
    new_n198_, new_n199_, new_n200_, new_n201_, new_n202_, new_n204_,
    new_n205_, new_n206_, new_n207_, new_n208_, new_n209_, new_n210_,
    new_n211_, new_n213_, new_n214_, new_n215_, new_n216_, new_n217_,
    new_n218_, new_n219_, new_n220_, new_n222_, new_n223_, new_n224_,
    new_n225_, new_n226_, new_n227_, new_n228_, new_n229_, new_n231_,
    new_n232_, new_n233_, new_n234_, new_n235_, new_n236_, new_n237_,
    new_n238_, new_n240_, new_n241_, new_n242_, new_n243_, new_n244_,
    new_n245_, new_n246_, new_n247_, new_n249_, new_n250_, new_n251_,
    new_n252_, new_n253_, new_n254_, new_n255_, new_n256_, new_n257_,
    new_n258_, new_n259_, new_n261_, new_n262_, new_n263_, new_n264_,
    new_n265_, new_n266_, new_n267_, new_n268_, new_n269_, new_n270_,
    new_n271_, new_n273_, new_n274_, new_n275_, new_n276_, new_n277_,
    new_n278_, new_n279_, new_n280_, new_n281_, new_n282_, new_n283_,
    new_n284_, new_n285_, new_n286_, new_n287_, new_n288_, new_n289_,
    new_n290_, new_n291_, new_n292_, new_n293_, new_n294_, new_n295_,
    new_n296_, new_n297_, new_n298_, new_n299_, new_n300_, new_n301_,
    new_n302_, new_n303_, new_n304_, new_n305_, new_n306_, new_n307_,
    new_n308_, new_n309_, new_n310_, new_n311_, new_n312_, new_n313_,
    new_n314_, new_n315_, new_n316_, new_n317_, new_n318_, new_n319_,
    new_n320_, new_n321_, new_n322_, new_n323_, new_n324_, new_n325_,
    new_n326_, new_n327_, new_n328_, new_n329_, new_n330_, new_n331_,
    new_n332_, new_n333_, new_n334_, new_n335_, new_n336_, new_n337_,
    new_n338_, new_n339_, new_n340_, new_n341_, new_n342_, new_n343_,
    new_n344_, new_n345_, new_n348_, new_n349_, new_n350_, new_n352_,
    new_n354_, new_n355_, new_n356_, new_n357_, new_n359_, new_n360_,
    new_n364_, new_n365_, new_n366_, new_n367_, new_n368_, new_n369_,
    new_n370_;
  assign new_n140_ = ~v0 & ~v1;
  assign \v82.0  = v2 & new_n140_;
  assign new_n142_ = ~v4 & ~v5;
  assign new_n143_ = ~v3 & new_n142_;
  assign \v82.3  = ~v8 & ~new_n143_;
  assign new_n145_ = ~v7 & \v82.3 ;
  assign new_n146_ = v6 & new_n145_;
  assign \v82.1  = ~v0 & new_n146_;
  assign new_n148_ = ~v10 & ~v11;
  assign new_n149_ = ~v9 & new_n148_;
  assign new_n150_ = ~v8 & ~new_n149_;
  assign new_n151_ = ~v7 & new_n150_;
  assign new_n152_ = v6 & new_n151_;
  assign new_n153_ = ~v1 & new_n152_;
  assign \v82.2  = ~v0 & new_n153_;
  assign new_n155_ = v3 & v4;
  assign \v82.4  = v5 | ~new_n155_;
  assign new_n157_ = ~v3 & v5;
  assign new_n158_ = v3 & new_n142_;
  assign \v82.5  = new_n157_ | new_n158_;
  assign new_n160_ = v3 & ~v5;
  assign \v82.9  = v4 & ~new_n160_;
  assign new_n162_ = v9 & v10;
  assign \v82.20  = v11 & new_n162_;
  assign \v82.24  = ~v9 & ~v10;
  assign new_n165_ = v10 & v11;
  assign \v82.32  = v9 & ~new_n165_;
  assign new_n167_ = v9 & v11;
  assign \v82.33  = v10 & ~new_n167_;
  assign \v82.25  = \v82.32  | \v82.33 ;
  assign new_n170_ = v21 & v22;
  assign \v82.35  = v20 & ~new_n170_;
  assign new_n172_ = ~v24 & ~v25;
  assign new_n173_ = ~v23 & new_n172_;
  assign new_n174_ = ~v23 & ~v24;
  assign new_n175_ = ~v26 & ~new_n174_;
  assign \v82.36  = new_n173_ | new_n175_;
  assign new_n177_ = ~v28 & ~v29;
  assign new_n178_ = v28 & v29;
  assign new_n179_ = ~new_n177_ & ~new_n178_;
  assign new_n180_ = v27 & ~new_n179_;
  assign new_n181_ = ~v28 & v29;
  assign new_n182_ = v28 & ~v29;
  assign new_n183_ = ~new_n181_ & ~new_n182_;
  assign new_n184_ = ~v27 & ~new_n183_;
  assign \v82.37  = new_n180_ | new_n184_;
  assign new_n186_ = ~v31 & ~v32;
  assign new_n187_ = v31 & v32;
  assign new_n188_ = ~new_n186_ & ~new_n187_;
  assign new_n189_ = v30 & ~new_n188_;
  assign new_n190_ = ~v31 & v32;
  assign new_n191_ = v31 & ~v32;
  assign new_n192_ = ~new_n190_ & ~new_n191_;
  assign new_n193_ = ~v30 & ~new_n192_;
  assign \v82.38  = new_n189_ | new_n193_;
  assign new_n195_ = ~v34 & ~v35;
  assign new_n196_ = v34 & v35;
  assign new_n197_ = ~new_n195_ & ~new_n196_;
  assign new_n198_ = v33 & ~new_n197_;
  assign new_n199_ = ~v34 & v35;
  assign new_n200_ = v34 & ~v35;
  assign new_n201_ = ~new_n199_ & ~new_n200_;
  assign new_n202_ = ~v33 & ~new_n201_;
  assign \v82.39  = new_n198_ | new_n202_;
  assign new_n204_ = ~v37 & ~v38;
  assign new_n205_ = v37 & v38;
  assign new_n206_ = ~new_n204_ & ~new_n205_;
  assign new_n207_ = v36 & ~new_n206_;
  assign new_n208_ = ~v37 & v38;
  assign new_n209_ = v37 & ~v38;
  assign new_n210_ = ~new_n208_ & ~new_n209_;
  assign new_n211_ = ~v36 & ~new_n210_;
  assign \v82.40  = new_n207_ | new_n211_;
  assign new_n213_ = ~v40 & ~v41;
  assign new_n214_ = v40 & v41;
  assign new_n215_ = ~new_n213_ & ~new_n214_;
  assign new_n216_ = v39 & ~new_n215_;
  assign new_n217_ = ~v40 & v41;
  assign new_n218_ = v40 & ~v41;
  assign new_n219_ = ~new_n217_ & ~new_n218_;
  assign new_n220_ = ~v39 & ~new_n219_;
  assign \v82.41  = new_n216_ | new_n220_;
  assign new_n222_ = ~v43 & ~v44;
  assign new_n223_ = v43 & v44;
  assign new_n224_ = ~new_n222_ & ~new_n223_;
  assign new_n225_ = v42 & ~new_n224_;
  assign new_n226_ = ~v43 & v44;
  assign new_n227_ = v43 & ~v44;
  assign new_n228_ = ~new_n226_ & ~new_n227_;
  assign new_n229_ = ~v42 & ~new_n228_;
  assign \v82.42  = new_n225_ | new_n229_;
  assign new_n231_ = ~v46 & ~v47;
  assign new_n232_ = v46 & v47;
  assign new_n233_ = ~new_n231_ & ~new_n232_;
  assign new_n234_ = v45 & ~new_n233_;
  assign new_n235_ = ~v46 & v47;
  assign new_n236_ = v46 & ~v47;
  assign new_n237_ = ~new_n235_ & ~new_n236_;
  assign new_n238_ = ~v45 & ~new_n237_;
  assign \v82.43  = new_n234_ | new_n238_;
  assign new_n240_ = ~v50 & ~v51;
  assign new_n241_ = v49 & v52;
  assign new_n242_ = ~v48 & new_n241_;
  assign new_n243_ = v48 & v53;
  assign new_n244_ = ~new_n242_ & ~new_n243_;
  assign new_n245_ = ~new_n240_ & ~new_n244_;
  assign new_n246_ = v48 & v49;
  assign new_n247_ = new_n240_ & new_n246_;
  assign \v82.44  = new_n245_ | new_n247_;
  assign new_n249_ = v56 & ~new_n240_;
  assign new_n250_ = v49 & new_n249_;
  assign new_n251_ = v51 & v53;
  assign new_n252_ = v50 & new_n251_;
  assign new_n253_ = v54 & ~v55;
  assign new_n254_ = ~v48 & new_n253_;
  assign new_n255_ = ~new_n252_ & ~new_n254_;
  assign new_n256_ = ~v49 & ~new_n255_;
  assign new_n257_ = ~v51 & v53;
  assign new_n258_ = ~v50 & new_n257_;
  assign new_n259_ = ~new_n256_ & ~new_n258_;
  assign \v82.45  = new_n250_ | ~new_n259_;
  assign new_n261_ = v59 & ~new_n240_;
  assign new_n262_ = v49 & new_n261_;
  assign new_n263_ = v51 & v57;
  assign new_n264_ = v50 & new_n263_;
  assign new_n265_ = ~v55 & v58;
  assign new_n266_ = ~v48 & new_n265_;
  assign new_n267_ = ~new_n264_ & ~new_n266_;
  assign new_n268_ = ~v49 & ~new_n267_;
  assign new_n269_ = ~v51 & v57;
  assign new_n270_ = ~v50 & new_n269_;
  assign new_n271_ = ~new_n268_ & ~new_n270_;
  assign \v82.46  = new_n262_ | ~new_n271_;
  assign new_n273_ = v66 & ~new_n255_;
  assign new_n274_ = v65 & new_n273_;
  assign new_n275_ = v64 & new_n274_;
  assign new_n276_ = v63 & new_n275_;
  assign new_n277_ = v62 & new_n276_;
  assign new_n278_ = v61 & new_n277_;
  assign new_n279_ = v60 & new_n278_;
  assign new_n280_ = v45 & new_n279_;
  assign new_n281_ = v42 & new_n280_;
  assign new_n282_ = v39 & new_n281_;
  assign new_n283_ = v36 & new_n282_;
  assign new_n284_ = v33 & new_n283_;
  assign new_n285_ = v30 & new_n284_;
  assign new_n286_ = v27 & new_n285_;
  assign new_n287_ = ~v66 & ~new_n267_;
  assign new_n288_ = ~v65 & new_n287_;
  assign new_n289_ = ~v64 & new_n288_;
  assign new_n290_ = ~v63 & new_n289_;
  assign new_n291_ = ~v62 & new_n290_;
  assign new_n292_ = ~v61 & new_n291_;
  assign new_n293_ = ~v60 & new_n292_;
  assign new_n294_ = ~v45 & new_n293_;
  assign new_n295_ = ~v42 & new_n294_;
  assign new_n296_ = ~v39 & new_n295_;
  assign new_n297_ = ~v36 & new_n296_;
  assign new_n298_ = ~v33 & new_n297_;
  assign new_n299_ = ~v30 & new_n298_;
  assign new_n300_ = ~v27 & new_n299_;
  assign new_n301_ = ~new_n286_ & ~new_n300_;
  assign new_n302_ = ~v49 & ~new_n301_;
  assign new_n303_ = v30 & v33;
  assign new_n304_ = v27 & new_n303_;
  assign new_n305_ = v36 & v39;
  assign new_n306_ = v42 & v45;
  assign new_n307_ = new_n305_ & new_n306_;
  assign new_n308_ = new_n304_ & new_n307_;
  assign new_n309_ = v56 & v60;
  assign new_n310_ = v61 & v62;
  assign new_n311_ = new_n309_ & new_n310_;
  assign new_n312_ = v63 & v64;
  assign new_n313_ = v65 & v66;
  assign new_n314_ = new_n312_ & new_n313_;
  assign new_n315_ = new_n311_ & new_n314_;
  assign new_n316_ = new_n308_ & new_n315_;
  assign new_n317_ = ~v30 & ~v33;
  assign new_n318_ = ~v27 & new_n317_;
  assign new_n319_ = ~v36 & ~v39;
  assign new_n320_ = ~v42 & ~v45;
  assign new_n321_ = new_n319_ & new_n320_;
  assign new_n322_ = new_n318_ & new_n321_;
  assign new_n323_ = v59 & ~v60;
  assign new_n324_ = ~v61 & ~v62;
  assign new_n325_ = new_n323_ & new_n324_;
  assign new_n326_ = ~v63 & ~v64;
  assign new_n327_ = ~v65 & ~v66;
  assign new_n328_ = new_n326_ & new_n327_;
  assign new_n329_ = new_n325_ & new_n328_;
  assign new_n330_ = new_n322_ & new_n329_;
  assign new_n331_ = ~new_n316_ & ~new_n330_;
  assign new_n332_ = ~new_n240_ & ~new_n331_;
  assign new_n333_ = v49 & new_n332_;
  assign new_n334_ = v53 & v60;
  assign new_n335_ = new_n310_ & new_n334_;
  assign new_n336_ = new_n314_ & new_n335_;
  assign new_n337_ = new_n308_ & new_n336_;
  assign new_n338_ = v57 & ~v60;
  assign new_n339_ = new_n324_ & new_n338_;
  assign new_n340_ = new_n328_ & new_n339_;
  assign new_n341_ = new_n322_ & new_n340_;
  assign new_n342_ = ~new_n337_ & ~new_n341_;
  assign new_n343_ = ~v51 & ~new_n342_;
  assign new_n344_ = ~v50 & new_n343_;
  assign new_n345_ = ~new_n333_ & ~new_n344_;
  assign \v82.47  = new_n302_ | ~new_n345_;
  assign \v82.48  = v67 & v68;
  assign new_n348_ = v68 & ~new_n240_;
  assign new_n349_ = v67 & new_n348_;
  assign new_n350_ = v48 & new_n349_;
  assign \v82.51  = v48 & ~new_n240_;
  assign new_n352_ = v69 & ~\v82.51 ;
  assign \v82.49  = new_n350_ | new_n352_;
  assign new_n354_ = ~v72 & ~v73;
  assign new_n355_ = v74 & ~new_n354_;
  assign new_n356_ = v70 & new_n354_;
  assign new_n357_ = ~new_n355_ & ~new_n356_;
  assign \v82.50  = v71 & ~new_n357_;
  assign new_n359_ = ~v51 & ~new_n240_;
  assign new_n360_ = ~v50 & new_n359_;
  assign \v82.52  = v54 & ~new_n360_;
  assign \v82.53  = v58 & ~new_n240_;
  assign \v82.54  = v50 & v51;
  assign new_n364_ = ~v76 & ~v77;
  assign new_n365_ = v79 & ~new_n364_;
  assign new_n366_ = ~v77 & v78;
  assign new_n367_ = ~v76 & new_n366_;
  assign new_n368_ = ~new_n365_ & ~new_n367_;
  assign new_n369_ = ~v81 & ~new_n368_;
  assign new_n370_ = ~v80 & new_n369_;
  assign \v82.55  = v75 & new_n370_;
  assign \v82.6  = 1'b0;
  assign \v82.7  = 1'b0;
  assign \v82.10  = 1'b0;
  assign \v82.11  = 1'b0;
  assign \v82.21  = 1'b0;
  assign \v82.22  = 1'b0;
  assign \v82.23  = 1'b0;
  assign \v82.28  = 1'b0;
  assign \v82.30  = 1'b0;
  assign \v82.8  = ~v4;
  assign \v82.31  = ~\v82.20 ;
  assign \v82.12  = v12;
  assign \v82.13  = v13;
  assign \v82.14  = v14;
  assign \v82.15  = v15;
  assign \v82.16  = v16;
  assign \v82.17  = v17;
  assign \v82.18  = v18;
  assign \v82.19  = v19;
  assign \v82.26  = \v82.20 ;
  assign \v82.27  = \v82.20 ;
  assign \v82.29  = \v82.20 ;
  assign \v82.34  = v11;
endmodule


