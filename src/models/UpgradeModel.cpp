#include <models/UpgradeModel.h>

namespace tiger
{
namespace trains
{
namespace models
{


UpgradeModel::UpgradeModel()
{
}


UpgradeModel::UpgradeModel(const std::vector<int> &trainIdxList, const std::vector<int> &postIdxList)
    : trainIdxList(trainIdxList), postIdxList(postIdxList)
{
}


const std::vector<int> &UpgradeModel::getTrainIdxList() const
{
    return trainIdxList;
}


const std::vector<int>  &UpgradeModel::getPostIdxList() const
{
    return postIdxList;
}


void UpgradeModel::clearTrainIdxList()
{
    trainIdxList.clear();
}


void UpgradeModel::clearPostIdxList()
{
    postIdxList.clear();
}


void UpgradeModel::addTrainIdx(const int idx)
{
    trainIdxList.push_back(idx);
}


void UpgradeModel::addPostIdx(const int idx)
{
    postIdxList.push_back(idx);
}


}
}
}

