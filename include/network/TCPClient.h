#pragma once


#include "network/TCPSocket.h"
#if defined(linux) || defined(__linux) || defined(__linux__)
#include <netdb.h>
#else
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <WS2tcpip.h>
#endif

namespace tiger
{
namespace trains
{
namespace network
{


class TCPClient
{
public:
    TCPClient();
    virtual ~TCPClient();
    void close();
    bool connect(const char *addr, int port);
    int send(const char *buffer, size_t bufferSize);
    int recv(char *buffer, size_t maxBytes);




protected:

private:
    TCPSocket tcpSocket;
};


}
}
}
