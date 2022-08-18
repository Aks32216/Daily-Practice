// Method - 1

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode* lc=lowestCommonAncestor(root->left,p,q);
        TreeNode* rc=lowestCommonAncestor(root->right,p,q);
        if(lc!=NULL && rc!=NULL)
            return root;
        else if(lc!=NULL)
            return lc;
        else
            return rc;
            
      }

// Method - 2

      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val<p->val && root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;
            
      }