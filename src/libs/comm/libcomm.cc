#include <iostream>
#include <dlfcn.h>
#include <errno.h>
#include "libcomm.h"

using namespace std;

Comm::Comm()
{
	cout << "libcomm.cc: Comm::Comm()" << endl;
}

Comm::~Comm()
{
	cout << "libcomm.cc: Comm::~Comm()" << endl;
}

//
// The Comm Factory's entry point
//
// This particular one implements a
// multiple-library build-time factory:
//
//	gcc -g -fPIC -shared -o libcomm.so libcomm.cc -ldl
//	gcc -g -fPIC -shared -o libcommtcpipv4.so tcpipv4/libcommtcpipv4.cc
//	gcc -g -fPIC -shared -o libcommtcpipv6.so tcpipv4/libcommtcpipv6.cc
//
// Applications will use such a factory as follows:
//
//	gcc -g -o app app.cc -lcomm -lcommtcpipv4 -lcommtcpipv6
//

Comm*
Comm::create( const std::string& type )
{
	cout << "libcomm.cc: Comm::create()" << endl;

	//
	// Concrete implementations will provide the
	// corresponding creation function whose name
	// conforms to the following format:
	//     <type>Create()
	//
	// For example:
	//     tcpipv4Create()
	//     tcpipv6Create()
	//     udsCreate(), for Unix Domain Socket
	//

	//
	// This is what we return
	//
	Comm*		comm;

	//
	// Points to a function that brings
	// an instance of a concrete implementation
	// of an abstract communication protocol to life
	//
	Comm*		( *typeCreate )();

	//
	// This is a multiple-library build-time factory.
	// As such, dlsym() will search *all* the libraries
	// loaded up to and including this moment in time
	// for the name of a function that will instantiate
	// a concrete class of a requested type
	//
	void*		libHandle = RTLD_DEFAULT;

	//
	// Arbitrary, agreed upon format according to which
	// the name of a function that creates an instance
	// of a concrete class is constructed
	//
	std::string	crfnm = type + "Create";


	//
	// Find the name of a function that will create an
	// instance of a concrete class in the curren library
	//
	typeCreate = ( Comm* ( * )() )dlsym( libHandle, crfnm.c_str() );
	if ( !typeCreate )
	{
		errno = EINVAL;
		return NULL;
	}

	//
	// Create an instance of a concrete
	// class of a requested type
	//
	comm = typeCreate();

	//
	// and return it
	//
	return comm;
}
