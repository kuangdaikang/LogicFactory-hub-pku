#include "tcl/start.hpp"

void print_banner()
{
  auto print_centered = []( const std::string& text, size_t width ) {
    size_t padding = ( width - text.length() ) / 2;
    std::cout << "* " << std::string( padding, ' ' ) << text << std::string( padding, ' ' );
    if ( text.length() % 2 != 0 )
    {
      std::cout << " ";
    }
    std::cout << " *" << std::endl;
  };

  const size_t width = 40;
  std::string line = std::string( width + 4, '-' );

  std::cout << line << std::endl;
  print_centered( "Welcome to LogicFactory (Platform)", width );
  print_centered( "Version 0.1", width );
  print_centered( "https://github.com/Logic-Factory", width );
  std::cout << line << std::endl;
}

int main( int argc, char** argv )
{

  if ( argc == 1 ) // command line
  {
    print_banner();
    argv[0] = const_cast<char*>( "TclMain\n" );
    lf::tcl::engine_start( argc, argv );
    return 1;
  }
  else
  {
    if ( argc != 3 )
    {
      std::cerr << "wrong number of arguments!\n";
      assert( false );
      return -1;
    }

    if ( argv[1] == std::string( "-s" ) ) // tcl file
    {
      argc -= 1;
      argv += 1;
      lf::tcl::engine_start( argv[1] );
      return 1;
    }
    else if ( argv[1] == std::string( "-c" ) ) // command sequence
    {
      std::istringstream iss( argv[2] );
      std::string command;
      std::vector<char*> commands;
      commands.push_back( const_cast<char*>( "TclMain\n" ) );
      while ( std::getline( iss, command, ';' ) )
      {
        char* cmd = new char[command.size() + 1];
        std::copy( command.begin(), command.end(), cmd );
        cmd[command.size()] = '\0';
        commands.push_back( cmd );
      }
      lf::tcl::engine_start( commands.size(), commands.data() );
      return 1;
    }
    else
    {
      std::cerr << "unknow format!\n";
      assert( false );
      return -1;
    }
  }
}