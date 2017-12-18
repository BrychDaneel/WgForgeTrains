#include <world/events/TrainCollisionEvent.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{

TrainCollisionEven::TrainCollisionEven(const models::EventModel &model, Train *source)
    : BaseEvent(model, source->getWorld())
{
    source = source;
    another = world->getTrainByIdx(model.getParametrs());
}


Train *TrainCollisionEven::getSource() const
{
    return source;
}


Train *TrainCollisionEven::getAnother() const
{
    return another;
}


}
}
}
}




