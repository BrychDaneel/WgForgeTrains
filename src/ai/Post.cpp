#include <ai/Post.h>
#include <easylogging++/easylogging++.h>

#include <set>
using namespace tiger::trains;

ai::Post::Post(world::Point *point):postPoint(point)
{

}

void ai::Post::init(const world::World &world)
{
    for (auto point : world.getPointList())
    {
        minLen[point] = inf;
        ancestors[point] = nullptr;
    }

    minLen[postPoint] = 0;
    ancestors[postPoint] = postPoint;

    std::set< std::pair<int, const world::Point*>> setMinLen;
    setMinLen.insert({0, postPoint});

    while (!setMinLen.empty())
    {
        auto minPoint = setMinLen.begin()->second;
        setMinLen.erase(setMinLen.begin());
        for (auto line : minPoint->getEdges())
        {
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

int ai::Post::getMinLen(const world::Point *point) const
{
    return minLen[point];
}

const world::Point *ai::Post::getPoint() const
{
    return postPoint;
}

std::vector<const world::Point *> ai::Post::getMinPath(const world::Point *point) const
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
