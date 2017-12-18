#pragma once


#include <convertors/IModelConvertor.h>


#include <convertors/IDynamicMapReader.h>
#include <convertors/IStaticMapReader.h>
#include <convertors/IPlayerReader.h>
#include <convertors/IMoveWriter.h>
#include <convertors/IUpgradeWriter.h>
#include <convertors/ICoordsMapReader.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


class ModelConvertor : public IModelConvertor{

private:

    IDynamicMapReader* dynamicMapReader;
    IMoveWriter* moveWriter;
    IPlayerReader* playerReader;
    IStaticMapReader* staticMapReader;
    IUpgradeWriter* upgradeWriter;
    ICoordsMapReader* coordMapReader;

public:

    ModelConvertor();

    ~ModelConvertor();

    int readStaticMap(const char* buffer, const int bufferSize, models::StaticMap* staticMap);
    int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap);
    int readPlayer(const char* buffer, const int bufferSize, models::PlayerModel* playerModel);
    int writeMove(const models::MoveModel* move, char* buffer, int* bufferSize);
    int writeUpgrade(const models::UpgradeModel* upgrade, char* buffer, int* bufferSize);

    int readCoordsMap(const char* buffer, const int bufferSize, models::CoordsMap* coordsMap);

    int getLastErrorCode();
    const std::string& getLastErrorMessage();

private:

    int lastErrorCode;
    std::string lastErrorMessage;

};


}
}
}
}
