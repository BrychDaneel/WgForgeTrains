#include <gui/QWorldWidget.h>
#include <QApplication>
#include <Runner.h>
#include <QRunnerThread.h>
#include <ai/JustDoItBot.h>
#include <ai/GreedyBot.h>
#include <easylogging++/easylogging++.h>


using namespace tiger::trains;


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]){

    QApplication application(argc, argv);

    Runner runner("tiger8", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "localhost", 30001);

    ai::JustDoItBot bot;
    ai::GreedyBot greedyBot;
    runner.setBot(&greedyBot);

    QRunnerThred runnerThread(&runner);
    runnerThread.start();

    gui::QWorldWidget worldWidget(runner.getWorld());
    worldWidget.show();

    return application.exec();
}
