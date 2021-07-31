#include "threadpool.h"
#include "workthread.h"
#include <unistd.h>
using namespace std;

void ThreadPool::start()
{
    for(int i = 0;i<_threadSize;++i)
    {
        shared_ptr<Thread> pThread (new WorkThread(*this));
        _threads.push_back(std::move(pThread));
    }
    for(auto &it : _threads)
        it->start();
}

void ThreadPool::stop()
{
    if(!_isExit)
    {
        while(!_tq.empty())
        {
            sleep(1);
        }
        _isExit = 1;
        _tq.wakeup();
        for(auto &it : _threads)
            it->join();
    }
}

ThreadPool::~ThreadPool()
{
    if(!_isExit)
    {
        stop();
    }
}

void ThreadPool::addTask(Task * t)
{
    _tq.push(t);
} 

Task * ThreadPool::getTask()
{
    return _tq.pop();
}

void ThreadPool::threadFunc()
{
    while(!_isExit)
    {
        Task *t = getTask();
        if(t) t->process();
    }
}