#pragma once
#ifndef _TIGER_TRAINS_WORLD_TOWN_H_
#define _TIGER_TRAINS_WORLD_TOWN_H_


#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{


class Town : public BasePost{

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

    Town(const models::PostModel& model, World* world);
    void update(const models::PostModel& model);

    int getArrmor() const;
    int getPopulation() const;
    int getProduct() const;

    int getArrmorCapacity() const;
    int getPopulationCapacity() const;
    int getProductCapacity() const;

    int getLevel() const;
    int getNextLevelPrice() const;

    void upgrade() const;

};


}
}
}


#endif
