#pragma once

#include <world/World.h>
#include <map>
#include <vector>
namespace tiger
{
namespace trains
{
namespace ai
{

class Barrier
{
public:
    explicit Barrier(const world::Point *point);
    Barrier() {}
    bool doMove(const world::Line *line);
    bool canMove(const world::Line *line);
    void setLines(const std::vector<world::Line *> &lines);



private:
    const world::Point *point;
    std::map<const world::Line *, int> lineInTick;

};




}
}
}
