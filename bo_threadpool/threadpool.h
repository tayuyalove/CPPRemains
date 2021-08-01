#include "taskqueue.h"
#include <vector>
#include <functional>
#include <memory>

using namespace std;
class Thread;
class ThreadPool
{
    public:
    using Task = std::function<void()>;
    ThreadPool(int threadSize,int taskSize)
    :_threadSize(threadSize),_taskSize(taskSize),_tq(_taskSize),_isExit(0)
    {
        _threads.reserve(_threadSize);
    }
    ~ThreadPool();
    void addTask(Task &&);
    void start();
    void stop();
    private:

    void threadFunc();
    Task getTask();
    int _threadSize;
    int _taskSize;
    vector<shared_ptr< Thread>> _threads;
    TaskQueue _tq;
    bool _isExit;
};