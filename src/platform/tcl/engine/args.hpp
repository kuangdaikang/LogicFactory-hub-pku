#pragma once

#include <vector>
#include <string>
#include <string.h>

namespace lf
{
namespace tcl
{

/**
 * @brief
 */
char* copyCharStar( const char* orig )
{
  if ( orig == nullptr )
    return nullptr;

  char* copy_str = new char[strlen( orig ) + 1];
  if ( copy_str == nullptr )
    return nullptr;

  strcpy( copy_str, orig );
  return copy_str;
}

/**
 * @brief split a string into a vector of integers
 * @example
 *   split_int( "1,2,3", "," ) -> {1,2,3}
 *   split_int( "1 2 3", " " ) -> {1,2,3}
 */
std::vector<int> splitInt( const char* orig, const char* delimiter )
{
  char* copy_str = copyCharStar( orig );
  std::vector<int> results;

  char* token = strtok( copy_str, delimiter );
  while ( token )
  {
    if ( *token != '{' )
    {
      results.push_back( std::atoi( token ) );
    }
    token = strtok( nullptr, delimiter );
  }

  std::free( copy_str );
  return results;
}

/**
 * @brief   split a string into a vector of Double
 * @example
 *   split_double( "1,2,3", "," ) -> {1.0,2.0,3.0}
 */
std::vector<double> splitDouble( const char* orig, const char* delimiter )
{
  char* copy_str = copyCharStar( orig );
  std::vector<double> results;

  char* token = strtok( copy_str, delimiter );
  while ( token )
  {
    if ( *token != '{' )
    {
      results.push_back( std::atof( token ) );
    }
    token = strtok( nullptr, delimiter );
  }

  std::free( copy_str );
  return results;
}

/**
 * @brief    split a string into a vector of strings
 * @example
 *   split_string( "1,2,3", "," ) -> {"1","2","3"}
 */
std::vector<std::string> splitString( const char* orig, const char* delimiter )
{
  char* copy_str = copyCharStar( orig );
  std::vector<std::string> results;

  char* token = strtok( copy_str, delimiter );
  while ( token )
  {
    results.push_back( token );
    token = strtok( nullptr, delimiter );
  }

  std::free( copy_str );
  return results;
}

template<char c>
inline int ignoreNext( const char val[], int pos = 0 )
{
  static_assert( c != '\0' );
  for ( ; val[pos] == c; ++pos )
    ;
  return pos;
}

template<char c>
inline int findNext( const char val[], int pos = 0 )
{
  for ( ; val[pos] != c; ++pos )
    if ( val[pos] == '\0' )
      break;
  return pos;
}

template<char c0, char c1, class Itr = std::string::iterator>
inline Itr ignoreNext( Itr start )
{
  for ( ; *start == c0 || *start == c1; ++start )
    ;
  return start;
}

template<char c, class Itr = std::string::iterator>
inline Itr findNext( Itr start, Itr end )
{
  for ( ; *start != c; ++start )
    if ( start == end )
      break;
  return start;
}

inline std::vector<std::pair<int, int>> getStrListPosLen( const char val[] )
{
  std::vector<std::pair<int, int>> pos_len_list;
  int pos = 0;
  while ( val[pos] != '\0' )
  {
    int start = findNext<'{'>( val, pos );
    int end = findNext<'}'>( val, start );
    start = ignoreNext<' '>( val, start + 1 );
    pos = ignoreNext<' '>( val, end + 1 );
    pos_len_list.emplace_back( start, end - start );
  }
  return pos_len_list;
}

template<char delim0, char delim1>
std::vector<std::string> split( const char* val, int len )
{
  std::vector<std::string> str_list;
  std::string str( val, len );
  auto substr_begin = str.begin();
  auto substr_end = str.begin();
  while ( substr_end != str.end() )
  {
    switch ( *substr_end )
    {
    case '\"':
      substr_begin = ++substr_end;
      substr_end = findNext<'\"'>( substr_end, str.end() );
      *substr_end = ' ';

    case delim0:
    case delim1:
      str_list.emplace_back( substr_begin, substr_end );
      substr_begin = substr_end = ignoreNext<delim0, delim1>( substr_end );
      break;

    default:
      ++substr_end;
      break;
    }
  }
  if ( substr_begin != substr_end )
  {
    str_list.emplace_back( substr_begin, substr_end );
  }
  return str_list;
}

} // namespace tcl
} // namespace lf