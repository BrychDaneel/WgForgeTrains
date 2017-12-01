#include <ai/NPBot.h>


#include <map>
#include <ai/Post.h>


using namespace tiger::trains::ai;


NPBot::NPBot(){
}


NPBot::~NPBot(){
    delete scoreCalc;
    for (auto pair : postMap)
        delete pair.second;
}


void NPBot::init(world::World* world){
    this->world = world;
    std::vector<int> idxs;
    for (world::IPost* post : world->getPostList()){
        Post* aiPost = new Post(post->getPoint());
        aiPost->init(*world);
        postMap[post->getIdx()] = aiPost;
        idxs.push_back(post->getIdx());
    }

    Post* homeAiPost = postMap[world->getPlayerList()[0]->getHome()->getPoint()->getIdx()];
    current = homeAiPost;
    next = current;

    scoreCalc = new ScoreCalc(&postMap, current, homeAiPost, 100);

    //pathGenerator =
    pathGenerator->init(scoreCalc, idxs, 50);
}


void NPBot::step(){
    //if (next == current)
}

