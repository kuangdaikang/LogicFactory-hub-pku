#pragma once

#include "layer_logic/logic_manager.hpp"

#include <cstdio>

#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/abci/abc.h"
#include "base/io/ioAbc.h"

namespace lf
{

namespace logic
{

namespace abc
{

void rewrite( LogicManager& manager )
{
  manager.update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = manager.current<babc::Abc_Frame_t*>(); // the the network from shared_ptr
  int argc;
  char** argv;
  babc::Abc_CommandPrintStats( ntk_ptr, argc, argv );
  babc::Abc_CommandRewrite( ntk_ptr, argc, argv );
  babc::Abc_CommandPrintStats( ntk_ptr, argc, argv );
  babc::Io_Write( babc::Abc_FrameReadNtk( ntk_ptr ), "test.rewrite.aig", babc::IO_FILE_AIGER );
}

} // namespace abc

} // namespace logic

} // end namespace lf