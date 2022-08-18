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
 
vector<vector<int> > graph(100005);
vector<bool> visited(100005);
vector<int> low(100005),in(100005);
int timer=0;

void dfs(int src,int par,vector<vector<int> >& res)
{
	visited[src]=true;
	in[src]=low[src]=timer++;
	for(auto child:graph[src])
	{
		if(child==par)
			continue;
		if(visited[child])
			low[src]=min(low[src],in[child]);
		else
		{
			dfs(child,src,res);
			if(low[child]>in[src])
				res.push_back({src,child});
			low[src]=min(low[src],low[child]);
		}
	}
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
       		int n,m;
       		cin>>n>>m;
       		for(int i=0;i<=n+5;++i)
       			graph[i].clear(),visited[i]=false,low[i]=INT_MAX,in[i]=0;
       		int a,b;
       		while(m--)
       		{
       			cin>>a>>b;
       			graph[a].push_back(b);
       			graph[b].push_back(a);
       		}
       		vector<vector<int> > res;
       		for(int i=0;i<n;++i)
       		{
       			if(visited[i]==false)
       			{
       				dfs(i,-1,res);
       			}
       		}
       		cout<<res.size()<<"\n";
       		for(auto i:res)
       		{
       			cout<<i[0]<<" "<<i[1]<<"\n";
       		}
       }
}