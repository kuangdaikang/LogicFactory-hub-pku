#pragma once

#include "tcl_script.hpp"
#include "tcl_option.hpp"
#include "utils.hpp"

#include "nlohmann/json.hpp"

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <memory>
#include <assert.h>

namespace lf
{
namespace tcl
{

/**
 * @brief check whether the pattern contain wildcard.
 * @example
 *
 */
bool containWildcard( const char* pattern );

/**
 * @brief
 * @example
 */
bool matchWildcardWithtarget( const char* const pattern, const char* const target );

/**
 * @brief
 * @example
 */
int cmdProcess( ClientData clientData, Tcl_Interp* interp, int objc, struct Tcl_Obj* const* objv );

class TclCmd
{
public:
  explicit TclCmd( const char* cmd_name )
      : _cmd_name( copyCharStar( cmd_name ) )
  {}

  virtual ~TclCmd()
  {
    std::free( _cmd_name );
    _cmd_name = nullptr;
  }

  char* get_cmd_name() const { return _cmd_name; }

  TclOption* getOptionOrArg( const char* option_name )
  {
    if ( containWildcard( option_name ) )
    {
      return findOptionWithWildcard( option_name );
    }
    else
    {
      if ( auto it = _options.find( option_name ); it != _options.end() )
      {
        return it->second.get();
      }
    }

    return nullptr;
  }

  void addOption( TclOption* option )
  {
    // The arg need keep order.
    if ( option->is_arg() )
    {
      _args.push_back( option );
    }

    _options.emplace( option->get_option_name(), option );
  }

  TclOption* getArg( int index ) { return ( static_cast<int>( _args.size() ) > index ) ? _args[index] : nullptr; }

  void resetOptionArgValue()
  {
    for ( auto& [name, option] : _options )
    {
      option->resetVal();
    }
  }

  virtual unsigned check()
  {
    std::cerr << "This cmd has not define check body.\n";
    return 0;
  }

  virtual unsigned exec()
  {
    std::cerr << "This cmd has not define exe body.\n";
    return 0;
  }

private:
  TclOption* findOptionWithWildcard( const char* option_name )
  {
    int match_times = 0;
    auto res = _options.end();
    for ( auto it = _options.begin(); it != _options.end(); ++it )
    {
      if ( matchWildcardWithtarget( option_name, it->second.get()->get_option_name() ) )
      {
        if ( ++match_times > 1 )
        {
          std::cerr << "invalid option wildcard(s), multiple options matched.\n";
          assert( false );
        }
        res = it;
      }
    }
    return res == _options.end() ? nullptr : res->second.get();
  }

private:
  char* _cmd_name;
  std::unordered_map<const char*, std::unique_ptr<TclOption>, CStrHash, CStrEqual> _options; // store the options
  std::vector<TclOption*> _args;                                                             // the tcl args need keep order
}; // class TclCmd

class TclCmds
{
public:
  TclCmds() = default;
  ~TclCmds() = default;

public:
  static void addTclCmd( std::unique_ptr<TclCmd> cmd )
  {
    TclScript::getOrCreateInstance()->createCmd( cmd->get_cmd_name(), cmdProcess, cmd.get() );
    _cmds.emplace( cmd->get_cmd_name(), std::move( cmd ) );
  }

  static TclCmd* getTclCmd( const char* cmd_name )
  {
    auto it = _cmds.find( cmd_name );
    if ( it != _cmds.end() )
    {
      return it->second.get();
    }
    return nullptr;
  }

  // cmd_name + anchor as the key
  static std::unordered_map<const char*, std::unique_ptr<TclCmd>, CStrHash, CStrEqual> _cmds;
}; // class TclCmds

std::unordered_map<const char*, std::unique_ptr<TclCmd>, CStrHash, CStrEqual> TclCmds::_cmds;

bool containWildcard( const char* pattern )
{
  return ( pattern[0] == '-' ) && ( strpbrk( pattern, "*?" ) != nullptr );
}

bool matchWildcardWithtarget( const char* const pattern, const char* const target )
{
  const char* p = pattern;
  const char* t = target;

  while ( 1 )
  {
    while ( *p && *t && ( *p == *t ) )
    {
      ++p;
      ++t;
    }

    if ( *p == '\0' )
    {
      return ( *t == '\0' ) ? true : false;
    }

    if ( *t == '\0' )
    {
      if ( *p == '\0' )
      {
        return true;
      }
      else
      {
        while ( *p == '*' )
        {
          ++p;
          if ( *p == '\0' )
          {
            return true;
          }
          else if ( *p == '*' )
          {
            continue;
          }
          else
          {
            return false;
          }
        }
      }
    }

    if ( *p == '?' )
    {
      ++p;
      ++t;
    }
    else if ( *p == '*' )
    {
      if ( *( p + 1 ) == '\0' )
      {
        return true;
      }
      else
      {
        if ( *( p + 1 ) == *t )
        {
          ++p;
        }
        else
        {
          ++t;
        }
      }
    }
    else if ( *p != *t )
    {
      return false;
    }
  }
}

int cmdProcess( ClientData clientData, Tcl_Interp* interp, int objc, struct Tcl_Obj* const* objv )
{
  const char* cmd_name = Tcl_GetString( objv[0] );
  TclCmd* cmd = TclCmds::getTclCmd( cmd_name );
  if ( !cmd )
    return TCL_ERROR;
  cmd->resetOptionArgValue();

  bool next_is_option_val = false;
  TclOption* curr_option = nullptr;
  int arg_index = 0;
  for ( int cnt = 1; cnt < objc; ++cnt )
  {
    struct Tcl_Obj* obj = objv[cnt];
    // get option lead string or arg
    const char* obj_str = Tcl_GetString( obj );
    if ( !next_is_option_val )
    {
      TclOption* option = cmd->getOptionOrArg( obj_str );
      curr_option = option;
      if ( option )
      {
        if ( !option->isSwitchOption() )
        {
          // It is option, next should be option value if it is not switch option,
          next_is_option_val = true;
        }
        else
        {
          // switch option
          option->setVal( nullptr );
        }
      }
      else
      {
        // should be arg, arg is need keep order.
        TclOption* arg = cmd->getArg( arg_index );
        ++arg_index;
        if ( !arg )
        {
          std::cerr << "The cmd " << cmd->get_cmd_name() << " syntax has error.\n";
          return TCL_ERROR;
        }

        arg->setVal( obj_str );
      }
    }
    else
    {
      curr_option->setVal( obj_str );
      next_is_option_val = false;
    }
  }

  if ( next_is_option_val )
  {
    std::cerr << "The cmd syntax has error " << curr_option->get_option_name() << " need val.\n";
  }

  unsigned result = cmd->exec();
  return result ? TCL_OK : TCL_ERROR;
}

} // namespace tcl

} // namespace lf