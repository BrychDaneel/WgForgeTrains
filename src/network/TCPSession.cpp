#include "network/TCPSession.h"
#include <stdio.h>

using namespace tiger::trains::network;


TCPSession::TCPSession(std::string name, char *servAddr, int port):name(name), servAddr(servAddr), port(port)
{

}

TCPSession::~TCPSession()
{
    uint8_t sendBuffer[8];
    uint32_t cmd = 2;
    size_t len = 0;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    send(sendBuffer, len + 8);
}

ResposeMessage* TCPSession::login()
{

    if (!tcpClient.connect(servAddr, port))
    {
       return nullptr;
    }
    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"name\": \"%s\"\n}", name.c_str());
    uint8_t sendBuffer[8+len];
    uint32_t cmd = 1;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    int retVal = send(sendBuffer, len + 8);


    return recv();



}

bool TCPSession::send(const uint8_t *buffer, size_t bufferSize)
{
    int retVal = tcpClient.send(buffer, bufferSize);
    return retVal == -1 ? false : true;
}

ResposeMessage* TCPSession::recv()
{
    int retVal;
    uint8_t firstBuffer[8];
    retVal = tcpClient.recv(firstBuffer, 8);
    if (retVal == -1)
    {
        return nullptr;
    }

    ResposeMessage *message = new ResposeMessage();
    memcpy(&message->result, firstBuffer, 4);
    memcpy(&message->dataLength, firstBuffer + 4, 4);

    uint8_t secondBuffer[message->dataLength];
    retVal = tcpClient.recv(secondBuffer, message->dataLength);

    message->data = new char[message->dataLength];
    memcpy(message->data, secondBuffer, message->dataLength);

    if (retVal == -1)
    {
        delete message;
        message = nullptr;
    }

    return message;
}
