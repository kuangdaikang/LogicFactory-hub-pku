#pragma once

namespace lf
{

namespace misc
{

/**
 * @brief
 */
enum class E_LF_ANCHOR
{
  E_LF_ANCHOR_NONE = 0,
  E_LF_ANCHOR_INIT,
  ////////////////////////////////////////////////////
  // architecture steps
  ////////////////////////////////////////////////////
  // YOSYS
  E_LF_ANCHOR_ARCH_YOSYS_NONE,
  E_LF_ANCHOR_ARCH_YOSYS_INIT,
  E_LF_ANCHOR_ARCH_YOSYS_NTK_NONE,         // unused
  E_LF_ANCHOR_ARCH_YOSYS_NTK_ARCH_AST,     // ast analysis
  E_LF_ANCHOR_ARCH_YOSYS_NTK_ARCH_RTLIR,   // intermediate representation
  E_LF_ANCHOR_ARCH_YOSYS_NTK_LOGIC_AIG,    // aig_map
  E_LF_ANCHOR_ARCH_YOSYS_NTK_NETLIST_FPGA, // fpga technology mapping
  E_LF_ANCHOR_ARCH_YOSYS_NTK_NETLIST_ASIC, // asic technology mapping

  ////////////////////////////////////////////////////
  // logic steps
  ////////////////////////////////////////////////////
  // ABC
  E_LF_ANCHOR_LOGIC_ABC_NONE,
  E_LF_ANCHOR_LOGIC_ABC_INIT,
  E_LF_ANCHOR_LOGIC_ABC_NTK_NONE,      // unused
  E_LF_ANCHOR_LOGIC_ABC_NTK_LOGIC_SOP, // logic graphs
  E_LF_ANCHOR_LOGIC_ABC_NTK_LOGIC_BDD,
  E_LF_ANCHOR_LOGIC_ABC_NTK_LOGIC_AIG,
  E_LF_ANCHOR_LOGIC_ABC_NTK_LOGIC_FPGA,
  E_LF_ANCHOR_LOGIC_ABC_NTK_LOGIC_ASIC,
  E_LF_ANCHOR_LOGIC_ABC_NTK_STRASH_AIG,  // structure hash into AIG
  E_LF_ANCHOR_LOGIC_ABC_NTK_NETLIST_SOP, // netlist graphs
  E_LF_ANCHOR_LOGIC_ABC_NTK_NETLIST_AIG,
  E_LF_ANCHOR_LOGIC_ABC_NTK_NETLIST_FPGA,
  E_LF_ANCHOR_LOGIC_ABC_NTK_NETLIST_ASIC,
  // LSILS
  E_LF_ANCHOR_LOGIC_LSILS_NONE,
  E_LF_ANCHOR_LOGIC_LSILS_INIT,
  E_LF_ANCHOR_LOGIC_LSILS_NTK_NONE,         // unused
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_CVG,    // Cover Graph  , each node is a boolean function
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG,    // And-Inverter Graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG,    // Xor-And Graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG,    // Majority-Inverter Graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG,    // Xor3-Majority3 Graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG,    // GTech Graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_COVER_KLUT,   // k-LUT graph
  E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_FPGA, // FPGA netlist
  E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_ASIC, // ASIC netlist graph

  ////////////////////////////////////////////////////
  // netlist steps
  ////////////////////////////////////////////////////
  // iEDA
  E_LF_ANCHOR_NETLIST_IEDA_NONE,
  E_LF_ANCHOR_NETLIST_IEDA_INIT,
  E_LF_ANCHOR_NETLIST_IEDA_STA,
  E_LF_ANCHOR_NETLIST_IEDA_FLOORPLAN,
  E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT,
  E_LF_ANCHOR_NETLIST_IEDA_CTS,
  E_LF_ANCHOR_NETLIST_IEDA_ROUTING
};

#define lfAnchorINST lf::misc::LfAnchor::get_instance()

/**
 * @brief
 */
class LfAnchor
{
public:
  static LfAnchor* get_instance()
  {
    if ( instance_ == nullptr )
    {
      instance_ = new LfAnchor;
    }
    return instance_;
  }

  void set_anchor( E_LF_ANCHOR anchor )
  {
    anchor_prev_ = anchor_curr_;
    anchor_curr_ = anchor;
  }

  E_LF_ANCHOR get_anchor_prev() const { return anchor_prev_; }
  E_LF_ANCHOR get_anchor() const { return anchor_curr_; }
  E_LF_ANCHOR get_anchor_curr() const { return anchor_curr_; }

private:
  LfAnchor() = default;
  ~LfAnchor() = default;
  LfAnchor( const LfAnchor& ) = delete;
  LfAnchor& operator=( const LfAnchor& ) = delete;

private:
  static LfAnchor* instance_;
  E_LF_ANCHOR anchor_prev_{ E_LF_ANCHOR::E_LF_ANCHOR_NONE };
  E_LF_ANCHOR anchor_curr_{ E_LF_ANCHOR::E_LF_ANCHOR_NONE };
}; // class LfAnchor

LfAnchor* LfAnchor::instance_ = nullptr;

} // namespace misc
} // namespace lf