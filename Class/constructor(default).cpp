#include <bits/stdc++.h>
using namespace std;

class Employee{
private:
	string empName;
	int empId;
	int empPhNo;
public:
	Employee(){ // default constructor without any parameter
		empName="Amish";
		empId=1;
		empPhNo=999;
	}

	void display()
	{
		cout<<empName<<" "<<empId<<" "<<empPhNo<<"\n";
	}
};

class Student{
private:
	string stName;
	int rollNo;
public: // if no constructor defined then compiler provides its own version of default constructor
	Student(){}
	void display()
	{
		cout<<stName<<" "<<rollNo<<"\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Employee e1;
	Student s1;
	e1.display();
	s1.display();
}