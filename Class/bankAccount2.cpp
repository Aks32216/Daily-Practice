#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
	static int custId;
	int customerId;
	string name;
	int curLoan;
	int phNo;
	static int limit;
public:
	Bank(string name,int phNo)
	{
		custId++;
		this->customerId=custId;
		this->name=name;
		this->phNo=phNo;
		this->curLoan=0;
	}
	void changeAttribute()
	{
		cout<<"Enter Your New Name: \n";
		string newName;
		cin>>newName;
		this->name=newName;
		cout<<"Enter your New Phone No. \n";
		int newPhNo;
		cin>>newPhNo;
		this->phNo=newPhNo;
	}
	void askLoan()
	{
		cout<<"Enter the amount you want as loan : \n";
		int loanAmount;
		cin>>loanAmount;
		if(curLoan+loanAmount<=limit)
		{
			cout<<"Your Loan has been Approved!.\n";
			curLoan+=loanAmount;
		}
	}
	void creditLimit()
	{
		cout<<"Your Credit Limit is : "<<limit<<"\n";
	}
	void getCurLoan()
	{
		cout<<"Your Current loan amount is : "<<curLoan<<"\n";
	}
	void amountLoanSeekable()
	{
		cout<<"You can seek "<<limit-curLoan<<" amount.\n";
	}
	void getName()
	{
		cout<<"Name : "<<name<<"\n";
	}
	void getPhNo()
	{
		cout<<"Your Phone Number is : "<<phNo<<"\n";
	}
	void getDetails()
	{
		getName();
		creditLimit();
		getCurLoan();
		getPhNo();
	}
};

int Bank::limit=50000;
int Bank::custId=1000;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Bank b1("amish",2345);
	b1.getDetails();
	b1.changeAttribute();
}