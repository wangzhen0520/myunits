#include <iostream>
#include <memory>
#include <vector>
#include <unistd.h>

#include "Mutex.h"
#include "Thread.h"

using namespace std;

void threadFunc()
{
    printf("tid=%d\n", Base::CurrentThread::tid());
}

void threadFunc2(int x)
{
    printf("tid=%d, x=%d\n", Base::CurrentThread::tid(), x);
}

void threadFunc3()
{
    printf("tid=%d\n", Base::CurrentThread::tid());
    sleep(1);
}

int main()
{
    Base::MutexLock mutex;

    mutex.lock();
    cout << "mutex" << endl;
    mutex.unlock();

    printf("pid=%d, tid=%d\n", ::getpid(), Base::CurrentThread::tid());

    Base::Thread t1(threadFunc);
    t1.start();
    cout << t1.name() << endl;
    t1.join();

    Base::Thread t2(std::bind(threadFunc2, 42),
                     "thread for free function with argument");
    t2.start();
    cout << t2.name() << endl;
    t2.join();

    getchar();
    return 0;
}