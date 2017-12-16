#pragma once


#include <world/World.h>


namespace tiger{
namespace trains{
namespace ai{


class TrainGoalPredictor{

    TrainGoalPredictor(world::World* world);

    int predictGoal(world::Train* train);

};


}
}
}
