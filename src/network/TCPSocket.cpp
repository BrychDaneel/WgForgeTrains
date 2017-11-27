#include "network/TCPSocket.h"
#include <iostream>

using namespace tiger::trains::network;


TCPSocket::TCPSocket()
{

}

bool TCPSocket::init()
{
    pSocket = socket(AF_INET, SOCK_STREAM, 0);

    return isSocketValid();
}

bool TCPSocket::bind(uint32_t addr, int port)
{
    clientSockAddr.sin_port = htons(port);
    clientSockAddr.sin_family = AF_INET;
    clientSockAddr.sin_addr.s_addr = addr;
    int retVal = ::bind(pSocket,(struct sockaddr*) &clientSockAddr, sizeof(clientSockAddr));
    return retVal == 0 ? true : false;
}


bool TCPSocket::bind(int port)
{
    return bind(INADDR_ANY, port);
}

bool TCPSocket::connect(uint32_t addr, int port)
{
    serverSockAddr.sin_port = htons(port);
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_addr.s_addr = htonl(addr);

    int retVal = ::connect(pSocket, (struct sockaddr*) &serverSockAddr, sizeof(serverSockAddr));
    return retVal == 0 ? true : false;
}

int TCPSocket::send(const uint8_t* buffer, size_t bufferSize)
{
    #ifdef  DEBUG
        printf("%s  :  %i", buffer, maxBytes);
    #endif // DEBUG
    int bytesSend = -1;
    if (isSocketValid())
    {
        if (bufferSize > 0 && buffer != nullptr)
        {
            bytesSend = ::send(pSocket, buffer, bufferSize, 0);
        }
    }

    return bytesSend;
}

int TCPSocket::recv(uint8_t* buffer, size_t maxBytes = 1)
{
    #ifdef DEBUG
        printf("%s  :  %i", buffer, maxBytes);
    #endif // DEBUG
    int bytesRecieved = -1;
    if (isSocketValid())
    {
        bytesRecieved = ::recv(pSocket, buffer, maxBytes, 0);
    }

    return bytesRecieved;
}

void TCPSocket::close()
{
    if (pSocket != -1)
    {
        ::close(pSocket);
        pSocket = -1;
    }
}


