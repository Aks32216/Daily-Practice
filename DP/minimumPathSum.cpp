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
 
int solve(int x,int y,vector<vector<int> >& grid,vector<vector<int> >& dp){
	if(x<0 || y<0)
		return 1e9;
	if(x==0 && y==0)
		return grid[0][0];
	if(dp[x][y]!=-1)
		return dp[x][y];
	int up=solve(x-1,y,grid,dp)+grid[x][y];
	int left=solve(x,y-1,grid,dp)+grid[x][y];
	return dp[x][y]=min(up,left);
}

int minPathSum(vector<vector<int>>& grid) {
	int n=grid.size();
	int m=grid[0].size();
        // vector<vector<int> > dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,grid,dp);
	vector<vector<int> > dp(n,vector<int>(m));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(i==0 && j==0)
				dp[i][j]=grid[i][j];
			else if(i==0)
				dp[i][j]=grid[i][j]+dp[i][j-1];
			else if(j==0)
				dp[i][j]=grid[i][j]+dp[i-1][j];
			else
				dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                // cout<<dp[i][j]<<" ";
		}
            // cout<<"\n";
	}
	return dp[n-1][m-1];
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
    cout<<minPathSum(v)<<"\n";
}
