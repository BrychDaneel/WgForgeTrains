#include <ai/LineBlocker.h>
#include <ai/CollisionAllower.h>
#include <world/Town.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;

LineBlocker::LineBlocker(world::Train *train, models::GoodType type, BotSharedData *data)
    : train(train), type(type), sharedData(data)
{
    blockLines = sharedData->getBlockLines();
}

void LineBlocker::makeOwnBlockLines()
{
    CollisionAllower allower;

    world::World *world = train->getWorld();


    ownBlockLine.clear();

    for (auto blockLine: *blockLines)
    {
        if (blockLine.first != train->getIdx())
        {
            ownBlockLine.insert(blockLine.second);
        }
    }

    for(auto trainA : world->getTrainList())
    {

        if (allower.isCollisionAllow(train, trainA))
        {
            ownBlockLine.insert({trainA->getLine(),trainA->getLine()->getStartPont()});
        }

    }

    for(auto post : world->getPostList())

    {
        if (post->getPostType() == models::PostType::TOWN ||
                post->getPostType() == getPostTypeByGood(type))
            continue;

        for (auto line : post->getPoint()->getEdges())
        {
            ownBlockLine.insert({line, line->getStartPont()});
        }
    }
}

void LineBlocker::changeCurrentBlock(const std::vector<const world::Point *> &points)
{
    for (auto block : currentBlock)
    {
        blockLines->erase(block);
    }

    currentBlock.clear();

    const world::Town *homeTown = (world::Town *)train->getPlayer()->getHome();


    for (auto line : points[1]->getEdges())
    {

        if (line->getAnotherPoint(points[1]) == points[0])
        {
            if (sharedData->doMove(points[0], line))
            {
                currentBlock.push_back({train->getIdx(), {line, points[1]} });
                blockLines->insert(currentBlock.back());
            }
        }

        if (line->getAnotherPoint(points[1]) == points[2])
        {
            currentBlock.push_back({train->getIdx(), {line, points[0]} });
            blockLines->insert(currentBlock.back());
        }

        /* if (line->getAnotherPoint(points[1]) != points[2] &&
                 line->getAnotherPoint(points[1]) != points[0] &&
                 points[1] != homeTown->getPoint())
         {
             currentBlock.push_back({train->getIdx(), {line, line->getAnotherPoint(points[1])} });
             blockLines->insert(currentBlock.back());
         }*/

    }


}

bool LineBlocker::contain(LineBlock lineBlock)
{
    return ownBlockLine.count(lineBlock) == 0 ? false : true;
}

void LineBlocker::changeType(models::GoodType type)
{
    this->type = type;
}

tiger::trains::models::PostType LineBlocker::getPostTypeByGood(tiger::trains::models::GoodType type)
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
