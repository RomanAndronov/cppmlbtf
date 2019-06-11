#ifndef __LIB_COMM_TCPIPV4_H__
#define __LIB_COMM_TCPIPV4_H__

#include "libcomm.h"

//
// A concrete implementation of
// an abstract Comm interface
//

class CommTcpIpV4 : public Comm
{
public:
	CommTcpIpV4();

	virtual 		~CommTcpIpV4();
	virtual void		setAddress( const std::string& );
	virtual void		getAddress( std::string& );
	virtual int		open();
	virtual ssize_t		read( std::string&, size_t );
	virtual ssize_t		write( std::string&, size_t );
	virtual int		close();

private:
	int			socket;
};


//
// The following function will be invoked
// by the Comm::create() method to make an
// instance of this concrete class
//

extern "C"
{
extern Comm*	tcpipv4Create();
}

#endif
