#include <bits/stdc++.h>
using namespace std;


class M{
protected:
	int m;
public:
	M(){
		cout<<"Constructor of M\n";
	}
	void getM(int m)
	{
		this->m=m;
	}
	void putM(){
		cout<<"M - "<<m<<"\n";
	}
	~M(){
		cout<<"Destructor of M\n";
	}
};

class N{
protected:
	int n;
public:
	N(){
		cout<<"Constructor of N\n";
	}
	void getN(int n)
	{
		this->n=n;
	}
	void putN(){
		cout<<"N - "<<n<<"\n";
	}
	~N(){
		cout<<"Destructor of N\n";
	}
};

class D:public N,public M{
public:
	D(){
		cout<<"Constructor of D\n";
	}
	void display(){
		putM();
		putN();
	}
	~D(){
		cout<<"Destructor of D\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	D d1;
	d1.getM(55);
	d1.getN(54);
	d1.display();
}