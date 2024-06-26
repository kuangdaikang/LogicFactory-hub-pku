#pragma once
#include <cstring>

namespace lf
{

namespace utility
{

/**
 * @brief checking whether a string is end with a suffix
 * @param str
 * @param suffix
 * @return
 */
bool endsWith( const std::string& str, const std::string& suffix )
{
  if ( str.length() >= suffix.length() )
  {
    return ( 0 == str.compare( str.length() - suffix.length(), suffix.length(), suffix ) );
  }
  else
  {
    return false;
  }
}
} // namespace utility

} // namespace lf