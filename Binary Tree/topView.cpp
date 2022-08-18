vector<int> topView(Node *root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
        map<int,int> mp;
        queue<pair<Node*,int> > q;
        q.push({root,0});
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            if(mp.find(cur.second)==mp.end())
            {
                mp[cur.second]=cur.first->data;
            }
            if(cur.first->left)
                q.push({cur.first->left,cur.second-1});
            if(cur.first->right)
                q.push({cur.first->right,cur.second+1});
        }
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }