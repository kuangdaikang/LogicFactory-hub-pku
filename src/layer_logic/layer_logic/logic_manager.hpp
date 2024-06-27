#pragma once

/////////////////////////////////////////////
//  abc header
/////////////////////////////////////////////
#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/main/abcapis.h"
#include "base/abc/abc.h"
#include "base/main/main.h"

/////////////////////////////////////////////
//  misc functions
/////////////////////////////////////////////
#include "layer_logic/op/convert.hpp"

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xmg.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/klut.hpp"

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

namespace lf
{

namespace logic
{

enum class E_ToolLogicType
{
  E_LOGIC_ABC_AIG,
  E_LOGIC_ABC_GIA,
  E_LOGIC_MOCKTURTLE_AIG,
  E_LOGIC_MOCKTURTLE_XAG,
  E_LOGIC_MOCKTURTLE_MIG,
  E_LOGIC_MOCKTURTLE_XMG,
  E_LOGIC_MOCKTURTLE_GTG,
  E_LOGIC_IMAP_AIG,
};

/**
 * @class LogicManager
 * @brief manager the logic type for the logic tools, also it namanger all the list netowrks
 *
 * @code
 *
 */
class LogicManager
{
public:
  LogicManager()
      : logic_type_prev_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG ),
        logic_type_curr_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG )
  {
  }

  LogicManager( const LogicManager& ) = delete;
  LogicManager& operator=( const LogicManager& ) = delete;
  ~LogicManager() = default;

  void start()
  {
    babc::Abc_Start();
    frame_abc_ = babc::Abc_FrameGetGlobalFrame();
  }

  void stop()
  {
    babc::Abc_Stop();
  }

  /**
   * @brief set the current logic type, and transform the data strcuture to the current logic type
   * @param logic_type
   * @code
   *  LogicManager manager;
   *  manager.update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );        // set the logic type to E_LOGIC_ABC_AIG
   *  manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG ); // set the logic type to E_LOGIC_MOCKTURTLE_AIG
   * @endcode
   *
   */
  void update_logic( E_ToolLogicType logic_type )
  {

    /// update the logic status
    logic_type_prev_ = logic_type_curr_;
    logic_type_curr_ = logic_type;

    /// adapt the data strcuture if needed
    // condition1: same logic type
    if ( logic_type_prev_ == logic_type_curr_ )
    {
      return;
    }
    // condition2: different logic type
    else
    {
      using NtkIR = lsils::aig_seq_network;
      NtkIR ntk;
      babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( frame_abc_ );

      // step1:  previous logic-based data structure -> IR
      switch ( logic_type_prev_ )
      {
      case E_ToolLogicType::E_LOGIC_ABC_AIG:
      {
        ntk = lf::logic::convert_abc_2_lsils<NtkIR>( pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_ABC_GIA:
      {
        ntk = lf::logic::convert_abc_2_lsils<NtkIR>( pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::aig_seq_network>( frame_lsils_.curr_aig );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xag_seq_network>( frame_lsils_.curr_xag );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::mig_seq_network>( frame_lsils_.curr_mig );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xmg_seq_network>( frame_lsils_.curr_xmg );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::gtg_seq_network>( frame_lsils_.curr_gtg );
        break;
      }
      // case E_ToolLogicType::E_LOGIC_IMAP_AIG:
      //   ntk = lf::logic::convert_lsils_internal<NtkIR, imap::aig_network>( *ntk_mt_aig_ );
      //   break;
      default:
      {
        assert( false );
        break;
      }
      }

      // step2:  IR -> current logic-based data structure
      switch ( logic_type_curr_ )
      {
      case E_ToolLogicType::E_LOGIC_ABC_AIG:
      {
        pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
        babc::Abc_FrameSetCurrentNetwork( frame_abc_, pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_ABC_GIA:
      {
        pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
        babc::Abc_FrameSetCurrentNetwork( frame_abc_, pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG:
      {
        frame_lsils_.curr_aig = lf::logic::convert_lsils_internal<lsils::aig_seq_network, NtkIR>( ntk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
      {
        frame_lsils_.curr_xag = lf::logic::convert_lsils_internal<lsils::xag_seq_network, NtkIR>( ntk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
      {
        frame_lsils_.curr_mig = lf::logic::convert_lsils_internal<lsils::mig_seq_network, NtkIR>( ntk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
      {
        frame_lsils_.curr_xmg = lf::logic::convert_lsils_internal<lsils::xmg_seq_network, NtkIR>( ntk );

        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
      {
        frame_lsils_.curr_gtg = lf::logic::convert_lsils_internal<lsils::gtg_seq_network, NtkIR>( ntk );
        break;
      }
      // case E_ToolLogicType::E_LOGIC_IMAP_AIG:
      //   imap::aig_network tNtk = lf::logic::convert_lsils_internal<imap::aig_network, NtkIR>( ntk );
      //   ntk_mt_aig_ = &tNtk;
      //   break;
      default:
      {
        assert( false );
        break;
      }
      }
    }
  }

  /**
   * @brief get the current network for the given type
   * @tparam T current network type
   * @return ntk
   */
  template<typename T>
  T current()
  {
    if constexpr ( std::is_same_v<T, babc::Abc_Frame_t*> )
    {
      return frame_abc_;
    }
    else if constexpr ( std::is_same_v<T, lsils::Lsils_Frame_t> )
    {
      return frame_lsils_;
    }
    else if constexpr ( std::is_same_v<T, lsils::aig_seq_network> )
    {
      return frame_lsils_.curr_aig;
    }
    else if constexpr ( std::is_same_v<T, lsils::xag_seq_network> )
    {
      return frame_lsils_.curr_xag;
    }
    else if constexpr ( std::is_same_v<T, lsils::mig_seq_network> )
    {
      return frame_lsils_.curr_mig;
    }
    else if constexpr ( std::is_same_v<T, lsils::xmg_seq_network> )
    {
      return frame_lsils_.curr_xmg;
    }
    else if constexpr ( std::is_same_v<T, lsils::gtg_seq_network> )
    {
      return frame_lsils_.curr_gtg;
    }
    else if constexpr ( std::is_same_v<T, lsils::blut_seq_network> )
    {
      return frame_lsils_.netlist_asic;
    }
    else if constexpr ( std::is_same_v<T, lsils::klut_seq_network> )
    {
      return frame_lsils_.netlist_fpga;
    }
    else if constexpr ( std::is_same_v<T, lsils::lib_gates> )
    {
      return frame_lsils_.gates;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
      return nullptr;
    }
  }

  template<typename T>
  void set_current( T obj )
  {
    // Update specific network pointer based on the type of T
    if constexpr ( std::is_same_v<T, lsils::Lsils_Frame_t> )
    {
      frame_lsils_ = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::aig_seq_network> )
    {
      frame_lsils_.curr_aig = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::xag_seq_network> )
    {
      frame_lsils_.curr_xag = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::mig_seq_network> )
    {
      frame_lsils_.curr_mig = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::xmg_seq_network> )
    {
      frame_lsils_.curr_xmg = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::gtg_seq_network> )
    {
      frame_lsils_.curr_gtg = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::blut_seq_network> )
    {
      frame_lsils_.netlist_asic = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::klut_seq_network> )
    {
      frame_lsils_.netlist_fpga = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::lib_gates> )
    {
      frame_lsils_.gates = obj;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
    }
  }

private:
  babc::Abc_Frame_t* frame_abc_ = nullptr;
  lsils::Lsils_Frame_t frame_lsils_;

  E_ToolLogicType logic_type_prev_;
  E_ToolLogicType logic_type_curr_;
};

} // end namespace logic

} // end namespace lf