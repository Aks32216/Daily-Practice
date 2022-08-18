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

set<int> adj[200005];
vector<bool> vis(200005);
int n;
 
void bfs(int node,vector<int>& arr)
{
    vis[node]=1;
    queue<int>q;
    q.push(node);
    int i=1;
    while(q.size())
    {
        node=q.front();
        q.pop();
        {
            while(adj[node].size() && i<n)
            {
                if(adj[node].count(arr[i]))
                {
                    adj[node].erase(arr[i]);
                    q.push(arr[i]);
                    vis[arr[i]]=1;
                    i++;
                }
                else break;
            }
            for(auto e:adj[node])
            {
                if(!vis[e])
                {
                    cout<<"no";
                    return;
                }
            }
 
        }
 
    }
  cout<<"yes";
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

        cin>>n;
    int a,b;
    for(int i=0;i<n-1;++i)
    {
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> tempBFS(n);
    for(auto& i:tempBFS)
        cin>>i;
    if(tempBFS[0]!=1)
    {
        cout<<"No\n";
        exit(0);
    }
    bfs(1,tempBFS);
}