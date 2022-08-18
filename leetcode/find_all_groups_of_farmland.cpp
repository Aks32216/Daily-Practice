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
 
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y,int& xmin,int& xmax,int& ymin,int& ymax,vector<vector<bool> >& visited,vector<vector<int> >& land)
{
	if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==true || land[x][y]==0)
		return;
	xmin=min(xmin,x);
	xmax=max(xmax,x);
	ymin=min(ymin,y);
	ymax=max(ymax,y);
	visited[x][y]=true;
	for(int i=0;i<4;++i)
	{
		int curx=x+dx[i];
		int cury=y+dy[i];
		dfs(curx,cury,xmin,xmax,ymin,ymax,visited,land);
	}
}

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
	n=land.size();
	m=land[0].size();
	vector<vector<int> > res;
	if(n==0 || m==0)
	{
	    res.push_back({0});
	    return res;
	}
	vector<vector<bool> > visited(n,vector<bool>(m,false));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(land[i][j]==1 && visited[i][j]==false)
			{
			    cout<<"function called for the values "<<i<<" and "<<j<<"\n";
				int xmin=INT_MAX,xmax=INT_MIN,ymin=INT_MAX,ymax=INT_MIN;
				dfs(i,j,xmin,xmax,ymin,ymax,visited,land);
				res.push_back({xmin,ymin,xmax,ymax});
			}
		}
	}        
	if(res.size()==0)
	    res.push_back({0});
	return res;
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
       vector<vector<int> > v(n,vector<int>(m));
       for(int i=0;i<n;++i)
       {
           for(int j=0;j<m;++j)
            cin>>v[i][j];
       }
       vector<vector<int> > res=findFarmland(v);
       cout<<res.size()<<" "<<res[0].size()<<"\n";
       for(const auto& i:res)
       {
       	for(const auto& j:i)
       		cout<<j<<" ";
       	cout<<"\n";
       }
}