#pragma once
#ifndef _TIGER_TRAINS_WORLD_BASE_POST_H_
#define _TIGER_TRAINS_WORLD_BASE_POST_H_


#include <world/World.h>
#include <world/IPost.h>


namespace tiger{
namespace trains{
namespace world{

    class World;

    class BasePost : public IPost{
        private:
            World * owner;
            int idx;
            models::PostType type;
            std::string name;
        public:
            ~BasePost();
            BasePost();
            BasePost(const models::PostModel& model, World * world);
            void update(const models::PostModel& model);

            int getIdx() const;
            Point * getPoint() const;
            World * getWorld() const;
            const std::string& getName() const;
            models::PostType getPostType() const;
    };
}
}
}



#endif

