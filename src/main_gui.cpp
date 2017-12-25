#include <gui/QWorldWidget.h>
#include <QApplication>
#include <Runner.h>
#include <QRunnerThread.h>
#include <ai/ComplexBot.h>
#include <easylogging++/easylogging++.h>

#include <client/TCPTrainClient.h>


using namespace tiger::trains;


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);


    const char *login = "Tiger228";
    const char *host = "localhost";
    int port = 2000;
    const char *gameName = "TigersGame";
    int playersNum = 4;


    if (argc > 5)
    {
        login = argv[1];
        host = argv[2];
        port = atoi(argv[3]);
        gameName = argv[4];
        playersNum = atoi(argv[5]);

        if (!port)
        {
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

    QRunnerThred runnerThread(&runner);
    runnerThread.start();

    gui::QWorldWidget worldWidget(runner.getWorld());
    worldWidget.show();

    int res = application.exec();
    runnerThread.shutDown();
    runnerThread.wait();
    return res;
}
