#include<iostream>
#include "thread.h"

Thread::Thread(ThreadCallBack &&c)
:cb(move(c)),pthid(0),isRunning(0)
{}

void Thread::start()
{
    pthread_create(&pthid,NULL,threadFunc,this);
    isRunning = true;
}

void* Thread::threadFunc(void * arg)
{
    Thread* t = static_cast<Thread*> (arg);
    if(t)
    {
        t->cb();
    }   
    return NULL;
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
    {
        pthread_detach(pthid);
    }
}
