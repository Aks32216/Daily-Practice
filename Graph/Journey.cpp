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
 
vector<vector<ll> > adj(100005);
vector<ll> dist(100005);
vector<bool> visited(100005);
ll n;
 
void bfs(int node)
{
	queue<ll> q;
	q.push(node);
	visited[node]=true;
	dist[node]=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(auto child:adj[cur])
		{
			if(!visited[child])
			{
				visited[child]=true;
				dist[child]=1+dist[cur];
				q.push(child);
			}
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
 
       cin>>n;
       for(int i=1;i<=n;++i)
       		adj[i].clear(),dist[i]=0,visited[i]=false;
       	ll a,b;
       	for(int i=0;i<n-1;++i)
       	{
       		cin>>a>>b;
       		adj[a].push_back(b);
       		adj[b].push_back(a);
       	}
       	bfs(1);
       	ll count=0,sum=0;
       	for(int i=2;i<=n;++i)
       	{
       		if(adj[i].size()==1)
       		{
       			count++;
       			sum+=dist[i];
       		}
       	}
       	double ans=((1.0)*sum)/count;
       	cout<<fixed<<setprecision(7)<<ans;
}