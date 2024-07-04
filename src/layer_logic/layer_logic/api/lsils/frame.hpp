#pragma once

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xmg.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/klut.hpp"

#include "mockturtle/io/gtech_reader.hpp"

#include "mockturtle/networks/sequential.hpp"
#include "mockturtle/views/binding_view.hpp"
#include "mockturtle/views/mapping_view.hpp"
#include "mockturtle/io/genlib_reader.hpp"
#include "mockturtle/utils/tech_library.hpp"

#include <vector>
#include <assert.h>
#include <iostream>
#include <memory>

namespace lf
{

namespace logic
{

namespace lsils
{
///////////////////////////////////////////////////////////
//  combinational
///////////////////////////////////////////////////////////
using aig_comb_network = mockturtle::aig_network;
using xag_comb_network = mockturtle::xag_network;
using mig_comb_network = mockturtle::mig_network;
using xmg_comb_network = mockturtle::xmg_network;
using gtg_comb_network = mockturtle::gtg_network;

using klut_comb_network = mockturtle::klut_network;
using blut_comb_network = mockturtle::binding_view<klut_comb_network>;

///////////////////////////////////////////////////////////
//  sequential
///////////////////////////////////////////////////////////
using aig_seq_network = mockturtle::sequential<aig_comb_network>;
using xag_seq_network = mockturtle::sequential<xag_comb_network>;
using mig_seq_network = mockturtle::sequential<mig_comb_network>;
using xmg_seq_network = mockturtle::sequential<xmg_comb_network>;
using gtg_seq_network = mockturtle::sequential<gtg_comb_network>;

using klut_seq_network = mockturtle::sequential<klut_comb_network>;
using blut_seq_network = mockturtle::binding_view<klut_seq_network>;

///////////////////////////////////////////////////////////
//  library
///////////////////////////////////////////////////////////
using lib_gates = std::vector<mockturtle::gate>;
using lib_techlib_np = mockturtle::tech_library<6u, mockturtle::classification_type::np_configurations>;

/**
 * @brief struct Lsils_Frame_t
 *  it stores all the networks and the libraries
 */
struct Lsils_Frame_t
{
  // technology-independent network
  aig_seq_network curr_aig;
  xag_seq_network curr_xag;
  mig_seq_network curr_mig;
  xmg_seq_network curr_xmg;
  gtg_seq_network curr_gtg;

  // technology-dependent netlist
  blut_seq_network netlist_asic;
  klut_seq_network netlist_fpga;

  // technology-dependent library
  lib_gates gates;
};

} // namespace lsils

} // namespace logic

} // namespace lf