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
template<typename Ntk = aig_seq_network>
void write_bench( const std::string& file )
{
  using NtkBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, GTG" );

  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  Ntk ntk = lfLmINST->current<Ntk>();

  std::ofstream os( file.c_str(), std::ofstream::out );
  mockturtle::write_bench<Ntk>( ntk, os );
  os.close();
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
