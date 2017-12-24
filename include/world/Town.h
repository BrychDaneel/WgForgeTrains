#pragma once


#include <world/BasePost.h>
#include <world/IUpgradeble.h>


namespace tiger
{
namespace trains
{
namespace world
{


class Town : public BasePost, public IUpgradeble
{
private:

    int arrmor;
    int population;
    int product;

    int arrmorCapacity;
    int populationCapacity;
    int productCapacity;

    int level;
    int nextLevelPrice;

public:

    Town();

    Town(const models::PostModel &model, World *world);
    void update(const models::PostModel &model);

    int getArrmor() const;
    int getPopulation() const;
    int getProduct() const;

    int getArrmorCapacity() const;
    int getPopulationCapacity() const;
    int getProductCapacity() const;

    int getLevel() const;
    int getNextLevelPrice() const;

    bool upgrade() const;

    int predictProduct(int delta) const;
};


}
}
}
