#pragma once
#ifndef _TIGER_TRAINS_WORLD_BASE_POST_H_
#define _TIGER_TRAINS_WORLD_BASE_POST_H_


#include <world/World.h>
#include <world/IPost.h>


namespace tiger{
namespace trains{
namespace world{

    class BasePost : public IPost{
        public:
            BasePost();
            BasePost(models::PostModel, World * world);
            void update(const models::PostModel& model);
            Point * getPoint() const;
            World * getWorld() const;
            const std::string& getName() const;
            models::PostType getPostType() const;
    };
}
}
}



#endif

