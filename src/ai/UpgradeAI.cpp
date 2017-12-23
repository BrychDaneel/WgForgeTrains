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
        upgradeQueue.push(train);

    upgradeQueue.push(town);

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        upgradeQueue.push(train);

    upgradeQueue.push(town);
}


void UpgradeAI::step()
{
    int ar = town->getArrmor();

    while (!upgradeQueue.empty() && ar - upgradeQueue.front()->getNextLevelPrice() >= RESERV_ARMOR)
    {
        ar -= upgradeQueue.front()->getNextLevelPrice();

        if (upgradeQueue.front()->upgrade())
            upgradeQueue.pop();
        else
            LOG(ERROR) << "Can't apply update that coasts " << upgradeQueue.front()->getNextLevelPrice()
                       << " when have " << ar + upgradeQueue.front()->getNextLevelPrice();
    }
}


}
}
}
