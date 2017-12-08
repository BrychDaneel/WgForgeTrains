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

    update(model);
}


void Train::update(models::TrainModel model){
    line = owner->getLineByIdx(model.getLineIdx());

    speed = model.getSpeed();
    position = model.getPosition();
    goodsCapacity = model.getGoodsCapacity();
    goods = model.getGoods();

    goodsType = model.getGoodsType();
    level = model.getLevel();
    nextLevelPrice = model.getNextLevelPrice();
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


int Train::getGoodsCapacity() const{
    return goodsCapacity;
}


int Train::getGoods() const{
    return goods;
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


void Train::addEvent(IEvent* event){
    eventsHistory.push_back(event);
}


void Train::clearEvents(){
    eventsHistory.clear();
}


const std::vector<IEvent*>& Train::getEvents() const{
    return eventsHistory;
}


models::GoodType Train::getGoodsType() const{
    return goodsType;
}


int Train::getLevel() const{
    return level;
}


int Train::getNextLevelPrice() const{
    return nextLevelPrice;
}


}
}
}
