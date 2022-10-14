#include <bits/stdc++.h>
using namespace std;

class vec{
private:
	int a,b,c,d;
public:
	vec(){
		a=0;
		b=0;
		c=0;
		d=0;
	}
	vec(int a,int b,int c,int d)
	{
		this->a=a;
		this->b=b;
		this->c=c;
		this->d=d;
	}
	void getData(int a,int b,int c,int d)
	{
		this->a=a;
		this->b=b;
		this->c=c;
		this->d=d;
	}
	void display(){
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}

	/*vec operator +(vec v1){
		return (vec(a+v1.a,b+v1.b,c+v1.c,d+v1.d));
	}

	vec operator -(vec v1){
		return (vec(a-v1.a,b-v1.b,c-v1.c,d-v1.d));
	}

	vec operator *(vec v1){
		return (vec(a*v1.a,b*v1.b,c*v1.c,d*v1.d));	
	}

	vec operator /(vec v1){
		return (vec(a/v1.a,b/v1.b,c/v1.c,d/v1.d));
	}*/

	friend vec operator +(vec,vec);
	friend vec operator -(vec,vec);
	friend vec operator *(vec,vec);
	friend vec operator /(vec,vec);
};

vec operator +(vec v1,vec v2){
	return (vec(v2.a+v1.a,v2.b+v1.b,v2.c+v1.c,v2.d+v1.d));
}

vec operator -(vec v1,vec v2){
	return (vec(v2.a-v1.a,v2.b-v1.b,v2.c-v1.c,v2.d-v1.d));
}

vec operator *(vec v1,vec v2){
	return (vec(v2.a*v1.a,v2.b*v1.b,v2.c*v1.c,v2.d*v1.d));	
}

vec operator /(vec v1,vec v2){
	return (vec(v2.a/v1.a,v2.b/v1.b,v2.c/v1.c,v2.d/v1.d));
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vec v1(1,2,4,5);
	vec v2(6,7,8,9);
	vec v3=v1+v2;
	vec v4=v1-v2;
	vec v5=v2-v1;
	vec v6=v1*v2;
	vec v7=v1/v2;
	v1.display();
	v2.display();
	v3.display();
	v4.display();
	v5.display();
	v6.display();
	v7.display();

}