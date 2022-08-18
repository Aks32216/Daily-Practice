#include <bits/stdc++.h>
#include <thread>

using namespace std;


void printNumbers(int x)
{
    ofstream outputFile;
    outputFile.open("ascending.txt");
    for(int i=1;i<=x;++i)
    {
        outputFile << i << endl;
    }
    outputFile<<"\n";
    outputFile.close();
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void printPrimes(int x)
{
    ofstream outputFile2;
    outputFile2.open("prime.txt");
    for(int i=2;i<=x;++i)
    {
        if(isPrime(i))
            outputFile2<<i<<" ";
    }
    outputFile2<<"\n";
    outputFile2.close();
}
  
int main()
{
    thread th1(printNumbers,100000);
    thread th2(printPrimes,200000);
    th1.join();
    th2.join();
}