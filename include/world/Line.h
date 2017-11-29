#pragma once
#ifndef _TIGER_TRAINS_WORLD_LINE_H_
#define _TIGER_TRAINS_WORLD_LINE_H_


#include <world/World.h>
#include <models/LineModel.h>

#include <vector>


namespace tiger{
namespace trains{
namespace world{


class World;
class Point;
class Train;


class Line{

private:

    World* owner;
    Point* startPont;
    Point* endPont;
    int length;
    int idx;

public:

    Line();
    Line(const models::LineModel& model, World* world);

    World* getWorld() const;
    int getIdx() const;
    Point* getStartPont() const;
    Point* getEndPont() const;
    int getLenght() const;

    const std::vector<Point*> getPoints() const;

    const std::vector<Train*>& getTrains();

};


}
}
}


#endif
