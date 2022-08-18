#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
	int accNo;
	int balance;
	static double rate;
public:

	void showInterestRate()
	{
		cout<<"Your Interest Rate is : "<<rate<<"\n";
	}

	void initializeInterestRate()
	{
		cout<<"Enter the value of new Interset Rate : \n";
		double newRate;
		cin>>newRate;
		rate=newRate;
	}

	void showBalance(){
		cout<<"Your Current Balance is : "<<balance<<"\n";
	}
	void calclateInterest()
	{
		double interest=(balance*rate*2)/100;
		cout<<"Your Interest is : "<<interest<<"\n";
	}

};

double Bank::rate=0;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Bank b1;
	b1.showBalance();
	b1.calclateInterest();
	b1.initializeInterestRate();
	b1.showInterestRate();
}