// deadlock is a situation in which two or more processes are waiting for certain event to occur and that event never occurs
// eg : p1 has resource r1 and wants r2 to complete execution
// p2 has resource r2 and wants r1 to complete execution
// both are waiting for each others acquired resource and hence are in a deadlock situation

// necessary conditon for a deadlock
// 1. mutual exclusion
// 2. no preumption
// 3. hold and wait
// 4. circular wait

// there are several methods adopted to handle the deadlock situation
// 1. deadlock ignorance (ostrich method) - ignore the deadlock condition
// 2. deadlock prevention - try to prevent all necessary condition for deadlock
// 3. deadlock avoidance (bankers algorithm) - before allocating any resource to a certain process check if it can result into a deadlock
// for this method resources for each process must be known in advance
// 4. deadlock prevention and recovery - if deadlock occurs then do the following
/// i. preupmpt the process
// ii. kill the process
// iii. rollback all the resources

// deadlock happens once in a million time in a system thus having a system for checking deadlock inbuilt effects efficiency of system.
// thus ostrich method is the best and most practical method

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1,m2;

void thread1()
{
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout<<"Execute critical section\n";
    m2.unlock();
    m1.unlock();
}

void thread2()
{
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout<<"Execute critical section\n";
    m1.unlock();
    m2.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
}