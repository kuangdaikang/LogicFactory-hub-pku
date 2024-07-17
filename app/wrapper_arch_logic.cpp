#include "layer_arch/arch_manager.hpp"
#include "layer_arch/api/yosys/io/read_verilog.hpp"
#include "layer_arch/api/yosys/io/read_aiger.hpp"
#include "layer_arch/api/yosys/pass/hierarchy.hpp"
#include "layer_arch/api/yosys/pass/opt.hpp"
#include "layer_arch/api/yosys/pass/aigmap.hpp"

#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/io/write_dot.hpp"
#include "layer_logic/wrapper/to_logic_wrapper.hpp"

void profile( Yosys::RTLIL::Design* design )
{
  auto top_module = design->top_module();
  std::vector<Yosys::RTLIL::Wire*> all_wires = top_module->selected_wires();
  std::vector<Yosys::RTLIL::Cell*> all_cells = top_module->selected_cells();

  printf( "Wires:\n" );
  for ( auto wire : all_wires )
  {
    printf( "-wire: %s\n", wire->name.c_str() );
  }

  printf( "Cells:\n" );
  for ( auto cell : all_cells )
  {
    printf( "-name: %s\n", cell->name.c_str() );
    printf( "-type: %s\n", cell->type.c_str() );
  }
}

int main( int argc, char** argv )
{
  std::string file = std::string( argv[1] );
  lfAmINST->start();

  //   lf::arch::yosys::read_verilog(  file );
  lf::arch::yosys::read_aiger( file );

  lf::arch::yosys::hierarchy();
  lf::arch::yosys::opt();
  lf::arch::yosys::aigmap();

  Yosys::RTLIL::Design* frame_yosys = lfAmINST->current<Yosys::RTLIL::Design*>();

  mockturtle::gtg_network gtg = lf::logic::to_lsils_wrapper( frame_yosys );
  mockturtle::write_dot( gtg, "test_arch.gtg.dot" );

  return 1;
}