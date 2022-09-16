// mutex referes to mutual exclusion

// co-operative process sharing critical section (common data) must executed this section
// in a mutual exclusion manner so that ambiguity does no arise
// otherwise if threads are not synchronised then race condition may happen

// race condition is a situation in which two or more threads are acessing crititcal 
// section data at same time and they are changing the variable which can result into a worng result

// mutex is a method adopted to prevent race condition
// so to prevent race condition every thread must execute a entry section code
// and a exit section code
// while a thread is inside and executing a critical section code
// other threads must not be allowed to execute the critical section

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

int money=0;
mutex m;

void addMoney()
{
    m.lock(); // prevents other to execute critical section till unlock() method is not called
    ++money;
    m.unlock();
}

int main()
{
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();
    cout<<money<<"\n";
}