#include <ai/Barrier.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;


Barrier::Barrier(const world::Point *point)
    : point(point)
{

}

bool Barrier::doMove(const world::Line *line)
{

    if (canMove(line))
    {
        lineInTick[line] = line->getWorld()->getTickNum();
        return true;
    }


    return false;
}

bool Barrier::canMove(const world::Line *line)
{
    if (lineInTick.count(line) == 0 ||
            lineInTick[line] == line->getWorld()->getTickNum())
        return false;

    return true;
}

void Barrier::setLines(const std::vector<world::Line *> &lines)
{
    for (auto line : lines)
    {
        if (line->getEndPont() == point || line->getStartPont() == point)
            lineInTick[line] = -1;
    }
}
