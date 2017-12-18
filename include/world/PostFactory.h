#pragma once


#include <world/World.h>

#include <models/PostModel.h>


namespace tiger
{
namespace trains
{
namespace world
{


class IPost;


class PostFactory
{
public:

    static IPost* createPost(const models::PostModel& model, World* world);
};


}
}
}
