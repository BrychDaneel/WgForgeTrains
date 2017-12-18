#pragma once


#include <models/SpeedType.h>


namespace tiger{
namespace trains{
namespace models{


class MoveModel{

private:

    int lineIdx = 0;
    int trainIdx = 0;
    SpeedType speedType = SpeedType::STOP;

public:

    MoveModel();
    MoveModel(const int lineIdx, const int trainIdx, const SpeedType speedType);
    int getLineIdx() const;
    int getTrainIdx() const;
    SpeedType getSpeedType() const;

    void setLineIdx(const int lineIdx);
    void setTrainIdx(const int trainIdx);
    void setSpeedType(const SpeedType speedType);

};


}
}
}
