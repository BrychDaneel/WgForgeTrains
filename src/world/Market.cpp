#include <world/Market.h>


namespace tiger{
namespace trains{
namespace world{


Market::Market() : BasePost(){
}

Market::Market(const models::PostModel& model, World * world) :
    BasePost(model, world)
{
    product = model.getProduct();
}

void Market::update(const models::PostModel& model)
{
    BasePost::update(model);
    product = model.getProduct();
}

int Market::getProduct(){
    return product;
}

}
}
}


