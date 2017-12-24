#pragma once


#include <convertors/IStaticMapReader.h>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


class StaticMapReader : public IStaticMapReader
{

public:

    int readStaticMap(const char *buffer, const int bufferSize, models::StaticMap *staticMap);

    int getLastErrorCode();
    const std::string &getLastErrorMessage();

private:

    int lastErrorCode;
    std::string lastErrorMessage;

};


}
}
}
}
