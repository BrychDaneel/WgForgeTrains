#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_PLAYER_READER_H_
#define _TIGER_TRAINS_MODELS_I_PLAYER_READER_H_


#include <models/PlayerModel.h>


namespace tiger{
namespace trains{
namespace convertors{


struct IPlayerReader{

    virtual ~IPlayerReader(){}

    virtual int readPlayer(const char* buffer, const int bufferSize, models::PlayerModel* playerModel) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string& getLastErrorMessage() = 0;
};


}
}
}


#endif
