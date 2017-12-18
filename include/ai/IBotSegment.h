#pragma once


#include <CommandSender.h>
#include <world/World.h>


namespace tiger
{
namespace trains
{
namespace ai
{


class IBotSegment
{
public:

    virtual ~IBotSegment() {}
    virtual void step() = 0;

};


}
}
}
