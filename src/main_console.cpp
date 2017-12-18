#include <Runner.h>
#include <ai/ComplexBot.h>
#include <easylogging++/easylogging++.h>

#include <client/TCPTrainClient.h>


using namespace tiger::trains;


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]){

    Runner runner("Tiger", "wgforge-srv.wargaming.net", 443);
    ai::ComplexBot complexBot;
    runner.setBot(&complexBot);

    runner.run();

    return 0;
}
