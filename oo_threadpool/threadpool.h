#ifndef THREADPOOL
#define THREADPOOL
#include "taskqueue.h"
#include <vector>
#include <memory>
class Thread;
class WorkThread;
using namespace std;

class Task
{
    public:
    virtual void process() = 0;
};

class ThreadPool
{
    friend WorkThread;
    public:
    ThreadPool(int threadSize,int taskSize)
    :_taskSize(taskSize),_threadSize(threadSize),_tq(_taskSize),_isExit(0)
    {}
    void start();
    void stop();
    void addTask(Task *);
    ~ThreadPool();
    private:
    void threadFunc();
    Task * getTask();
    int _threadSize;
    
    int _taskSize;
    TaskQueue _tq;
    vector<shared_ptr<Thread>> _threads;
    bool _isExit;
};
#endif