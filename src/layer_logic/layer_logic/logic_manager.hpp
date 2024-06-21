#pragma once
#include "layer_logic/op/convert.hpp"

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"

#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/main/abcapis.h"
#include "base/abc/abc.h"
#include "base/main/main.h"

#include <assert.h>
#include <iostream>
#include <memory>
#include <variant>

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
      : logic_type_prev_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG ),
        logic_type_curr_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG ),
        ntk_abc_aig_( babc::Abc_FrameGetGlobalFrame() )
  {
  }

  LogicManager( const LogicManager& ) = delete;
  LogicManager& operator=( const LogicManager& ) = delete;
  ~LogicManager() = default;

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
      // TODO: just save the pointer is fine
      return;
    }
    // condition2: different logic type
    else
    {
      using NtkIR = mockturtle::aig_network;
      NtkIR ntk;
      babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( ntk_abc_aig_ );

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
        ntk = lf::logic::convert_lsils_internal<NtkIR, mockturtle::aig_network>( *ntk_mt_aig_ );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, mockturtle::xag_network>( *ntk_mt_xag_ );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, mockturtle::mig_network>( *ntk_mt_mig_ );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, mockturtle::xmg_network>( *ntk_mt_xmg_ );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
      {
        ntk = lf::logic::convert_lsils_internal<NtkIR, mockturtle::gtg_network>( *ntk_mt_gtg_ );
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
        *pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
        babc::Abc_FrameSetCurrentNetwork( ntk_abc_aig_, pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_ABC_GIA:
      {
        *pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
        babc::Abc_FrameSetCurrentNetwork( ntk_abc_aig_, pNtk );
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG:
      {
        auto tNtk3 = lf::logic::convert_lsils_internal<mockturtle::aig_network, NtkIR>( ntk );
        ntk_mt_aig_ = &tNtk3;
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
      {
        auto tNtk4 = lf::logic::convert_lsils_internal<mockturtle::xag_network, NtkIR>( ntk );
        ntk_mt_xag_ = &tNtk4;
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
      {
        auto tNtk5 = lf::logic::convert_lsils_internal<mockturtle::mig_network, NtkIR>( ntk );
        ntk_mt_mig_ = &tNtk5;
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
      {
        auto tNtk6 = lf::logic::convert_lsils_internal<mockturtle::xmg_network, NtkIR>( ntk );
        ntk_mt_xmg_ = &tNtk6;
        break;
      }
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
      {
        auto tNtk7 = lf::logic::convert_lsils_internal<mockturtle::gtg_network, NtkIR>( ntk );
        ntk_mt_gtg_ = &tNtk7;
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
   * @tparam Ntk current network type
   * @return ntk
   */
  template<typename Ntk>
  Ntk* current()
  {
    auto ptr = std::get_if<Ntk*>( &current_ntk_ );
    if ( !ptr )
    {
      std::cerr << "Requested network type is not currently stored." << std::endl;
      return nullptr;
    }
    return *ptr;
  }

  template<typename Ntk>
  void set_current( Ntk* ntk_ptr )
  {
    if ( !ntk_ptr )
    {
      throw std::invalid_argument( "ntk_ptr is nullptr" );
    }

    current_ntk_ = ntk_ptr;

    using NtkBase = typename Ntk::base_type;
    // Update specific network pointer based on the type of Ntk
    if constexpr ( std::is_same_v<Ntk, babc::Abc_Frame_t> )
    {
      ntk_abc_aig_ = ntk_ptr;
    }
    else if constexpr ( std::is_same_v<NtkBase, mockturtle::aig_network> )
    {
      ntk_mt_aig_ = ntk_ptr;
    }
    else if constexpr ( std::is_same_v<NtkBase, mockturtle::xag_network> )
    {
      ntk_mt_xag_ = ntk_ptr;
    }
    else if constexpr ( std::is_same_v<NtkBase, mockturtle::mig_network> )
    {
      ntk_mt_mig_ = ntk_ptr;
    }
    else if constexpr ( std::is_same_v<NtkBase, mockturtle::xmg_network> )
    {
      ntk_mt_xmg_ = ntk_ptr;
    }
    else if constexpr ( std::is_same_v<NtkBase, mockturtle::gtg_network> )
    {
      ntk_mt_gtg_ = ntk_ptr;
    }
    else
    {
      std::cerr << "Unhandled network type provided." << std::endl;
      assert( false );
    }
  }

private:
  E_ToolLogicType logic_type_prev_;
  E_ToolLogicType logic_type_curr_;

  std::variant<babc::Abc_Frame_t*,
               mockturtle::aig_network*,
               mockturtle::xag_network*,
               mockturtle::mig_network*,
               mockturtle::xmg_network*,
               mockturtle::gtg_network*>
      current_ntk_; // store the current network

  babc::Abc_Frame_t* ntk_abc_aig_ = nullptr;
  mockturtle::aig_network* ntk_mt_aig_ = nullptr;
  mockturtle::xag_network* ntk_mt_xag_ = nullptr;
  mockturtle::mig_network* ntk_mt_mig_ = nullptr;
  mockturtle::xmg_network* ntk_mt_xmg_ = nullptr;
  mockturtle::gtg_network* ntk_mt_gtg_ = nullptr;
};

} // end namespace logic

} // end namespace lf