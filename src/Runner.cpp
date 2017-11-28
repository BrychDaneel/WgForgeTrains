#include "Runner.h"

#include <vector>
#include <models/PlayerModel.h>
#include <memory>

using namespace tiger::trains;


Runner::Runner(const char *name, const char *addr, int port):trainClient(name, addr, port), world()
{

}

void Runner::run()
{
    trainClient.login();

    std::vector<models::PlayerModel> models;
    std::shared_ptr<const models::PlayerModel> player = trainClient.getMyPlayer();
    std::shared_ptr<const models::StaticMap> staticMap = trainClient.getStaticMap();
    models.push_back(*player);
    world.init(models, *staticMap);
    player.reset();
    staticMap.reset();
    while (true)
    {
        std::shared_ptr<const models::DynamicMap> dynamicMap = trainClient.getDynamicMap();
        world.update(*dynamicMap);


        //work bot

        // make command

        sleep(1);

    }



}
