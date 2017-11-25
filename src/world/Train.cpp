#include <world/Train.h>


namespace tiger{
namespace trains{
namespace world{

    Train::Train(){
    }

    Train::Train(const models::TrainModel& model, World* owner){
    }

    void Train::upadte(models::TrainModel model){
    }


    World* Train::getWorld() const{
    }


    int Train::getIdx() const{
    }

    Player * Train::getPlayer() const{
    }

    Line * Train::getLine() const{
    }

    int Train::getPosition() const{
    }

    models::SpeedType Train::getSpeed() const{
    }

}
}
}
