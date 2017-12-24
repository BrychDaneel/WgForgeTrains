#pragma once

#include <world/World.h>
#include <tuple>

namespace tiger
{
namespace trains
{
namespace ai
{

struct BlockLine
{
    int owner;
    const world::Line *line;
    const world::Point *inPoint;


};


inline bool operator < (const BlockLine &lhs, const BlockLine &rhs)
{
    return std::tie(lhs.inPoint, lhs.line, lhs.owner) < std::tie(rhs.inPoint, rhs.line, rhs.owner);
}



}
}
}


