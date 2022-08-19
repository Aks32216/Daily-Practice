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
        This problem is extension of LIS problem. So we will be using the logic of LIS but with little improvement
        we will be maintaining a dp array which will store the LIS till ith element and another count array which
        will store no. of LIS till ith index.
        we will run normal LIS  check but here there will be two checks.
        1. if LIS at ith and LIS at jth index is same then LIS can be increased by 1 and count would be count of LIS at jth
            element because a new length LIS is begin extended from the previous LIS
        2. If LIS at ith index is greater than LIS at jth index by 1 then LIS will remain of the same length and hence we have
            found out a new LIS of same length only so we add the count of these two indices.
        
        at every index we will maintain the maximum LIS.
        at last we will add the count of LIS with maximum length
    */

int findNumberOfLIS(vector<int>& nums) {
	int n=nums.size();
	if(n<=1)
		return n;
	vector<int> dp(n,1),count(n,1);
	int m=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(nums[i]>nums[j])
			{
				if(dp[i]==dp[j])
				{
					count[i]=count[j];
					dp[i]=dp[j]+1;
				}
				else if(dp[j]+1==dp[i])
				{
					count[i]+=count[j];
				}
			}
		}
		m=max(m,dp[i]);
	}
	int ans=0;
	for(int i=0;i<n;++i)
	{
		if(dp[i]==m)
			ans+=count[i];
	}
	return ans;
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
       cout<<findNumberOfLIS(v)<<"\n";
}