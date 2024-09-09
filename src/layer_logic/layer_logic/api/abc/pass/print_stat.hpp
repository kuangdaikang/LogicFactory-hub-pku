#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"

#include "nlohmann/json.hpp"

#include <cstdio>
#include <string>

namespace lf
{

namespace logic
{

namespace abc
{

void write_abc_logic_stat( const babc::Abc_Frame_t* pAbc, std::string file = "" )
{
  int size = 0, depth = 0;
  double area = 0.0f, delay = 0.0f;
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( pAbc );
  int num_pis = Abc_NtkPiNum( pNtk );
  int num_pos = Abc_NtkPoNum( pNtk );
  size = babc::Abc_NtkNodeNum( pNtk ); // wintout ports
  depth = babc::Abc_NtkLevel( pNtk );

  if ( !file.empty() )
  {
    nlohmann::json j = {
        { "input", num_pis },
        { "output", num_pos },
        { "gates", size },
        { "depth", depth },
        { "area", size },
        { "delay", depth } };
    std::ofstream out( file );
    if ( !out.is_open() )
    {
      std::cerr << "Error: Unable to open file " << file << std::endl;
      return;
    }
    out << j.dump( 4 ) << std::endl;
    out.close();
  }
}

void write_abc_fpga_stat( const babc::Abc_Frame_t* pAbc, std::string file = "" )
{
  int size = 0, depth = 0;
  double area = 0.0f, delay = 0.0f;
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( pAbc );
  int num_pis = Abc_NtkPiNum( pNtk );
  int num_pos = Abc_NtkPoNum( pNtk );
  size = babc::Abc_NtkNodeNum( pNtk ); // wintout ports
  depth = babc::Abc_NtkLevel( pNtk );

  if ( !babc::Abc_NtkIsAigLogic( pNtk ) ) // FPGA netlist
  {
    std::cerr << "Error: netlist is not mapped to ASIC cells" << std::endl;
    assert( false );
  }
  else
  {
    area = babc::Abc_NtkGetArea( pNtk );
    delay = babc::Abc_NtkDelayTraceLut( pNtk, 1 );
  }

  if ( !file.empty() )
  {
    nlohmann::json j = {
        { "input", num_pis },
        { "output", num_pos },
        { "gates", size },
        { "depth", depth },
        { "area", area },
        { "delay", delay } };
    std::ofstream out( file );
    if ( !out.is_open() )
    {
      std::cerr << "Error: Unable to open file " << file << std::endl;
      return;
    }
    out << j.dump( 4 ) << std::endl;
    out.close();
  }
}

void write_abc_asic_stat( const babc::Abc_Frame_t* pAbc, std::string file = "" )
{
  int size = 0, depth = 0;
  double area = 0.0f, delay = 0.0f;
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( pAbc );
  int num_pis = Abc_NtkPiNum( pNtk );
  int num_pos = Abc_NtkPoNum( pNtk );
  size = babc::Abc_NtkNodeNum( pNtk ); // wintout ports
  depth = babc::Abc_NtkLevel( pNtk );

  if ( !babc::Abc_NtkIsMappedLogic( pNtk ) ) // ASIC netlist
  {
    std::cerr << "Error: netlist is not mapped to ASIC cells" << std::endl;
    assert( false );
  }
  else
  {
    area = babc::Abc_NtkGetMappedArea( pNtk );
    delay = babc::Abc_NtkDelayTrace( pNtk, NULL, NULL, 0 );
  }

  if ( !file.empty() )
  {
    nlohmann::json j = {
        { "input", num_pis },
        { "output", num_pos },
        { "gates", size },
        { "depth", depth },
        { "area", area },
        { "delay", delay } };
    std::ofstream out( file );
    if ( !out.is_open() )
    {
      std::cerr << "Error: Unable to open file " << file << std::endl;
      return;
    }
    out << j.dump( 4 ) << std::endl;
    out.close();
  }
}

/**
 * @brief
 */
void write_stat( std::string file = "" )
{
  auto pAbc = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr
  if ( !file.empty() )
  {
  }
  auto ntktype = lfLntINST->get_ntktype_curr();
  switch ( ntktype )
  {
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG:
  {
    write_abc_logic_stat( pAbc, file );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_NETLIST_FPGA:
  {
    write_abc_fpga_stat( pAbc, file );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_NETLIST_ASIC:
  {
    write_abc_asic_stat( pAbc, file );
    break;
  }
  default:
  {
    std::cerr << "Error: unknown netlist type" << std::endl;
    break;
  }
  }
}

/**
 * @brief Logic optimization
 * @example
 *  print_stat [options]
 *  options: -fbdltmpgscu
 * @note
 */
void print_stat( bool is_factored_form = false, bool is_best_ntk_saved_blif = false, bool is_dump = false, bool is_lut_delayed_stat = false,
                 bool is_time_stat = false, bool is_mux_stat = false, bool is_power_dissipation = false, bool is_glitching_power = false,
                 bool is_skip_buf = false, bool is_constant_buf_skiped = false, bool is_usage_momeory = false,
                 std::string file = "" )
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

  if ( !file.empty() )
  {
    write_stat( file );
  }
}

} // namespace abc

} // namespace logic

} // end namespace lf