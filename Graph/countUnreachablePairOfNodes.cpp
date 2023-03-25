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
 
void dfs(int node,vector<bool>& visited,vector<vector<int> >& graph,long long& count)
{
    visited[node]=true;
    count++;
    for(auto child:graph[node])
    {
        if(!visited[child])
            dfs(child,visited,graph,count);
    }
}

long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int> > graph(n);
    for(auto i:edges)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    vector<long long> connCompSize;
    vector<bool> visited(n,false);
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            long long count=0;
            dfs(i,visited,graph,count);
            sum+=count;
            connCompSize.push_back(count);
        }
    }
    long long  ans=0;
    for(int i=0;i<connCompSize.size();++i)
    {
        sum-=connCompSize[i];
        ans+=(connCompSize[i]*sum);
    }
    return ans;
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
 	vector<vector<int> > graph(n,vector<int>(2));
 	for(int i=0;i<n;++i){
 		cin>>graph[i][0]>>graph[i][1];
 	}      
 	cout<<countPairs(n,graph)<<"\n";
}
