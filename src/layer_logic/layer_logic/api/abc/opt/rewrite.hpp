#pragma once

#ifdef __cplusplus
extern "C"
{
// #include "base/abc/abc.h"
#include "base/abci/abc.c"
}
#endif

#include "layer_logic/logic_manager.hpp"

#include <cstdio>

namespace lf
{

namespace logic
{

namespace abc
{

void rewrite( LogicManager& manager )
{
  manager.update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk = manager.current();

  // int argc, char **argv;
  // return pabc::Abc_CommandRewrite( pAbc, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf