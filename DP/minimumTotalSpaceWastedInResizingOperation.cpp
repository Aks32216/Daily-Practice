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
 
int solve(int idx,int k,vector<int>& nums,vector<vector<int> >& dp)
{
	if(idx==nums.size())
		return 0;
	if(k==-1)
		return 1e8;
	if(dp[idx][k]!=-1)
		return dp[idx][k];
	int sum=0,ans=1e8,m=-1e8;
	for(int j=idx;j<nums.size();++j)
	{
		m=max(m,nums[j]);
		sum+=nums[j];
		int totalWastage=(j-idx+1)*m-sum;
		ans=min(ans,totalWastage+solve(j+1,k-1,nums,dp));
	}
	return dp[idx][k]=ans;
}

int minSpaceWastedKResizing(vector<int>& nums, int k) {
	int n=nums.size();
	vector<vector<int> > dp(n,vector<int>(k+1,-1));
	return solve(0,k,nums,dp);
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
 	int k;
 	cin>>k;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<minSpaceWastedKResizing(v,k)<<"\n";
}