// Benchmark "ctrl" written by ABC on Mon Sep 11 23:40:43 2023

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
    new_n41_, new_n42_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n64_, new_n65_,
    new_n66_, new_n67_, new_n68_, new_n70_, new_n71_, new_n72_, new_n74_,
    new_n75_, new_n76_, new_n77_, new_n78_, new_n80_, new_n81_, new_n82_,
    new_n83_, new_n84_, new_n85_, new_n86_, new_n87_, new_n88_, new_n90_,
    new_n91_, new_n92_, new_n94_, new_n96_, new_n97_, new_n100_, new_n101_,
    new_n102_, new_n106_, new_n112_, new_n113_, new_n114_, new_n115_,
    new_n116_, new_n118_, new_n120_, new_n123_, new_n124_;
  INV_X1     g00(.I(\opcode[2] ), .ZN(new_n34_));
  NAND2_X1   g01(.A1(\opcode[3] ), .A2(\opcode[4] ), .ZN(new_n35_));
  NOR2_X1    g02(.A1(\opcode[0] ), .A2(\opcode[1] ), .ZN(new_n36_));
  OAI21_X1   g03(.A1(new_n36_), .A2(new_n35_), .B(new_n34_), .ZN(new_n37_));
  INV_X1     g04(.I(new_n35_), .ZN(new_n38_));
  INV_X1     g05(.I(\opcode[1] ), .ZN(new_n39_));
  OR2_X2     g06(.A1(\opcode[3] ), .A2(\opcode[4] ), .Z(new_n40_));
  NOR2_X1    g07(.A1(new_n40_), .A2(new_n39_), .ZN(new_n41_));
  OAI21_X1   g08(.A1(new_n41_), .A2(new_n38_), .B(\opcode[2] ), .ZN(new_n42_));
  NAND2_X1   g09(.A1(new_n42_), .A2(new_n37_), .ZN(\sel_reg_dst[0] ));
  INV_X1     g10(.I(\opcode[0] ), .ZN(new_n44_));
  NAND4_X1   g11(.A1(new_n44_), .A2(new_n39_), .A3(\opcode[3] ), .A4(\opcode[4] ), .ZN(new_n45_));
  INV_X1     g12(.I(\opcode[4] ), .ZN(new_n46_));
  NOR2_X1    g13(.A1(new_n46_), .A2(\opcode[3] ), .ZN(new_n47_));
  INV_X1     g14(.I(new_n47_), .ZN(new_n48_));
  OAI21_X1   g15(.A1(new_n48_), .A2(new_n39_), .B(new_n45_), .ZN(new_n49_));
  MUX2_X1    g16(.I0(new_n49_), .I1(new_n41_), .S(\opcode[2] ), .Z(\sel_reg_dst[1] ));
  NAND3_X1   g17(.A1(new_n46_), .A2(\opcode[1] ), .A3(\opcode[3] ), .ZN(new_n51_));
  INV_X1     g18(.I(\opcode[3] ), .ZN(new_n52_));
  OAI21_X1   g19(.A1(new_n39_), .A2(new_n52_), .B(\opcode[4] ), .ZN(new_n53_));
  NAND2_X1   g20(.A1(new_n39_), .A2(new_n52_), .ZN(new_n54_));
  NAND2_X1   g21(.A1(\opcode[0] ), .A2(\opcode[4] ), .ZN(new_n55_));
  NAND3_X1   g22(.A1(new_n54_), .A2(new_n34_), .A3(new_n55_), .ZN(new_n56_));
  AOI21_X1   g23(.A1(new_n51_), .A2(new_n53_), .B(new_n56_), .ZN(\sel_alu_opB[0] ));
  NOR2_X1    g24(.A1(new_n52_), .A2(\opcode[4] ), .ZN(new_n58_));
  NOR2_X1    g25(.A1(new_n47_), .A2(new_n58_), .ZN(new_n59_));
  INV_X1     g26(.I(new_n59_), .ZN(new_n60_));
  NAND4_X1   g27(.A1(new_n34_), .A2(\opcode[0] ), .A3(\opcode[1] ), .A4(\opcode[3] ), .ZN(new_n61_));
  NAND2_X1   g28(.A1(new_n47_), .A2(\opcode[2] ), .ZN(new_n62_));
  OAI21_X1   g29(.A1(new_n60_), .A2(new_n61_), .B(new_n62_), .ZN(\sel_alu_opB[1] ));
  NOR2_X1    g30(.A1(new_n48_), .A2(new_n44_), .ZN(new_n64_));
  NAND4_X1   g31(.A1(new_n44_), .A2(\opcode[3] ), .A3(\opcode[4] ), .A4(\op_ext[0] ), .ZN(new_n65_));
  NAND2_X1   g32(.A1(\op_ext[0] ), .A2(\op_ext[1] ), .ZN(new_n66_));
  OAI21_X1   g33(.A1(new_n40_), .A2(new_n66_), .B(\opcode[0] ), .ZN(new_n67_));
  AOI21_X1   g34(.A1(new_n67_), .A2(new_n65_), .B(new_n39_), .ZN(new_n68_));
  MUX2_X1    g35(.I0(new_n68_), .I1(new_n64_), .S(\opcode[2] ), .Z(\alu_op[0] ));
  NOR2_X1    g36(.A1(new_n47_), .A2(new_n34_), .ZN(new_n70_));
  NOR2_X1    g37(.A1(new_n46_), .A2(\op_ext[1] ), .ZN(new_n71_));
  NAND2_X1   g38(.A1(new_n39_), .A2(\opcode[2] ), .ZN(new_n72_));
  NOR4_X1    g39(.A1(new_n70_), .A2(new_n52_), .A3(new_n71_), .A4(new_n72_), .ZN(\alu_op[1] ));
  NOR2_X1    g40(.A1(new_n44_), .A2(new_n39_), .ZN(new_n74_));
  NAND3_X1   g41(.A1(new_n34_), .A2(\opcode[3] ), .A3(\opcode[4] ), .ZN(new_n75_));
  NAND2_X1   g42(.A1(new_n74_), .A2(\opcode[3] ), .ZN(new_n76_));
  NAND2_X1   g43(.A1(new_n38_), .A2(new_n34_), .ZN(new_n77_));
  NAND4_X1   g44(.A1(new_n59_), .A2(new_n76_), .A3(new_n77_), .A4(\opcode[2] ), .ZN(new_n78_));
  NAND2_X1   g45(.A1(new_n78_), .A2(new_n75_), .ZN(\alu_op[2] ));
  NOR2_X1    g46(.A1(new_n52_), .A2(\opcode[0] ), .ZN(new_n80_));
  NAND4_X1   g47(.A1(new_n80_), .A2(new_n39_), .A3(new_n34_), .A4(\opcode[4] ), .ZN(new_n81_));
  NOR2_X1    g48(.A1(\opcode[1] ), .A2(\opcode[4] ), .ZN(new_n82_));
  NOR2_X1    g49(.A1(new_n82_), .A2(\opcode[3] ), .ZN(new_n83_));
  NAND2_X1   g50(.A1(new_n80_), .A2(new_n46_), .ZN(new_n84_));
  NAND2_X1   g51(.A1(new_n84_), .A2(new_n83_), .ZN(new_n85_));
  NAND3_X1   g52(.A1(new_n44_), .A2(new_n46_), .A3(\opcode[3] ), .ZN(new_n86_));
  NAND4_X1   g53(.A1(new_n85_), .A2(\opcode[2] ), .A3(new_n81_), .A4(new_n86_), .ZN(new_n87_));
  NAND4_X1   g54(.A1(new_n80_), .A2(new_n39_), .A3(new_n34_), .A4(\opcode[4] ), .ZN(new_n88_));
  NAND2_X1   g55(.A1(new_n87_), .A2(new_n88_), .ZN(\alu_op_ext[0] ));
  NOR2_X1    g56(.A1(new_n48_), .A2(\opcode[0] ), .ZN(new_n90_));
  OAI21_X1   g57(.A1(new_n90_), .A2(\opcode[2] ), .B(new_n59_), .ZN(new_n91_));
  NAND3_X1   g58(.A1(new_n47_), .A2(new_n44_), .A3(new_n34_), .ZN(new_n92_));
  AOI21_X1   g59(.A1(new_n91_), .A2(new_n92_), .B(new_n39_), .ZN(\alu_op_ext[1] ));
  NOR4_X1    g60(.A1(new_n52_), .A2(\opcode[0] ), .A3(\opcode[1] ), .A4(\opcode[4] ), .ZN(new_n94_));
  MUX2_X1    g61(.I0(new_n94_), .I1(new_n41_), .S(\opcode[2] ), .Z(\alu_op_ext[2] ));
  AOI21_X1   g62(.A1(new_n55_), .A2(new_n52_), .B(new_n39_), .ZN(new_n96_));
  AOI21_X1   g63(.A1(new_n60_), .A2(new_n39_), .B(new_n96_), .ZN(new_n97_));
  OAI21_X1   g64(.A1(new_n97_), .A2(\opcode[2] ), .B(new_n62_), .ZN(\alu_op_ext[3] ));
  NOR4_X1    g65(.A1(new_n40_), .A2(\opcode[0] ), .A3(\opcode[1] ), .A4(\opcode[2] ), .ZN(halt));
  NOR2_X1    g66(.A1(new_n36_), .A2(new_n46_), .ZN(new_n100_));
  NAND2_X1   g67(.A1(new_n34_), .A2(new_n52_), .ZN(new_n101_));
  AOI21_X1   g68(.A1(new_n52_), .A2(\opcode[1] ), .B(\opcode[4] ), .ZN(new_n102_));
  OAI22_X1   g69(.A1(new_n100_), .A2(new_n101_), .B1(new_n102_), .B2(new_n34_), .ZN(reg_write));
  NOR3_X1    g70(.A1(new_n40_), .A2(new_n44_), .A3(new_n34_), .ZN(sel_pc_opA));
  NOR3_X1    g71(.A1(new_n40_), .A2(\opcode[0] ), .A3(new_n34_), .ZN(sel_pc_opB));
  INV_X1     g72(.I(new_n58_), .ZN(new_n106_));
  NOR3_X1    g73(.A1(new_n106_), .A2(new_n72_), .A3(\opcode[0] ), .ZN(beqz));
  NOR3_X1    g74(.A1(new_n106_), .A2(new_n72_), .A3(new_n44_), .ZN(bnez));
  NOR4_X1    g75(.A1(new_n106_), .A2(new_n44_), .A3(new_n39_), .A4(new_n34_), .ZN(bgez));
  NOR4_X1    g76(.A1(new_n106_), .A2(\opcode[0] ), .A3(new_n39_), .A4(new_n34_), .ZN(bltz));
  NOR2_X1    g77(.A1(new_n40_), .A2(new_n34_), .ZN(jump));
  NOR2_X1    g78(.A1(new_n74_), .A2(new_n35_), .ZN(new_n112_));
  NOR2_X1    g79(.A1(new_n112_), .A2(new_n34_), .ZN(new_n113_));
  NOR2_X1    g80(.A1(new_n46_), .A2(\op_ext[0] ), .ZN(new_n114_));
  OAI21_X1   g81(.A1(new_n76_), .A2(new_n114_), .B(new_n34_), .ZN(new_n115_));
  NAND3_X1   g82(.A1(new_n58_), .A2(\opcode[0] ), .A3(new_n39_), .ZN(new_n116_));
  AOI21_X1   g83(.A1(new_n115_), .A2(new_n116_), .B(new_n113_), .ZN(Cin));
  OAI21_X1   g84(.A1(new_n52_), .A2(\opcode[4] ), .B(\opcode[1] ), .ZN(new_n118_));
  NOR3_X1    g85(.A1(new_n118_), .A2(new_n44_), .A3(\opcode[2] ), .ZN(invA));
  NAND4_X1   g86(.A1(new_n52_), .A2(new_n46_), .A3(\op_ext[0] ), .A4(\op_ext[1] ), .ZN(new_n120_));
  AOI21_X1   g87(.A1(new_n120_), .A2(new_n74_), .B(\opcode[2] ), .ZN(invB));
  NAND2_X1   g88(.A1(new_n39_), .A2(\opcode[0] ), .ZN(new_n123_));
  NAND2_X1   g89(.A1(new_n44_), .A2(\opcode[1] ), .ZN(new_n124_));
  AOI22_X1   g90(.A1(new_n123_), .A2(new_n124_), .B1(new_n47_), .B2(new_n34_), .ZN(mem_write));
  NOR3_X1    g91(.A1(new_n48_), .A2(new_n123_), .A3(\opcode[2] ), .ZN(sel_wb));
  assign     sign = 1'b1;
endmodule


