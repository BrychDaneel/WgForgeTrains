#pragma once
#ifndef _TIGER_TRAINS_WORLD_TRAIN_H_
#define _TIGER_TRAINS_WORLD_TRAIN_H_


#include <world/World.h>
#include <models/SpeedType.h>

#include <models/TrainModel.h>


namespace tiger{
namespace trains{
namespace world{


class World;
class Player;


class Train{

private:

    int idx;
    World* owner;
    Player* player;
    Line* line;
    models::SpeedType speed;
    int capacity;
    int product;
    int position;

public:

    Train();
    Train(const models::TrainModel& model, World* world);
    void update(models::TrainModel model);

    World* getWorld() const;

    int getIdx() const;
    Player * getPlayer() const;
    Line * getLine() const;
    int getPosition() const;
    int getCapacity() const;
    int getProduct() const;
    models::SpeedType getSpeed() const;

    void move(Line* line, models::SpeedType speed);

};


}
}
}


#endif
