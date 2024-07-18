#pragma once

#include "register/arch/tcl_register_yosys.hpp"
#include "register/logic/tcl_register_abc.hpp"
#include "register/logic/tcl_register_lsils.hpp"
#include "register/netlist/tcl_register_ieda.hpp"

namespace lf

{
namespace tcl
{

int registerCmds()
{
  registerCmdArchYosys();
  registerCmdiEDA();
}

} // namespace tcl

} // namespace lf