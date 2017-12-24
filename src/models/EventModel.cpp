#include <models/EventModel.h>


namespace tiger
{
namespace trains
{
namespace models
{


EventType EventModel::getType() const
{
    return type;
}


int EventModel::getTick() const
{
    return tick;
}


int EventModel::getParametrs() const
{
    return parametrs;
}


void EventModel::setType(const EventType type)
{
    this->type = type;
}


void EventModel::setTick(const int tick)
{
    this->tick = tick;
}


void EventModel::setParametrs(const int parametrs)
{
    this->parametrs = parametrs;
}


}
}
}
