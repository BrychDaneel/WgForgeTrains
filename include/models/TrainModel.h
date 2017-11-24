#pragma once
#ifndef _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_
#define _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_


#include <models/SpeedType.h>

#include <string>

using std::string;


namespace tiger{
namespace trains{
namespace models{

    class TrainModel{
        private:
            int idx = 0;
            int lineIdx = 0;
            string playerIdx;
            int position = 0;
            SpeedType speed = SpeedType::STOP;
        public:
            TrainModel();
            TrainModel(const int idx, const int lineIdx, const string playerIdx, const int position, const SpeedType speed);
            const int getIdx() const;
            const int getLineIdx() const;
            const string getPlayerIdx() const;
            const int getPosition() const;
            const SpeedType getSpeed() const;

            bool isInLine() const;

            void setIdx(const int idx);
            void setLineIdx(const int lineIdx);
            void setPlayerIdx(const string playerIdx);
            void setPosition(const int position);
            void setSpeed(const SpeedType speed);
    };
}
}
}


#endif
