#pragma once


#include <world/World.h>


namespace tiger{
namespace trains{
namespace ai{


class TrainGoalPredictor{

    TrainGoalPredictor();

    std::pair<world::IPost*, int> predictGoal(const world::Train* train);

};


}
}
}
