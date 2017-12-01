#ifndef _TIGER_TRAIN_AI_I_PATH_GENERATOR_H_
#define _TIGER_TRAIN_AI_I_PATH_GENERATOR_H_


#include <ai/ScoreCalc.h>
#include <ai/Post.h>
#include <vector>


namespace tiger{
namespace trains{
namespace ai{


class IPathGenerator{

public:

    virtual void init(ScoreCalc* scoreCalc, std::vector<int> postIdxs, int len) = 0;
    virtual void tick() = 0;
    virtual int nextMarket() = 0;

private:

    int current;
    int len;
    ScoreCalc* scoreCalc;
    std::vector<int> postIdxs;

};


}
}
}


#endif
