#include "ai/ArtTown.h"
#include "world/Town.h"

using namespace tiger::trains::ai;

ArtTown::ArtTown(const Post *post):post(post)
{
    const world::Town *town = static_cast<const world::Town*>((post->getPoint()->getPost()));
    armor = town->getArrmor();
    population = town->getPopulation();
    product = town->getProduct();
}

int ArtTown::getArmor() const
{
    return armor;
}

int ArtTown::getPopulation() const
{
    return population;
}

int ArtTown::getProduct() const
{
    return product;
}

const Post *ArtTown::getPost() const
{
    return post;
}
