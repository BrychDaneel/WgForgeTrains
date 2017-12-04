#include "ai/ArtMarket.h"
#include <world/Market.h>

using namespace tiger::trains::ai;

ArtMarket::ArtMarket(const tiger::trains::ai::Post *post):post(post), lastTick(0)
{
    const world::Market *market = static_cast<const world::Market*>((post->getPoint()->getPost()));
    replenishment = market->getReplenishment();
    product = market->getProduct();
    productCapacity = market->getProductCapacity();
}


const Post *ArtMarket::getPost() const
{
    return post;
}

int ArtMarket::getProduct() const
{
    return product;
}

int ArtMarket::takeProduct(int value)
{
    if (value > product)
    {
        int temp = product;
        product = 0;
        return temp;
    }
    else
        product -= value;
    return value;
}

int ArtMarket::getReplenishment() const
{
    return replenishment;
}

int ArtMarket::getProductCapacity() const
{
    return productCapacity;
}

int ArtMarket::getLastTick() const
{
    return lastTick;
}

void ArtMarket::setLastTick(int value)
{
    lastTick = value;
}

ArtMarket ArtMarket::getFuture(int tick) const
{
    ArtMarket artMarket = *this;
    if ((tick - lastTick)*replenishment + product >= productCapacity)
        artMarket.product = productCapacity;
    else
        artMarket.product += (tick - lastTick)*replenishment;

    artMarket.setLastTick(tick);

    return artMarket;

}

