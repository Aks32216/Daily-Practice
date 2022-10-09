#include <bits/stdc++.h>
using namespace std;

class Complex{
private:
	int real;
	int imaginary;
public:
	Complex(){} // do noting constructor
	Complex(int real,int imaginary){
		this->real=real;
		this->imaginary=imaginary;
	}

	void display(){
		cout<<real<<"+"<<imaginary<<"i\n";
	}

	friend Complex sum(Complex,Complex);
};

Complex sum(Complex c1,Complex c2)
{
	Complex c3;
	c3.real=c1.real+c2.real;
	c3.imaginary=c1.imaginary+c2.imaginary;
	return c3;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Complex c1(4,5),c2(5,6);
	Complex c3; // error if no default constructor is provided as this time compiler wont give its version of default constructor
	c3=sum(c1,c2);
	c3.display();
}