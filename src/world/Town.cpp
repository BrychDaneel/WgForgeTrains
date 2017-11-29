#include <world/Town.h>


namespace tiger{
namespace trains{
namespace world{


Town::Town() : BasePost(){
}


Town::Town(const models::PostModel& model, World* world) :
    BasePost(model, world)
{
    arrmor = model.getArmor();
    population = model.getPopulation();
    product = model.getProduct();
}


void Town::update(const models::PostModel& model){
    BasePost::update(model);
    arrmor = model.getArmor();
    population = model.getPopulation();
    product = model.getProduct();
}


int Town::getArrmor() const{
    return arrmor;
}


int Town::getPopulation() const{
    return population;
}


int Town::getProduct() const{
    return product;
}


}
}
}
