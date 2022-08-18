vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > res;
        map<int,vector<pair<int,int> > > mp;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        int height=-1;
        while(!q.empty())
        {
            height++;
            int n=q.size();
            while(n--)
            {
                auto cur=q.front();
                q.pop();
                int line=cur.second;
                mp[line].push_back({height,cur.first->val});
                if(cur.first->left)
                    q.push({cur.first->left,cur.second-1});
                if(cur.first->right)
                    q.push({cur.first->right,cur.second+1});
            }
        }
        vector<pair<int,int> > temp;
        for(auto i:mp)
        {
            temp=i.second;
            sort(temp.begin(),temp.end(),[](pair<int,int> a,pair<int,int> b){ if(a.first==b.first) return a.second<b.second; else return a.first<b.first;});
            vector<int> temp1;
            for(auto i:temp)
                temp1.push_back(i.second);
            res.push_back(temp1);
        }
        return res;
    }