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
        idxs.push_back(post->getPoint()->getIdx());
    }

    homeAiPost = postMap[world->getPlayerList()[0]->getHome()->getPoint()->getIdx()];
    next = homeAiPost;

    scoreCalc = new ScoreCalc(&postMap, next, homeAiPost, 200);

    pathGenerator->init(scoreCalc, idxs, 50);
}


void NPBot::step(){
    world::Train* train = world->getTrainList()[0];
    int pos = train->getPosition();
    if (train->getLine() != nullptr && pos != 0 && pos != train->getLine()->getLenght())
        return;

    if (!path.empty()){
        followPath();
        return;
    }

    Post* current = next;
    scoreCalc->setStartPost(current);

    next = postMap[pathGenerator->front()];
    while (current == next){
        pathGenerator->pop();
        next = postMap[pathGenerator->front()];
    }

    if (needHome(current, next))
        next = homeAiPost;
    else
        pathGenerator->pop();

    for (const world::Point* station : current->getMinPath(next->getPoint()))
        path.push(station);

    path.pop();

    followPath();
}


void NPBot::followPath(){
    world::Train* train = world->getTrainList()[0];
    int pos = train->getPosition();
    world::Line* currentLine = train->getLine() ;

    world::Point* point = pos ? currentLine->getEndPont() : currentLine->getStartPont();

    const world::Point* nextPoint = path.front();
    path.pop();

    world::Line* line = world->getLine(point, nextPoint);

    models::SpeedType speed = models::SpeedType::FORWARD;
    if (line->getStartPont() != point)
        speed = models::SpeedType::REVERSE;

    train->move(line, speed);
}


bool NPBot::needHome(Post* current, Post* nextPost){
    int len = current->getMinLen(nextPost->getPoint()); // Path to Market
    int home_len = nextPost->getMinLen(homeAiPost->getPoint()); // Path to Home from Market

    world::Town* home = (world::Town*) homeAiPost->getPoint()->getPost();

    if (home->getPopulation() * (len + home_len) > home->getProduct())
        return true;

    return false;
}
