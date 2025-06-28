// Benchmark "ctrl" written by ABC on Fri Sep 15 11:25:18 2023

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
    new_n41_, new_n42_, new_n43_, new_n45_, new_n46_, new_n47_, new_n48_,
    new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n62_, new_n63_, new_n64_,
    new_n65_, new_n67_, new_n68_, new_n69_, new_n70_, new_n71_, new_n72_,
    new_n74_, new_n75_, new_n77_, new_n78_, new_n79_, new_n81_, new_n82_,
    new_n83_, new_n85_, new_n86_, new_n88_, new_n89_, new_n91_, new_n92_,
    new_n93_, new_n96_, new_n101_, new_n106_, new_n107_, new_n108_,
    new_n109_, new_n111_, new_n112_, new_n113_, new_n115_, new_n118_;
  INV_X1     g00(.I(\opcode[4] ), .ZN(new_n34_));
  NOR2_X1    g01(.A1(\opcode[0] ), .A2(\opcode[1] ), .ZN(new_n35_));
  NOR2_X1    g02(.A1(new_n35_), .A2(new_n34_), .ZN(new_n36_));
  NAND2_X1   g03(.A1(new_n36_), .A2(\opcode[3] ), .ZN(new_n37_));
  INV_X1     g04(.I(\opcode[3] ), .ZN(new_n38_));
  NAND2_X1   g05(.A1(new_n38_), .A2(\opcode[4] ), .ZN(new_n39_));
  NAND2_X1   g06(.A1(new_n39_), .A2(\opcode[2] ), .ZN(new_n40_));
  INV_X1     g07(.I(\opcode[1] ), .ZN(new_n41_));
  NOR2_X1    g08(.A1(new_n41_), .A2(\opcode[3] ), .ZN(new_n42_));
  NOR2_X1    g09(.A1(new_n42_), .A2(\opcode[4] ), .ZN(new_n43_));
  OAI22_X1   g10(.A1(new_n37_), .A2(\opcode[2] ), .B1(new_n43_), .B2(new_n40_), .ZN(\sel_reg_dst[0] ));
  INV_X1     g11(.I(\opcode[2] ), .ZN(new_n45_));
  INV_X1     g12(.I(\opcode[0] ), .ZN(new_n46_));
  NAND3_X1   g13(.A1(new_n46_), .A2(\opcode[3] ), .A3(\opcode[4] ), .ZN(new_n47_));
  NOR2_X1    g14(.A1(new_n47_), .A2(\opcode[1] ), .ZN(new_n48_));
  NOR2_X1    g15(.A1(new_n39_), .A2(new_n41_), .ZN(new_n49_));
  OAI21_X1   g16(.A1(new_n48_), .A2(new_n49_), .B(new_n45_), .ZN(new_n50_));
  NAND2_X1   g17(.A1(new_n38_), .A2(new_n34_), .ZN(new_n51_));
  NOR2_X1    g18(.A1(new_n51_), .A2(new_n41_), .ZN(new_n52_));
  NAND2_X1   g19(.A1(new_n52_), .A2(\opcode[2] ), .ZN(new_n53_));
  NAND2_X1   g20(.A1(new_n50_), .A2(new_n53_), .ZN(\sel_reg_dst[1] ));
  NAND2_X1   g21(.A1(new_n34_), .A2(\opcode[3] ), .ZN(new_n55_));
  INV_X1     g22(.I(new_n55_), .ZN(new_n56_));
  NAND2_X1   g23(.A1(new_n56_), .A2(\opcode[1] ), .ZN(new_n57_));
  NOR2_X1    g24(.A1(new_n38_), .A2(\opcode[1] ), .ZN(new_n58_));
  NOR2_X1    g25(.A1(new_n34_), .A2(\opcode[0] ), .ZN(new_n59_));
  OAI21_X1   g26(.A1(new_n42_), .A2(new_n58_), .B(new_n59_), .ZN(new_n60_));
  AOI21_X1   g27(.A1(new_n57_), .A2(new_n60_), .B(\opcode[2] ), .ZN(\sel_alu_opB[0] ));
  INV_X1     g28(.I(new_n39_), .ZN(new_n62_));
  NAND2_X1   g29(.A1(new_n62_), .A2(\opcode[2] ), .ZN(new_n63_));
  NAND2_X1   g30(.A1(\opcode[3] ), .A2(\opcode[4] ), .ZN(new_n64_));
  OAI22_X1   g31(.A1(new_n62_), .A2(new_n58_), .B1(new_n46_), .B2(new_n64_), .ZN(new_n65_));
  OAI21_X1   g32(.A1(new_n65_), .A2(\opcode[2] ), .B(new_n63_), .ZN(\sel_alu_opB[1] ));
  INV_X1     g33(.I(\op_ext[0] ), .ZN(new_n67_));
  NOR2_X1    g34(.A1(new_n47_), .A2(new_n67_), .ZN(new_n68_));
  AOI21_X1   g35(.A1(\op_ext[0] ), .A2(\op_ext[1] ), .B(new_n34_), .ZN(new_n69_));
  NOR3_X1    g36(.A1(new_n69_), .A2(new_n46_), .A3(new_n38_), .ZN(new_n70_));
  OAI21_X1   g37(.A1(new_n70_), .A2(new_n68_), .B(\opcode[1] ), .ZN(new_n71_));
  NAND3_X1   g38(.A1(new_n62_), .A2(\opcode[0] ), .A3(\opcode[2] ), .ZN(new_n72_));
  OAI21_X1   g39(.A1(new_n71_), .A2(\opcode[2] ), .B(new_n72_), .ZN(\alu_op[0] ));
  NOR2_X1    g40(.A1(new_n34_), .A2(\op_ext[1] ), .ZN(new_n74_));
  OR3_X2     g41(.A1(new_n74_), .A2(\opcode[2] ), .A3(new_n38_), .Z(new_n75_));
  AOI21_X1   g42(.A1(new_n75_), .A2(new_n63_), .B(new_n41_), .ZN(\alu_op[1] ));
  NAND2_X1   g43(.A1(\opcode[0] ), .A2(\opcode[1] ), .ZN(new_n77_));
  NAND3_X1   g44(.A1(new_n77_), .A2(\opcode[3] ), .A3(\opcode[4] ), .ZN(new_n78_));
  NAND3_X1   g45(.A1(new_n78_), .A2(new_n45_), .A3(new_n51_), .ZN(new_n79_));
  OAI21_X1   g46(.A1(new_n45_), .A2(new_n64_), .B(new_n79_), .ZN(\alu_op[2] ));
  NOR2_X1    g47(.A1(new_n64_), .A2(new_n46_), .ZN(new_n81_));
  NOR2_X1    g48(.A1(new_n52_), .A2(new_n81_), .ZN(new_n82_));
  NAND2_X1   g49(.A1(new_n41_), .A2(new_n45_), .ZN(new_n83_));
  OAI22_X1   g50(.A1(new_n82_), .A2(new_n45_), .B1(new_n47_), .B2(new_n83_), .ZN(\alu_op_ext[0] ));
  NAND3_X1   g51(.A1(new_n39_), .A2(new_n55_), .A3(\opcode[2] ), .ZN(new_n85_));
  NAND3_X1   g52(.A1(new_n62_), .A2(new_n46_), .A3(new_n45_), .ZN(new_n86_));
  AOI21_X1   g53(.A1(new_n86_), .A2(new_n85_), .B(new_n41_), .ZN(\alu_op_ext[1] ));
  NOR3_X1    g54(.A1(new_n41_), .A2(\opcode[0] ), .A3(\opcode[3] ), .ZN(new_n88_));
  OAI21_X1   g55(.A1(new_n88_), .A2(new_n58_), .B(\opcode[4] ), .ZN(new_n89_));
  OAI21_X1   g56(.A1(new_n89_), .A2(\opcode[2] ), .B(new_n53_), .ZN(\alu_op_ext[2] ));
  OAI21_X1   g57(.A1(new_n62_), .A2(new_n56_), .B(new_n41_), .ZN(new_n91_));
  OAI21_X1   g58(.A1(new_n46_), .A2(new_n34_), .B(new_n38_), .ZN(new_n92_));
  AOI21_X1   g59(.A1(new_n92_), .A2(\opcode[1] ), .B(\opcode[2] ), .ZN(new_n93_));
  AOI22_X1   g60(.A1(new_n91_), .A2(new_n93_), .B1(\opcode[2] ), .B2(new_n39_), .ZN(\alu_op_ext[3] ));
  NOR3_X1    g61(.A1(new_n51_), .A2(new_n83_), .A3(\opcode[0] ), .ZN(halt));
  OAI21_X1   g62(.A1(new_n36_), .A2(\opcode[3] ), .B(new_n45_), .ZN(new_n96_));
  OAI21_X1   g63(.A1(new_n45_), .A2(new_n43_), .B(new_n96_), .ZN(reg_write));
  NOR3_X1    g64(.A1(new_n51_), .A2(new_n46_), .A3(new_n45_), .ZN(sel_pc_opA));
  NOR3_X1    g65(.A1(new_n51_), .A2(\opcode[0] ), .A3(new_n45_), .ZN(sel_pc_opB));
  NOR4_X1    g66(.A1(new_n55_), .A2(\opcode[0] ), .A3(\opcode[1] ), .A4(new_n45_), .ZN(beqz));
  NAND3_X1   g67(.A1(new_n56_), .A2(\opcode[0] ), .A3(new_n41_), .ZN(new_n101_));
  NOR2_X1    g68(.A1(new_n101_), .A2(new_n45_), .ZN(bnez));
  NOR4_X1    g69(.A1(new_n55_), .A2(new_n46_), .A3(new_n41_), .A4(new_n45_), .ZN(bgez));
  NOR3_X1    g70(.A1(new_n57_), .A2(\opcode[0] ), .A3(new_n45_), .ZN(bltz));
  NOR2_X1    g71(.A1(new_n51_), .A2(new_n45_), .ZN(jump));
  AND2_X2    g72(.A1(new_n78_), .A2(\opcode[2] ), .Z(new_n106_));
  INV_X1     g73(.I(new_n77_), .ZN(new_n107_));
  AOI21_X1   g74(.A1(\opcode[4] ), .A2(new_n67_), .B(new_n38_), .ZN(new_n108_));
  AOI21_X1   g75(.A1(new_n108_), .A2(new_n107_), .B(\opcode[2] ), .ZN(new_n109_));
  AOI21_X1   g76(.A1(new_n101_), .A2(new_n109_), .B(new_n106_), .ZN(Cin));
  NOR2_X1    g77(.A1(new_n55_), .A2(\opcode[1] ), .ZN(new_n111_));
  NOR4_X1    g78(.A1(new_n38_), .A2(new_n34_), .A3(new_n67_), .A4(\op_ext[1] ), .ZN(new_n112_));
  AOI21_X1   g79(.A1(\opcode[1] ), .A2(new_n112_), .B(new_n111_), .ZN(new_n113_));
  NOR3_X1    g80(.A1(new_n113_), .A2(new_n46_), .A3(\opcode[2] ), .ZN(invA));
  OR3_X2     g81(.A1(new_n69_), .A2(new_n38_), .A3(new_n77_), .Z(new_n115_));
  AOI21_X1   g82(.A1(new_n115_), .A2(new_n45_), .B(new_n106_), .ZN(invB));
  NOR2_X1    g83(.A1(new_n107_), .A2(new_n35_), .ZN(new_n118_));
  NOR3_X1    g84(.A1(new_n118_), .A2(\opcode[2] ), .A3(new_n39_), .ZN(mem_write));
  NOR3_X1    g85(.A1(new_n83_), .A2(new_n39_), .A3(new_n46_), .ZN(sel_wb));
  assign     sign = 1'b1;
endmodule


