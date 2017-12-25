#include <ai/TrainAI.h>
#include <ai/CollisionAllower.h>
#include <climits>
#include <world/Town.h>
#include <world/Market.h>
#include <world/Storage.h>
#include <ai/TrainGoalPredictor.h>
#include <algorithm>
#include <cmath>
#include <easylogging++/easylogging++.h>




using namespace tiger::trains;
using namespace tiger::trains::ai;



TrainAI::TrainAI(BotSharedData *data, models::GoodType type, world::Train *train)
    : sharedData(data), type(type), train(train), lineBlocker(train, type, data),
      pathCalculator(train, data), lastPoint(nullptr), nextPoint(nullptr)
{
    id = train->getIdx();
}

void TrainAI::step()
{



    lineBlocker.makeOwnBlockLines();
    makeGoalPredict(*train->getWorld());
    pathCalculator.calculate(lineBlocker);

    if (train->getMove() != nullptr)
        return;

    makePath(*train->getWorld());

    if (currentPath.size() > 1 && train->getPoint() == currentPath[0])
    {
        lineBlocker.changeCurrentBlock(currentPath);
        lastPoint = currentPath[0];
        currentPath.erase(currentPath.begin());
        makeMove();

    }

    else
    {
        if (currentPath.size() == 1)
        {
            int i = 2;
        }

        if (!currentPath.empty() && train->getPoint() != currentPath[0])
            makeMove();


    }

}

void TrainAI::changeType(models::GoodType type)
{
    lineBlocker.changeType(type);
    this->type = type;
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
    {
        speed = models::SpeedType::FORWARD;

        if (train->getPosition() + 1 == train->getLine()->getLenght())
        {
            if (!sharedData->getInPoints()->count(currentPath[0]))
                sharedData->getInPoints()->insert(currentPath[0]);
            else
            {

                int stopLen = train->getPosition() - 1;
                bool stoped = false;

                while (!stoped && stopLen > 0)
                {
                    stoped = true;

                    for (auto otherTrain : train->getLine()->getTrains())
                    {
                        if (otherTrain->getPosition() == stopLen)
                        {
                            otherTrain->setMove(models::MoveModel(otherTrain->getLine()->getIdx(),
                                                                  otherTrain->getIdx(),
                                                                  models::SpeedType::STOP));
                            --stopLen;

                            stoped = false;
                        }

                    }
                }

                speed = models::SpeedType::STOP;
            }
        }

        if (train->getPoint())
        {
            sharedData->getInPoints()->erase(train->getPoint());
        }
    }
    else
    {
        speed = models::SpeedType::REVERSE;

        if (train->getPosition() == 1)
        {
            if (!sharedData->getInPoints()->count(currentPath[0]))
                sharedData->getInPoints()->insert(currentPath[0]);
            else
            {
                int stopLen = 2;
                bool stoped = false;

                while (!stoped && stopLen < train->getLine()->getLenght())
                {
                    stoped = true;

                    for (auto otherTrain : train->getLine()->getTrains())
                    {
                        if (otherTrain->getPosition() == stopLen)
                        {
                            otherTrain->setMove(models::MoveModel(otherTrain->getLine()->getIdx(),
                                                                  otherTrain->getIdx(),
                                                                  models::SpeedType::STOP));

                            ++stopLen;

                            stoped = false;
                        }

                    }
                }

                speed = models::SpeedType::STOP;

            }
        }

        if (train->getPoint())
        {
            sharedData->getInPoints()->erase(train->getPoint());
        }

    }

    train->move(currentLine, speed);
}

int TrainAI::calculateProducts(int tick, world::IPost *post)
{

    if (tick == 0)
        tick = 1;

    int visitTime = -1;

    for (auto goal : goalPredict)
    {
        if (goal.first != post)
            continue;

        if (goal.second < tick && goal.second > visitTime)
        {
            visitTime = goal.second;
        }
    }

    if (type ==  models::GoodType::PRODUCT)
    {
        const world::Market *market = (world::Market *)post;
        return std::min(market->predictProduct(tick, visitTime), train->getGoodsCapacity() - train->getGoods() );
    }
    //if (type == models::GoodType::ARMOR)
    else
    {
        const world::Storage *storage = (world::Storage *)post;
        return std::min(storage->predictArmor(tick, visitTime), train->getGoodsCapacity() - train->getGoods() );
    }


}




void TrainAI::makePath(const world::World &world)
{

    const world::Town *homeTown = (world::Town *)train->getPlayer()->getHome();


    int currHomeLen = pathCalculator.getMinLen(homeTown->getPoint());
    double maxProductByTick = 0;
    world::Point *tempNext = nullptr;
    int killer = 0;

    while(true)
    {
        for (auto post : world.getPostList())
        {
            if (post->getPostType() != getPostTypeByGood(type)
                    || pathCalculator.getMinLen(post->getPoint()) == INT_MAX
               )//  || train->getPoint() == post->getPoint())
                continue;

            int tempLen = pathCalculator.getMinLen(post->getPoint())*2
                          + pathCalculator.getMinLen(homeTown->getPoint()); // TODO DIJKSTRA for MARKET/TOWN

            if (sharedData->getCheker()->needHome(train,tempLen - killer, currHomeLen, type))
                continue;




            int predict =  calculateProducts(pathCalculator.getMinLen(post->getPoint()), post);

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

    currentPath = pathCalculator.getMinPath(nextPoint);

}

void TrainAI::makeGoalPredict(const world::World &world)
{
    TrainGoalPredictor predictor;

    for (auto trainI : world.getTrainList() )
    {
        if (trainI->getPlayer() != train->getPlayer())
        {
            goalPredict.push_back(predictor.predictGoal(trainI));
        }
    }
}


models::PostType TrainAI::getPostTypeByGood(models::GoodType type)
{
    switch (type)
    {
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

