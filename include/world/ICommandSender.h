#pragma once
#ifndef _TIGER_TRAINS_WORLD_I_COMMAND_SENDER_H_
#define _TIGER_TRAINS_WORLD_I_COMMAND_SENDER_H_


#include <models/MoveModel.h>
#include <models/UpgradeModel.h>


namespace tiger{
namespace trains{
namespace world{


class ICommandSender{

public:

    virtual ~ICommandSender(){}

    virtual void move(const models::MoveModel& move) = 0;
    virtual void upgrade(const models::UpgradeModel& upgrade) = 0;
    virtual void turn() = 0;

};


}
}
}


#endif
