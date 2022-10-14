#include <bits/stdc++.h>
using namespace std;

class Student{
protected:
	int rollNo;
public:
	Student(){
		cout<<"Student constructor\n";
	}
	void getRollNo(int rn)
	{
		rollNo=rn;
	}
	void putRollNo(){
		cout<<"Roll No - "<<rollNo<<"\n";
	}
	~Student(){
		cout<<"Student destructor\n";
	}
};

class Test:virtual public Student{
protected:
	int sub1;
	int sub2;
public:
	Test(){
		cout<<"Test constructor\n";
	}
	void getMarks(int sb1,int sb2){
		sub1=sb1;
		sub2=sb2;
	}
	void putMarks(){
		cout<<"Marks : \n";
		cout<<"Sub1 - "<<sub1<<"\n";
		cout<<"Sub2 - "<<sub2<<"\n";
	}
	~Test(){
		cout<<"Test destructor\n";
	}
};

class Sports:virtual public Student{
protected:
	int score;
public:
	Sports(){
		cout<<"Sports constructor\n";
	}
	void getScore(int sc){
		score=sc;
	}
	void putScore(){
		cout<<"Score - "<<score<<"\n";
	}
	~Sports(){
		cout<<"Sports destructor\n";
	}
};

class Result:public Test,public Sports{
private:
	int total;
public:
	Result(){
		cout<<"Result constructor\n";
	}
	void calculateTotal(){
		total=sub1+sub2;
	}
	void display(){
		calculateTotal();
		putRollNo();
		putMarks();
		putScore();
		cout<<"Total - "<<total<<"\n";
	}
	~Result(){
		cout<<"Result destructor\n";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Result r1;
	r1.getRollNo(41);
	r1.getMarks(95,87);
	r1.getScore(97);
	r1.display();
}