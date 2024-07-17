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

void map_asic()
{
  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr
  int argc = 0;
  char** argv = nullptr;
  babc::Abc_CommandMap( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf