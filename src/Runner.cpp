#include <Runner.h>

#include <vector>
#include <models/PlayerModel.h>
#include <models/CoordsMap.h>
#include <CommandSender.h>
#include <memory>

using namespace tiger::trains;


Runner::Runner(const char *name, const char *addr, int port)
    :trainClient(name, addr, port), world(),bot(nullptr), name(name),
        addr(addr), port(port)
{

}

world::World* Runner::getWorld(){
    return &world;
}

void Runner::setBot(ai::IBot *bot)
{
    this->bot = bot;
}


void shutDown(){

}


void Runner::run()
{
    doRun = true;
    int retVal = trainClient.login();
    CommandSender commandSender(&trainClient);

    std::vector<models::PlayerModel> models;
    models::PlayerModel * player = trainClient.getMyPlayer();
    models::StaticMap *staticMap = new models::StaticMap();
    models::CoordsMap coordsMap;

    trainClient.getStaticMap(staticMap);
    trainClient.getCoordinate(&coordsMap);
    models.push_back(*player);
    world.init(models, *staticMap, &commandSender);
    world.setCoords(coordsMap);

    delete staticMap;


    models::DynamicMap *dynamicMap = new models::DynamicMap();

    trainClient.getDynamicMap(dynamicMap);
    world.update(*dynamicMap);

    if (bot != nullptr)
        bot->init(&world);

    while (doRun)
    {
        trainClient.getDynamicMap(dynamicMap);
        world.update(*dynamicMap);


        if (bot != nullptr)
            bot->step();


        trainClient.turn();

        world.tick();
    }



}


void Runner::shutDown(){
    doRun = false;
}
