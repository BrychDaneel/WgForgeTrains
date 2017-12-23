#pragma once

#include <vector>
#include <set>
#include <world/World.h>



namespace tiger
{
namespace trains
{
namespace ai
{

class HomeChecker
{
public:
    HomeChecker();
    bool needHome(world::Train *train, int len, int homeLen, models::GoodType type);


private:
    const double dec_product =  0.0001;
    const double dec_armor = 0.0001;

};




}
}
}
