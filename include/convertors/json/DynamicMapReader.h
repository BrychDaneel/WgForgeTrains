#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_DYNAMIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_JSON_DYNAMIC_MAP_READER_H_


#include <convertors/IDynamicMapReader.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    class DynamicMapReader : public IDynamicMapReader{
        public:
            const int readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const;
    };
}
}
}
}


#endif


