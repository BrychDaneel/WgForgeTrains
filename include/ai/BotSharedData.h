#pragma once

#include <set>
#include <world/World.h>
#include <ai/HomeChecker.h>
#include <ai/LineBlock.h>
#include <ai/Barrier.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class BotSharedData
{
public:
    BotSharedData();

    void init(const world::World *world);
    void clear(world::World *world);
    std::set<std::pair<int, LineBlock> > *getBlockLines();
    bool doMove(const world::Point *point, const world::Line *line);
    bool canMove(const world::Point *point, const world::Line *line);
    std::set<const world::Point *> *getInPoints();
    std::map<const world::Train *,const world::Point *> *getTrainInPoints();

    HomeChecker *getCheker();


private:
    std::set<const world::Point *> inPoints;
    std::set<std::pair<int, LineBlock> > blockLines;
    std::map<const world::Point *, Barrier> barrierMap;
    std::map<const world::Train *,const world::Point *> trainInPoints;
    HomeChecker cheker;

};




}
}
}
