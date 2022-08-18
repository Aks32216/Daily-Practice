// Stack Method
stack<int>s;
void help(vector<int> adj[],bool vis[],int p)
{
    vis[p]=true;
    int i;
    for(i=0;i<adj[p].size();i++)
    if(vis[adj[p][i]]==false)
       help(adj,vis,adj[p][i]);
       s.push(p);
}
vector<int> topoSort(int v, vector<int> adj[]) 
{
   
      bool vis[v+1];
      memset(vis,0,sizeof(vis));
      int i;
      for(i=0;i<v;i++)
     if(vis[i]==false)
     {
         help(adj,vis,i);
     }
     vector<int>ans;
     while(!s.empty())
     {
       //  cout<<s.top()<<" ";
         ans.push_back(s.top());
         s.pop();
     }
    // cout<<endl;
     return ans;
}

// kahn's algorithm

vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
        vector<int> indegree(N, 0); 
        for(int i = 0;i<N;i++) {
            for(auto it: adj[i]) {
                indegree[it]++; 
            }
        }
        
        for(int i = 0;i<N;i++) {
            if(indegree[i] == 0) {
                q.push(i); 
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it); 
                }
            }
        }
        return topo;
    }