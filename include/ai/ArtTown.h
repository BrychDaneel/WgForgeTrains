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

    const Post *getPost() const;

private:
    const Post *post;
    int last_in;
    int armor;
    int population;
    int product;

};



}

}

}


#endif
