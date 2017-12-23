#pragma once


#include <CommandSender.h>
#include <ai/IBotSegment.h>
#include <world/World.h>
#include <world/IUpgradeble.h>
#include <vector>
#include <world/Town.h>
#include <queue>


namespace tiger
{
namespace trains
{
namespace ai
{


class UpgradeAI: public IBotSegment
{

    world::Town *town;
    const world::World *world;
    const int RESERV_ARMOR = 0;
    std::vector<std::pair<world::IUpgradeble *, int>> upgradeQueue;  // <target, level>

public:
    explicit UpgradeAI(const world::World *world);
    void step();

};


}
}
}
