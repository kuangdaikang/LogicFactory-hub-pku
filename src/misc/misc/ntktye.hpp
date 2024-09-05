#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <assert.h>

// logic network type instance
#define lfLntINST lf::misc::LogicNtkType::get_instance()

namespace lf
{

namespace misc
{

/**
 * @brief the ntktype is used to break the conflict of the template operation on the Boolean network
 * @note
 */
enum E_LF_NTK_TYPE
{
  E_LF_NTK_TYPE_NONE = 0,
  // ntk type of abc
  E_LF_NTK_TYPE_ABC_LOGIC_AIG,
  E_LF_NTK_TYPE_ABC_LOGIC_SOP,
  E_LF_NTK_TYPE_ABC_LOGIC_BDD,
  E_LF_NTK_TYPE_ABC_LOGIC_FPGA,
  E_LF_NTK_TYPE_ABC_LOGIC_ASIC,
  E_LF_NTK_TYPE_ABC_STRASH_AIG,
  E_LF_NTK_TYPE_ABC_NETLIST_FPGA,
  E_LF_NTK_TYPE_ABC_NETLIST_ASIC,
  // ntk type of lsils
  E_LF_NTK_TYPE_LSILS_LOGIC_AIG,
  E_LF_NTK_TYPE_LSILS_LOGIC_OIG,
  E_LF_NTK_TYPE_LSILS_LOGIC_AOG,
  E_LF_NTK_TYPE_LSILS_LOGIC_XAG,
  E_LF_NTK_TYPE_LSILS_LOGIC_XOG,
  E_LF_NTK_TYPE_LSILS_LOGIC_MIG,
  E_LF_NTK_TYPE_LSILS_LOGIC_XMG,
  E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY,
  E_LF_NTK_TYPE_LSILS_LOGIC_GTG,
  E_LF_NTK_TYPE_LSILS_LOGIC_CVG,
  E_LF_NTK_TYPE_LSILS_LOGIC_BLG,
  E_LF_NTK_TYPE_LSILS_LOGIC_FPGA,
  E_LF_NTK_TYPE_LSILS_LOGIC_ASIC,
  E_LF_NTK_TYPE_LSILS_STRASH_AIG,
  E_LF_NTK_TYPE_LSILS_STRASH_OIG,
  E_LF_NTK_TYPE_LSILS_STRASH_AOG,
  E_LF_NTK_TYPE_LSILS_STRASH_XAG,
  E_LF_NTK_TYPE_LSILS_STRASH_XOG,
  E_LF_NTK_TYPE_LSILS_STRASH_MIG,
  E_LF_NTK_TYPE_LSILS_STRASH_XMG,
  E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY,
  E_LF_NTK_TYPE_LSILS_STRASH_GTG,
  E_LF_NTK_TYPE_LSILS_NETLIST_FPGA,
  E_LF_NTK_TYPE_LSILS_NETLIST_ASIC,
}; // enum E_LF_NTK_TYPE

/**
 * @class
 * @brief
 */
class LogicNtkType
{
public:
  static LogicNtkType* get_instance()
  {
    if ( instance_ == nullptr )
    {
      instance_ = new LogicNtkType;
    }
    return instance_;
  }

