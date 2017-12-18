#include <Runner.h>
#include <ai/ComplexBot.h>
#include <easylogging++/easylogging++.h>

#include <client/TCPTrainClient.h>
#include <cstdlib>
#include <iostream>


using namespace tiger::trains;


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]){

    const char * login = "Tiger";
    const char * host = "wgforge-srv.wargaming.net";
    int port = 443;

    if (argc > 1){
        if (argc > 4){
            std::cerr << "Wrong number of arguments." << std::endl;
            std::cerr << "Usage:  console (login) (host) (port)" << std::endl;
            return -1;
        }
        login = argv[1];
        host = argv[2];
        port = atoi(argv[3]);

        if (!port){
            std::cerr << "Invalid port." << std::endl;
            return -1;
        }
    }

    Runner runner(login, host, port);
    ai::ComplexBot complexBot;
    runner.setBot(&complexBot);

    runner.run();

    return 0;
}
