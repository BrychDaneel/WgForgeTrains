#include <ai/TrainAI.h>
#include <ai/CollisionAllower.h>
#include <climits>
#include <world/Town.h>
#include <world/Market.h>
#include <world/Storage.h>
#include <algorithm>




using namespace tiger::trains;
using namespace tiger::trains::ai;



TrainAI::TrainAI(std::set<std::pair<int, const world::Line *> > *busyLines,
                 models::GoodType type, world::Train *train)
    : busyLines(busyLines), type(type), train(train), lastPoint(nullptr), nextPoint(nullptr)
{
    id = train->getIdx();
}

void TrainAI::step()
{

    makeOwnBusyLines(*train->getWorld());
    calculatePath(*train->getWorld());
    makePath(*train->getWorld());

    if (currentPath.size() > 1 && train->getPoint() == currentPath[0])
    {
        changeCurrentBusy();
        lastPoint = currentPath[0];
        currentPath.erase(currentPath.begin());
        makeMove();

    } else
    {
        if (!currentPath.empty() && train->getPoint() != currentPath[0])
            makeMove();
    }

}

void TrainAI::makeMove()
{

    world::Line *currentLine = train->getLine();

    for(auto line : currentPath[0]->getEdges())
    {
        if (line->getAnotherPoint(currentPath[0]) == lastPoint)
        {
            currentLine = line;
            break;
        }
    }


    models::SpeedType speed;

    if (currentLine->getEndPont() == currentPath[0])
        speed = models::SpeedType::FORWARD;
    else
        speed = models::SpeedType::REVERSE;

    train->move(currentLine, speed);
}

int TrainAI::calculateProducts(int tick, world::IPost *post)
{

    if (tick == 0)
        tick = 1;

    if (type ==  models::GoodType::PRODUCT)
    {
        const world::Market *market = (world::Market*)post;
        return std::min(market->predictProduct(tick), train->getGoodsCapacity() - train->getGoods() );
    }
    if (type == models::GoodType::ARMOR)
    {
        const world::Storage *storage = (world::Storage*)post;
        return std::min(storage->predictArmor(tick), train->getGoodsCapacity() - train->getGoods() );
    }


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
    ancestors[startPoint] = startPoint;
    setMinLen.insert({lenToStart, startPoint});

    const world::Point* endPoint = train->getLine()->getEndPont();
    int lenToEnd = train->getLine()->getLenght() - train->getPosition();

    minLen[endPoint] = lenToEnd;
    ancestors[endPoint] = endPoint;
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
    int maxLen;
    if (type == models::GoodType::PRODUCT)
        maxLen = (homeTown->getProduct() - 10) / homeTown->getPopulation();
    else
        maxLen = 150;

    int currHomeLen = minLen[homeTown->getPoint()];
    double maxProductByTick = 0;
    world::Point *tempNext = nullptr;
    int killer = 0;
    while(true)
    {
        for (auto post : world.getPostList())
        {
            if (post->getPostType() != getPostTypeByGood(type) || minLen[post->getPoint()] == INT_MAX)
                continue;

            int tempLen = minLen[post->getPoint()]*2 + minLen[homeTown->getPoint()]; // TODO DIJKSTRA for MARKET/TOWN

            if (tempLen > maxLen + killer)
                continue;




            int predict =  calculateProducts(minLen[post->getPoint()], post);
            if (((double)predict)/(tempLen-currHomeLen + 1) > maxProductByTick)
            {
                tempNext = post->getPoint();
                maxProductByTick = ((double)predict)/(tempLen-currHomeLen + 1);
            }

        }

        if (lastPoint != homeTown->getPoint() || maxProductByTick > homeTown->getPopulation() -  killer)
            break;
        killer++;
    }

    if (tempNext == nullptr)
        nextPoint = train->getPlayer()->getHome()->getPoint();
    else
        nextPoint = tempNext;





    if (train->getGoods() >= train->getGoodsCapacity())
        nextPoint = homeTown->getPoint();

    //if (currentPost != homePost && maxProductByTick < homeTown.getPopulation() - 0.6)
      // nextPost = homePost;  // May improve score or not


    currentPath = getMinPath(nextPoint);


}

std::vector<const world::Point *> TrainAI::getMinPath(const world::Point *point)
{
    std::vector<const world::Point *> vec;
    const world::Point *temp_point=point;

    if (ancestors[temp_point] == nullptr)
        return vec;

    while (ancestors[temp_point] != temp_point)
    {
        vec.push_back(temp_point);
        temp_point = ancestors[temp_point];
    }

    vec.push_back(temp_point);
    std::reverse(vec.begin(), vec.end());

    return vec;
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

void TrainAI::changeCurrentBusy()
{
    for (auto busy : currentBusy)
    {
        busyLines->erase(busy);
    }

    currentBusy.clear();

    for (auto line : currentPath[1]->getEdges())
    {
        if (line->getAnotherPoint(currentPath[1]) == currentPath[0])
        {
            currentBusy.push_back({id, line});
            busyLines->insert(currentBusy.back());
        }
    }
}
