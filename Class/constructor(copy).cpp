#include <bits/stdc++.h>
using namespace std;

class Complex{
private:
	int real,imaginary;
public:
	Complex(){} // default or do nothing constructor

	Complex(int real,int imaginary){
		this->real=real;
		this->imaginary=imaginary;
	}

	Complex(Complex& c)
	{
		real=c.real;
		imaginary=c.imaginary;
	}

	friend Complex sum(Complex,Complex);

	void display()
	{
		cout<<real<<"+"<<imaginary<<"i\n";
	}
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

	Complex c1(4,5);
	Complex c2(c1);
	Complex c3;
	c3=sum(c1,c2);
	c3.display();
}