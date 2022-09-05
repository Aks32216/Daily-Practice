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

// Using DFS
/*bool isBipartite(int node,int par,int col,vector<int>& color,vector<int> adj[]){
    color[node]=col;
    for(auto child:adj[node]){
        if(color[child]==-1){
            int tempCol=1-col;
            if(isBipartite(child,node,tempCol,color,adj)==false)
                return false;
        }
        else if(color[child]!=color[par])
            return false;
    }
    return true;
}*/

// using BFS
    
bool isBipartite(int node,int par,int col,vector<int>& color,vector<int> adj[]){
    queue<pair<int,int> > q;
    q.push({node,par});
    color[node]=col;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(auto child:adj[cur.first]){
            if(color[child]==-1){
                color[child]=1-color[cur.first];
                q.push({child,cur.first});
            }else if(color[child]!=color[cur.second])
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V,-1);
    for(int i=0;i<V;++i){
        if(color[i]==-1){
            if(isBipartite(i,-1,1,color,adj)==false){
                return false;
            }
        }
    }
    return true;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
    int v;
    cin>>v;
    vector<int> adj[v];
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }      
    cout<<isBipartite(v,adj)<<"\n";
}