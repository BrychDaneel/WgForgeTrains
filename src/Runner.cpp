#include <Runner.h>

#include <vector>
#include <models/PlayerModel.h>
#include <CommandSender.h>
#include <memory>

using namespace tiger::trains;


Runner::Runner(const char *name, const char *addr, int port):trainClient(name, addr, port), world(),bot(nullptr)
{

}

world::World* Runner::getWorld(){
    return &world;
}

void Runner::setBot(ai::IBot *bot)
{
    this->bot = bot;
}


void Runner::run()
{
    trainClient.login();
    CommandSender commandSender(&trainClient);

    std::vector<models::PlayerModel> models;
    std::shared_ptr<const models::PlayerModel> player = trainClient.getMyPlayer();
    std::shared_ptr<const models::StaticMap> staticMap = trainClient.getStaticMap();
    models.push_back(*player);
    world.init(models, *staticMap, &commandSender);
    player.reset();
    staticMap.reset();
    if (bot != nullptr)
        bot->init(&world);

    while (true)
    {
        std::shared_ptr<const models::DynamicMap> dynamicMap = trainClient.getDynamicMap();
        world.update(*dynamicMap);


        if (bot != nullptr)
            bot->step();

        // make command

        sleep(1);

    }



}
