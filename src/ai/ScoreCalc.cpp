#include <ai/ScoreCalc.h>
#include <models/PostType.h>

using namespace tiger::trains::ai;

ScoreCalc::ScoreCalc(std::map<int, Post *> *postMap):postMap(postMap)
{
    for(std::pair<int, tiger::trains::ai::Post *> mapPair : *postMap)
    {
        switch(mapPair.second->getPoint()->getPost()->getPostType())
        {
        case models::PostType::MARKET:
            artMarketMap[mapPair.first] = ArtMarket(mapPair.second);
            break;
        case models::PostType::TOWN:
            artTownMap[mapPair.first] = ArtTown(mapPair.second);
            break;
        default:
            break;
        }

    }
}

double ScoreCalc::getScore(const std::vector<int> &vec)
{
    double ans = 0;
    for (int idx : vec)
    {
        const Post* post = (*postMap)[idx];

    }

}
