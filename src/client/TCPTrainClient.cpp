#include <client/TCPTrainClient.h>

#define BUFF_SIZE 255
#define OFFSET_SIZE 4
#define OFFSET_1 4
#define OFFSET_2 8

using namespace tiger::trains::client;
using namespace tiger::trains::models;
using namespace tiger::trains;


TCPTrainClient::TCPTrainClient(const char *name, const char *addr, int port, const char *gameName, const int playersNum)
    : tcpSession(name, addr, port, gameName, playersNum), convertor(),playerModel(new PlayerModel())
{
    logger = el::Loggers::getLogger("TCPClient");
    el::Loggers::reconfigureLogger("TCPClient", el::ConfigurationType::Filename, LOGGER_FILE);
}

TCPTrainClient::~TCPTrainClient()
{
    delete playerModel;
    logger->info("Logout");
}

int TCPTrainClient::login()
{
    std::unique_ptr<network::ResposeMessage> message(tcpSession.login());

//  network::ResposeMessage *message = tcpSession.login();
    if (message == nullptr)
    {
        lastErrorMessage = "unknown error";
        return (int)TCPTrainClient::ErrorType::UNKOWN_ERROR;
    }

    if (message->result != 0)
    {
        lastErrorMessage = errorMessages[message->result];
        return message->result;
    }

    logger->info(" %v\n %v", "login", message->data);
    int retVal = convertor.readPlayer(message->data, message->dataLength, playerModel);

    if (retVal == 4)
    {
        tcpSession.logout();
        logger->info("Logout");

        sleep(2);
        message.reset(tcpSession.login());

        if (message == nullptr || message->result != 0)
            return message->result;

        logger->info(" %v\n %v", "login", message->data);

        retVal = convertor.readPlayer(message->data, message->dataLength, playerModel);
    }



    if (retVal)
    {
        lastErrorMessage = convertor.getLastErrorMessage();
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;
    }

    return (int)TCPTrainClient::ErrorType::OKEY;
}

std::string TCPTrainClient::getLastErrorMessage() const
{
    return lastErrorMessage;
}


PlayerModel *TCPTrainClient::getMyPlayer() const
{

    return playerModel;
}


int TCPTrainClient::getStaticMap(StaticMap *staticMap)
{
    char buffer[BUFF_SIZE] = "{\n \"layer\": 0\n}";
    size_t len = strlen(buffer);
    char sendBuffer[OFFSET_2 + len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, buffer, len);

    if (!tcpSession.send(sendBuffer, len + OFFSET_2))
        return (int)TCPTrainClient::ErrorType::NOT_SEND;


    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());

    if (message == nullptr)
        return (int)TCPTrainClient::ErrorType::UNKOWN_ERROR;

    if (message->result != 0)
        return message->result;

    logger->info(" %v\n %v", "Static Map", message->data);


    int retVal = convertor.readStaticMap(message->data, message->dataLength, staticMap);


    if (retVal != 0)
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;

    return (int)TCPTrainClient::ErrorType::OKEY;
}

int TCPTrainClient::getDynamicMap(DynamicMap *dynamicMap)
{
    char buffer[BUFF_SIZE] = "{\n \"layer\": 1\n}";
    size_t len = strlen(buffer);
    char sendBuffer[OFFSET_2 + len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, buffer, len);

    if (!tcpSession.send(sendBuffer, len + OFFSET_2))
        return (int)TCPTrainClient::ErrorType::NOT_SEND;


    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());

    if (message == nullptr)
        return (int)TCPTrainClient::ErrorType::UNKOWN_ERROR;

    if (message->result != 0)
        return message->result;


    logger->info(" %v\n %v", "Dynamic Map", message->data);


    int retVal = convertor.readDynamicMap(message->data, message->dataLength, dynamicMap);


    if (retVal != 0)
    {
        LOG(ERROR) << convertor.getLastErrorMessage();
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;
    }

    return (int)TCPTrainClient::ErrorType::OKEY;
}


void TCPTrainClient::turn()
{

    uint32_t cmd = 5;
    size_t len = 2;
    char sendBuffer[OFFSET_2 + len];
    const char *js = "{}";

    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, js, len);
    tcpSession.send(sendBuffer, 8 + len);

    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());





}

int TCPTrainClient::move(const models::MoveModel &move)
{
    char buffer[BUFF_SIZE];

    int len = BUFF_SIZE;
    uint32_t cmd = 3;

    convertor.writeMove(&move, buffer, &len);
    char sendBuffer[len + OFFSET_2];
    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, buffer, len);

    tcpSession.send(sendBuffer, len + OFFSET_2);

    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());

    int retVal = message->result;



    return retVal;
}

int TCPTrainClient::getCoordinate(models::CoordsMap *coordsMap)
{
    char buffer[BUFF_SIZE] = "{\n \"layer\": 10\n}";
    size_t len = strlen(buffer);

    char sendBuffer[8+len];
    uint32_t cmd = 10;

    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, buffer, len);

    if (!tcpSession.send(sendBuffer, len + OFFSET_2))
        return (int)TCPTrainClient::ErrorType::NOT_SEND;


    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());

    if (message == nullptr || message->result != 0)
        return message->result;


    logger->info(" %v\n %v", "Coordinate Map", message->data);

    int retVal = convertor.readCoordsMap(message->data, message->dataLength, coordsMap);


    if (retVal != 0)
    {
        LOG(ERROR) << convertor.getLastErrorMessage();
        return (int)TCPTrainClient::ErrorType::JSON_NO_PARSE;
    }

    return (int)TCPTrainClient::ErrorType::OKEY;


}

int TCPTrainClient::upgrade(const UpgradeModel &upgradeModel)
{
    char buffer[BUFF_SIZE];
    int len = BUFF_SIZE;
    uint32_t cmd = 4;

    convertor.writeUpgrade(&upgradeModel, buffer, &len);
    char sendBuffer[len + OFFSET_2];
    memcpy(sendBuffer, &cmd, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_1, &len, OFFSET_SIZE);
    memcpy(sendBuffer + OFFSET_2, buffer, len);

    tcpSession.send(sendBuffer, len + OFFSET_2);

    std::unique_ptr<network::ResposeMessage> message(tcpSession.recv());

    int retVal = message->result;



    return retVal;
}



