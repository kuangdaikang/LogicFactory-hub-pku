// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:41 2022

module b11  ( 
    v0, v1, v2, v3, v4, v5, v6, v7,
    \v8.0 , \v8.1 , \v8.2 , \v8.3 , \v8.4 , \v8.5 , \v8.6 , \v8.7 , \v8.8 ,
    \v8.9 , \v8.10 , \v8.11 , \v8.12 , \v8.13 , \v8.14 , \v8.15 , \v8.16 ,
    \v8.17 , \v8.18 , \v8.19 , \v8.20 , \v8.21 , \v8.22 , \v8.23 , \v8.24 ,
    \v8.25 , \v8.26 , \v8.27 , \v8.28 , \v8.29 , \v8.30   );
  input  v0, v1, v2, v3, v4, v5, v6, v7;
  output \v8.0 , \v8.1 , \v8.2 , \v8.3 , \v8.4 , \v8.5 , \v8.6 , \v8.7 ,
    \v8.8 , \v8.9 , \v8.10 , \v8.11 , \v8.12 , \v8.13 , \v8.14 , \v8.15 ,
    \v8.16 , \v8.17 , \v8.18 , \v8.19 , \v8.20 , \v8.21 , \v8.22 , \v8.23 ,
    \v8.24 , \v8.25 , \v8.26 , \v8.27 , \v8.28 , \v8.29 , \v8.30 ;
  wire new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_, new_n47_,
    new_n48_, new_n49_, new_n50_, new_n52_, new_n53_, new_n54_, new_n55_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n69_, new_n70_, new_n71_,
    new_n72_, new_n73_, new_n74_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n83_, new_n84_, new_n86_, new_n87_, new_n89_,
    new_n90_, new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n97_,
    new_n100_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n115_, new_n117_, new_n120_, new_n121_, new_n122_, new_n124_,
    new_n125_, new_n127_, new_n131_, new_n132_, new_n133_, new_n134_,
    new_n136_, new_n137_, new_n139_, new_n140_, new_n141_, new_n143_,
    new_n144_, new_n146_, new_n147_, new_n148_, new_n149_, new_n151_,
    new_n153_, new_n154_, new_n155_, new_n156_, new_n158_, new_n160_,
    new_n161_, new_n162_;
  assign new_n41_ = v5 & ~v6;
  assign new_n42_ = v5 & ~new_n41_;
  assign new_n43_ = ~v4 & ~new_n42_;
  assign new_n44_ = ~v3 & new_n43_;
  assign new_n45_ = ~v2 & new_n44_;
  assign new_n46_ = v1 & new_n45_;
  assign new_n47_ = ~v1 & v2;
  assign new_n48_ = v3 & v4;
  assign new_n49_ = new_n47_ & new_n48_;
  assign new_n50_ = ~new_n46_ & ~new_n49_;
  assign \v8.1  = ~v0 & ~new_n50_;
  assign new_n52_ = ~v0 & ~v1;
  assign new_n53_ = v2 & new_n52_;
  assign new_n54_ = v3 & new_n53_;
  assign new_n55_ = ~v4 & new_n54_;
  assign \v8.2  = v5 & new_n55_;
  assign new_n57_ = ~v4 & v5;
  assign new_n58_ = ~v1 & new_n57_;
  assign new_n59_ = ~v1 & ~new_n58_;
  assign new_n60_ = v3 & ~new_n59_;
  assign new_n61_ = v1 & ~v3;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = v2 & ~new_n62_;
  assign new_n64_ = ~v0 & new_n63_;
  assign new_n65_ = v0 & v1;
  assign new_n66_ = ~v2 & ~v3;
  assign new_n67_ = new_n65_ & new_n66_;
  assign \v8.3  = new_n64_ | new_n67_;
  assign new_n69_ = ~v3 & v7;
  assign new_n70_ = ~v3 & ~new_n69_;
  assign new_n71_ = ~v4 & ~new_n70_;
  assign new_n72_ = ~v1 & new_n71_;
  assign new_n73_ = ~new_n61_ & ~new_n72_;
  assign new_n74_ = ~v2 & ~new_n73_;
  assign \v8.4  = v0 & new_n74_;
  assign new_n76_ = v0 & v2;
  assign new_n77_ = ~v0 & new_n66_;
  assign new_n78_ = ~new_n76_ & ~new_n77_;
  assign new_n79_ = ~v2 & v3;
  assign new_n80_ = ~v0 & new_n79_;
  assign new_n81_ = new_n78_ & ~new_n80_;
  assign \v8.5  = ~v1 & ~new_n81_;
  assign new_n83_ = v2 & v3;
  assign new_n84_ = ~v1 & new_n83_;
  assign \v8.6  = ~v0 & new_n84_;
  assign new_n86_ = v2 & ~v3;
  assign new_n87_ = ~v1 & new_n86_;
  assign \v8.7  = ~v0 & new_n87_;
  assign new_n89_ = ~v4 & ~v5;
  assign new_n90_ = ~v4 & ~new_n89_;
  assign new_n91_ = v3 & ~new_n90_;
  assign new_n92_ = ~v3 & ~v5;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = v2 & ~new_n93_;
  assign new_n95_ = ~v1 & new_n94_;
  assign \v8.8  = ~v0 & new_n95_;
  assign new_n97_ = v1 & v2;
  assign \v8.9  = ~v0 & new_n97_;
  assign \v8.10  = ~v0 & new_n46_;
  assign new_n100_ = v1 & new_n66_;
  assign \v8.11  = ~v0 & new_n100_;
  assign new_n102_ = v5 & v6;
  assign new_n103_ = v5 & ~new_n102_;
  assign new_n104_ = ~v4 & ~new_n103_;
  assign new_n105_ = ~v3 & new_n104_;
  assign new_n106_ = ~v2 & new_n105_;
  assign new_n107_ = v1 & new_n106_;
  assign \v8.12  = ~v0 & new_n107_;
  assign new_n109_ = ~v4 & new_n41_;
  assign new_n110_ = ~v4 & ~new_n109_;
  assign new_n111_ = ~v3 & ~new_n110_;
  assign new_n112_ = ~v2 & new_n111_;
  assign new_n113_ = v1 & new_n112_;
  assign \v8.13  = ~v0 & new_n113_;
  assign new_n115_ = v1 & ~v2;
  assign \v8.14  = ~v0 & new_n115_;
  assign new_n117_ = ~v1 & ~v2;
  assign \v8.15  = ~v0 & new_n117_;
  assign \v8.16  = v2 | ~new_n52_;
  assign new_n120_ = ~v3 & v5;
  assign new_n121_ = v2 & new_n120_;
  assign new_n122_ = ~v1 & new_n121_;
  assign \v8.17  = v0 & new_n122_;
  assign new_n124_ = v2 & new_n92_;
  assign new_n125_ = ~v1 & new_n124_;
  assign \v8.18  = v0 & new_n125_;
  assign new_n127_ = ~v3 & ~\v8.16 ;
  assign \v8.19  = ~v4 & new_n127_;
  assign \v8.20  = v3 & ~\v8.16 ;
  assign \v8.21  = v2 & new_n65_;
  assign new_n131_ = v3 & ~v4;
  assign new_n132_ = ~v1 & new_n131_;
  assign new_n133_ = ~new_n61_ & ~new_n132_;
  assign new_n134_ = ~v2 & ~new_n133_;
  assign \v8.22  = v0 & new_n134_;
  assign new_n136_ = ~v2 & new_n131_;
  assign new_n137_ = ~v1 & new_n136_;
  assign \v8.23  = v0 & new_n137_;
  assign new_n139_ = ~v3 & ~v4;
  assign new_n140_ = ~v2 & new_n139_;
  assign new_n141_ = ~v1 & new_n140_;
  assign \v8.24  = v0 & new_n141_;
  assign new_n143_ = ~v2 & new_n57_;
  assign new_n144_ = ~v1 & new_n143_;
  assign \v8.25  = v0 & new_n144_;
  assign new_n146_ = ~v1 & v4;
  assign new_n147_ = ~v1 & ~new_n146_;
  assign new_n148_ = v3 & ~new_n147_;
  assign new_n149_ = ~v2 & new_n148_;
  assign \v8.26  = v0 & new_n149_;
  assign new_n151_ = ~new_n97_ & ~new_n144_;
  assign \v8.27  = v0 & ~new_n151_;
  assign new_n153_ = ~v3 & v4;
  assign new_n154_ = ~v3 & ~new_n153_;
  assign new_n155_ = ~new_n139_ & new_n154_;
  assign new_n156_ = v1 & ~new_n155_;
  assign \v8.28  = ~v0 & new_n156_;
  assign new_n158_ = ~v3 & new_n53_;
  assign \v8.29  = v5 & new_n158_;
  assign new_n160_ = v0 & ~v1;
  assign new_n161_ = v2 & new_n160_;
  assign new_n162_ = v3 & new_n161_;
  assign \v8.30  = ~v4 & new_n162_;
  assign \v8.0  = 1'b0;
endmodule


