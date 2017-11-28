#pragma once
#ifndef _TIGER_TRAINS_WORLD_I_COMMAND_SENDER_H_
#define _TIGER_TRAINS_WORLD_I_COMMAND_SENDER_H_


#include <models/MoveModel.h>

namespace tiger{
namespace trains{
namespace world{

    class ICommandSender{
        public:
            virtual void move(const models::MoveModel &move) = 0;
            virtual ~ICommandSender(){};
    };
}
}
}



#endif


