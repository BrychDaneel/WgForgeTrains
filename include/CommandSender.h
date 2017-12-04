#ifndef _COMMAND_SENDER_H_
#define _COMMAND_SENDER_H_

#include <world/ICommandSender.h>
#include <client/ITrainClient.h>

namespace tiger
{
    namespace trains
    {

        class CommandSender: public world::ICommandSender
        {
            public:
                CommandSender(client::ITrainClient *client);
                void move(const models::MoveModel &move);



            private:

                client::ITrainClient *client;
        };

    }
}


#endif
