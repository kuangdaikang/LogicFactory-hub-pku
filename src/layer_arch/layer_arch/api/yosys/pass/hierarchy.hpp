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

void hierarchy( ArchManager& manager, std::string top_name = "" )
{
  std::string script = "hierarchy -check ";
  if ( top_name != "" )
  {
    script += "-top " + top_name;
  }
  else
  {
    script += "-auto-top";
  }
  auto frame = manager.current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf