#include"thread.h"
#include <iostream>
#include "threadpool.h"

class WorkThread
:public Thread
{
    public:
    WorkThread(ThreadPool &tp)
    :_tp(tp){}
    void run()
    {
        _tp.threadFunc();
    }
    private:
    ThreadPool & _tp;
};
