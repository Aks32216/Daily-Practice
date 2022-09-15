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
 
/*
int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,int& res,vector<vector<int> >& dp)
{
    if(i==0 || j==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(nums1[i-1]==nums2[j-1])
        ans=1+solve(i-1,j-1,nums1,nums2,res,dp);
    int ans2=solve(i-1,j,nums1,nums2,res,dp);
    int ans3=solve(i,j-1,nums1,nums2,res,dp);
    res=max({res,ans,ans2,ans3});
    return dp[i][j]=ans;
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    vector<vector<int> > dp(1005,vector<int>(1005,-1));
    int res=0;
    solve(n,m,nums1,nums2,res,dp);
    return res;
}
*/

int findLength(vector<int>& nums1, vector<int>& nums2) {
	int n=nums1.size();
	int m=nums2.size();
	vector<vector<int> > dp(n+1,vector<int>(m+1));
	int ans=0;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(nums1[i-1]==nums2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=0;
			ans=max(ans,dp[i][j]);
		}
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
 
 	int n,m;
 	cin>>n>>m;
 	vector<int> a(n),b(m);
 	for(auto& i:a)
 		cin>>i;
 	for(auto& i:b)
 		cin>>i;
 	cout<<findLength(a,b)<<"\n";
}