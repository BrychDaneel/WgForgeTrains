#include <models/EventModel.h>


namespace tiger{
namespace trains{
namespace models{


EventType EventModel::getType(){
    return type;
}


int EventModel::getTick(){
    return tick;
}


int EventModel::getParametrs(){
    return parametrs;
}


void EventModel::setType(const EventType type){
    this->type = type;
}


void EventModel::setTick(const int tick){
    this->tick = tick;
}


void EventModel::setParametrs(const int parametrs){
    this->parametrs = parametrs;
}


}
}
}
