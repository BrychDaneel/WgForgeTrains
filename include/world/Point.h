#pragma once


#include <world/World.h>

#include <models/PointModel.h>
#include <vector>


namespace tiger{
namespace trains{
namespace world{


class World;
class Line;
class IPost;
class Train;


class Point{

private:

    World* owner;
    int idx;
    int x = 0;
    int y = 0;

public:

    Point();
    Point(const models::PointModel& model, World* world);

    World* getWorld() const;

    int getIdx() const;
    int getX() const;
    int getY() const;

    IPost* getPost() const;
    const std::vector<Line*>& getEdges() const;
    const std::vector<Point*> getNeighboards() const;

    const std::vector<Train*> getTrains() const;

    void setX(const int x);
    void setY(const int y);

};


}
}
}
