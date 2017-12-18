#pragma once


#include <convertors/ICoordsMapReader.h>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


struct CoordsMapReader : public ICoordsMapReader
{
    virtual int readCoordsMap(const char* buffer, const int bufferSize, models::CoordsMap* coordsMap);

    virtual int getLastErrorCode();
    virtual const std::string& getLastErrorMessage();

private:

    int lastErrorCode;
    std::string lastErrorMessage;

};


}
}
}
}
