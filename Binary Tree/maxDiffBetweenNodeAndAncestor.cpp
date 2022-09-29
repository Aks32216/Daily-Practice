tvoid solve(TreeNode* root,int minVal,int maxVal,int& maxDiff)
    {
        if(root==NULL)
            return;
        minVal=min(minVal,root->val);
        maxVal=max(maxVal,root->val);
        maxDiff=max({maxDiff,maxVal-minVal});
        solve(root->left,minVal,maxVal,maxDiff);
        solve(root->right,minVal,maxVal,maxDiff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff=0;
        int minVal=INT_MAX;
        int maxVal=0;
        solve(root,minVal,maxVal,maxDiff);
        return maxDiff;
    }