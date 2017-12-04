#include <client/TCPTrainClient.h>


using namespace tiger::trains::client;
using namespace tiger::trains::models;
using namespace tiger::trains;

TCPTrainClient::TCPTrainClient(const char *name, const char *addr, int port)
    :tcpSession(name, addr, port), convertor(),playerModel(new PlayerModel())
{
    logger = el::Loggers::getLogger("TCPClient");
    el::Loggers::reconfigureLogger("TCPClient", el::ConfigurationType::Filename, "TCPClient.log");
}

TCPTrainClient::~TCPTrainClient()
{
    delete playerModel;
    logger->info("Logout");    
}

int TCPTrainClient::login()
{
    network::ResposeMessage *message = tcpSession.login();
    if (message == nullptr || message->result != 0)
        return message->result;

    logger->info(" %v\n %v", "login", message->data);
    convertor.readPlayer(message->data, message->dataLength, playerModel);

    delete message;
    return (int)TCPTrainClient::ErrorType::OKEY;
}


PlayerModel *TCPTrainClient::getMyPlayer() const
{

    return playerModel;
}


int TCPTrainClient::getStaticMap(StaticMap *staticMap) const
{
    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"layer\": %i\n}", 0);
    uint8_t sendBuffer[8+len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    if (!tcpSession.send(sendBuffer, len + 8))
        return (int)TCPTrainClient::ErrorType::NOT_SEND;


    network::ResposeMessage *message = tcpSession.recv();

    if (message == nullptr || message->result != 0)
        return message->result;

     logger->info(" %v\n %v", "Static Map", message->data);


    int retVal = convertor.readStaticMap(message->data, message->dataLength, staticMap);

    delete message;

    if (retVal != 0)
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;

    return (int)TCPTrainClient::ErrorType::OKEY;
}

int TCPTrainClient::getDynamicMap(DynamicMap *dynamicMap) const
{
    char buffer[255];
    size_t len = sprintf(buffer, "{\n \"layer\": %i\n}", 1);
    uint8_t sendBuffer[8+len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, buffer, len);

    if (!tcpSession.send(sendBuffer, len + 8))
        return (int)TCPTrainClient::ErrorType::NOT_SEND;


    network::ResposeMessage *message = tcpSession.recv();

    if (message == nullptr || message->result != 0)
        return message->result;


    logger->info(" %v\n %v", "Dynamic Map", message->data);


    int retVal = convertor.readDynamicMap(message->data, message->dataLength, dynamicMap);

    delete message;
    if (retVal != 0)
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;

    return (int)TCPTrainClient::ErrorType::OKEY;
}


void TCPTrainClient::turn() const
{

    uint32_t cmd = 5;
    size_t len = 2;
    uint8_t sendBuffer[8 + len];
    char *js = "{}";

    memcpy(sendBuffer, &cmd, 4);
    memcpy(sendBuffer + 4, &len, 4);
    memcpy(sendBuffer + 8, js, len);
    tcpSession.send(sendBuffer, 8 + len);

    network::ResposeMessage *message = tcpSession.recv();




    delete message;
}

int TCPTrainClient::move(const models::MoveModel &move) const
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

    int retVal = message->result;


    delete message;
    return retVal;
}



