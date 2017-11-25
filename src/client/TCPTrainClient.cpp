#include <client/TCPTrainClient.h>
#include <iostream>
using namespace tiger::trains::client;
using namespace tiger::trains::models;
using namespace tiger::trains;

TCPTrainClient::TCPTrainClient(const char *name, const char *addr, int port)
    :tcpSession(name, addr, port), convertor(),playerModel(new PlayerModel())
{

}

TCPTrainClient::~TCPTrainClient()
{

}

bool TCPTrainClient::login()
{
    network::ResposeMessage *message = tcpSession.login();
    if (message == nullptr || message->result != 0)
        return false;

    std::cout << message->data << std::endl;
    convertor.readPlayer(message->data, message->dataLength, playerModel.get());

    delete message;
    return true;
}


std::shared_ptr<const PlayerModel> TCPTrainClient::getMyPlayer()
{

    return playerModel;
}


std::shared_ptr<const StaticMap> TCPTrainClient::getStaticMap()
{
    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"layer\": %i\n}", 0);
    uint8_t sendBuffer[8+len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    if (!tcpSession.send(sendBuffer, len + 8))
        return nullptr;


    network::ResposeMessage *message = tcpSession.recv();

    if (message == nullptr || message->result != 0)
        return nullptr;

    std::cout << message->data << std::endl;

    std::shared_ptr<StaticMap> staticMap(new StaticMap());
    convertor.readStaticMap(message->data, message->dataLength, staticMap.get());

    delete message;

    return staticMap;
}

std::shared_ptr<const DynamicMap> TCPTrainClient::getDynamicMap()
{
    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"layer\": %i\n}", 1);
    uint8_t sendBuffer[8+len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    if (!tcpSession.send(sendBuffer, len + 8))
        return nullptr;


    network::ResposeMessage *message = tcpSession.recv();

    if (message == nullptr || message->result != 0)
        return nullptr;


    std::cout << message->data << std::endl;

    std::shared_ptr<DynamicMap> dynamicMap(new DynamicMap());
    int retVal = convertor.readDynamicMap(message->data, message->dataLength, dynamicMap.get());

    delete message;
    if (retVal != 0)
        return nullptr;

    return dynamicMap;
}


void TCPTrainClient::turn()
{

}

void TCPTrainClient::move(const models::MoveModel &move)
{
    char buffer[255];
    //size_t len = sprintf(buffer, "{\n\"line_idx\": 1,\n\"speed\": 1,\n\"train_idx\": 0\n}");
    int len = 255;
    uint32_t cmd = 3;

    convertor.writeMove(&move, buffer, &len);
    uint8_t sendBuffer[len + 8];
    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    tcpSession.send(sendBuffer, len + 8);

    network::ResposeMessage *message = tcpSession.recv();


}
