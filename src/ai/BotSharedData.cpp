#include <ai/BotSharedData.h>


using namespace tiger::trains::ai;
using namespace tiger::trains;


BotSharedData::BotSharedData()
{
}

std::set<std::pair<int, const world::Line *> > *BotSharedData::getBlockLines()
{
    return &blockLines;
}

HomeChecker *BotSharedData::getCheker()
{
    return &cheker;
}
