#include <ai/BotSharedData.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;


BotSharedData::BotSharedData()
{

}

void BotSharedData::init(const world::World *world)
{
    const world::Point *point = world->getPlayerList()[0]->getHome()->getPoint();
    barrierMap.insert({point,Barrier(point)});
    barrierMap[point].setLines(point->getEdges());
    blockLines.insert({-1, {point->getEdges()[1], point} });
    blockLines.insert({-1, {point->getEdges()[0],
                            point->getEdges()[0]->getAnotherPoint(point)
                           }
                      });
}

std::set<std::pair<int, LineBlock> > *BotSharedData::getBlockLines()
{
    return &blockLines;
}

bool BotSharedData::doMove(const world::Point *point, const world::Line *line)
{
    if (barrierMap.count(point) == 0)
        return true;

    return barrierMap[point].doMove(line);
}

bool BotSharedData::canMove(const world::Point *point, const world::Line *line)
{
    if (barrierMap.count(point) == 0)
        return true;

    return barrierMap[point].canMove(line);
}

std::set<world::Point *> *BotSharedData::getInPoints()
{
    return &inPoints;
}

HomeChecker *BotSharedData::getCheker()
{
    return &cheker;
}
