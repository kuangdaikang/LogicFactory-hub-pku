#pragma once

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xmg.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/klut.hpp"

#include "mockturtle/io/aiger_reader.hpp"
#include "mockturtle/io/bench_reader.hpp"
#include "mockturtle/io/blif_reader.hpp"
#include "mockturtle/io/dimacs_reader.hpp"
#include "mockturtle/io/genlib_reader.hpp"
#include "mockturtle/io/pla_reader.hpp"
#include "mockturtle/io/verilog_reader.hpp"
#include "mockturtle/io/bristol_reader.hpp"
#include "mockturtle/io/super_reader.hpp"

#include "mockturtle/io/write_aiger.hpp"
#include "mockturtle/io/write_bench.hpp"
#include "mockturtle/io/write_blif.hpp"
#include "mockturtle/io/write_dimacs.hpp"
#include "mockturtle/io/write_dot.hpp"
#include "mockturtle/io/write_genlib.hpp"
#include "mockturtle/io/write_patterns.hpp"
#include "mockturtle/io/write_verilog.hpp"

#include "mockturtle/networks/sequential.hpp"
#include "mockturtle/views/binding_view.hpp"
#include "mockturtle/views/mapping_view.hpp"
#include "mockturtle/utils/tech_library.hpp"

// balance
#include "mockturtle/algorithms/balancing.hpp"
#include "mockturtle/algorithms/balancing/sop_balancing.hpp"
#include "mockturtle/algorithms/aig_balancing.hpp"
#include "mockturtle/algorithms/xag_balancing.hpp"

// rewrite
#include "mockturtle/algorithms/node_resynthesis.hpp"
#include "mockturtle/algorithms/rewrite.hpp"
#include "mockturtle/algorithms/cut_rewriting.hpp"
#include "mockturtle/algorithms/mig_algebraic_rewriting.hpp"
#include "mockturtle/algorithms/xag_algebraic_rewriting.hpp"
#include "mockturtle/algorithms/xmg_algebraic_rewriting.hpp"
#include "mockturtle/algorithms/window_rewriting.hpp"

// refactor
#include "mockturtle/algorithms/refactoring.hpp"

// resubstitution
#include "mockturtle/algorithms/resubstitution.hpp"
#include "mockturtle/algorithms/aig_resub.hpp"
#include "mockturtle/algorithms/mig_resub.hpp"
#include "mockturtle/algorithms/xmg_resub.hpp"
#include "mockturtle/algorithms/xag_resub_withDC.hpp"

// technology mapping
#include "mockturtle/algorithms/cut_enumeration.hpp"
#include "mockturtle/algorithms/lut_mapper.hpp"
#include "mockturtle/algorithms/lut_mapping.hpp"
#include "mockturtle/algorithms/satlut_mapping.hpp"
#include "mockturtle/algorithms/mapper.hpp"

#include "mockturtle/algorithms/circuit_validator.hpp"
#include "mockturtle/algorithms/cleanup.hpp
#include "mockturtle/algorithms/cnf.hpp
#include "mockturtle/algorithms/dont_cares.hpp"

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

  // flag the storage of the ntks
  bool has_logic_aig{ false };
  bool has_logic_xag{ false };
  bool has_logic_mig{ false };
  bool has_logic_xmg{ false };
  bool has_logic_gtg{ false };
  bool has_libs{ false };
  bool has_netlist_asic{ false };
  bool has_netlist_fpga{ false };
};

} // namespace lsils

} // namespace logic

} // namespace lf