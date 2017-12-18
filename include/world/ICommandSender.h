#pragma once


#include <models/MoveModel.h>
#include <models/UpgradeModel.h>


namespace tiger
{
namespace trains
{
namespace world
{


struct ICommandSender
{
    virtual ~ICommandSender() {}

    virtual void move(const models::MoveModel &move) = 0;
    virtual bool upgrade(const models::UpgradeModel &upgrade) = 0;
    virtual void turn() = 0;

};


}
}
}
