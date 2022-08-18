// Recursive Solution

void solve(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }

    // Iterative Solution

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root==NULL)
            return res;
        s.push(root);
        while(!s.empty())
        {
            auto cur=s.top();
            if(cur->left)
            {
                auto temp=cur->left;
                cur->left=NULL;
                s.push(temp);
            }
            else
            {
                res.push_back(cur->val);
                s.pop();
                if(cur->right)
                    s.push(cur->right);
            }
        }
        return res;
    }