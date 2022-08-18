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
 
vector<pair<ll,ll> > merge(vector<pair<ll,ll> >& v)
{
	sort(v.begin(),v.end());
	vector<pair<ll,ll> > res;
	res.push_back(v[0]);
	int j=0;
	for(int i=1;i<v.size();++i)
	{
		if(v[i].first<=res[j].second)
		{
			res[j].first=min(res[j].first,v[i].first);
			res[j].second=max(res[j].second,v[i].second);
		}
		else
		{
			res.push_back(v[i]);
			j++;
		}
	}
	return res;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int t;
       cin>>t;
       while(t--)
       {
       	ll n,q;
       	cin>>n>>q;
       	vector<pair<ll,ll> > v(n);
       	for(auto& i:v)
       	{
       			cin>>i.first>>i.second;
       	}
       	vector<pair<ll,ll> > res=merge(v);
       	ll a;
       	while(q--)
       	{
       		cin>>a;
       		for(int i=0;i<res.size();++i)
       		{
       			if(a>(res[i].second-res[i].first+1))
       				a-=(res[i].second-res[i].first+1);
       			else
       			{
       				cout<<res[i].first+a-1<<"\n";
       				a=0;
       				break;
       			}
       		}
       		if(a>0)
       			cout<<"-1\n";
       	}
    }
}