#pragma once
#ifndef _TIGER_TRAINS_MODELS_UPGRADE_MODEL_H_
#define _TIGER_TRAINS_MODELS_UPGRADE_MODEL_H_


#include <vector>


namespace tiger{
namespace trains{
namespace models{


class UpgradeModel{

private:

    std::vector<int> trainIdxList;
    std::vector<int> postIdxList;

public:

    UpgradeModel();

    const std::vector<int>& getTrainIdxList() const;
    const std::vector<int>&  getPostIdxList() const;

    void clearTrainIdxList();
    void clearPostIdxList();

    void addTrainIdx(const int idx);
    void addPostIdx(const int idx);

};


}
}
}


#endif

