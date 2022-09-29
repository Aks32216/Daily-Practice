int solve(TreeNode* root,int& m)
    {
        if(root==NULL)
            return 0;
        int lSum=solve(root->left,m);
        int rSum=solve(root->right,m);
        m=max({m,root->val+lSum+rSum,root->val,root->val+lSum,root->val+rSum});
        return max({root->val,root->val+lSum,root->val+rSum});
    }
    
    int maxPathSum(TreeNode* root) {
        int m=INT_MIN;
        solve(root,m);
        return m;
    }