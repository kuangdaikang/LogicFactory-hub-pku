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
 * @brief checking whether a string is end with a suffix
 * @param str
 * @param suffix
 * @return
 */
std::vector<std::string> glob( const std::string& folder, const std::string& suffix )
{
  std::vector<std::string> res;
  try
  {
    if ( std::filesystem::is_directory( folder ) )
    {
      for ( const auto& entry : std::filesystem::directory_iterator( folder ) )
      {
        const auto& path = entry.path();
        // Check if the file extension is .lef
        if ( path.extension() == suffix )
        {
          res.push_back( path.string() );
        }
      }
    }
    else
    {
      std::cerr << "Provided path is not a directory: " << folder << std::endl;
    }
  }
  catch ( const std::filesystem::filesystem_error& e )
  {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
  }
  catch ( const std::exception& e )
  {
    std::cerr << "Standard exception: " << e.what() << std::endl;
  }
  return res;
}

/**
 * @brief create a directory
 */
bool createDirectory( const std::string& path )
{
  try
  {
    if ( std::filesystem::create_directories( path ) )
    {
    }
    else
    {
      std::cout << "Directories already exist or failed to create." << std::endl;
    }
    return true;
  }
  catch ( const std::filesystem::filesystem_error& e )
  {
    std::cerr << "Error: " << e.what() << " | Path: " << e.path1() << std::endl;
    if ( e.code() == std::make_error_code( std::errc::no_such_file_or_directory ) )
    {
      std::cerr << "Check if the intermediate directories exist or if the path is correct." << std::endl;
    }
    return false;
  }
}

} // namespace utility

} // namespace lf