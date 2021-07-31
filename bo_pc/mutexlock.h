#ifndef MUTEX
#define MUTEX
#include "NoneCopyable.h"
#include <pthread.h>
class MutexLock
:public NoneCopyable
{
    public:
    MutexLock() { pthread_mutex_init(&_mutex,NULL);}
    ~MutexLock() { pthread_mutex_destroy(&_mutex);}
    void lock() { pthread_mutex_lock(&_mutex);}
    void unlock() { pthread_mutex_unlock(&_mutex);}
    pthread_mutex_t * getMutexPtr() { return &_mutex;}
    private:
    pthread_mutex_t _mutex;
};

class MutexGuard
{
    public:
    MutexGuard(MutexLock & m)
    :mutex(m)
    {
        mutex.lock();
    }
    ~MutexGuard()
    {
        mutex.unlock();
    }
    private:
    MutexLock & mutex;
};
#endif