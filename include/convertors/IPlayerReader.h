#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_PLAYER_READER_H_
#define _TIGER_TRAINS_MODELS_I_PLAYER_READER_H_


#include <models/PlayerModel.h>


namespace tiger{
namespace trains{
namespace convertors{

    class IPlayerReader{
        public:
            virtual ~IPlayerReader(){};
            virtual const int readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const = 0;
    };
}
}
}



#endif


