#pragma once


#include <world/World.h>
#include <models/PostType.h>
#include <models/PostModel.h>
#include <world/Point.h>
#include <world/IEvent.h>


namespace tiger{
namespace trains{
namespace world{


class Point;
class IEvent;
class World;


struct IPost{

    virtual ~IPost(){}

    virtual void update(const models::PostModel& model) = 0;

    virtual World* getWorld() const = 0;
    virtual int getIdx() const = 0;
    virtual Point* getPoint() const = 0;
    virtual const std::string& getName() const = 0;
    virtual models::PostType getPostType() const = 0;

    virtual void addEvent(IEvent* event) = 0;
    virtual void clearEvents() = 0;
    virtual const std::vector<IEvent*>& getEvents() const = 0;

};


}
}
}
