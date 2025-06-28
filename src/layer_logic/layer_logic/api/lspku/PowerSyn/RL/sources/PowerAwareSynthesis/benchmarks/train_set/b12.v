// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:45 2022

module b12  ( 
    v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14,
    \v15.0 , \v15.1 , \v15.2 , \v15.3 , \v15.4 , \v15.5 , \v15.6 , \v15.7 ,
    \v15.8   );
  input  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14;
  output \v15.0 , \v15.1 , \v15.2 , \v15.3 , \v15.4 , \v15.5 , \v15.6 ,
    \v15.7 , \v15.8 ;
  wire new_n25_, new_n26_, new_n27_, new_n28_, new_n29_, new_n30_, new_n31_,
    new_n32_, new_n33_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n41_, new_n42_, new_n43_, new_n45_, new_n46_, new_n47_,
    new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n61_, new_n62_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n69_, new_n70_, new_n71_,
    new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n94_,
    new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n101_, new_n102_,
    new_n103_, new_n104_, new_n105_, new_n106_, new_n107_;
  assign new_n25_ = v4 & ~v5;
  assign new_n26_ = ~v2 & ~v3;
  assign new_n27_ = ~new_n25_ & ~new_n26_;
  assign new_n28_ = ~v2 & v3;
  assign new_n29_ = ~new_n27_ & ~new_n28_;
  assign new_n30_ = v1 & ~new_n29_;
  assign new_n31_ = v3 & ~v4;
  assign new_n32_ = v2 & new_n31_;
  assign new_n33_ = ~new_n30_ & ~new_n32_;
  assign \v15.0  = ~v0 & ~new_n33_;
  assign new_n35_ = ~v3 & ~v4;
  assign new_n36_ = v5 & v6;
  assign new_n37_ = v1 & new_n36_;
  assign new_n38_ = ~new_n35_ & ~new_n37_;
  assign new_n39_ = v2 & new_n38_;
  assign new_n40_ = v2 & new_n36_;
  assign new_n41_ = v3 & ~new_n40_;
  assign new_n42_ = v1 & new_n41_;
  assign new_n43_ = ~new_n39_ & ~new_n42_;
  assign \v15.1  = ~v0 & ~new_n43_;
  assign new_n45_ = ~v7 & ~v8;
  assign new_n46_ = v0 & ~new_n45_;
  assign new_n47_ = ~v9 & ~v10;
  assign new_n48_ = ~v3 & ~new_n47_;
  assign new_n49_ = ~v1 & new_n48_;
  assign new_n50_ = ~v2 & ~new_n49_;
  assign new_n51_ = ~new_n46_ & ~new_n50_;
  assign new_n52_ = ~v3 & v7;
  assign new_n53_ = v9 & ~v10;
  assign new_n54_ = ~v7 & new_n53_;
  assign new_n55_ = ~new_n52_ & ~new_n54_;
  assign new_n56_ = ~v0 & ~new_n55_;
  assign new_n57_ = new_n45_ & new_n53_;
  assign new_n58_ = ~new_n56_ & ~new_n57_;
  assign new_n59_ = ~v1 & ~new_n58_;
  assign \v15.2  = new_n51_ | new_n59_;
  assign new_n61_ = v7 & v11;
  assign new_n62_ = ~v0 & v12;
  assign \v15.3  = ~new_n61_ & ~new_n62_;
  assign new_n64_ = v8 & v9;
  assign new_n65_ = v0 & new_n64_;
  assign new_n66_ = ~new_n61_ & ~new_n65_;
  assign new_n67_ = v7 & ~v11;
  assign \v15.4  = new_n66_ | new_n67_;
  assign new_n69_ = ~v12 & v13;
  assign new_n70_ = ~v0 & ~v7;
  assign new_n71_ = ~v10 & new_n70_;
  assign \v15.5  = ~new_n69_ | ~new_n71_;
  assign new_n73_ = ~v1 & ~v2;
  assign new_n74_ = ~v3 & v9;
  assign new_n75_ = v3 & ~v9;
  assign new_n76_ = ~new_n74_ & ~new_n75_;
  assign new_n77_ = new_n73_ & new_n76_;
  assign new_n78_ = ~v0 & v14;
  assign new_n79_ = ~v8 & ~new_n78_;
  assign new_n80_ = ~v0 & ~v14;
  assign new_n81_ = ~new_n79_ & ~new_n80_;
  assign new_n82_ = ~new_n77_ & ~new_n81_;
  assign new_n83_ = v0 & v8;
  assign new_n84_ = v1 & v2;
  assign new_n85_ = ~new_n76_ & ~new_n84_;
  assign new_n86_ = ~v1 & v2;
  assign new_n87_ = v1 & ~v2;
  assign new_n88_ = ~new_n86_ & ~new_n87_;
  assign new_n89_ = ~new_n85_ & new_n88_;
  assign new_n90_ = ~new_n83_ & ~new_n89_;
  assign new_n91_ = ~new_n82_ & ~new_n90_;
  assign new_n92_ = ~v10 & ~new_n91_;
  assign \v15.6  = ~v7 & new_n92_;
  assign new_n94_ = ~v1 & new_n28_;
  assign new_n95_ = v8 & ~new_n94_;
  assign new_n96_ = v9 & ~new_n95_;
  assign new_n97_ = ~v8 & ~new_n94_;
  assign new_n98_ = ~v7 & ~v10;
  assign new_n99_ = ~new_n97_ & new_n98_;
  assign \v15.7  = new_n96_ | ~new_n99_;
  assign new_n101_ = v0 & ~v9;
  assign new_n102_ = v3 & ~v12;
  assign new_n103_ = new_n73_ & new_n102_;
  assign new_n104_ = ~new_n101_ & ~new_n103_;
  assign new_n105_ = ~v0 & ~v9;
  assign new_n106_ = ~v10 & ~new_n105_;
  assign new_n107_ = ~v7 & new_n106_;
  assign \v15.8  = new_n104_ | ~new_n107_;
endmodule


