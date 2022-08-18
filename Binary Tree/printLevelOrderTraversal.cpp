vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>  >res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int n=q.size();
            while(n--)
            {
                auto cur=q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(temp);
        }
        return res;
    }