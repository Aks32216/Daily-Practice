#include <bits/stdc++.h>
using namespace std;


// shallow copy

class rectangle
{
private:
	int length;
	int breadth;
public:
	rectangle()
	{
		length=0;
		breadth=0;
	}

	rectangle(int length,int breadth)
	{
		this->length=length;
		this->breadth=breadth;
	}

	rectangle(rectangle& r)
	{
		length=r.length;
		breadth=r.breadth;
	}

	void display()
	{
		cout<<length<<" "<<breadth<<"\n";
	}
};

// deep copy

class trapezium{
private:
	int firstSide;
	int secondSide;
	int* parallelSide;
public:
	trapezium(){
		firstSide=0;
		parallelSide=new int(0);
		secondSide=0;
	}

	trapezium(int firstSide,int secondSide,int parallelSide)
	{
		this->firstSide=firstSide;
		this->secondSide=secondSide;
		*this->parallelSide=parallelSide;
	}

	trapezium(trapezium& t)
	{
		firstSide=t.firstSide;
		secondSide=t.secondSide;
		parallelSide=new int;
		*parallelSide=*(t.parallelSide);
	}

	void display()
	{
		cout<<firstSide<<" "<<secondSide<<" "<<*parallelSide<<"\n";
	}

};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// rectangle r1;
	// rectangle r2(10,15);
	// r1.display();
	// r2.display();
	trapezium t1;
	trapezium t2(5,6,7);
	trapezium t3(t1);
	trapezium t4=t2;
	trapezium t5;
	t5=t2;
	t1.display();
	t2.display();
	t3.display();
	t4.display();
	t5.display();
}