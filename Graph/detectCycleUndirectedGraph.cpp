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
 
/*

BFS approach

bool containCycle(vector<int> graph[],int n)
{
	vector<int> parent(n,-1);
	vector<int> visited(n,false);
	queue<pair<int,int> > q;
	q.push({0,-1});
	visited[0]=true;
	while(!q.empty())
	{
		int node=q.front().first;
		int par=q.front().second;
		q.pop();
		for(auto child:graph[node])
		{
			if(!visited[child])
			{
				visited[child]=true;
				q.push({child,par});
			}
			else if(par!=child)
				return true;
		}
	}
	return false;
}*/

bool dfs(int node,int par,vector<int> graph[],vector<bool>& visited)
{
	visited[node]=true;
	for(auto child:graph[node])
	{
		if(!visited[child])
		{
			if(dfs(child,node,graph,visited))
				return true;
		}
		else if(par!=child)
			return true;
	}
	return false;
}

bool containCycle(vector<int> graph[],int n)
{
	vector<bool> visited(n,false);
	return dfs(0,-1,graph,visited);
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n,m;
       cin>>n>>m;
       vector<int> adj[n];
       int a,b;
       for(int i=0;i<m;++i)
       {
       		cin>>a>>b;
       		adj[a].push_back(b);
       		adj[b].push_back(a);
       }
       if(containCycle(adj,n))
       		cout<<"Graph contains Cycle\n";
       	else
       		cout<<"Graph does not contain cycle\n";
}