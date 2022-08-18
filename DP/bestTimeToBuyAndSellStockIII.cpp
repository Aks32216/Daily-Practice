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

/*int solve(int idx,int buy,int noOfTransaction,vector<int>& prices,vector<vector<vector<int> > >& dp)
{
	if(idx>=prices.size() || noOfTransaction>=2)
		return 0;
	if(dp[idx][buy][noOfTransaction]!=-1)
		return dp[idx][buy][noOfTransaction];
	if(buy)
	{
		return max(-prices[idx]+solve(idx+1,0,noOfTransaction,prices,dp),solve(idx+1,1,noOfTransaction,prices,dp));
	}
	else{
		return max(prices[idx]+solve(idx+1,1,noOfTransaction+1,prices,dp),solve(idx+1,0,noOfTransaction,prices,dp));
	}
}

int maxProfit(vector<int>& prices) {
	vector<vector<vector<int> > > dp(prices.size(),vector<vector<int> > (2,vector<int> (3,-1)));
	return solve(0,1,0,prices,dp);
}*/
 
int maxProfit(vector<int>& prices) {
	int n=prices.size();
	vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (2,vector<int> (3,0)));
	for(int idx=n-1;idx>=0;--idx)
	{
		for(int buy=0;buy<=1;++buy)
		{
			for(int cap=1;cap<=2;++cap)
			{
				if(buy==1)
				{
					dp[idx][buy][cap]=max(-prices[idx]+dp[idx+1][0][cap],dp[idx+1][1][cap]);
				}
				else
				{
					dp[idx][buy][cap]=max(prices[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
				}
			}
		}
	}
	return dp[0][1][2];
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
       vector<int> v(n);
       for(auto& i:v)
       		cin>>i;
       int profit=maxProfit(v);
       cout<<profit<<"\n";
}