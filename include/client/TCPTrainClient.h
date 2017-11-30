#ifndef TCP_TRAIN_CLIENT_H_
#define TCP_TRAIN_CLIENT_H_


#include "easylogging++.h"


#include "client/ITrainClient.h"
#include "convertors/json/ModelConvertor.h"
#include "network/TCPSession.h"
#include "network/ResposeMessage.h"
#include <memory>




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

                    TCPTrainClient(const char *name, const char *addr, int port);
                    virtual ~TCPTrainClient();
                    models::PlayerModel *getMyPlayer() const;
                    int getStaticMap(models::StaticMap *staticMap) const;
                    int getDynamicMap(models::DynamicMap *dynamicMap) const;
                    void turn() const;
                    int move(const models::MoveModel &move) const;
                    int login();

                private:


                    mutable network::TCPSession tcpSession;
                    convertors::json::ModelConvertor convertor;
                    models::PlayerModel *playerModel;
                    el::Logger *logger;


            };




        }

    }
}



#endif
