#pragma once

#include "layer_logic/logic_manager.hpp"

#include "idm.h"
#include "builder.h"

namespace lf
{

namespace netlist
{

enum class E_ToolNetlistAsicType
{
  E_NETLIST_Asic_iEDA_init,
  E_NETLIST_Asic_iEDA_sta,
  E_NETLIST_Asic_iEDA_fp,
  E_NETLIST_Asic_iEDA_cts,
  E_NETLIST_Asic_iEDA_place,
  E_NETLIST_Asic_iEDA_route,
  E_NETLIST_Asic_iEDA_drc
};

/**
 * @class NetlistAsicManager
 * @brief
 *
 * @code
 */
class NetlistAsicManager
{
public:
  NetlistAsicManager( lf::logic::LogicManager const& logic_manager )
      : logic_manager_( logic_manager ),
        idb_builder_( nullptr ),
        netlist_step_prev_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init ),
        netlist_step_curr_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init )
  {
  }

  NetlistAsicManager( const NetlistAsicManager& ) = delete;
  NetlistAsicManager& operator=( const NetlistAsicManager& ) = delete;
  ~NetlistAsicManager() = default;

  void start()
  {
    idb_builder_ = dmInst->get_idb_builder();
  }

  void stop()
  {
  }

  /**
   * @brief
   */
  void update_netlist( E_ToolNetlistAsicType netlist_step )
  {
    netlist_step_prev_ = netlist_step_curr_;
    netlist_step_curr_ = netlist_step;
  }

  /**
   * @brief
   */
  template<typename T>
  T current()
  {
    if constexpr ( std::is_same_v<T, idb::IdbBuilder*> )
    {
      return idb_builder_;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
      return nullptr;
    }
  }

  /**
   * @brief
   */
  template<typename T>
  void set_current( T obj )
  {
    if constexpr ( std::is_same_v<T, idb::IdbBuilder*> )
    {
      idb_builder_ = obj;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
      return nullptr;
    }
  }

private:
  const lf::logic::LogicManager& logic_manager_;

  idb::IdbBuilder* idb_builder_ = nullptr;
  E_ToolNetlistAsicType netlist_step_prev_;
  E_ToolNetlistAsicType netlist_step_curr_;
}; // class NelistAsicManager

enum class E_ToolNetlistFpgaType
{
  E_NETLIST_Fpga_VPR_init,
  E_NETLIST_Fpga_VPR_place,
  E_NETLIST_Fpga_VPR_route,
  E_NETLIST_Fpga_VPR_bitstream
};

} // namespace netlist

} // namespace lf