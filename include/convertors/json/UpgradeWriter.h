#pragma once


#include <convertors/IUpgradeWriter.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


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
}
