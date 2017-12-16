#include <ai/CollisionAllower.h>


namespace tiger{
namespace trains{
namespace ai{


CollisionAllower::CollisionAllower(){
}


bool CollisionAllower::isCollisionAllow(world::Train* train, world::Train* otherTrain){

    if (train->getPlayer() == otherTrain->getPlayer())
        return false;

    float firstScore = 0;

    switch (train->getGoodsType()) {

    case models::GoodType::ARMOR:
        firstScore += ARMOR_WEIGHT * train->getGoods();
        break;

    case models::GoodType::PRODUCT:
        firstScore += PRODUCT_WEIGHT * train->getGoods();
        break;

    default:
        break;
    }


    float secondScore = 0;

    switch (otherTrain->getGoodsType()) {

    case models::GoodType::ARMOR:
        secondScore += ARMOR_WEIGHT * otherTrain->getGoods();
        break;

    case models::GoodType::PRODUCT:
        secondScore += PRODUCT_WEIGHT * otherTrain->getGoods();
        break;

    default:
        break;
    }

    return firstScore < secondScore;
}


}
}
}
