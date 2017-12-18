#pragma once


#include <world/IEvent.h>
#include <world/World.h>
#include <models/EventModel.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{


class BaseEvent : public IEvent
{
public:

    BaseEvent(){}
    BaseEvent(const models::EventModel& model, World* world);

    virtual models::EventType getType() const;
    virtual int getTick() const;
    virtual World* getWorld() const;

protected:

    World* world;
    int tick;
    models::EventType type;
};


}
}
}
}
