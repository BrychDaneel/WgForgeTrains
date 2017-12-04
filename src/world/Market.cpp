#include <world/Market.h>


namespace tiger{
namespace trains{
namespace world{


Market::Market() : BasePost(){
}


Market::Market(const models::PostModel& model, World* world) :
    BasePost(model, world)
{
    product = model.getProduct();
    replenishment = model.getReplenishment();
    productCapacity = model.getProductCapacity();
}


void Market::update(const models::PostModel& model){
    BasePost::update(model);
    product = model.getProduct();
    replenishment = model.getReplenishment();
    productCapacity = model.getProductCapacity();
}


int Market::getProduct() const{
    return product;
}


int Market::getReplenishment() const{
    return replenishment;
}


int Market::getProductCapacity() const{
    return productCapacity;
}


}
}
}
