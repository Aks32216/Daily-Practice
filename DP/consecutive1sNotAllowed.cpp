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
#define ll long long int
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int

ll mod=(int)1e9+7;
 
ll solve(int i,int j,int n,vector<vector<ll> >& dp)
{
	if(i>=n)
		return 1;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(j==0)
		return dp[i][j]=(solve(i+1,0,n,dp) % mod + solve(i+1,1,n,dp) % mod ) % mod;
	else
		return dp[i][j]=solve(i+1,0,n,dp) % mod;
}

ll countStrings(int n) {
   // vector<vector<ll> > dp(n,vector<ll>(2,-1));
   // return solve(0,0,n,dp) % mod;
	vector<vector<ll> > dp(n+1,vector<ll>(2));
	dp[n][0]=dp[n][1]=1;
	for(int i=n-1;i>=0;--i)
	{
		for(int j=1;j>=0;--j)
		{
			if(j==0)
				dp[i][j]=(dp[i+1][0] % mod + dp[i+1][1] % mod) % mod;
			else
				dp[i][j]=dp[i+1][0] % mod;
		}
	}
	return dp[0][0];
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
 	cout<<countStrings(n)<<"\n";
}