 int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,unsigned long long int> > q;
        q.push({root,1});
        unsigned long long int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            ans=max(ans,((q.back().second-q.front().second)+1));
            while(n--)
            {
                auto cur=q.front();
                q.pop();
                if(cur.first->left!=NULL)
                    q.push({cur.first->left,cur.second*2});
                if(cur.first->right!=NULL)
                    q.push({cur.first->right,cur.second*2+1});
            }
        }
        return ans;
    }