#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
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
 
vector<ll> primes;
vector<bool> isPrime(1000005,true);

void seive()
{
	
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i*i<1000005;++i)
	{
		if(isPrime[i])
		{
			for(int j=2*i;j<1000005;j+=i)
				isPrime[j]=false;
		}
	}
	for(int i=2;i<1000005;++i)
		if(isPrime[i])
			primes.push_back(i);
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA


       seive();
       ll n,m;
       cin>>n>>m;
       vector<vector<ll> > mat(n,vector<ll>(m));
       for(int i=0;i<n;++i)
       {
       		for(int j=0;j<m;++j)
       		{
       			cin>>mat[i][j];
       			if(isPrime[mat[i][j]])
       				mat[i][j]=0;
       			else
       			{
       				int temp=upper_bound(primes.begin(),primes.end(),mat[i][j])-primes.begin();
       				mat[i][j]=primes[temp]-mat[i][j];
       			}
       		}
       }
       ll ans=LLONG_MAX;
       for(int i=0;i<n;++i)
       {
       		ll tempSum=0;
       		for(int j=0;j<m;++j)
       		{
       			tempSum+=mat[i][j];
       		}
       		ans=min(ans,tempSum);
       }
       for(int i=0;i<m;++i)
       {
       		ll tempSum=0;
       		for(int j=0;j<n;++j)
       		{
       			tempSum+=mat[j][i];
       		}
       		ans=min(ans,tempSum);
       }
       cout<<ans<<"\n";
}	