#pragma once


#include <models/PostModel.h>
#include <models/TrainModel.h>

#include <vector>
#include <map>


using std::vector;


namespace tiger{
namespace trains{
namespace models{


class DynamicMap{

private:

    int idx = 0;
    vector<PostModel> postList;
    vector<TrainModel> trainList;
    std::map<std::string, int> scoreMap;

public:

    DynamicMap();
    DynamicMap(const int idx);

    void addPost(const PostModel& post);
    void addTrain(const TrainModel& train);
    void addScore(const std::string& name, const int score);

    int getIdx() const;
    const vector<PostModel>& getPostList() const;
    const vector<TrainModel>& getTrainList() const;
    const std::map<std::string, int>& getScoreMap() const;

    void setIdx(int idx);
    void clearPostList();
    void clearTrainList();
    void clearScoreMap();

};


}
}
}
