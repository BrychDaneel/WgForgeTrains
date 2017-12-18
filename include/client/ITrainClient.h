#pragma once


#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/MoveModel.h>
#include <models/CoordsMap.h>
#include <models/UpgradeModel.h>

#include <memory>


namespace tiger
{
namespace trains
{
namespace client
{


struct ITrainClient
{
    virtual ~ITrainClient(){}

    virtual models::PlayerModel *getMyPlayer() const = 0;
    virtual int getStaticMap(models::StaticMap *staticMap) = 0;
    virtual int getDynamicMap(models::DynamicMap *dynamicMap) = 0;
    virtual void turn() = 0;

    virtual int getCoordinate(models::CoordsMap* coordsMap) = 0;
    virtual int move(const models::MoveModel &move) = 0;
    virtual int upgrade(const models::UpgradeModel &upgradeModel) = 0;

};


}
}
}
