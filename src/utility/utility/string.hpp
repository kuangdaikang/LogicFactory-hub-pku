#pragma once
#include <cstring>
#include <random>
#include <ctime>

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

bool startWith( const std::string& str, const std::string& prefix )
{
  return str.rfind( prefix, 0 ) == 0;
}

/**
 * @brief generate random name
 */
std::string genRandomName( size_t length )
{
  const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  std::uniform_int_distribution<> alphabet_dist( 0, alphabet.size() - 1 );

  std::string res;
  res.reserve( length + 3 );

  std::mt19937 generator( std::time( nullptr ) ); // Random number generator seeded with current time

  for ( size_t i = 0; i < length; ++i )
  {
    res += alphabet[alphabet_dist( generator )];
  }
  return res;
}

} // namespace utility

} // namespace lf