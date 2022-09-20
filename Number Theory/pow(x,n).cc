#include <bits/stdc++.h>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int
#define mod 1e9+7
 
/*
double myPow(double x, int n) {
    double res=1;
    bool isNeg=n<0?true:false;
    n=abs(n);
    for(long long i=1;i<=n;++i)
    {
        res=res*x;
    }
    if(isNeg)
        return 1/res;
    return res;
}
*/

/*
double solve(double x,int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    double res=solve(x,n/2);
    if(n%2==0)
        return res*res;
    else
        return res*res*x;
}

double myPow(double x,int n)
{
    bool isNeg=n<0?true:false;
    n=abs(n);
    double res=solve(x,n);
    if(isNeg)
        return 1/res;
    else
        return res;
}
*/
    
double myPow(double x, int n) {
	double res=1.0;
	long m=n;
	if(m<0)
		m=-1*m;
	while(m)
	{
		if(m&1)
		{
			res=res*x;
			m--;
		}
		else
		{
			x=x*x;
			m>>=1;
		}
	}
	if(n<0)
		return (double)(1.0)/res;
	else
		return res;
}


int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	double x;
 	cin>>x;
 	int n;
 	cin>>n;
 	cout<<myPow(x,n)<<"\n";    
}