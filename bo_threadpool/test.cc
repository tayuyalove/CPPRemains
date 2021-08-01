#include "threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using namespace std;


void process()
{
    ::srand(100);
    //::srand(::clock());
    int number = ::rand() % 100;
    ::sleep(2);
    //::usleep(100);
    cout << ">>> subThread: "<< pthread_self() << ". produce a number : " << number << endl;
	
}

int main()
{
    ThreadPool tp(4,10);
    tp.start();
    int i =10;
    while(i>0)
    {
        tp.addTask(bind(process));
        --i;
    }
    tp.stop();
    return 0;
}           