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

int solve(int i,int j,vector<vector<int> >& triangle,vector<vector<int> >& dp){
	if(i+1==triangle.size())
		return triangle[i][j];
	if(dp[i][j]!=-1)
		return dp[i][j];
	int exactDown=solve(i+1,j,triangle,dp)+triangle[i][j];
	int diagDown=solve(i+1,j+1,triangle,dp)+triangle[i][j];
	return dp[i][j]=min(exactDown,diagDown);
}

int minimumTotal(vector<vector<int>>& triangle) {
	int n=triangle.size();
        // vector<vector<int> > dp(n,vector<int>(n,-1));
        // return solve(0,0,triangle,dp);
	vector<vector<int> > dp(n,vector<int>(n));
	for(int i=0;i<n;++i)
		dp[n-1][i]=triangle[n-1][i];
	for(int i=n-2;i>=0;--i)
	{
		for(int j=i;j>=0;--j){
			dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
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
 
 	
 	int n,m;
 	cin>>n>>m;
 	vector<vector<int> > v(n,vector<int>(m));
 	for(int i=0;i<n;++i){
 		for(int j=0;j<m;++j){
 			cin>>v[i][j];
 		}
 	}      
 	cout<<minimumTotal(v)<<"\n";
}