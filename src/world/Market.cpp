#include <world/Market.h>


#define MIN(a,b) ((a)<(b)?(a):(b))


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


int Market::predictProduct(int delta, int visitTime){
    int pr = product;
    if (visitTime != -1 && delta < visitTime){
        pr = 0;
        delta -= visitTime;
    }

    return MIN(productCapacity, pr + delta * replenishment);
}


}
}
}
