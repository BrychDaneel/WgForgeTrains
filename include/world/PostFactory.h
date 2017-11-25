#pragma once
#ifndef _TIGER_TRAINS_WORLD_POST_FACTORY_H_
#define _TIGER_TRAINS_WORLD_POST_FACTORY_H_


#include <world/World.h>

#include <models/PostModel.h>


namespace tiger{
namespace trains{
namespace world{

    class IPost;

    class PostFactory{
        public:
            static IPost* createPost(const models::PostModel& model, World* world);
    };
}
}
}



#endif


