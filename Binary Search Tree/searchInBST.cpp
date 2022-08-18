TreeNode* solve(TreeNode* root,int val)
    {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        else if(root->val>val)
            return solve(root->left,val);
        else if(root->val<val)
            return solve(root->right,val);
        else
            return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }