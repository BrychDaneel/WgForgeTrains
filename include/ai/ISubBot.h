#pragma once


#include <CommandSender.h>
#include <world/World.h>


namespace tiger
{
namespace trains
{
namespace ai
{


class ISubBot
{
public:

    virtual ~ISubBot() {}
    virtual void step() = 0;

};


}
}
}
