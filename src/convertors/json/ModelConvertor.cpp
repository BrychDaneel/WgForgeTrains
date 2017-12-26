#include <convertors/json/ModelConvertor.h>


#include <convertors/json/DynamicMapReader.h>
#include <convertors/json/StaticMapReader.h>
#include <convertors/json/PlayerReader.h>
#include <convertors/json/MoveWriter.h>
#include <convertors/json/UpgradeWriter.h>
#include <convertors/json/CoordsMapReader.h>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


ModelConvertor::ModelConvertor()
{
    dynamicMapReader = new DynamicMapReader();
    staticMapReader = new StaticMapReader();
    playerReader = new PlayerReader();
    moveWriter = new MoveWriter();
    upgradeWriter = new UpgradeWriter();
    coordMapReader = new CoordsMapReader();
}


ModelConvertor::~ModelConvertor()
{
    delete dynamicMapReader;
    delete staticMapReader;
    delete playerReader;
    delete moveWriter;
    delete upgradeWriter;
    delete coordMapReader;
}


int ModelConvertor::readStaticMap(const char *buffer, const int bufferSize, models::StaticMap *staticMap)
{
    if (staticMapReader->readStaticMap(buffer, bufferSize, staticMap))
    {
        lastErrorCode = staticMapReader->getLastErrorCode();
        lastErrorMessage = staticMapReader->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::readDynamicMap(const char *buffer, int bufferSize, models::DynamicMap *dynamicMap)
{
    if (dynamicMapReader->readDynamicMap(buffer, bufferSize, dynamicMap))
    {
        lastErrorCode = dynamicMapReader->getLastErrorCode();
        lastErrorMessage = dynamicMapReader->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::readPlayer(const char *buffer, int bufferSize, models::PlayerModel *playerModel)
{
    if (playerReader->readPlayer(buffer, bufferSize, playerModel))
    {
        lastErrorCode = playerReader->getLastErrorCode();
        lastErrorMessage = playerReader->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::writeMove(const models::MoveModel *move, char *buffer, int *bufferSize)
{
    if (moveWriter->writeMove(move, buffer, bufferSize))
    {
        lastErrorCode = moveWriter->getLastErrorCode();
        lastErrorMessage = moveWriter->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::writeUpgrade(const models::UpgradeModel *upgrade, char *buffer, int *bufferSize)
{
    if (upgradeWriter->writeUpgrade(upgrade, buffer, bufferSize))
    {
        lastErrorCode = upgradeWriter->getLastErrorCode();
        lastErrorMessage = upgradeWriter->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::readCoordsMap(const char *buffer, const int bufferSize, models::CoordsMap *coordsMap)
{
    if (coordMapReader->readCoordsMap(buffer, bufferSize, coordsMap))
    {
        lastErrorCode = playerReader->getLastErrorCode();
        lastErrorMessage = playerReader->getLastErrorMessage();
        return lastErrorCode;
    }

    return 0;
}


int ModelConvertor::getLastErrorCode()
{
    return lastErrorCode;
}


const std::string &ModelConvertor::getLastErrorMessage()
{
    return lastErrorMessage;
}


}
}
}
}
