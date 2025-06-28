// Benchmark "source.pla" written by ABC on Fri Feb 25 15:12:35 2022

module newtpla2  ( 
    GStrap, trapinstr, datapagefINT, winunderflow, winoverflow, SWI,
    intTAGtrap, illegalopc, instrpagefINT, IOINT,
    TRAPreason3, TRAPreason2, TRAPreason1, TRAPreason0  );
  input  GStrap, trapinstr, datapagefINT, winunderflow, winoverflow, SWI,
    intTAGtrap, illegalopc, instrpagefINT, IOINT;
  output TRAPreason3, TRAPreason2, TRAPreason1, TRAPreason0;
  wire new_n15_, new_n16_, new_n17_, new_n18_, new_n19_, new_n20_, new_n21_,
    new_n22_, new_n23_, new_n25_, new_n26_, new_n27_, new_n28_, new_n29_,
    new_n30_, new_n31_, new_n32_, new_n33_, new_n35_, new_n36_, new_n37_,
    new_n38_, new_n39_, new_n40_, new_n41_, new_n43_, new_n44_, new_n45_,
    new_n46_, new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_,
    new_n53_;
  assign new_n15_ = ~instrpagefINT & IOINT;
  assign new_n16_ = ~instrpagefINT & ~new_n15_;
  assign new_n17_ = ~illegalopc & ~new_n16_;
  assign new_n18_ = ~intTAGtrap & new_n17_;
  assign new_n19_ = ~SWI & new_n18_;
  assign new_n20_ = ~winoverflow & new_n19_;
  assign new_n21_ = ~winunderflow & new_n20_;
  assign new_n22_ = ~datapagefINT & new_n21_;
  assign new_n23_ = ~trapinstr & new_n22_;
  assign TRAPreason3 = ~GStrap & new_n23_;
  assign new_n25_ = GStrap & ~trapinstr;
  assign new_n26_ = ~trapinstr & ~new_n25_;
  assign new_n27_ = ~datapagefINT & ~new_n26_;
  assign new_n28_ = ~datapagefINT & ~new_n27_;
  assign new_n29_ = ~winunderflow & ~new_n28_;
  assign new_n30_ = ~winunderflow & ~new_n29_;
  assign new_n31_ = ~illegalopc & ~new_n30_;
  assign new_n32_ = ~intTAGtrap & new_n31_;
  assign new_n33_ = ~SWI & new_n32_;
  assign TRAPreason2 = ~winoverflow & new_n33_;
  assign new_n35_ = ~winoverflow & ~new_n26_;
  assign new_n36_ = ~winunderflow & new_n35_;
  assign new_n37_ = ~datapagefINT & new_n36_;
  assign new_n38_ = ~winoverflow & ~new_n37_;
  assign new_n39_ = ~SWI & ~new_n38_;
  assign new_n40_ = ~SWI & ~new_n39_;
  assign new_n41_ = ~illegalopc & ~new_n40_;
  assign TRAPreason1 = ~intTAGtrap & new_n41_;
  assign new_n43_ = ~GStrap & new_n15_;
  assign new_n44_ = ~GStrap & ~new_n43_;
  assign new_n45_ = ~datapagefINT & ~new_n44_;
  assign new_n46_ = ~trapinstr & new_n45_;
  assign new_n47_ = ~datapagefINT & ~new_n46_;
  assign new_n48_ = ~winoverflow & ~new_n47_;
  assign new_n49_ = ~winunderflow & new_n48_;
  assign new_n50_ = ~winoverflow & ~new_n49_;
  assign new_n51_ = ~intTAGtrap & ~new_n50_;
  assign new_n52_ = ~SWI & new_n51_;
  assign new_n53_ = ~intTAGtrap & ~new_n52_;
  assign TRAPreason0 = ~illegalopc & ~new_n53_;
endmodule


