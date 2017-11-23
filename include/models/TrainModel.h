#pragma once
#ifndef _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_
#define _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_


namespace tiger{
namespace trains{
namespace models{

    class TrainModel{
        private:
            const int idx;
            const int lineIdx;
            const int playerIdx;
            const int position;
            const int speed;
        public:
            TrainModel(const int idx, const int lineIdx, const int playerIdx, const int position, const int speed);
            const int getIdx() const;
            const int getLineIdx() const;
            const int getPlayerIdx() const;
            const int getPosition() const;
            const int getSpeed() const;
    };
}
}
}


#endif
