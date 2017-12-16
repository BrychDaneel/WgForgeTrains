#pragma once
#ifndef _TIGER_TRAINS_WORLD_MARKET_H_
#define _TIGER_TRAINS_WORLD_MARKET_H_


#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{


class Market : public BasePost{

private:

    int product;
    int replenishment;
    int productCapacity;

public:

    Market();

    Market(const models::PostModel& model, World* world);
    void update(const models::PostModel& model);

    int getProduct() const;
    int getReplenishment() const;
    int getProductCapacity() const;

    int predictProduct(int delta, int visitTime=-1) const;

};


}
}
}


#endif
