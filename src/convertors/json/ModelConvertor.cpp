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
    delete dynamicMapReader;
    delete staticMapReader;
    delete playerReader;
    delete moveWriter;
}


int ModelConvertor::readStaticMap(const char* buffer, const int bufferSize, models::StaticMap* staticMap){
    lastErrorCode = staticMapReader->readStaticMap(buffer, bufferSize, staticMap);
    lastErrorMessage = staticMapReader->getLastErrorMessage();
    return lastErrorCode;
}


int ModelConvertor::readDynamicMap(const char* buffer, int bufferSize, models::DynamicMap* dynamicMap){
    lastErrorCode = dynamicMapReader->readDynamicMap(buffer, bufferSize, dynamicMap);
    lastErrorMessage = dynamicMapReader->getLastErrorMessage();
    return lastErrorCode;
}


int ModelConvertor::readPlayer(const char* buffer, int bufferSize, models::PlayerModel* playerModel){
    lastErrorCode = playerReader->readPlayer(buffer, bufferSize, playerModel);
    lastErrorMessage = playerReader->getLastErrorMessage();
    return lastErrorCode;
}


int ModelConvertor::writeMove(const models::MoveModel* move, char* buffer, int* bufferSize){
    lastErrorCode = moveWriter->writeMove(move, buffer, bufferSize);
    lastErrorMessage = moveWriter->getLastErrorMessage();
    return lastErrorCode;
}


int ModelConvertor::getLastErrorCode(){
    return lastErrorCode;
}


const std::string& ModelConvertor::getLastErrorMessage(){
    return lastErrorMessage;
}


}
}
}
}
