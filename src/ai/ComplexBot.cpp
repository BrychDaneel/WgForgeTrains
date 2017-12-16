#include <ai/ComplexBot.h>
#include <ai/TrainAI.h>
#include <ai/UpgradeAI.h>


namespace tiger{
namespace trains{
namespace ai{


ComplexBot::ComplexBot(){
}


void ComplexBot::init(world::World *world){
    this->world = world;

    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::PRODUCT,
                             world->getPlayerList()[0]->getTrains()[1]));
    listBotSegment.push_back(new TrainAI(&busyLines, models::GoodType::ARMOR,
                             world->getPlayerList()[0]->getTrains()[0]));

    listBotSegment.push_back(new UpgradeAI(world));
}


void ComplexBot::step(){

    for (IBotSegment* subBot : listBotSegment)
        subBot->step();
}


}
}
}

