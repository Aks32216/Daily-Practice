#include <bits/stdc++.h>
using namespace std;

int formGraph(vector<vector<int> >& adj,vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& mp,int& idx,int start,int end)
{
    if(idx>=preorder.size() || start>end)
        return -1;
    int curEle=preorder[idx];
    int pivot=mp[inorder[idx]];
    idx++;

    int a=formGraph(adj,preorder,inorder,mp,idx,start,pivot-1);
    int b=formGraph(adj,preorder,inorder,mp,idx,pivot+1,end);
    cout<<curEle<<" "<<a<<" "<<b<<" "<<idx<<" "<<pivot<<"\n";
    if(a!=-1)
    {
        adj[curEle].push_back(a);
        adj[a].push_back(curEle);
    } 
    if(b!=-1)
    {
        adj[curEle].push_back(b);
        adj[b].push_back(curEle);
    }

    return curEle;
}

void dfs(int src,unordered_map<int,int>& water,vector<vector<int> >& adj)
{
    int n=adj.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    int count=0;
    while(!q.empty())
    {
        cout<<count<<" -> ";
        int size=q.size();
        vector<int> temp;
        while(size--)
        {
            int cur=q.front();
            q.pop();
            temp.push_back(cur);
            for(auto child:adj[cur])
            {
                if(!visited[child] && water.find(child)==water.end())
                {
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
        for(auto i:temp)
            cout<<i<<" ";
        cout<<"\n";
        count++;
    }
}

vector<vector<int> > adj(1000005);

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    for(auto& i:preorder)
        cin>>i;
    for(auto& i:inorder)
        cin>>i;
    int m;
    cin>>m;
    unordered_map<int,int> water;
    int x;
    for(int i=0;i<m;++i)
    {
        cin>>x;
        water[x]++;
    }
    int fire;
    cin>>fire;
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();++i)
    {
        mp[inorder[i]]=i;
    }
    int idx=0,start=0,end=n-1;
    int temp=formGraph(adj,preorder,inorder,mp,idx,start,end);
    dfs(fire,water,adj);
}