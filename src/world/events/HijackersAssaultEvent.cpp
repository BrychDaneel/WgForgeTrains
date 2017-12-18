#include <world/events/HijackersAssaultEvent.h>


namespace tiger
{
namespace trains
{
namespace world
{
namespace events
{


HijackersAssaultEvent::HijackersAssaultEvent(const models::EventModel &model, Town *source)
    : BaseEvent(model, source->getWorld())
{
    source = source;
    hijackersPower = model.getParametrs();
}


Town *HijackersAssaultEvent::getSource() const
{
    return source;
}


int HijackersAssaultEvent::getHijackersPower() const
{
    return hijackersPower;
}


}
}
}
}


