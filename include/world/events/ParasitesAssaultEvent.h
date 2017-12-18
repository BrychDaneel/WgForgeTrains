#pragma once


#include <world/events/BaseEvent.h>
#include <world/Town.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{


class ParasitesAssaultEvent : public BaseEvent
{
public:

    ParasitesAssaultEvent(){}
    ParasitesAssaultEvent(const models::EventModel& model, Town* source);

    Town* getSource() const;
    int getParasitesPower() const;

private:

    Town* source;
    int parasitesPower;
};


}
}
}
}


