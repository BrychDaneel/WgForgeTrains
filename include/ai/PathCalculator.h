#pragma once


#include <set>
#include <map>
#include <vector>
#include <world/World.h>
#include <ai/LineBlocker.h>
#include <ai/BotSharedData.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class PathCalculator
{
public:
    PathCalculator(world::Train *train, BotSharedData *sharedData);
    void calculate(LineBlocker &blocker);
    std::vector<const world::Point *> getMinPath(const world::Point *point);
    int getMinLen(const world::Point *point);

private:

    void startInit(LineBlocker &blocker,
                   std::set< std::pair<int, const world::Point *>> &setMinLen);
    void startOnPoint(LineBlocker &blocker,
                      std::set< std::pair<int, const world::Point *>> &setMinLen);
    void startOnLine(std::set< std::pair<int, const world::Point *>> &setMinLen);
    world::Train *train;
    BotSharedData *sharedData;
    std::map<const world::Point *, int> minLen;
    std::map<const world::Point *, const world::Point *> ancestors;


};




}
}
}
