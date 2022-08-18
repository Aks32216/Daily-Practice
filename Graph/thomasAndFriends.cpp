#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int> >& graph,vector<bool>& visited,vector<int>& in,vector<int>& out,vector<int>& low,int& timer,int& ans,int node,int dest,int par)
{
    visited[node]=true;
    in[node]=low[node]++;
    for(auto child:graph[node])
    {
        if(child==par)
            continue;
        if(visited[child]==true)
            low[node]=min(low[node],in[child]);
        else
        {
            dfs(graph,visited,in,out,low,timer,ans,child,dest,node);
            if(low[child]>in[node])
            {
                if(in[child]<=in[dest] && out[child]>=out[dest])
                    ans++;
            }
        }
        low[node]=min(low[node],low[child]);
    }
}

int getMinDistance(int v,int e,vector<int>& v1,vector<int>& v2,int a,int b)
{
    unordered_map<int,vector<int> > mp;
    for(int i=0;i<e;++i)
    {
        graph[v1[i]].push_back(v2[i]);
        graph[v2[i]].push_back(v1[i]);
    }
    vector<bool> visited(v,false);
    vector<int> in(v,0),out(v,0),low(v,0);
    int timer=0,ans=0;
    dfs(graph,visited,in,out,low,timer,ans,a,b,-1);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v1(m),v2(m);
        for(int i=0;i<m;++i)
        {
            cin>>v1[i]>>v2[i];
        }
        int a,b;
        cin>>a>>b;
        cout<<getMinDistance(n,m,v1,v2,a,b)<<"\n";
    }
}