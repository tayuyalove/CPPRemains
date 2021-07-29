#include "thread.h"
#include "ctime"
#include<iostream>

void Task()
{
    srand(time(NULL));
    cout<<rand()<<endl;
}

int main()
{
    for(int i = 0;i<10;++i)
    {
        Thread t (bind(&Task));
        t.start();
        t.join();
    }
    return 0;
}