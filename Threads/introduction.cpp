// Threads
// for every program there is a default thread which is usually called main
// all program start from there and using main thread we can create threads
// these threads perform separate independent tasks and improves multiprogramming
// thread is a lightweight process and helps to achieve parallelism
// threads must be created within main and must be finished before main finishes
// Eg -
// 1. browser having multiple tabs with each tab performing separate task
// 2. MS word has multiple functionalities each operating independently

// Ways to create Threads
// 1. Function Pointers
// 2. Lambda Function
// 3. Functors
// 4. Member Functions
// 5. Static Member Function

// find the sum of odd number from 1 to 10^10 and even no from 1 to 10^10

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
#define ull unsigned long long

void findOddSum(ull start,ull end,ull& sum)
{
    for(int i=start;i<=end;++i)
    {
        if(i%2==1)
            sum+=i;
    }
}

void findEvenSum(ull start,ull end,ull& sum)
{
    for(int i=start;i<=end;++i)
    {
        if(i%2==0)
            sum+=i;
    }
}

int main(){
    // doing the same operation with function
    ull start=1,end=1e9;
    ull odd=0,even=0;
    /*
    auto startTime=high_resolution_clock::now();
    findOddSum(start,end,odd);
    findEvenSum(start,end,even);
    auto stopTime=high_resolution_clock::now();
    auto duration =duration_cast<microseconds>(stopTime-startTime);
    cout<<odd<<"\n";
    cout<<even<<"\n";
    cout<<"time Taken : "<<duration.count()/1000000<<"\n";
    */
    // so to perfom these task it took around 7 sec.
    // but these two tasks are independent of each other
    // and hence can be converted to threads

    // way to create thread
    // thread(function pinter,parameter of function)
    // t1.join() waits for the thread to finsh otherwise main would finish without using the 
    // result of thread and hence can result into unwanted outputs

    auto startTime=high_resolution_clock::now();
    thread t1(findOddSum,start,end,ref(odd)); // calling the thread
    thread t2(findEvenSum,start,end,ref(even));
    t1.join();
    t2.join();
    auto stopTime=high_resolution_clock::now();
    auto duration =duration_cast<microseconds>(stopTime-startTime);
    cout<<odd<<"\n";
    cout<<even<<"\n";
    cout<<"time Taken : "<<duration.count()/1000000<<"\n";


}