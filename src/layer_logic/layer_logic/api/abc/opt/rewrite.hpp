#pragma once

#ifdef __cplusplus
extern "C"
{
#include "misc/util/abc_global.h"
#include "base/abci/abc.h"
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
  // Abc_Frame_t* ntk = manager.current().get(); // the the network from shared_ptr
  // Abc_Frame_t* ntk;
  
  // int argc;
  // char** argv;
  // Abc_CommandRewrite( ntk, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf