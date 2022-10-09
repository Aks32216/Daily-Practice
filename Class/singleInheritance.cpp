#include <bits/stdc++.h>
using namespace std;

class B{
private:
	int a;
public:
	int b;
	void putB()
	{
		a=5,b=10;
	}
	int getA()
	{
		return a;
	}
	void showA()
	{
		cout<<"a = "<<a<<"\n";
	}
};

// since publicaly inherited all public members become public members of the class C
// thus in public section of C
// display(), putB(), getA(), showA(),mul() are present
// a is not present but can be accesed using getA() and showA()
// c and b are present as data members

class C:public B{
private:
	int c;
public:
	void display()
	{
		cout<<b<<" "<<c<<" "<<getA()<<"\n";
	}
	void mul()
	{
		putB();
		c=b*getA();
	}
};

class D:private B{
private:
	int c;
public:
	void display(){
		cout<<b<<" "<<c<<" "<<getA()<<"\n";
	}
	void mul(){
		putB();
		c=b*getA();
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	C test;
	test.display();
	test.putB();
	cout<<test.getA()<<"\n";
	test.showA();
	test.mul();
	test.display();
	cout<<"--------------------------------------------------\n";
	D test2;
	test.display();
	test.mul();
}