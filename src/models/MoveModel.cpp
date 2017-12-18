#include <models/MoveModel.h>


namespace tiger
{
namespace trains
{
namespace models
{


MoveModel::MoveModel()
{
}


MoveModel::MoveModel(const int lineIdx, const int trainIdx, const SpeedType speedType)
    : lineIdx(lineIdx), trainIdx(trainIdx), speedType(speedType)
{
}


int MoveModel::getLineIdx() const
{
    return lineIdx;
}


int MoveModel::getTrainIdx() const
{
    return trainIdx;
}


SpeedType MoveModel::getSpeedType() const
{
    return speedType;
}


void MoveModel::setLineIdx(const int lineIdx)
{
    this->lineIdx = lineIdx;
}


void MoveModel::setTrainIdx(const int trainIdx)
{
    this->trainIdx = trainIdx;
}


void MoveModel::setSpeedType(const SpeedType speedType)
{
    this->speedType = speedType;
}


}
}
}