  /**
   * @brief generate the network type: tool + stat + type}
   * @note
   * @param tool  which tool to use
   * @note the space of tool
   *      abc
   *      lsils
   * @param stat  the status of the network
   * @note the space of stat
   *      logic
   *      strash
   *      netlist
   * @param type the type of the network
   * @note the space of type
   *      aig
   *      oig
   *      aog
   *      xag
   *      xog
   *      mig
   *      xmg
   *      primary
   *      gtg
   *      cvg
   *      blg
   *      sop
   *      bdd
   *      fpga
   *      asic
   * @return
   */
  E_LF_NTK_TYPE gen_ntktype( const std::string& tool, const std::string& stat, const std::string& type )
  {
    static const std::unordered_map<std::string, E_LF_NTK_TYPE> type_map = {
        { "abc_logic_aig", E_LF_NTK_TYPE_ABC_LOGIC_AIG },
        { "abc_logic_sop", E_LF_NTK_TYPE_ABC_LOGIC_SOP },
        { "abc_logic_bdd", E_LF_NTK_TYPE_ABC_LOGIC_BDD },
        { "abc_logic_fpga", E_LF_NTK_TYPE_ABC_LOGIC_FPGA },
        { "abc_logic_asic", E_LF_NTK_TYPE_ABC_LOGIC_ASIC },
        { "abc_strash_aig", E_LF_NTK_TYPE_ABC_STRASH_AIG },
        { "abc_netlist_fpga", E_LF_NTK_TYPE_ABC_NETLIST_FPGA },
        { "abc_netlist_asic", E_LF_NTK_TYPE_ABC_NETLIST_ASIC },
        { "lsils_logic_aig", E_LF_NTK_TYPE_LSILS_LOGIC_AIG },
        { "lsils_logic_oig", E_LF_NTK_TYPE_LSILS_LOGIC_OIG },
        { "lsils_logic_aog", E_LF_NTK_TYPE_LSILS_LOGIC_AOG },
        { "lsils_logic_xag", E_LF_NTK_TYPE_LSILS_LOGIC_XAG },
        { "lsils_logic_xog", E_LF_NTK_TYPE_LSILS_LOGIC_XOG },
        { "lsils_logic_mig", E_LF_NTK_TYPE_LSILS_LOGIC_MIG },
        { "lsils_logic_xmg", E_LF_NTK_TYPE_LSILS_LOGIC_XMG },
        { "lsils_logic_primary", E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY },
        { "lsils_logic_gtg", E_LF_NTK_TYPE_LSILS_LOGIC_GTG },
        { "lsils_logic_cvg", E_LF_NTK_TYPE_LSILS_LOGIC_CVG },
        { "lsils_logic_blg", E_LF_NTK_TYPE_LSILS_LOGIC_BLG },
        { "lsils_logic_fpga", E_LF_NTK_TYPE_LSILS_LOGIC_FPGA },
        { "lsils_logic_asic", E_LF_NTK_TYPE_LSILS_LOGIC_ASIC },
        { "lsils_strash_aig", E_LF_NTK_TYPE_LSILS_STRASH_AIG },
        { "lsils_strash_oig", E_LF_NTK_TYPE_LSILS_STRASH_OIG },
        { "lsils_strash_aog", E_LF_NTK_TYPE_LSILS_STRASH_AOG },
        { "lsils_strash_xag", E_LF_NTK_TYPE_LSILS_STRASH_XAG },
        { "lsils_strash_xog", E_LF_NTK_TYPE_LSILS_STRASH_XOG },
        { "lsils_strash_mig", E_LF_NTK_TYPE_LSILS_STRASH_MIG },
        { "lsils_strash_xmg", E_LF_NTK_TYPE_LSILS_STRASH_XMG },
        { "lsils_strash_primary", E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY },
        { "lsils_strash_gtg", E_LF_NTK_TYPE_LSILS_STRASH_GTG },
        { "lsils_netlist_fpga", E_LF_NTK_TYPE_LSILS_NETLIST_FPGA },
        { "lsils_netlist_asic", E_LF_NTK_TYPE_LSILS_NETLIST_ASIC } };

    std::string key = tool + "_" + stat + "_" + type;
    auto it = type_map.find( key );
    if ( it != type_map.end() )
    {
      return it->second;
    }
    else
    {
      std::cerr << "Unhandled logic network type provided:\"" << key << "\"" << std::endl;
      assert( false );
      return E_LF_NTK_TYPE_NONE;
    }
  }

  void set_ntktype( E_LF_NTK_TYPE ntktype )
  {
    if ( ntktype == ntktype_curr_ ) // no need to update the ntktype
      return;
    ntktype_prev_ = ntktype_curr_;
    ntktype_curr_ = ntktype;
  }

  void set_ntktype( const std::string& tool, const std::string& type, const std::string& ntk )
  {
    auto ntktype = gen_ntktype( tool, type, ntk );
    if ( ntktype != E_LF_NTK_TYPE_NONE )
    {
      set_ntktype( ntktype );
    }
    else
    {
      std::cerr << "Unhandled logic network type provided." << std::endl;
      assert( false );
    }
  }

  E_LF_NTK_TYPE get_ntktype_prev() const { return ntktype_prev_; }
  E_LF_NTK_TYPE get_ntktype_curr() const { return ntktype_curr_; }

private:
  LogicNtkType() = default;
  ~LogicNtkType() = default;
  LogicNtkType( const LogicNtkType& ) = delete;
  LogicNtkType& operator=( const LogicNtkType& ) = delete;

private:
  static LogicNtkType* instance_;
  E_LF_NTK_TYPE ntktype_prev_{ E_LF_NTK_TYPE_NONE };
  E_LF_NTK_TYPE ntktype_curr_{ E_LF_NTK_TYPE_NONE };
}; // class LogicNtkType

LogicNtkType* LogicNtkType::instance_ = nullptr;

} // namespace misc

} // end namespace lf