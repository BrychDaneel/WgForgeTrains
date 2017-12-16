#pragma once


#include <world/World.h>


namespace tiger{
namespace trains{
namespace ai{


class CollisionAllower{

    CollisionAllower(world::World* world);

    bool isCollisionAllow(world::Train* firstTrain, world::Train* secondTrain);

};


}
}
}
