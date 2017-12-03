#include <ai/generators/Annealing.h>


#include <cstdlib>
#include <cmath>
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


void Annealing::tick(){

}


int Annealing::pop(){
    if (path.empty())
        calculate();

    int res = path.front();
    path.pop();
    return res;
}


int Annealing::front(){
    if (path.empty())
        calculate();

    return path.front();
}


void Annealing::calculate(){

    srand(seed);

    float maxT = 80;
    float minT = 0.0001;
    float t = maxT;
    float k = 0.97;
    int it = 100;

    vector<int> state;
    for (int i=0; i<len; i++)
        state.push_back(postIdxs[rand()%postIdxs.size()]);

    int e = 300 - scoreCalc->getScore(state);


    while (t > minT){
        for (int i=0; i<it; i++){

            int change = rand() % len;
            int oldIdx = state[change];
            state[change] = postIdxs[rand()%postIdxs.size()];

            int ne = 300 - scoreCalc->getScore(state);

            int d = e - ne;

            if (ne < e)
                e = ne;
            else
                if (rand()*1./RAND_MAX < exp(d/t))
                    e = ne;
                else
                    state[change] = oldIdx;
        }
        t *= k;
    }

    LOG(INFO) << "predict score: " << 300 - e;

    for (int idx : state)
        path.push(idx);
}
