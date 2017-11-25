#include <world/Point.h>

namespace tiger{
namespace trains{
namespace world{

    Point::Point(){
    }

    Point::Point(const models::PointModel& model, World * owner){
    }

    World* Point::getWorld() const{
    }

    int Point::getIdx() const{
    }

    IPost* Point::getPost() const{
    }

    const std::vector<Line*>& Point::getEdges() const{
    }

    const std::vector<Point*>& Point::getNeighboards() const{
    }

}
}
}
