#ifndef _TIGER_TRAIN_AI_GENERATORS_ANNEALING_H_
#define _TIGER_TRAIN_AI_GENERATORS_ANNEALING_H_


#include <ai/IPathGenerator.h>
#include <ai/ScoreCalc.h>
#include <ai/Post.h>
#include <vector>
#include <queue>


namespace tiger{
namespace trains{
namespace ai{
namespace generators {


class Annealing : public IPathGenerator{

public:

    Annealing(const int seed=1);

    void init(ScoreCalc* scoreCalc, std::vector<int>& postIdxs, int len);
    void tick();
    int pop();
    int front();

private:

    int len;
    int seed;
    ScoreCalc* scoreCalc;
    std::vector<int> postIdxs;
    std::queue<int> path;

    void calculate();

};


}
}
}
}


#endif

