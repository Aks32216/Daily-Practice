#include <bits/stdc++.h>
using namespace std;

class Stack{
	int size;
	int top;
	int* arr;
public:
	Stack(){
		this->size=1000;
		this->top=-1;
		arr=new int[size];
	}

	Stack(int x){
		this->size=x;
		this->top=-1;
		arr=new int[x];
	}

	void Push(int x)
	{
		top++;
		arr[top]=x;
	}

	int Top()
	{
		return arr[top];
	}

	int Pop()
	{
		int x=arr[top];
		top--;
		return x;
	}

	int Size()
	{
		return top+1;
	}

	bool isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif


	int n;
	cin>>n;
	Stack s(n);
	int a;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		s.Push(a);
	}
	cout<<s.Size()<<"\n";
	while(!s.isEmpty())
	{
		cout<<s.Pop()<<" ";
	}
}