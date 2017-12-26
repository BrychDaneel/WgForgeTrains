#pragma once

#include <world/World.h>
#include <tuple>

namespace tiger
{
namespace trains
{
namespace ai
{

struct LineBlock
{

    const world::Line *line;
    const world::Point *inPoint;
    LineBlock(const world::Line *line, const world::Point *point)
        : line(line), inPoint(point)
    {

    }


};


inline bool operator < (const LineBlock &lhs, const LineBlock &rhs)
{
    return std::tie(lhs.line, lhs.inPoint) < std::tie(rhs.line, rhs.inPoint);
}



}
}
}


