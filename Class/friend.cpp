#include <bits/stdc++.h>
using namespace std;

class timeUniv1;

class timeUniv2{
	int time;
public:
	void setTime(int time)
	{
		this->time=time;
	}

	friend int getMaxTime(timeUniv1,timeUniv2);
};

class timeUniv1{
	int time;
public:
	void setTime(int time)
	{
		this->time=time;
	}
	friend int getMaxTime(timeUniv1,timeUniv2);
};

int getMaxTime(timeUniv1 t1,timeUniv2 t2)
{
	return max(t1.time,t2.time);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	timeUniv1 t1;
	t1.setTime(5);
	timeUniv2 t2;
	t2.setTime(7);
	cout<<getMaxTime(t1,t2);
}