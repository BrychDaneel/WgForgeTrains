#pragma once
#ifndef _TIGER_TRAINS_MODELS_EVENT_TYPE_H_
#define _TIGER_TRAINS_MODELS_EVENT_TYPE_H_


namespace tiger{
namespace trains{
namespace models{


enum class EventType{

    TRAIN_COLLISION = 1,
    HIJACKERS_ASSAULT = 2,
    PARASITES_ASSAULT = 3,
    REFUGEES_ARRIVAL = 4,
    RESOURCE_OVERFLOW = 5,
    RESOURCE_LACK = 6,
    GAME_OVER = 100

};


}
}
}


#endif
