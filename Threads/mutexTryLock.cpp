// mutex has try_lock() function which is inbuilt
// try_lock() tries to acquire the lock, but if lock is not acquired then false is returned
// but try_lock() does not block the thread but instead allows them to try again to lock


#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

int count=0;
mutex mtx;

void incrementThousandTimes()
{
    for(int i=1;i<=1000;++i)
    {
        if(mtx.try_lock()) // tries to unlock if sucessful lock is acquired otherwise false is returned and that thread needs to try agian
        {
            count++;
            mtx.unlock(); // once unlocked others can acquire the lock
        }
    }
}

int main()
{
    thread t1(incrementThousandTimes);
    thread t2(incrementThousandTimes);

    t1.join();
    t2.join();

    cout<<count<<"\n"; // output wont be 2000 because suppose t1 has acquired the lock and at the same time t2 tries to acquire the lock
    // then false is returned and loop counter is increased.
    // then suppose t1 is still trying to increment the counter and t2 again tries but again t2 tries to acquire lock but it will fail as t1 still has lock
    // thus counter again increment by 1
    // now this time t1 has finished and unlocked and then t2 tries to acquire the lock, and it will gain the lock
    // so if we analyze the situation then t2 loop has increased 3 times but it was successful increasing count only once
    // and such situation will happen innumerous no of times thus we wont be geting 2000 as output
    // thus in order to get 2000 as output we can try mutex lock() which we have seen previous
}