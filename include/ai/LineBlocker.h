#pragma once

#include <set>
#include <world/World.h>
#include <ai/LineBlock.h>
#include <ai/BotSharedData.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class LineBlocker
{
public:
    LineBlocker(world::Train *train, models::GoodType type, BotSharedData *data);
    void makeOwnBlockLines();
    void changeCurrentBlock(const std::vector<const world::Point *> &points);
    bool contain(LineBlock lineBlock);
    void changeType(models::GoodType type);
    void addBlockLine(std::pair<int, LineBlock> block);


private:
    world::Train *train;
    models::GoodType type;
    BotSharedData *sharedData;

    std::set<std::pair<int, LineBlock> > *blockLines;
    std::set<LineBlock> ownBlockLine;
    std::vector<std::pair<int,LineBlock> > currentBlock;





    models::PostType getPostTypeByGood(models::GoodType type);


};





}
}
}
