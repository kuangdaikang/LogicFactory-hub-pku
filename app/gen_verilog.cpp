#include "layer_arch/arch_manager.hpp"
#include "layer_arch/api/yosys/io/read_aiger.hpp"
#include "layer_arch/api/yosys/io/write_verilog.hpp"

#include "layer_arch/api/yosys/pass/hierarchy.hpp"
#include "layer_arch/api/yosys/pass/flattern.hpp"
#include "layer_arch/api/yosys/pass/abc.hpp"

int main( int argc, char** argv )
{
  std::string aiger = std::string( argv[1] );
  std::string abc = std::string( argv[2] );
  std::string liberty = std::string( argv[3] );
  std::string verilog = std::string( argv[4] );

  lf::arch::ArchManager manager;
  manager.start();

  // read aiger
  lf::arch::yosys::read_aiger( manager, aiger );

  // run pass
  lf::arch::yosys::hierarchy( manager );

  lf::arch::yosys::abc( manager, " -exe " + abc + " -liberty " + liberty );

  lf::arch::yosys::write_verilog( manager, verilog );

  manager.stop();
  return 1;
}