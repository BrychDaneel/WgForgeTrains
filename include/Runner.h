#pragma once


#include <string>
#include <client/TCPTrainClient.h>
#include <world/World.h>
#include <ai/IBot.h>

namespace tiger
{
namespace trains
{


class Runner
{
private:
    const char *name;
    const char *addr;
    int port;
    const char *gameName;
    int playersNum;
    world::World world;
    ai::IBot *bot;
    bool doRun;


public:
    Runner(const char *name, const char *addr, int port, const char *gameName, const int playersNum);

    void setBot(ai::IBot *bot);

    world::World *getWorld();

    void shutDown();

    virtual ~Runner()
    {
    }

    void run();
};


}
}
