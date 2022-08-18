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

int solve(int idx,int buy,int& fee,vector<int>& prices,vector<vector<int> >& dp)
{
	if(idx>=prices.size())
		return 0;
	if(dp[idx][buy]!=-1)
		return dp[idx][buy];
	if(buy){
		return dp[idx][buy]=max(-prices[idx]+solve(idx+1,0,fee,prices,dp),solve(idx+1,1,fee,prices,dp));
	}else{
		return dp[idx][buy]=max(prices[idx]-fee+solve(idx+1,1,fee,prices,dp),solve(idx+1,0,fee,prices,dp));
	}
}

int maxProfit(vector<int>& prices, int fee) {
	int n=prices.size();
	vector<vector<int> > dp(n+1,vector<int>(2,0));
        // return solve(0,1,fee,prices,dp);
	for(int idx=n-1;idx>=0;--idx)
	{
		for(int buy=0;buy<=1;++buy)
		{
			if(buy)
				dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
			else
				dp[idx][buy]=max(prices[idx]-fee+dp[idx+1][1],dp[idx+1][0]);
		}
	}
	return dp[0][1];
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n,fee;
       cin>>n>>fee;
       vector<int> v(n);
       for(auto& i:v)
       		cin>>i;
       int profit=maxProfit(v,fee);
       cout<<profit<<"\n";
}