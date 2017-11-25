#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{

    BasePost::BasePost(){
    }

    BasePost::BasePost(models::PostModel, World * world){
    }

    void update(const models::PostModel& model){
    }

    Point * BasePost::getPoint() const{
    }

    World * BasePost::getWorld() const{
    }

    const std::string& BasePost::getName() const{
    }

    models::PostType BasePost::getPostType() const{
    }

}
}
}
