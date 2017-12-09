#ifndef _RUNNER_H_
#define _RUNNER_H_

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
                client::TCPTrainClient trainClient;
                world::World world;
                ai::IBot *bot;
                const char *name;
                const char *addr;
                int port;
                bool doRun;


            public:
                Runner(const char *name, const char *addr, int port);

                void setBot(ai::IBot *bot);

                world::World* getWorld();

                void shutDown();

                virtual ~Runner()
                {
                }

                void run();
        };
    }
}


#endif
