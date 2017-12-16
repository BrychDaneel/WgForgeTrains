#include <ai/TrainGoalPredictor.h>


namespace tiger{
namespace trains{
namespace ai{


TrainGoalPredictor::TrainGoalPredictor(world::World* world){
}


int TrainGoalPredictor::predictGoal(world::Train* train){
    return train->getPlayer()->getHome()->getIdx();
}


}
}
}
