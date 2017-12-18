#pragma once


#include <world/World.h>
#include <models/SpeedType.h>
#include <world/IEvent.h>
#include <models/TrainModel.h>
#include <world/IUpgradeble.h>


namespace tiger
{
namespace trains
{
namespace world
{


class World;
class Player;
class IEvent;


class Train : public IUpgradeble
{
private:

    int idx;
    World* owner;
    Player* player;
    Line* line;
    models::SpeedType speed;
    int goodsCapacity;
    int goods;
    int position;
    std::vector<IEvent*> eventsHistory;
    models::GoodType goodsType;
    int level;
    int nextLevelPrice;

public:

    Train();
    Train(const models::TrainModel& model, World* world);

    void update(models::TrainModel model);

    World* getWorld() const;

    int getIdx() const;
    Player* getPlayer() const;
    Line* getLine() const;
    int getPosition() const;
    int getGoodsCapacity() const;
    int getGoods() const;
    Point *getPoint() const;

    models::SpeedType getSpeed() const;

    models::GoodType getGoodsType() const;
    int getLevel() const;
    int getNextLevelPrice() const;

    void move(Line* line, models::SpeedType speed);

    void addEvent(IEvent* event);
    void clearEvents();
    const std::vector<IEvent*>& getEvents() const;

    bool upgrade() const;

    std::vector<Train*> getPosibleCollisions(const models::MoveModel* move=nullptr);
};


}
}
}
