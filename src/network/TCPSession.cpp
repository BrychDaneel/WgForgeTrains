#include "TCPSession.h"


using namespace tiger::trains::network;


TCPSession::TCPSession():tcpSocket()
{
    tcpSocket.init();
}

TCPSession::~TCPSession()
{
    tcpSocket.close();
}


bool TCPSession::connect(const char* addr, int port)
{
    struct hostent *host = gethostbyname(addr);
    if (host == nullptr)
        return false;
    uint32_t addrInt32 = ((in_addr*)host->h_addr_list[0])->s_addr;

    return tcpSocket.connect(addrInt32, port);
}

int TCPSession::send(const uint8_t* buffer, int bufferSize)
{
    int sent = 0;
    int lastSent = 0;
    while (sent < bufferSize)
    {
        lastSent = tcpSocket.send(buffer + sent, bufferSize - sent);
        if (lastSent == -1) break;
        sent += lastSent;
    }

    return lastSent == -1 ? -1 : sent;
}

int TCPSession::recv(uint8_t* buffer, int maxBytes)
{
    int received = 0;
    int lastReceived = 0;
    while (received < maxBytes)
    {
        lastReceived = tcpSocket.recv(buffer + received, maxBytes - received);
        if (lastReceived == -1) break;
        received += lastReceived;
    }

    return lastReceived == -1 ? -1 : received;
}
