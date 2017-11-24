#include <convertors/json/ModelConvertor.h>


#include <convertors/json/DynamicMapReader.h>
#include <convertors/json/StaticMapReader.h>
#include <convertors/json/PlayerReader.h>
#include <convertors/json/MoveWriter.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    ModelConvertor::ModelConvertor(){
        dynamicMapReader = new DynamicMapReader();
        staticMapReader = new StaticMapReader();
        playerReader = new PlayerReader();
        moveWriter = new MoveWriter();
    }

    ModelConvertor::~ModelConvertor(){
        free(dynamicMapReader);
        free(staticMapReader);
        free(playerReader);
        free(moveWriter);
    }

    const int ModelConvertor::readStaticMap(const char * buffer, const int bufferSize, models::StaticMap * staticMap) const{
        return staticMapReader->readStaticMap(buffer, bufferSize, staticMap);
    }

    const int ModelConvertor::readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const{
        return dynamicMapReader->readDynamicMap(buffer, bufferSize, dynamicMap);
    }

    const int ModelConvertor::readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const{
        return playerReader->readPlayer(buffer, bufferSize, playerModel);
    }

    const int ModelConvertor::writeMove(const models::MoveModel * move, char * buffer, int * bufferSize) const{
        return moveWriter->writeMove(move, buffer, bufferSize);
    }

}
}
}
}
