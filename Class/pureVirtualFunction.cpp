#include <bits/stdc++.h>
using namespace std;


class A{
public:
	A(){
		cout<<"A constructor\n";
	}
	virtual void show(){};
	virtual ~A(){
		cout<<"A destructor\n";
	}
};

class B:public A{
public:
	B(){
		cout<<"B constructor\n";
	}

	void show(){
		cout<<"B show\n";
	}
	~B(){
		cout<<"B destructor\n";
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	A* bptr=new B();
	// bptr=&b;
	bptr->show();
	delete bptr;
}