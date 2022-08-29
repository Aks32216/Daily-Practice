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

int n,m;

int solve(int i,int j,vector<vector<int> >& matrix,vector<vector<int> >& dp)
{
	if(j<0 || j>=m)
		return 1e9;
	if(i==n-1){
		return matrix[i][j];
	}
	if(dp[i][j]!=-1)
		return dp[i][j];
	int down=matrix[i][j]+solve(i+1,j,matrix,dp);
	int leftDown=matrix[i][j]+solve(i+1,j-1,matrix,dp);
	int rightDown=matrix[i][j]+solve(i+1,j+1,matrix,dp);
	return dp[i][j]=min({down,leftDown,rightDown});
}

int minFallingPathSum(vector<vector<int>>& matrix) {
	n=matrix.size();
	m=matrix[0].size();
	vector<vector<int> > dp(n,vector<int>(m,-1));
	int sum=1e9;
	for(int col=0;col<matrix[0].size();++col){
		int curSum=solve(0,col,matrix,dp);
		sum=min(sum,curSum);
	}
	return sum;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int r,c;
 	cin>>r>>c;
 	vector<vector<int> > v(r,vector<int>(c));
 	for(int i=0;i<r;++i){
 		for(int j=0;j<c;++j){
 			cin>>v[i][j];
 		}
 	}      
 	cout<<minFallingPathSum(v)<<"\n";
}