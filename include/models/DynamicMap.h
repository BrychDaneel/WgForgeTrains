#pragma once
#ifndef _TIGER_TRAINS_MODELS_DYNAMIC_MAP_HPP_
#define _TIGER_TRAINS_MODELS_DYNAMIC_MAP_HPP_


#include <models/PostModel.h>
#include <models/TrainModel.h>

#include <vector>


using std::vector;


namespace tiger{
namespace trains{
namespace models{

    class DynamicMap{
        private:
            const int idx;
            vector<PostModel> postList;
            vector<TrainModel> trainList;
        public:
            DynamicMap(const int idx);

            void addPost(const PostModel& post);
            void addTrain(const TrainModel& train);

            const int getIdx() const;
            const vector<PostModel> getPostList() const;
            const vector<TrainModel> getTrainList() const;
    };
}
}
}



#endif
