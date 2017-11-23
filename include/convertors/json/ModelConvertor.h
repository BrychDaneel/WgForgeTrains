#pragma once
#ifndef _TIGER_TRAINS_MODELS_JSON_MODEL_CONVERTOR_H_
#define _TIGER_TRAINS_MODELS_JSON_MODEL_CONVERTOR_H_


#include <convertors/IModelConvertor.h>


#include <convertors/IDynamicMapReader.h>
#include <convertors/IStaticMapReader.h>
#include <convertors/IPlayerReader.h>
#include <convertors/IMoveWriter.h>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    class ModelConvertor : public IModelConvertor{
        private:
            IDynamicMapReader * dynamicMapReader;
            IMoveWriter * moveWriter;
            IPlayerReader * playerReader;
            IStaticMapReader * staticMapReader;
        public:
            ModelConvertor();
            ~ModelConvertor();
            const int readStaticMap(const char * buffer, const int bufferSize, models::StaticMap * staticMap) const;
            const int readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const;
            const int readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const;
            const int writeMove(const models::MoveModel * move, const char * buffer, const int bufferSize) const;
    };
}
}
}
}


#endif
