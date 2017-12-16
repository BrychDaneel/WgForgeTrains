#include <ai/UpgradeAI.h>


namespace tiger{
namespace trains{
namespace ai{


UpgradeAI::UpgradeAI(const world::World* world) : world(world){
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


void UpgradeAI::step(){
    if (upgradeQueue.empty())
        return;

   /* if (town->getArrmor() - upgradeQueue.front()->getNextLevelPrice() >= RESERV_ARMOR){
        upgradeQueue.front()->upgrade();
        upgradeQueue.pop();
    }*/

    while (upgradeQueue.front()->upgrade())
    {
        upgradeQueue.pop();
    }
}


}
}
}
