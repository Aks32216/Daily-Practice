int solve(TreeNode* root,bool& isHeightBalanced)
    {
        if(root==NULL)
            return 0;
        int lh=solve(root->left,isHeightBalanced);
        int rh=solve(root->right,isHeightBalanced);
        if(abs(rh-lh)>1)
            isHeightBalanced=false;
        return max(rh,lh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool isHeightBalanced=true;
        int x=solve(root,isHeightBalanced);
        return isHeightBalanced;
    }