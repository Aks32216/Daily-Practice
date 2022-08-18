// Recursive Solution

 void solve(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        res.push_back(root->val);
        solve(root->left,res);
        solve(root->right,res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }

// Iterative Solution

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto cur=s.top();
            res.push_back(cur->val);
            s.pop();
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        return res;
    }