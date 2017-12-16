#include <ai/TrainAI.h>
using namespace tiger::trains::ai;



TrainAI::TrainAI(std::set<std::pair<int, const world::Line *> > *busyLines,
                 models::GoodType type, world::Train *train)
    : busyLines(busyLines), type(type), train(train)
{
    id = train->getIdx();
}

void TrainAI::step(const world::World &world)
{
    makeOwnBusyLines(world);
}

void TrainAI::makeOwnBusyLines(const world::World &world)
{
    for (auto busyLine : *busyLines)
    {
        if (busyLine.first != id)
        {
            ownBusy.insert(busyLine.second);
        }

    }
}
