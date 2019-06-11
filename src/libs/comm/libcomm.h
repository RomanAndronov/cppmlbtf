#ifndef __LIB_COMM_H__
#define __LIB_COMM_H__

#include <string>
#include <unistd.h>

//
// A sample common abstract interface
// for inter-process communication
//
// Multiple concrete implementations
// can be attached to such an interface
//
// The create() method is the Factory's
// entry point
//
// Factory's possible flavors are:
//  - single library build time factory
//  - multiple library build time factory
//  - multiple library run time factory
//

class Comm
{
public:
	Comm();

	virtual 		~Comm() = 0;
	virtual void		setAddress( const std::string& ) = 0;
	virtual void		getAddress( std::string& ) = 0;
	virtual int		open() = 0;
	virtual ssize_t		read( std::string&, size_t ) = 0;
	virtual ssize_t		write( std::string&, size_t ) = 0;
	virtual int		close() = 0;

	static Comm*		create( const std::string& );
};

#endif
