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

static bool comp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
	return a.first<b.first;
}

int find(int n,vector<int>& parent)
{
	if(parent[n]<0)
		return n;
	return parent[n]=find(parent[n],parent);
}

void unions(int a,int b,vector<int>& parent,vector<int>& rank)
{
	if(a==b)
		return;
	if(rank[a]<=rank[b])
	{
		rank[b]+=rank[a];
		parent[a]=b;
	}
	else
	{
		rank[a]+=rank[b];
		parent[b]=a;
	}
}

int minCostConnectPoints(vector<vector<int>>& points) 
{
	int n=points.size();
    vector<pair<int,pair<int,int> > > graph;
    for(int i=0;i<n-1;++i)
    {
    	for(int j=i+1;j<n;++j)
    	{
    		int diff=abs(points[j][1]-points[i][1]) + abs(points[j][0]-points[i][0]);
    		graph.push_back({diff,{i,j}});
    	}
    }
    sort(graph.begin(),graph.end(),comp);
    vector<int> parent(n,-1);
    vector<int> rank(n,1);
    int sum=0;
    for(int i=0;i<graph.size();++i)
    {
    	auto a=find(graph[i].second.first,parent);
    	auto b=find(graph[i].second.second,parent);
    	if(a!=b)
    	{
    		unions(a,b,parent,rank);
    		sum+=graph[i].first;
    	}
    }
    return sum;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n;
       cin>>n;
       vector<vector<int> > points(n,vector<int>(2));
       for(int i=0;i<n;++i)
       {
       		cin>>points[i][0]>>points[i][1];
       }
       cout<<minCostConnectPoints(points)<<"\n";
}