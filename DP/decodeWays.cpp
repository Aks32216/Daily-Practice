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
 
int solve(int idx,string s,vector<int>& dp)
{
	if(idx==s.length())
		return 1;
	if(s[idx]=='0')
		return 0;
	if(dp[idx]!=-1)
		return dp[idx];
	int singleDigit=solve(idx+1,s,dp);
	int twoDigit=0;
	if(idx+1<s.length())
	{
		int x=s[idx]-'0';
		int y=s[idx+1]-'0';
		int val=x*10+y;
		if(val>=1 && val<=26)
			twoDigit=solve(idx+2,s,dp);
	}
	return dp[idx]=singleDigit+twoDigit;
}

int numDecodings(string s) {
    // int n=s.length();
    // vector<int> dp(n,-1);
    // return solve(0,s,dp);
	int n=s.length();
	vector<int> dp(n+2,0);
	dp[n]=1;
	for(int i=n-1;i>=0;--i)
	{
		if(s[i]=='0')
		{
			dp[i]=0;
			continue;
		}
		int singleDigit=dp[i+1];
		int twoDigit=0;
		if(i+1<n)
		{
			int x=s[i]-'0';
			int y=s[i+1]-'0';
			int val=x*10+y;
			if(val>=1 && val<=26)
				twoDigit=dp[i+2];
		}
		dp[i]=singleDigit+twoDigit;
	}
	return dp[0];
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	string s;
 	cin>>s;    
 	cout<<numDecodings(s)<<"\n";  
}