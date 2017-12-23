#pragma once


#include <easylogging++/easylogging++.h>


#include "client/ITrainClient.h"
#include <convertors/json/ModelConvertor.h>
#include "network/TCPSession.h"
#include "network/ResposeMessage.h"
#include <memory>

#define LOGGER_FILE "logs/TCPClient.log"


namespace tiger
{
namespace trains
{
namespace client
{


class TCPTrainClient : public ITrainClient
{
public:
    enum class ErrorType: int
    {
        OKEY = 0,
        BAD_COMMAND = 1,
        RESOURCE_NOT_FOUND = 2,
        PATH_NOT_FOUND = 3,
        ACCESS_DENIED = 5,
        JSON_NO_PARSE = 6,
        UNKOWN_ERROR = 7,
        NOT_SEND = 8
    };

    TCPTrainClient(const char *name, const char *addr, int port,
                   const char *gameName, const int playersNum);
    virtual ~TCPTrainClient();
    models::PlayerModel *getMyPlayer() const;
    int getStaticMap(models::StaticMap *staticMap);
    int getDynamicMap(models::DynamicMap *dynamicMap);
    void turn();
    int move(const models::MoveModel &move);
    int getCoordinate(models::CoordsMap *coordsMap);

    int upgrade(const models::UpgradeModel &upgradeModel);
    int login();

    std::string getLastErrorMessage() const;

private:

    const char *errorMessages[8] = {"", "BAD_COMMAND", "RESOURCE_NOT_FOUND", "PATH_NOT_FOUND", "ACCESS_DENIED",
                                    "JSON_NO_PARSE", "UNKOWN_ERROR", "NOT_SEND"
                                   };

    mutable network::TCPSession tcpSession;
    convertors::json::ModelConvertor convertor;
    models::PlayerModel *playerModel;
    el::Logger *logger;

    std::string lastErrorMessage;

};


}
}
}
