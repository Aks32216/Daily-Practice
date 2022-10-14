#include <bits/stdc++.h>
using namespace std;

class Complex{
private:
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
	friend Complex operator +(Complex,Complex);
	friend Complex operator -(Complex,Complex);
	friend istream & operator >>(istream &,Complex&);
	friend ostream & operator <<(ostream &,Complex&);
};

Complex operator +(Complex c1,Complex c2){
	return (Complex(c1.real+c2.real,c1.imaginary+c2.imaginary));
}

Complex operator -(Complex c1,Complex c2){
	return (Complex(c1.real-c2.real,c1.imaginary-c2.imaginary));
}

istream & operator >>(istream &in,Complex& c1){
	in>>c1.real>>c1.imaginary;
	return (in);
}

ostream & operator <<(ostream &out,Complex& c1){
	out<<c1.real<<" + "<<c1.imaginary<<"i\n";
	return out;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Complex c1;
	Complex c2;
	Complex c3=c1+c2;
	Complex c4;
	cin>>c4;
	cout<<c4;
	cout<<c1<<c2<<c3<<c4;
}