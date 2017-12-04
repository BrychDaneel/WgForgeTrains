#pragma once
#ifndef _TIGER_TRAINS_WORLD_POINT_H_
#define _TIGER_TRAINS_WORLD_POINT_H_


#include <world/World.h>

#include <models/PointModel.h>
#include <vector>


namespace tiger{
namespace trains{
namespace world{


class World;
class Line;
class IPost;


class Point{

private:

    World* owner;
    int idx;

public:

    Point();
    Point(const models::PointModel& model, World* world);

    World* getWorld() const;

    int getIdx() const;
    IPost* getPost() const;
    const std::vector<Line*>& getEdges() const;
    const std::vector<Point*> getNeighboards() const;

};


}
}
}


#endif
