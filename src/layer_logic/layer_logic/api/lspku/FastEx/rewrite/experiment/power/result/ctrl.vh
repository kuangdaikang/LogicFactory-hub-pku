// Benchmark "ctrl" written by ABC on Thu Sep 14 22:39:52 2023

module ctrl ( 
    \opcode[0] , \opcode[1] , \opcode[2] , \opcode[3] , \opcode[4] ,
    \op_ext[0] , \op_ext[1] ,
    \sel_reg_dst[0] , \sel_reg_dst[1] , \sel_alu_opB[0] , \sel_alu_opB[1] ,
    \alu_op[0] , \alu_op[1] , \alu_op[2] , \alu_op_ext[0] ,
    \alu_op_ext[1] , \alu_op_ext[2] , \alu_op_ext[3] , halt, reg_write,
    sel_pc_opA, sel_pc_opB, beqz, bnez, bgez, bltz, jump, Cin, invA, invB,
    sign, mem_write, sel_wb  );
  input  \opcode[0] , \opcode[1] , \opcode[2] , \opcode[3] , \opcode[4] ,
    \op_ext[0] , \op_ext[1] ;
  output \sel_reg_dst[0] , \sel_reg_dst[1] , \sel_alu_opB[0] ,
    \sel_alu_opB[1] , \alu_op[0] , \alu_op[1] , \alu_op[2] ,
    \alu_op_ext[0] , \alu_op_ext[1] , \alu_op_ext[2] , \alu_op_ext[3] ,
    halt, reg_write, sel_pc_opA, sel_pc_opB, beqz, bnez, bgez, bltz, jump,
    Cin, invA, invB, sign, mem_write, sel_wb;
  wire new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_, new_n40_,
    new_n41_, new_n42_, new_n44_, new_n45_, new_n46_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n64_, new_n65_,
    new_n66_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n73_,
    new_n74_, new_n75_, new_n76_, new_n78_, new_n79_, new_n80_, new_n81_,
    new_n82_, new_n83_, new_n84_, new_n85_, new_n86_, new_n87_, new_n88_,
    new_n89_, new_n90_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_,
    new_n97_, new_n99_, new_n100_, new_n101_, new_n102_, new_n103_,
    new_n105_, new_n106_, new_n108_, new_n109_, new_n110_, new_n111_,
    new_n112_, new_n113_, new_n116_, new_n117_, new_n118_, new_n120_,
    new_n123_, new_n126_, new_n127_, new_n128_, new_n129_, new_n130_,
    new_n132_, new_n133_, new_n134_, new_n135_, new_n137_, new_n140_,
    new_n141_;
  INV_X1     g000(.I(\opcode[3] ), .ZN(new_n34_));
  INV_X1     g001(.I(\opcode[4] ), .ZN(new_n35_));
  NAND2_X1   g002(.A1(\opcode[0] ), .A2(\opcode[1] ), .ZN(new_n36_));
  AOI21_X1   g003(.A1(new_n34_), .A2(new_n35_), .B(new_n36_), .ZN(new_n37_));
  INV_X1     g004(.I(\opcode[1] ), .ZN(new_n38_));
  NAND2_X1   g005(.A1(new_n34_), .A2(new_n35_), .ZN(new_n39_));
  NAND2_X1   g006(.A1(\opcode[3] ), .A2(\opcode[4] ), .ZN(new_n40_));
  OAI21_X1   g007(.A1(new_n39_), .A2(new_n38_), .B(new_n40_), .ZN(new_n41_));
  NAND2_X1   g008(.A1(new_n41_), .A2(\opcode[2] ), .ZN(new_n42_));
  OAI21_X1   g009(.A1(\opcode[2] ), .A2(new_n37_), .B(new_n42_), .ZN(\sel_reg_dst[0] ));
  NAND2_X1   g010(.A1(new_n39_), .A2(\opcode[2] ), .ZN(new_n44_));
  NOR2_X1    g011(.A1(new_n34_), .A2(\opcode[0] ), .ZN(new_n45_));
  NAND4_X1   g012(.A1(new_n34_), .A2(\opcode[1] ), .A3(\opcode[2] ), .A4(\opcode[4] ), .ZN(new_n46_));
  XOR2_X1    g013(.A1(new_n44_), .A2(new_n46_), .Z(\sel_reg_dst[1] ));
  INV_X1     g014(.I(\opcode[0] ), .ZN(new_n48_));
  NAND3_X1   g015(.A1(new_n48_), .A2(new_n38_), .A3(\opcode[4] ), .ZN(new_n49_));
  XOR2_X1    g016(.A1(\opcode[0] ), .A2(\opcode[1] ), .Z(new_n50_));
  NAND2_X1   g017(.A1(new_n38_), .A2(\opcode[4] ), .ZN(new_n51_));
  NAND2_X1   g018(.A1(new_n50_), .A2(new_n51_), .ZN(new_n52_));
  INV_X1     g019(.I(\opcode[2] ), .ZN(new_n53_));
  INV_X1     g020(.I(new_n40_), .ZN(new_n54_));
  INV_X1     g021(.I(new_n51_), .ZN(new_n55_));
  OAI21_X1   g022(.A1(new_n55_), .A2(new_n54_), .B(new_n53_), .ZN(new_n56_));
  AOI21_X1   g023(.A1(new_n52_), .A2(new_n49_), .B(new_n56_), .ZN(\sel_alu_opB[0] ));
  NAND2_X1   g024(.A1(new_n34_), .A2(\opcode[4] ), .ZN(new_n58_));
  NOR2_X1    g025(.A1(new_n38_), .A2(new_n34_), .ZN(new_n59_));
  NOR3_X1    g026(.A1(new_n59_), .A2(new_n45_), .A3(new_n51_), .ZN(new_n60_));
  NOR2_X1    g027(.A1(new_n38_), .A2(new_n34_), .ZN(new_n61_));
  OAI21_X1   g028(.A1(new_n60_), .A2(new_n61_), .B(new_n53_), .ZN(new_n62_));
  OAI21_X1   g029(.A1(new_n53_), .A2(new_n58_), .B(new_n62_), .ZN(\sel_alu_opB[1] ));
  NAND2_X1   g030(.A1(new_n58_), .A2(\opcode[2] ), .ZN(new_n64_));
  NAND3_X1   g031(.A1(\opcode[3] ), .A2(\opcode[4] ), .A3(\op_ext[0] ), .ZN(new_n65_));
  OAI21_X1   g032(.A1(new_n65_), .A2(new_n36_), .B(new_n48_), .ZN(new_n66_));
  INV_X1     g033(.I(\op_ext[0] ), .ZN(new_n67_));
  INV_X1     g034(.I(\op_ext[1] ), .ZN(new_n68_));
  AOI21_X1   g035(.A1(new_n40_), .A2(new_n68_), .B(new_n67_), .ZN(new_n69_));
  NOR2_X1    g036(.A1(new_n48_), .A2(new_n53_), .ZN(new_n70_));
  NAND3_X1   g037(.A1(new_n66_), .A2(new_n69_), .A3(new_n70_), .ZN(new_n71_));
  XOR2_X1    g038(.A1(new_n71_), .A2(new_n64_), .Z(\alu_op[0] ));
  NAND2_X1   g039(.A1(new_n68_), .A2(\opcode[4] ), .ZN(new_n73_));
  NOR2_X1    g040(.A1(new_n35_), .A2(\opcode[3] ), .ZN(new_n74_));
  NAND3_X1   g041(.A1(new_n74_), .A2(\opcode[1] ), .A3(\opcode[2] ), .ZN(new_n75_));
  NAND3_X1   g042(.A1(new_n58_), .A2(\opcode[1] ), .A3(new_n53_), .ZN(new_n76_));
  AOI22_X1   g043(.A1(new_n75_), .A2(new_n76_), .B1(\opcode[3] ), .B2(new_n73_), .ZN(\alu_op[1] ));
  NOR2_X1    g044(.A1(new_n53_), .A2(\opcode[3] ), .ZN(new_n78_));
  INV_X1     g045(.I(new_n78_), .ZN(new_n79_));
  NOR3_X1    g046(.A1(new_n35_), .A2(\opcode[0] ), .A3(\opcode[3] ), .ZN(new_n80_));
  OAI21_X1   g047(.A1(new_n80_), .A2(\opcode[1] ), .B(new_n48_), .ZN(new_n81_));
  NOR2_X1    g048(.A1(new_n48_), .A2(\opcode[1] ), .ZN(new_n82_));
  INV_X1     g049(.I(new_n82_), .ZN(new_n83_));
  NAND2_X1   g050(.A1(new_n81_), .A2(new_n83_), .ZN(new_n84_));
  NOR2_X1    g051(.A1(new_n53_), .A2(new_n35_), .ZN(new_n85_));
  NAND3_X1   g052(.A1(new_n84_), .A2(new_n79_), .A3(new_n85_), .ZN(new_n86_));
  NAND3_X1   g053(.A1(new_n48_), .A2(new_n34_), .A3(\opcode[4] ), .ZN(new_n87_));
  AOI21_X1   g054(.A1(new_n87_), .A2(new_n38_), .B(\opcode[0] ), .ZN(new_n88_));
  OAI21_X1   g055(.A1(new_n88_), .A2(new_n82_), .B(new_n85_), .ZN(new_n89_));
  NAND2_X1   g056(.A1(new_n89_), .A2(new_n78_), .ZN(new_n90_));
  NAND2_X1   g057(.A1(new_n90_), .A2(new_n86_), .ZN(\alu_op[2] ));
  NOR2_X1    g058(.A1(new_n53_), .A2(\opcode[1] ), .ZN(new_n92_));
  NAND2_X1   g059(.A1(\opcode[0] ), .A2(\opcode[3] ), .ZN(new_n93_));
  NAND4_X1   g060(.A1(new_n93_), .A2(new_n38_), .A3(new_n34_), .A4(\opcode[4] ), .ZN(new_n94_));
  NAND3_X1   g061(.A1(\opcode[0] ), .A2(\opcode[3] ), .A3(\opcode[4] ), .ZN(new_n95_));
  NAND4_X1   g062(.A1(new_n48_), .A2(\opcode[2] ), .A3(\opcode[3] ), .A4(\opcode[4] ), .ZN(new_n96_));
  AOI21_X1   g063(.A1(new_n94_), .A2(new_n95_), .B(new_n96_), .ZN(new_n97_));
  XOR2_X1    g064(.A1(new_n97_), .A2(new_n92_), .Z(\alu_op_ext[0] ));
  NOR2_X1    g065(.A1(new_n34_), .A2(\opcode[4] ), .ZN(new_n99_));
  NOR2_X1    g066(.A1(new_n74_), .A2(new_n99_), .ZN(new_n100_));
  NAND4_X1   g067(.A1(new_n74_), .A2(new_n48_), .A3(\opcode[1] ), .A4(\opcode[2] ), .ZN(new_n101_));
  NAND2_X1   g068(.A1(new_n74_), .A2(new_n48_), .ZN(new_n102_));
  NAND3_X1   g069(.A1(new_n102_), .A2(\opcode[1] ), .A3(new_n53_), .ZN(new_n103_));
  AOI21_X1   g070(.A1(new_n103_), .A2(new_n101_), .B(new_n100_), .ZN(\alu_op_ext[1] ));
  OAI21_X1   g071(.A1(\opcode[1] ), .A2(\opcode[3] ), .B(\opcode[0] ), .ZN(new_n105_));
  NAND4_X1   g072(.A1(new_n105_), .A2(\opcode[1] ), .A3(\opcode[2] ), .A4(new_n35_), .ZN(new_n106_));
  XOR2_X1    g073(.A1(new_n44_), .A2(new_n106_), .Z(\alu_op_ext[2] ));
  OAI21_X1   g074(.A1(new_n74_), .A2(new_n99_), .B(new_n38_), .ZN(new_n108_));
  NAND2_X1   g075(.A1(new_n108_), .A2(\opcode[2] ), .ZN(new_n109_));
  NOR4_X1    g076(.A1(new_n48_), .A2(new_n53_), .A3(new_n35_), .A4(\opcode[3] ), .ZN(new_n110_));
  NAND2_X1   g077(.A1(new_n109_), .A2(new_n110_), .ZN(new_n111_));
  INV_X1     g078(.I(new_n110_), .ZN(new_n112_));
  NAND3_X1   g079(.A1(new_n112_), .A2(new_n108_), .A3(\opcode[2] ), .ZN(new_n113_));
  NAND2_X1   g080(.A1(new_n111_), .A2(new_n113_), .ZN(\alu_op_ext[3] ));
  NOR3_X1    g081(.A1(new_n39_), .A2(new_n53_), .A3(new_n36_), .ZN(halt));
  OAI21_X1   g082(.A1(new_n54_), .A2(\opcode[0] ), .B(\opcode[1] ), .ZN(new_n116_));
  NAND2_X1   g083(.A1(new_n116_), .A2(new_n53_), .ZN(new_n117_));
  AOI21_X1   g084(.A1(new_n34_), .A2(\opcode[1] ), .B(\opcode[4] ), .ZN(new_n118_));
  OAI21_X1   g085(.A1(new_n53_), .A2(new_n118_), .B(new_n117_), .ZN(reg_write));
  INV_X1     g086(.I(new_n70_), .ZN(new_n120_));
  NOR2_X1    g087(.A1(new_n120_), .A2(new_n39_), .ZN(sel_pc_opA));
  NOR3_X1    g088(.A1(new_n39_), .A2(\opcode[0] ), .A3(new_n53_), .ZN(sel_pc_opB));
  NAND2_X1   g089(.A1(new_n35_), .A2(\opcode[3] ), .ZN(new_n123_));
  NOR3_X1    g090(.A1(new_n123_), .A2(new_n53_), .A3(new_n36_), .ZN(beqz));
  NOR2_X1    g091(.A1(new_n39_), .A2(new_n53_), .ZN(jump));
  NOR2_X1    g092(.A1(new_n37_), .A2(new_n53_), .ZN(new_n126_));
  NAND3_X1   g093(.A1(new_n99_), .A2(\opcode[0] ), .A3(new_n38_), .ZN(new_n127_));
  NAND2_X1   g094(.A1(new_n67_), .A2(\opcode[4] ), .ZN(new_n128_));
  NOR3_X1    g095(.A1(\opcode[0] ), .A2(\opcode[1] ), .A3(\opcode[2] ), .ZN(new_n129_));
  AOI21_X1   g096(.A1(new_n128_), .A2(\opcode[3] ), .B(new_n129_), .ZN(new_n130_));
  AOI21_X1   g097(.A1(new_n127_), .A2(new_n130_), .B(new_n126_), .ZN(Cin));
  NAND3_X1   g098(.A1(new_n99_), .A2(\opcode[0] ), .A3(\opcode[1] ), .ZN(new_n132_));
  NAND3_X1   g099(.A1(new_n123_), .A2(\opcode[0] ), .A3(new_n38_), .ZN(new_n133_));
  NOR2_X1    g100(.A1(new_n34_), .A2(\opcode[2] ), .ZN(new_n134_));
  NAND4_X1   g101(.A1(new_n134_), .A2(\opcode[4] ), .A3(\op_ext[0] ), .A4(\op_ext[1] ), .ZN(new_n135_));
  AOI21_X1   g102(.A1(new_n132_), .A2(new_n133_), .B(new_n135_), .ZN(invA));
  INV_X1     g103(.I(new_n129_), .ZN(new_n137_));
  AOI21_X1   g104(.A1(new_n69_), .A2(new_n137_), .B(new_n126_), .ZN(invB));
  NAND2_X1   g105(.A1(new_n58_), .A2(\opcode[1] ), .ZN(new_n140_));
  NAND2_X1   g106(.A1(new_n74_), .A2(new_n38_), .ZN(new_n141_));
  AOI21_X1   g107(.A1(new_n141_), .A2(new_n140_), .B(new_n120_), .ZN(mem_write));
  NOR3_X1    g108(.A1(new_n120_), .A2(new_n38_), .A3(new_n58_), .ZN(sel_wb));
  assign     sign = 1'b1;
  NOR3_X1    g109(.A1(new_n123_), .A2(new_n53_), .A3(new_n36_), .ZN(bnez));
  NOR3_X1    g110(.A1(new_n123_), .A2(new_n53_), .A3(new_n36_), .ZN(bgez));
  NOR3_X1    g111(.A1(new_n123_), .A2(new_n53_), .A3(new_n36_), .ZN(bltz));
endmodule


