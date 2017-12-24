#include <ai/PathCalculator.h>
#include <models/MoveModel.h>
#include <climits>
#include <algorithm>
#include <ai/CollisionAllower.h>

using namespace tiger::trains::ai;
using namespace tiger::trains;

PathCalculator::PathCalculator(world::Train *train, BotSharedData *sharedData)
    : train(train), sharedData(sharedData)
{

}

void PathCalculator::calculate(LineBlocker &blocker)
{

    std::set< std::pair<int, const world::Point *>> setMinLen;

    startInit(blocker, setMinLen);

    while (!setMinLen.empty())
    {
        auto minPoint = setMinLen.begin()->second;
        setMinLen.erase(setMinLen.begin());

        for (auto line : minPoint->getEdges())
        {
            if (blocker.contain(line))
                continue;

            const world::Point *another = line->getAnotherPoint(minPoint);

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



std::vector<const world::Point *> PathCalculator::getMinPath(const world::Point *point)
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



int PathCalculator::getMinLen(const world::Point *point)
{
    return minLen[point];
}



void PathCalculator::startInit(LineBlocker &blocker,
                               std::set< std::pair<int, const world::Point *>> &setMinLen)
{
    for (auto point : train->getWorld()->getPointList())
    {
        minLen[point] = INT_MAX;
        ancestors[point] = nullptr;
    }

    if (train->getPoint() != nullptr)
        startOnPoint(blocker, setMinLen);
    else
        startOnLine(setMinLen);



}

void PathCalculator::startOnPoint(LineBlocker &blocker, std::set<std::pair<int, const world::Point *> > &setMinLen)
{
    const world::Point *point = train->getPoint();
    models::MoveModel move(1, train->getIdx(), models::SpeedType::STOP);
    CollisionAllower allower;

    minLen[point] = 0;
    ancestors[point] = point;
    setMinLen.insert({0, point});

    for (auto line : point->getEdges())
    {
        if (blocker.contain(line) || !sharedData->canMove(point, line))
            continue;

        move.setLineIdx(line->getIdx());

        if (line->getStartPont() == point)
            move.setSpeedType(models::SpeedType::FORWARD);
        else
            move.setSpeedType(models::SpeedType::REVERSE);

        bool canMove = true;

        for (auto otherTrain : train->getPosibleCollisions(&move))
        {
            if (!allower.isCollisionAllow(train, otherTrain) &&
                    train->getPlayer() != otherTrain->getPlayer())
            {
                canMove = false;
            }
        }

        if (canMove)
        {
            minLen[line->getAnotherPoint(point)] = line->getLenght();
            ancestors[line->getAnotherPoint(point)] = point;
            setMinLen.insert({line->getLenght(), line->getAnotherPoint(point)});
        }

    }
}

void PathCalculator::startOnLine(std::set<std::pair<int, const world::Point *> > &setMinLen)
{
    const world::Point *startPoint = train->getLine()->getStartPont();

    bool canBack = true;
    models::MoveModel move(train->getLine()->getIdx(), train->getIdx(), models::SpeedType::REVERSE);
    CollisionAllower allower;


    for (auto otherTrain : train->getPosibleCollisions(&move))
    {
        if (!allower.isCollisionAllow(train, otherTrain) &&
                train->getPlayer() != otherTrain->getPlayer())
        {
            canBack = false;
        }
    }

    if (canBack)
    {
        int lenToStart = train->getLine()->getLenght();
        minLen[startPoint] = lenToStart;
        ancestors[startPoint] = startPoint;
        setMinLen.insert({lenToStart, startPoint});
    }



    bool canForward = true;
    move.setSpeedType(models::SpeedType::REVERSE);

    for (auto otherTrain : train->getPosibleCollisions(&move))
    {
        if (!allower.isCollisionAllow(train, otherTrain) &&
                train->getPlayer() != otherTrain->getPlayer())
        {
            canForward = false;
        }

    }

    const world::Point *endPoint = train->getLine()->getEndPont();

    if (canForward)
    {
        int lenToEnd = train->getLine()->getLenght() - train->getPosition();
        minLen[endPoint] = lenToEnd;
        ancestors[endPoint] = endPoint;
        setMinLen.insert({lenToEnd, endPoint});
    }
}
