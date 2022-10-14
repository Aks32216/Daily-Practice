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
    In order to find all paths we need to apply DFS so that it can traverse through all the children of a node and come back to               traverse other nodes.
    
    We know our source node is 0 and destination node is n-1 so we run a DFS from 0 and keep our destination as n-1.
    
    We keep a temporary array to store the current path and a result matrix to store the answer.
    
    whenever src==dest, this is one of our required path and hence we push this path into our result.
    
    at last this node may or may not form a path so we pop it from temporary array after exploring all its childrent for 
    other paths to be discovered.
*/

void dfs(int src,int dest,vector<vector<int> >& graph,vector<int> temp,vector<vector<int> >& res)
{
	temp.push_back(src);
	if(src==dest)
	{
		res.push_back(temp);
		return;
	}
	for(auto child:graph[src])
	{
		dfs(child,dest,graph,temp,res);
	}
	temp.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	int n=graph.size();
	vector<vector<int> > res;
	vector<int> temp;
	dfs(0,n-1,graph,temp,res);
	return res;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,m;
 	cin>>n>>m;
 	vector<vector<int> > v(n);
 	int a,b;
 	while(m--)
 	{
 		cin>>a>>b;
 		v[a].push_back(b);
 	}
 	vector<vector<int> > res=allPathsSourceTarget(v);
 	for(auto i:res)
 	{
 		for(auto j:i)
 			cout<<j<<" ";
 		cout<<"\n";
 	}
}