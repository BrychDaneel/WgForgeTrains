#pragma once
#ifndef _TIGER_TRAINS_MODELS_POINT_MODEL_H_
#define _TIGER_TRAINS_MODELS_POINT_MODEL_H_


#include <string>


using std::string;


namespace tiger{
namespace trains{
namespace models{

    class PointModel{
        private:
            const int idx;
            const int postId;
        public:
            PointModel(const int idx, const int postId);
            const int getIdx() const;
            const int getPostId() const;
    };
}
}
}



#endif
