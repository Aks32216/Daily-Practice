#include <bits/stdc++.h>
using namespace std;

class item{
	int x=91;
	int y;
public:
	// item()
	// {
	// 	x=0;
	// 	y=0;
	// }
	// item(int x,int y)
	// {
	// 	this->x=x;
	// 	this->y=y;
	// }

	void putData(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	void getData()
	{
		// putData(1,2); // member function  can be called without using dot operator
		cout<<x<<" "<<y<<"\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	item i1;
	item i2;
	i1.getData();
	i2.putData(9,10);
	i2.getData();
}