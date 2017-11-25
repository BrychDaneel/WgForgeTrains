#include <world/Line.h>



namespace tiger{
namespace trains{
namespace world{

    Line::Line(){
    }

    Line::Line(const models::LineModel& model, World * world){
    }

    World * Line::getWorld() const{
    }

    Point * Line::getStartPont() const{
    }
    Point * Line::getEndPont() const{
    }

    const std::vector<Point*>& Line::getPoints() const{
    }

    int Line::getLenght() const{
    }

}
}
}
