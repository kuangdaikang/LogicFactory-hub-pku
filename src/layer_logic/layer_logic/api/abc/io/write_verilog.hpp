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

void write_verilog( std::string file )
{
  if ( !lf::utility::endsWith( file, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  char** argv = ABC_ALLOC( char*, argc + 1 );

  argv[0] = babc::Extra_UtilStrsav( "write_verilog" );
  argv[1] = const_cast<char*>( file.c_str() );

  babc::IoCommandWriteVerilog( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf