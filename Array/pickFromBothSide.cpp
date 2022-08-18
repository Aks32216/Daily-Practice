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

Dynamic Programming Approach:

Time Complexity : O(K^2)

int solve(vi& arr,vector<vector<int> >& dp,int sum,int i,int j,int b)
{
	if(b==0)
		return sum;
	if(i>j)
		return sum;
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j]=max(solve(arr,dp,sum+arr[i],i+1,j,b-1),solve(arr,dp,sum+arr[j],i,j-1,b-1));
}

int maxSum(vi& v,int b)
{
	int n=v.size();
	vector<vector<int> > dp(n,vector<int>(n,-1));
	return solve(v,dp,0,0,n-1,b);
}*/

int maxSum(vi& v,int b)
{
	int sum=0,i=0;
	while(i<b)
		sum+=v[i],i++;
	int maxScore=sum;
	int j=v.size()-1;
	while(b>0)
	{
		sum=sum+v[j]-v[b-1];
		maxScore=max(maxScore,sum);
		b--,j--;
	}
	return maxScore;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       int n,b;
       cin>>n>>b;
       vi v(n);
       for(auto& i:v)
       		cin>>i;
       	cout<<maxSum(v,b)<<"\n";
}