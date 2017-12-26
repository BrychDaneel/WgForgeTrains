#pragma once

#include <CommandSender.h>
#include <world/World.h>

namespace tiger
{
namespace trains
{
namespace ai
{


struct IBot
{
    virtual ~IBot() {}
    virtual void init(world::World *world) = 0;
    virtual void step() = 0;

};


}
}
}
