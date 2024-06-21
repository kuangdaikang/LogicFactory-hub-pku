#pragma once

#include "layer_logic/logic_manager.hpp"

#include <cstdio>

#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/abci/abc.h"

namespace lf
{

namespace logic
{

namespace abc
{

void rewrite( LogicManager& manager )
{
  manager.update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = manager.current<babc::Abc_Frame_t>(); // the the network from shared_ptr
  int argc;
  char** argv;
  babc::Abc_CommandRewrite( ntk_ptr, argc, argv );
  // update the
  manager.set_current<babc::Abc_Frame_t>( ntk_ptr );
}

} // namespace abc

} // namespace logic

} // end namespace lf