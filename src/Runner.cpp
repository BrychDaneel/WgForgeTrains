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
    models::PlayerModel * player = trainClient.getMyPlayer();
    models::StaticMap *staticMap = new models::StaticMap();

    trainClient.getStaticMap(staticMap);
    models.push_back(*player);
    world.init(models, *staticMap, &commandSender);

    delete staticMap;


    models::DynamicMap *dynamicMap = new models::DynamicMap();

    trainClient.getDynamicMap(dynamicMap);
    world.update(*dynamicMap);

    if (bot != nullptr)
        bot->init(&world);

    while (true)
    {
        trainClient.getDynamicMap(dynamicMap);
        world.update(*dynamicMap);


        if (bot != nullptr)
            bot->step();

        // make command

        //sleep(1);

    }



}
