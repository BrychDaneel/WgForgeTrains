#pragma once
#ifndef _TIGER_TRAINS_MODELS_I_MOVE_WRITER_H_
#define _TIGER_TRAINS_MODELS_I_MOVE_WRITER_H_


#include <models/MoveModel.h>


namespace tiger{
namespace trains{
namespace convertors{

    class IMoveWriter{
        public:
            virtual ~IMoveWriter(){};
            virtual const int writeMove(const models::MoveModel * move, char * buffer, const int bufferSize) const = 0;
    };

}
}
}



#endif


