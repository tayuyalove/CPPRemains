#include <iostream>
#include "thread.h"
using namespace std;
class WorkThread
:public Thread
{
    void run()
    {
        cout<<rand()<<endl;
    }
};


int main()
{
    for(int i = 0;i<10;++i)
    {
        Thread * t = new WorkThread();
        t->start();
    }
    return 0;
}