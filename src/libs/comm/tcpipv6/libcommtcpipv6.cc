#include <iostream>
#include "libcommtcpipv6.h"
using namespace std;


Comm*
tcpipv6Create()
{
	cout << "libcommtcpipv6.cc: tcpipv6Create()" << endl;

	return new CommTcpIpV6();
}


CommTcpIpV6::CommTcpIpV6()
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::CommTcpIpV6()" << endl;
}


CommTcpIpV6::~CommTcpIpV6()
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::~CommTcpIpV6()" << endl;
}


void
CommTcpIpV6::setAddress( const std::string& address )
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::setAddress(" +
		address + ")" << endl;
}


void
CommTcpIpV6::getAddress( std::string& address )
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::getAddress()" << endl;
}


int
CommTcpIpV6::open()
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::open()" << endl;
}


ssize_t
CommTcpIpV6::read( std::string& buf, size_t bufsz )
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::read()" << endl;
}


ssize_t
CommTcpIpV6::write( std::string& buf, size_t bufsz )
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::write()" << endl;
}


int
CommTcpIpV6::close()
{
	cout << "libcommtcpipv6.cc: CommTcpIpV6::close()" << endl;
}
