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
  print_centered( "Driving innovation in Logic Synthesis!", width );
  std::cout << line << std::endl;
}

int main( int argc, char** argv )
{
  if ( argc == 1 )
  {
    argv[0] = const_cast<char*>( "TclMain\n" );
  }

  for ( int i = 1; i < argc; ++i )
  {
    if ( std::string( "-script" ) == argv[i] )
    {
      argc -= i;
      argv += i;
      break;
    }
  }
  print_banner();
  lf::tcl::engine_start( argc, argv );

  return 0;
}