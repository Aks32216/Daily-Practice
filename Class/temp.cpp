#include <bits/stdc++.h>
using namespace std;

class A{
public:
	virtual void show(){
		cout<<"base\n";
	}
};

class B:public A{
public:
	void show(){
		cout<<"Derived\n";
	}
};

class C:public A{
public:
	void display(){
		cout<<"C derived\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	A a;
	a.show();
	B b;
	b.show();

	A* bptr;
	C c;
	bptr=&c;
	bptr->show();
}