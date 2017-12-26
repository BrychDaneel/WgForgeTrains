#include <world/events/BaseEvent.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{


BaseEvent::BaseEvent(const models::EventModel &model, World *world)
{
    this->world = world;
    tick = model.getTick();
    type = model.getType();
}



models::EventType BaseEvent::getType() const
{
    return type;
}


int BaseEvent::getTick() const
{
    return tick;
}


World *BaseEvent::getWorld() const
{
    return world;
}


}
}
}
}

