#include <world/Train.h>


namespace tiger{
namespace trains{
namespace world{

    Train::Train(){
    }

    Train::Train(const models::TrainModel& model, World* world){
        owner = world;

        idx = model.getIdx();
        player = owner->getPlayerByIdx(model.getPlayerIdx());

        if (model.isInLine())
            line = owner->getLineByIdx(model.getLineIdx());

        speed = model.getSpeed();
        position = model.getPosition();
    }

    void Train::update(models::TrainModel model){
        if (model.isInLine())
            line = owner->getLineByIdx(model.getLineIdx());

        speed = model.getSpeed();
        position = model.getPosition();
    }


    World* Train::getWorld() const{
        return owner;
    }


    int Train::getIdx() const{
        return idx;
    }

    Player * Train::getPlayer() const{
        return player;
    }

    Line * Train::getLine() const{
        return line;
    }

    int Train::getPosition() const{
        return position;
    }

    models::SpeedType Train::getSpeed() const{
        return speed;
    }

}
}
}