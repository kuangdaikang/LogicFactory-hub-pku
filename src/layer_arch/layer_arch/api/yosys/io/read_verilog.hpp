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

void read_verilog( std::string file )
{
  std::string script = "read_verilog ";
  if ( !lf::utility::endsWith( file, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }
  else
  {
    script += file;
  }
  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf