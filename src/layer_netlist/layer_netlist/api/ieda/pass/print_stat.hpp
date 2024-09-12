#pragma once

#include "operation/iSTA/api/TimingEngine.hh"
#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/eval/profile_timing.hpp"

#include "misc/anchor.hpp"

#include "nlohmann/json.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

void print_stat( std::string file = "" )
{
  auto anchor = lfAnchorINST->get_anchor_curr();

  switch ( anchor )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_STA:
  {
    auto sta_engine = lfNmINST->get_profile_timing();
    auto power_engine = lfNmINST->get_profile_power();
    double arrive_time = sta_engine->get_wrost_arrive_time();
    double internal_power = power_engine->get_internal_power();
    double leakage_power = power_engine->get_leakage_power();
    double dynamic_power = power_engine->get_dynamic_power();
    double total_power = power_engine->get_total_power();
    nlohmann::json j = {
        { "arrive_time", arrive_time }};
    std::ofstream out( file );
    if ( !out.is_open() )
    {
      std::cerr << "Error: Unable to open file " << file << std::endl;
      return;
    }
    out << j.dump( 4 ) << std::endl;
    out.close();
    break;
  }
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_POWER:
  {
    auto power_engine = lfNmINST->get_profile_power();
    double internal_power = power_engine->get_internal_power();
    double leakage_power = power_engine->get_leakage_power();
    double dynamic_power = power_engine->get_dynamic_power();
    double total_power = power_engine->get_total_power();
    nlohmann::json j = {
        { "internal_power", internal_power },
        { "leakage_power", leakage_power },
        { "dynamic_power", dynamic_power },
        { "total_power", total_power } };
    std::ofstream out( file );
    if ( !out.is_open() )
    {
      std::cerr << "Error: Unable to open file " << file << std::endl;
      return;
    }
    out << j.dump( 4 ) << std::endl;
    out.close();
    break;
  }
  default:
  {
    std::cout << "TODO: \n";
    break;
  }
  }
}

} // namespace ieda
} // namespace netlist
} // namespace lf