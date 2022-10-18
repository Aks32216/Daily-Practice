#include <bits/stdc++.h>
using namespace std;

class Complex{
	int real;
	int imaginary;
public:
	Complex(){
		real=0;
		imaginary=0;
	}

	Complex(int real,int imaginary){
		this->real=real;
		this->imaginary=imaginary;
	}

	void getData(int real,int imaginary){
		this->real=real;
		this->imaginary=imaginary;
	}
	void putData(){
		cout<<real<<" "<<imaginary<<"\n";
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Complex* c1=new Complex(5,6);
	c1->putData();
	Complex* c2=new Complex();
	c2->getData(1,2);
	c2->putData();
}