#include <ai/HomeChecker.h>
#include <world/Town.h>
#include <cmath>

using namespace tiger::trains::ai;
using namespace tiger::trains;

HomeChecker::HomeChecker()
{
    homeBlocked = false;
}

void HomeChecker::setHome(world::Town *town)
{
    homeTown = town;
}

bool HomeChecker::needHome(world::Train *train, int len, int homeLen, models::GoodType type)
{
    if (train->getGoods() == 0)
        return false;

    if (goingHomeTrain.count(train) != 0)
        return true;

    const world::Town *homeTown = (world::Town *)train->getPlayer()->getHome();

    if (type == models::GoodType::PRODUCT)
    {
        int predict = homeTown->getProduct() - (int)std::ceil(dec_product*len);
        int maxLen = predict / homeTown->getPopulation();
        int curProduct = train->getGoods();


        if (maxLen < len)
        {
            goingHomeTrain.insert(train);
            return true;
        }


        predict = homeTown->predictProduct(homeLen) -
                  (int)std::ceil(dec_product*len);

        if (curProduct + predict > homeTown->getProductCapacity())
        {
            goingHomeTrain.insert(train);
            return true;
        }

        return false;
    }
    else
    {
        int predict = homeTown->getArrmor() - (int)std::ceil(dec_armor*len);
        int maxLen = 150;
        int curProduct = train->getGoods();

        if (maxLen < len)
        {
            goingHomeTrain.insert(train);
            return true;
        }

        if (curProduct + predict > homeTown->getArrmorCapacity())
        {
            goingHomeTrain.insert(train);
            return true;
        }

        return false;
    }
}

void HomeChecker::blockHome(std::set<const world::Point *> &inPoints)
{
    if (!homeBlocked)
    {
        if (homeTown->getPopulation() > getMaxPopulation())
        {
            inPoints.insert(homeTown->getPoint());
            homeBlocked = true;
        }

    }
    else
    {
        if (homeTown->getPopulation() < getMaxPopulation())
        {
            inPoints.erase(homeTown->getPoint());
            homeBlocked = false;
        }
    }
}

void HomeChecker::comeHome(const world::Train *train)
{
    goingHomeTrain.erase(train);
}

double HomeChecker::getMaxPopulation()
{
    int ans = homeTown->getProduct()/60;
    return (ans < 10 ? 10 : ans);
}
