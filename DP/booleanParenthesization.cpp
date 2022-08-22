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
    lets suppose four variable with meaning
        leftTrue -> no of ways in which left partition from our operator yields true
        leftFalse -> no of ways in which left partition from our operator yields false
        rightTrue -> no of ways in which right partition from our operator yields true
        rightFalse -> no of ways in which right  partition from our operator yields false
        isTrue -> denotes for a particular partition what we want as no of ways
            -> 1-> that means we want the no of ways a particualr partition can yield true
            -> 0 -> means that we wnat the no of ways a particualr partition can yield false
        
    Now just for convinience lets suppose we want to calculate the no of ways in which a partiular partition yeilds true
    and in between we have operator.
    so how we will calculate the value
        
    if operator == &
    	T&T=T F&T=F T&F=F F&F=F
    
        -> for true value
            leftTrue*rightTrue
            
        -> for false value
            leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse
    
    if operator == |
    	F&F=F T&F=T F&T=T T&T=T
        
        -> for true value
            leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue
            
        -> for false value
            leftFalse*rightFalse
            
    if operator == ^
    	T&T=F F&F=F T&F=T F&T=T
    
        -> for true value
            leftTrue*rightFalse + leftFalse*rightTrue
            
        -> for false value
            leftTrue*rightTrue + leftFalse*rightFalse
            
    Now we can use this formula to calulate whatever isTrue value we are looking to sovle for a particular sub problem and return it

*/

int solve(int i,int j,bool isTrue,string s,vector<vector<vector<int> > >& dp)
{
	if(i>j)
		return 0;
	if(i==j)
	{
		if(isTrue==1)
			return s[i]=='T';
		else
			return s[i]=='F';
	}
	if(dp[i][j][isTrue]!=-1)
		return dp[i][j][isTrue] % 1003;
	int ways = 0;
	for(int idx=i+1;idx<=j-1;idx+=2)
	{
		int leftTrue=solve(i,idx-1,1,s,dp);
		int leftFalse=solve(i,idx-1,0,s,dp);
		int rightTrue=solve(idx+1,j,1,s,dp);
		int rightFalse=solve(idx+1,j,0,s,dp);
		if(s[idx]=='&')
		{
			if(isTrue)
				ways+=(leftTrue*rightTrue) % 1003;
			else
				ways+=(leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse) % 1003;
		}else if(s[idx]=='|')
		{
			if(isTrue)
				ways+=(leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue) % 1003;
			else
				ways+=(leftFalse*rightFalse) % 1003;
		}
		else if(s[idx]=='^')
		{
			if(isTrue)
				ways+=(leftTrue*rightFalse + leftFalse*rightTrue) % 1003;
			else
				ways+=(leftTrue*rightTrue + leftFalse*rightFalse) % 1003;
		}
	}
	return dp[i][j][isTrue]=ways % 1003;
}

int countWays(int N, string S){
	vector<vector<vector<int> > > dp(N,vector<vector<int> > (N,vector<int>(2,-1)));
	return solve(0,N-1,1,S,dp) % 1003;
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
       string s;
       cin>>s;
       cout<<countWays(n,s)<<"\n";
}