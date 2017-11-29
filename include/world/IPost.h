#pragma once
#ifndef _TIGER_TRAINS_WORLD_I_POST_H_
#define _TIGER_TRAINS_WORLD_I_POST_H_


#include <world/World.h>
#include <models/PostType.h>
#include <models/PostModel.h>
#include <world/Point.h>


namespace tiger{
namespace trains{
namespace world{


class Point;


class IPost{

public:

    virtual ~IPost(){}

    virtual void update(const models::PostModel& model) = 0;

    virtual World * getWorld() const = 0;
    virtual int getIdx() const = 0;
    virtual Point * getPoint() const = 0;
    virtual const std::string& getName() const = 0;
    virtual models::PostType getPostType() const = 0;

};


}
}
}


#endif
