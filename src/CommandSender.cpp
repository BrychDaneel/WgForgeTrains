#include <CommandSender.h>

using namespace tiger::trains;

CommandSender::CommandSender(client::ITrainClient *client):client(client)
{

}


void CommandSender::move(const models::MoveModel &move)
{
    client->move(move);
}

void CommandSender::turn()
{
    client->turn();
}


void CommandSender::upgrade(const models::UpgradeModel& upgrade){
    client->upgrade(upgrade);
}
