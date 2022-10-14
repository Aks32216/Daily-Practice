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

		vec(int a,int b,int c,int d){
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

		/*void operator - (){
			a=-a;
			b=-b;
			c=-c;
			d=-c;
		}*/

		vec operator -(){
			a=-a;
			b=-b;
			c=-c;
			d=-d;
			return (vec(a,b,c,d)); // shorthand notation	
		}

		// friend void operator - (vec&);
};

/*void operator - (vec& v1){
	v1.a=-v1.a * 5;
	v1.b=-v1.b * 4;
	v1.c=-v1.c * 3;
	v1.d=-v1.d * 2;
}*/

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vec v1;
	vec v2(5,6,7,8);
	v1.getData(1,2,3,5);
	v1.display();
	v2.display();
	-v1;
	vec v3;
	v3=-v2;
	v1.display();
	v3.display();
}
