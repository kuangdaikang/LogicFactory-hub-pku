#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_logic/logic_manager.hpp"
#include "layer_netlist/netlist_manager.hpp"

#include "misc/anchor.hpp"

namespace lf
{

namespace tcl
{
class CmdLfStart : public TclCmd
{
public:
  explicit CmdLfStart( const char* cmd_name, const char* anchor_domain )
      : TclCmd( cmd_name, anchor_domain )
  {
    auto* option = new TclStringOption( "-anchor", 1, nullptr );
    addOption( option );
  }

  ~CmdLfStart() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-anchor" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    lfAmINST->start();
    lfLmINST->start();
    lfNamINST->start();

    std::string anchor = "";
    TclOption* option_anchor = getOptionOrArg( "-anchor" );
    if ( option_anchor->is_set_val() )
      anchor = option_anchor->getStringVal();

    if ( anchor == "-arch" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_ARCH_INIT );
    }
    else if ( anchor == "-logic" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_INIT );
    }
    else if ( anchor == "-netlist" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_INIT );
    }
    else
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NONE );
      std::cerr << "Unknown anchor: " << anchor << std::endl;
      assert( false );
      return 0;
    }

    return 1;
  }

}; // class CmdLfStart

class CmdLfStop : public TclCmd
{
public:
  explicit CmdLfStop( const char* cmd_name, const char* anchor_domain )
      : TclCmd( cmd_name, anchor_domain )
  {
  }

  ~CmdLfStop() override = default;

  unsigned check() override
  {
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    lfAmINST->stop();
    lfLmINST->stop();
    lfNamINST->stop();

    return 1;
  }

}; // class CmdLfStop

} // namespace tcl

} // namespace lf