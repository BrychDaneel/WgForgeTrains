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
    std::set<std::pair<int, LineBlock> > *getBlockLines();
    bool doMove(const world::Point *point, const world::Line *line);
    bool canMove(const world::Point *point, const world::Line *line);
    std::set<world::Point *> *getInPoints();

    HomeChecker *getCheker();


private:
    std::set<world::Point *> inPoints;
    std::set<std::pair<int, LineBlock> > blockLines;
    std::map<const world::Point *, Barrier> barrierMap;
    HomeChecker cheker;

};




}
}
}
