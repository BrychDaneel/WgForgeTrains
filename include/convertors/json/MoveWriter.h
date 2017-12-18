#pragma once


#include <convertors/IMoveWriter.h>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


class MoveWriter : public IMoveWriter
{
public:

    int writeMove(const models::MoveModel* move, char* buffer,  int* bufferSize);

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
