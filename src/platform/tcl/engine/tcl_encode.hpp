#pragma once

#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

namespace lf
{
namespace tcl
{
class TclEncodeResult
{
public:
  TclEncodeResult() = default;
  ~TclEncodeResult() = default;

public:
  static char* encode( void* pointer )
  {
    char* encode_str = (char*)malloc( 4096 );
    sprintf( encode_str, "%s%p", _encode_prefix, pointer );
    return encode_str;
  }

  static void* decode( const char* encode_str )
  {
    std::string pointer_str;
    std::string str = encode_str;
    std::string prefix = _encode_prefix;
    auto it = std::search( str.begin(), str.end(), prefix.begin(), prefix.end() );

    if ( it != str.end() )
    {
      pointer_str = std::string( it + prefix.size(), str.end() );
    }

    const int hex = 16;
    auto pointer_address = static_cast<uintptr_t>( std::stoull( pointer_str, nullptr, hex ) );
    return reinterpret_cast<void*>( pointer_address );
  }

  static const char* get_encode_prefix() { return _encode_prefix; }

private:
  inline static const char* _encode_prefix = "@ptr";
};

} // namespace tcl

} // namespace lf