#include <models/TrainModel.h>


namespace tiger{
namespace trains{
namespace models{


TrainModel::TrainModel(){
}


TrainModel::TrainModel(const int idx, const int lineIdx, const string playerIdx,
                       const int position, const int goodsCapacity,
                       const int goods, const GoodType goodsType,
                       const int level, const int nextLevelPrice,
                       const SpeedType speed) :
    idx(idx), lineIdx(lineIdx), playerIdx(playerIdx), position(position),
    speed(speed), goodsCapacity(goodsCapacity),
    goods(goods), goodsType(goodsType),
    level(level), nextLevelPrice(nextLevelPrice)
{
}


int TrainModel::getIdx() const{
    return idx;
}


int TrainModel::getLineIdx() const{
    return lineIdx;
}


const string& TrainModel::getPlayerIdx() const{
    return playerIdx;
}


int TrainModel::getPosition() const{
    return position;
}


int TrainModel::getGoodsCapacity() const{
    return goodsCapacity;
}


int TrainModel::getGoods() const{
    return goods;
}

GoodType TrainModel::getGoodsType() const{
    return goodsType;
}


SpeedType TrainModel::getSpeed() const{
    return speed;
}


int TrainModel::getLevel() const{
    return level;
}


int TrainModel::getNextLevelPrice() const{
    return nextLevelPrice;
}


void TrainModel::setIdx(const int idx){
    this->idx = idx;
}


void TrainModel::setLineIdx(const int lineIdx){
    this->lineIdx = lineIdx;
}


void TrainModel::setPlayerIdx(const string playerIdx){
    this->playerIdx = playerIdx;
}


void TrainModel::setPosition(const int position){
    this->position = position;
}


void TrainModel::setGoodsCapacity(const int capacity){
    this->goodsCapacity = capacity;
}


void TrainModel::setGoods(const int goods){
    this->goods = goods;
}


void TrainModel::setSpeed(const SpeedType speed){
    this->speed = speed;
}


void TrainModel::setLevel(const int level){
    this->level = level;
}


void TrainModel::setNextLevelPrice(const int nextLevelPrice){
    this->nextLevelPrice = nextLevelPrice;
}


void TrainModel::setGoodsType(const GoodType type){
    this->goodsType = type;
}


void TrainModel::addEvent(const EventModel& event){
    eventList.push_back(event);
}


void TrainModel::clearEventList(){
    eventList.clear();
}


const std::vector<EventModel>& TrainModel::getEventList() const{
    return eventList;
}


}
}
}
