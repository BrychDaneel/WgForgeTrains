#include <QRunnerThread.h>


namespace tiger{
namespace trains{


QRunnerThred::QRunnerThred(Runner* runner, QObject* ppw) : QThread(ppw), runner(runner){

}


void QRunnerThred::run(){
    try
    {
        runner->run();

    }
    catch(...)
    {
        runner->~Runner();
        throw;
    }

}


}
}
