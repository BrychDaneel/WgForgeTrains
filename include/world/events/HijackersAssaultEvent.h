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


class HijackersAssaultEvent : public BaseEvent
{
public:

    HijackersAssaultEvent() {}
    HijackersAssaultEvent(const models::EventModel &model, Town *source);

    Town *getSource() const;
    int getHijackersPower() const;

private:

    Town *source;
    int hijackersPower;
};


}
}
}
}

