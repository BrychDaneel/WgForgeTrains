#pragma once


#include <world/events/BaseEvent.h>
#include <world/Train.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{


class TrainCollisionEven : public BaseEvent
{
public:

    TrainCollisionEven(){}
    TrainCollisionEven(const models::EventModel& model, Train* source);

    Train* getSource() const;
    Train* getAnother() const;

private:

    Train* source;
    Train* another;
};


}
}
}
}


