#include <models/TrainModel.h>


namespace tiger{
namespace trains{
namespace models{

    TrainModel::TrainModel(){
    }

    TrainModel::TrainModel(const int idx, const int lineIdx, const int playerIdx, const int position, const SpeedType speed) :
        idx(idx), lineIdx(lineIdx), playerIdx(playerIdx), position(position), speed(speed)
    {
    }

    const int TrainModel::getIdx() const{
        return idx;
    }

    const int TrainModel::getLineIdx() const{
        return lineIdx;
    }

    const int TrainModel::getPlayerIdx() const{
        return playerIdx;
    }

    const int TrainModel::getPosition() const{
        return position;
    }

    const SpeedType TrainModel::getSpeed() const{
        return speed;
    }

    void TrainModel::setIdx(const int idx){
        this->idx = idx;
    }

    void TrainModel::setLineIdx(const int lineIdx){
        this->lineIdx = lineIdx;
    }

    void TrainModel::setPlayerIdx(const int playerIdx){
        this->playerIdx = playerIdx;
    }

    void TrainModel::setPosition(const int position){
        this->position = position;
    }

    void TrainModel::setSpeed(const SpeedType speed){
        this->speed = speed;
    }

}
}
}
