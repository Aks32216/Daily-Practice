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
       		ll n;
       		cin>>n;
       		vl v(n);
       		for(auto& i:v)
       			cin>>i;
       		sort(begin(v),end(v));
       		vl temp(n);
       		ll j=0,k=(n+1)/2;
       		for(int i=0;i<n;i+=2)
       		{
       			temp[i]=v[j];
       			if(i+1<n)
       				temp[i+1]=v[k];
       			k++;
       			j++;
       		}
       		bool isPossible=true;
       		for(int i=0;i<n;++i)
       		{
       			int next=(i+1)%n;
       			int prev=(i-1+n)%n;
       			if(i%2==0)
       			{
       				if(temp[i]<temp[prev] && temp[i]<temp[next])
       					continue;
       				else
       				{
       					isPossible=false;
       					break;
       				}
       			}
       			else
       			{
       				if(temp[i]>temp[prev] && temp[i]>temp[next])
       					continue;
       				else
       				{
       					isPossible=false;
       					break;
       				}
       			}
       		}
       		if(isPossible)
       		{
       			cout<<"Yes\n";
       			for(auto i:temp)
       				cout<<i<<" ";
       			cout<<"\n";
       		}
       		else
       			cout<<"No\n";
       }
}