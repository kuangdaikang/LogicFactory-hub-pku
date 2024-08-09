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
 * @brief Logic optimization
 * @example
 *  print_stat [options]
 *  options: -fbdltmpgscu
 * @note
 */
void print_stat( bool is_factored_form = false, bool is_best_ntk_saved_blif = false, bool is_dump = false, bool is_lut_delayed_stat = false,
                 bool is_time_stat = false, bool is_mux_stat = false, bool is_power_dissipation = false, bool is_glitching_power = false,
                 bool is_skip_buf = false, bool is_constant_buf_skiped = false, bool is_usage_momeory = false )
{
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name

  if ( is_factored_form )
    argc++;
  if ( is_best_ntk_saved_blif )
    argc++;
  if ( is_dump )
    argc++;
  if ( is_lut_delayed_stat )
    argc++;
  if ( is_time_stat )
    argc++;
  if ( is_mux_stat )
    argc++;
  if ( is_power_dissipation )
    argc++;
  if ( is_glitching_power )
    argc++;
  if ( is_skip_buf )
    argc++;
  if ( is_constant_buf_skiped )
    argc++;
  if ( is_usage_momeory )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "print_stat" );

  if ( is_factored_form )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -f " ).c_str() );
  if ( is_best_ntk_saved_blif )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -b " ).c_str() );
  if ( is_dump )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -d " ).c_str() );
  if ( is_lut_delayed_stat )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -l " ).c_str() );
  if ( is_time_stat )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -t " ).c_str() );
  if ( is_mux_stat )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -m " ).c_str() );
  if ( is_power_dissipation )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -p " ).c_str() );
  if ( is_glitching_power )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -g " ).c_str() );
  if ( is_skip_buf )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -s " ).c_str() );
  if ( is_constant_buf_skiped )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -c " ).c_str() );
  if ( is_usage_momeory )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -u " ).c_str() );

  babc::Abc_CommandPrintStats( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf