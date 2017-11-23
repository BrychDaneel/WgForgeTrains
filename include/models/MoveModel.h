#pragma once
#ifndef _TIGER_TRAINS_MODELS_MOVE_MODEL_H_
#define _TIGER_TRAINS_MODELS_MOVE_MODEL_H_


#include <models/SpeedType.h>


namespace tiger{
namespace trains{
namespace models{

    class MoveModel{
        private:
            const int lineIdx;
            const int trainIdx;
            const SpeedType speedType;
        public:
            MoveModel(const int lineIdx, const int trainIdx, const SpeedType speedType);
            const int getLineIdx() const;
            const int getTrainIdx() const;
            const SpeedType getSpeedType() const;
    };
}
}
}



#endif
