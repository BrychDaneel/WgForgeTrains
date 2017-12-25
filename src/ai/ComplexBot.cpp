#include <ai/ComplexBot.h>
#include <ai/TrainAI.h>
#include <ai/UpgradeAI.h>
#include <ai/SwitchAI.h>


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

    std::vector<TrainAI *> trainsAI;

    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT    ,
                                   world->getPlayerList()[0]->getTrains()[1]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT,
                                   world->getPlayerList()[0]->getTrains()[0]));

    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR,
                                   world->getPlayerList()[0]->getTrains()[2]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR,
                                   world->getPlayerList()[0]->getTrains()[3]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT,
                                   world->getPlayerList()[0]->getTrains()[4]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::PRODUCT,
                                   world->getPlayerList()[0]->getTrains()[5]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR    ,
                                   world->getPlayerList()[0]->getTrains()[6]));
    trainsAI.push_back(new TrainAI(&sharedData, models::GoodType::ARMOR    ,
                                   world->getPlayerList()[0]->getTrains()[7]));

    listSubBot.push_back(new SwitchAI(world, trainsAI));

    for (ISubBot *bot : trainsAI)
        listSubBot.push_back(bot);

    listSubBot.push_back(new UpgradeAI(world));
}


void ComplexBot::step()
{
    //world::Town *home = (world::Town *)world->getPlayerList()[0]->getHome();


    for (ISubBot *subBot : listSubBot)
        subBot->step();

    for (world::Train *train : world->getPlayerList()[0]->getTrains())
        if (train->getMove() != nullptr)
            world->getCommandSender()->move(*train->getMove());

}


}
}
}

