// Benchmark "source.pla" written by ABC on Fri Feb 25 15:13:02 2022

module x9dn  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26,
    \v27.0 , \v27.1 , \v27.2 , \v27.3 , \v27.4 , \v27.5 , \v27.6   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26;
  output \v27.0 , \v27.1 , \v27.2 , \v27.3 , \v27.4 , \v27.5 , \v27.6 ;
  wire new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n41_,
    new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n71_,
    new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n127_, new_n128_, new_n129_, new_n130_, new_n131_,
    new_n132_, new_n133_, new_n134_, new_n135_, new_n136_, new_n137_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n142_, new_n143_,
    new_n144_, new_n145_, new_n146_, new_n147_, new_n148_, new_n149_,
    new_n150_, new_n151_, new_n154_, new_n155_, new_n156_, new_n157_,
    new_n158_, new_n159_, new_n160_, new_n161_, new_n162_, new_n163_,
    new_n164_, new_n165_, new_n166_, new_n167_, new_n168_, new_n169_,
    new_n170_, new_n171_, new_n172_, new_n173_, new_n174_, new_n175_,
    new_n176_, new_n177_, new_n178_, new_n179_, new_n180_, new_n181_,
    new_n182_, new_n183_, new_n184_, new_n185_, new_n186_, new_n187_,
    new_n188_, new_n189_;
  assign new_n35_ = v8 & v9;
  assign new_n36_ = ~v7 & new_n35_;
  assign new_n37_ = ~v8 & ~v9;
  assign new_n38_ = ~new_n36_ & ~new_n37_;
  assign new_n39_ = v6 & ~new_n38_;
  assign new_n40_ = v13 & ~new_n37_;
  assign new_n41_ = v7 & new_n40_;
  assign new_n42_ = ~v7 & v10;
  assign new_n43_ = ~v11 & ~v12;
  assign new_n44_ = new_n42_ & new_n43_;
  assign new_n45_ = ~new_n41_ & ~new_n44_;
  assign new_n46_ = ~new_n39_ & new_n45_;
  assign new_n47_ = v5 & ~new_n46_;
  assign new_n48_ = v4 & new_n47_;
  assign new_n49_ = v3 & new_n48_;
  assign new_n50_ = v2 & new_n49_;
  assign new_n51_ = v1 & new_n50_;
  assign \v27.0  = v0 & new_n51_;
  assign new_n53_ = v16 & ~new_n37_;
  assign new_n54_ = v7 & new_n53_;
  assign new_n55_ = v9 & v14;
  assign new_n56_ = v8 & new_n55_;
  assign new_n57_ = ~v12 & v15;
  assign new_n58_ = ~v11 & new_n57_;
  assign new_n59_ = ~new_n56_ & ~new_n58_;
  assign new_n60_ = ~v7 & ~new_n59_;
  assign new_n61_ = ~v9 & v14;
  assign new_n62_ = ~v8 & new_n61_;
  assign new_n63_ = ~new_n60_ & ~new_n62_;
  assign new_n64_ = ~new_n54_ & new_n63_;
  assign new_n65_ = ~v5 & ~new_n64_;
  assign new_n66_ = ~v4 & new_n65_;
  assign new_n67_ = ~v3 & new_n66_;
  assign new_n68_ = ~v2 & new_n67_;
  assign new_n69_ = ~v1 & new_n68_;
  assign \v27.1  = ~v0 & new_n69_;
  assign new_n71_ = ~v22 & v23;
  assign new_n72_ = v20 & ~new_n71_;
  assign new_n73_ = v21 & ~new_n72_;
  assign new_n74_ = v18 & ~new_n73_;
  assign new_n75_ = v19 & ~new_n74_;
  assign new_n76_ = v17 & ~new_n75_;
  assign new_n77_ = ~new_n46_ & ~new_n76_;
  assign new_n78_ = v22 & ~v23;
  assign new_n79_ = ~v20 & ~new_n78_;
  assign new_n80_ = ~v21 & ~new_n79_;
  assign new_n81_ = ~v18 & ~new_n80_;
  assign new_n82_ = ~v19 & ~new_n81_;
  assign new_n83_ = ~v17 & ~new_n82_;
  assign new_n84_ = ~new_n64_ & ~new_n83_;
  assign \v27.2  = new_n77_ | new_n84_;
  assign new_n86_ = ~v1 & v2;
  assign new_n87_ = v3 & ~new_n86_;
  assign new_n88_ = v4 & ~new_n87_;
  assign new_n89_ = v5 & ~new_n88_;
  assign new_n90_ = ~new_n46_ & ~new_n89_;
  assign new_n91_ = v1 & ~v2;
  assign new_n92_ = ~v3 & ~new_n91_;
  assign new_n93_ = ~v4 & ~new_n92_;
  assign new_n94_ = ~v5 & ~new_n93_;
  assign new_n95_ = ~new_n64_ & ~new_n94_;
  assign \v27.3  = new_n90_ | new_n95_;
  assign new_n97_ = v24 & v25;
  assign new_n98_ = v1 & v2;
  assign new_n99_ = v0 & new_n98_;
  assign new_n100_ = v3 & v4;
  assign new_n101_ = v5 & v6;
  assign new_n102_ = new_n100_ & new_n101_;
  assign new_n103_ = new_n99_ & new_n102_;
  assign new_n104_ = v17 & v18;
  assign new_n105_ = v19 & v20;
  assign new_n106_ = new_n104_ & new_n105_;
  assign new_n107_ = v21 & v22;
  assign new_n108_ = v23 & v26;
  assign new_n109_ = new_n107_ & new_n108_;
  assign new_n110_ = new_n106_ & new_n109_;
  assign new_n111_ = new_n103_ & new_n110_;
  assign new_n112_ = ~v1 & ~v2;
  assign new_n113_ = ~v0 & new_n112_;
  assign new_n114_ = ~v3 & ~v4;
  assign new_n115_ = ~v5 & v14;
  assign new_n116_ = new_n114_ & new_n115_;
  assign new_n117_ = new_n113_ & new_n116_;
  assign new_n118_ = ~v17 & ~v18;
  assign new_n119_ = ~v19 & ~v20;
  assign new_n120_ = new_n118_ & new_n119_;
  assign new_n121_ = ~v21 & ~v22;
  assign new_n122_ = ~v23 & ~v26;
  assign new_n123_ = new_n121_ & new_n122_;
  assign new_n124_ = new_n120_ & new_n123_;
  assign new_n125_ = new_n117_ & new_n124_;
  assign new_n126_ = ~new_n111_ & ~new_n125_;
  assign new_n127_ = ~new_n38_ & ~new_n126_;
  assign new_n128_ = v5 & v10;
  assign new_n129_ = new_n100_ & new_n128_;
  assign new_n130_ = new_n99_ & new_n129_;
  assign new_n131_ = new_n110_ & new_n130_;
  assign new_n132_ = ~v5 & v15;
  assign new_n133_ = new_n114_ & new_n132_;
  assign new_n134_ = new_n113_ & new_n133_;
  assign new_n135_ = new_n124_ & new_n134_;
  assign new_n136_ = ~new_n131_ & ~new_n135_;
  assign new_n137_ = ~v12 & ~new_n136_;
  assign new_n138_ = ~v11 & new_n137_;
  assign new_n139_ = ~v7 & new_n138_;
  assign new_n140_ = v5 & v13;
  assign new_n141_ = new_n100_ & new_n140_;
  assign new_n142_ = new_n99_ & new_n141_;
  assign new_n143_ = new_n110_ & new_n142_;
  assign new_n144_ = ~v5 & v16;
  assign new_n145_ = new_n114_ & new_n144_;
  assign new_n146_ = new_n113_ & new_n145_;
  assign new_n147_ = new_n124_ & new_n146_;
  assign new_n148_ = ~new_n143_ & ~new_n147_;
  assign new_n149_ = ~new_n37_ & ~new_n148_;
  assign new_n150_ = v7 & new_n149_;
  assign new_n151_ = ~new_n139_ & ~new_n150_;
  assign \v27.5  = new_n127_ | ~new_n151_;
  assign \v27.4  = ~new_n97_ & \v27.5 ;
  assign new_n154_ = v2 & v3;
  assign new_n155_ = v0 & v1;
  assign new_n156_ = new_n154_ & new_n155_;
  assign new_n157_ = v4 & v5;
  assign new_n158_ = v6 & v17;
  assign new_n159_ = new_n157_ & new_n158_;
  assign new_n160_ = new_n156_ & new_n159_;
  assign new_n161_ = ~v2 & ~v3;
  assign new_n162_ = ~v0 & ~v1;
  assign new_n163_ = new_n161_ & new_n162_;
  assign new_n164_ = ~v4 & ~v5;
  assign new_n165_ = v14 & ~v17;
  assign new_n166_ = new_n164_ & new_n165_;
  assign new_n167_ = new_n163_ & new_n166_;
  assign new_n168_ = ~new_n160_ & ~new_n167_;
  assign new_n169_ = ~new_n38_ & ~new_n168_;
  assign new_n170_ = v10 & v17;
  assign new_n171_ = new_n157_ & new_n170_;
  assign new_n172_ = new_n156_ & new_n171_;
  assign new_n173_ = v15 & ~v17;
  assign new_n174_ = new_n164_ & new_n173_;
  assign new_n175_ = new_n163_ & new_n174_;
  assign new_n176_ = ~new_n172_ & ~new_n175_;
  assign new_n177_ = ~v12 & ~new_n176_;
  assign new_n178_ = ~v11 & new_n177_;
  assign new_n179_ = ~v7 & new_n178_;
  assign new_n180_ = v13 & v17;
  assign new_n181_ = new_n157_ & new_n180_;
  assign new_n182_ = new_n156_ & new_n181_;
  assign new_n183_ = v16 & ~v17;
  assign new_n184_ = new_n164_ & new_n183_;
  assign new_n185_ = new_n163_ & new_n184_;
  assign new_n186_ = ~new_n182_ & ~new_n185_;
  assign new_n187_ = ~new_n37_ & ~new_n186_;
  assign new_n188_ = v7 & new_n187_;
  assign new_n189_ = ~new_n179_ & ~new_n188_;
  assign \v27.6  = new_n169_ | ~new_n189_;
endmodule


