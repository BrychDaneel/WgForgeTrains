#include <gui/QWorldWidget.h>
#include <QApplication>
#include <Runner.h>
#include <QRunnerThread.h>
#include <ai/JustDoItBot.h>
#include <ai/GreedyBot.h>
#include <ai/NPBot.h>
#include <ai/ComplexBot.h>
#include <ai/generators/Annealing.h>
#include <easylogging++/easylogging++.h>

#include <client/TCPTrainClient.h>


using namespace tiger::trains;


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]){

    QApplication application(argc, argv);

    Runner runner("Tiger", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "localhost", 30001);

    //ai::JustDoItBot bot;
    ai::GreedyBot greedyBot;
    ai::ComplexBot complexBot;
    //ai::generators::Annealing pathGenerator;
    //ai::NPBot npBot(&pathGenerator);

    runner.setBot(&complexBot);

    QRunnerThred runnerThread(&runner);
    runnerThread.start();

    gui::QWorldWidget worldWidget(runner.getWorld());
    worldWidget.show();

    int res = application.exec();
    runnerThread.shutDown();
    runnerThread.wait();
    return res;
}
