#ifndef _AI_ART_TOWN_H_
#define _AI_ART_TOWN_H_

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

class ArtTown
{

public:

    ArtTown(){}
    ArtTown(const Post *post);



    int getArmor() const;

    int getPopulation() const;

    int getProduct() const;
    void addProduct(int value);

    const Post *getPost() const;

    int getLastTick() const;
    void setLastTick(int value);

    const ArtTown getFuture(int tick) const;


private:
    const Post *post;
    int lastTick;
    int armor;
    int population;
    int product;

};



}

}

}


#endif
