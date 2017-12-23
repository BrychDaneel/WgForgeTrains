#pragma once


#include <set>
#include <map>
#include <vector>
#include <world/World.h>
#include <ai/LineBlocker.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class PathCalculator
{
public:
    PathCalculator(world::Train *train);
    void calculate(LineBlocker &blocker);
    std::vector<const world::Point *> getMinPath(const world::Point *point);
    int getMinLen(const world::Point *point);

private:

    world::Train *train;
    std::map<const world::Point *, int> minLen;
    std::map<const world::Point *, const world::Point *> ancestors;


};




}
}
}
