#pragma once
#include "lorina/lorina.hpp"
#include "mockturtle/mockturtle.hpp"

#include "layer_logic/logic_manager.hpp"

#include <cstring>
#include <memory>

namespace lf
{

namespace logic
{

/**
 * @brief read gtech verilog file into the network
 * @param filename
 * @param ntk
 * @param ports
 * @return true/ false
 */
template<class Ntk = mockturtle::gtg_network>
bool read_gtech( std::string const& filename, Ntk& ntk, mockturtle::read_verilog_params& ports )
{
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );

  auto rc = lorina::read_gtech( filename, mockturtle::gtech_reader( ntk, ports ), &diag );
  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief read gtech verilog file into the network
 * @param filename
 * @param ntk
 * @return
 */
template<class Ntk = mockturtle::gtg_network>
bool read_gtech( std::string const& filename, Ntk& ntk )
{
  mockturtle::read_verilog_params ports;
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );

  auto rc = lorina::read_gtech( filename, mockturtle::gtech_reader( ntk, ports ), &diag );
  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief read gtech verilog file
 * @param filename
 * @param ntk
 * @return true/ false
 */
template<class Ntk = lsils::gtg_seq_network>
bool read_gtech( std::string const& filename )
{
  using NtkBase = typename Ntk::base_type;
  if constexpr ( std::is_same_v<NtkBase, mockturtle::aig_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::xag_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::mig_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::xmg_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::gtg_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG );
  }
  else
  {
    assert( false );
  }

  Ntk ntk;

  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;

  lorina::return_code rc = lorina::read_gtech( filename, mockturtle::gtech_reader<Ntk>( ntk, ports ), &diag );
  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
    return false;
  }

  lfLmINST->set_current<Ntk>( ntk );

  return true;
}

} // namespace logic

} // end namespace lf