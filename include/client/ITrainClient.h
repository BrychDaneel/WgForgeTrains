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

                    virtual models::PlayerModel *getMyPlayer() const = 0;
                    virtual int getStaticMap(models::StaticMap *staticMap) const = 0;
                    virtual int getDynamicMap(models::DynamicMap *dynamicMap) const = 0;
                    virtual void turn() const = 0;
                    virtual int move(const models::MoveModel &move) const = 0;


            };







        }
    }
}



#endif
