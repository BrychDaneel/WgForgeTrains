#include <models/DynamicMap.h>


namespace tiger{
namespace trains{
namespace models{

    DynamicMap::DynamicMap(){
    }

    DynamicMap::DynamicMap(const int idx):
        idx(idx){
    }

    void DynamicMap::addPost(const PostModel& post){
        postList.push_back(post);
    }

    void DynamicMap::addTrain(const TrainModel& train){
        trainList.push_back(train);
    }

    int DynamicMap::getIdx() const{
        return idx;
    }

    const vector<PostModel> DynamicMap::getPostList() const{
        return postList;
    }

    const vector<TrainModel> DynamicMap::getTrainList() const{
        return trainList;
    }

    void DynamicMap::setIdx(int idx){
        this->idx = idx;
    }

    void DynamicMap::clearPostList(){
        postList.clear();
    }

    void DynamicMap::clearTrainList(){
        trainList.clear();
    }
}
}
}
