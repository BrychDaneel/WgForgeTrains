#pragma once

#include <world/ICommandSender.h>
#include <client/ITrainClient.h>

namespace tiger
{
namespace trains
{


class CommandSender: public world::ICommandSender
{
public:
    explicit CommandSender(client::ITrainClient *client);
    void move(const models::MoveModel &move);
    bool upgrade(const models::UpgradeModel &upgrade);
    void turn();

private:

    client::ITrainClient *client;
};


}
}
