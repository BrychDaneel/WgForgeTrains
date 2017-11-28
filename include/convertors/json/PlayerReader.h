#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_PLAYER_READER_H_
#define _TIGER_TRAINS_MODELS_JSON_PLAYER_READER_H_


#include <convertors/IPlayerReader.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    class PlayerReader : public IPlayerReader{
        public:
            const int readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const;
    };
}
}
}
}


#endif


