#include <models/DynamicMap.h>


namespace tiger
{
namespace trains
{
namespace models
{


DynamicMap::DynamicMap()
{
}


DynamicMap::DynamicMap(const int idx)
    : idx(idx)
{
}


void DynamicMap::addPost(const PostModel& post)
{
    postList.push_back(post);
}


void DynamicMap::addTrain(const TrainModel& train)
{
    trainList.push_back(train);
}

void DynamicMap::addScore(const std::string& name, const int score)
{
    scoreMap[name] = score;
}


int DynamicMap::getIdx() const
{
    return idx;
}


const vector<PostModel>& DynamicMap::getPostList() const
{
    return postList;
}


const vector<TrainModel>& DynamicMap::getTrainList() const
{
    return trainList;
}


const std::map<std::string, int>& DynamicMap::getScoreMap() const
{
    return scoreMap;
}


void DynamicMap::setIdx(int idx)
{
    this->idx = idx;
}


void DynamicMap::clearPostList()
{
    postList.clear();
}


void DynamicMap::clearTrainList()
{
    trainList.clear();
}

void DynamicMap::clearScoreMap()
{
    scoreMap.clear();
}


}
}
}
