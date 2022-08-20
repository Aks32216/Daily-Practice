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
    in loop cost to cut is (cuts[j+1]-cuts[i-1]) + solve(left recursive) + solve(right recursive)
    in start apend 0 and n because those are the length of the stick at start and end side

*/

int solve(int i,int j,vector<int>& cuts,vector<vector<int> >& dp)
{
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int minVal=1e9;
	for(int idx=i;idx<=j;++idx)
	{
		int val=(cuts[j+1]-cuts[i-1])+solve(i,idx-1,cuts,dp)+solve(idx+1,j,cuts,dp);
		minVal=min(minVal,val);
	}
	return dp[i][j]=minVal;
}

int minCost(int n, vector<int>& cuts) {
	int m=cuts.size();
	cuts.insert(begin(cuts),0);
	cuts.push_back(n);
	sort(begin(cuts),end(cuts));
    // vector<vector<int> > dp(m+1,vector<int>(m+1,-1));
    // return solve(1,m,cuts,dp);

	vector<vector<int> > dp(m+2,vector<int>(m+2,0));
	for(int i=m;i>=1;--i)
	{
		for(int j=1;j<=m;++j)
		{
			if(i>j)
				continue;
			int minVal=1e9;
			for(int idx=i;idx<=j;++idx)
			{
				int val=(cuts[j+1]-cuts[i-1])+dp[i][idx-1]+dp[idx+1][j];
				minVal=min(minVal,val);
			}
			dp[i][j]=minVal;
		}
	}
	return dp[1][m];
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
       int c;
       cin>>c;
       vector<int> v(c);
       for(auto& i:v)
       		cin>>i;
       cout<<minCost(n,v)<<"\n";
}