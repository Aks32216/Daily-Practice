// timed_mutex is another object under mutex header file
// timed_mutex has all the same function except for two extra function

// timed_mutex supported function
// lock
// unlock
// try_lock
// try_lock_for
// try_lock_untill

// we have seen how lock, unlock and try_lock works

// try_lock_for()
// now as we have seen that try_lock tries to acquire mutex but if not acquired it immediately returns false and carries on with other task
// whereas lock() if not able to acquire the lock blocks the thread
// but try_lock_for() tries to acquire the lock for specified amount of time
// if it is able to acquire lock within that time then it will return true otherwise it will return false

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

timed_mutex mtx;
int count=0;

void increment(int i)
{
    if(mtx.try_lock_for(chrono::seconds(1))) // this thread will wait for 1 second till it acquires lock otherwise it will return false
    {
        count++;
        this_thread::sleep_for(chrono::seconds(2)); // since this critical section takes up 2 sec to complete and other thread will wait only for 1 sec thus only 1
        // thread will be able to execute the critical section
        cout<<"thread :"<<i<<"Entered\n";
        mtx.unlock();
    }
    else
    {
        cout<<"Thread : "<<i<<"could not entered\n";
    }
}

int main()
{
    thread t1(increment,1);
    thread t2(increment,2);

    t1.join();
    t2.join();

    cout<<count<<"\n";
}