#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{


BasePost::~BasePost(){
}


BasePost::BasePost(){
}


BasePost::BasePost(const models::PostModel& model, World * world){
    owner = world;
    name = model.getName();
    idx = model.getIdx();
    type = model.getType();
}


int BasePost::getIdx() const{
    return idx;
}


void BasePost::update(const models::PostModel& model){
    name = model.getName();
    idx = model.getIdx();
}


Point * BasePost::getPoint() const{
    return owner->getPointOfPost(this);
}


World * BasePost::getWorld() const{
    return owner;
}


const std::string& BasePost::getName() const{
    return name;
}


models::PostType BasePost::getPostType() const{
    return type;
}


}
}
}
