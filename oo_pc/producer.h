#include "Thread.h"
#include "taskqueue.h"
#include <iostream>
#include <unistd.h>
using namespace std;
class Producer
:public Thread
{
    public:
    Producer(TaskQueue &tq)
    :_tq(tq){}
    void run()
    {
        srand(100);
        while(1)
        {
        Task t = rand();
        _tq.push(t);
        cout<<"producer task "<<t<<"to queue"<<endl;
        sleep(1);
        }
    }
    private:
    TaskQueue &_tq;
};
