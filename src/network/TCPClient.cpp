#include "network/TCPClient.h"


using namespace tiger::trains::network;


TCPClient::TCPClient():tcpSocket()
{
    tcpSocket.init();
}

TCPClient::~TCPClient()
{

}

void TCPClient::close()
{
    tcpSocket.close();

}



bool TCPClient::connect(const char *addr, int port)
{
    struct hostent *host = gethostbyname(addr);

    if (host == nullptr)
        return false;

    uint32_t addrInt32 = ((in_addr *)host->h_addr_list[0])->s_addr;

    return tcpSocket.connect(ntohl(addrInt32), port);
}

int TCPClient::send(const char *buffer, size_t bufferSize)
{
    size_t sent = 0;
    int lastSent = 0;

    while (sent < bufferSize)
    {
        lastSent = tcpSocket.send(buffer + sent, bufferSize - sent);

        if (lastSent == -1) break;

        sent += lastSent;
    }

    return lastSent == -1 ? -1 : sent;
}

int TCPClient::recv(char *buffer, size_t maxBytes)
{
    size_t received = 0;
    int lastReceived = 0;

    while (received < maxBytes)
    {
        lastReceived = tcpSocket.recv(buffer + received, maxBytes - received);

        if (lastReceived == -1) break;

        received += lastReceived;
    }

    return lastReceived == -1 ? -1 : received;
}


