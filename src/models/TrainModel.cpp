#include <models/TrainModel.h>


namespace tiger{
namespace trains{
namespace models{

    TrainModel::TrainModel(){
    }

    TrainModel::TrainModel(const int idx, const int lineIdx,
                           const string playerIdx, const int position,
                           const int capacity, const int product,
                           const SpeedType speed) :
        idx(idx), lineIdx(lineIdx), playerIdx(playerIdx), position(position),
        capacity(capacity), product(product), speed(speed)
    {
    }

    int TrainModel::getIdx() const{
        return idx;
    }

    int TrainModel::getLineIdx() const{
        return lineIdx;
    }

    const string TrainModel::getPlayerIdx() const{
        return playerIdx;
    }

    int TrainModel::getPosition() const{
        return position;
    }

    int TrainModel::getCapacity() const{
        return capacity;
    }

    int TrainModel::getProduct() const{
        return product;
    }

    SpeedType TrainModel::getSpeed() const{
        return speed;
    }

    bool TrainModel::isInLine() const{
        return lineIdx != 0;
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

    void TrainModel::setCapacity(const int capacity){
        this->capacity = capacity;
    }

    void TrainModel::setProduct(const int product){
        this->product = product;
    }

    void TrainModel::setSpeed(const SpeedType speed){
        this->speed = speed;
    }

}
}
}
