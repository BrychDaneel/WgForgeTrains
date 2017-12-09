#pragma once
#ifndef _TIGER_TRAINS_Q_RUNNER_THREAD_H_
#define _TIGER_TRAINS_Q_RUNNER_THREAD_H_


#include <QThread>
#include <Runner.h>
#include <Runner.h>


namespace tiger{
namespace trains{


class QRunnerThred : public QThread{
    Q_OBJECT

private:

    Runner* runner;

public:

    QRunnerThred(Runner* runner, QObject* ppw = 0);
    void run();
    void shutDown();

};


}
}


#endif
