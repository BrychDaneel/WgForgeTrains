#include <world/Player.h>


namespace tiger{
namespace trains{
namespace world{

    Player::Player(){
    }

    Player::Player(const models::PlayerModel& model, World * world){
    }

    World* Player::getWorld() const{
    }

    const std::string& Player::getIdx(){
    }

    const std::string& Player::getName(){
    }

    IPost* Player::getHome(){
    }

    const std::vector<Train*>& Player::getTrains(){
    }

}
}
}
