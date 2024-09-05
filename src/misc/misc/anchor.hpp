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
  E_LF_ANCHOR_ARCH_INIT,
  // YOSYS
  E_LF_ANCHOR_ARCH_YOSYS_NONE, // unused
  E_LF_ANCHOR_ARCH_YOSYS_INIT,
  E_LF_ANCHOR_ARCH_YOSYS_AST,     // preproc
  E_LF_ANCHOR_ARCH_YOSYS_LOGIC,   // aigmap / techmap / simplemap
  E_LF_ANCHOR_ARCH_YOSYS_NETLIST, // technology mapping

  ////////////////////////////////////////////////////
  // logic steps
  ////////////////////////////////////////////////////
  E_LF_ANCHOR_LOGIC_INIT,
  // ABC
  E_LF_ANCHOR_LOGIC_ABC_NONE, // unused
  E_LF_ANCHOR_LOGIC_ABC_INIT,
  E_LF_ANCHOR_LOGIC_ABC_LOGIC,  // logic graphs
  E_LF_ANCHOR_LOGIC_ABC_STRASH, // structure hash into AIG
  E_LF_ANCHOR_LOGIC_ABC_NETLIST,
  // LSILS
  E_LF_ANCHOR_LOGIC_LSILS_NONE, // unused
  E_LF_ANCHOR_LOGIC_LSILS_INIT,
  E_LF_ANCHOR_LOGIC_LSILS_LOGIC,   // Cover Graph  , each node is a boolean function
  E_LF_ANCHOR_LOGIC_LSILS_STRASH,  // GTech Graph
  E_LF_ANCHOR_LOGIC_LSILS_NETLIST, // FPGA netlist

  ////////////////////////////////////////////////////
  // netlist steps
  ////////////////////////////////////////////////////
  E_LF_ANCHOR_NETLIST_INIT,
  // iEDA
  E_LF_ANCHOR_NETLIST_IEDA_INIT,
  E_LF_ANCHOR_NETLIST_IEDA_STA,
  E_LF_ANCHOR_NETLIST_IEDA_FLOORPLAN,
  E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT,
  E_LF_ANCHOR_NETLIST_IEDA_CTS,
  E_LF_ANCHOR_NETLIST_IEDA_ROUTING
};

enum class E_LF_ANCHOR_LAYER
{
  E_LF_ANCHOR_LAYER_NONE,
  E_LF_ANCHOR_LAYER_ARCH,
  E_LF_ANCHOR_LAYER_LOGIC,
  E_LF_ANCHOR_LAYER_NETLIST,
};

enum class E_LF_ANCHOR_TOOL
{
  E_LF_ANCHOR_TOOL_NONE,
  E_LF_ANCHOR_TOOL_ARCH_NONE,
  E_LF_ANCHOR_TOOL_ARCH_YOSYS,
  E_LF_ANCHOR_TOOL_LOGIC_NONE,
  E_LF_ANCHOR_TOOL_LOGIC_ABC,
  E_LF_ANCHOR_TOOL_LOGIC_LSILS,
  E_LF_ANCHOR_TOOL_NETLIST_NONE,
  E_LF_ANCHOR_TOOL_NETLIST_IEDA,
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

  /**
   * @brief
   * @param layer
   * @note "arch", "logic", "netlist"
   * @param tool
   * @note "yosys", "abc", "lsils", "ieda"
   * @param stat
   * @note "init", "ast", "logic", "strash", "netlist", "sta", "floorplan", "placement", "cts", "routing"
   * @return
   */
  E_LF_ANCHOR gen_anchor( const std::string& layer, const std::string& tool, const std::string& stat )
  {
    static const std::unordered_map<std::string, E_LF_ANCHOR> type_map = {
        { "arch_yosys_init", E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_INIT },
        { "arch_yosys_ast", E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_AST },
        { "arch_yosys_logic", E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_LOGIC },
        { "arch_yosys_netlist", E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_NETLIST },
        { "logic_abc_init", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_INIT },
        { "logic_abc_logic", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_LOGIC },
        { "logic_abc_strash", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_STRASH },
        { "logic_abc_netlist", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NETLIST },
        { "logic_lsils_init", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_INIT },
        { "logic_lsils_logic", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_LOGIC },
        { "logic_lsils_strash", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_STRASH },
        { "logic_lsils_netlist", E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NETLIST },
        { "netlist_ieda_init", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_INIT },
        { "netlist_ieda_sta", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_STA },
        { "netlist_ieda_floorplan", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_FLOORPLAN },
        { "netlist_ieda_placement", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT },
        { "netlist_ieda_cts", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_CTS },
        { "netlist_ieda_routing", E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_ROUTING } };

    std::string key = layer + "_" + tool + "_" + stat;
    auto it = type_map.find( key );
    if ( it != type_map.end() )
    {
      return it->second;
    }
    else
    {
      std::cerr << "Unhandled anchor type provided:\"" << key << "\"" << std::endl;
      assert( false );
      return E_LF_ANCHOR::E_LF_ANCHOR_NONE;
    }
  }

  void set_anchor( E_LF_ANCHOR anchor )
  {
    anchor_prev_ = anchor_curr_;
    anchor_curr_ = anchor;
  }

  void set_anchor( const std::string& layer, const std::string& tool, const std::string& stat )
  {
    auto anchor = gen_anchor( layer, tool, stat );
    if ( anchor != E_LF_ANCHOR::E_LF_ANCHOR_NONE )
    {
      set_anchor( anchor );
    }
    else
    {
      std::cerr << "Unhandled anchor type provided!" << std::endl;
      assert( false );
    }
  }

  E_LF_ANCHOR_LAYER get_anchor_layer_domain() const
  {
    E_LF_ANCHOR anchor = get_anchor_curr();
    switch ( anchor )
    {
    case E_LF_ANCHOR::E_LF_ANCHOR_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_INIT:
      return E_LF_ANCHOR_LAYER::E_LF_ANCHOR_LAYER_NONE;
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_AST:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_NETLIST:
      return E_LF_ANCHOR_LAYER::E_LF_ANCHOR_LAYER_ARCH;
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_STRASH:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NETLIST:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_STRASH:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NETLIST:
      return E_LF_ANCHOR_LAYER::E_LF_ANCHOR_LAYER_LOGIC;
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_STA:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_FLOORPLAN:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_CTS:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_ROUTING:
      return E_LF_ANCHOR_LAYER::E_LF_ANCHOR_LAYER_NETLIST;
    default:
      assert( false && "Invalid anchor" );
      return E_LF_ANCHOR_LAYER::E_LF_ANCHOR_LAYER_NONE;
    }
  }

  E_LF_ANCHOR_TOOL get_anchor_tool_domain() const
  {
    E_LF_ANCHOR anchor = get_anchor_curr();
    switch ( anchor )
    {
    case E_LF_ANCHOR::E_LF_ANCHOR_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_INIT:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_NONE;
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_INIT:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_ARCH_NONE;
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_AST:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_NETLIST:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_ARCH_YOSYS;
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_INIT:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_NONE;
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_STRASH:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NETLIST:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC;
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NONE:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_LOGIC:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_STRASH:
    case E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NETLIST:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS;
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_INIT:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_NETLIST_NONE;
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_INIT:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_STA:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_FLOORPLAN:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_CTS:
    case E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_ROUTING:
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_NETLIST_IEDA;
    default:
      assert( false && "Invalid anchor" );
      return E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_NONE;
    }
  }

  E_LF_ANCHOR get_anchor_prev() const { return anchor_prev_; }
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