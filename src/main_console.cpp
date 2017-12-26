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
    const char *gameName = "wg-forge3";
    int playersNum = 4;

    if (argc > 1){
        if (argc != 6){
            std::cerr << "Wrong number of arguments." << std::endl;
            std::cerr << "Usage:  console (login) (host) (port) (game) (playersNum)" << std::endl;
            return -1;
        }

        login = argv[1];
        host = argv[2];
        port = atoi(argv[3]);
        gameName = argv[4];
        playersNum = atoi(argv[5]);

        if (!port){
            std::cerr << "Invalid port." << std::endl;
            return -1;
        }

        if (!playersNum)
        {
            std::cerr << "Invalid players num." << std::endl;
            return -1;
        }
    }

    Runner runner(login, host, port, gameName, playersNum);
    ai::ComplexBot complexBot;
    runner.setBot(&complexBot);

    runner.run();

    return 0;
}
