#include "network/TCPSession.h"
#include <stdio.h>

using namespace tiger::trains::network;


TCPSession::TCPSession(const char *name, const char *servAddr, int port):name(name), servAddr(servAddr), port(port)
{

}

TCPSession::~TCPSession()
{
    logout();
}

ResposeMessage *TCPSession::login()
{

    if (!tcpClient.connect(servAddr, port))
    {
        return nullptr;
    }

    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"name\": \"%s\"\n}", name);
    char sendBuffer[8+len];
    uint32_t cmd = 1;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    bool retVal = send(sendBuffer, len + 8);

    if (!retVal)
        return nullptr;

    return recv();



}

void TCPSession::logout()
{
    char sendBuffer[8];
    uint32_t cmd = 2;
    size_t len = 0;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    send(sendBuffer, len + 8);

    tcpClient.close();
    tcpClient = TCPClient();
}

bool TCPSession::send(const char *buffer, size_t bufferSize)
{
    int retVal = tcpClient.send(buffer, bufferSize);
    return retVal == -1 ? false : true;
}

ResposeMessage *TCPSession::recv()
{
    int retVal;
    char firstBuffer[4];
    retVal = tcpClient.recv(firstBuffer, 4);

    if (retVal == -1)
    {
        return nullptr;
    }


    ResposeMessage *message = new ResposeMessage();
    memcpy(&message->result, firstBuffer, 4);
    retVal = tcpClient.recv(firstBuffer, 4);

    if (retVal == -1)
    {
        delete message;
        return nullptr;
    }

    memcpy(&message->dataLength, firstBuffer, 4);

    char secondBuffer[message->dataLength];
    retVal = tcpClient.recv(secondBuffer, message->dataLength);

    message->data = new char[message->dataLength + 1];
    memcpy(message->data, secondBuffer, message->dataLength + 1);

    if (retVal == -1)
    {
        delete message;
        message = nullptr;
    }

    return message;
}
