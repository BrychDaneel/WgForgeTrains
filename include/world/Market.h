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

public:

    Market();

    Market(const models::PostModel& model, World * world);
    void update(const models::PostModel& model);

    int getProduct();

};


}
}
}


#endif
