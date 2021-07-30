#include "consumer.h"
#include "producer.h"
#include <unistd.h>

int main()
{
    TaskQueue tq(10);
//虚函数：
/*     Thread * c = new Consumer (tq);
    Thread * p = new Producer (tq);
    c->start();
    p->start();
    sleep(100);
    c->join();
    p->join(); */
//普通多态
    Consumer c (tq);
    Producer p (tq);
    c.start();
    p.start();
    sleep(10);
    c.join();
    p.join();
    return 0;
}