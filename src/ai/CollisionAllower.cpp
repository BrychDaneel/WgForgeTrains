#include <ai/CollisionAllower.h>


namespace tiger{
namespace trains{
namespace ai{


CollisionAllower::CollisionAllower(world::World* world){

}


bool CollisionAllower::isCollisionAllow(world::Train* firstTrain, world::Train* secondTrain){
    return false;
}


}
}
}
