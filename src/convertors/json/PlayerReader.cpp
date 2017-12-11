#include <convertors/json/PlayerReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

/*
 * Errors:
 * -1 unknown error
 * 1 - bad buffer
 * 2 - bad json
 * 3 - value error
 * 4 - player is empty
 */
int PlayerReader::readPlayer(const char* buffer, const int bufferSize, models::PlayerModel* playerModel){
    string str;
    try{
        str.assign(buffer, bufferSize);
    }
    catch (...){
        lastErrorCode = 1;
        lastErrorMessage = "Can't conver buffer to string";
        return lastErrorCode;
    }

    nlohmann::json j;
    try{
        j = nlohmann::json::parse(str);
    }
    catch (const nlohmann::json::parse_error& e){
        lastErrorCode = 2;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }

    try{

        if (j.find("home") != j.end() && j["home"].is_null()){
            lastErrorCode = 4;
            lastErrorMessage = "Player is empty";
            return lastErrorCode;
        }

        playerModel->setIdx(j["idx"]);
        playerModel->setHome(j["home"]["post_id"]);
        playerModel->setName(j["name"]);

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


int PlayerReader::getLastErrorCode(){
    return lastErrorCode;
}


const std::string& PlayerReader::getLastErrorMessage(){
    return lastErrorMessage;
}


}
}
}
}
