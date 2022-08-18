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
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       ll t;
       cin>>t;
       while(t--)
       {
       		ll n,m;
       		cin>>n>>m;
       		vector<vector<char> > v(n,vector<char>(m));
       		for(int i=0;i<n;++i)
       		{
       			for(int j=0;j<m;++j)
       				cin>>v[i][j];
       		}
       		ll x,y;
       		bool isFound=false;
       		for(int i=0;i<n;++i)
       		{
       			for(int j=0;j<m;++j)
       			{
       				if(v[i][j]=='R')
       				{
       					x=i,y=j;
       					isFound=true;
       					break;
       				}
       			}
       			if(isFound)
       				break;
       		}
       		ll x1,x2;
       		isFound=false;
       		for(int i=0;i<m;++i)
       		{
       			for(int j=0;j<n;++j)
       			{
       				if(v[j][i]=='R')
       				{
       					x1=j;
       					x2=i;
       					isFound=true;
       					break;
       				}
       			}
       			if(isFound)
       				break;

       		}
       		if(x1==x && x2==y)
       			cout<<"YES\n";
       		else
       			cout<<"NO\n";
       }
}