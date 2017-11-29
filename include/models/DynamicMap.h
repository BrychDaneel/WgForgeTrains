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

    int idx = 0;
    vector<PostModel> postList;
    vector<TrainModel> trainList;

public:

    DynamicMap();
    DynamicMap(const int idx);

    void addPost(const PostModel& post);
    void addTrain(const TrainModel& train);

    int getIdx() const;
    const vector<PostModel> getPostList() const;
    const vector<TrainModel> getTrainList() const;

    void setIdx(int idx);
    void clearPostList();
    void clearTrainList();

};


}
}
}


#endif
