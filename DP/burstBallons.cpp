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
 
int solve(int i,int j,vector<int>& nums,vector<vector<int> >& dp)
{
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int minVal=-1;
	for(int k=i;k<=j;++k)
	{
		int val=nums[k]*nums[i-1]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
		minVal=max(minVal,val);
	}
	return dp[i][j]=minVal;
}

int maxCoins(vector<int>& nums) {
	int n=nums.size();
    // vector<vector<int> > dp(n+2,vector<int>(n+2,-1));
	nums.insert(begin(nums),1);
	nums.push_back(1);
    // return solve(1,n,nums,dp);
	vector<vector<int> > dp(n+2,vector<int>(n+2,0));
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i>j)
				continue;
			int minVal=-1;
			for(int k=i;k<=j;++k)
			{
				int val=nums[k]*nums[i-1]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
				minVal=max(minVal,val);
			}
			dp[i][j]=minVal;
		}
	}
	return dp[1][n];
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
       cout<<maxCoins(v)<<"\n";
}
