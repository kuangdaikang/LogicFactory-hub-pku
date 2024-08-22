#pragma once

#include "layer_logic/logic_manager.hpp"
#include "mockturtle/views/depth_view.hpp"

#include <iomanip>
#include <assert.h>

namespace lf
{

namespace logic
{

namespace lsils
{

template<typename Ntk>
void print_logic_stat( const Ntk& ntk )
{
  // assert the sequential network
  static_assert( mockturtle::has_num_registers_v<Ntk>, "Ntk does not implement the num_registers method" );

  mockturtle::depth_view<Ntk> ntk_depth( ntk );
  std::string module_name = lfLmINST->ports().get_module_name();
  uint32_t area = ntk_depth.size();
  uint32_t depth = ntk_depth.depth();
  uint32_t latch = ntk_depth.num_registers();

  std::cout << module_name << "\t\t: i/o = " << ntk.num_pis() << "/" << ntk.num_pos()
            << "\tlatch = " << latch
            << "\tarea = " << area
            << "\tdepth = " << depth << std::endl;
}

void print_mapping_stat( const lf::logic::lsils::blut_seq_network& ntk )
{
  std::string module_name = lfLmINST->ports().get_module_name();
  double area = ntk.compute_area();
  double delay = ntk.compute_worst_delay();
  uint32_t latch = ntk.num_registers();
  std::cout << std::fixed << std::setprecision( 3 )
            << module_name << "\t\t: i/o = " << ntk.num_pis() << "/" << ntk.num_pos()
            << "\tlatch = " << latch
            << "\tarea = " << area
            << "\tdepth = " << delay << std::endl;
}

/**
 * @brief Logic optimization
 * @example
 *  print_stat [options]
 *  options:
 * @note
 */
void print_stat( bool is_liberty = false )
{
  printf("print stat\n");
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG );

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA )
  {
    lf::logic::lsils::klut_seq_network ntk = lfLmINST->current<lf::logic::lsils::klut_seq_network>();
    print_logic_stat( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC )
  {
    lf::logic::lsils::blut_seq_network ntk = lfLmINST->current<lf::logic::lsils::blut_seq_network>();
    if ( is_liberty )
      print_mapping_stat( ntk );
    else
      print_logic_stat( ntk );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

} // namespace lsils
} // namespace logic
} // namespace lf