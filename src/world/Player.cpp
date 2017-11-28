#include <world/Player.h>


namespace tiger{
namespace trains{
namespace world{

    Player::Player(){
    }

    Player::Player(const models::PlayerModel& model, World * world){
        owner = world;
        name = model.getName();
        idx = model.getIdx();
    }

    World* Player::getWorld() const{
        return owner;
    }

    const std::string& Player::getIdx(){
        return idx;
    }

    const std::string& Player::getName(){
        return name;
    }

    IPost* Player::getHome(){
        return owner->getHome(this);
    }

    const std::vector<Train*>& Player::getTrains(){
        return owner->getTrainsOfPlayer(this);
    }

}
}
}
