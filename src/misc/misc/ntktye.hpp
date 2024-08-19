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
 * @brief
 * @note
 *  LOGIC   :
 *  STRASH  : optimization and technolgoy mapping
 *  NETLIST :
 */
enum E_LF_LOGIC_NTK_TYPE
{
  E_LF_LOGIC_NTK_TYPE_NONE = 0,
  E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG,
  E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_SOP,
  E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_BDD,
  E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_FPGA,
  E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_ASIC,
  E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG,
  E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_SOP,
  E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_AIG,
  E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_FPGA,
  E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_ASIC,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_CVG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_BLG,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_FPGA,
  E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_ASIC,
  E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG,
  E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG,
  E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG,
  E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG,
  E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG,
  E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA,
  E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC,
}; // enum E_LF_LOGIC_NTK_TYPE

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

  void set_ntktype( E_LF_LOGIC_NTK_TYPE ntktype )
  {
    ntktype_prev_ = ntktype_curr_;
    ntktype_curr_ = ntktype;
  }

  void set_ntktype( const std::string& tool, const std::string& type, const std::string& ntk )
  {
    static const std::unordered_map<std::string, E_LF_LOGIC_NTK_TYPE> type_map = {
        { "abc_logic_aig", E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG },
        { "abc_logic_sop", E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_SOP },
        { "abc_logic_bdd", E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_BDD },
        { "abc_logic_fpga", E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_FPGA },
        { "abc_logic_asic", E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_ASIC },
        { "abc_strash_aig", E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG },
        { "abc_netlist_fpga", E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_FPGA },
        { "abc_netlist_asic", E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_ASIC },
        { "lsils_logic_aig", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG },
        { "lsils_logic_xag", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG },
        { "lsils_logic_mig", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG },
        { "lsils_logic_xmg", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG },
        { "lsils_logic_gtg", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG },
        { "lsils_logic_cvg", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_CVG },
        { "lsils_logic_fpga", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_FPGA },
        { "lsils_logic_asic", E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_ASIC },
        { "lsils_strash_aig", E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG },
        { "lsils_strash_xag", E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG },
        { "lsils_strash_mig", E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG },
        { "lsils_strash_xmg", E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG },
        { "lsils_strash_gtg", E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG },
        { "lsils_netlist_fpga", E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA },
        { "lsils_netlist_asic", E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC } };

    std::string key = tool + "_" + type + "_" + ntk;
    auto it = type_map.find( key );
    if ( it != type_map.end() )
    {
      set_ntktype( it->second );
    }
    else
    {
      std::cerr << "Unhandled logic network type provided." << std::endl;
      assert( false );
    }
  }

  E_LF_LOGIC_NTK_TYPE get_ntktype_prev() const { return ntktype_prev_; }
  E_LF_LOGIC_NTK_TYPE get_ntktype_curr() const { return ntktype_curr_; }

private:
  LogicNtkType() = default;
  ~LogicNtkType() = default;
  LogicNtkType( const LogicNtkType& ) = delete;
  LogicNtkType& operator=( const LogicNtkType& ) = delete;

private:
  static LogicNtkType* instance_;
  E_LF_LOGIC_NTK_TYPE ntktype_prev_{ E_LF_LOGIC_NTK_TYPE_NONE };
  E_LF_LOGIC_NTK_TYPE ntktype_curr_{ E_LF_LOGIC_NTK_TYPE_NONE };
}; // class LogicNtkType

LogicNtkType* LogicNtkType::instance_ = nullptr;

} // namespace misc

} // end namespace lf