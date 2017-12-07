#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_UPGRADE_WRITER_H_
#define _TIGER_TRAINS_MODELS_JSON_UPGRADE_WRITER_H_


#include <convertors/IUpgradeWriter.h>


namespace tiger{
namespace trains{
namespace convertors{


struct UpgradeWriter : public IUpgradeWriter{

    int writeUpgrade(const models::UpgradeModel* upgrade, char* buffer, int* bufferSize);

    int getLastErrorCode();
    const std::string& getLastErrorMessage();

private:

    int lastErrorCode;
    std::string lastErrorMessage;

};


}
}
}


#endif


