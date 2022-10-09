#include <bits/stdc++.h>
using namespace std;

// by default data members are public in default
// c does not allow acess modifier but c++ has acess modifiers thus providing
// featrues of data hiding  and inheritance

struct student{
private: // acess specifier allowed in c++ but not in c
	string name;
	int st=134;
public:
	int rollNo=34;
	int phNo;
	static int studentCount; // static data members allowd in c++ but not in c

	// student() // constructors are not allowed in c but allowed in c++
	// {
	// 	studentCount++; 
	// 	rollNo=-1;
	// 	phNo=-1;
	// 	name="";
	// }

	// student(int rollNo,int phNo,string name)
	// {
	// 	studentCount++;
	// 	this->rollNo=rollNo;
	// 	this->phNo=phNo;
	// 	this->name=name;
	// }

	void display() // member function are not allowed in c but allowed in c++
	{
		cout<<name<<" "<<rollNo<<" "<<phNo<<" "<<studentCount<<"\n";
	}
};


int student::studentCount=0;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	student s1; // in c struct keyword is necessary before variable to be decalred but in c++ not necessary
	student s2;
	s1.display();
	s2.display();
	cout<<student::studentCount<<"\n";
	cout<<sizeof(s1)<<"\n";
	// cout<<sizeof(temp)<<"\n";
}