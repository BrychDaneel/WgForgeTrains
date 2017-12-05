#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_DYNAMIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_I_DYNAMIC_MAP_READER_H_


#include <models/DynamicMap.h>


namespace tiger{
namespace trains{
namespace convertors{


class IDynamicMapReader{

public:

    virtual ~IDynamicMapReader(){}

    virtual int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap) const = 0;

};


}
}
}


#endif
