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

int factors(int n)
{
	int count=1;
	while(n%2==0)
		n/=2,count++;
	for(int i=3;i*i<=n;++i)
	{
		if(n%i==0)
		{
			int ans=1;
			while(n%i==0)
				n/=i,ans++;
			count*=ans;
		}
	}
	if(n>2)
		count*=2;
	return count;
}

int kthFactor(int n, int k) 
{
	int no_of_factors=factors(n);
	vector<int> v(no_of_factors);
	if(k>no_of_factors)
		return -1;
	if(k==no_of_factors)
		return n;
	v[0]=1;
	v[no_of_factors-1]=n;
	int i=1,j=no_of_factors-2;
	for(int k=2;k*k<=n;++k)
	{
		if(n%k==0)
		{
			if(k!=n/k)
				v[i]=k,v[j]=n/k,i++,j--;
			else
				v[i]=k,i++,j++;
		}
	}

	return v[k-1];
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,k;
 	cin>>n>>k;
 	cout<<kthFactor(n,k)<<"\n";
}