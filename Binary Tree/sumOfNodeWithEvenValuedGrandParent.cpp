void solve(TreeNode* root,TreeNode* par,TreeNode* grandPar,int& ans)
    {
        if(root==NULL)
            return;
        if(grandPar!=NULL && grandPar->val%2==0)
            ans+=root->val;
        solve(root->left,root,par,ans);
        solve(root->right,root,par,ans);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        solve(root,NULL,NULL,ans);
        return ans;
    }