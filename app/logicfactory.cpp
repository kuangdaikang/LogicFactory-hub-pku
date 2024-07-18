#include "tcl/start.hpp"

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

  lf::tcl::engine_start( argc, argv );

  return 0;
}