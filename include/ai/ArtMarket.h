#ifndef _AI_ART_MARKET_H_
#define _AI_ART_MARKET_H_


#include <vector>
#include <map>
#include <world/World.h>
#include <ai/Post.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class ArtMarket
{

public:

    ArtMarket(){}
    ArtMarket(const Post* post);

    const Post *getPost() const;

    int getProduct() const;
    int takeProduct(int value);

    int getReplenishment() const;

    int getProductCapacity() const;

    int getLastTick() const;
    void setLastTick(int value);

    ArtMarket getFuture(int tick) const;

private:
    const Post *post;
    int lastTick;
    int product;
    int replenishment;
    int productCapacity;


};



}

}

}


#endif
