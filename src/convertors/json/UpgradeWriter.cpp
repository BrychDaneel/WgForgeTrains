#include <convertors/json/UpgradeWriter.h>
#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{


/*
 * Error codes:
 *  -1 : unknown
 *  1 : buffer overflow
 */

int UpgradeWriter::writeUpgrade(const models::UpgradeModel* upgrade, char* buffer, int* bufferSize){
    nlohmann::json jupgrade;

    nlohmann::json jtrainIdxs;
    for (int tidx : upgrade->getTrainIdxList())
        jtrainIdxs.push_back(tidx);

    nlohmann::json jpostIdxs;
    for (int pidx : upgrade->getPostIdxList())
        jpostIdxs.push_back(pidx);

    jupgrade["post"] = jtrainIdxs;
    jupgrade["train"] = jpostIdxs;

    std::string str = jupgrade.dump();
    const char* cstr = str.c_str();
    int len = strlen(cstr);
    if (len > *bufferSize){
        lastErrorCode = 1;
        lastErrorMessage = "Buffer is too smal to convert upgrade.";
        return lastErrorCode;
    }

    *bufferSize = len;
    for (int i=0; i<len; i++)
        buffer[i] = cstr[i];

    return 0;
}


int UpgradeWriter::getLastErrorCode(){
    return lastErrorCode;
}


const std::string& UpgradeWriter::getLastErrorMessage(){
    return lastErrorMessage;
}


}
}
}
