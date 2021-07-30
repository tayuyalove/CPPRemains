#ifndef COND
#define COND
#include <pthread.h>
#include "MutexLock.h"
#include "NoneCopyable.h"

class Condition
:public NoneCopyable{
    public:
    Condition(MutexLock & m):_mutex(m)
    {
        pthread_cond_init(&_cond,NULL);
    }
    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }
    void wait()
    {
        pthread_cond_wait(&_cond,_mutex.getMutexPtr());
    }
    void notify()
    {
        pthread_cond_signal(&_cond);
    }
    void notifyAll()
    {
        pthread_cond_broadcast(&_cond);
    }
    private:
    pthread_cond_t _cond;
    MutexLock & _mutex;
};
#endif