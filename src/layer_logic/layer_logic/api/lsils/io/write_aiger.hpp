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
void write_aiger( Ntk const& ntk, const std::string& file )
{
  using NtkBase = typename Ntk::base_type;

  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, or GTG" );

  std::ofstream os( file.c_str(), std::ofstream::out );
  mockturtle::write_aiger<Ntk>( ntk, os );
  os.close();
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
