#include <convertors/json/CoordsMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json {


int CoordsMapReader::readCoordsMap(const char* buffer, const int bufferSize,
                                   std::vector<models::CoordModel>& coordsMap)
{
    std::string str;
    try{
        str.assign(buffer, bufferSize);
    }
    catch (...){
        lastErrorCode = 1;
        lastErrorMessage = "Can't conver buffer to string";
        return lastErrorCode;
    }

    nlohmann::json jmap;
    try{
        jmap = nlohmann::json::parse(str);
    }
    catch (const nlohmann::json::parse_error& e){
        lastErrorCode = 2;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }

    coordsMap.clear();

    try{
        for (nlohmann::json jcord : jmap["point"]){
            models::CoordModel coord;
            coord.idx = jcord["idx"];
            coord.x = jcord["x"];
            coord.y = jcord["y"];

            coordsMap.push_back(coord);
        }

    }
    catch(const nlohmann::json::type_error& e){
        lastErrorCode = 3;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }
    catch(...){
        lastErrorCode = -1;
        lastErrorMessage = "Unknown parse data error.";
        return lastErrorCode;
    }

    return 0;
}


int CoordsMapReader::getLastErrorCode(){
    return lastErrorCode;
}


const std::string& CoordsMapReader::getLastErrorMessage(){
    return lastErrorMessage;
}


}
}
}
}
