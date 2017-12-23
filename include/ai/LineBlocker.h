#pragma once

#include <set>
#include <world/World.h>

namespace tiger
{
namespace trains
{
namespace ai
{

class LineBlocker
{
public:
    LineBlocker(std::set<std::pair<int, const world::Line *>> *blockLines, world::Train *train,
                models::GoodType type);
    void makeOwnBlockLines();
    void changeCurrentBlock(const world::Point *point);
    bool contain(const world::Line *line);
    void changeType(models::GoodType type);


private:
    std::set<std::pair<int, const world::Line *>> *blockLines;
    world::Train *train;
    models::GoodType type;

    std::set<const world::Line *> ownBlockLine;
    std::vector<std::pair<int, const world::Line *>> currentBlock;



    models::PostType getPostTypeByGood(models::GoodType type);


};




}
}
}
