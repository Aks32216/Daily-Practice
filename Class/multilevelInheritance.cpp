#include <bits/stdc++.h>
using namespace std;

class Student{
protected:
	int rollNo;
public:
	Student(){
		cout<<"Constructor of Student\n";
	}
	void getRollNo()
	{
		cout<<"Roll No = "<<rollNo<<"\n";
	}
	void putRollNo(int rn)
	{
		rollNo=rn;
	}
	~Student(){
		cout<<"Destructor of Student\n";
	}
};

class Marks:public Student{
protected:
	int sub1;
	int sub2;
public:
	Marks(){
		cout<<"Constructor of Marks\n";
	}
	void getMarks()
	{
		cout<<"Sub 1 = "<<sub1<<"\n";
		cout<<"Sub 2 = "<<sub2<<"\n";
	}

	void putMarks(int sb1,int sb2){
		sub1=sb1;
		sub2=sb2;
	}
	~Marks(){
		cout<<"Destructor of Marks\n";
	}
};

class Result:public Marks{
private:
	int total;
public:
	Result(){
		cout<<"Constructor of Result\n";
	}
	void displayResult(){
		total=sub1+sub2;
		getRollNo();
		getMarks();
		cout<<"Total Obtained = "<<total<<"\n";
	}
	~Result(){
		cout<<"Destructor of Result\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Result r1;
	r1.putRollNo(1);
	r1.putMarks(96,75);
	r1.displayResult();
}