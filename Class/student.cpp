#include <iostream>
using namespace std;

class student
{
private:
	string name;
	int rollNo;
	int score;
public:
	student(int rollNo=0,string name="",int score=0)
	{
		this->rollNo=rollNo;
		this->name=name;
		this->score=score;
	}
	void getAttributes(string name,int rollNo,int score)
	{
		this->name=name;
		this->rollNo=rollNo;
		this->score=score;
	}
	void displayAttributes()
	{
		cout<<"Name : "<<name<<"\n";
		cout<<"Roll No. : "<<rollNo<<"\n";
		cout<<"Score : "<<score<<"\n";
	}
	void copyDetails(student& toStudent)
	{
		toStudent.name=name;
		toStudent.rollNo=rollNo;
		toStudent.score=score;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// student s1,s2;
	// s1.getAttributes("Amish",1,67);
	// s2.getAttributes("Ashish",2,87);
	// s1.displayAttributes();
	// s2.displayAttributes();
	// student s3;
	// s2.copyDetails(s3);
	// s3.displayAttributes();

	student s4,s5(5),s6(6,"anshuman"),s7(7,"aniket",89);
	s4.displayAttributes();
	s5.displayAttributes();
	s6.displayAttributes();
	s7.displayAttributes();

}