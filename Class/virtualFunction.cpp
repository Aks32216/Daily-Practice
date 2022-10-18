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
		cout<<"Derived 1\n";
	}
};

class C:public A{
public:
	void show(){
		cout<<"Derived 2\n";
	}
};

class D:public A{
public:
	void show(){
		cout<<"Derived 3\n";
	}
};

class E:public A{
public:
	void show(){
		cout<<"Derived 4\n";
	}
};

int main(){

	A* bptr;

	int input;
	do{
		cin>>input;

		switch(input){
			case 1:	{B b;
					bptr=&b;
					bptr->show();
					break;}
			case 2: {C c;
					bptr=&c;
					bptr->show();
					break;}
			case 3:
			 		{D d;
			 		bptr=&d;
			 		bptr->show();
			 		break;}
			 case 4:
			 		{E e;
			 		bptr=&e;
			 		bptr->show();
			 		break;}
			 case 5:
			 		{break;}
		}
	}while(input!=5);
}