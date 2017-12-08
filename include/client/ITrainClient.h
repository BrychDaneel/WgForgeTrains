#ifndef I_TRAIN_CLIENT_H_
#define I_TRAIN_CLIENT_H_

#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/MoveModel.h>
#include <models/CoordModel.h>
#include <models/UpgradeModel.h>

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
                    virtual int getStaticMap(models::StaticMap *staticMap) = 0;
                    virtual int getDynamicMap(models::DynamicMap *dynamicMap) = 0;
                    virtual void turn() = 0;

                    virtual int getCoordinate(models::CoordModel *coordModel) = 0;
                    virtual int move(const models::MoveModel &move) = 0;
                    virtual int upgrade(models::UpgradeModel &upgradeModel) = 0;

            };

        }
    }
}



#endif
