#include <world/PostFactory.h>

#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{


    IPost* PostFactory::createPost(const models::PostModel& model, World* world){
        return new BasePost(model, world);
    }

}
}
}
