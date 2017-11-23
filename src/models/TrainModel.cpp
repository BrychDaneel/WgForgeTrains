#include <models/TrainModel.h>


namespace tiger{
namespace trains{
namespace models{

    TrainModel::TrainModel(const int idx, const int lineIdx, const int playerIdx, const int position, const int speed) :
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

    const int TrainModel::getSpeed() const{
        return speed;
    }

}
}
}
