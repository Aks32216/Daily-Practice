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
 
/*int dp[505][505];
    
    int distance(string a,int n,string b,int m)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=distance(a,n-1,b,m-1);
        else
            return dp[n][m]=1+min({distance(a,n-1,b,m),distance(a,n,b,m-1),distance(a,n-1,b,m-1)});
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return distance(word1,word1.length(),word2,word2.length());
    }*/


View raw Copy to clipboard
int minDistance(string a, string b) {
        int n=b.length();
        int m=a.length();
        
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;++i)
            t[i][0]=i;
        for(int i=0;i<m+1;++i)
            t[0][i]=i;
        
        for(int i=1;i<n+1;++i)
        {
            for(int j=1;j<m+1;++j)
            {
                if(b[i-1]==a[j-1])
                    t[i][j]=t[i-1][j-1];
                else
                    t[i][j]=1+min(t[i-1][j],min(t[i-1][j-1],t[i][j-1]));
            }
        }
        return t[n][m];
    }

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       string a,b;
       cin>>a>>b;
       cout<<minDistance(a,b)<<"\n";
}	