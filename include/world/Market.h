#pragma once


#include <world/BasePost.h>


namespace tiger
{
namespace trains
{
namespace world
{


class Market : public BasePost
{
private:

    int product;
    int replenishment;
    int productCapacity;

public:

    Market();

    Market(const models::PostModel &model, World *world);
    void update(const models::PostModel &model);

    int getProduct() const;
    int getReplenishment() const;
    int getProductCapacity() const;

    int predictProduct(int delta, int visitTime=-1) const;

};


}
}
}
