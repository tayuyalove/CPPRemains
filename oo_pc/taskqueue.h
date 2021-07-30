#ifndef TQ
#define TQ
#include "thread.h"
#include "mutexlock.h"
#include "condition.h"
#include <queue>
typedef int Task;
class TaskQueue
{
    public:
    TaskQueue(int queSize)
    :_queSize(queSize),_mutex(),_notFull(_mutex),_notEmpty(_mutex){}
    void push(const Task & );
    Task pop();
    bool empty()
    {
        return _que.size()==0;
    }
    bool full()
    {
        return _que.size() == _queSize;
    }
    
    private:
    std::queue<Task> _que;
    size_t _queSize;
    MutexLock _mutex;
    Condition _notFull;
    Condition _notEmpty;
};
#endif
