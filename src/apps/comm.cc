#include <string>
#include "libcomm.h"
using namespace std;

//
// Expected usage:
//  comm type address
//
// The sample application below
// demonstrates the complete
// concrete class names diet
//

extern int
main( int argc, char* argv[] )
{
	string		buf;
	string		commType( argv[ 1 ] );
	string		address( argv[ 2 ] );

	Comm*		comm = Comm::create( commType );

	comm->setAddress( address );
	comm->open();
	comm->write( buf, 17 );
	comm->read( buf, 17 );
	comm->close();

	delete comm;

	return 0;
}
