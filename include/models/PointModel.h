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
            int idx = 0;
            int postId = 0;
        public:
            PointModel();
            PointModel(const int idx, const int postId);
            int getIdx() const;
            int getPostId() const;
            bool hasPost() const;

            void setIdx(const int idx);
            void setPostId(const int postId);
    };
}
}
}



#endif
