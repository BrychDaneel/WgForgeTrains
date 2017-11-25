#ifndef _RUNNER_H_
#define _RUNNER_H_

#include <string>
#include <client/TCPTrainClient.h>
#include <world/World.h>

namespace tiger
{
    namespace trains
    {
        class Runner
        {
            private:
                client::TCPTrainClient trainClient;
                world::World world;

            public:
                Runner(const char *name, const char *addr, int port);
                virtual ~Runner()
                {
                    trainClient.~TCPTrainClient();
                }

                void run();
        };
    }
}


#endif
