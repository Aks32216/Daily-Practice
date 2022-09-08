#include <bits/stdc++.h>
 
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
#define mod 1e9+7

int solve(int idx,vector<int>& nums,vector<int>& dp)
{
	if(idx<0)
		return 0;
	if(idx==0)
		return nums[idx];
	if(idx==1)
		return max(nums[idx],nums[idx-1]);
	if(dp[idx]!=-1)
		return dp[idx];
	int pick=nums[idx]+solve(idx-2,nums,dp);
	int nonPick=solve(idx-1,nums,dp);
	return dp[idx]=max(pick,nonPick);
}

int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return solve(nums.size()-1,nums,dp);
	int n=nums.size();
	if(n==1)
		return nums[0];
	if(n==2)
		return max(nums[0],nums[1]);
	vector<int> dp(n);
	dp[0]=nums[0];
	dp[1]=max(nums[0],nums[1]);
	for(int i=2;i<n;++i)
	{
		dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
	}
	return dp[n-1];
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
 	cout<<rob(v)<<"\n";
}