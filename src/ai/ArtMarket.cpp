#include "ai/ArtMarket.h"
#include <world/Market.h>

using namespace tiger::trains::ai;

ArtMarket::ArtMarket(const tiger::trains::ai::Post *post)
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

int ArtMarket::getReplenishment() const
{
    return replenishment;
}

int ArtMarket::getProductCapacity() const
{
    return productCapacity;
}

