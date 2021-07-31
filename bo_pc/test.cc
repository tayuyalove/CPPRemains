#include "thread.h"
#include "taskqueue.h"
#include <functional>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


void produce (TaskQueue &tq)
{
    srand(100);
    int t = rand();
    tq.push(t);
    return;
}

void consume (TaskQueue &tq)
{
    int t = tq.pop();
    cout<<t<<endl;
    return ;
}

int main()
{
    TaskQueue tq(10);

    Thread tp (bind(produce,ref(tq)));
    Thread tc (bind(consume,ref(tq)));
    tp.start();
    tc.start();
    tp.join();
    tc.join();
    return 0;

}