#include <bits/stdc++.h>
using namespace std;

class A{
private:
	int a;
public:
	A(int a){
		this->a=a;
		cout<<"A initialized\n";
	}
	void displayA(){
		cout<<"A - "<<a<<"\n";
	}
};

class B{
private:
	int b;
public:
	B(int b){
		this->b=b;
		cout<<"B initialized\n";
	}
	void displayB(){
		cout<<"B - "<<b<<"\n";
	}
};

class D:public B,public A{
private:
	int m,n;
public:
	D(int a,int b,int m,int n):
	A(a),B(b){
		this->m=m;
		this->n=n;
		cout<<"D initialized\n";
	}
	void display(){
		displayA();
		displayB();
		cout<<"M - "<<m<<"\n";
		cout<<"N - "<<n<<"\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	D d1(1,2,3,4);
	d1.display();
}