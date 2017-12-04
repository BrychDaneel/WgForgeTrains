#include <ai/generators/Annealing.h>


#include <cstdlib>
#include <cmath>
#include <ctime>
#include <libs/easylogging++/easylogging++.h>


using namespace tiger::trains::ai::generators;


Annealing::Annealing(const int seed){
    this->seed = seed;
}


void Annealing::init(ScoreCalc* scoreCalc, std::vector<int>& postIdxs, int len){
    this->scoreCalc = scoreCalc;
    this->postIdxs = postIdxs;
    this->len = len;
}


double Annealing::scoreToEnerg(double score){

   /* if (score == -1)
        return 400;

    if (score == 0)
        return 300;

    return 300 / score;*/
    if (score < 0)
        return 10100;
    return 10000 - score;
}


double Annealing::energToScore(double energ){
    /*if (energ == 400)
        return -1;

    if (energ == 300)
        return 0;

    return 1 / energ * 300;*/
    if (energ > 10000)
        return -1;
    return 10000 - energ;
}


std::queue<const tiger::trains::world::Point*> Annealing::generate(){

    srand(seed);

    float maxT = 80;
    float minT = 0.1;
    float t = maxT;
    float k = 0.97;
    int it = 200;

    vector<int> state;
    for (int i=0; i<len; i++)
        state.push_back(postIdxs[rand()%postIdxs.size()]);

    double e = scoreToEnerg(scoreCalc->getScore(state));

    int startTime = time(0);

    while (t > minT){
        for (int i=0; i<it; i++){

            int change = rand() % len;
            int oldIdx = state[change];
            while (state[change] == oldIdx)
                state[change] = postIdxs[rand()%postIdxs.size()];

            double ne = scoreToEnerg(scoreCalc->getScore(state));

            double d = e - ne;

            if (ne < e)
                e = ne;
            else
                if (rand()*1./RAND_MAX < exp(d/t)){
                    e = ne;
                   // LOG(INFO) <<  "swap "<< d << " " << t << " "<< exp(d/t);
                }
                else
                    state[change] = oldIdx;
        }
        t *= k;
        //LOG(INFO) << t << ": " << e << "=" << energToScore(e);
    }

    LOG(INFO) << "Finish in: " << time(0) - startTime;
    LOG(INFO) << "predict score: " << energToScore(e);

    std::queue<const world::Point*> path;

    for (const world::Point* point : scoreCalc->getLastPath())
        path.push(point);

    return path;
}
