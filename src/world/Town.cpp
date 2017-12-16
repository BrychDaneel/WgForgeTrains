#include <world/Town.h>


namespace tiger{
namespace trains{
namespace world{


Town::Town() : BasePost(){
}


Town::Town(const models::PostModel& model, World* world) :
    BasePost(model, world)
{
    update(model);
}


void Town::update(const models::PostModel& model){
    BasePost::update(model);
    arrmor = model.getArmor();
    population = model.getPopulation();
    product = model.getProduct();

    arrmorCapacity = model.getArmorCapacity();
    productCapacity = model.getPopulationCapacity();
    populationCapacity = model.getPopulationCapacity();

    level = model.getLevel();
    nextLevelPrice = model.getNextLevelPrice();
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


int Town::getArrmorCapacity() const{
    return arrmorCapacity;
}


int Town::getPopulationCapacity() const{
    return populationCapacity;
}


int Town::getProductCapacity() const{
    return productCapacity;
}


int Town::getLevel() const{
    return level;
}


int Town::getNextLevelPrice() const{
    return nextLevelPrice;
}


bool Town::upgrade() const{
    return (owner->getCommandSender()->upgrade(models::UpgradeModel({},{idx})));
}


int Town::predictProduct(int delta){
    int predict = product - delta * population;
    if (predict < 0)
        return 0;
    else
        return predict;
}


}
}
}
