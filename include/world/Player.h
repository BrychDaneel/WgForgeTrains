#pragma once
#ifndef _TIGER_TRAINS_WORLD_PLAYER_H_
#define _TIGER_TRAINS_WORLD_PLAYER_H_


#include <world/World.h>
#include <models/PlayerModel.h>

#include <string>


namespace tiger{
namespace trains{
namespace world{


class World;
class IPost;
class Train;


class Player{

private:

    World* owner;
    std::string name;
    std::string idx;

public:

    Player();
    Player(const models::PlayerModel& model, World * world);

    World* getWorld() const;
    const std::string& getIdx();
    const std::string& getName();
    IPost* getHome();

    const std::vector<Train*>& getTrains();

};


}
}
}


#endif
