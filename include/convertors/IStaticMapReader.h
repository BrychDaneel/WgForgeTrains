#pragma once


#include <models/StaticMap.h>


namespace tiger
{
namespace trains
{
namespace convertors
{


struct IStaticMapReader
{
    virtual ~IStaticMapReader() {}

    virtual int readStaticMap(const char *buffer, const int bufferSize, models::StaticMap *staticMap) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string &getLastErrorMessage() = 0;
};


}
}
}
