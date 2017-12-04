#ifndef _TIGER_TRAIN_AI_NP_BOT_H_
#define _TIGER_TRAIN_AI_NP_BOT_H_


#include <world/World.h>
#include <ai/IBot.h>
#include <ai/Post.h>
#include <ai/ScoreCalc.h>
#include <ai/IPathGenerator.h>
#include <queue>


namespace tiger{
namespace trains{
namespace ai{


class NPBot: public IBot{

public:

    NPBot(IPathGenerator* pathGenerator);

    ~NPBot();

    void init(world::World *world);
    void step();

private:

    ScoreCalc* scoreCalc = nullptr;
    IPathGenerator* pathGenerator;
    world::World *world;
    std::map<int, Post*> postMap;
    const int maxGenTick = 100;
    const int pathLen = 33;
    std::queue<const world::Point*> path;
    Post* homeAiPost;

    void followPath();
    bool needHome(Post* current, Post* nextPost);

};


}
}
}


#endif

