TreeNode* solve(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        root->left=solve(root->left);
        root->right=solve(root->right);
        swap(root->left,root->right);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }