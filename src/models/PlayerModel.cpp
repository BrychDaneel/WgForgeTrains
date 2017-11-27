#include <models/PlayerModel.h>


namespace tiger{
namespace trains{
namespace models{

    PlayerModel::PlayerModel(){
    }

    PlayerModel::PlayerModel(const string idx, const int home, const string name) :
        idx(idx), home(home), name(name){
    }

    const string PlayerModel::getIdx() const{
        return idx;
    }

    const int PlayerModel::getHome() const{
        return home;
    }

    const string PlayerModel::getName() const{
        return name;
    }

    void PlayerModel::setIdx(const string idx){
        this->idx = idx;
    }

    void PlayerModel::setHome(const int home){
        this->home = home;
    }

    void PlayerModel::setName(const string name){
        this->name = name;
    }

}
}
}
