#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"

#include <cstdio>
#include <string>

namespace lf
{

namespace logic
{

namespace abc
{

/**
 * @brief Reads file into the current logic network.
 * @example
 *  read_aiger [options] [filename]
 *  options: -n -m -a -c
 * @note
 */
void read_blif( const std::string& file, bool is_old_parser = false, bool is_aig_created = false, bool is_saving_names = false, bool is_checking = false )
{
  if ( !lf::utility::endsWith( file, ".blif" ) )
  {
    std::cerr << "Unmatched blif suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( lf::misc::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_SOP );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name
  argc += 1;    // file name
  if ( is_old_parser )
    argc += 1;
  if ( is_aig_created )
    argc += 1;
  if ( is_saving_names )
    argc += 1;
  if ( is_checking )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;

  argv[pos++] = babc::Extra_UtilStrsav( "read_blif" );

  if ( is_old_parser )
    argv[pos++] = babc::Extra_UtilStrsav( " -n " );
  if ( is_aig_created )
    argv[pos++] = babc::Extra_UtilStrsav( " -m " );
  if ( is_saving_names )
    argv[pos++] = babc::Extra_UtilStrsav( " -a " );
  if ( is_checking )
    argv[pos++] = babc::Extra_UtilStrsav( " -c " );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandReadBlif( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf