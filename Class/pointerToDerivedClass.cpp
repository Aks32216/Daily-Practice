#include <bits/stdc++.h>
using namespace std;

class A{
public:
	int a;
	void showA(){
		cout<<a<<"\n";
	}
	void common(){
		cout<<"Common in base\n";
	}
};

class B:public A{
public:
	int b;
	void showB(){
		cout<<b<<"\n";
	}
	void common(){
		cout<<"common in derived\n";
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// base to base pointer -> allowed by C++
	/*

	A* bptr;
	A a;
	bptr=&a;
	bptr->a=100;
	bptr->showA();
	
	*/

	// derived to derived pointer -> allowed by C++
	
	/*
	
	B* dptr;
	B b;
	dptr=&b;
	dptr->a=100;
	dptr->b=200;
	dptr->showA();
	dptr->showB();
	
	*/

	// base to derived pointer -> allowed by C++

	/*	
	
	A* bptr;
	B b;
	bptr=&b;
	bptr->a=300;
	// bptr->b=400; would result error as seeing from base we wont be able to see
						// derived variables or functions and hence we cannot acess it
	bptr->showA(); 		
	// bptr->showB(); same reason
	bptr->common();
	// but if we want to acess it then we need to type convert it
	((B *)bptr)->common();
	((B *)bptr)->b=400;
	((B *)bptr)->showB();

	*/


	// derived to base pointer -> not allowed by compiler
	// would always show error

	/*
	
	B* dptr;
	A a;
	dptr=&a;
	dptr->a=500;
	dptr->b=600;
	dptr->showA();
	dptr->showB();
	dptr->common();

	*/
}