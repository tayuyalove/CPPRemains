#include "threadpool.h"

#include "thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;


void ThreadPool::start()
{
    for(int i = 0;i< _threadSize;++i)
    {
        shared_ptr<Thread>pt(new Thread(bind(&ThreadPool::threadFunc,this)));
        _threads.push_back(pt);
    }
    for(auto &p : _threads)
        p->start();
}

void ThreadPool::stop()
{
    if(!_isExit)
    {
        while(!_tq.empty())
            sleep(1);
        _isExit =1;
        _tq.wakeup();
        for(auto & pt : _threads)
            pt->join();
    }
}

ThreadPool::~ThreadPool()
{
    if(!_isExit)
        stop();
}

void ThreadPool::addTask(Task &&task)
{
    _tq.push(move(task));
}

Task ThreadPool::getTask()
{
    return _tq.pop();
}

void ThreadPool::threadFunc()
{
    while(!_isExit)
    {
        Task t = getTask();
        if(t)
        {
            t();
        }
    }
}