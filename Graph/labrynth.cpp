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

vector<vector<char> > grid(1005,vector<char>(1005));
int n,m;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
string res;

void dfs(int x,int y,string temp)
{
    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='#')
        return;
    if(grid[x][y]=='B')
    {
        if(res=="" || temp.length()<res.length())
            res=temp;
        return;
    }
    grid[x][y]='#';
    dfs(x+1,y,temp+'D');
    dfs(x-1,y,temp+'U');
    dfs(x,y+1,temp+'R');
    dfs(x,y-1,temp+'L');
} 

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       cin>>n>>m;
    grid.resize(n,vector<char>(m));
    int aXcord,aYcord;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
                aXcord=i,aYcord=j;
        }
    }
    string temp;
    dfs(aXcord,aYcord,temp);
    if(res=="")
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        cout<<res.length()<<"\n";
        cout<<res<<"\n";
    }
}