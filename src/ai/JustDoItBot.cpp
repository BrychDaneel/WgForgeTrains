#include <ai/JustDoItBot.h>
#include <world/Train.h>
#include <models/SpeedType.h>
#include <easylogging++.h>

using namespace tiger::trains::ai;

JustDoItBot::JustDoItBot():world(nullptr),tick(0)
{

}

void JustDoItBot::init(world::World *world)
{
    this->world = world;
    Post post(world->getPlayerList()[0]->getHome()->getPoint());
    post.init(*world);

    for (auto point : world->getPointList())
    {
        LOG(INFO) << point->getIdx() << " " << post.getMinLen(point);
    }
}
void JustDoItBot::step()
{
    world::Train * train = world->getTrainList()[0];
    if (tick == 0)
        train->move(world->getLineByIdx(1), models::SpeedType::FORWARD);
    if (tick == 11)
        train->move(world->getLineByIdx(1), models::SpeedType::REVERSE);

    ++tick;

}
