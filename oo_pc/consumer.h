#include<iostream>
#include "pthread.h"
#include "taskqueue.h"
#include <unistd.h>
using namespace std;

class Consumer
:public Thread
{
    public:
    Consumer(TaskQueue &tq)
    :_tq(tq)
    {}

    void run()
    {
        while(1)
        {

        Task t = _tq.pop();
        cout<<"consumer Task is"<<t<<endl;
        sleep(1);
        }
    }
    private:
    TaskQueue &_tq;
};