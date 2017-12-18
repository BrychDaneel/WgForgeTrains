#include <world/EventFactory.h>


#include <world/events/BaseEvent.h>
#include <world/events/HijackersAssaultEvent.h>
#include <world/events/ParasitesAssaultEvent.h>
#include <world/events/TrainCollisionEvent.h>


namespace tiger
{
namespace trains
{
namespace world
{


IEvent* EventFactory::createEvent(const models::EventModel& model, IPost* source)
{
    switch (model.getType()) {

    case models::EventType::HIJACKERS_ASSAULT:
        return new events::HijackersAssaultEvent(model, static_cast<Town*>(source));

    case models::EventType::PARASITES_ASSAULT:
        return new events::ParasitesAssaultEvent(model, static_cast<Town*>(source));

    default:
        return new events::BaseEvent(model, source->getWorld());
    }
}


 IEvent* EventFactory::createEvent(const models::EventModel& model, Train* source)
 {
    switch (model.getType()) {

    case models::EventType::TRAIN_COLLISION:
        return new events::TrainCollisionEven(model, source);

    default:
        return new events::BaseEvent(model, source->getWorld());
    }
}


}
}
}
