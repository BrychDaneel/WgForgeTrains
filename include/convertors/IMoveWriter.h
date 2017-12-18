#pragma once

#include <models/MoveModel.h>
#include <string>


namespace tiger
{
namespace trains
{
namespace convertors
{


struct IMoveWriter
{
    virtual ~IMoveWriter() {}

    virtual int writeMove(const models::MoveModel *move, char *buffer, int *bufferSize) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string &getLastErrorMessage() = 0;
};


}
}
}
