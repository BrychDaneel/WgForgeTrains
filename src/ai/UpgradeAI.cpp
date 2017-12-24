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

    std::vector<std::pair<world::IUpgradeble *, int>> upgradeVector;

    town = static_cast<world::Town *>(world->getPlayerList()[0]->getHome());

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        upgradeVector.push_back(std::make_pair(train, 2));

    upgradeVector.push_back(std::make_pair(town, 2));

    upgradeQueue.push(upgradeVector);
    upgradeVector.clear();

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        upgradeVector.push_back(std::make_pair(train, 3));

    upgradeVector.push_back(std::make_pair(town, 3));

    upgradeQueue.push(upgradeVector);
}


void UpgradeAI::step()
{
    int ar = town->getArrmor();

    if (upgradeQueue.empty())
        return;

    std::vector<std::pair<world::IUpgradeble *, int>> upgradeVector = upgradeQueue.front();

    int i = 0;

    while (i < upgradeVector.size())
    {
        world::IUpgradeble *target = upgradeVector[i].first;
        int level = upgradeVector[i].second;

        if (target->getLevel() + 1 == level &&
                target->getNextLevelPrice() < ar - RESERV_ARMOR &&
                target->isReadyToUpgrade())
        {
            target->upgrade();
            ar -= target->getNextLevelPrice();
            upgradeVector.erase(upgradeVector.begin() + i);
        }
        else
            i++;
    }

    if (upgradeVector.empty())
        upgradeQueue.pop();

}


}
}
}
