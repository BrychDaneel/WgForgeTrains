#include <ai/PathCalculator.h>
#include <climits>
#include <algorithm>

using namespace tiger::trains::ai;
using namespace tiger::trains;

PathCalculator::PathCalculator(world::Train *train) : train(train)
{

}

void PathCalculator::calculate(LineBlocker &blocker)
{
    for (auto point : train->getWorld()->getPointList())
    {
        minLen[point] = INT_MAX;
        ancestors[point] = nullptr;
    }

    std::set< std::pair<int, const world::Point *>> setMinLen;


    const world::Point *startPoint = train->getLine()->getStartPont();
    int lenToStart = train->getPosition();

    if (lenToStart != train->getLine()->getLenght())
    {
        minLen[startPoint] = lenToStart;
        ancestors[startPoint] = startPoint;
        setMinLen.insert({lenToStart, startPoint});
    }

    const world::Point *endPoint = train->getLine()->getEndPont();
    int lenToEnd = train->getLine()->getLenght() - train->getPosition();

    if (train->getPosition() != 0)
    {
        minLen[endPoint] = lenToEnd;
        ancestors[endPoint] = endPoint;
        setMinLen.insert({lenToEnd, endPoint});
    }


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
