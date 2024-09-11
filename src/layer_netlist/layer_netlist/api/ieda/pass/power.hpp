#pragma once

#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/eval/profile_power.hpp"

#include "misc/anchor.hpp"

namespace lf
{
namespace netlist
{

struct ProfilePower;

namespace ieda
{
void init_power( ipower::PowerEngine* engine )
{

  engine->get_power()->runCompleteFlow();
}

/**
 * @brief
 */
void run_power()
{
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_POWER );

  ipower::PowerEngine* power_manager = ipower::PowerEngine::getOrCreatePowerEngine();
  init_power( power_manager );

  ProfilePower* profile = lfNmINST->get_profile_power();
  profile->set_power_engine( power_manager );

  double internal_power = profile->get_internal_power();
  double leakage_power = profile->get_leakage_power();
  double dynamic_power = profile->get_dynamic_power();
  double total_power = profile->get_total_power();
}

} // namespace ieda
} // namespace netlist
} // namespace lf