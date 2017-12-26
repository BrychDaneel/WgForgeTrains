#pragma once


#include <ai/ISubBot.h>
#include <ai/TrainAI.h>
#include <map>
#include <vector>
#include <set>
#include <world/World.h>
#include <ai/IBot.h>
#include <ai/BotSharedData.h>


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
        for (auto subBot : listSubBot)
        {
            delete subBot;
        }
    }

private:

    world::World *world;

    std::vector<ISubBot * > listSubBot;
    BotSharedData sharedData;
    TrainAI *trainA;
    TrainAI *trainB;

};


}
}
}
