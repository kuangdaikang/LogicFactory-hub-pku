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

void read_aiger( ArchManager& manager, std::string file )
{
  std::string script = "read_aiger ";
  if ( !lf::utility::endsWith( file, ".aig" ) )
  {
    std::cerr << "Unmatched aig suffix type." << std::endl;
    assert( false );
    return;
  }
  else
  {
    script += file;
  }
  auto frame = manager.current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf