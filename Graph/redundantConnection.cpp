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

/*
int find(int a,vector<int>& parent){
    if(parent[a]==-1)
        return a;
    else
        return find(parent[a],parent);
}

void unions(int a,int b,vector<int>& parent,vector<int>& rank){
    a=find(a,parent);
    b=find(b,parent);
    if(a==b)
        return;
    if(rank[a]>=rank[b]){
        rank[a]+=rank[b];
        parent[b]=a;
    }
    else
    {
        rank[b]+=rank[a];
        parent[a]=b;
    }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n=edges.size();
    vector<int> parent(n,-1);
    vector<int> rank(n,1);
    for(auto i:edges){
        int a=i[0];
        int b=i[1];
        a--,b--;
        a=find(a,parent);
        b=find(b,parent);
        if(a==b)
            return {i[0],i[1]};
        else
            unions(a,b,parent,rank);
    }
    return {-1,-1};
}
*/
    
void dfs(int node,vector<bool>& visited,vector<vector<int> >& graph){
	visited[node]=true;
	for(auto child:graph[node]){
		if(visited[child]==false){
			dfs(child,visited,graph);
		}
	}
}

vector<int> findRedundantConnection(vector<vector<int> >& edges){
	int n=edges.size();
	vector<vector<int> > graph(n+1);
	for(auto i:edges)
	{
		vector<bool> visited(n,false);
		int a=i[0];
		int b=i[1];
		dfs(a,visited,graph);
		if(visited[b]==true){
			return {a,b};
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	return {-1,-1};
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
 	vector<vector<int> > v(n,vector<int>(2));
 	for(int i=0;i<n;++i){
 		cin>>v[i][0]>>v[i][1];
 	}      
 	vector<int> res=findRedundantConnection(v);
 	cout<<res[0]<<" "<<res[1]<<"\n";
}