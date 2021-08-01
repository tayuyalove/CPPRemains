#ifndef THREAD
#define THREAD
#include <iostream>
#include "Nonecopyable.h"
#include <functional>
using namespace std;
typedef function<void()> ThreadCallBack;
class Thread
:public NoneCopyable
{
    public:
    Thread(ThreadCallBack &&);
    ~Thread();
    static void* threadFunc(void *);
    void start();
    void join();
    private:
    pthread_t pthid;
    bool isRunning;
    ThreadCallBack cb;
};
#endif