#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <cstring>

#include <system_error>

namespace lf
{

namespace utility
{

/**
 * @brief print the argv
 */
void printArgv( int argc, char** argv )
{
  for ( int i = 0; i < argc; ++i )
  {
    std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
  }
}

} // namespace utility
} // namespace lf