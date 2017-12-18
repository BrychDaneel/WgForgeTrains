#pragma once


#include <ai/IBotSegment.h>
#include <ai/TrainAI.h>
#include <map>
#include <vector>
#include <set>
#include <world/World.h>
#include <ai/IBot.h>


namespace tiger
{
namespace trains
{
namespace ai
{


class ComplexBot: public IBot
{
public:

    ComplexBot();
    void init(world::World *world);
    void step();
    ~ComplexBot()
    {
        for (auto botSegment : listBotSegment)
        {
            delete botSegment;
        }
    }

private:

    world::World *world;

    std::vector<IBotSegment* > listBotSegment;
    std::set<std::pair<int ,const world::Line *>> busyLines;
    TrainAI *trainA;
    TrainAI *trainB;

};


}
}
}
