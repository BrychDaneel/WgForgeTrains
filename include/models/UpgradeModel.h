#pragma once


#include <vector>


namespace tiger
{
namespace trains
{
namespace models
{


class UpgradeModel
{
private:

    std::vector<int> trainIdxList;
    std::vector<int> postIdxList;

public:

    UpgradeModel();
    UpgradeModel(const std::vector<int> &trainIdxList, const std::vector<int> &postIdxList);

    const std::vector<int> &getTrainIdxList() const;
    const std::vector<int>  &getPostIdxList() const;

    void clearTrainIdxList();
    void clearPostIdxList();

    void addTrainIdx(const int idx);
    void addPostIdx(const int idx);
};


}
}
}
