#pragma once


#include <CommandSender.h>
#include <ai/ISubBot.h>
#include <vector>
#include <set>
#include <world/Player.h>
#include <world/Train.h>
#include <models/GoodType.h>
#include <models/PostType.h>
#include <ai/BotSharedData.h>
#include <ai/PathCalculator.h>
#include <ai/LineBlocker.h>


namespace tiger
{
namespace trains
{
namespace ai
{


class TrainAI: public ISubBot
{
public:
    TrainAI(BotSharedData *data, models::GoodType type, world::Train *train);
    void step();

    void changeType(models::GoodType type);
    models::GoodType getType();
    world::Train *getTrain();

private:

    void makeMove();
    int calculateProducts(int tick, world::IPost *post);

    void makePath(const world::World &world);
    void makeGoalPredict(const world::World &world);

    models::PostType getPostTypeByGood(models::GoodType type);

    BotSharedData *sharedData;
    models::GoodType type;
    world::Train *train;
    LineBlocker lineBlocker;
    PathCalculator pathCalculator;
    const world::Point *lastPoint;
    const world::Point *nextPoint;

    std::vector<const world::Point *> currentPath;
    std::vector<std::pair<const world::IPost *, int>> goalPredict;

    int id;


};


}
}
}
