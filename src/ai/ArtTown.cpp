#include "ai/ArtTown.h"
#include "world/Town.h"
#include "algorithm"

using namespace tiger::trains::ai;

ArtTown::ArtTown(const Post *post):post(post), lastTick(0)
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

void ArtTown::addProduct(int value)
{
    product += value;
}

const Post *ArtTown::getPost() const
{
    return post;
}

int ArtTown::getLastTick() const
{
    return lastTick;
}

void ArtTown::setLastTick(int value)
{
    lastTick = value;
}

const ArtTown ArtTown::getFuture(int tick) const
{
    ArtTown artTown = *this;
    artTown.product -= (tick - lastTick)*artTown.population;
    if (artTown.product < 0)
    {
        artTown.population -= std::min(artTown.population, abs(artTown.product)/artTown.population + 1);
        artTown.product = 0;
    }

    artTown.setLastTick(tick);

    return artTown;
}


