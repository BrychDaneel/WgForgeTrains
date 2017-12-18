#pragma once


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
