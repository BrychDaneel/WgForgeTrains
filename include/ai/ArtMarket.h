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

    int getReplenishment() const;

    int getProductCapacity() const;

private:
    const Post *post;
    int product;
    int replenishment;
    int productCapacity;


};



}

}

}


#endif
