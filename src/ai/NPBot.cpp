#include <ai/NPBot.h>


#include <map>
#include <ai/Post.h>
#include <world/Town.h>


using namespace tiger::trains::ai;


NPBot::NPBot(IPathGenerator* pathGenerator){
    this->pathGenerator = pathGenerator;
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
        postMap[post->getPoint()->getIdx()] = aiPost;
        if (post->getPostType() == models::PostType::MARKET)
            idxs.push_back(post->getPoint()->getIdx());
    }

    homeAiPost = postMap[world->getPlayerList()[0]->getHome()->getPoint()->getIdx()];

    scoreCalc = new ScoreCalc(&postMap, homeAiPost, homeAiPost, maxGenTick);

    pathGenerator->init(scoreCalc, idxs, pathLen);

}


void NPBot::step(){

    world::Train* train = world->getTrainList()[0];
    int pos = train->getPosition();
    if (train->getLine() != nullptr && pos != 0 && pos != train->getLine()->getLenght())
        return;

    /*if (path.empty()){*/
    if (train->getPoint()->getPost()!=nullptr){
        scoreCalc->setStartPost(postMap[train->getPoint()->getIdx()]);
        scoreCalc->setStartProduct(train->getProduct());
        path = pathGenerator->generate();
        path.pop();
    }

    followPath();
}


void NPBot::followPath(){
    world::Train* train = world->getTrainList()[0];

    world::Point* point = train->getPoint();

    const world::Point* nextPoint = path.front();
    path.pop();

    world::Line* line = world->getLine(point, nextPoint);

    models::SpeedType speed = models::SpeedType::FORWARD;
    if (line->getStartPont() != point)
        speed = models::SpeedType::REVERSE;

    train->move(line, speed);
}
