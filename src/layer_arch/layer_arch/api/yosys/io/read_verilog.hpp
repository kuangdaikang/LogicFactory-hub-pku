#pragma once

#include "layer_arch/arch_manager.hpp"
#include "utility/string.hpp"

#include <cstdio>
#include <string>
#include <assert.h>

namespace lf
{

namespace arch
{

namespace yosys
{

void read_verilog( ArchManager& manager, std::string file )
{
  if ( !lf::utility::endsWith( file, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }
  auto frame = manager.current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( "read_verilog " + file );
}

} // namespace yosys

} // namespace arch

} // end namespace lf