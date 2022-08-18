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

/*int lengthOfLIS(vector<int>& nums) {
	vector<int> dp;
	for(auto i:nums)
	{
		if(dp.size()==0)
		{
			dp.push_back(i);
			continue;
		}
		auto it=lower_bound(begin(dp),end(dp),i);
		if(it==dp.end())
			dp.push_back(i);
		else
		{
			int idx=it-dp.begin();
			dp[idx]=i;
		}
	}
	return dp.size();
}*/

/*int solve(int idx,int prev_idx,vector<int>& nums,vector<vector<int> >& dp)
{
	if(idx>=nums.size())
		return 0;
	if(dp[idx][prev_idx+1]!=-1)
		return dp[idx][prev_idx+1];
	int len=solve(idx+1,prev_idx,nums,dp);
	if(prev_idx==-1 || nums[idx]>nums[prev_idx])
		len=max(len,1+solve(idx+1,idx,nums,dp));
	return dp[idx][prev_idx+1]=len;
}

int lengthOfLIS(vector<int>& nums) {
	int n=nums.size();
	vector<vector<int> > dp(n,vector<int>(n+1,-1));
	return solve(0,-1,nums,dp);
}*/
 
int LIS(vi& v)
{
	int n=v.size();
	if(n==1)
		return 1;
	vi dp(n,1);
	int m=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(v[i]>v[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
		m=max(m,dp[i]);
	}
	return m;
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
       vi v(n);
       for(auto& i:v)
       		cin>>i;
       	cout<<LIS(v)<<"\n";
}