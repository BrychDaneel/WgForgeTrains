#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_MODEL_CONVERTOR_H_
#define _TIGER_TRAINS_MODELS_JSON_MODEL_CONVERTOR_H_


#include <convertors/IModelConvertor.h>


#include <convertors/IDynamicMapReader.h>
#include <convertors/IStaticMapReader.h>
#include <convertors/IPlayerReader.h>
#include <convertors/IMoveWriter.h>


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

public:

    ModelConvertor();

    ~ModelConvertor();

    int readStaticMap(const char* buffer, const int bufferSize, models::StaticMap* staticMap);
    int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap);
    int readPlayer(const char* buffer, const int bufferSize, models::PlayerModel* playerModel);
    int writeMove(const models::MoveModel* move, char* buffer, int* bufferSize);

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


#endif
