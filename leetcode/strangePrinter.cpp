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
int  dy[4]={0,0,1,-1};

void bfs(int x,int y,vector<vector<int> >& grid,vector<vector<bool> >& visited)
{
	visited[x][y]=true;
	int val=grid[x][y];
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty())
	{
		auto cur=q.front();
		q.pop();
		for(int i=0;i<4;++i)
		{
			int curx=cur.first+dx[i];
			int cury=cur.second+dy[i];
			if(curx>=0 && cury>=0 && curx<n && cury<m && visited[curx][cury]==false &&  val==grid[curx][cury])
			{
				visited[curx][cury]=true;
				q.push({curx,cury});
			}
		}
	}
}

bool isPrintable(vector<vector<int>>& targetGrid) {
	 n=targetGrid.size();
	 m=targetGrid[0].size();
	 if(n==0 || m==0)
	 	return true;
	 vector<bool> tracker(100,false);
	 vector<vector<bool> > visited(n,vector<bool>(m,false));
	 for(int i=0;i<n;++i)
	 {
	 	for(int j=0;j<m;++j)
	 	{
	 		if(visited[i][j]==false)
	 		{
	 			if(tracker[targetGrid[i][j]]==true)
	 				return false;
	 			tracker[targetGrid[i][j]]=true;
	 			bfs(i,j,targetGrid,visited);
	 		}
	 	}
	 }
	 return true;
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
       cout<<isPrintable(v)<<"\n";
}