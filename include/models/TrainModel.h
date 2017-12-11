#pragma once
#ifndef _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_
#define _TIGER_TRAINS_MODELS_TRAIN_MODEL_H_


#include <models/SpeedType.h>
#include <models/GoodType.h>
#include <models/EventModel.h>

#include <string>
#include <vector>

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
    int goodsCapacity = 0;
    int goods = 0;
    GoodType goodsType = GoodType::NONE;
    int level = 0;
    int nextLevelPrice;
    SpeedType speed = SpeedType::STOP;

    std::vector<EventModel> eventList;

public:

    TrainModel();
    TrainModel(const int idx, const int lineIdx, const string playerIdx,
               const int position, const int goodsCapacity,
               const int goods, const GoodType goodsType,
               const int level, const int nextLevelPrice,
               const SpeedType speed);

    int getIdx() const;
    int getLineIdx() const;
    const string& getPlayerIdx() const;
    int getPosition() const;
    int getGoodsCapacity() const;
    GoodType getGoodsType() const;
    int getGoods() const;
    int getLevel() const;
    int getNextLevelPrice() const;
    SpeedType getSpeed() const;

    void setIdx(const int idx);
    void setLineIdx(const int lineIdx);
    void setPlayerIdx(const string playerIdx);
    void setPosition(const int position);
    void setGoodsCapacity(const int capacity);
    void setGoods(const int goods);
    void setGoodsType(const GoodType type);
    void setSpeed(const SpeedType speed);
    void setLevel(const int level);
    void setNextLevelPrice(const int nextLevelPrice);

    void addEvent(const EventModel& event);
    void clearEventList();
    const std::vector<EventModel>& getEventList() const;
};


}
}
}


#endif
