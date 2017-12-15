#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_DYNAMIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_I_DYNAMIC_MAP_READER_H_


#include <models/DynamicMap.h>


namespace tiger{
namespace trains{
namespace convertors{


struct IDynamicMapReader{

    virtual ~IDynamicMapReader(){}

    virtual int readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string& getLastErrorMessage() = 0;
};


}
}
}


#endif
