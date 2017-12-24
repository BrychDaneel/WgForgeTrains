#include <Runner.h>

#include <vector>
#include <models/PlayerModel.h>
#include <models/CoordsMap.h>
#include <CommandSender.h>
#include <memory>
#include <easylogging++/easylogging++.h>

using namespace tiger::trains;


Runner::Runner(const char *name, const char *addr, int port, const char *gameName, const int playersNum)
    : name(name), addr(addr), port(port), gameName(gameName), playersNum(playersNum), world(),bot(nullptr)
{

}

world::World *Runner::getWorld()
{
    return &world;
}

void Runner::setBot(ai::IBot *bot)
{
    this->bot = bot;
}


void Runner::run()
{
    client::TCPTrainClient trainClient(name, addr, port, gameName, playersNum);

    doRun = true;
    int retVal = trainClient.login();

    if (retVal)
    {
        LOG(ERROR) << "Login error: " << trainClient.getLastErrorMessage();
        return;
    }

    CommandSender commandSender(&trainClient);

    std::vector<models::PlayerModel> models;
    models::PlayerModel *player = trainClient.getMyPlayer();
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

    while (doRun && !world.isGameOver())
    {
        trainClient.getDynamicMap(dynamicMap);
        world.update(*dynamicMap);

        if (world.isGameOver())
            break;

        if (world.getPlayerList().size() < (size_t)playersNum)
        {
            sleep(1000);
            continue;
        }

        if (bot != nullptr)
            bot->step();


        trainClient.turn();

        world.tick();
    }

}


void Runner::shutDown()
{
    doRun = false;
}
