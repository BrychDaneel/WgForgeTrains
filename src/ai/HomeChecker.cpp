#include <ai/HomeChecker.h>
#include <world/Town.h>
#include <cmath>

using namespace tiger::trains::ai;
using namespace tiger::trains;

HomeChecker::HomeChecker()
{

}

bool HomeChecker::needHome(world::Train *train, int len, int homeLen, models::GoodType type)
{
    if (train->getGoods() == 0)
        return false;

    const world::Town *homeTown = (world::Town *)train->getPlayer()->getHome();

    if (type == models::GoodType::PRODUCT)
    {
        int predict = homeTown->getProduct() - (int)std::ceil(dec_product*len);
        int maxLen = predict / homeTown->getPopulation();
        int curProduct = train->getGoods();


        if (maxLen < len)
            return true;


        predict = homeTown->predictProduct(homeLen) -
                  (int)std::ceil(dec_product*len);

        if (curProduct + predict > homeTown->getProductCapacity())
            return true;

        return false;
    }
    else
    {
        int predict = homeTown->getArrmor() - (int)std::ceil(dec_armor*len);
        int maxLen = 150;
        int curProduct = train->getGoods();

        if (maxLen < len)
            return true;

        if (curProduct + predict > homeTown->getArrmorCapacity())
            return true;

        return false;
    }
}
