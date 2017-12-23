#pragma once

#include <set>
#include <world/World.h>
#include <ai/HomeChecker.h>

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

    std::set<std::pair<int, const world::Line *> > *getBlockLines();

    HomeChecker *getCheker();

private:
    std::set<std::pair<int, const world::Line *>> blockLines;
    HomeChecker cheker;

};




}
}
}
