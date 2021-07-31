#include <iostream>
#include "NoneCopyable.h"

class Thread
:public NoneCopyable
{
    public:
    Thread();
    virtual ~Thread();
    static void *threadFunc(void*);
    void start();
    void join();
    virtual void run() = 0;
    int getPid()
    {
        return pthid;
    }
    void detach();
    private:
    bool isRunning;
    pthread_t pthid;
};