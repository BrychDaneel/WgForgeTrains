#include <world/Point.h>


namespace tiger{
namespace trains{
namespace world{


Point::Point(){
}


Point::Point(const models::PointModel& model, World * world){
    owner = world;
    idx = model.getIdx();
}


World* Point::getWorld() const{
    return owner;
}


int Point::getIdx() const{
    return idx;
}


IPost* Point::getPost() const{
    return owner->getPostOfPoint(this);
}


const std::vector<Line*>& Point::getEdges() const{
    return owner->getEdges(this);
}


const std::vector<Point*> Point::getNeighboards() const{
    std::vector<Point*> result;
    for (Line * line : owner->getEdges(this))
        if (line->getStartPont() != this)
            result.push_back(line->getStartPont());
        else
            result.push_back(line->getEndPont());
    return result;
}


}
}
}
