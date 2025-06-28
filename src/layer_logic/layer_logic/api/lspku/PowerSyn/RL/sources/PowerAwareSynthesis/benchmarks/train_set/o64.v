// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:32 2022

module o64  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,
    v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,
    v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57,
    v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71,
    v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85,
    v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99,
    v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111,
    v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123,
    v124, v125, v126, v127, v128, v129,
    \v130.0   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28,
    v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42,
    v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56,
    v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70,
    v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84,
    v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98,
    v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110,
    v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122,
    v123, v124, v125, v126, v127, v128, v129;
  output \v130.0 ;
  wire new_n132_, new_n133_, new_n134_, new_n135_, new_n136_, new_n137_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n142_, new_n143_,
    new_n144_, new_n145_, new_n146_, new_n147_, new_n148_, new_n149_,
    new_n150_, new_n151_, new_n152_, new_n153_, new_n154_, new_n155_,
    new_n156_, new_n157_, new_n158_, new_n159_, new_n160_, new_n161_,
    new_n162_, new_n163_, new_n164_, new_n165_, new_n166_, new_n167_,
    new_n168_, new_n169_, new_n170_, new_n171_, new_n172_, new_n173_,
    new_n174_, new_n175_, new_n176_, new_n177_, new_n178_, new_n179_,
    new_n180_, new_n181_, new_n182_, new_n183_, new_n184_, new_n185_,
    new_n186_, new_n187_, new_n188_, new_n189_, new_n190_, new_n191_,
    new_n192_, new_n193_, new_n194_, new_n195_, new_n196_, new_n197_,
    new_n198_, new_n199_, new_n200_, new_n201_, new_n202_, new_n203_,
    new_n204_, new_n205_, new_n206_, new_n207_, new_n208_, new_n209_,
    new_n210_, new_n211_, new_n212_, new_n213_, new_n214_, new_n215_,
    new_n216_, new_n217_, new_n218_, new_n219_, new_n220_, new_n221_,
    new_n222_, new_n223_, new_n224_, new_n225_, new_n226_, new_n227_,
    new_n228_, new_n229_, new_n230_, new_n231_, new_n232_, new_n233_,
    new_n234_, new_n235_, new_n236_, new_n237_, new_n238_, new_n239_,
    new_n240_, new_n241_, new_n242_, new_n243_, new_n244_, new_n245_,
    new_n246_, new_n247_, new_n248_, new_n249_, new_n250_, new_n251_,
    new_n252_, new_n253_, new_n254_, new_n255_, new_n256_, new_n257_,
    new_n258_, new_n259_;
  assign new_n132_ = v0 & v129;
  assign new_n133_ = v64 & v128;
  assign new_n134_ = ~new_n132_ & ~new_n133_;
  assign new_n135_ = v63 & v127;
  assign new_n136_ = v62 & v126;
  assign new_n137_ = ~new_n135_ & ~new_n136_;
  assign new_n138_ = new_n134_ & new_n137_;
  assign new_n139_ = v61 & v125;
  assign new_n140_ = v60 & v124;
  assign new_n141_ = ~new_n139_ & ~new_n140_;
  assign new_n142_ = v59 & v123;
  assign new_n143_ = v58 & v122;
  assign new_n144_ = ~new_n142_ & ~new_n143_;
  assign new_n145_ = new_n141_ & new_n144_;
  assign new_n146_ = new_n138_ & new_n145_;
  assign new_n147_ = v57 & v121;
  assign new_n148_ = v56 & v120;
  assign new_n149_ = ~new_n147_ & ~new_n148_;
  assign new_n150_ = v55 & v119;
  assign new_n151_ = v54 & v118;
  assign new_n152_ = ~new_n150_ & ~new_n151_;
  assign new_n153_ = new_n149_ & new_n152_;
  assign new_n154_ = v53 & v117;
  assign new_n155_ = v52 & v116;
  assign new_n156_ = ~new_n154_ & ~new_n155_;
  assign new_n157_ = v51 & v115;
  assign new_n158_ = v50 & v114;
  assign new_n159_ = ~new_n157_ & ~new_n158_;
  assign new_n160_ = new_n156_ & new_n159_;
  assign new_n161_ = new_n153_ & new_n160_;
  assign new_n162_ = new_n146_ & new_n161_;
  assign new_n163_ = v49 & v113;
  assign new_n164_ = v48 & v112;
  assign new_n165_ = ~new_n163_ & ~new_n164_;
  assign new_n166_ = v47 & v111;
  assign new_n167_ = v46 & v110;
  assign new_n168_ = ~new_n166_ & ~new_n167_;
  assign new_n169_ = new_n165_ & new_n168_;
  assign new_n170_ = v45 & v109;
  assign new_n171_ = v44 & v108;
  assign new_n172_ = ~new_n170_ & ~new_n171_;
  assign new_n173_ = v43 & v107;
  assign new_n174_ = v42 & v106;
  assign new_n175_ = ~new_n173_ & ~new_n174_;
  assign new_n176_ = new_n172_ & new_n175_;
  assign new_n177_ = new_n169_ & new_n176_;
  assign new_n178_ = v41 & v105;
  assign new_n179_ = v40 & v104;
  assign new_n180_ = ~new_n178_ & ~new_n179_;
  assign new_n181_ = v39 & v103;
  assign new_n182_ = v38 & v102;
  assign new_n183_ = ~new_n181_ & ~new_n182_;
  assign new_n184_ = new_n180_ & new_n183_;
  assign new_n185_ = v37 & v101;
  assign new_n186_ = v36 & v100;
  assign new_n187_ = ~new_n185_ & ~new_n186_;
  assign new_n188_ = v35 & v99;
  assign new_n189_ = v34 & v98;
  assign new_n190_ = ~new_n188_ & ~new_n189_;
  assign new_n191_ = new_n187_ & new_n190_;
  assign new_n192_ = new_n184_ & new_n191_;
  assign new_n193_ = new_n177_ & new_n192_;
  assign new_n194_ = new_n162_ & new_n193_;
  assign new_n195_ = v33 & v97;
  assign new_n196_ = v32 & v96;
  assign new_n197_ = ~new_n195_ & ~new_n196_;
  assign new_n198_ = v31 & v95;
  assign new_n199_ = v30 & v94;
  assign new_n200_ = ~new_n198_ & ~new_n199_;
  assign new_n201_ = new_n197_ & new_n200_;
  assign new_n202_ = v29 & v93;
  assign new_n203_ = v28 & v92;
  assign new_n204_ = ~new_n202_ & ~new_n203_;
  assign new_n205_ = v27 & v91;
  assign new_n206_ = v26 & v90;
  assign new_n207_ = ~new_n205_ & ~new_n206_;
  assign new_n208_ = new_n204_ & new_n207_;
  assign new_n209_ = new_n201_ & new_n208_;
  assign new_n210_ = v25 & v89;
  assign new_n211_ = v24 & v88;
  assign new_n212_ = ~new_n210_ & ~new_n211_;
  assign new_n213_ = v23 & v87;
  assign new_n214_ = v22 & v86;
  assign new_n215_ = ~new_n213_ & ~new_n214_;
  assign new_n216_ = new_n212_ & new_n215_;
  assign new_n217_ = v21 & v85;
  assign new_n218_ = v20 & v84;
  assign new_n219_ = ~new_n217_ & ~new_n218_;
  assign new_n220_ = v19 & v83;
  assign new_n221_ = v18 & v82;
  assign new_n222_ = ~new_n220_ & ~new_n221_;
  assign new_n223_ = new_n219_ & new_n222_;
  assign new_n224_ = new_n216_ & new_n223_;
  assign new_n225_ = new_n209_ & new_n224_;
  assign new_n226_ = v17 & v81;
  assign new_n227_ = v16 & v80;
  assign new_n228_ = ~new_n226_ & ~new_n227_;
  assign new_n229_ = v15 & v79;
  assign new_n230_ = v14 & v78;
  assign new_n231_ = ~new_n229_ & ~new_n230_;
  assign new_n232_ = new_n228_ & new_n231_;
  assign new_n233_ = v13 & v77;
  assign new_n234_ = v12 & v76;
  assign new_n235_ = ~new_n233_ & ~new_n234_;
  assign new_n236_ = v11 & v75;
  assign new_n237_ = v10 & v74;
  assign new_n238_ = ~new_n236_ & ~new_n237_;
  assign new_n239_ = new_n235_ & new_n238_;
  assign new_n240_ = new_n232_ & new_n239_;
  assign new_n241_ = v9 & v73;
  assign new_n242_ = v8 & v72;
  assign new_n243_ = ~new_n241_ & ~new_n242_;
  assign new_n244_ = v7 & v71;
  assign new_n245_ = v6 & v70;
  assign new_n246_ = ~new_n244_ & ~new_n245_;
  assign new_n247_ = new_n243_ & new_n246_;
  assign new_n248_ = v5 & v69;
  assign new_n249_ = v4 & v68;
  assign new_n250_ = ~new_n248_ & ~new_n249_;
  assign new_n251_ = v3 & v67;
  assign new_n252_ = v2 & v66;
  assign new_n253_ = v1 & v65;
  assign new_n254_ = ~new_n252_ & ~new_n253_;
  assign new_n255_ = ~new_n251_ & new_n254_;
  assign new_n256_ = new_n250_ & new_n255_;
  assign new_n257_ = new_n247_ & new_n256_;
  assign new_n258_ = new_n240_ & new_n257_;
  assign new_n259_ = new_n225_ & new_n258_;
  assign \v130.0  = ~new_n194_ | ~new_n259_;
endmodule


