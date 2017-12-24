#pragma once

#include <set>
#include <world/World.h>
#include <ai/LineBlock.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class LineBlocker
{
public:
    LineBlocker(std::set<std::pair<int, LineBlock> > *blockLines, world::Train *train,
                models::GoodType type);
    void makeOwnBlockLines();
    void changeCurrentBlock(const world::Point *point);
    bool contain(const world::Line *line);
    void changeType(models::GoodType type);


private:
    std::set<std::pair<int, LineBlock> > *blockLines;
    world::Train *train;
    models::GoodType type;

    std::set<LineBlock> ownBlockLine;
    std::vector<std::pair<int,LineBlock> > currentBlock;





    models::PostType getPostTypeByGood(models::GoodType type);


};





}
}
}
