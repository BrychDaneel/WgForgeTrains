#include <ai/TrainGoalPredictor.h>


#include <map>
#include <set>
#include <climits>


namespace tiger{
namespace trains{
namespace ai{


TrainGoalPredictor::TrainGoalPredictor(){
}


std::pair<world::IPost*, int> TrainGoalPredictor::predictGoal(const world::Train* train){

    std::map<const world::Point*, int> minLen;

    for (auto point : train->getWorld()->getPointList())
        minLen[point] = INT_MAX;

    const world::Point* startPoint = train->getLine()->getStartPont();
    int lenToStart = train->getPosition();
    const world::Point* endPoint = train->getLine()->getEndPont();
    int lenToEnd = train->getLine()->getLenght() - train->getPosition();

    minLen[startPoint] = lenToStart;
    minLen[endPoint] = lenToEnd;

    std::set< std::pair<int, const world::Point*>> setMinLen;
    setMinLen.insert({lenToStart, startPoint});
    setMinLen.insert({lenToEnd, endPoint});

    while (!setMinLen.empty())
    {
        auto minPoint = minLen.begin()->first;
        setMinLen.erase(setMinLen.begin());
        for (auto line : minPoint->getEdges())
        {
            const world::Point* another = line->getAnotherPoint(minPoint);
            if (minLen[another] > minLen[minPoint] + line->getLenght())
            {
                setMinLen.erase({minLen[another], another});
                minLen[another] = minLen[minPoint] + line->getLenght();
                setMinLen.insert({minLen[another], another});
            }
        }

    }

    world::IPost* minPost = train->getPlayer()->getHome();

    for (world::IPost* post : train->getWorld()->getPostList())
        if (minLen[minPost->getPoint()] > minLen[post->getPoint()]){
            if (post->getPostType() == models::PostType::MARKET && train->getGoodsType() == models::GoodType::PRODUCT)
                minPost = post;
            if (post->getPostType() == models::PostType::STORAGE && train->getGoodsType() == models::GoodType::ARMOR)
                minPost = post;
        }

    return std::make_pair(minPost, minLen[minPost->getPoint()]);
}


}
}
}
