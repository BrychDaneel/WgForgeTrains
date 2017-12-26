#include <ai/SwitchAI.h>


#include <world/Town.h>

namespace tiger
{
namespace trains
{
namespace ai
{


SwitchAI::SwitchAI(const world::World *world, const std::vector<TrainAI *> &trainAIList)
{
    for (TrainAI *bot : trainAIList)
    {
        if (bot->getType() == models::GoodType::ARMOR)
            armorBots.push_back(bot);

        if (bot->getType() == models::GoodType::PRODUCT)
            productBots.push_back(bot);
    }

    this->world = world;
}

void SwitchAI::step()
{
    int population = static_cast<world::Town *>(world->getPlayerList()[0]->getHome())->getPopulation();
    int needProductCompacity;
    int level = static_cast<world::Town *>(world->getPlayerList()[0]->getHome())->getLevel();

    needProductCompacity = 60 *(population + level - 1);


    for (TrainAI *bot : productBots)
        if (!canSwitch(bot))
            needProductCompacity -= bot->getTrain()->getGoodsCapacity();


    int i = 0;

    while (i < productBots.size())
    {
        TrainAI *bot = productBots[i];

        if (canSwitch(bot))
            if (needProductCompacity > 0 || productBots.size() < 2)
                needProductCompacity -= bot->getTrain()->getGoodsCapacity();
            else
            {
                productBots.erase(productBots.begin() + i);
                bot->changeType(models::GoodType::ARMOR);
                armorBots.push_back(bot);
                i--;
            }

        i++;
    }

    i = 0;

    while (i < armorBots.size())
    {
        TrainAI *bot = armorBots[i];

        if (canSwitch(bot) && needProductCompacity > 0 && armorBots.size() > 1)
        {
            armorBots.erase(armorBots.begin() + i);
            bot->changeType(models::GoodType::PRODUCT);
            productBots.push_back(bot);
        }
        else
            i++;
    }
}

bool SwitchAI::canSwitch(TrainAI *bot)
{
    if (bot->getTrain()->getGoodsType() != models::GoodType::NONE)
        return false;

    for (world::IPost *post : world->getPostList())
        if (post->getPostType() != models::PostType::TOWN)
            for (world::Line *line : post->getPoint()->getEdges())
                if (bot->getTrain()->getLine() == line)
                    return false;

    return true;
}


}
}
}
