#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_DYNAMIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_JSON_DYNAMIC_MAP_READER_H_


#include <convertors/IDynamicMapReader.h>
#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


class DynamicMapReader : public IDynamicMapReader{

public:

    int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap);
    int getLastErrorCode();
    const std::string& getLastErrorMessage();

private:

    void readEvent(const nlohmann::json& jevent, models::EventModel* event);
    void readTrain(const nlohmann::json& jtrain, models::TrainModel* train);
    void readPost(const nlohmann::json& jpost, models::PostModel* post);
    void readTown(const nlohmann::json& jtown, models::PostModel* post);
    void readMarket(const nlohmann::json& jmarket, models::PostModel* post);
    void readStorage(const nlohmann::json& jstorage, models::PostModel* post);

    int lastErrorCode;
    std::string lastErrorMessage;

};


}
}
}
}


#endif
