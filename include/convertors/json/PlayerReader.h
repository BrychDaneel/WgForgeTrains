#pragma once


#include <convertors/IPlayerReader.h>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


class PlayerReader : public IPlayerReader
{
public:

    int readPlayer(const char *buffer, const int bufferSize, models::PlayerModel *playerModel);

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
