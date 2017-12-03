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
    else
        line = nullptr;

    speed = model.getSpeed();
    position = model.getPosition();
    capacity = model.getCapacity();
    product = model.getProduct();
}


void Train::update(models::TrainModel model){
    if (model.isInLine())
        line = owner->getLineByIdx(model.getLineIdx());
    else
        line = nullptr;

    speed = model.getSpeed();
    position = model.getPosition();
    capacity = model.getCapacity();
    product = model.getProduct();
}


World* Train::getWorld() const{
    return owner;
}


int Train::getIdx() const{
    return idx;
}


Player* Train::getPlayer() const{
    return player;
}


Line* Train::getLine() const{
    return line;
}


int Train::getPosition() const{
    return position;
}


int Train::getCapacity() const{
    return capacity;
}


int Train::getProduct() const{
    return product;
}


Point *Train::getPoint() const{

    if (line == nullptr){
        return player->getHome()->getPoint();
    }

    if (position == 0){

        return line->getStartPont();
    }

    if (position == line->getLenght())
    {
        return line->getEndPont();
    }

    return nullptr;

}

models::SpeedType Train::getSpeed() const{
    return speed;
}


void Train::move(Line* line, models::SpeedType speed){
    models::MoveModel moveModel(line->getIdx(), idx, speed);
    owner->getCommandSender()->move(moveModel);
}


}
}
}
