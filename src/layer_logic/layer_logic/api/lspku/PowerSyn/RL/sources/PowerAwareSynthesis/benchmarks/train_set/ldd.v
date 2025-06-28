// Benchmark "ldd" written by ABC on Fri Feb 25 15:12:33 2022

module ldd ( 
    a, b, c, d, e, f, g, h, i,
    j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a0, b0  );
  input  a, b, c, d, e, f, g, h, i;
  output j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a0, b0;
  wire new_n29_, new_n30_, new_n31_, new_n32_, new_n33_, new_n34_, new_n35_,
    new_n36_, new_n37_, new_n38_, new_n39_, new_n40_, new_n42_, new_n44_,
    new_n45_, new_n46_, new_n48_, new_n49_, new_n51_, new_n52_, new_n53_,
    new_n54_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_,
    new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_,
    new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n90_, new_n91_, new_n94_, new_n95_, new_n96_,
    new_n97_, new_n98_, new_n99_, new_n100_, new_n101_, new_n102_,
    new_n104_, new_n105_, new_n106_, new_n107_, new_n108_, new_n110_,
    new_n111_, new_n112_, new_n114_, new_n115_, new_n117_, new_n118_,
    new_n120_, new_n121_;
  assign new_n29_ = ~a & ~b;
  assign new_n30_ = ~c & new_n29_;
  assign new_n31_ = ~d & new_n30_;
  assign new_n32_ = ~e & new_n31_;
  assign new_n33_ = ~f & new_n32_;
  assign new_n34_ = ~g & new_n33_;
  assign new_n35_ = h & new_n34_;
  assign new_n36_ = g & new_n33_;
  assign new_n37_ = c & new_n29_;
  assign new_n38_ = i & new_n37_;
  assign new_n39_ = ~a & b;
  assign new_n40_ = ~c & new_n39_;
  assign r = i & new_n40_;
  assign new_n42_ = c & new_n39_;
  assign s = i & new_n42_;
  assign new_n44_ = a & ~b;
  assign new_n45_ = ~c & new_n44_;
  assign new_n46_ = ~i & new_n45_;
  assign t = i & new_n45_;
  assign new_n48_ = c & new_n44_;
  assign new_n49_ = ~i & new_n48_;
  assign u = i & new_n48_;
  assign new_n51_ = a & b;
  assign new_n52_ = ~c & new_n51_;
  assign new_n53_ = ~i & new_n52_;
  assign new_n54_ = i & new_n52_;
  assign o = new_n53_ | new_n54_;
  assign new_n56_ = ~t & ~new_n49_;
  assign new_n57_ = ~u & new_n56_;
  assign new_n58_ = ~o & new_n57_;
  assign new_n59_ = ~r & ~s;
  assign new_n60_ = ~new_n46_ & new_n59_;
  assign new_n61_ = ~new_n35_ & ~new_n36_;
  assign new_n62_ = ~new_n38_ & new_n61_;
  assign new_n63_ = new_n60_ & new_n62_;
  assign j = ~new_n58_ | ~new_n63_;
  assign new_n65_ = f & new_n32_;
  assign new_n66_ = e & new_n31_;
  assign new_n67_ = ~i & new_n40_;
  assign new_n68_ = ~i & new_n42_;
  assign new_n69_ = ~s & ~t;
  assign new_n70_ = ~u & new_n69_;
  assign new_n71_ = ~o & new_n70_;
  assign new_n72_ = ~r & ~new_n67_;
  assign new_n73_ = ~new_n68_ & new_n72_;
  assign new_n74_ = ~new_n65_ & ~new_n66_;
  assign new_n75_ = ~new_n38_ & new_n74_;
  assign new_n76_ = new_n73_ & new_n75_;
  assign k = ~new_n71_ | ~new_n76_;
  assign b0 = d & new_n30_;
  assign new_n79_ = ~i & new_n37_;
  assign new_n80_ = ~new_n49_ & ~new_n54_;
  assign new_n81_ = ~s & ~new_n68_;
  assign new_n82_ = ~t & new_n81_;
  assign new_n83_ = new_n80_ & new_n82_;
  assign p = new_n38_ | new_n79_;
  assign new_n85_ = ~r & ~p;
  assign new_n86_ = ~new_n35_ & ~new_n65_;
  assign new_n87_ = ~b0 & new_n86_;
  assign new_n88_ = new_n85_ & new_n87_;
  assign l = ~new_n83_ | ~new_n88_;
  assign new_n90_ = ~s & ~new_n49_;
  assign new_n91_ = ~u & new_n90_;
  assign m = ~new_n73_ | ~new_n91_;
  assign n = new_n46_ | t;
  assign new_n94_ = new_n74_ & ~b0;
  assign new_n95_ = ~c & ~d;
  assign new_n96_ = new_n29_ & new_n95_;
  assign new_n97_ = ~e & ~f;
  assign new_n98_ = ~g & ~h;
  assign new_n99_ = new_n97_ & new_n98_;
  assign new_n100_ = new_n96_ & new_n99_;
  assign new_n101_ = ~new_n35_ & ~new_n100_;
  assign new_n102_ = ~new_n36_ & new_n101_;
  assign q = ~new_n94_ | ~new_n102_;
  assign new_n104_ = ~new_n49_ & ~u;
  assign new_n105_ = new_n69_ & new_n104_;
  assign new_n106_ = ~r & ~new_n66_;
  assign new_n107_ = new_n61_ & ~new_n65_;
  assign new_n108_ = new_n106_ & new_n107_;
  assign v = ~new_n105_ | ~new_n108_;
  assign new_n110_ = ~t & ~u;
  assign new_n111_ = new_n59_ & new_n110_;
  assign new_n112_ = new_n61_ & new_n74_;
  assign w = ~new_n111_ | ~new_n112_;
  assign new_n114_ = ~new_n36_ & ~new_n66_;
  assign new_n115_ = ~r & ~t;
  assign y = ~new_n114_ | ~new_n115_;
  assign new_n117_ = ~new_n35_ & ~new_n66_;
  assign new_n118_ = ~r & ~u;
  assign z = ~new_n117_ | ~new_n118_;
  assign new_n120_ = ~new_n36_ & ~new_n65_;
  assign new_n121_ = ~u & ~new_n66_;
  assign a0 = ~new_n120_ | ~new_n121_;
  assign x = w;
endmodule


