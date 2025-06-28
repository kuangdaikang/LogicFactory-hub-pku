// Benchmark "int2float" written by ABC on Fri Sep  1 14:05:03 2023

module int2float ( 
    \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] , \B[8] ,
    \B[9] , \B[10] ,
    \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2]   );
  input  \B[0] , \B[1] , \B[2] , \B[3] , \B[4] , \B[5] , \B[6] , \B[7] ,
    \B[8] , \B[9] , \B[10] ;
  output \M[0] , \M[1] , \M[2] , \M[3] , \E[0] , \E[1] , \E[2] ;
  wire new_new_n21__, new_new_n28__, new_new_n33__, new_new_n25__,
    new_new_n22__, new_new_n23__, new_new_n24__, new_new_n26__,
    new_new_n27__, new_new_n29__, new_new_n32__, new_new_n30__,
    new_new_n31__, new_new_n34__, new_new_n36__, new_new_n35__,
    new_new_n53__, new_new_n61__, new_new_n38__, new_new_n39__,
    new_new_n44__, new_new_n43__, new_new_n40__, new_new_n41__,
    new_new_n42__, new_new_n52__, new_new_n45__, new_new_n46__,
    new_new_n48__, new_new_n50__, new_new_n47__, new_new_n49__,
    new_new_n51__, new_new_n54__, new_new_n55__, new_new_n58__,
    new_new_n59__, new_new_n56__, new_new_n57__, new_new_n60__,
    new_new_n62__, new_new_n78__, new_new_n64__, new_new_n80__,
    new_new_n65__, new_new_n76__, new_new_n71__, new_new_n66__,
    new_new_n73__, new_new_n67__, new_new_n69__, new_new_n68__,
    new_new_n70__, new_new_n72__, new_new_n75__, new_new_n74__,
    new_new_n77__, new_new_n79__, new_new_n82__, new_new_n81__,
    new_new_n84__, new_new_n85__, new_new_n86__, new_new_n88__,
    new_new_n95__, new_new_n93__, new_new_n89__, new_new_n90__,
    new_new_n91__, new_new_n92__, new_new_n94__, new_new_n96__,
    new_new_n97__, new_new_n104__, new_new_n99__, new_new_n102__,
    new_new_n100__, new_new_n101__, new_new_n103__, new_new_n105__,
    new_new_n107__, new_n_99_, new_n_100_, new_n_101_, new_n_102_,
    new_n_103_, new_n_104_, new_n_105_, new_n_106_, new_n_107_, new_n_108_,
    new_n_109_, new_n_110_, new_n_111_, new_n_112_, new_n_113_, new_n_114_,
    new_n_115_, new_n_116_, new_n_117_, new_n_118_, new_n_119_, new_n_120_,
    new_n_121_, new_n_122_, new_n_123_, new_n_124_, new_n_125_, new_n_126_,
    new_n_127_, new_n_128_, new_n_129_, new_n_130_, new_n_131_, new_n_132_,
    new_n_133_, new_n_134_, new_n_135_, new_n_136_, new_n_137_, new_n_138_,
    new_n_139_, new_n_140_, new_n_141_, new_n_142_, new_n_143_, new_n_144_,
    new_n_145_, new_n_146_, new_n_147_, new_n_148_, new_n_149_, new_n_150_,
    new_n_151_, new_n_152_, new_n_153_, new_n_154_, new_n_155_, new_n_156_,
    new_n_157_, new_n_158_, new_n_159_, new_n_160_, new_n_161_, new_n_162_,
    new_n_163_, new_n_164_, new_n_165_, new_n_166_, new_n_167_, new_n_168_,
    new_n_169_, new_n_170_, new_n_171_, new_n_172_, new_n_173_, new_n_174_,
    new_n_175_, new_n_176_, new_n_177_, new_n_178_, new_n_179_, new_n_180_,
    new_n_181_, new_n_182_, new_n_183_, new_n_184_, new_n_185_, new_n_186_,
    new_n_187_, new_n_188_, new_n_189_, new_n_190_, new_n_191_, new_n_192_,
    new_n_193_, new_n_194_, new_n_195_, new_n_196_, new_n_197_, new_n_198_,
    new_n_199_, new_n_200_, new_n_201_, new_n_202_, new_n_203_, new_n_204_,
    new_n_205_, new_n_206_, new_n_207_, new_n_208_, new_n_209_, new_n_210_,
    new_n_211_, new_n_212_, new_n_213_, new_n_214_, new_n_215_, new_n_216_,
    new_n_217_, new_n_218_, new_n_219_, new_n_220_, new_n_221_, new_n_222_,
    new_n_223_, new_n_224_, new_n_225_, new_n_226_, new_n_227_, new_n_228_,
    new_n_229_, new_n_230_, new_n_231_, new_n_232_, new_n_233_, new_n_234_,
    new_n_235_, new_n_236_, new_n_237_, new_n_238_, new_n_239_, new_n_240_,
    new_n_241_, new_n_242_, new_n_243_, new_n_244_, new_n_245_, new_n_246_,
    new_n_247_, new_n_248_, new_n_249_, new_n_250_, new_n_251_, new_n_252_,
    new_n_253_, new_n_254_, new_n_255_, new_n_256_, new_n_257_;
  assign \M[0]  = new_new_n33__ & new_n_100_;
  assign \M[1]  = ~new_n_101_ & new_n_102_;
  assign \M[2]  = ~new_new_n80__ & new_n_104_;
  assign \M[3]  = \B[9]  | new_n_106_;
  assign \E[0]  = \B[10]  | new_n_108_;
  assign \E[1]  = ~new_new_n102__ & new_n_110_;
  assign \E[2]  = ~new_new_n107__ & new_n_112_;
  assign new_new_n21__ = \B[9]  | new_n_114_;
  assign new_new_n28__ = ~new_n_117_ & new_n_118_;
  assign new_new_n33__ = new_n_120_ ^ new_n_121_;
  assign new_new_n25__ = new_n_122_ | new_n_123_;
  assign new_new_n22__ = ~new_n_125_ & new_n_126_;
  assign new_new_n23__ = new_n_128_ | new_n_129_;
  assign new_new_n24__ = new_n_130_ & new_n_131_;
  assign new_new_n26__ = new_n_132_ ^ new_n_134_;
  assign new_new_n27__ = ~\B[6]  & ~\B[7] ;
  assign new_new_n29__ = ~new_new_n30__ & new_n_136_;
  assign new_new_n32__ = \B[7]  ^ new_n_139_;
  assign new_new_n30__ = \B[9]  | new_n_141_;
  assign new_new_n31__ = ~\B[7]  & ~\B[8] ;
  assign new_new_n34__ = new_n_143_ | new_n_144_;
  assign new_new_n36__ = \B[8]  & \B[9] ;
  assign new_new_n35__ = ~new_n_145_ & new_n_146_;
  assign new_new_n53__ = ~new_n_147_ & new_n_148_;
  assign new_new_n61__ = \B[8]  & new_n_150_;
  assign new_new_n38__ = \B[10]  | new_n_152_;
  assign new_new_n39__ = new_n_153_ | new_n_154_;
  assign new_new_n44__ = new_n_155_ & new_n_156_;
  assign new_new_n43__ = new_n_158_ ^ new_n_159_;
  assign new_new_n40__ = new_new_n42__ | new_n_161_;
  assign new_new_n41__ = new_n_163_ ^ new_n_164_;
  assign new_new_n42__ = new_n_165_ & new_n_166_;
  assign new_new_n52__ = new_n_168_ ^ new_n_169_;
  assign new_new_n45__ = new_new_n50__ & new_n_171_;
  assign new_new_n46__ = ~new_n_173_ & new_n_174_;
  assign new_new_n48__ = ~new_n_175_ & new_n_176_;
  assign new_new_n50__ = ~new_n_178_ & new_n_179_;
  assign new_new_n47__ = ~\B[7]  & \B[4] ;
  assign new_new_n49__ = new_n_180_ & new_n_181_;
  assign new_new_n51__ = \B[3]  & \B[4] ;
  assign new_new_n54__ = new_new_n59__ | new_n_183_;
  assign new_new_n55__ = ~\B[3]  & new_n_185_;
  assign new_new_n58__ = ~\B[2]  & new_n_187_;
  assign new_new_n59__ = \B[4]  & new_n_189_;
  assign new_new_n56__ = ~\B[6]  & \B[5] ;
  assign new_new_n57__ = \B[6]  & ~\B[4]  & ~\B[9] ;
  assign new_new_n60__ = \B[2]  & \B[3] ;
  assign new_new_n62__ = \B[6]  & \B[7] ;
  assign new_new_n78__ = ~new_new_n79__ & \B[8] ;
  assign new_new_n64__ = \B[9]  | new_n_191_;
  assign new_new_n80__ = new_n_192_ | new_n_193_;
  assign new_new_n65__ = ~new_new_n73__ & new_n_195_;
  assign new_new_n76__ = new_new_n62__ ^ new_n_198_;
  assign new_new_n71__ = ~new_new_n72__ & \B[4] ;
  assign new_new_n66__ = \B[2]  & new_n_200_;
  assign new_new_n73__ = new_new_n51__ ? new_new_n74__ : ~new_new_n75__;
  assign new_new_n67__ = new_new_n68__ | new_n_202_;
  assign new_new_n69__ = \B[5]  | new_n_204_;
  assign new_new_n68__ = new_n_205_ & new_n_206_;
  assign new_new_n70__ = ~new_n_207_ & new_n_208_;
  assign new_new_n72__ = new_n_210_ ^ new_n_211_;
  assign new_new_n75__ = \B[5]  & \B[6] ;
  assign new_new_n74__ = ~new_n_214_ & new_n_215_;
  assign new_new_n77__ = ~new_n_218_ & new_n_219_;
  assign new_new_n79__ = new_n_221_ & new_n_222_;
  assign new_new_n82__ = \B[10]  | new_n_224_;
  assign new_new_n81__ = new_n_226_ ^ new_n_227_;
  assign new_new_n84__ = new_new_n86__ | new_n_229_;
  assign new_new_n85__ = \B[5]  & ~\B[2]  & new_new_n62__;
  assign new_new_n86__ = ~\B[4]  & new_n_231_;
  assign new_new_n88__ = new_new_n89__ & (~new_new_n60__ | new_new_n93__);
  assign new_new_n95__ = new_new_n96__ | new_n_233_;
  assign new_new_n93__ = new_n_235_ ^ new_n_237_;
  assign new_new_n89__ = ~new_new_n90__ & new_n_239_;
  assign new_new_n90__ = ~new_new_n91__ & new_n_241_;
  assign new_new_n91__ = new_new_n56__ & (~\B[2]  | ~\B[1] );
  assign new_new_n92__ = ~\B[9]  & new_n_243_;
  assign new_new_n94__ = \B[0]  & \B[1] ;
  assign new_new_n96__ = new_new_n97__ & new_n_246_;
  assign new_new_n97__ = \B[4]  & new_n_248_;
  assign new_new_n104__ = \B[7]  & new_new_n105__ & \B[5] ;
  assign new_new_n99__ = \B[2]  & new_n_250_;
  assign new_new_n102__ = \B[9]  | new_n_252_;
  assign new_new_n100__ = new_new_n31__ & ~\B[5]  & \B[3] ;
  assign new_new_n101__ = \B[8]  & new_n_254_;
  assign new_new_n103__ = new_n_256_ | new_n_257_;
  assign new_new_n105__ = \B[8]  & \B[3]  & \B[6] ;
  assign new_new_n107__ = new_new_n31__ & ~\B[9]  & ~\B[10] ;
  assign new_n_99_ = ~new_new_n21__ & new_new_n28__;
  assign new_n_100_ = \B[10]  | new_n_99_;
  assign new_n_101_ = \B[8]  | new_new_n53__;
  assign new_n_102_ = new_new_n61__ | new_new_n38__;
  assign new_n_103_ = new_new_n78__ | new_new_n64__;
  assign new_n_104_ = ~\B[10]  & new_n_103_;
  assign new_n_105_ = new_new_n84__ | \B[3] ;
  assign new_n_106_ = \B[10]  | new_n_105_;
  assign new_n_107_ = new_new_n88__ | \B[8] ;
  assign new_n_108_ = new_new_n95__ & new_n_107_;
  assign new_n_109_ = new_new_n104__ | new_new_n99__;
  assign new_n_110_ = \B[4]  & new_n_109_;
  assign new_n_111_ = new_new_n51__ & new_new_n75__;
  assign new_n_112_ = \B[2]  & new_n_111_;
  assign new_n_113_ = new_new_n25__ | \B[5] ;
  assign new_n_114_ = new_new_n22__ & new_n_113_;
  assign new_n_115_ = \B[5]  ^ \B[6] ;
  assign new_n_116_ = ~\B[9]  & \B[6] ;
  assign new_n_117_ = ~new_n_115_ & new_n_116_;
  assign new_n_118_ = new_new_n29__ & \B[5] ;
  assign new_n_119_ = \B[7]  & \B[10] ;
  assign new_n_120_ = \B[6]  | new_n_119_;
  assign new_n_121_ = new_new_n34__ & \B[6] ;
  assign new_n_122_ = \B[4]  & \B[8] ;
  assign new_n_123_ = ~new_new_n26__ & new_new_n27__;
  assign new_n_124_ = ~\B[4]  & \B[5] ;
  assign new_n_125_ = new_new_n23__ | \B[8] ;
  assign new_n_126_ = \B[8]  & new_n_124_;
  assign new_n_127_ = \B[4]  ^ \B[3] ;
  assign new_n_128_ = \B[7]  & new_n_127_;
  assign new_n_129_ = new_new_n24__ & \B[3] ;
  assign new_n_130_ = ~\B[7]  & \B[1] ;
  assign new_n_131_ = ~\B[2]  & \B[5] ;
  assign new_n_132_ = \B[1]  & \B[4] ;
  assign new_n_133_ = ~\B[8]  & \B[4] ;
  assign new_n_134_ = ~\B[0]  & new_n_133_;
  assign new_n_135_ = new_new_n32__ | \B[2] ;
  assign new_n_136_ = ~\B[1]  & new_n_135_;
  assign new_n_137_ = \B[3]  | \B[8] ;
  assign new_n_138_ = \B[7]  ^ new_n_137_;
  assign new_n_139_ = \B[4]  & new_n_138_;
  assign new_n_140_ = ~\B[1]  & \B[2] ;
  assign new_n_141_ = new_new_n31__ & new_n_140_;
  assign new_n_142_ = new_new_n35__ | \B[10] ;
  assign new_n_143_ = ~\B[7]  & new_n_142_;
  assign new_n_144_ = new_new_n36__ & \B[10] ;
  assign new_n_145_ = \B[8]  | \B[9] ;
  assign new_n_146_ = \B[2]  ^ \B[3] ;
  assign new_n_147_ = ~\B[6]  & \B[10] ;
  assign new_n_148_ = new_new_n54__ | \B[7] ;
  assign new_n_149_ = ~\B[9]  & \B[10] ;
  assign new_n_150_ = new_new_n62__ & new_n_149_;
  assign new_n_151_ = ~new_new_n39__ & \B[5] ;
  assign new_n_152_ = ~new_new_n44__ & new_n_151_;
  assign new_n_153_ = ~new_new_n43__ & \B[6] ;
  assign new_n_154_ = ~new_new_n40__ & \B[3] ;
  assign new_n_155_ = new_new_n45__ | \B[5] ;
  assign new_n_156_ = new_new_n52__ | \B[6] ;
  assign new_n_157_ = \B[4]  & \B[8] ;
  assign new_n_158_ = ~\B[9]  & new_n_157_;
  assign new_n_159_ = \B[7]  & \B[9] ;
  assign new_n_160_ = ~new_new_n41__ & \B[1] ;
  assign new_n_161_ = \B[2]  & new_n_160_;
  assign new_n_162_ = \B[8]  | \B[9] ;
  assign new_n_163_ = new_new_n27__ | \B[4] ;
  assign new_n_164_ = \B[4]  & new_n_162_;
  assign new_n_165_ = ~\B[9]  & \B[7] ;
  assign new_n_166_ = ~\B[8]  & \B[4] ;
  assign new_n_167_ = ~\B[4]  & \B[8] ;
  assign new_n_168_ = ~\B[9]  & new_n_167_;
  assign new_n_169_ = ~\B[7]  & \B[9] ;
  assign new_n_170_ = ~new_new_n46__ & new_new_n48__;
  assign new_n_171_ = \B[6]  | new_n_170_;
  assign new_n_172_ = ~\B[1]  & \B[0] ;
  assign new_n_173_ = ~new_new_n47__ & new_n_172_;
  assign new_n_174_ = \B[0]  ^ \B[2] ;
  assign new_n_175_ = ~\B[9]  & \B[8] ;
  assign new_n_176_ = new_new_n49__ | \B[1] ;
  assign new_n_177_ = new_new_n51__ | \B[8] ;
  assign new_n_178_ = \B[9]  ^ \B[7] ;
  assign new_n_179_ = ~\B[9]  & new_n_177_;
  assign new_n_180_ = \B[2]  | \B[7] ;
  assign new_n_181_ = \B[4]  | \B[9] ;
  assign new_n_182_ = new_new_n55__ | new_new_n58__;
  assign new_n_183_ = \B[10]  | new_n_182_;
  assign new_n_184_ = ~\B[1]  & new_new_n56__;
  assign new_n_185_ = new_new_n57__ | new_n_184_;
  assign new_n_186_ = ~\B[3]  & new_new_n56__;
  assign new_n_187_ = new_new_n57__ | new_n_186_;
  assign new_n_188_ = ~\B[9]  & new_new_n60__;
  assign new_n_189_ = \B[6]  & new_n_188_;
  assign new_n_190_ = new_new_n65__ | \B[8] ;
  assign new_n_191_ = new_new_n76__ & new_n_190_;
  assign new_n_192_ = ~new_new_n82__ & \B[9] ;
  assign new_n_193_ = ~new_new_n81__ & new_new_n62__;
  assign new_n_194_ = new_new_n71__ | new_new_n66__;
  assign new_n_195_ = ~\B[7]  & new_n_194_;
  assign new_n_196_ = new_new_n77__ ^ new_new_n62__;
  assign new_n_197_ = ~\B[5]  & new_n_196_;
  assign new_n_198_ = \B[4]  & new_n_197_;
  assign new_n_199_ = ~new_new_n67__ & \B[1] ;
  assign new_n_200_ = new_new_n69__ | new_n_199_;
  assign new_n_201_ = ~\B[4]  & \B[3] ;
  assign new_n_202_ = \B[5]  & new_n_201_;
  assign new_n_203_ = \B[4]  | \B[6] ;
  assign new_n_204_ = ~new_new_n70__ & new_n_203_;
  assign new_n_205_ = ~\B[6]  & \B[0] ;
  assign new_n_206_ = ~\B[3]  & \B[4] ;
  assign new_n_207_ = \B[1]  & \B[0] ;
  assign new_n_208_ = \B[3]  & \B[4] ;
  assign new_n_209_ = \B[2]  | \B[6] ;
  assign new_n_210_ = \B[5]  | \B[3] ;
  assign new_n_211_ = \B[3]  & new_n_209_;
  assign new_n_212_ = \B[5]  ^ \B[6] ;
  assign new_n_213_ = ~\B[2]  & \B[6] ;
  assign new_n_214_ = ~new_n_212_ & new_n_213_;
  assign new_n_215_ = \B[1]  & \B[5] ;
  assign new_n_216_ = \B[6]  ^ \B[7] ;
  assign new_n_217_ = ~\B[3]  & \B[7] ;
  assign new_n_218_ = ~new_n_216_ & new_n_217_;
  assign new_n_219_ = \B[2]  & \B[6] ;
  assign new_n_220_ = \B[4]  & \B[5] ;
  assign new_n_221_ = \B[7]  | new_n_220_;
  assign new_n_222_ = \B[7]  ^ \B[6] ;
  assign new_n_223_ = \B[7]  & \B[5] ;
  assign new_n_224_ = ~\B[8]  & new_n_223_;
  assign new_n_225_ = \B[9]  & \B[5] ;
  assign new_n_226_ = ~\B[8]  & new_n_225_;
  assign new_n_227_ = \B[10]  & \B[8] ;
  assign new_n_228_ = new_new_n85__ & \B[4] ;
  assign new_n_229_ = \B[8]  & new_n_228_;
  assign new_n_230_ = ~\B[8]  & new_new_n27__;
  assign new_n_231_ = ~\B[5]  & new_n_230_;
  assign new_n_232_ = new_new_n75__ & \B[7] ;
  assign new_n_233_ = ~\B[9]  & new_n_232_;
  assign new_n_234_ = new_new_n94__ | \B[6] ;
  assign new_n_235_ = ~\B[5]  & new_n_234_;
  assign new_n_236_ = ~new_new_n47__ & \B[5] ;
  assign new_n_237_ = ~\B[6]  & new_n_236_;
  assign new_n_238_ = new_new_n56__ | \B[7] ;
  assign new_n_239_ = ~\B[3]  & new_n_238_;
  assign new_n_240_ = ~\B[7]  & new_new_n75__;
  assign new_n_241_ = ~new_new_n92__ & new_n_240_;
  assign new_n_242_ = ~\B[7]  & \B[6] ;
  assign new_n_243_ = \B[4]  | new_n_242_;
  assign new_n_244_ = ~\B[2]  & \B[3] ;
  assign new_n_245_ = \B[8]  & \B[3] ;
  assign new_n_246_ = new_n_244_ | new_n_245_;
  assign new_n_247_ = ~\B[9]  & new_new_n62__;
  assign new_n_248_ = \B[5]  & new_n_247_;
  assign new_n_249_ = new_new_n94__ & new_new_n100__;
  assign new_n_250_ = new_new_n101__ | new_n_249_;
  assign new_n_251_ = ~new_new_n31__ & new_new_n103__;
  assign new_n_252_ = \B[10]  | new_n_251_;
  assign new_n_253_ = \B[5]  & \B[6] ;
  assign new_n_254_ = \B[7]  & new_n_253_;
  assign new_n_255_ = new_new_n60__ & \B[4] ;
  assign new_n_256_ = \B[5]  ^ \B[6] ;
  assign new_n_257_ = ~\B[6]  & new_n_255_;
endmodule


