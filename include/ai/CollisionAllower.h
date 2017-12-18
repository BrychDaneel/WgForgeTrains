#pragma once


#include <world/World.h>


namespace tiger
{
namespace trains
{
namespace ai
{


class CollisionAllower
{
public:
    CollisionAllower();

    bool isCollisionAllow(const world::Train *train,const world::Train *otherTrain);

private:

    const float ARMOR_WEIGHT = 1;
    const float PRODUCT_WEIGHT = 2;

};


}
}
}
