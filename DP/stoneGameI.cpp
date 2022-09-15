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
 
bool solve(int i,int j,int alice,int bob,bool chance,vector<int>& piles,vector<vector<int> >& dp)
{
	if(i>j)
		return alice>bob?true:false;
	if(dp[i][j]!=-1)
		return dp[i][j];
    if(chance==true) // alice choice
       	return dp[i][j]=solve(i+1,j,alice+piles[i],bob,!chance,piles,dp) || solve(i,j-1,alice+piles[j],bob,!chance,piles,dp);
    else
	   	return dp[i][j]=solve(i+1,j,alice,bob+piles[i],!chance,piles,dp) || solve(i,j-1,alice,bob+piles[j],!chance,piles,dp);
}
    
bool stoneGame(vector<int>& piles) {
	int n=piles.size();
   	vector<vector<int> > dp(n,vector<int>(n,-1));
   	return solve(0,piles.size()-1,0,0,true,piles,dp);
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
 	cout<<stoneGame(v)<<"\n";
}