#pragma once

#include "tcl/engine/tcl_option.hpp"
#include "tcl/engine/tcl_cmd.hpp"

namespace lf
{
namespace tcl
{

struct lfCmdOption
{
  std::string name = "";
  std::string tool = "";        // "", "yosys", "abc", "lsils", "ieda" ..
  std::string type = "";        // string, bool, int, double, strvec ...
  std::string description = ""; //

  lfCmdOption( const std::string& name, const std::string& tool, const std::string& type, const std::string& description )
      : name( name ), tool( tool ), type( type ), description( description )
  {}
};

/**
 * @brief set the toptions for a commands
 */
void setOptions( TclCmd* cmd, const std::vector<lfCmdOption> args )
{
  for ( auto arg : args )
  {
    TclOption* opt = nullptr;
    if ( arg.type == "bool" )
      opt = new TclSwitchOption( arg.name.c_str() );
    else if ( arg.type == "string" )
      opt = new TclStringOption( arg.name.c_str(), 1, nullptr );
    else if ( arg.type == "int" )
      opt = new TclIntOption( arg.name.c_str(), 1, 0 );
    else if ( arg.type == "double" )
      opt = new TclDoubleOption( arg.name.c_str(), 1, 0.0f );
    else if ( arg.type == "strvec" )
      opt = new TclStringListOption( arg.name.c_str(), 1, {} );
    else if ( arg.type == "intvec" )
      opt = new TclIntListOption( arg.name.c_str(), 1, {} );
    else if ( arg.type == "dblvec" )
      opt = new TclDoubleListOption( arg.name.c_str(), 1, {} );
    // else if ( arg.type == "strvecvec" )
    //   opt = new TclStringListListOption( arg.name.c_str(), 1, {} );
    else
    {
      std::cerr << "Unknown option type: " << arg.type << std::endl;
      assert( false );
    }
    opt->set_description( arg.description );
    opt->set_tool( arg.tool );

    cmd->addOption( opt );
  }
}

/**
 * @brief check whether the essential options are set the value
 */
unsigned checkEssentialOptions( TclCmd* cmd, const std::vector<std::string>& essential )
{
  for ( auto& ess : essential )
  {
    if ( !cmd->getOptionOrArg( ess.c_str() )->is_set_val() )
    {
      std::cerr << "Essential option \"" << ess << "\" is not set value!" << std::endl;
      assert( false );
      return 0;
    }
  }
  return 1;
}

/**
 * @brief extract the options' value from the command
 */
void extractOptions( TclCmd* cmd,
                     const std::vector<std::string>& strOptions,
                     const std::vector<std::string>& boolOptions,
                     const std::vector<std::string>& intOptions,
                     const std::vector<std::string>& doubleOptions,
                     const std::vector<std::string>& strvecOptions,
                     const std::vector<std::string>& intvecOptions,
                     const std::vector<std::string>& doublevecOptions,
                     std::map<std::string, std::string>& strOptionsValue,
                     std::map<std::string, bool>& boolOptionsValue,
                     std::map<std::string, int>& intOptionsValue,
                     std::map<std::string, double>& doubleOptionsValue,
                     std::map<std::string, std::vector<std::string>>& strvecOptionsValue,
                     std::map<std::string, std::vector<int>>& intvecOptionsValue,
                     std::map<std::string, std::vector<double>>& doublevecOptionsValue )
{
  for ( auto stropt : strOptions )
  {
    if ( cmd->getOptionOrArg( stropt.c_str() )->is_set_val() )
      strOptionsValue[stropt] = cmd->getOptionOrArg( stropt.c_str() )->getStringVal();
    else
      strOptionsValue[stropt] = "";
  }

  for ( auto boolopt : boolOptions )
  {
    if ( cmd->getOptionOrArg( boolopt.c_str() )->is_set_val() )
      boolOptionsValue[boolopt] = true;
    else
      boolOptionsValue[boolopt] = false;
  }

  for ( auto intopt : intOptions )
  {
    if ( cmd->getOptionOrArg( intopt.c_str() )->is_set_val() )
      intOptionsValue[intopt] = cmd->getOptionOrArg( intopt.c_str() )->getIntVal();
    else
      intOptionsValue[intopt] = -1;
  }

  for ( auto doubleopt : doubleOptions )
  {
    if ( cmd->getOptionOrArg( doubleopt.c_str() )->is_set_val() )
      doubleOptionsValue[doubleopt] = cmd->getOptionOrArg( doubleopt.c_str() )->getDoubleVal();
    else
      doubleOptionsValue[doubleopt] = -1.0f;
  }

  for ( auto strvecopt : strvecOptions )
  {
    if ( cmd->getOptionOrArg( strvecopt.c_str() )->is_set_val() )
      strvecOptionsValue[strvecopt] = cmd->getOptionOrArg( strvecopt.c_str() )->getStringList();
    else
      strvecOptionsValue[strvecopt] = std::vector<std::string>();
  }

  for ( auto intvecopt : intvecOptions )
  {
    if ( cmd->getOptionOrArg( intvecopt.c_str() )->is_set_val() )
      intvecOptionsValue[intvecopt] = cmd->getOptionOrArg( intvecopt.c_str() )->getIntList();
    else
      intvecOptionsValue[intvecopt] = std::vector<int>();
  }

  for ( auto doublevecopt : doublevecOptions )
  {
    if ( cmd->getOptionOrArg( doublevecopt.c_str() )->is_set_val() )
      doublevecOptionsValue[doublevecopt] = cmd->getOptionOrArg( doublevecopt.c_str() )->getDoubleList();
    else
      doublevecOptionsValue[doublevecopt] = std::vector<double>();
  }
}

} // namespace tcl

} // namespace lf
