#ifndef __LIB_COMM_TCPIPV6_H__
#define __LIB_COMM_TCPIPV6_H__

#include "libcomm.h"

//
// A concrete implementation of
// an abstract Comm interface
//

class CommTcpIpV6 : public Comm
{
public:
	CommTcpIpV6();

	virtual 		~CommTcpIpV6();
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
extern Comm*	tcpipv6Create();
}

#endif
