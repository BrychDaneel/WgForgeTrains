#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_STATIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_I_STATIC_MAP_READER_H_


#include <models/StaticMap.h>


namespace tiger{
namespace trains{
namespace convertors{

    class IStaticMapReader{
        public:
            virtual ~IStaticMapReader(){};
            virtual const int readStaticMap(const char * buffer, const int bufferSize, models::StaticMap * staticMap) const = 0;
    };
}
}
}



#endif


