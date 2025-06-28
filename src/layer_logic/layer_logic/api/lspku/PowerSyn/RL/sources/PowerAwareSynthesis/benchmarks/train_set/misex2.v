// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:29 2022

module misex2  ( 
    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x,
    y,
    z, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1, q1  );
  input  a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,
    v, w, x, y;
  output z, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1,
    q1;
  wire new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_, new_n51_,
    new_n52_, new_n53_, new_n54_, new_n56_, new_n57_, new_n58_, new_n60_,
    new_n61_, new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n67_,
    new_n68_, new_n69_, new_n70_, new_n72_, new_n73_, new_n74_, new_n75_,
    new_n76_, new_n78_, new_n81_, new_n82_, new_n83_, new_n84_, new_n87_,
    new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_, new_n94_,
    new_n96_, new_n97_, new_n98_, new_n99_, new_n100_, new_n101_,
    new_n102_, new_n103_, new_n104_, new_n105_, new_n106_, new_n107_,
    new_n108_, new_n109_, new_n111_, new_n112_, new_n113_, new_n114_,
    new_n115_, new_n116_, new_n117_, new_n118_, new_n119_, new_n120_,
    new_n121_, new_n122_, new_n123_, new_n124_, new_n126_, new_n127_,
    new_n128_, new_n129_, new_n130_, new_n131_, new_n132_, new_n133_,
    new_n134_, new_n135_, new_n137_, new_n138_, new_n139_, new_n140_,
    new_n141_, new_n142_, new_n143_, new_n144_, new_n145_, new_n146_,
    new_n147_, new_n148_, new_n150_, new_n152_, new_n153_, new_n154_,
    new_n156_, new_n157_, new_n158_, new_n159_, new_n160_;
  assign new_n44_ = ~a & ~b;
  assign new_n45_ = ~c & new_n44_;
  assign new_n46_ = ~j & new_n45_;
  assign new_n47_ = k & new_n46_;
  assign new_n48_ = ~r & new_n47_;
  assign new_n49_ = ~s & new_n48_;
  assign z = ~t & new_n49_;
  assign new_n51_ = j & new_n45_;
  assign new_n52_ = k & new_n51_;
  assign new_n53_ = ~r & new_n52_;
  assign new_n54_ = ~s & new_n53_;
  assign a1 = ~t & new_n54_;
  assign new_n56_ = ~k & new_n51_;
  assign new_n57_ = ~r & new_n56_;
  assign new_n58_ = ~s & new_n57_;
  assign b1 = ~t & new_n58_;
  assign new_n60_ = ~b & ~c;
  assign new_n61_ = ~a & new_n60_;
  assign new_n62_ = s & ~t;
  assign new_n63_ = ~r & new_n62_;
  assign new_n64_ = new_n61_ & new_n63_;
  assign new_n65_ = b & c;
  assign new_n66_ = a & new_n65_;
  assign new_n67_ = ~j & k;
  assign new_n68_ = l & m;
  assign new_n69_ = new_n67_ & new_n68_;
  assign new_n70_ = new_n66_ & new_n69_;
  assign c1 = new_n64_ | new_n70_;
  assign new_n72_ = a & b;
  assign new_n73_ = c & new_n72_;
  assign new_n74_ = ~j & new_n73_;
  assign new_n75_ = k & new_n74_;
  assign new_n76_ = ~l & new_n75_;
  assign d1 = ~m & new_n76_;
  assign new_n78_ = j & new_n73_;
  assign e1 = k & new_n78_;
  assign f1 = l & new_n75_;
  assign new_n81_ = l & ~m;
  assign new_n82_ = new_n67_ & new_n81_;
  assign new_n83_ = b & ~new_n82_;
  assign new_n84_ = c & ~new_n83_;
  assign g1 = a & new_n84_;
  assign q1 = c & new_n44_;
  assign new_n87_ = ~d & q1;
  assign new_n88_ = e & new_n87_;
  assign new_n89_ = ~f & new_n88_;
  assign new_n90_ = ~g & new_n89_;
  assign new_n91_ = ~h & new_n90_;
  assign new_n92_ = ~i & new_n91_;
  assign new_n93_ = r & new_n92_;
  assign new_n94_ = ~s & new_n93_;
  assign h1 = t & new_n94_;
  assign new_n96_ = ~l & m;
  assign new_n97_ = ~b & c;
  assign new_n98_ = new_n96_ & new_n97_;
  assign new_n99_ = ~n & ~o;
  assign new_n100_ = ~q & u;
  assign new_n101_ = ~p & new_n100_;
  assign new_n102_ = new_n99_ & new_n101_;
  assign new_n103_ = new_n98_ & new_n102_;
  assign new_n104_ = b & s;
  assign new_n105_ = ~t & ~u;
  assign new_n106_ = new_n104_ & new_n105_;
  assign new_n107_ = ~new_n103_ & ~new_n106_;
  assign new_n108_ = ~w & ~new_n107_;
  assign new_n109_ = ~v & new_n108_;
  assign i1 = ~a & new_n109_;
  assign new_n111_ = b & new_n62_;
  assign new_n112_ = v & w;
  assign new_n113_ = ~u & new_n112_;
  assign new_n114_ = new_n111_ & new_n113_;
  assign new_n115_ = m & ~n;
  assign new_n116_ = ~l & new_n115_;
  assign new_n117_ = new_n97_ & new_n116_;
  assign new_n118_ = p & q;
  assign new_n119_ = ~o & new_n118_;
  assign new_n120_ = ~v & ~w;
  assign new_n121_ = u & new_n120_;
  assign new_n122_ = new_n119_ & new_n121_;
  assign new_n123_ = new_n117_ & new_n122_;
  assign new_n124_ = ~new_n114_ & ~new_n123_;
  assign j1 = ~a & ~new_n124_;
  assign new_n126_ = ~u & v;
  assign new_n127_ = ~t & new_n126_;
  assign new_n128_ = new_n104_ & new_n127_;
  assign new_n129_ = ~o & p;
  assign new_n130_ = u & ~v;
  assign new_n131_ = ~q & new_n130_;
  assign new_n132_ = new_n129_ & new_n131_;
  assign new_n133_ = new_n117_ & new_n132_;
  assign new_n134_ = ~new_n128_ & ~new_n133_;
  assign new_n135_ = ~w & ~new_n134_;
  assign k1 = ~a & new_n135_;
  assign new_n137_ = c & k;
  assign new_n138_ = b & ~new_n137_;
  assign new_n139_ = a & new_n138_;
  assign new_n140_ = ~c & ~t;
  assign new_n141_ = x & ~new_n140_;
  assign new_n142_ = r & ~t;
  assign new_n143_ = ~c & new_n142_;
  assign new_n144_ = ~new_n141_ & ~new_n143_;
  assign new_n145_ = ~b & ~new_n144_;
  assign new_n146_ = ~a & new_n145_;
  assign new_n147_ = ~new_n139_ & ~new_n146_;
  assign new_n148_ = ~y & ~new_n147_;
  assign l1 = j & new_n148_;
  assign new_n150_ = r & new_n45_;
  assign m1 = ~t & new_n150_;
  assign new_n152_ = ~k & new_n46_;
  assign new_n153_ = ~r & new_n152_;
  assign new_n154_ = ~s & new_n153_;
  assign n1 = ~t & new_n154_;
  assign new_n156_ = b & ~k;
  assign new_n157_ = c & ~new_n156_;
  assign new_n158_ = a & ~new_n157_;
  assign new_n159_ = ~c & t;
  assign new_n160_ = ~b & new_n159_;
  assign o1 = new_n158_ | new_n160_;
  assign p1 = ~a & b;
endmodule


