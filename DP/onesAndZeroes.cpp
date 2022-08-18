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

int dp[105][105][605];
    
    vector<int> countZeroOne(string& s)
    {
        vector<int> count(2,0);
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='0')
                count[0]++;
            else
                count[1]++;
        }
        return count;
    }
    
    int solve(vector<string>& arr,int m,int n,int idx)
    {
        if(idx>=arr.size() || m+n==0)
            return dp[m][n][idx]=0;
        if(dp[m][n][idx]!=-1)
            return dp[m][n][idx];
        int consider=0;
        vector<int> zeroOne=countZeroOne(arr[idx]);
        if(m>=zeroOne[0] && n>=zeroOne[1])
            consider=1+solve(arr,m-zeroOne[0],n-zeroOne[1],idx+1);
        int skip=0;
        skip=solve(arr,m,n,idx+1);
        return dp[m][n][idx]=max(skip,consider);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
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
       int a,b;
       cin>>a>>b;
       vector<string> v(n);
       for(auto& i:v)
       		cin>>i;
       	cout<<findMaxForm(v,a,b)<<"\n";
}