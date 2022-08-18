vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        vector<int> distance(V,INT_MAX);
        distance[S]=0;
        pq.push({S,0});
        while(!pq.empty())
        {
            int node=pq.top().first;
            int dist=pq.top().second;
            pq.pop();
            for(auto child:adj[node])
            {
                if(dist+child[1]<distance[child[0]])
                {
                    pq.push({child[0],dist+child[1]});
                    distance[child[0]]=dist+child[1];
                }
            }
        }
        return distance;
    }