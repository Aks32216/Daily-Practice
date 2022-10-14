int moves=0;
    
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        moves+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    
    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
    }