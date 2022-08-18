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

void dfs(int x,int y,int& count,vector<vector<int> >& grid)
{
	if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)
		return;
	grid[x][y]=0;
	count++;
	for(int i=0;i<4;++i)
	{
		int curx=x+dx[i];
		int cury=y+dy[i];
		dfs(curx,cury,count,grid);
	}
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int maxArea=0;
	n=grid.size();
	m=grid[0].size();
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(grid[i][j]==1)
			{
				int count=0;
				dfs(i,j,count,grid);
				maxArea=max(maxArea,count);
			}
		}
	}
	return maxArea;
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
       vector<vector<int> > grid(n,vector<int>(m));
       for(int i=0;i<n;++i)
       {
       		for(int j=0;j<m;++j)
       		{
       			cin>>grid[i][j];
       		}
       }
       int area=maxAreaOfIsland(grid);
       cout<<area<<"\n";
}