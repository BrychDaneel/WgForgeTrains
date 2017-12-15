#include <convertors/json/MoveWriter.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


/*
 * Error codes:
 *  -1 : unknown
 *  1 : buffer overflow
 */
int MoveWriter::writeMove(const models::MoveModel* move, char* buffer, int* bufferSize){
    nlohmann::json j;
    j["line_idx"] = move->getLineIdx();
    j["speed"] = move->getSpeedType();
    j["train_idx"] = move->getTrainIdx();

    std::string str = j.dump();
    const char* cstr = str.c_str();
    int len = strlen(cstr);
    if (len > *bufferSize){
        lastErrorCode = 1;
        lastErrorMessage = "Buffer is too small to convert move.";
        return lastErrorCode;
    }

    *bufferSize = len;
    for (int i=0; i<len; i++)
        buffer[i] = cstr[i];

    return 0;
}


int MoveWriter::getLastErrorCode(){
    return lastErrorCode;
}


const std::string& MoveWriter::getLastErrorMessage(){
    return lastErrorMessage;
}


}
}
}
}
