// use of join(), detach() and joinable()

// join()
// once thread is started and thus join waits for thread to finish
// dobule join will cause program to terminate

// detach()
// separates newly created thread from main thread
// hence main thread wont wait for thread to finish to terminate itself
// must check both of these function so to avoid double calling of these function
// if main returned and thread has not completed then thread is suspended as no orphan process are allowed


#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void fun(int n)
{
    while(n--)
    {
        cout<<"hello wordl\n";
    }
    this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
    // this thread completes after 5 second
    thread t1(fun,10);
    cout<<"before"<<"\n";
    // so after running main content till here main will wait for fun thread to get complete
    // after completed thread is joined with main and hence further execution starts
    // t1.join();
    // t1.join(); two times join will make erroneous program as no thread name t1 is running and hence no waiting for it
    // thus before calling join function we must check whether a thread is joinable or not
    // this can be done with joinable() function
    // it returns true if thread is joinable else returns false
    // if(t1.joinable())
    //     t1.join();

    // separates main thread and t1 thread and thus both are independent in their execution
    // now if main terminates then thread will be suspended
    t1.detach();
    this_thread::sleep_for(chrono::seconds(5));
    cout<<"after"<<"\n";
}