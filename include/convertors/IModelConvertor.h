#pragma once


#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/MoveModel.h>
#include <models/UpgradeModel.h>
#include <models/CoordsMap.h>
#include <string>


namespace tiger
{
namespace trains
{
namespace convertors
{


struct IModelConvertor
{
    virtual ~IModelConvertor(){}

    virtual int readStaticMap(const char* buffer, const int bufferSize, models::StaticMap* staticMap) = 0;
    virtual int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap) = 0;
    virtual int readPlayer(const char* buffer, const int bufferSize, models::PlayerModel* playerModel) = 0;
    virtual int writeMove(const models::MoveModel* move, char* buffer, int* bufferSize) = 0;
    virtual int writeUpgrade(const models::UpgradeModel* upgrade, char* buffer, int* bufferSize) = 0;

    virtual int readCoordsMap(const char* buffer, const int bufferSize,
                              models::CoordsMap* coordsMap) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string& getLastErrorMessage() = 0;
};


}
}
}
