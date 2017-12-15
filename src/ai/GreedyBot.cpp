#include <ai/GreedyBot.h>

#include <world/Train.h>
#include <world/Town.h>
#include <models/SpeedType.h>
#include <algorithm>
#include <easylogging++/easylogging++.h>

using namespace tiger::trains::ai;

GreedyBot::GreedyBot():world(nullptr),tick(0)
{

}

void GreedyBot::init(world::World *world)
{
    this->world = world;
    for (auto post : world->getPostList())
    {
        postMap[post->getPoint()->getIdx()] = new Post(post->getPoint());
        postMap[post->getPoint()->getIdx()]->init(*world);
    }
    homePost =  postMap[world->getPlayerList()[0]->getHome()->getPoint()->getIdx()];
    currentPost = homePost;
    currentLine = nullptr;
    nextPost = nullptr;

}



void GreedyBot::step()
{

    world::Train * train = world->getTrainList()[0];
    world::Town * town = (world::Town*)world->getHome(world->getPlayerList()[0]);

    train->upgrade();
    town->upgrade();
    checkArrival();

    if (nextPost == nullptr)
    {
        findNextPost();
    }

    makeStep();


}

void GreedyBot::findNextPost()
{
    ArtTown homeTown = ArtTown(homePost);
    int maxLen = homeTown.getProduct() / homeTown.getPopulation();
    int currHomeLen = currentPost->getMinLen(homeTown.getPost()->getPoint());
    double maxProductByTick = 0;
    Post *tempNext = nullptr;
    int killer = 0;
    while(true)
    {
        for (std::pair<int, Post*> mapPair : postMap)
        {
            if (mapPair.second == currentPost ||
                    mapPair.second->getPoint()->getPost()->getPostType() == models::PostType::TOWN)
                continue;

            int tempLen = mapPair.second->getMinLen(currentPost->getPoint())
                    + mapPair.second->getMinLen(homePost->getPoint());


            if (tempLen > maxLen + killer)
                continue;

            ArtMarket market(mapPair.second);
            ArtMarket newMarket = market.getFuture(mapPair.second->getMinLen(currentPost->getPoint()));

            if (((double)newMarket.getProduct())/(tempLen-currHomeLen + 1) > maxProductByTick)
            {
                tempNext = mapPair.second;
                maxProductByTick = ((double)newMarket.getProduct())/(tempLen-currHomeLen + 1);
            }

        }

        if (currentPost != homePost || maxProductByTick > homeTown.getPopulation() -  killer)
            break;
        killer++;
    }
    if (tempNext == nullptr)
        nextPost = homePost;
    else
        nextPost = tempNext;
    world::Train * train = world->getTrainList()[0];


    if (currentPost->getPoint()->getPost()->getPostType() == models::PostType::MARKET
            && currHomeLen < maxLen)
    {
        ArtMarket mark = ArtMarket(currentPost);
        if (mark.getReplenishment() > maxProductByTick)
            nextPost = nullptr;
    }

    if (train->getGoods() >= train->getGoodsCapacity())
        nextPost = homePost;

    //if (currentPost != homePost && maxProductByTick < homeTown.getPopulation() - 0.6)
      // nextPost = homePost;  // May improve score or not
    if (nextPost != nullptr)
        currentPath = currentPost->getMinPath(nextPost->getPoint());



}

// p1, p3, p4, p5

void GreedyBot::makeStep()
{
    if (nextPost == nullptr)
            return;
    world::Train * train = world->getTrainList()[0];
    if (train->getPoint() == currentPath[0])
    {

        for(auto line : currentPath[0]->getEdges())
        {
            if (line->getAnotherPoint(currentPath[0]) == currentPath[1])
            {
                currentLine = line;
                break;
            }
        }

        currentPath.erase(currentPath.begin());

    }



    models::SpeedType speed;
    if (currentLine->getEndPont() == currentPath[0])
        speed = models::SpeedType::FORWARD;
    else
        speed = models::SpeedType::REVERSE;

    train->move(currentLine, speed);

}


void GreedyBot::checkArrival()
{
    if (nextPost == nullptr)
        return;

    world::Train * train = world->getTrainList()[0];

    if (train->getPoint() == nextPost->getPoint())
    {
        currentPost = nextPost;
        nextPost = nullptr;
        currentLine = nullptr;

    }
}
