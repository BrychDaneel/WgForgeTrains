#pragma once
#ifndef _TIGER_TRAINS_MODELS_EVENT_MODEL_H_
#define _TIGER_TRAINS_MODELS_EVENT_MODEL_H_


#include <models/EventType.h>


namespace tiger{
namespace trains{
namespace models{


class EventModel{

private:
    EventType type;
    int tick;
    int parametrs;

public:

    EventType getType();
    int getTick();
    int getParametrs();

    void setType(const EventType type);
    void setTick(const int tick);
    void setParametrs(const int parametrs);

};


}
}
}


#endif

