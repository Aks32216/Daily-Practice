// Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition

// it will sleep when wait condition returns false and when notify function is called it will wake up and again check for conditon
// it is defined under condition variable header file

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

condition_variable cv;
mutex mtx;
int balance=0;

// lock guard acquires lock till the scope only and release lock automatically through its destructor

void addMoney(int money)
{
    lock_guard<mutex> lg(mtx); // lock guard wraps around lock and has scope locking
    balance+=money;
    cout<<"Balance Added to account. Current Balance is : "<<balance<<"\n";
    cv.notify_one(); // notifies other threads waiting for acquiring lock based on certain condition
}

void withdrawMoney(int money)
{
    unique_lock<mutex> ul(mtx); // wait only accepts unique lock
    cv.wait(ul,[](){return balance!=0?true:false;}); // this conditon first acquire lock and checks for condition
    // if condition evaluates to true then continue forward 
    // if conditon evaluates to false then it release the lock and goes to sleep and waits for notification
    if(balance>=money){
        balance-=money;
        cout<<"Money withdrawn from account\n";
    }
    else{
        cout<<"Money could not be withdrawn. Please put more money into your account.\n";
    }
    cout<<"Current Balance is : "<<balance<<"\n";
}

int main()
{
    thread t2(withdrawMoney,500);
    thread t1(addMoney,500);
    // even if withdraw money function is called first it is not executed first as condition variable does not allow it to run
    // thus condition variable allows to run a thread only when a certain conditon is met
    t1.join();
    t2.join();
}