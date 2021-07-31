#include "taskqueue.h"

using namespace std;

void TaskQueue::push(const Task&t)
{
    MutexGuard autoLock(_mutex);
    while(full())
    {
        _notFull.wait();
    }
    _que.push(t);
    _notEmpty.notify();
}

Task TaskQueue::pop()
{
    MutexGuard autoLock(_mutex);
    while(empty())
    {
        _notEmpty.wait();
    }
    Task t = _que.front();
    _que.pop();
    _notFull.notify();
    return t;
}

