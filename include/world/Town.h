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

public:

    Town();

    Town(const models::PostModel& model, World* world);
    void update(const models::PostModel& model);

    int getArrmor() const;
    int getPopulation() const;
    int getProduct() const;

};


}
}
}


#endif
