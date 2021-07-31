#include "threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using namespace std;


class MyTask
:public Task{
    public:
    void process()
    {
        srand(100);
        int number = ::rand() % 100;
		::sleep(2);
		//::usleep(100);
		cout << ">>> subThread: "<< pthread_self() << ". produce a number : " << number << endl;
    }
};


int main()
{
    unique_ptr<Task>pTask(new MyTask());
    ThreadPool tp(4,10);
    tp.start();
    int cnt = 20;
	while(cnt--) {
		tp.addTask(pTask.get());
		cout << "MainThread: "<< cnt << endl;
	}
}