#include <bits/stdc++.h>
using namespace std;

class Queue{
	int *arr;
	int start,end,curSize,maxSize;
public:
	Queue()
	{
		this->maxSize=100;
		start=-1;
		end=-1;
		arr=new int[this->maxSize];
		curSize=0;
	}

	Queue(int size)
	{
		this->maxSize=size;
		start=-1;
		end=-1;
		arr=new int[size];
		curSize=0;
	}

	void Push(int element)
	{
		if(curSize==maxSize)
		{
			cout<<"Cannot push Element to queue: Queue Full\n";
			exit(1);
		}
		if(end==-1)
		{
			start=0;
			end=0;
		}
		else
		{
			end=(end+1)%maxSize;
		}
		arr[end]=element;
		curSize++;
	}

	int front()
	{
		if(start==-1)
		{
			cout<<"Queue Empty\n";
			exit(1);
		}
		int element=arr[start];
		if(curSize==1)
		{
			start=-1;
			end=-1;
		}
		else
			start=(start+1)%maxSize;
		curSize--;
		return element;
	}

	int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return curSize;
  }

};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

		Queue q(1000);

		q.Push(5);
		q.Push(56);
		cout<<q.top()<<" ";
		cout<<q.front()<<" ";
		cout<<q.front()<<" ";
		cout<<q.front()<<"\n";

}