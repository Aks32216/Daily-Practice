// Recursive Solution

void solve(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        solve(root->left,res);
        solve(root->right,res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }

    // Iterative Solution

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto cur=s.top();
            s.pop();
            if(cur->left)
            {
                s.push(cur->left);
            }
            if(cur->right)
                s.push(cur->right);
            res.insert(res.begin(),cur->val);
        }
        return res;
    }