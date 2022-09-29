bool solve(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
            return p==q;
        return (p->val==q->val) && solve(p->left,q->right) && solve(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }