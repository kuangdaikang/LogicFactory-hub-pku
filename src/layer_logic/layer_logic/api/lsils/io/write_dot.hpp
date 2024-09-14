#pragma once

#include "layer_logic/logic_manager.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief
 *
 */
void write_dot( const std::string& file )
{
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_FPGA ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_ASIC );
  if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG &&
       ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_FPGA &&
       ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_ASIC )
  {
    std::cerr << "[ERROR] write_dot: wrong ntk type!" << std::endl;
    return;
  }

  switch ( ntktype )
  {
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG:
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG:
  {
    lf::logic::lsils::oig_seq_network ntk = lfLmINST->current<lf::logic::lsils::oig_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG:
  {
    lf::logic::lsils::aog_seq_network ntk = lfLmINST->current<lf::logic::lsils::aog_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG:
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG:
  {
    lf::logic::lsils::xog_seq_network ntk = lfLmINST->current<lf::logic::lsils::xog_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG:
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG:
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY:
  {
    lf::logic::lsils::primary_seq_network ntk = lfLmINST->current<lf::logic::lsils::primary_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG:
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_FPGA:
  {
    lf::logic::lsils::klut_seq_network ntk = lfLmINST->current<lf::logic::lsils::klut_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_ASIC:
  {
    lf::logic::lsils::blut_seq_network ntk = lfLmINST->current<lf::logic::lsils::blut_seq_network>();
    if ( ntk.num_gates() > 1000 )
    {
      std::cout << "warning, too many gates (> 1000), not writing dot file\n";
    }
    else
    {
      mockturtle::write_dot( ntk, file );
    }
    break;
  }
  default:
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
    break;
  }
  }
}
} // end namespace lsils

} // end namespace logic

} // end namespace lf
