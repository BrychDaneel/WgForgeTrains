#ifndef TCP_TRAIN_CLIENT_H_
#define TCP_TRAIN_CLIENT_H_

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
                    TCPTrainClient(const char *name, const char *addr, int port);
                    virtual ~TCPTrainClient();
                    std::shared_ptr<const models::PlayerModel> getMyPlayer();
                    std::shared_ptr<const models::StaticMap> getStaticMap();
                    std::shared_ptr<const models::DynamicMap> getDynamicMap();
                    void turn();
                    bool move(const models::MoveModel &move);
                    bool login();

                private:

                    network::TCPSession tcpSession;
                    convertors::json::ModelConvertor convertor;
                    std::shared_ptr<models::PlayerModel> playerModel;
            };




        }

    }
}



#endif
