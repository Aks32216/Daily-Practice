bool solve(TreeNode* f,TreeNode* s)
    {
        if(f==NULL || s==NULL)
            return f==s;
        return (f->val==s->val) && solve(f->left,s->right) && solve(f->right,s->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }