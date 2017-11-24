#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_MODEL_CONVERTOR_H_
#define _TIGER_TRAINS_MODELS_I_MODEL_CONVERTOR_H_


#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/MoveModel.h>


namespace tiger{
namespace trains{
namespace convertors{

    class IModelConvertor{
        public:
            virtual ~IModelConvertor(){};
            virtual const int readStaticMap(const char * buffer, const int bufferSize, models::StaticMap * staticMap) const = 0;
            virtual const int readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const = 0;
            virtual const int readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const = 0;
            virtual const int writeMove(const models::MoveModel * move, char * buffer, const int bufferSize) const = 0;
    };
}
}
}



#endif


