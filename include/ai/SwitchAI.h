#pragma once


#include <ai/ISubBot.h>
#include <ai/TrainAI.h>
#include <vector>


namespace tiger
{
namespace trains
{
namespace ai
{



class SwitchAI : public ISubBot
{
public:

    SwitchAI(const world::World *world, const std::vector<TrainAI *> &trainAIList);
    void step();

private:

    const world::World *world;
    std::vector<TrainAI *> armorBots;
    std::vector<TrainAI *> productBots;

    bool canSwitch(TrainAI *bot);

};


}
}
}
