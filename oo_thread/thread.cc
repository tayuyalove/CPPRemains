#include <iostream>
#include "thread.h"

Thread::Thread()
:isRunning(0),pthid(0)
{}

void * Thread::threadFunc( void * arg)
{
    Thread * t = static_cast<Thread*> (arg);
    if(t)
    {
        t->run();
    }
    return NULL;
}

void Thread::start()
{
    pthread_create(&pthid,NULL,threadFunc,this);
    isRunning = 1;
}

void Thread::join()
{
    if(isRunning)
    {
        pthread_join(pthid,NULL);
        isRunning = false;
    }
}

Thread::~Thread()
{
    if(isRunning)
        pthread_detach(pthid);
}