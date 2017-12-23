#include <ai/UpgradeAI.h>
#include <easylogging++/easylogging++.h>


namespace tiger
{
namespace trains
{
namespace ai
{


UpgradeAI::UpgradeAI(const world::World *world) : world(world)
{
    town = static_cast<world::Town *>(world->getPlayerList()[0]->getHome());

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        upgradeQueue.push_back(std::make_pair(train, 2));

    upgradeQueue.push_back(std::make_pair(town, 2));

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        upgradeQueue.push_back(std::make_pair(train, 3));

    upgradeQueue.push_back(std::make_pair(town, 3));
}


void UpgradeAI::step()
{
    int ar = town->getArrmor();

    if (upgradeQueue.empty())
        return;

    auto p = upgradeQueue.begin();

    while (p != upgradeQueue.end())
    {
        world::IUpgradeble *target = p->first;
        int level = p->second;

        if (target->getLevel() + 1 == level &&
                target->getNextLevelPrice() < ar &&
                target->isReadyToUpgrade())
        {
            target->upgrade();
            ar -= target->getNextLevelPrice();
        }

        p++;
    }

}


}
}
}
