#include <ai/UpgradeAI.h>
#include <easylogging++/easylogging++.h>


namespace tiger
{
namespace trains
{
namespace ai
{


UpgradeAI::UpgradeAI(const world::World* world) : world(world)
{
    world::Train* train0 = world->getPlayerList()[0]->getTrains()[0];
    world::Train* train1 = world->getPlayerList()[0]->getTrains()[1];
    town = static_cast<world::Town*>(world->getPlayerList()[0]->getHome());
    upgradeQueue.push(train0);
    upgradeQueue.push(train1);
    upgradeQueue.push(town);
    upgradeQueue.push(train0);
    upgradeQueue.push(train1);
    upgradeQueue.push(town);
}


void UpgradeAI::step()
{
    int ar = town->getArrmor();
    while (!upgradeQueue.empty() && ar - upgradeQueue.front()->getNextLevelPrice() >= RESERV_ARMOR){
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
