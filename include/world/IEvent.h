#pragma once


#include <world/World.h>
#include <models/EventModel.h>


namespace tiger{
namespace trains{
namespace world{


class World;


class IEvent{

public:

    virtual ~IEvent(){}

    virtual models::EventType getType() const = 0;
    virtual int getTick() const = 0;
    virtual World* getWorld() const = 0;

};


}
}
}
