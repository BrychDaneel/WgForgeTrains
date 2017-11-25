#ifndef I_TRAIN_CLIENT_H_
#define I_TRAIN_CLIENT_H_

#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/MoveModel.h>

#include <memory>


namespace tiger
{
    namespace trains
    {
        namespace client
        {

            class ITrainClient
            {
                public:

                    virtual std::shared_ptr<const models::PlayerModel> getMyPlayer() = 0;
                    virtual std::shared_ptr<const models::StaticMap> getStaticMap() = 0;
                    virtual std::shared_ptr<const models::DynamicMap> getDynamicMap() = 0;
                    virtual void turn() = 0;
                    virtual void move(const models::MoveModel &move) = 0;


            };







        }
    }
}



#endif
