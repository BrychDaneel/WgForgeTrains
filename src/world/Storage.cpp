#include <world/Storage.h>


#define MIN(a,b) ((a)<(b)?(a):(b))


namespace tiger{
namespace trains{
namespace world{


Storage::Storage() : BasePost(){
}


Storage::Storage(const models::PostModel& model, World* world) :
    BasePost(model, world)
{
    update(model);
}


void Storage::update(const models::PostModel& model){
    BasePost::update(model);
    armor = model.getArmor();
    replenishment = model.getReplenishment();
    armorCapacity = model.getArmorCapacity();
}


int Storage::getArmor() const{
    return armor;
}


int Storage::getReplenishment() const{
    return replenishment;
}


int Storage::getArmorCapacity() const{
    return armorCapacity;
}


int Storage::predictArmor(int delta, int visitTime){
    int ar = armor;
    if (visitTime != -1 && delta > visitTime){
        ar = 0;
        delta -= visitTime;
    }

    return MIN(armorCapacity, ar + replenishment * delta);
}


}
}
}
