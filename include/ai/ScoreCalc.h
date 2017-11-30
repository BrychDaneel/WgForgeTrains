#ifndef _SCORE_CALC_BOT_H_
#define _SCORE_CALC_BOT_H_
#include <vector>
#include <map>
#include <world/World.h>
#include <ai/Post.h>
#include <ai/ArtMarket.h>
#include <ai/ArtTown.h>

namespace tiger
{
namespace trains
{
namespace ai
{

    class ScoreCalc
    {
    public:
        ScoreCalc(std::map<int, Post*> *postMap);

        double getScore(const std::vector<int> &vec);

    private:

        std::map<int, Post*> *postMap;
        std::map<int, ArtTown> artTownMap;
        std::map<int, ArtMarket> artMarketMap;


    };


}

}

}

#endif
