bool dfs(int node,vector<int>& color,vector<bool>& visited,vector<vector<int> >& graph,int color_node)
{
    visited[node]=true;
    color[node]=color_node;
    for(auto child:graph[node])
    {
        if(!visited[child])
        {
            int child_color=color_node==2?3:2;
            if(dfs(child,color,visited,graph,child_color)==false)
                return false;
        }
        else if(color[child]==color[node])
            return false;
    }
    return true;
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<bool> visited(n+1,false);
    vector<int> color(n+1,-1);
    bool x=true;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            int color_node=2;
            x=dfs(i,color,visited,graph,color_node);
            if(!x)
                return false;
        }
    }
    return true;
}