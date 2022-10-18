#include <bits/stdc++.h>
using namespace std;


class A{
public:
	A(){
		cout<<"Constructor A\n";
	}
	virtual void show(){
		cout<<"Base\n";
	}
	virtual ~A(){
		cout<<"Destructor A\n";
	}
};

class B:public A{
public:
	B(){
		cout<<"Constructor B\n";
	}
	void show(){
		cout<<"Derived\n";
	}
	~B(){
		cout<<"Destructor B\n";
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	A* a=new B();
	delete a;
}