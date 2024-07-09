#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
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
} // namespace utility

} // namespace lf