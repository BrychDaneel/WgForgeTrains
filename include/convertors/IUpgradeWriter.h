#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_UPGRADE_WRITER_H_
#define _TIGER_TRAINS_MODELS_I_UPGRADE_WRITER_H_


#include <models/UpgradeModel.h>
#include <string>


namespace tiger{
namespace trains{
namespace convertors{


struct IUpgradeWriter{

    virtual ~IUpgradeWriter(){}

    virtual int writeUpgrade(const models::UpgradeModel* upgrade, char* buffer, int* bufferSize) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string& getLastErrorMessage() = 0;
};


}
}
}


#endif

