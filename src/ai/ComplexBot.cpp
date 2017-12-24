#include <ai/ComplexBot.h>
#include <ai/TrainAI.h>
#include <ai/UpgradeAI.h>


namespace tiger
{
namespace trains
{
namespace ai
{


ComplexBot::ComplexBot()
{
}


void ComplexBot::init(world::World *world)
{
    this->world = world;

    sharedData.init(world);

    trainA = new TrainAI(&sharedData, models::GoodType::PRODUCT    ,
                         world->getPlayerList()[0]->getTrains()[1]);
    listSubBot.push_back(trainA);

    trainB = new TrainAI(&sharedData, models::GoodType::PRODUCT,
                         world->getPlayerList()[0]->getTrains()[0]);
    listSubBot.push_back(trainB);
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR,
                                     world->getPlayerList()[0]->getTrains()[2]));
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR,
                                     world->getPlayerList()[0]->getTrains()[3]));
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT,
                                     world->getPlayerList()[0]->getTrains()[4]));
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT,
                                     world->getPlayerList()[0]->getTrains()[5]));
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR    ,
                                     world->getPlayerList()[0]->getTrains()[6]));
    listSubBot.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR    ,
                                     world->getPlayerList()[0]->getTrains()[7]));




    listSubBot.push_back(new UpgradeAI(world));
}


void ComplexBot::step()
{
    //world::Town *home = (world::Town *)world->getPlayerList()[0]->getHome();

    for (ISubBot *subBot : listSubBot)
        subBot->step();

}


}
}
}

