// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:54 2022

module misj  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,
    v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,
    v30, v31, v32, v33, v34,
    \v35.0 , \v35.1 , \v35.2 , \v35.3 , \v35.4 , \v35.5 , \v35.6 , \v35.7 ,
    \v35.8 , \v35.9 , \v35.10 , \v35.11 , \v35.12 , \v35.13   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28,
    v29, v30, v31, v32, v33, v34;
  output \v35.0 , \v35.1 , \v35.2 , \v35.3 , \v35.4 , \v35.5 , \v35.6 ,
    \v35.7 , \v35.8 , \v35.9 , \v35.10 , \v35.11 , \v35.12 , \v35.13 ;
  wire new_n51_, new_n52_, new_n54_, new_n55_, new_n56_, new_n57_, new_n58_,
    new_n59_, new_n61_, new_n62_, new_n64_, new_n65_, new_n66_, new_n69_,
    new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_,
    new_n79_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_;
  assign new_n51_ = v0 & v1;
  assign new_n52_ = v2 & new_n51_;
  assign \v35.0  = v3 & new_n52_;
  assign new_n54_ = v1 & v3;
  assign new_n55_ = v15 & v16;
  assign new_n56_ = v4 & new_n55_;
  assign new_n57_ = new_n54_ & new_n56_;
  assign new_n58_ = v8 & ~new_n57_;
  assign new_n59_ = ~v5 & ~new_n58_;
  assign \v35.1  = v7 & ~new_n59_;
  assign new_n61_ = v10 & v11;
  assign new_n62_ = ~v5 & ~new_n61_;
  assign \v35.3  = ~v7 | new_n62_;
  assign new_n64_ = v13 & v14;
  assign new_n65_ = v12 & new_n64_;
  assign new_n66_ = ~v5 & ~new_n65_;
  assign \v35.4  = ~v7 | new_n66_;
  assign \v35.5  = ~v17 | ~v18;
  assign new_n69_ = ~v9 & ~v19;
  assign \v35.6  = v20 | ~new_n69_;
  assign \v35.8  = ~v6 | ~v21;
  assign new_n72_ = v32 & v33;
  assign new_n73_ = v29 & v30;
  assign new_n74_ = v31 & new_n73_;
  assign new_n75_ = new_n72_ & new_n74_;
  assign new_n76_ = v27 & v28;
  assign new_n77_ = v22 & ~v23;
  assign new_n78_ = ~v25 & new_n77_;
  assign new_n79_ = new_n76_ & new_n78_;
  assign \v35.9  = ~new_n75_ | ~new_n79_;
  assign new_n81_ = v33 & v34;
  assign new_n82_ = v30 & v31;
  assign new_n83_ = v32 & new_n82_;
  assign new_n84_ = new_n81_ & new_n83_;
  assign new_n85_ = v22 & v24;
  assign new_n86_ = v26 & new_n85_;
  assign new_n87_ = new_n76_ & new_n86_;
  assign \v35.10  = ~new_n84_ | ~new_n87_;
  assign \v35.11  = v7 & new_n58_;
  assign \v35.12  = 1'b0;
  assign \v35.13  = 1'b0;
  assign \v35.2  = ~v5;
  assign \v35.7  = ~v15;
endmodule


