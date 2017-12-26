#pragma once

#include <vector>
#include <set>
#include <world/World.h>
#include <world/Town.h>



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
    void setHome(world::Town *town);
    bool needHome(world::Train *train, int len, int homeLen, models::GoodType type);
    void blockHome(std::set<const world::Point *> &inPoints);
    void comeHome(const world::Train *train);


private:
    world::Town *homeTown;
    std::set<const world::Train *> goingHomeTrain;
    const double dec_product =  0.08;
    const double dec_armor = 0.08;
    bool homeBlocked;

    double getMaxPopulation();

};




}
}
}
