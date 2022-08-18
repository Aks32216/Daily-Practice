int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> distance(V,INT_MAX);
        vector<bool> visited(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        pq.push({0,0});
        distance[0]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            visited[node]=true;
            for(auto child:adj[node])
            {
                int v=child[0];
                int weight=child[1];
                if(visited[v]==false && weight<distance[v])
                {
                    distance[v]=weight;
                    pq.push({distance[v],v});
                }
            }
        }
        int sum=0;
        for(int i=0;i<distance.size();++i)
            sum+=distance[i];
        return sum;
    }