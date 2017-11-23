#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_MOVE_WRITER_H_
#define _TIGER_TRAINS_MODELS_JSON_MOVE_WRITER_H_


#include <convertors/IMoveWriter.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    class MoveWriter : public IMoveWriter{
        public:
            const int writeMove(const models::MoveModel * move, const char * buffer, const int bufferSize) const;
    };

}
}
}
}


#endif
