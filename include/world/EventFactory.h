#pragma once


#include <world/IPost.h>
#include <models/EventModel.h>
#include <world/IEvent.h>


namespace tiger{
namespace trains{
namespace world{


class EventFactory{

public:

    static IEvent* createEvent(const models::EventModel& model, IPost* source);
    static IEvent* createEvent(const models::EventModel& model, Train* source);

};


}
}
}
