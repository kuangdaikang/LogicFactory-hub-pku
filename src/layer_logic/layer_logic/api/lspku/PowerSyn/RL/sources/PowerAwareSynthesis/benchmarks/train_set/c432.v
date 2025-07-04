// Benchmark "c432.blif" written by ABC on Fri Feb 25 15:12:40 2022

module c432  ( 
    G1gat, G4gat, G8gat, G11gat, G14gat, G17gat, G21gat, G24gat, G27gat,
    G30gat, G34gat, G37gat, G40gat, G43gat, G47gat, G50gat, G53gat, G56gat,
    G60gat, G63gat, G66gat, G69gat, G73gat, G76gat, G79gat, G82gat, G86gat,
    G89gat, G92gat, G95gat, G99gat, G102gat, G105gat, G108gat, G112gat,
    G115gat,
    G223gat, G329gat, G370gat, G421gat, G430gat, G431gat, G432gat  );
  input  G1gat, G4gat, G8gat, G11gat, G14gat, G17gat, G21gat, G24gat,
    G27gat, G30gat, G34gat, G37gat, G40gat, G43gat, G47gat, G50gat, G53gat,
    G56gat, G60gat, G63gat, G66gat, G69gat, G73gat, G76gat, G79gat, G82gat,
    G86gat, G89gat, G92gat, G95gat, G99gat, G102gat, G105gat, G108gat,
    G112gat, G115gat;
  output G223gat, G329gat, G370gat, G421gat, G430gat, G431gat, G432gat;
  wire new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_, new_n50_,
    new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_, new_n57_,
    new_n58_, new_n59_, new_n61_, new_n62_, new_n63_, new_n64_, new_n65_,
    new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n73_, new_n74_, new_n75_, new_n76_, new_n77_, new_n78_, new_n79_,
    new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_, new_n86_,
    new_n87_, new_n88_, new_n89_, new_n90_, new_n91_, new_n92_, new_n93_,
    new_n94_, new_n95_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n108_, new_n109_, new_n110_, new_n111_, new_n112_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n127_, new_n128_, new_n129_, new_n130_, new_n131_,
    new_n132_, new_n133_, new_n134_, new_n135_, new_n136_, new_n137_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n142_, new_n143_,
    new_n144_, new_n145_, new_n146_, new_n147_, new_n148_, new_n149_,
    new_n150_, new_n151_, new_n152_, new_n153_, new_n154_, new_n155_,
    new_n156_, new_n157_, new_n158_, new_n159_, new_n160_, new_n161_,
    new_n162_, new_n163_, new_n164_, new_n165_, new_n166_, new_n167_,
    new_n168_, new_n169_, new_n170_, new_n171_, new_n172_, new_n173_,
    new_n174_, new_n176_, new_n177_, new_n178_, new_n179_, new_n180_,
    new_n181_, new_n182_, new_n183_, new_n184_, new_n185_, new_n186_,
    new_n187_, new_n188_, new_n189_, new_n190_, new_n191_, new_n192_,
    new_n193_, new_n194_, new_n195_, new_n196_, new_n197_, new_n198_,
    new_n199_, new_n200_, new_n201_, new_n202_, new_n203_, new_n204_,
    new_n205_, new_n206_, new_n207_, new_n208_, new_n209_, new_n210_,
    new_n211_, new_n212_, new_n213_, new_n214_, new_n215_, new_n216_,
    new_n217_, new_n218_, new_n219_, new_n220_, new_n221_, new_n222_,
    new_n223_, new_n224_, new_n225_, new_n226_, new_n227_, new_n228_,
    new_n229_, new_n230_, new_n231_, new_n232_, new_n233_, new_n234_,
    new_n235_, new_n236_, new_n238_, new_n239_, new_n241_, new_n242_,
    new_n243_, new_n244_, new_n245_, new_n246_, new_n248_, new_n249_,
    new_n250_, new_n251_;
  assign new_n44_ = ~G1gat & G4gat;
  assign new_n45_ = ~G11gat & G17gat;
  assign new_n46_ = ~G24gat & G30gat;
  assign new_n47_ = ~G37gat & G43gat;
  assign new_n48_ = ~G50gat & G56gat;
  assign new_n49_ = ~G63gat & G69gat;
  assign new_n50_ = ~G76gat & G82gat;
  assign new_n51_ = ~G89gat & G95gat;
  assign new_n52_ = ~G102gat & G108gat;
  assign new_n53_ = ~new_n44_ & ~new_n45_;
  assign new_n54_ = ~new_n46_ & new_n53_;
  assign new_n55_ = ~new_n47_ & new_n54_;
  assign new_n56_ = ~new_n48_ & new_n55_;
  assign new_n57_ = ~new_n49_ & new_n56_;
  assign new_n58_ = ~new_n50_ & new_n57_;
  assign new_n59_ = ~new_n51_ & new_n58_;
  assign G223gat = new_n52_ | ~new_n59_;
  assign new_n61_ = ~new_n44_ & ~G223gat;
  assign new_n62_ = new_n44_ & G223gat;
  assign new_n63_ = ~new_n61_ & ~new_n62_;
  assign new_n64_ = G4gat & ~G8gat;
  assign new_n65_ = ~new_n63_ & new_n64_;
  assign new_n66_ = ~new_n45_ & ~G223gat;
  assign new_n67_ = new_n45_ & G223gat;
  assign new_n68_ = ~new_n66_ & ~new_n67_;
  assign new_n69_ = G17gat & ~G21gat;
  assign new_n70_ = ~new_n68_ & new_n69_;
  assign new_n71_ = ~new_n46_ & ~G223gat;
  assign new_n72_ = new_n46_ & G223gat;
  assign new_n73_ = ~new_n71_ & ~new_n72_;
  assign new_n74_ = G30gat & ~G34gat;
  assign new_n75_ = ~new_n73_ & new_n74_;
  assign new_n76_ = ~new_n47_ & ~G223gat;
  assign new_n77_ = new_n47_ & G223gat;
  assign new_n78_ = ~new_n76_ & ~new_n77_;
  assign new_n79_ = G43gat & ~G47gat;
  assign new_n80_ = ~new_n78_ & new_n79_;
  assign new_n81_ = ~new_n48_ & ~G223gat;
  assign new_n82_ = new_n48_ & G223gat;
  assign new_n83_ = ~new_n81_ & ~new_n82_;
  assign new_n84_ = G56gat & ~G60gat;
  assign new_n85_ = ~new_n83_ & new_n84_;
  assign new_n86_ = ~new_n49_ & ~G223gat;
  assign new_n87_ = new_n49_ & G223gat;
  assign new_n88_ = ~new_n86_ & ~new_n87_;
  assign new_n89_ = G69gat & ~G73gat;
  assign new_n90_ = ~new_n88_ & new_n89_;
  assign new_n91_ = ~new_n50_ & ~G223gat;
  assign new_n92_ = new_n50_ & G223gat;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = G82gat & ~G86gat;
  assign new_n95_ = ~new_n93_ & new_n94_;
  assign new_n96_ = ~new_n51_ & ~G223gat;
  assign new_n97_ = new_n51_ & G223gat;
  assign new_n98_ = ~new_n96_ & ~new_n97_;
  assign new_n99_ = G95gat & ~G99gat;
  assign new_n100_ = ~new_n98_ & new_n99_;
  assign new_n101_ = ~new_n52_ & ~G223gat;
  assign new_n102_ = new_n52_ & G223gat;
  assign new_n103_ = ~new_n101_ & ~new_n102_;
  assign new_n104_ = G108gat & ~G112gat;
  assign new_n105_ = ~new_n103_ & new_n104_;
  assign new_n106_ = ~new_n65_ & ~new_n70_;
  assign new_n107_ = ~new_n75_ & new_n106_;
  assign new_n108_ = ~new_n80_ & new_n107_;
  assign new_n109_ = ~new_n85_ & new_n108_;
  assign new_n110_ = ~new_n90_ & new_n109_;
  assign new_n111_ = ~new_n95_ & new_n110_;
  assign new_n112_ = ~new_n100_ & new_n111_;
  assign G329gat = new_n105_ | ~new_n112_;
  assign new_n114_ = ~new_n65_ & ~G329gat;
  assign new_n115_ = new_n65_ & G329gat;
  assign new_n116_ = ~new_n114_ & ~new_n115_;
  assign new_n117_ = G4gat & ~G14gat;
  assign new_n118_ = ~new_n63_ & new_n117_;
  assign new_n119_ = ~new_n116_ & new_n118_;
  assign new_n120_ = ~new_n70_ & ~G329gat;
  assign new_n121_ = new_n70_ & G329gat;
  assign new_n122_ = ~new_n120_ & ~new_n121_;
  assign new_n123_ = G17gat & ~G27gat;
  assign new_n124_ = ~new_n68_ & new_n123_;
  assign new_n125_ = ~new_n122_ & new_n124_;
  assign new_n126_ = ~new_n75_ & ~G329gat;
  assign new_n127_ = new_n75_ & G329gat;
  assign new_n128_ = ~new_n126_ & ~new_n127_;
  assign new_n129_ = G30gat & ~G40gat;
  assign new_n130_ = ~new_n73_ & new_n129_;
  assign new_n131_ = ~new_n128_ & new_n130_;
  assign new_n132_ = ~new_n80_ & ~G329gat;
  assign new_n133_ = new_n80_ & G329gat;
  assign new_n134_ = ~new_n132_ & ~new_n133_;
  assign new_n135_ = G43gat & ~G53gat;
  assign new_n136_ = ~new_n78_ & new_n135_;
  assign new_n137_ = ~new_n134_ & new_n136_;
  assign new_n138_ = ~new_n85_ & ~G329gat;
  assign new_n139_ = new_n85_ & G329gat;
  assign new_n140_ = ~new_n138_ & ~new_n139_;
  assign new_n141_ = G56gat & ~G66gat;
  assign new_n142_ = ~new_n83_ & new_n141_;
  assign new_n143_ = ~new_n140_ & new_n142_;
  assign new_n144_ = ~new_n90_ & ~G329gat;
  assign new_n145_ = new_n90_ & G329gat;
  assign new_n146_ = ~new_n144_ & ~new_n145_;
  assign new_n147_ = G69gat & ~G79gat;
  assign new_n148_ = ~new_n88_ & new_n147_;
  assign new_n149_ = ~new_n146_ & new_n148_;
  assign new_n150_ = ~new_n95_ & ~G329gat;
  assign new_n151_ = new_n95_ & G329gat;
  assign new_n152_ = ~new_n150_ & ~new_n151_;
  assign new_n153_ = G82gat & ~G92gat;
  assign new_n154_ = ~new_n93_ & new_n153_;
  assign new_n155_ = ~new_n152_ & new_n154_;
  assign new_n156_ = ~new_n100_ & ~G329gat;
  assign new_n157_ = new_n100_ & G329gat;
  assign new_n158_ = ~new_n156_ & ~new_n157_;
  assign new_n159_ = G95gat & ~G105gat;
  assign new_n160_ = ~new_n98_ & new_n159_;
  assign new_n161_ = ~new_n158_ & new_n160_;
  assign new_n162_ = ~new_n105_ & ~G329gat;
  assign new_n163_ = new_n105_ & G329gat;
  assign new_n164_ = ~new_n162_ & ~new_n163_;
  assign new_n165_ = G108gat & ~G115gat;
  assign new_n166_ = ~new_n103_ & new_n165_;
  assign new_n167_ = ~new_n164_ & new_n166_;
  assign new_n168_ = ~new_n119_ & ~new_n125_;
  assign new_n169_ = ~new_n131_ & new_n168_;
  assign new_n170_ = ~new_n137_ & new_n169_;
  assign new_n171_ = ~new_n143_ & new_n170_;
  assign new_n172_ = ~new_n149_ & new_n171_;
  assign new_n173_ = ~new_n155_ & new_n172_;
  assign new_n174_ = ~new_n161_ & new_n173_;
  assign G370gat = new_n167_ | ~new_n174_;
  assign new_n176_ = G1gat & G223gat;
  assign new_n177_ = G8gat & G329gat;
  assign new_n178_ = G14gat & G370gat;
  assign new_n179_ = ~new_n177_ & ~new_n178_;
  assign new_n180_ = G4gat & ~new_n176_;
  assign new_n181_ = new_n179_ & new_n180_;
  assign new_n182_ = G11gat & G223gat;
  assign new_n183_ = G21gat & G329gat;
  assign new_n184_ = G27gat & G370gat;
  assign new_n185_ = G17gat & ~new_n184_;
  assign new_n186_ = ~new_n182_ & ~new_n183_;
  assign new_n187_ = new_n185_ & new_n186_;
  assign new_n188_ = G24gat & G223gat;
  assign new_n189_ = G34gat & G329gat;
  assign new_n190_ = G40gat & G370gat;
  assign new_n191_ = G30gat & ~new_n190_;
  assign new_n192_ = ~new_n188_ & ~new_n189_;
  assign new_n193_ = new_n191_ & new_n192_;
  assign new_n194_ = G37gat & G223gat;
  assign new_n195_ = G47gat & G329gat;
  assign new_n196_ = G53gat & G370gat;
  assign new_n197_ = G43gat & ~new_n196_;
  assign new_n198_ = ~new_n194_ & ~new_n195_;
  assign new_n199_ = new_n197_ & new_n198_;
  assign new_n200_ = G50gat & G223gat;
  assign new_n201_ = G60gat & G329gat;
  assign new_n202_ = G66gat & G370gat;
  assign new_n203_ = G56gat & ~new_n202_;
  assign new_n204_ = ~new_n200_ & ~new_n201_;
  assign new_n205_ = new_n203_ & new_n204_;
  assign new_n206_ = G63gat & G223gat;
  assign new_n207_ = G73gat & G329gat;
  assign new_n208_ = G79gat & G370gat;
  assign new_n209_ = G69gat & ~new_n208_;
  assign new_n210_ = ~new_n206_ & ~new_n207_;
  assign new_n211_ = new_n209_ & new_n210_;
  assign new_n212_ = G76gat & G223gat;
  assign new_n213_ = G86gat & G329gat;
  assign new_n214_ = G92gat & G370gat;
  assign new_n215_ = G82gat & ~new_n214_;
  assign new_n216_ = ~new_n212_ & ~new_n213_;
  assign new_n217_ = new_n215_ & new_n216_;
  assign new_n218_ = G89gat & G223gat;
  assign new_n219_ = G99gat & G329gat;
  assign new_n220_ = G105gat & G370gat;
  assign new_n221_ = G95gat & ~new_n220_;
  assign new_n222_ = ~new_n218_ & ~new_n219_;
  assign new_n223_ = new_n221_ & new_n222_;
  assign new_n224_ = G102gat & G223gat;
  assign new_n225_ = G112gat & G329gat;
  assign new_n226_ = G115gat & G370gat;
  assign new_n227_ = G108gat & ~new_n226_;
  assign new_n228_ = ~new_n224_ & ~new_n225_;
  assign new_n229_ = new_n227_ & new_n228_;
  assign new_n230_ = ~new_n187_ & ~new_n193_;
  assign new_n231_ = ~new_n199_ & new_n230_;
  assign new_n232_ = ~new_n205_ & new_n231_;
  assign new_n233_ = ~new_n211_ & new_n232_;
  assign new_n234_ = ~new_n217_ & new_n233_;
  assign new_n235_ = ~new_n223_ & new_n234_;
  assign new_n236_ = ~new_n229_ & new_n235_;
  assign G421gat = ~new_n181_ & ~new_n236_;
  assign new_n238_ = ~new_n193_ & new_n199_;
  assign new_n239_ = ~new_n205_ & ~new_n238_;
  assign G430gat = ~new_n230_ | ~new_n239_;
  assign new_n241_ = ~new_n205_ & new_n211_;
  assign new_n242_ = ~new_n193_ & ~new_n199_;
  assign new_n243_ = new_n241_ & new_n242_;
  assign new_n244_ = ~new_n199_ & ~new_n205_;
  assign new_n245_ = new_n217_ & new_n244_;
  assign new_n246_ = ~new_n243_ & ~new_n245_;
  assign G431gat = ~new_n230_ | ~new_n246_;
  assign new_n248_ = ~new_n217_ & new_n223_;
  assign new_n249_ = new_n242_ & new_n248_;
  assign new_n250_ = ~new_n243_ & ~new_n249_;
  assign new_n251_ = ~new_n187_ & ~new_n238_;
  assign G432gat = ~new_n250_ | ~new_n251_;
endmodule


