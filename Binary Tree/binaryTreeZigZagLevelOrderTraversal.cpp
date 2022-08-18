vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp(n);
            for(int i=0;i<n;++i)
            {
                auto cur=q.front();
                q.pop();
                if(f==0)
                    temp[i]=cur->val;
                else
                    temp[n-i-1]=cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(temp);
            f=1-f;
            
        }
        return res;
    }