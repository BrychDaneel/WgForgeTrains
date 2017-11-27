#pragma once
#ifndef _TIGER_TRAINS_MODELS_MOVE_MODEL_H_
#define _TIGER_TRAINS_MODELS_MOVE_MODEL_H_


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
            const int getLineIdx() const;
            const int getTrainIdx() const;
            const SpeedType getSpeedType() const;

            void setLineIdx(const int lineIdx);
            void setTrainIdx(const int trainIdx);
            void setSpeedType(const SpeedType speedType);
    };
}
}
}



#endif
