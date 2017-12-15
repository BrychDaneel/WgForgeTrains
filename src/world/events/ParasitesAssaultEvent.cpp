#include <world/events/ParasitesAssaultEvent.h>


namespace tiger{
namespace trains{
namespace world{
namespace events{


ParasitesAssaultEvent::ParasitesAssaultEvent(const models::EventModel& model, Town* source) :
    BaseEvent(model, source->getWorld())
{
    source = source;
    parasitesPower = model.getParametrs();
}


Town* ParasitesAssaultEvent::getSource() const{
    return source;
}


int ParasitesAssaultEvent::getParasitesPower() const{
    return parasitesPower;
}


}
}
}
}



