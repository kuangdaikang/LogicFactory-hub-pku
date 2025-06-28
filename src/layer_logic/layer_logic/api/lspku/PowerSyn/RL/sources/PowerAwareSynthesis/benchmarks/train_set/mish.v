// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:36 2022

module mish  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,
    v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,
    v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57,
    v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71,
    v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85,
    v86, v87, v88, v89, v90, v91, v92, v93,
    \v94.0 , \v94.1 , \v94.2 , \v94.3 , \v94.4 , \v94.5 , \v94.6 , \v94.7 ,
    \v94.8 , \v94.9 , \v94.10 , \v94.11 , \v94.12 , \v94.13 , \v94.14 ,
    \v94.15 , \v94.16 , \v94.17 , \v94.18 , \v94.19 , \v94.20 , \v94.21 ,
    \v94.22 , \v94.23 , \v94.24 , \v94.25 , \v94.26 , \v94.27 , \v94.28 ,
    \v94.29 , \v94.30 , \v94.31 , \v94.32 , \v94.33 , \v94.34 , \v94.35 ,
    \v94.36 , \v94.37 , \v94.38 , \v94.39 , \v94.40 , \v94.41 , \v94.42   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28,
    v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42,
    v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56,
    v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70,
    v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84,
    v85, v86, v87, v88, v89, v90, v91, v92, v93;
  output \v94.0 , \v94.1 , \v94.2 , \v94.3 , \v94.4 , \v94.5 , \v94.6 ,
    \v94.7 , \v94.8 , \v94.9 , \v94.10 , \v94.11 , \v94.12 , \v94.13 ,
    \v94.14 , \v94.15 , \v94.16 , \v94.17 , \v94.18 , \v94.19 , \v94.20 ,
    \v94.21 , \v94.22 , \v94.23 , \v94.24 , \v94.25 , \v94.26 , \v94.27 ,
    \v94.28 , \v94.29 , \v94.30 , \v94.31 , \v94.32 , \v94.33 , \v94.34 ,
    \v94.35 , \v94.36 , \v94.37 , \v94.38 , \v94.39 , \v94.40 , \v94.41 ,
    \v94.42 ;
  wire new_n139_, new_n140_, new_n141_, new_n142_, new_n143_, new_n144_,
    new_n145_, new_n146_, new_n148_, new_n149_, new_n151_, new_n152_,
    new_n153_, new_n155_, new_n157_, new_n158_, new_n162_, new_n163_,
    new_n164_, new_n166_, new_n167_, new_n168_, new_n170_, new_n172_,
    new_n173_, new_n174_, new_n175_, new_n176_, new_n177_, new_n179_,
    new_n181_, new_n182_, new_n184_, new_n185_, new_n186_, new_n188_,
    new_n191_, new_n192_, new_n193_, new_n195_, new_n196_, new_n197_,
    new_n198_, new_n200_, new_n202_, new_n203_, new_n205_, new_n206_,
    new_n207_, new_n209_, new_n210_, new_n211_, new_n213_, new_n215_,
    new_n217_, new_n219_, new_n220_, new_n222_, new_n223_, new_n224_,
    new_n225_, new_n226_, new_n228_;
  assign new_n139_ = ~v4 & v5;
  assign new_n140_ = v4 & ~v5;
  assign new_n141_ = ~new_n139_ & ~new_n140_;
  assign new_n142_ = v3 & ~new_n141_;
  assign new_n143_ = v4 & v5;
  assign new_n144_ = ~v4 & ~v5;
  assign new_n145_ = ~new_n143_ & ~new_n144_;
  assign new_n146_ = ~v3 & ~new_n145_;
  assign \v94.2  = new_n142_ | new_n146_;
  assign new_n148_ = v2 & \v94.2 ;
  assign new_n149_ = v0 & new_n148_;
  assign \v94.1  = ~v1 | new_n149_;
  assign new_n151_ = v9 & v10;
  assign new_n152_ = v6 & v7;
  assign new_n153_ = v8 & new_n152_;
  assign \v94.3  = ~new_n151_ | ~new_n153_;
  assign new_n155_ = ~v12 & v13;
  assign \v94.4  = ~v11 | new_n155_;
  assign new_n157_ = v16 & v17;
  assign new_n158_ = v18 & v19;
  assign \v94.6  = ~new_n157_ | ~new_n158_;
  assign \v94.7  = v21 | ~v22;
  assign \v94.8  = ~v23 | ~v24;
  assign new_n162_ = v25 & v26;
  assign new_n163_ = ~\v94.8  & new_n162_;
  assign new_n164_ = v20 & ~new_n163_;
  assign \v94.9  = ~v28 | ~new_n164_;
  assign new_n166_ = v33 & v34;
  assign new_n167_ = v30 & v32;
  assign new_n168_ = new_n166_ & new_n167_;
  assign \v94.12  = v31 | new_n168_;
  assign new_n170_ = v20 & v35;
  assign \v94.13  = v37 & new_n170_;
  assign new_n172_ = v15 & v38;
  assign new_n173_ = v39 & v41;
  assign new_n174_ = new_n172_ & new_n173_;
  assign new_n175_ = v36 & ~new_n174_;
  assign new_n176_ = v35 & v37;
  assign new_n177_ = ~new_n175_ & ~new_n176_;
  assign \v94.14  = v20 & ~new_n177_;
  assign new_n179_ = ~v42 & ~v44;
  assign \v94.15  = v46 & ~new_n179_;
  assign new_n181_ = v33 & v43;
  assign new_n182_ = v45 & v47;
  assign \v94.17  = ~new_n181_ | ~new_n182_;
  assign new_n184_ = v51 & v52;
  assign new_n185_ = v48 & v49;
  assign new_n186_ = v50 & new_n185_;
  assign \v94.18  = ~new_n184_ | ~new_n186_;
  assign new_n188_ = v54 & v55;
  assign \v94.19  = ~v56 | ~new_n188_;
  assign \v94.20  = ~v53 | ~v57;
  assign new_n191_ = v65 & v66;
  assign new_n192_ = v62 & v63;
  assign new_n193_ = v64 & new_n192_;
  assign \v94.21  = ~new_n191_ | ~new_n193_;
  assign new_n195_ = ~v12 & ~v59;
  assign new_n196_ = ~v61 & v67;
  assign new_n197_ = ~v60 & new_n196_;
  assign new_n198_ = new_n195_ & new_n197_;
  assign \v94.22  = ~v68 | new_n198_;
  assign new_n200_ = v53 & v58;
  assign \v94.23  = ~v69 | ~new_n200_;
  assign new_n202_ = v70 & v71;
  assign new_n203_ = v72 & v73;
  assign \v94.25  = ~new_n202_ | ~new_n203_;
  assign new_n205_ = v75 & v77;
  assign new_n206_ = ~v21 & v76;
  assign new_n207_ = ~new_n205_ & ~new_n206_;
  assign \v94.26  = v74 & ~new_n207_;
  assign new_n209_ = v81 & v84;
  assign new_n210_ = v83 & ~new_n209_;
  assign new_n211_ = v82 & new_n210_;
  assign \v94.27  = v53 & new_n211_;
  assign new_n213_ = ~v27 & ~new_n211_;
  assign \v94.28  = v53 & ~new_n213_;
  assign new_n215_ = v55 & v80;
  assign \v94.29  = ~v85 | ~new_n215_;
  assign new_n217_ = v53 & v79;
  assign \v94.30  = ~v86 | ~new_n217_;
  assign new_n219_ = v55 & v78;
  assign new_n220_ = v82 & v85;
  assign \v94.31  = ~new_n219_ | ~new_n220_;
  assign new_n222_ = v41 & v87;
  assign new_n223_ = v15 & new_n222_;
  assign new_n224_ = v89 & v90;
  assign new_n225_ = v88 & new_n224_;
  assign new_n226_ = new_n223_ & new_n225_;
  assign \v94.32  = ~v38 | new_n226_;
  assign new_n228_ = v91 & v92;
  assign \v94.33  = v93 & new_n228_;
  assign \v94.34  = 1'b0;
  assign \v94.35  = 1'b0;
  assign \v94.36  = 1'b0;
  assign \v94.37  = 1'b0;
  assign \v94.38  = 1'b0;
  assign \v94.39  = 1'b0;
  assign \v94.40  = 1'b0;
  assign \v94.41  = 1'b0;
  assign \v94.42  = 1'b0;
  assign \v94.0  = ~v0;
  assign \v94.5  = ~v14;
  assign \v94.10  = ~v21;
  assign \v94.11  = ~v29;
  assign \v94.16  = ~v40;
  assign \v94.24  = ~v11;
endmodule


