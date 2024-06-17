#pragma once

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"

#ifdef __cplusplus
extern "C"
{
#include "base/abc/abc.h"
#include "base/abci/abc.c"
#include "misc/util/abc_global.h"
#include "misc/util/utilSort.c"
}
#endif

using namespace babc;

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
  LogicManager() : logic_type_prev_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG ), logic_type_curr_( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG ) {} // Default tool
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
      // step1:  previous logic-based data structure -> IR
      switch ( logic_type_prev_ )
      {
      case E_ToolLogicType::E_LOGIC_ABC_AIG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_ABC_AIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_ABC_GIA:
        /* code */
        std::cout << "previous logic type is E_LOGIC_ABC_GIA\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_MOCKTURTLE_AIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_MOCKTURTLE_XAG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_MOCKTURTLE_MIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_MOCKTURTLE_XMG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_MOCKTURTLE_GTG\n";
        break;
      case E_ToolLogicType::E_LOGIC_IMAP_AIG:
        /* code */
        std::cout << "previous logic type is E_LOGIC_IMAP_AIG\n";
        break;
      default:
        assert( false );
        break;
      }

      // step2:  IR -> current logic-based data structure
      switch ( logic_type_curr_ )
      {
      case E_ToolLogicType::E_LOGIC_ABC_AIG:
        /* code */
        std::cout << "current logic type is E_LOGIC_ABC_AIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_ABC_GIA:
        /* code */
        std::cout << "current logic type is E_LOGIC_ABC_GIA\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG:
        /* code */
        std::cout << "current logic type is E_LOGIC_MOCKTURTLE_AIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG:
        /* code */
        std::cout << "current logic type is E_LOGIC_MOCKTURTLE_XAG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG:
        /* code */
        std::cout << "current logic type is E_LOGIC_MOCKTURTLE_MIG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG:
        /* code */
        std::cout << "current logic type is E_LOGIC_MOCKTURTLE_XMG\n";
        break;
      case E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG:
        /* code */
        std::cout << "current logic type is E_LOGIC_MOCKTURTLE_GTG\n";
        break;
      case E_ToolLogicType::E_LOGIC_IMAP_AIG:
        /* code */
        std::cout << "current logic type is E_LOGIC_IMAP_AIG\n";
        break;
      default:
        assert( false );
        break;
      }
    }
  }

  /**
   * @brief get the current network for the given type
   * @tparam Ntk current network type
   * @return ntk
   */
  std::shared_ptr<void> current()
  {
    return std::visit( []( auto&& arg ) -> std::shared_ptr<void> {
      using T = std::decay_t<decltype( arg )>;
      if constexpr ( !std::is_same_v<T, std::nullptr_t> )
      {
        return std::static_pointer_cast<void>( arg );
      }
      else
      {
        return nullptr;
      }
    },
                       current_ntk_ );
  }

private:
  E_ToolLogicType logic_type_prev_;
  E_ToolLogicType logic_type_curr_;

  std::variant<std::shared_ptr<pabc::Abc_Frame_t>,
               std::shared_ptr<mockturtle::aig_network>,
               std::shared_ptr<mockturtle::xag_network>,
               std::shared_ptr<mockturtle::mig_network>,
               std::shared_ptr<mockturtle::xmg_network>,
               std::shared_ptr<mockturtle::gtg_network>>
      current_ntk_; // store the current network

  std::shared_ptr<pabc::Abc_Frame_t> ntk_abc_aig_ = nullptr;
  std::shared_ptr<mockturtle::aig_network> ntk_mt_aig_ = nullptr;
  std::shared_ptr<mockturtle::xag_network> ntk_mt_xag_ = nullptr;
  std::shared_ptr<mockturtle::mig_network> ntk_mt_mig_ = nullptr;
  std::shared_ptr<mockturtle::xmg_network> ntk_mt_xmg_ = nullptr;
  std::shared_ptr<mockturtle::gtg_network> ntk_mt_gtg_ = nullptr;
};

} // end namespace logic

} // end namespace lf