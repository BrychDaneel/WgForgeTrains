#include <gui/QWorldWidget.h>
#include <QApplication>
#include <Runner.h>
#include <QRunnerThread.h>
#include <ai/JustDoItBot.h>


using namespace tiger::trains;


int main(int argc, char *argv[]){

    QApplication application(argc, argv);

    Runner runner("tiger6", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "wgforge-srv.wargaming.net", 443);
    //Runner runner("tiger", "localhost", 30001);

    ai::JustDoItBot bot;
    bot.init(runner.getWorld());
    runner.setBot(&bot);

    QRunnerThred runnerThread(&runner);
    runnerThread.start();

    gui::QWorldWidget worldWidget(runner.getWorld());
    worldWidget.show();

    return application.exec();
}
