#include <ai/TrainAI.h>
#include <ai/CollisionAllower.h>
#include <climits>
#include <world/Town.h>
#include <world/Market.h>


using namespace tiger::trains;
using namespace tiger::trains::ai;



TrainAI::TrainAI(std::set<std::pair<int, const world::Line *> > *busyLines,
                 models::GoodType type, world::Train *train)
    : busyLines(busyLines), type(type), train(train), lastPoint(nullptr), nextPoint(nullptr)
{
    id = train->getIdx();
}

void TrainAI::step(const world::World &world)
{
    makeOwnBusyLines(world);
    calculatePath(world);
    makePath();

}

int TrainAI::calculateProducts()
{

}

bool TrainAI::needHome()
{

}

void TrainAI::calculatePath(const world::World &world)
{

    for (auto point : world.getPointList())
    {
        minLen[point] = INT_MAX;
        ancestors[point] = nullptr;
    }

    std::set< std::pair<int, const world::Point*>> setMinLen;


    const world::Point* startPoint = train->getLine()->getStartPont();
    int lenToStart = train->getPosition();

    minLen[startPoint] = lenToStart;
    setMinLen.insert({lenToStart, startPoint});

    const world::Point* endPoint = train->getLine()->getStartPont();
    int lenToEnd = train->getLine()->getLenght() - train->getPosition();

    minLen[endPoint] = lenToEnd;
    setMinLen.insert({lenToEnd, endPoint});


    while (!setMinLen.empty())
    {
        auto minPoint = setMinLen.begin()->second;
        setMinLen.erase(setMinLen.begin());
        for (auto line : minPoint->getEdges())
        {
            if (ownBusy.count(line) != 0)
                continue;
            const world::Point* another = line->getAnotherPoint(minPoint);
            if (minLen[another] > minLen[minPoint] + line->getLenght())
            {
                setMinLen.erase({minLen[another], another});
                minLen[another] = minLen[minPoint] + line->getLenght();
                ancestors[another] = minPoint;
                setMinLen.insert({minLen[another], another});
            }
        }

    }

}

void TrainAI::makeOwnBusyLines(const world::World &world)
{
    CollisionAllower allower;

    for (auto busyLine : *busyLines)
    {
        if (busyLine.first != id)
        {
            ownBusy.insert(busyLine.second);
        }
    }

    for(auto trainA : world.getTrainList())
    {
        if (trainA != train)
        {
            if (allower.isCollisionAllow(train, trainA))
            {
                ownBusy.insert(trainA->getLine());
            }
        }
    }

    for(auto post : world.getPostList())

    {
        if (post->getPostType() == models::PostType::TOWN ||
                post->getPostType() == getPostTypeByGood(type))
            continue;
        for (auto line : post->getPoint()->getEdges())
        {
            ownBusy.insert(line);
        }
    }
}



void TrainAI::makePath(const world::World &world)
{
    const world::Town *homeTown = (world::Town*)train->getPlayer()->getHome();
    int maxLen = homeTown->getProduct() / homeTown->getProductCapacity(); // TODO SWITCH
    int currHomeLen = minLen[homeTown->getPoint()];
    double maxProductByTick = 0;
    world::Point *tempNext = nullptr;
    int killer = 0;
    while(true)
    {
        for (auto post : world.getPostList())
        {
            if (post->getPostType() != getPostTypeByGood(type))
                continue;

            int tempLen = minLen[post->getPoint()]*2 + minLen[homeTown->getPoint()]; // TODO DIJKSTRA for MARKET/TOWN

            if (tempLen > maxLen + killer)
                continue;


            const world::Market *market = (world::Market*)post;

            if (((double)newMarket.getProduct())/(tempLen-currHomeLen + 1) > maxProductByTick)
            {
                tempNext = mapPair.second;
                maxProductByTick = ((double)newMarket.getProduct())/(tempLen-currHomeLen + 1);
            }

        }

        if (lastPoint != homeTown->getPoint() || maxProductByTick > homeTown->getPopulation() -  killer)
            break;
        killer++;
    }


}

models::PostType TrainAI::getPostTypeByGood(models::GoodType type)
{
    switch (type) {
    case models::GoodType::PRODUCT:
        return models::PostType::MARKET;
        break;
    case models::GoodType::ARMOR:
        return models::PostType::STORAGE;
        break;
    default:
        return models::PostType::UNKNOWN;
        break;
    }
}