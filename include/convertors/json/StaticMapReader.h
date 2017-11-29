#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_STATIC_MAP_READER_H_
#define _TIGER_TRAINS_MODELS_JSON_STATIC_MAP_READER_H_


#include <convertors/IStaticMapReader.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


class StaticMapReader : public IStaticMapReader{

public:

    int readStaticMap(const char* buffer, const int bufferSize, models::StaticMap* staticMap) const;

};


}
}
}
}


#endif
