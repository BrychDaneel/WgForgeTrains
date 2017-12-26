#include <ai/BotSharedData.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;


BotSharedData::BotSharedData()
{

}

void BotSharedData::init(const world::World *world)
{
    cheker.setHome((world::Town *)world->getPlayerList()[0]->getHome());
    const world::Point *point = world->getPlayerList()[0]->getHome()->getPoint();
    barrierMap.insert({point,Barrier(point)});
    barrierMap[point].setLines(point->getEdges());
    blockLines.insert({-1, {point->getEdges()[1], point} });
    blockLines.insert({-1, {point->getEdges()[0],
                            point->getEdges()[0]->getAnotherPoint(point)
                           }
                      });
}

void BotSharedData::clear(world::World *world)
{
    for (auto train : world->getTrainList())
    {
        if (trainInPoints.count(train) != 0 && !train->getEvents().empty() &&
                train->getEvents().back()->getTick() >= world->getTickNum() - 3)
        {

            inPoints.erase(trainInPoints[train]);
            trainInPoints.erase(train);
        }

        if (train->getPoint() == train->getPlayer()->getHome()->getPoint())
            cheker.comeHome(train);

    }

    cheker.blockHome(inPoints);
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

std::set<const world::Point *> *BotSharedData::getInPoints()
{
    return &inPoints;
}

std::map<const world::Train *, const world::Point *> *BotSharedData::getTrainInPoints()
{
    return &trainInPoints;
}

HomeChecker *BotSharedData::getCheker()
{
    return &cheker;
}
