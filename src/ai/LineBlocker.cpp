#include <ai/LineBlocker.h>
#include <ai/CollisionAllower.h>
#include <world/Town.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;

LineBlocker::LineBlocker(std::set<std::pair<int, const world::Line *> > *blockLines,
                         world::Train *train, models::GoodType type):
    blockLines(blockLines), train(train), type(type)
{

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
            ownBlockLine.insert(trainA->getLine());
        }

    }

    for(auto post : world->getPostList())

    {
        if (post->getPostType() == models::PostType::TOWN ||
                post->getPostType() == getPostTypeByGood(type))
            continue;

        for (auto line : post->getPoint()->getEdges())
        {
            ownBlockLine.insert(line);
        }
    }
}

void LineBlocker::changeCurrentBlock(const world::Point *point)
{
    for (auto block : currentBlock)
    {
        blockLines->erase(block);
    }

    currentBlock.clear();

    const world::Town *homeTown = (world::Town *)train->getPlayer()->getHome();

    for (auto line : point->getEdges())
    {

        if (point != homeTown->getPoint())
        {
            currentBlock.push_back({train->getIdx(), line});
            blockLines->insert(currentBlock.back());
        }
    }


}

bool LineBlocker::contain(const world::Line *line)
{
    return ownBlockLine.count(line) == 0 ? false : true;
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
