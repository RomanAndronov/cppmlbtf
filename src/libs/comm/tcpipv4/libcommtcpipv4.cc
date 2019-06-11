#include <iostream>
#include "libcommtcpipv4.h"
using namespace std;


Comm*
tcpipv4Create()
{
	cout << "libcommtcpipv4.cc: tcpipv4Create()" << endl;

	return new CommTcpIpV4();
}


CommTcpIpV4::CommTcpIpV4()
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::CommTcpIpV4()" << endl;
}


CommTcpIpV4::~CommTcpIpV4()
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::~CommTcpIpV4()" << endl;
}


void
CommTcpIpV4::setAddress( const std::string& address )
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::setAddress(" +
		address + ")" << endl;
}


void
CommTcpIpV4::getAddress( std::string& address )
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::getAddress()" << endl;
}


int
CommTcpIpV4::open()
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::open()" << endl;
}


ssize_t
CommTcpIpV4::read( std::string& buf, size_t bufsz )
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::read()" << endl;
}


ssize_t
CommTcpIpV4::write( std::string& buf, size_t bufsz )
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::write()" << endl;
}


int
CommTcpIpV4::close()
{
	cout << "libcommtcpipv4.cc: CommTcpIpV4::close()" << endl;
}
