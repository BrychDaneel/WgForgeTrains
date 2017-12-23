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


    trainA = new TrainAI(&busyLines, models::GoodType::PRODUCT    ,
                         world->getPlayerList()[0]->getTrains()[1]);
    listBotSegment.push_back(trainA);

    trainB = new TrainAI(&busyLines, models::GoodType::PRODUCT,
                         world->getPlayerList()[0]->getTrains()[0]);
    listBotSegment.push_back(trainB);
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::ARMOR,
                                         world->getPlayerList()[0]->getTrains()[2]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::ARMOR,
                                         world->getPlayerList()[0]->getTrains()[3]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::PRODUCT,
                                         world->getPlayerList()[0]->getTrains()[4]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::PRODUCT,
                                         world->getPlayerList()[0]->getTrains()[5]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::ARMOR    ,
                                         world->getPlayerList()[0]->getTrains()[6]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::ARMOR    ,
                                         world->getPlayerList()[0]->getTrains()[7]));




    listBotSegment.push_back(new UpgradeAI(world));
}


void ComplexBot::step()
{
    //world::Town *home = (world::Town *)world->getPlayerList()[0]->getHome();

    for (IBotSegment *subBot : listBotSegment)
        subBot->step();

}


}
}
}

