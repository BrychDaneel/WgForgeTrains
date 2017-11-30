#include <world/Line.h>


namespace tiger{
namespace trains{
namespace world{


Line::Line(){
}


Line::Line(const models::LineModel& model, World* world){
    owner = world;
    startPont = owner->getPointByIdx(model.getStartPoint());
    endPont = owner->getPointByIdx(model.getEndPoint());
    length = model.getLength();
    idx = model.getIdx();
}


World* Line::getWorld() const{
    return owner;
}


int Line::getIdx() const{
    return idx;
}


Point* Line::getStartPont() const{
    return startPont;
}


Point* Line::getEndPont() const{
    return endPont;
}

Point *Line::getAnotherPoint(const Point *point) const
{
    if (point == startPont)
        return endPont;
    if (point == endPont)
        return startPont;
    return nullptr;
}


const std::vector<Point*> Line::getPoints() const{
    std::vector<Point*> v;
    v.push_back(startPont);
    v.push_back(endPont);
    return v;
}


int Line::getLenght() const{
    return length;
}


const std::vector<Train*>& Line::getTrains(){
    return owner->getTrainsOfLine(this);
}


}
}
}
