#pragma once


#include <stdio.h>


#if defined(linux) || defined(__linux) || defined(__linux__)
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
typedef int SOCKET;

#else
#include <winsock2.h>
#include <WS2tcpip.h>
#include <inttypes.h>
#pragma comment(lib, "Ws2_32.lib")

#endif


namespace tiger
{
namespace trains
{
namespace network
{


class TCPSocket {
public:
    TCPSocket();
    bool init();
    bool bind(uint32_t addr, int port);
    bool bind(int port);
    bool connect(uint32_t addr, int port);
    int send(const uint8_t *buffer, size_t bufferSize);
    int recv(uint8_t *buffer, size_t maxBytes);
    void close();


private:
    SOCKET pSocket;
    struct sockaddr_in  serverSockAddr;
    struct sockaddr_in  clientSockAddr;

    bool isSocketValid() {return pSocket != -1;}


};


}
}
}
