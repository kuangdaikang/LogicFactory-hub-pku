#pragma once

#include "layer_logic/logic_manager.hpp"

#include <cstdio>
#include <string>

#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/io/io.h"
#include "misc/extra/extra.h"

#include "utility/string.hpp"

namespace lf
{

namespace logic
{

namespace abc
{

void read_liberty( LogicManager& manager, std::string file )
{
  if ( !lf::utility::endsWith( file, ".lib" ) )
  {
    std::cerr << "Unmatched liberty suffix type." << std::endl;
    assert( false );
    return;
  }

  manager.update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = manager.current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  char** argv = ABC_ALLOC( char*, argc + 1 );

  argv[0] = babc::Extra_UtilStrsav( "read" );
  argv[1] = const_cast<char*>( file.c_str() );

  babc::IoCommandRead( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf