bool solve(TreeNode* root,long minVal,long maxVal)
    {
        if(root==NULL)
            return true;
        if(root->val>minVal && root->val<maxVal)
            return solve(root->left,minVal,root->val) && solve(root->right,root->val,maxVal);
        else
            return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }