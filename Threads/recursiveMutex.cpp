// Recursive Mutex In C++ (std::recursive_mutex)
 
// NOTES:
// 0. It is same as mutex but, Same thread can lock one mutex multiple times using recursive_mutex.
// 1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now 
//    as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
// 2. But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock
//    it 10 times otherwise no other thread will be able to lock mutex m1.
//    It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
// 3. How many time we can lock recursive_mutex is not defined but when that number reaches and if we were calling
//    lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

// BOTTOM LINE:
// 0. It is similar to mutex but have extra facility that it can be locked multiple time by same thread.
// 1. If we can avoid recursive_mutex then we should because it brings overhead to the system.
// 2. It can be used in loops also.

// only difference between lock and recursive_lock is that the ohter thread wont be blocked when trying to acquire mutex
// instead it will wait there till it gains mutex

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int count=0;
recursive_mutex mtx;

void printTill10(int id,int n)
{
    if(n<0)
        return;
    mtx.lock();
    count++;
    cout<<"Locked by : "<<id<<" Buffer : "<<count<<"\n";
    printTill10(id,n-1);
    mtx.unlock();
    cout<<"Unlocked by : "<<id<<"\n";
}

int main()
{
    thread t1(printTill10,1,10);
    thread t2(printTill10,2,10);
    t1.join();
    t2.join();

    cout<<count<<"\n";
}