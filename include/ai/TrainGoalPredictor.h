#pragma once


#include <world/World.h>


namespace tiger{
namespace trains{
namespace ai{


class TrainGoalPredictor{

    TrainGoalPredictor();

    world::IPost* predictGoal(const world::Train* train);

};


}
}
}
