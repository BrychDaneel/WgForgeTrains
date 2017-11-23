#include <models/MoveModel.h>


namespace tiger{
namespace trains{
namespace models{

    MoveModel::MoveModel(const int lineIdx, const int trainIdx, const SpeedType speedType):
        lineIdx(lineIdx), trainIdx(trainIdx), speedType(speedType){
    }

    const int MoveModel::getLineIdx() const{
        return lineIdx;
    }

    const int MoveModel::getTrainIdx() const{
        return trainIdx;
    }

    const SpeedType MoveModel::getSpeedType() const{
        return speedType;
    }

}
}
}
